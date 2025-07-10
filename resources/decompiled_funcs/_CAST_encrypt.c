unsigned int *__cdecl CAST_encrypt(unsigned int *a1, _DWORD *a2)
{
  unsigned int v2; // esi
  int v3; // edx
  unsigned int v4; // edi
  int v5; // edx
  unsigned int v6; // esi
  int v7; // edx
  unsigned int v8; // edi
  int v9; // edx
  unsigned int v10; // esi
  int v11; // edx
  unsigned int v12; // edi
  int v13; // edx
  unsigned int v14; // esi
  int v15; // edx
  unsigned int v16; // edi
  int v17; // edx
  unsigned int v18; // esi
  int v19; // edx
  unsigned int v20; // edi
  int v21; // edx
  unsigned int v22; // esi
  int v23; // edx
  unsigned int v24; // edi
  int v25; // edx
  unsigned int v26; // esi
  int v27; // edx
  unsigned int v28; // edi
  int v29; // edx
  unsigned int v30; // esi
  int v31; // edx
  int v32; // edx
  unsigned int *result; // eax

  v2 = a1[1];
  v3 = __ROL4__(v2 + *a2, a2[1]);
  v4 = (CAST_S_table3[BYTE2(v3)]
      + (CAST_S_table1[(unsigned __int8)v3] ^ CAST_S_table0[BYTE1(v3)])
      - CAST_S_table2[HIBYTE(v3)])
     ^ *a1;
  v5 = __ROL4__(v4 ^ a2[2], a2[3]);
  v6 = CAST_S_table3[BYTE2(v5)]
     ^ (CAST_S_table2[HIBYTE(v5)] + CAST_S_table0[BYTE1(v5)] - CAST_S_table1[(unsigned __int8)v5])
     ^ v2;
  v7 = __ROL4__(a2[4] - v6, a2[5]);
  v8 = ((CAST_S_table2[HIBYTE(v7)] ^ (CAST_S_table1[(unsigned __int8)v7] + CAST_S_table0[BYTE1(v7)]))
      - CAST_S_table3[BYTE2(v7)])
     ^ v4;
  v9 = __ROL4__(v8 + a2[6], a2[7]);
  v10 = (CAST_S_table3[BYTE2(v9)]
       + (CAST_S_table1[(unsigned __int8)v9] ^ CAST_S_table0[BYTE1(v9)])
       - CAST_S_table2[HIBYTE(v9)])
      ^ v6;
  v11 = __ROL4__(v10 ^ a2[8], a2[9]);
  v12 = CAST_S_table3[BYTE2(v11)]
      ^ (CAST_S_table2[HIBYTE(v11)] + CAST_S_table0[BYTE1(v11)] - CAST_S_table1[(unsigned __int8)v11])
      ^ v8;
  v13 = __ROL4__(a2[10] - v12, a2[11]);
  v14 = ((CAST_S_table2[HIBYTE(v13)] ^ (CAST_S_table1[(unsigned __int8)v13] + CAST_S_table0[BYTE1(v13)]))
       - CAST_S_table3[BYTE2(v13)])
      ^ v10;
  v15 = __ROL4__(v14 + a2[12], a2[13]);
  v16 = (CAST_S_table3[BYTE2(v15)]
       + (CAST_S_table1[(unsigned __int8)v15] ^ CAST_S_table0[BYTE1(v15)])
       - CAST_S_table2[HIBYTE(v15)])
      ^ v12;
  v17 = __ROL4__(v16 ^ a2[14], a2[15]);
  v18 = CAST_S_table3[BYTE2(v17)]
      ^ (CAST_S_table2[HIBYTE(v17)] + CAST_S_table0[BYTE1(v17)] - CAST_S_table1[(unsigned __int8)v17])
      ^ v14;
  v19 = __ROL4__(a2[16] - v18, a2[17]);
  v20 = ((CAST_S_table2[HIBYTE(v19)] ^ (CAST_S_table1[(unsigned __int8)v19] + CAST_S_table0[BYTE1(v19)]))
       - CAST_S_table3[BYTE2(v19)])
      ^ v16;
  v21 = __ROL4__(v20 + a2[18], a2[19]);
  v22 = (CAST_S_table3[BYTE2(v21)]
       + (CAST_S_table1[(unsigned __int8)v21] ^ CAST_S_table0[BYTE1(v21)])
       - CAST_S_table2[HIBYTE(v21)])
      ^ v18;
  v23 = __ROL4__(v22 ^ a2[20], a2[21]);
  v24 = CAST_S_table3[BYTE2(v23)]
      ^ (CAST_S_table2[HIBYTE(v23)] + CAST_S_table0[BYTE1(v23)] - CAST_S_table1[(unsigned __int8)v23])
      ^ v20;
  v25 = __ROL4__(a2[22] - v24, a2[23]);
  v26 = ((CAST_S_table2[HIBYTE(v25)] ^ (CAST_S_table1[(unsigned __int8)v25] + CAST_S_table0[BYTE1(v25)]))
       - CAST_S_table3[BYTE2(v25)])
      ^ v22;
  if ( !a2[32] )
  {
    v27 = __ROL4__(v26 + a2[24], a2[25]);
    v28 = (CAST_S_table3[BYTE2(v27)]
         + (CAST_S_table1[(unsigned __int8)v27] ^ CAST_S_table0[BYTE1(v27)])
         - CAST_S_table2[HIBYTE(v27)])
        ^ v24;
    v29 = __ROL4__(v28 ^ a2[26], a2[27]);
    v30 = CAST_S_table3[BYTE2(v29)]
        ^ (CAST_S_table2[HIBYTE(v29)] + CAST_S_table0[BYTE1(v29)] - CAST_S_table1[(unsigned __int8)v29])
        ^ v26;
    v31 = __ROL4__(a2[28] - v30, a2[29]);
    v24 = ((CAST_S_table2[HIBYTE(v31)] ^ (CAST_S_table1[(unsigned __int8)v31] + CAST_S_table0[BYTE1(v31)]))
         - CAST_S_table3[BYTE2(v31)])
        ^ v28;
    v32 = __ROL4__(v24 + a2[30], a2[31]);
    v26 = (CAST_S_table3[BYTE2(v32)]
         + (CAST_S_table1[(unsigned __int8)v32] ^ CAST_S_table0[BYTE1(v32)])
         - CAST_S_table2[HIBYTE(v32)])
        ^ v30;
  }
  result = a1;
  a1[1] = v24;
  *a1 = v26;
  return result;
}
