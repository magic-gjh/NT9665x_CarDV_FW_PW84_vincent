#include "AudNR.h"
#include "stdlib.h"
#include "Type.h"
#include "UIAppMovie_AudNR.h"

UINT32 gAudNrIrisStopFreq     = 15000;
UINT32 gAudNrIrisReplaceFreq  = 15000;
UINT32 gAudNrIrisDecreaseLvl  = AUDNR_COEF(2.0);
UINT32 gAudNrIrisMixBackgrd   = AUDNR_COEF(0.7);

static INT32  gAudNrIrisBandNum      = 11;

static INT32  gpAudNrIrisNoiseFreqBand[11] = {
0,
32,
64,
128,
160,
192,
320,
384,
640,
768,
1023,
};

static INT64  gpAudNrIrisNoisePower[11] = {
0x000000000009fdd1LL,
0x0000001826c8c243LL,
0x0000005d2bf3a252LL,
0x0000002facc53b86LL,
0x000000480f52f171LL,
0x000001791dca456fLL,
0x00000176d97f3c06LL,
0x0000017d2879dc95LL,
0x0000002f724d40b3LL,
0x00000088175878eaLL,
0x0000052128a101acLL,
};

static INT32  gpAudNrIrisNoiseSpec[1024] = {
0x2cb,
0x88,
0x3,
0x66,
0x78,
0x3f,
0x3f,
0x53,
0x6e,
0x44,
0x46,
0x1b,
0x28,
0x4f,
0x5c,
0x19,
0x17,
0x3a,
0x23,
0x3c,
0x0,
0xb,
0x1a,
0x1a,
0x22,
0x16,
0x25,
0x26,
0x19,
0x46,
0x62,
0x80,
0x7e25,
0x8d9f,
0x651a,
0x79f5,
0x92cb,
0x798e,
0xd1de,
0x11677,
0x17c4b,
0x13b7f,
0x12d5a,
0x1418a,
0x1701e,
0x1c6e6,
0x13803,
0xe1c4,
0x9bd8,
0x730c,
0x392a,
0x4105,
0x39d4,
0x396f,
0x550b,
0x542d,
0x5810,
0x6a1d,
0xb4f0,
0xf0f5,
0xf747,
0x12fee,
0xe7fc,
0xe314,
0xf713,
0x18199,
0x13c4a,
0x1892e,
0x10122,
0xd768,
0x10cc2,
0xc2b8,
0xf97c,
0x15fbd,
0xfd57,
0x1627e,
0xe99a,
0xd022,
0xd66d,
0xb8eb,
0x8fcb,
0x8781,
0xd5c3,
0x11ad8,
0x9401,
0xd3a0,
0x14bae,
0x13d23,
0x1aa74,
0x1e752,
0x2be5a,
0x2b5c1,
0x26c9d,
0x2307e,
0x1464e,
0x11c89,
0x12d1d,
0x88da,
0xa63e,
0x8b2d,
0x9522,
0x7975,
0x5654,
0x950c,
0x8ff7,
0x93fc,
0xd639,
0x13c1b,
0x1428b,
0x100dd,
0xba58,
0x9b68,
0xb15d,
0xf78b,
0xec61,
0xe88a,
0x16624,
0x16ed5,
0x1045f,
0x16053,
0x132b4,
0x19993,
0x1ab0c,
0x1a957,
0x12c17,
0xd8f9,
0xb5e9,
0xde2b,
0x105a7,
0xe140,
0xbd2a,
0xf757,
0x12bf0,
0x1b1b3,
0x1b332,
0x1de81,
0x164f3,
0x229a9,
0x1871f,
0x17077,
0x1763f,
0x1e4af,
0x14e71,
0x15cb1,
0x12959,
0x13df5,
0xdecd,
0xd9ac,
0xef57,
0xbb59,
0xd5cf,
0xdaba,
0xfcee,
0x10b9a,
0xfec5,
0xb62d,
0xdd71,
0xa1c4,
0xf2d6,
0xc905,
0x1304a,
0xe3b9,
0xfad0,
0x10445,
0xe805,
0xd99d,
0xd45f,
0xfe98,
0xf436,
0xe51a,
0x136ef,
0xf6c6,
0x12b7c,
0xeeb9,
0x15a13,
0x168e3,
0x1e40a,
0x1deab,
0x1709b,
0x18001,
0x12dff,
0x2a989,
0x23adf,
0x1fa81,
0x1dc6b,
0x1d134,
0x1f9ab,
0x1b0ef,
0x18e17,
0x178df,
0x2048c,
0x1e0d4,
0x28234,
0x16faf,
0x1ad8f,
0x233ea,
0x2e7e5,
0x2c0dc,
0x26100,
0x3dc53,
0x2c5d7,
0x2c41c,
0x1d154,
0x29e3d,
0x30ab6,
0x2a9ef,
0x2d734,
0x27c7a,
0x24f51,
0x29ae0,
0x3b2e1,
0x54924,
0x495fd,
0x478ac,
0x2b6b3,
0x1ae83,
0x16fb0,
0x17e20,
0x14d7d,
0x14771,
0x18ffd,
0x29879,
0x2339b,
0x2c0bd,
0x2187d,
0x2a302,
0x20e0c,
0x214fb,
0x1db6a,
0x134eb,
0x11fbe,
0x188c8,
0x1b474,
0x107e2,
0x14e14,
0x158b6,
0x1dd73,
0x14550,
0x150a7,
0xe6a2,
0xec4a,
0x10b41,
0x11280,
0x11adb,
0xad8c,
0xa83d,
0xa1d5,
0xcd87,
0xbc2b,
0xcc12,
0xd8b3,
0x124cd,
0x1c514,
0x1a397,
0x17888,
0x166ee,
0x1a2f5,
0x1a4fb,
0x15f39,
0x1472b,
0x166a1,
0x13c77,
0x1177b,
0x149ca,
0x1052c,
0x1150c,
0x11f39,
0xbec5,
0xec6c,
0xbf28,
0xf1ef,
0x10011,
0x7dd5,
0x836b,
0x9757,
0xb816,
0x9f31,
0x9d70,
0xb785,
0xced1,
0x10a65,
0x16d67,
0x120d4,
0x111f1,
0x14f40,
0xeaa8,
0xe5ca,
0x11559,
0x12769,
0x8901,
0xf378,
0xcc5c,
0xbe2f,
0xc50c,
0x9966,
0x74ff,
0x5e7b,
0x8717,
0x82db,
0x7658,
0x898f,
0xc626,
0xec45,
0xa083,
0xd6b4,
0xce4e,
0x1114e,
0x120ab,
0x1759a,
0x128a4,
0xe1cf,
0x111bc,
0xe575,
0x13857,
0x15989,
0x1139f,
0x15b9c,
0x219b5,
0x1c36c,
0x1e8db,
0x145b0,
0x1c77c,
0x19208,
0x20241,
0x15853,
0x1f85e,
0x1b4d4,
0x17546,
0x1a104,
0x20762,
0x1d5cc,
0x28598,
0x2ab87,
0x2f237,
0x22e45,
0x28aa7,
0x226ae,
0x1f61a,
0x29c2d,
0x290c6,
0x26951,
0x336a2,
0x2684a,
0x223fa,
0x3a206,
0x269f7,
0x296a0,
0x31807,
0x2bca0,
0x2ca1d,
0x2e5df,
0x2518f,
0x27072,
0x1f69b,
0x24afe,
0x2af0e,
0x220fb,
0x2289b,
0x291bf,
0x39976,
0x305ed,
0x2579e,
0x2b1a6,
0x3207c,
0x223cb,
0x2c744,
0x241da,
0x2880b,
0x2f768,
0x2e255,
0x244ec,
0x243f1,
0x24b08,
0x29775,
0x15b1c,
0x21b52,
0x1ef7f,
0x2c7a3,
0x2a1b6,
0x2aaa2,
0x24ef9,
0x245a4,
0x219b8,
0x202ee,
0x20875,
0x1883b,
0x1536c,
0x1a533,
0x17674,
0x1b0fd,
0x34ced,
0x22c13,
0x24ff4,
0x1c012,
0x27078,
0x293fd,
0x255cd,
0x29eb6,
0x2e313,
0x29a47,
0x27662,
0x1dbba,
0x1bfbc,
0x192a5,
0x1815c,
0x18fef,
0x195b2,
0x215a6,
0x246e8,
0x1ea18,
0x1d980,
0x19e2e,
0x197ba,
0x1aaa8,
0x1a51e,
0x12daa,
0x1c7d8,
0x10ec3,
0x10831,
0x1236d,
0x19f92,
0x1567e,
0x16983,
0xf367,
0x146ae,
0x14999,
0x112e2,
0x11a8f,
0x177ea,
0x12736,
0x17a2f,
0x1965f,
0x1d612,
0x275a6,
0x1d8a7,
0x19067,
0x1cf66,
0x1791c,
0x18989,
0x1043d,
0x11fc0,
0x17461,
0x1328b,
0x1618c,
0x11306,
0xfd90,
0x137c8,
0x11d90,
0x11b36,
0x111de,
0x11626,
0x18da2,
0x13472,
0x18a9e,
0xf868,
0x1610b,
0x15452,
0x18d96,
0x110dc,
0x11411,
0xef25,
0x1bbf2,
0x14813,
0x107a8,
0xe5f7,
0x1359d,
0x10174,
0xc3cb,
0x17365,
0xfe7a,
0x143aa,
0x1548d,
0x1b6a0,
0x1a2a3,
0x132ef,
0x1a328,
0x1801e,
0x1af97,
0x1953d,
0x1a215,
0x13b6d,
0x1abd6,
0x17d98,
0x20795,
0x268d3,
0x17b19,
0x1dbc4,
0x11055,
0x15687,
0x173be,
0x17e47,
0x1a037,
0x104bb,
0x16010,
0x17761,
0x19f01,
0x1ccf6,
0x170c8,
0x17a98,
0x16f91,
0x130a2,
0x1940b,
0xebe2,
0x13378,
0x1ab2b,
0x15726,
0x1d5a0,
0x19a5b,
0x13fdf,
0x17113,
0x157a6,
0x180d6,
0x1b216,
0x13cc9,
0x1622a,
0x16821,
0xeedd,
0x10d05,
0x11a46,
0xfae6,
0x149a4,
0x12d32,
0xaf29,
0xd0d3,
0xab36,
0xf4ca,
0xd158,
0xb42a,
0xd644,
0xb15f,
0x9752,
0xb911,
0x6cf0,
0x8e6d,
0x706d,
0xac55,
0x704c,
0x7be9,
0x7c1d,
0x7cbd,
0x681d,
0x688f,
0x8c30,
0x6593,
0x7056,
0x7d60,
0x7b85,
0x976f,
0x7101,
0x7bb7,
0xb0ae,
0xc4be,
0x8da0,
0x805d,
0x9714,
0x7a2f,
0xb4cd,
0xe6c0,
0x9a3d,
0xac4c,
0x90f7,
0x832e,
0x8017,
0x77d2,
0x9f0a,
0xc5de,
0x85f7,
0x9d09,
0xb604,
0xbffe,
0xd278,
0xecfc,
0xedac,
0xc106,
0xd0d9,
0xd21a,
0xcd38,
0xb54d,
0x12802,
0xf05c,
0xdb59,
0x8dc5,
0x9478,
0x10fd4,
0x9596,
0xd253,
0xc46f,
0xb804,
0x9573,
0x8962,
0x8c74,
0x930b,
0x9d34,
0xbdc7,
0x7784,
0xa7da,
0x7b8b,
0x99d8,
0x9e9a,
0xc7fa,
0x9d07,
0x94be,
0x642d,
0x7ead,
0x5e50,
0x93ed,
0x6ff1,
0x4d9b,
0x4400,
0x70de,
0x5924,
0x5fdb,
0x4972,
0x408e,
0x5574,
0x6d62,
0x57bc,
0x566e,
0x5b97,
0x508f,
0x6b1e,
0x6687,
0x5ea6,
0x56d1,
0x5f0c,
0x4f0c,
0x6bdb,
0x4ede,
0x5547,
0x6b96,
0x60f8,
0x8424,
0x79ba,
0x9b88,
0x6b68,
0x63de,
0x85ef,
0x5a93,
0x6780,
0x6f3b,
0x4f95,
0x5d1f,
0x4b0c,
0x4c82,
0x4d9e,
0x454f,
0x3c7b,
0x56ba,
0x43cd,
0x61e7,
0x5bab,
0x4d93,
0x49ff,
0x4373,
0x4c92,
0x6486,
0x4ff9,
0x8dbb,
0x6f58,
0x9db5,
0x8bd1,
0x7d88,
0x86cc,
0xa751,
0x6010,
0xbbdf,
0x7869,
0xb23f,
0xa367,
0xb599,
0xe984,
0xc2fd,
0x7e14,
0xa6ed,
0x8b77,
0x80ed,
0x8bda,
0xad94,
0x82f7,
0x7bb0,
0x8a3f,
0x88de,
0xa6a9,
0xaaf4,
0xbc2a,
0x901c,
0xba43,
0xa7cb,
0x8d28,
0x4c18,
0x70b3,
0x7947,
0x63cb,
0x6752,
0x535a,
0x541c,
0x5a94,
0x4d7c,
0x3d2d,
0x428e,
0x382f,
0x4ad5,
0x4a16,
0x5ba4,
0x36eb,
0x2dc6,
0x38e5,
0x333d,
0x4218,
0x548d,
0x4165,
0x448c,
0x3467,
0x4bc7,
0x4df8,
0x2e26,
0x3dad,
0x3c60,
0x59ff,
0x66c7,
0x4f00,
0x60c4,
0x5a12,
0x5a4b,
0x6b5c,
0x67f1,
0x8b1f,
0x8409,
0x9e99,
0x64c6,
0x8957,
0x8ae6,
0x95a5,
0x7ac8,
0x85b9,
0xc28f,
0xd044,
0xbc6b,
0xafc9,
0xd608,
0x110e9,
0xef72,
0xdd2b,
0x12597,
0xcff3,
0xd782,
0xc5ad,
0xc9c1,
0xf3c5,
0xe96d,
0xd76f,
0xeb3e,
0xff95,
0x1010b,
0xb600,
0xdaab,
0xc5b0,
0x107ac,
0x1051b,
0x6a55,
0xb695,
0xe477,
0xf136,
0x13f03,
0xd633,
0x1452a,
0x12790,
0x1239b,
0xf070,
0xe9c0,
0x12bdf,
0x107fc,
0x1257f,
0x1054b,
0xfa95,
0xd3c2,
0xd217,
0xb224,
0xe402,
0x10983,
0xd5ff,
0x11ede,
0xf03a,
0xd9f3,
0xda60,
0xde75,
0xded3,
0xb2c6,
0xf4bc,
0xc212,
0xa4ff,
0x98b6,
0x124a7,
0xb236,
0xa923,
0xc6a3,
0xe123,
0xe342,
0x8e85,
0xaf0f,
0x68f3,
0x7b44,
0x95d4,
0x5c59,
0x879d,
0x90a4,
0x8298,
0x7b3c,
0x9ec5,
0x8c46,
0x804b,
0xa3a7,
0x811e,
0x98be,
0x8498,
0x70e3,
0x73bb,
0x6314,
0x7e5b,
0x79ce,
0x9765,
0x9063,
0x77da,
0x8d79,
0xac5f,
0x77dd,
0xa14a,
0x963e,
0x8843,
0xb2a4,
0xaf24,
0xb53a,
0xa00f,
0x7abc,
0x73cb,
0x7c3c,
0x770a,
0x774a,
0x75ad,
0x5b57,
0x9aa1,
0x944b,
0x6bf1,
0x96b2,
0x90dc,
0xab29,
0xc082,
0xbe41,
0xda1f,
0xdcf4,
0xd087,
0x112e5,
0xf8f5,
0x156bb,
0x12e38,
0x130e4,
0x116fe,
0xfddc,
0x1406f,
0x11e28,
0x134de,
0x1173a,
0xee5f,
0x116c5,
0x1717b,
0xbbd8,
0xf826,
0xeae0,
0x100ac,
0xbccb,
0xd9a9,
0xd708,
0xd07d,
0xe5f4,
0xe199,
0x10043,
0x16c4a,
0x152f7,
0x110fb,
0x19078,
0x168b7,
0xeeb8,
0x11796,
0x10321,
0xcfc2,
0xdba8,
0x10087,
0xe999,
0xecdb,
0x10b74,
0x7c1c,
0xccb9,
0xe7a4,
0xabe6,
0xeef4,
0xb965,
0xfa15,
0xafeb,
0x94fe,
0xc873,
0xa31c,
0x9de2,
0xc4a4,
0xffb3,
0xef16,
0xc3b6,
0x9509,
0xa64d,
0xb729,
0x81cf,
0x90ad,
0x9ef3,
0xb5a1,
0x8f2b,
0xa371,
0xa0bc,
0xa207,
0xac69,
0x8f55,
0x7465,
0x65f8,
0x96b3,
0x87eb,
0x5d71,
0x750b,
0x863a,
0x5a96,
0x4669,
0x76ad,
0x66be,
0x91bf,
0x8238,
0x991a,
0x8813,
0xb030,
0x8818,
0x95c5,
0x7b2b,
0xada8,
0xa7d7,
0x92fa,
0xcc71,
0xdd24,
0x82cf,
0xbd6e,
0xb468,
0xe30f,
0xc3f2,
0xe20e,
0xa309,
0x98c0,
0x6762,
0xa964,
0xaab9,
0x8422,
0xa122,
0xbbb7,
0xb869,
0x96c2,
0xe068,
0x1050d,
0xb11c,
0x764c,
0x952d,
0x9021,
0x84d1,
0x691f,
0x8d88,
0xbaac,
0x9892,
0xba43,
0xca5a,
0xb1b0,
0x88a0,
0xc42a,
0xb21c,
0xb404,
0x9890,
0x8a40,
0x82b0,
0x8d71,
0xcecd,
0x9750,
0x7d5c,
0x898f,
0x54d6,
0x6e7d,
0x94f1,
0x7517,
0x7a94,
0x6156,
0x66cb,
0x9bd8,
0x61a0,
0x71d6,
0x8b91,
0x7fe8,
0x7c60,
0x90b1,
0x8480,
0xa21d,
0x6faa,
0x86a5,
0x6e2d,
0x6ed2,
0x6050,
0x79c4,
0x8434,
0x70f4,
0x9df6,
0x6882,
0x8b4f,
0x843e,
0xb2a3,
0x7a80,
0x61ff,
0x7664,
0x6879,
0x8dfa,
0x9524,
0x9e10,
0x9162,
0x7d43,
0x0,
};

AUDNR_NOISE_SPEC gpAudNrNoiseSpec_Iris =
{
    &gAudNrIrisBandNum,
    gpAudNrIrisNoiseFreqBand,
    gpAudNrIrisNoisePower,
    gpAudNrIrisNoiseSpec
};