/*
 * Copyright (c) 2015, Ari Suutari <ari@stonepile.fi>.
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. The name of the author may not be used to endorse or promote
 *     products derived from this software without specific prior written
 *     permission. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT,  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <picoos.h>
#include <picoos-u.h>
#include <picoos-lua.h>

#include <string.h>

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include "driverlib.h"

void ledOffTask(void*);
void luaTask(void*);

void ledOffTask(void* arg)
{
   while (1) {

     uosResourceDiag();
     posTaskSleep(MS(60000));
     GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
   }
}

static const UosMount luaFs = { 
  "/usr/local/share/lua/5.3/",
  &uosRomFS,
  "/"
};

static int console(lua_State* L)
{
  const char* code = "require 'simplerepl'.new('Lua shell>'):repl()";
  int status;

  luaL_openlibs(L);
  status = luaL_loadbuffer(L, code, strlen(code), "=stdin");
  if (status == LUA_OK)
    status = lua_pcall(L, 0, 0, 0);

  if (status != LUA_OK) {

    lua_writestringerror("lua: %s\n", lua_tostring(L, -1));
     lua_pop(L, 1);
  }

  return 0;
}

void luaTask(void* arg)
{
  uosInit();
  uosBootDiag();
  uosMount(&luaFs);

  POSTASK_t ledOff = posTaskCreate(ledOffTask, NULL, 3, 500);
  POS_SETTASKNAME(ledOff, "ledOff");

  int status;
  lua_State *L = luaL_newstate();
  
  lua_pushcfunction(L, console);
  status = lua_pcall(L, 0, 0, 0);
  if (status != LUA_OK) {

    lua_writestringerror("lua: %s\n", lua_tostring(L, -1));
    lua_pop(L, 1);
  }
}

int main(int argc, char **argv)
{
  /*
   * Configure pins as uart.
   */
  MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1,
    GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);

  /*
   * Configure LED pins as output.
   */
  MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
  GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);

  /*
   * LED on.
   */
  GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);

  /*
   * Start scheduler.
   */
  nosInit(luaTask, NULL, 2, 15000, 256);
  return 0;
}
