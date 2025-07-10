void __usercall bn_GF2m_mul_1x1(
        unsigned int *r0@<edi>,
        const unsigned int b@<ecx>,
        unsigned int *r1,
        const unsigned int a)
{
  unsigned int v4; // esi
  int v5; // eax
  unsigned int v6; // ebp
  int v7; // esi
  int v8; // eax
  unsigned int v9; // ebp
  int v10; // esi
  int v11; // eax
  unsigned int v12; // ebp
  int v13; // esi
  int v14; // eax
  unsigned int v15; // ebp
  int v16; // esi
  int v17; // eax
  unsigned int v18; // ebp
  unsigned int v19; // edx
  int v20; // eax
  unsigned int v21; // ebp
  int v22; // esi
  int v23; // eax
  unsigned int v24; // ebp
  int v25; // esi
  int v26; // eax
  unsigned int v27; // ebp
  int v28; // eax
  int v29; // esi
  _DWORD v30[6]; // [esp+Ch] [ebp-20h]
  unsigned int v31; // [esp+24h] [ebp-8h]
  unsigned int v32; // [esp+28h] [ebp-4h]

  v30[3] = a & 0x3FFFFFFF ^ (2 * (a & 0x3FFFFFFF));
  v30[4] = 4 * a;
  v31 = (2 * (a & 0x3FFFFFFF)) ^ (4 * a);
  v32 = a & 0x3FFFFFFF ^ v31;
  v30[1] = a & 0x3FFFFFFF;
  v30[5] = a & 0x3FFFFFFF ^ (4 * a);
  v30[2] = 2 * (a & 0x3FFFFFFF);
  v30[0] = 0;
  v4 = v30[(b >> 3) & 7];
  v5 = v30[b & 7] ^ (8 * v4);
  v6 = v30[(b >> 6) & 7];
  v7 = (v6 >> 26) ^ (v4 >> 29);
  v8 = (v6 << 6) ^ v5;
  v9 = v30[(b >> 9) & 7];
  v10 = (v9 >> 23) ^ v7;
  v11 = (v9 << 9) ^ v8;
  v12 = v30[(b >> 12) & 7];
  v13 = (v12 >> 20) ^ v10;
  v14 = (v12 << 12) ^ v11;
  v15 = v30[(b >> 15) & 7];
  v16 = (v15 >> 17) ^ v13;
  v17 = (v15 << 15) ^ v14;
  v18 = v30[(b >> 18) & 7];
  v19 = v18 >> 14;
  v20 = (v18 << 18) ^ v17;
  v21 = v30[(b >> 21) & 7];
  v22 = (v21 >> 11) ^ v19 ^ v16;
  v23 = (v21 << 21) ^ v20;
  v24 = v30[HIBYTE(b) & 7];
  v25 = (v24 >> 8) ^ v22;
  v26 = (v24 << 24) ^ v23;
  v27 = v30[(b >> 27) & 7];
  v28 = (v30[b >> 30] << 30) ^ (v27 << 27) ^ v26;
  v29 = (v30[b >> 30] >> 2) ^ (v27 >> 5) ^ v25;
  if ( (a & 0x40000000) != 0 )
  {
    v28 ^= b << 30;
    v29 ^= b >> 2;
  }
  if ( ((a >> 30) & 2) != 0 )
  {
    v28 ^= b << 31;
    v29 ^= b >> 1;
  }
  *r1 = v29;
  *r0 = v28;
}
