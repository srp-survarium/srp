void __cdecl SEED_set_key(const unsigned __int8 *rawkey, seed_key_st *ks)
{
  unsigned int v2; // edi
  unsigned int v3; // ebp
  unsigned int v4; // ecx
  unsigned int v5; // esi
  unsigned int v7; // edx
  unsigned int v8; // ebp
  unsigned int v9; // ebx
  unsigned int v10; // edi
  unsigned int v11; // ecx
  unsigned int v12; // ebp
  unsigned int v13; // esi
  unsigned int v14; // edx
  unsigned int v15; // ebp
  unsigned int v16; // edi
  unsigned int v17; // ecx
  unsigned int v18; // ebp
  unsigned int v19; // esi
  unsigned int v20; // edx
  unsigned int v21; // ebp
  unsigned int v22; // edi
  unsigned int v23; // ecx
  unsigned int v24; // ebp
  unsigned int v25; // ecx
  unsigned int v26; // esi
  unsigned int v27; // edi
  int v28; // ebp
  unsigned int v29; // edx
  unsigned int v30; // ecx
  unsigned int v31; // [esp+10h] [ebp-4h]
  unsigned int v32; // [esp+1Ch] [ebp+8h]
  unsigned int v33; // [esp+1Ch] [ebp+8h]
  unsigned int v34; // [esp+1Ch] [ebp+8h]
  unsigned int v35; // [esp+1Ch] [ebp+8h]
  unsigned int v36; // [esp+1Ch] [ebp+8h]
  int v37; // [esp+1Ch] [ebp+8h]

  v2 = rawkey[3] | ((rawkey[2] | ((rawkey[1] | (*rawkey << 8)) << 8)) << 8);
  v3 = rawkey[7] | ((rawkey[6] | ((rawkey[5] | (rawkey[4] << 8)) << 8)) << 8);
  v4 = rawkey[11] | ((rawkey[10] | ((rawkey[9] | (rawkey[8] << 8)) << 8)) << 8);
  v5 = rawkey[15] | ((rawkey[14] | ((rawkey[13] | (rawkey[12] << 8)) << 8)) << 8);
  ks->data[0] = dword_6D31F8[0][(unsigned __int8)(v4 + v2 + 71)]
              ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v4 + v2 - 31161) >> 8)]
              ^ dword_6D31F8[2][(unsigned __int8)((v4 + v2 + 1640531527) >> 16)]
              ^ dword_6D31F8[3][(v4 + v2 + 1640531527) >> 24];
  ks->data[1] = dword_6D31F8[0][(unsigned __int8)(v3 - v5 - 71)]
              ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v3 - v5 + 31161) >> 8)]
              ^ dword_6D31F8[2][(unsigned __int8)((v3 - v5 - 1640531527) >> 16)]
              ^ dword_6D31F8[3][(v3 - v5 - 1640531527) >> 24];
  v7 = (v2 >> 8) ^ (v3 << 24);
  v8 = (v3 >> 8) ^ (v2 << 24);
  ks->data[2] = dword_6D31F8[0][(unsigned __int8)(v4 + BYTE1(v2) - 115)]
              ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v4 + v7 + 3213) >> 8)]
              ^ dword_6D31F8[2][(unsigned __int8)((v4 + v7 - 1013904243) >> 16)]
              ^ dword_6D31F8[3][(v4 + v7 - 1013904243) >> 24];
  ks->data[3] = dword_6D31F8[0][(unsigned __int8)(v8 - v5 + 115)]
              ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v8 - v5 - 3213) >> 8)]
              ^ dword_6D31F8[2][(unsigned __int8)((v8 - v5 + 1013904243) >> 16)]
              ^ dword_6D31F8[3][(v8 - v5 + 1013904243) >> 24];
  v9 = (v5 << 8) ^ HIBYTE(v4);
  v10 = (v4 << 8) ^ HIBYTE(v5);
  ks->data[4] = dword_6D31F8[0][(unsigned __int8)(HIBYTE(v5) + v7 + 26)]
              ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)((((_WORD)v4 << 8) ^ HIBYTE(v5)) + v7 + 6426) >> 8)]
              ^ dword_6D31F8[2][(unsigned __int8)((v10 + v7 - 2027808486) >> 16)]
              ^ dword_6D31F8[3][(v10 + v7 - 2027808486) >> 24];
  ks->data[5] = dword_6D31F8[0][(unsigned __int8)(v8 - v9 - 26)]
              ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v8 - v9 - 6426) >> 8)]
              ^ dword_6D31F8[2][(unsigned __int8)((v8 - v9 + 2027808486) >> 16)]
              ^ dword_6D31F8[3][(v8 - v9 + 2027808486) >> 24];
  v11 = (v7 >> 8) ^ (v8 << 24);
  v12 = (v8 >> 8) ^ (v7 << 24);
  ks->data[6] = dword_6D31F8[0][(unsigned __int8)(v10 + v11 + 52)]
              ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v10 + v11 + 12852) >> 8)]
              ^ dword_6D31F8[2][(unsigned __int8)((v10 + v11 + 239350324) >> 16)]
              ^ dword_6D31F8[3][(v10 + v11 + 239350324) >> 24];
  ks->data[7] = dword_6D31F8[0][(unsigned __int8)(v12 - v9 - 52)]
              ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v12 - v9 - 12852) >> 8)]
              ^ dword_6D31F8[2][(unsigned __int8)((v12 - v9 - 239350324) >> 16)]
              ^ dword_6D31F8[3][(v12 - v9 - 239350324) >> 24];
  v13 = (v10 << 8) ^ HIBYTE(v9);
  v32 = (v9 << 8) ^ HIBYTE(v10);
  ks->data[8] = dword_6D31F8[0][(unsigned __int8)(v13 + v11 + 103)]
              ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v13 + v11 + 25703) >> 8)]
              ^ dword_6D31F8[2][(unsigned __int8)((v13 + v11 + 478700647) >> 16)]
              ^ dword_6D31F8[3][(v13 + v11 + 478700647) >> 24];
  ks->data[9] = dword_6D31F8[0][(unsigned __int8)(v12 - v32 - 103)]
              ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v12 - v32 - 25703) >> 8)]
              ^ dword_6D31F8[2][(unsigned __int8)((v12 - v32 - 478700647) >> 16)]
              ^ dword_6D31F8[3][(v12 - v32 - 478700647) >> 24];
  v14 = (v11 >> 8) ^ (v12 << 24);
  v15 = (v12 >> 8) ^ (v11 << 24);
  ks->data[10] = dword_6D31F8[0][(unsigned __int8)(v13 + v14 - 51)]
               ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v13 + v14 - 14131) >> 8)]
               ^ dword_6D31F8[2][(unsigned __int8)((v13 + v14 + 957401293) >> 16)]
               ^ dword_6D31F8[3][(v13 + v14 + 957401293) >> 24];
  ks->data[11] = dword_6D31F8[0][(unsigned __int8)(v15 - v32 + 51)]
               ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v15 - v32 + 14131) >> 8)]
               ^ dword_6D31F8[2][(unsigned __int8)((v15 - v32 - 957401293) >> 16)]
               ^ dword_6D31F8[3][(v15 - v32 - 957401293) >> 24];
  v16 = (v13 << 8) ^ HIBYTE(v32);
  v33 = (v32 << 8) ^ HIBYTE(v13);
  ks->data[12] = dword_6D31F8[0][(unsigned __int8)(v16 + v14 - 103)]
               ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v16 + v14 - 28263) >> 8)]
               ^ dword_6D31F8[2][(unsigned __int8)((v16 + v14 + 1914802585) >> 16)]
               ^ dword_6D31F8[3][(v16 + v14 + 1914802585) >> 24];
  ks->data[13] = dword_6D31F8[0][(unsigned __int8)(v15 - v33 + 103)]
               ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v15 - v33 + 28263) >> 8)]
               ^ dword_6D31F8[2][(unsigned __int8)((v15 - v33 - 1914802585) >> 16)]
               ^ dword_6D31F8[3][(v15 - v33 - 1914802585) >> 24];
  v17 = (v14 >> 8) ^ (v15 << 24);
  v18 = (v15 >> 8) ^ (v14 << 24);
  ks->data[14] = dword_6D31F8[0][(unsigned __int8)(v16 + v17 + 49)]
               ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v16 + v17 + 9009) >> 8)]
               ^ dword_6D31F8[2][(unsigned __int8)((v16 + v17 - 465362127) >> 16)]
               ^ dword_6D31F8[3][(v16 + v17 - 465362127) >> 24];
  ks->data[15] = dword_6D31F8[0][(unsigned __int8)(v18 - v33 - 49)]
               ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v18 - v33 - 9009) >> 8)]
               ^ dword_6D31F8[2][(unsigned __int8)((v18 - v33 + 465362127) >> 16)]
               ^ dword_6D31F8[3][(v18 - v33 + 465362127) >> 24];
  v19 = (v16 << 8) ^ HIBYTE(v33);
  v34 = (v33 << 8) ^ HIBYTE(v16);
  ks->data[16] = dword_6D31F8[0][(unsigned __int8)(v19 + v17 + 98)]
               ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v19 + v17 + 18018) >> 8)]
               ^ dword_6D31F8[2][(unsigned __int8)((v19 + v17 - 930724254) >> 16)]
               ^ dword_6D31F8[3][(v19 + v17 - 930724254) >> 24];
  ks->data[17] = dword_6D31F8[0][(unsigned __int8)(v18 - v34 - 98)]
               ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v18 - v34 - 18018) >> 8)]
               ^ dword_6D31F8[2][(unsigned __int8)((v18 - v34 + 930724254) >> 16)]
               ^ dword_6D31F8[3][(v18 - v34 + 930724254) >> 24];
  v20 = (v17 >> 8) ^ (v18 << 24);
  v21 = (v18 >> 8) ^ (v17 << 24);
  ks->data[18] = dword_6D31F8[0][(unsigned __int8)(v19 + v20 - 60)]
               ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v19 + v20 - 29500) >> 8)]
               ^ dword_6D31F8[2][(unsigned __int8)((v19 + v20 - 1861448508) >> 16)]
               ^ dword_6D31F8[3][(v19 + v20 - 1861448508) >> 24];
  ks->data[19] = dword_6D31F8[0][(unsigned __int8)(v21 - v34 + 60)]
               ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v21 - v34 + 29500) >> 8)]
               ^ dword_6D31F8[2][(unsigned __int8)((v21 - v34 + 1861448508) >> 16)]
               ^ dword_6D31F8[3][(v21 - v34 + 1861448508) >> 24];
  v22 = (v19 << 8) ^ HIBYTE(v34);
  v35 = (v34 << 8) ^ HIBYTE(v19);
  ks->data[20] = dword_6D31F8[0][(unsigned __int8)(v22 + v20 - 120)]
               ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v22 + v20 + 6536) >> 8)]
               ^ dword_6D31F8[2][(unsigned __int8)((v22 + v20 + 572070280) >> 16)]
               ^ dword_6D31F8[3][(v22 + v20 + 572070280) >> 24];
  v23 = v21;
  ks->data[21] = dword_6D31F8[0][(unsigned __int8)(v21 - v35 + 120)]
               ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v21 - v35 - 6536) >> 8)]
               ^ dword_6D31F8[2][(unsigned __int8)((v21 - v35 - 572070280) >> 16)]
               ^ dword_6D31F8[3][(v21 - v35 - 572070280) >> 24];
  v24 = (v21 >> 8) ^ (v20 << 24);
  v25 = (v20 >> 8) ^ (v23 << 24);
  ks->data[22] = dword_6D31F8[0][(unsigned __int8)(v22 + v25 + 15)]
               ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v22 + v25 + 13071) >> 8)]
               ^ dword_6D31F8[2][(unsigned __int8)((v22 + v25 + 1144140559) >> 16)]
               ^ dword_6D31F8[3][(v22 + v25 + 1144140559) >> 24];
  ks->data[23] = dword_6D31F8[0][(unsigned __int8)(v24 - v35 - 15)]
               ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v24 - v35 - 13071) >> 8)]
               ^ dword_6D31F8[2][(unsigned __int8)((v24 - v35 - 1144140559) >> 16)]
               ^ dword_6D31F8[3][(v24 - v35 - 1144140559) >> 24];
  v26 = (v22 << 8) ^ HIBYTE(v35);
  v36 = (v35 << 8) ^ HIBYTE(v22);
  ks->data[24] = dword_6D31F8[0][(unsigned __int8)(v26 + v25 + 29)]
               ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v26 + v25 + 26141) >> 8)]
               ^ dword_6D31F8[2][(unsigned __int8)((v26 + v25 - 2006686179) >> 16)]
               ^ dword_6D31F8[3][(v26 + v25 - 2006686179) >> 24];
  ks->data[25] = dword_6D31F8[0][(unsigned __int8)(v24 - v36 - 29)]
               ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v24 - v36 - 26141) >> 8)]
               ^ dword_6D31F8[2][(unsigned __int8)((v24 - v36 + 2006686179) >> 16)]
               ^ dword_6D31F8[3][(v24 - v36 + 2006686179) >> 24];
  v31 = (v25 >> 8) ^ (v24 << 24);
  v27 = (v24 >> 8) ^ (v25 << 24);
  ks->data[26] = dword_6D31F8[0][(unsigned __int8)(v26 + BYTE1(v25) + 58)]
               ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v26 + (v25 >> 8) - 13254) >> 8)]
               ^ dword_6D31F8[2][(unsigned __int8)((v26 + v31 + 281594938) >> 16)]
               ^ dword_6D31F8[3][(v26 + v31 + 281594938) >> 24];
  ks->data[27] = dword_6D31F8[0][(unsigned __int8)(v27 - v36 - 58)]
               ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v27 - v36 + 13254) >> 8)]
               ^ dword_6D31F8[2][(unsigned __int8)((v27 - v36 - 281594938) >> 16)]
               ^ dword_6D31F8[3][(v27 - v36 - 281594938) >> 24];
  v28 = (v26 << 8) ^ HIBYTE(v36);
  v37 = (v36 << 8) ^ HIBYTE(v26);
  ks->data[28] = dword_6D31F8[0][(unsigned __int8)(v31 + v28 + 115)]
               ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v31 + v28 - 26509) >> 8)]
               ^ dword_6D31F8[2][(unsigned __int8)((v31 + v28 + 563189875) >> 16)]
               ^ dword_6D31F8[3][(v31 + v28 + 563189875) >> 24];
  ks->data[29] = dword_6D31F8[0][(unsigned __int8)(v27 - v37 - 115)]
               ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v27 - v37 + 26509) >> 8)]
               ^ dword_6D31F8[2][(unsigned __int8)((v27 - v37 - 563189875) >> 16)]
               ^ dword_6D31F8[3][(v27 - v37 - 563189875) >> 24];
  v29 = ((v31 >> 8) ^ (v27 << 24)) + v28 + 1126379749;
  v30 = ((v27 >> 8) ^ (v31 << 24)) - v37 - 1126379749;
  ks->data[30] = dword_6D31F8[0][(unsigned __int8)v29]
               ^ dword_6D31F8[1][BYTE1(v29)]
               ^ dword_6D31F8[2][BYTE2(v29)]
               ^ dword_6D31F8[3][HIBYTE(v29)];
  ks->data[31] = dword_6D31F8[0][(unsigned __int8)v30]
               ^ dword_6D31F8[1][BYTE1(v30)]
               ^ dword_6D31F8[2][BYTE2(v30)]
               ^ dword_6D31F8[3][HIBYTE(v30)];
}
