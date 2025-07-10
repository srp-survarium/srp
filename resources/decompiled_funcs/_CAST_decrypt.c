unsigned int *__cdecl CAST_decrypt(unsigned int *a1, _DWORD *a2)
{
  unsigned int v2; // edi
  unsigned int v3; // esi
  int v4; // edx
  unsigned int v5; // edi
  int v6; // edx
  unsigned int v7; // esi
  int v8; // edx
  int v9; // edx
  int v10; // edx
  unsigned int v11; // edi
  int v12; // edx
  unsigned int v13; // esi
  int v14; // edx
  unsigned int v15; // edi
  int v16; // edx
  unsigned int v17; // esi
  int v18; // edx
  unsigned int v19; // edi
  int v20; // edx
  unsigned int v21; // esi
  int v22; // edx
  unsigned int v23; // edi
  int v24; // edx
  unsigned int v25; // esi
  int v26; // edx
  unsigned int v27; // edi
  int v28; // edx
  unsigned int v29; // esi
  int v30; // edx
  unsigned int v31; // edi
  int v32; // edx
  unsigned int v33; // esi
  unsigned int *result; // eax

  v2 = *a1;
  v3 = a1[1];
  if ( !a2[32] )
  {
    v4 = __ROL4__(v3 + a2[30], a2[31]);
    v5 = (CAST_S_table3[BYTE2(v4)]
        + (CAST_S_table1[(unsigned __int8)v4] ^ CAST_S_table0[BYTE1(v4)])
        - CAST_S_table2[HIBYTE(v4)])
       ^ v2;
    v6 = __ROL4__(a2[28] - v5, a2[29]);
    v7 = ((CAST_S_table2[HIBYTE(v6)] ^ (CAST_S_table1[(unsigned __int8)v6] + CAST_S_table0[BYTE1(v6)]))
        - CAST_S_table3[BYTE2(v6)])
       ^ v3;
    v8 = __ROL4__(v7 ^ a2[26], a2[27]);
    v2 = CAST_S_table3[BYTE2(v8)]
       ^ (CAST_S_table2[HIBYTE(v8)] + CAST_S_table0[BYTE1(v8)] - CAST_S_table1[(unsigned __int8)v8])
       ^ v5;
    v9 = __ROL4__(v2 + a2[24], a2[25]);
    v3 = (CAST_S_table3[BYTE2(v9)]
        + (CAST_S_table1[(unsigned __int8)v9] ^ CAST_S_table0[BYTE1(v9)])
        - CAST_S_table2[HIBYTE(v9)])
       ^ v7;
  }
  v10 = __ROL4__(a2[22] - v3, a2[23]);
  v11 = ((CAST_S_table2[HIBYTE(v10)] ^ (CAST_S_table1[(unsigned __int8)v10] + CAST_S_table0[BYTE1(v10)]))
       - CAST_S_table3[BYTE2(v10)])
      ^ v2;
  v12 = __ROL4__(v11 ^ a2[20], a2[21]);
  v13 = CAST_S_table3[BYTE2(v12)]
      ^ (CAST_S_table2[HIBYTE(v12)] + CAST_S_table0[BYTE1(v12)] - CAST_S_table1[(unsigned __int8)v12])
      ^ v3;
  v14 = __ROL4__(v13 + a2[18], a2[19]);
  v15 = (CAST_S_table3[BYTE2(v14)]
       + (CAST_S_table1[(unsigned __int8)v14] ^ CAST_S_table0[BYTE1(v14)])
       - CAST_S_table2[HIBYTE(v14)])
      ^ v11;
  v16 = __ROL4__(a2[16] - v15, a2[17]);
  v17 = ((CAST_S_table2[HIBYTE(v16)] ^ (CAST_S_table1[(unsigned __int8)v16] + CAST_S_table0[BYTE1(v16)]))
       - CAST_S_table3[BYTE2(v16)])
      ^ v13;
  v18 = __ROL4__(v17 ^ a2[14], a2[15]);
  v19 = CAST_S_table3[BYTE2(v18)]
      ^ (CAST_S_table2[HIBYTE(v18)] + CAST_S_table0[BYTE1(v18)] - CAST_S_table1[(unsigned __int8)v18])
      ^ v15;
  v20 = __ROL4__(v19 + a2[12], a2[13]);
  v21 = (CAST_S_table3[BYTE2(v20)]
       + (CAST_S_table1[(unsigned __int8)v20] ^ CAST_S_table0[BYTE1(v20)])
       - CAST_S_table2[HIBYTE(v20)])
      ^ v17;
  v22 = __ROL4__(a2[10] - v21, a2[11]);
  v23 = ((CAST_S_table2[HIBYTE(v22)] ^ (CAST_S_table1[(unsigned __int8)v22] + CAST_S_table0[BYTE1(v22)]))
       - CAST_S_table3[BYTE2(v22)])
      ^ v19;
  v24 = __ROL4__(v23 ^ a2[8], a2[9]);
  v25 = CAST_S_table3[BYTE2(v24)]
      ^ (CAST_S_table2[HIBYTE(v24)] + CAST_S_table0[BYTE1(v24)] - CAST_S_table1[(unsigned __int8)v24])
      ^ v21;
  v26 = __ROL4__(v25 + a2[6], a2[7]);
  v27 = (CAST_S_table3[BYTE2(v26)]
       + (CAST_S_table1[(unsigned __int8)v26] ^ CAST_S_table0[BYTE1(v26)])
       - CAST_S_table2[HIBYTE(v26)])
      ^ v23;
  v28 = __ROL4__(a2[4] - v27, a2[5]);
  v29 = ((CAST_S_table2[HIBYTE(v28)] ^ (CAST_S_table1[(unsigned __int8)v28] + CAST_S_table0[BYTE1(v28)]))
       - CAST_S_table3[BYTE2(v28)])
      ^ v25;
  v30 = __ROL4__(v29 ^ a2[2], a2[3]);
  v31 = CAST_S_table3[BYTE2(v30)]
      ^ (CAST_S_table2[HIBYTE(v30)] + CAST_S_table0[BYTE1(v30)] - CAST_S_table1[(unsigned __int8)v30])
      ^ v27;
  v32 = __ROL4__(v31 + *a2, a2[1]);
  v33 = (CAST_S_table3[BYTE2(v32)]
       + (CAST_S_table1[(unsigned __int8)v32] ^ CAST_S_table0[BYTE1(v32)])
       - CAST_S_table2[HIBYTE(v32)])
      ^ v29;
  result = a1;
  a1[1] = v31;
  *a1 = v33;
  return result;
}
