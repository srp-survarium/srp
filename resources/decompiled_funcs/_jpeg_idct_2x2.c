char __cdecl jpeg_idct_2x2(int a1, int a2, __int16 *a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // edi
  int v6; // esi
  int v7; // eax
  int v8; // edx
  int v9; // esi
  int v10; // eax
  int v11; // ebx
  _BYTE *v12; // edi
  int v13; // ebp
  int v14; // eax
  int v15; // ecx
  _BYTE *v16; // edx
  char result; // al

  v5 = *(_DWORD **)(a2 + 84);
  v6 = v5[8] * a3[8];
  v7 = *v5 * *a3 + 4;
  v8 = v6 + v7;
  v9 = v7 - v6;
  v10 = v5[1] * a3[1];
  v11 = v5[9] * a3[9];
  v12 = (_BYTE *)(a5 + *a4);
  v13 = v11 + v10;
  v14 = v10 - v11;
  v15 = *(_DWORD *)(a1 + 292) + 128;
  *v12 = *(_BYTE *)((((v8 + v13) >> 3) & 0x3FF) + v15);
  v12[1] = *(_BYTE *)((((v8 - v13) >> 3) & 0x3FF) + v15);
  v16 = (_BYTE *)(a5 + a4[1]);
  *v16 = *(_BYTE *)((((v14 + v9) >> 3) & 0x3FF) + v15);
  result = *(_BYTE *)((((v9 - v14) >> 3) & 0x3FF) + v15);
  v16[1] = result;
  return result;
}
