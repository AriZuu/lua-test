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

#include <stdlib.h>
#include <string.h>
 
#include <picoos.h>
#include <picoos-u.h>
#include <picoos-lua.h>

#include "lauxlib.h"

int luaopen_gpio(lua_State *L);
int luaopen_uos(lua_State *L);

#include "driverlib.h"
 
/*
 * GPIO port.
 */

typedef struct {

  char port;
  int bit;

} GPIOPort;;
 
static int lgpio_new(lua_State *L)
{
  GPIOPort     *gu;
  const char*  port;
  int          bit;
 
  port  = luaL_checkstring(L, 1);
  if (port == NULL)
    luaL_error(L, "port cannot be empty");
 
  bit  = luaL_checkinteger(L, 2);

  gu       = (GPIOPort *)lua_newuserdata(L, sizeof(*gu));
  gu->port = '\0';
  gu->bit  = 0;
 
  luaL_getmetatable(L, "LGpio");
  lua_setmetatable(L, -2);
 
  gu->port = *port;
  gu->bit  = bit;
 
  return 1;
}
 
static int lgpio_set(lua_State *L)
{
  GPIOPort *gu;
  int      val;
 
  gu  = (GPIOPort *)luaL_checkudata(L, 1, "LGpio");
  val = luaL_checkinteger(L, 2);

  if (val)
    GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
  else
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
 
  return 0;
}
 
static const struct luaL_Reg lgpio_methods[] = {

  { "set",         lgpio_set       },
  //{ "__gc",        lgpio_destroy   },
  //{ "__tostring",  lgpio_tostring  },
  { NULL,          NULL               },

};
 
static const struct luaL_Reg lgpio_functions[] = {

  { "new", lgpio_new },
  { NULL,  NULL      }

};
 
int luaopen_gpio(lua_State *L)
{
  luaL_newmetatable(L, "LGpio");
  lua_pushvalue(L, -1);
  lua_setfield(L, -2, "__index");
 
  luaL_setfuncs(L, lgpio_methods, 0);
  luaL_newlib(L, lgpio_functions);
 
  return 1;
}

static int luos_resourceDiag(lua_State *L)
{
  uosResourceDiag();
  return 0;
}
static const struct luaL_Reg luos_functions[] = {

  { "resourcediag", luos_resourceDiag },
  { NULL,  NULL      }

};

int luaopen_uos(lua_State *L)
{
  luaL_newlib(L, luos_functions);

  return 1;
}

static const luaL_Reg libs[] = {

/*
 * Modules from lua distribution.
 */

  { "gpio", luaopen_gpio },
  { "uos", luaopen_uos, },
  { NULL, NULL }
};

LUALIB_API void pluaAddLibs(lua_State *L)
{
  const luaL_Reg *lib;

  for (lib = libs; lib->func; lib++) {

    luaL_requiref(L, lib->name, lib->func, 1);
    lua_pop(L, 1);
  }
}
