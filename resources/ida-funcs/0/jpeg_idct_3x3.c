char __cdecl jpeg_idct_3x3(int a1, int a2, __int16 *a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // ecx
  int v6; // edx
  int v7; // ebx
  int v8; // edi
  int v9; // ebp
  int v10; // edx
  int v11; // ebx
  int v12; // edi
  int v13; // ebp
  int v14; // esi
  int v15; // edx
  int v16; // ebx
  int v17; // edi
  int v18; // ebx
  _BYTE *v19; // esi
  int v20; // ecx
  int v21; // eax
  int v22; // ebp
  int v23; // ebx
  _BYTE *v24; // esi
  int v25; // ecx
  int v26; // edx
  _BYTE *v27; // esi
  int v28; // ecx
  char result; // al
  int v30; // [esp+10h] [ebp-24h]
  int v31; // [esp+1Ch] [ebp-18h]
  int v32; // [esp+20h] [ebp-14h]
  int v33; // [esp+24h] [ebp-10h]
  int v34; // [esp+28h] [ebp-Ch]
  int v35; // [esp+2Ch] [ebp-8h]

  v5 = *(_DWORD **)(a2 + 84);
  v6 = ((*v5 * *a3) << 13) + 1024;
  v7 = 5793 * v5[16] * a3[16] + v6;
  v8 = 10033 * v5[8] * a3[8];
  v9 = v7 + v8;
  v31 = (v6 - 11586 * v5[16] * a3[16]) >> 11;
  v10 = ((v5[1] * a3[1]) << 13) + 1024;
  v34 = (v7 - v8) >> 11;
  v11 = 5793 * v5[17] * a3[17] + v10;
  v12 = 10033 * v5[9] * a3[9];
  v30 = v9 >> 11;
  v13 = v11 + v12;
  v32 = (v10 - 11586 * v5[17] * a3[17]) >> 11;
  v14 = 10033 * v5[10] * a3[10];
  v15 = ((v5[2] * a3[2]) << 13) + 1024;
  v35 = (v11 - v12) >> 11;
  v16 = 5793 * v5[18] * a3[18] + v15;
  v17 = 5793 * ((v16 + v14) >> 11);
  v18 = v16 - v14;
  v33 = (v15 - 11586 * v5[18] * a3[18]) >> 11;
  v19 = (_BYTE *)(a5 + *a4);
  v20 = (v30 + 16) << 13;
  v21 = *(_DWORD *)(a1 + 292) + 128;
  v22 = 10033 * (v13 >> 11);
  v23 = 5793 * (v18 >> 11);
  *v19 = *(_BYTE *)((((v17 + v20 + v22) >> 18) & 0x3FF) + v21);
  v19[2] = *(_BYTE *)((((v17 + v20 - v22) >> 18) & 0x3FF) + v21);
  v19[1] = *(_BYTE *)((((v20 - 2 * v17) >> 18) & 0x3FF) + v21);
  v24 = (_BYTE *)(a5 + a4[1]);
  v25 = (v31 + 16) << 13;
  v26 = 5793 * v33 + v25;
  *v24 = *(_BYTE *)((((v26 + 10033 * v32) >> 18) & 0x3FF) + v21);
  v24[2] = *(_BYTE *)((((v26 - 10033 * v32) >> 18) & 0x3FF) + v21);
  v24[1] = *(_BYTE *)((((v25 - 11586 * v33) >> 18) & 0x3FF) + v21);
  v27 = (_BYTE *)(a5 + a4[2]);
  v28 = (v34 + 16) << 13;
  *v27 = *(_BYTE *)((((v23 + v28 + 10033 * v35) >> 18) & 0x3FF) + v21);
  v27[2] = *(_BYTE *)((((v23 + v28 - 10033 * v35) >> 18) & 0x3FF) + v21);
  result = *(_BYTE *)((((v28 - 2 * v23) >> 18) & 0x3FF) + v21);
  v27[1] = result;
  return result;
}
