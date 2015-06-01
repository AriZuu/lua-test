#include <picoos.h>
#include <picoos-u.h>

// simplerepl.lua
static const unsigned char file_1[] = {

0x1b,0x4c,0x75,0x61,0x53,0x00,0x19,0x93,0x0d,0x0a,0x1a,0x0a,0x04,0x04,0x04,
0x04,0x04,0x78,0x56,0x00,0x00,0x00,0x40,0xb9,0x43,0x01,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x04,0x15,0x00,0x00,0x00,0x0b,0x00,0x00,
0x00,0x08,0x00,0x00,0x80,0x06,0x00,0x40,0x00,0x46,0x00,0x40,0x00,0x0a,0x40,
0x80,0x80,0x06,0x80,0x40,0x00,0x07,0xc0,0x40,0x00,0x46,0x80,0x40,0x00,0x47,
0x00,0xc1,0x00,0x86,0x00,0x40,0x00,0xec,0x00,0x00,0x00,0x8a,0xc0,0x80,0x82,
0x86,0x80,0x41,0x00,0xec,0x40,0x00,0x00,0x8a,0xc0,0x80,0x83,0x86,0x80,0x41,
0x00,0xec,0x80,0x00,0x00,0x8a,0xc0,0x00,0x84,0x86,0x40,0x42,0x00,0xa6,0x00,
0x00,0x01,0x26,0x00,0x80,0x00,0x0a,0x00,0x00,0x00,0x04,0x0b,0x53,0x69,0x6d,
0x70,0x6c,0x65,0x52,0x45,0x50,0x4c,0x04,0x08,0x5f,0x5f,0x69,0x6e,0x64,0x65,
0x78,0x04,0x03,0x69,0x6f,0x04,0x07,0x73,0x74,0x64,0x6f,0x75,0x74,0x04,0x06,
0x73,0x74,0x64,0x69,0x6e,0x04,0x04,0x6e,0x65,0x77,0x04,0x0b,0x53,0x69,0x6d,
0x70,0x6c,0x65,0x52,0x45,0x50,0x4c,0x04,0x07,0x66,0x69,0x78,0x52,0x65,0x74,
0x04,0x05,0x72,0x65,0x70,0x6c,0x04,0x0b,0x53,0x69,0x6d,0x70,0x6c,0x65,0x52,
0x45,0x50,0x4c,0x01,0x00,0x00,0x00,0x01,0x00,0x03,0x00,0x00,0x00,0x00,0x29,
0x00,0x00,0x00,0x2d,0x00,0x00,0x00,0x01,0x00,0x04,0x07,0x00,0x00,0x00,0x46,
0x00,0x40,0x00,0x8b,0x00,0x00,0x00,0xc6,0x40,0x40,0x00,0x64,0x80,0x80,0x01,
0x4a,0x00,0x00,0x81,0x66,0x00,0x00,0x01,0x26,0x00,0x80,0x00,0x03,0x00,0x00,
0x00,0x04,0x0d,0x73,0x65,0x74,0x6d,0x65,0x74,0x61,0x74,0x61,0x62,0x6c,0x65,
0x04,0x0b,0x53,0x69,0x6d,0x70,0x6c,0x65,0x52,0x45,0x50,0x4c,0x04,0x07,0x70,
0x72,0x6f,0x6d,0x70,0x74,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2f,0x00,
0x00,0x00,0x32,0x00,0x00,0x00,0x01,0x01,0x06,0x0b,0x00,0x00,0x00,0x46,0x00,
0x40,0x00,0x81,0x40,0x00,0x00,0xed,0x00,0x00,0x00,0x64,0x80,0x00,0x00,0x80,
0x00,0x00,0x00,0xc0,0x00,0x80,0x00,0x0b,0x01,0x00,0x00,0x6d,0x01,0x00,0x00,
0x2b,0x41,0x00,0x00,0xa6,0x00,0x00,0x02,0x26,0x00,0x80,0x00,0x02,0x00,0x00,
0x00,0x04,0x07,0x73,0x65,0x6c,0x65,0x63,0x74,0x04,0x02,0x23,0x01,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x34,0x00,0x00,0x00,0x65,0x00,0x00,0x00,0x01,0x00,
0x0f,0x91,0x00,0x00,0x00,0x45,0x00,0x00,0x00,0x4c,0x00,0xc0,0x00,0xc7,0x40,
0x40,0x00,0x01,0x81,0x00,0x00,0xdd,0x00,0x81,0x01,0x64,0x40,0x80,0x01,0x45,
0x00,0x80,0x00,0x4c,0xc0,0xc0,0x00,0x64,0x00,0x01,0x01,0x1e,0xc0,0x20,0x80,
0x46,0x81,0x41,0x01,0x81,0xc1,0x01,0x00,0xc0,0x01,0x00,0x02,0x9d,0xc1,0x01,
0x03,0xc1,0x01,0x02,0x00,0x64,0xc1,0x80,0x01,0x88,0x80,0x81,0x82,0x88,0x40,
0x01,0x82,0x46,0x41,0x41,0x01,0x62,0x01,0x00,0x00,0x1e,0x00,0x10,0x80,0x46,
0x81,0x41,0x01,0x80,0x01,0x00,0x02,0xc1,0x01,0x02,0x00,0x64,0xc1,0x80,0x01,
0x88,0x80,0x81,0x82,0x88,0x40,0x01,0x82,0x46,0x41,0x41,0x01,0x62,0x01,0x00,
0x00,0x1e,0xc0,0x0d,0x80,0x46,0x41,0x42,0x01,0x47,0x81,0xc2,0x02,0x86,0x41,
0x41,0x01,0xc1,0xc1,0x02,0x00,0x64,0x81,0x80,0x01,0x62,0x01,0x00,0x00,0x1e,
0x00,0x0c,0x80,0x88,0x00,0x01,0x86,0x45,0x01,0x00,0x00,0x4c,0x01,0xc0,0x02,
0xc7,0x41,0x40,0x00,0x07,0x42,0x40,0x00,0x0c,0x42,0x43,0x04,0x87,0x42,0x40,
0x00,0x9c,0x02,0x00,0x05,0x24,0x82,0x80,0x01,0x41,0x82,0x00,0x00,0xdd,0x41,
0x82,0x03,0x64,0x41,0x80,0x01,0x45,0x01,0x80,0x00,0x4c,0xc1,0xc0,0x02,0x64,
0x01,0x01,0x01,0x1e,0x80,0x07,0x80,0x46,0x02,0x43,0x01,0x80,0x02,0x00,0x04,
0x5d,0x82,0x82,0x04,0x88,0x40,0x02,0x86,0x46,0x82,0x41,0x01,0x86,0x02,0x43,
0x01,0xc1,0x02,0x02,0x00,0x64,0xc2,0x80,0x01,0x88,0x80,0x82,0x82,0x88,0x40,
0x02,0x82,0x46,0x02,0x41,0x01,0x62,0x42,0x00,0x00,0x1e,0xc0,0x04,0x80,0x46,
0x42,0x42,0x01,0x47,0x82,0xc2,0x04,0x86,0x42,0x41,0x01,0xc1,0xc2,0x02,0x00,
0x64,0x82,0x80,0x01,0x62,0x02,0x00,0x00,0x1e,0x00,0x03,0x80,0x45,0x02,0x00,
0x00,0x4c,0x02,0xc0,0x04,0xc7,0x42,0x40,0x00,0x07,0x43,0x40,0x00,0x0c,0x43,
0x43,0x06,0x87,0x43,0x40,0x00,0x9c,0x03,0x00,0x07,0x24,0x83,0x80,0x01,0x41,
0x83,0x00,0x00,0xdd,0x42,0x83,0x05,0x64,0x42,0x80,0x01,0x69,0x41,0x00,0x00,
0xea,0x81,0xf7,0x7f,0x46,0x01,0x41,0x01,0x62,0x01,0x00,0x00,0x1e,0x80,0x0a,
0x80,0x46,0x41,0x44,0x01,0x47,0x81,0xc4,0x02,0x86,0xc1,0x44,0x01,0xc6,0x01,
0x41,0x01,0x06,0x02,0x45,0x01,0x07,0x42,0x45,0x04,0xa4,0x01,0x80,0x01,0x64,
0x01,0x01,0x00,0x88,0xc0,0x01,0x88,0x88,0x80,0x81,0x87,0x88,0x40,0x01,0x87,
0x46,0x81,0x43,0x01,0x62,0x01,0x00,0x00,0x1e,0xc0,0x05,0x80,0x46,0xc1,0x43,
0x01,0x20,0x40,0x01,0x8b,0x1e,0x40,0x07,0x80,0x41,0xc1,0x05,0x00,0x86,0xc1,
0x43,0x01,0xc1,0xc1,0x05,0x00,0x68,0x01,0x03,0x80,0x20,0x00,0x82,0x8b,0x1e,
0xc0,0x00,0x80,0x46,0x02,0x46,0x01,0x47,0x02,0xc0,0x04,0x81,0x42,0x06,0x00,
0x64,0x42,0x00,0x01,0x46,0x02,0x46,0x01,0x47,0x02,0xc0,0x04,0x86,0x82,0x46,
0x01,0xc6,0x02,0x44,0x01,0xc7,0x02,0x82,0x05,0xa4,0x02,0x00,0x01,0x64,0x42,
0x00,0x00,0x67,0x41,0xfc,0x7f,0x46,0xc1,0x46,0x01,0x64,0x41,0x80,0x00,0x1e,
0x00,0x02,0x80,0x46,0xc1,0x46,0x01,0x86,0x01,0x44,0x01,0x87,0xc1,0x45,0x03,
0x64,0x41,0x00,0x01,0x1e,0xc0,0x00,0x80,0x46,0xc1,0x46,0x01,0x81,0x01,0x07,
0x00,0xc6,0x41,0x41,0x01,0x64,0x41,0x80,0x01,0x45,0x01,0x00,0x00,0x4c,0x01,
0xc0,0x02,0xc7,0x41,0x40,0x00,0x01,0x82,0x00,0x00,0xdd,0x01,0x82,0x03,0x64,
0x41,0x80,0x01,0x69,0x40,0x00,0x00,0xea,0x40,0xde,0x7f,0x26,0x00,0x80,0x00,
0x1d,0x00,0x00,0x00,0x04,0x06,0x77,0x72,0x69,0x74,0x65,0x04,0x07,0x70,0x72,
0x6f,0x6d,0x70,0x74,0x04,0x02,0x20,0x04,0x06,0x6c,0x69,0x6e,0x65,0x73,0x04,
0x03,0x63,0x68,0x04,0x04,0x65,0x72,0x72,0x04,0x05,0x6c,0x6f,0x61,0x64,0x04,
0x08,0x72,0x65,0x74,0x75,0x72,0x6e,0x20,0x04,0x07,0x3d,0x73,0x74,0x64,0x69,
0x6e,0x04,0x07,0x73,0x74,0x72,0x69,0x6e,0x67,0x04,0x06,0x6d,0x61,0x74,0x63,
0x68,0x04,0x07,0x3c,0x65,0x6f,0x66,0x3e,0x24,0x04,0x04,0x62,0x75,0x66,0x04,
0x04,0x73,0x75,0x62,0x04,0x07,0x73,0x74,0x61,0x74,0x75,0x73,0x04,0x02,0x6e,
0x04,0x02,0x78,0x04,0x0b,0x53,0x69,0x6d,0x70,0x6c,0x65,0x52,0x45,0x50,0x4c,
0x04,0x07,0x66,0x69,0x78,0x52,0x65,0x74,0x04,0x07,0x78,0x70,0x63,0x61,0x6c,
0x6c,0x04,0x06,0x64,0x65,0x62,0x75,0x67,0x04,0x0a,0x74,0x72,0x61,0x63,0x65,
0x62,0x61,0x63,0x6b,0x13,0x00,0x00,0x00,0x00,0x13,0x01,0x00,0x00,0x00,0x04,
0x03,0x69,0x6f,0x04,0x02,0x09,0x04,0x09,0x74,0x6f,0x73,0x74,0x72,0x69,0x6e,
0x67,0x04,0x06,0x70,0x72,0x69,0x6e,0x74,0x04,0x06,0x65,0x72,0x72,0x6f,0x72,
0x03,0x00,0x00,0x00,0x01,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};


const UosRomFile uosRomFiles[] = {
{ "simplerepl.lua",  file_1, sizeof(file_1) },
{ NULL,  NULL, 0 }
};
