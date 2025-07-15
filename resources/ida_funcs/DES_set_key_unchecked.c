void __cdecl DES_set_key_unchecked(unsigned __int8 (*key)[8], DES_ks *schedule)
{
  int v2; // ecx
  int v3; // esi
  int v4; // edx
  unsigned int v5; // ecx
  unsigned int v6; // edx
  int v7; // esi
  unsigned int v8; // ecx
  int v9; // edx
  unsigned int v11; // esi
  unsigned int v12; // edx
  int v13; // ecx
  int v14; // esi
  int v15; // ecx
  unsigned int v16; // edi
  const int *v17; // edx
  unsigned int v18; // ecx
  unsigned int v19; // esi
  unsigned int v20; // ecx
  unsigned int v21; // ebx
  unsigned int v22; // edi
  unsigned int v23; // esi
  unsigned int v24; // ebx
  unsigned int v25; // ecx
  unsigned int v26; // edx
  unsigned int *v27; // eax
  _DWORD *v28; // eax
  int v29; // edi
  int v30; // ebp
  unsigned int v31; // edi
  unsigned int v32; // ebp
  unsigned int v33; // ecx
  unsigned int v34; // edx
  _DWORD *v35; // eax
  _DWORD *v36; // eax
  int v37; // esi
  int v38; // ebx
  unsigned int v39; // esi
  unsigned int v40; // ebx
  unsigned int v41; // ecx
  unsigned int v42; // edx
  _DWORD *v43; // eax
  _DWORD *v44; // eax
  int v45; // ecx
  int v46; // edi
  unsigned int v47; // edx
  unsigned int v48; // esi
  _DWORD *v49; // eax
  const int *v50; // [esp+Ch] [ebp-4h]

  v2 = ((*key)[3] << 24) | ((*key)[2] << 16) | *(unsigned __int16 *)key;
  v3 = (v2 ^ (*(_DWORD *)&(*key)[4] >> 4)) & 0xF0F0F0F;
  v4 = (16 * v3) ^ *(_DWORD *)&(*key)[4];
  v5 = (v3 ^ v2 ^ ((v3 ^ v2) << 18)) & 0xCCCC0000 ^ (((v3 ^ v2 ^ ((v3 ^ v2) << 18)) & 0xCCCC0000) >> 18) ^ v3 ^ v2;
  v6 = (v4 ^ (v4 << 18)) & 0xCCCC0000 ^ (((v4 ^ (v4 << 18)) & 0xCCCC0000) >> 18) ^ v4;
  v7 = (v5 ^ (v6 >> 1)) & 0x55555555;
  v8 = v7 ^ v5;
  v9 = (2 * v7) ^ v6;
  v11 = (unsigned int)&vostok::memory::s_CRT_arena[5508919] & (v9 ^ (v8 >> 8));
  v12 = v11 ^ v9;
  v13 = (v11 << 8) ^ v8;
  v14 = (v13 ^ (v12 >> 1)) & 0x55555555;
  v15 = v14 ^ v13;
  v16 = ((2 * v14) ^ v12) & 0xFF00
      | ((unsigned __int8)((2 * v14) ^ v12) << 16)
      | ((v15 & 0xF000000F | (((2 * v14) ^ v12) >> 12) & 0xFF0) >> 4);
  v17 = &shifts2[1];
  v18 = v15 & 0xFFFFFFF;
  v50 = &shifts2[1];
  do
  {
    if ( *(v17 - 1) )
    {
      v19 = v18 << 26;
      v20 = v18 >> 2;
      v21 = v16 << 26;
      v22 = v16 >> 2;
    }
    else
    {
      v19 = v18 << 27;
      v20 = v18 >> 1;
      v21 = v16 << 27;
      v22 = v16 >> 1;
    }
    v23 = (v20 | v19) & 0xFFFFFFF;
    v24 = (v22 | v21) & 0xFFFFFFF;
    v25 = des_skb[0][v23 & 0x3F]
        | des_skb[1][(v23 & 0xC0 | (v23 >> 1) & 0xF00) >> 6]
        | des_skb[2][(v23 & 0x1E000 | (unsigned int)&dword_60000 & (v23 >> 1)) >> 13]
        | des_skb[3][(v23 & 0x100000
                    | (((unsigned int)&vostok::memory::s_CRT_arena[1379896] & v23 | (v23 >> 1) & 0x7000000) >> 1)) >> 20];
    v26 = (des_skb[4][v24 & 0x3F]
         | des_skb[6][(v24 >> 15) & 0x3F]
         | des_skb[5][(v24 & 0x180 | (v24 >> 1) & 0x1E00) >> 7]
         | des_skb[7][((unsigned int)&vostok::memory::s_CRT_arena[20254264] & v24 | (v24 >> 1) & 0x6000000) >> 21])
        & 0xFFFF0000;
    schedule->ks[0].deslong[0] = __ROR4__(
                                   ((des_skb[4][v24 & 0x3F]
                                   | des_skb[6][(v24 >> 15) & 0x3F]
                                   | des_skb[5][(v24 & 0x180 | (v24 >> 1) & 0x1E00) >> 7]
                                   | des_skb[7][((unsigned int)&vostok::memory::s_CRT_arena[20254264] & v24
                                               | (v24 >> 1) & 0x6000000) >> 21]) << 16)
                                 | (unsigned __int16)v25,
                                   30);
    v27 = &schedule->ks[0].deslong[1];
    *v27 = __ROR4__(v26 | HIWORD(v25), 26);
    v28 = v27 + 1;
    if ( *v50 )
    {
      v29 = (v23 >> 2) | (v23 << 26);
      v30 = (v24 >> 2) | (v24 << 26);
    }
    else
    {
      v29 = (v23 >> 1) | (v23 << 27);
      v30 = (v24 >> 1) | (v24 << 27);
    }
    v31 = v29 & 0xFFFFFFF;
    v32 = v30 & 0xFFFFFFF;
    v33 = des_skb[0][v31 & 0x3F]
        | des_skb[1][(v31 & 0xC0 | (v31 >> 1) & 0xF00) >> 6]
        | des_skb[2][(v31 & 0x1E000 | (unsigned int)&dword_60000 & (v31 >> 1)) >> 13]
        | des_skb[3][(v31 & 0x100000
                    | (((unsigned int)&vostok::memory::s_CRT_arena[1379896] & v31 | (v31 >> 1) & 0x7000000) >> 1)) >> 20];
    v34 = (des_skb[4][v32 & 0x3F]
         | des_skb[6][(v32 >> 15) & 0x3F]
         | des_skb[5][(v32 & 0x180 | (v32 >> 1) & 0x1E00) >> 7]
         | des_skb[7][((unsigned int)&vostok::memory::s_CRT_arena[20254264] & v32 | (v32 >> 1) & 0x6000000) >> 21])
        & 0xFFFF0000;
    *v28 = __ROR4__(
             ((des_skb[4][v32 & 0x3F]
             | des_skb[6][(v32 >> 15) & 0x3F]
             | des_skb[5][(v32 & 0x180 | (v32 >> 1) & 0x1E00) >> 7]
             | des_skb[7][((unsigned int)&vostok::memory::s_CRT_arena[20254264] & v32 | (v32 >> 1) & 0x6000000) >> 21]) << 16)
           | (unsigned __int16)v33,
             30);
    v35 = v28 + 1;
    *v35 = __ROR4__(v34 | HIWORD(v33), 26);
    v36 = v35 + 1;
    if ( v50[1] )
    {
      v37 = (v31 >> 2) | (v31 << 26);
      v38 = (v32 >> 2) | (v32 << 26);
    }
    else
    {
      v37 = (v31 >> 1) | (v31 << 27);
      v38 = (v32 >> 1) | (v32 << 27);
    }
    v39 = v37 & 0xFFFFFFF;
    v40 = v38 & 0xFFFFFFF;
    v41 = des_skb[0][v39 & 0x3F]
        | des_skb[1][(v39 & 0xC0 | (v39 >> 1) & 0xF00) >> 6]
        | des_skb[2][(v39 & 0x1E000 | (unsigned int)&dword_60000 & (v39 >> 1)) >> 13]
        | des_skb[3][(v39 & 0x100000
                    | (((unsigned int)&vostok::memory::s_CRT_arena[1379896] & v39 | (v39 >> 1) & 0x7000000) >> 1)) >> 20];
    v42 = (des_skb[4][v40 & 0x3F]
         | des_skb[6][(v40 >> 15) & 0x3F]
         | des_skb[5][(v40 & 0x180 | (v40 >> 1) & 0x1E00) >> 7]
         | des_skb[7][((unsigned int)&vostok::memory::s_CRT_arena[20254264] & v40 | (v40 >> 1) & 0x6000000) >> 21])
        & 0xFFFF0000;
    *v36 = __ROR4__(
             ((des_skb[4][v40 & 0x3F]
             | des_skb[6][(v40 >> 15) & 0x3F]
             | des_skb[5][(v40 & 0x180 | (v40 >> 1) & 0x1E00) >> 7]
             | des_skb[7][((unsigned int)&vostok::memory::s_CRT_arena[20254264] & v40 | (v40 >> 1) & 0x6000000) >> 21]) << 16)
           | (unsigned __int16)v41,
             30);
    v43 = v36 + 1;
    *v43 = __ROR4__(v42 | HIWORD(v41), 26);
    v44 = v43 + 1;
    if ( v50[2] )
    {
      v45 = (v39 >> 2) | (v39 << 26);
      v46 = (v40 >> 2) | (v40 << 26);
    }
    else
    {
      v45 = (v39 >> 1) | (v39 << 27);
      v46 = (v40 >> 1) | (v40 << 27);
    }
    v18 = v45 & 0xFFFFFFF;
    v16 = v46 & 0xFFFFFFF;
    v47 = des_skb[0][v18 & 0x3F]
        | des_skb[1][(v18 & 0xC0 | (v18 >> 1) & 0xF00) >> 6]
        | des_skb[2][(v18 & 0x1E000 | (unsigned int)&dword_60000 & (v18 >> 1)) >> 13]
        | des_skb[3][(v18 & 0x100000
                    | (((unsigned int)&vostok::memory::s_CRT_arena[1379896] & v18 | (v18 >> 1) & 0x7000000) >> 1)) >> 20];
    v48 = (des_skb[4][v16 & 0x3F]
         | des_skb[6][(v16 >> 15) & 0x3F]
         | des_skb[5][(v16 & 0x180 | (v16 >> 1) & 0x1E00) >> 7]
         | des_skb[7][((unsigned int)&vostok::memory::s_CRT_arena[20254264] & v16 | (v16 >> 1) & 0x6000000) >> 21])
        & 0xFFFF0000;
    *v44 = __ROR4__(
             ((des_skb[4][v16 & 0x3F]
             | des_skb[6][(v16 >> 15) & 0x3F]
             | des_skb[5][(v16 & 0x180 | (v16 >> 1) & 0x1E00) >> 7]
             | des_skb[7][((unsigned int)&vostok::memory::s_CRT_arena[20254264] & v16 | (v16 >> 1) & 0x6000000) >> 21]) << 16)
           | (unsigned __int16)v47,
             30);
    v49 = v44 + 1;
    *v49 = __ROR4__(v48 | HIWORD(v47), 26);
    v17 = v50 + 4;
    schedule = (DES_ks *)(v49 + 1);
    v50 += 4;
  }
  while ( (int)v50 < (int)"es part of OpenSSL 1.0.0g 18 Jan 2012" );
}
