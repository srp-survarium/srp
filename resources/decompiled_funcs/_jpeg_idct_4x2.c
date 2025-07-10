int __cdecl jpeg_idct_4x2(int a1, int a2, __int16 *a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // ecx
  int v6; // esi
  int v7; // edi
  int v8; // ebx
  int v9; // esi
  int v10; // edi
  int v11; // esi
  int v12; // ebp
  int v13; // edi
  int v14; // esi
  int v15; // ebx
  int v16; // edi
  int v17; // ebx
  int v18; // esi
  int v19; // edx
  int v20; // ebx
  _BYTE *v21; // esi
  int v22; // ecx
  int v23; // edi
  int v24; // edx
  int v25; // ebp
  int v26; // edx
  int result; // eax
  _BYTE *v28; // esi
  int v29; // edx
  int v30; // ebx
  int v31; // ebp
  int v32; // ecx
  int v33; // edi
  int v34; // [esp+10h] [ebp-20h]
  int v35; // [esp+20h] [ebp-10h]
  int v36; // [esp+24h] [ebp-Ch]
  int v37; // [esp+28h] [ebp-8h]
  int v38; // [esp+2Ch] [ebp-4h]

  v5 = *(_DWORD **)(a2 + 84);
  v6 = *v5 * *a3;
  v7 = v5[8] * a3[8];
  v8 = v7 + v6;
  v9 = v6 - v7;
  v10 = v5[1] * a3[1];
  v35 = v9;
  v11 = v5[9] * a3[9];
  v12 = v11 + v10;
  v13 = v10 - v11;
  v14 = v5[10] * a3[10];
  v34 = v8;
  v15 = v5[2] * a3[2];
  v36 = v13;
  v16 = v14 + v15;
  v17 = v15 - v14;
  v18 = v5[3] * a3[3];
  v19 = v5[11] * a3[11];
  v37 = v17;
  v20 = v19 + v18;
  v38 = v18 - v19;
  v21 = (_BYTE *)(a5 + *a4);
  v22 = v16 + v34 + 4;
  v23 = (v34 + 4 - v16) << 13;
  v24 = 4433 * (v20 + v12);
  v22 <<= 13;
  v25 = v24 + 6270 * v12;
  v26 = v24 - 15137 * v20;
  result = *(_DWORD *)(a1 + 292) + 128;
  *v21 = *(_BYTE *)((((v22 + v25) >> 16) & 0x3FF) + result);
  v21[3] = *(_BYTE *)((((v22 - v25) >> 16) & 0x3FF) + result);
  v21[1] = *(_BYTE *)((((v23 + v26) >> 16) & 0x3FF) + result);
  v21[2] = *(_BYTE *)((((v23 - v26) >> 16) & 0x3FF) + result);
  v28 = (_BYTE *)(a5 + a4[1]);
  v29 = 4433 * (v36 + v38);
  v30 = v29 + 6270 * v36;
  v31 = v29 - 15137 * v38;
  v32 = (v37 + v35 + 4) << 13;
  *v28 = *(_BYTE *)((((v30 + v32) >> 16) & 0x3FF) + result);
  v33 = (v35 + 4 - v37) << 13;
  v28[3] = *(_BYTE *)((((v32 - v30) >> 16) & 0x3FF) + result);
  v28[1] = *(_BYTE *)((((v33 + v31) >> 16) & 0x3FF) + result);
  v28[2] = *(_BYTE *)((((v33 - v31) >> 16) & 0x3FF) + result);
  return result;
}
