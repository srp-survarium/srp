char __cdecl jpeg_idct_2x1(int a1, int a2, __int16 *a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // edx
  _BYTE *v6; // esi
  int v7; // edi
  int v8; // eax
  int v9; // ecx
  char result; // al

  v5 = *(_DWORD **)(a2 + 84);
  v6 = (_BYTE *)(a5 + *a4);
  v7 = v5[1] * a3[1];
  v8 = *v5 * *a3 + 4;
  v9 = *(_DWORD *)(a1 + 292) + 128;
  *v6 = *(_BYTE *)((((v7 + v8) >> 3) & 0x3FF) + v9);
  result = *(_BYTE *)((((v8 - v7) >> 3) & 0x3FF) + v9);
  v6[1] = result;
  return result;
}
