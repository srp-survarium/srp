char __cdecl jpeg_idct_2x4(int a1, int a2, __int16 *a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // ecx
  int v6; // ebp
  int v7; // esi
  int v8; // edi
  int v9; // ebx
  int v10; // esi
  int v11; // edi
  int v13; // esi
  int v14; // edi
  int v15; // esi
  int v16; // ebp
  int v17; // ebx
  int v18; // edi
  int v19; // esi
  int v20; // edi
  int v21; // ebx
  int v22; // esi
  int v23; // edi
  int v24; // edx
  int v25; // ecx
  int v26; // edi
  int v27; // ecx
  int v28; // edx
  int v29; // ebx
  int v30; // edi
  int v31; // esi
  int v32; // eax
  _BYTE *v33; // edi
  _BYTE *v34; // edi
  int v35; // edi
  _BYTE *v36; // esi
  char result; // al
  int v38; // [esp+18h] [ebp-18h]
  int v39; // [esp+1Ch] [ebp-14h]
  int v40; // [esp+20h] [ebp-10h]
  int v41; // [esp+28h] [ebp-8h]
  int v42; // [esp+34h] [ebp+4h]

  v5 = *(_DWORD **)(a2 + 84);
  v6 = v5[24] * a3[24];
  v7 = *v5 * *a3;
  v8 = v5[16] * a3[16];
  v9 = v8 + v7;
  v10 = v7 - v8;
  v11 = v5[8] * a3[8];
  v42 = v10 << 13;
  v13 = 4433 * (v11 + v6);
  v14 = v13 + 6270 * v11;
  v9 <<= 13;
  v15 = v13 - 15137 * v6;
  v16 = v9 + v14;
  v41 = v9 - v14;
  v17 = v42 + v15;
  v18 = v42 - v15;
  v19 = v5[1] * a3[1];
  v40 = v18;
  v20 = v5[17] * a3[17];
  v38 = v17;
  v21 = v20 + v19;
  v22 = v19 - v20;
  v23 = v5[9] * a3[9];
  v24 = v5[25] * a3[25];
  v25 = 4433 * (v24 + v23);
  v26 = v25 + 6270 * v23;
  v27 = v25 - 15137 * v24;
  v21 <<= 13;
  v28 = v21 + v26;
  v29 = v21 - v26;
  v22 <<= 13;
  v30 = v22 + v27;
  v31 = v22 - v27;
  v32 = *(_DWORD *)(a1 + 292) + 128;
  v39 = v30;
  v33 = (_BYTE *)(a5 + *a4);
  *v33 = *(_BYTE *)((((v28 + v16 + 0x8000) >> 16) & 0x3FF) + v32);
  v33[1] = *(_BYTE *)((((v16 + 0x8000 - v28) >> 16) & 0x3FF) + v32);
  v34 = (_BYTE *)(a5 + a4[1]);
  *v34 = *(_BYTE *)((((v39 + v38 + 0x8000) >> 16) & 0x3FF) + v32);
  v34[1] = *(_BYTE *)((((v38 + 0x8000 - v39) >> 16) & 0x3FF) + v32);
  v35 = a4[2];
  *(_BYTE *)(v35 + a5) = *(_BYTE *)((((v31 + v40 + 0x8000) >> 16) & 0x3FF) + v32);
  *(_BYTE *)(a5 + v35 + 1) = *(_BYTE *)((((v40 + 0x8000 - v31) >> 16) & 0x3FF) + v32);
  v36 = (_BYTE *)(a5 + a4[3]);
  *v36 = *(_BYTE *)((((v29 + v41 + 0x8000) >> 16) & 0x3FF) + v32);
  result = *(_BYTE *)((((v41 + 0x8000 - v29) >> 16) & 0x3FF) + v32);
  v36[1] = result;
  return result;
}
