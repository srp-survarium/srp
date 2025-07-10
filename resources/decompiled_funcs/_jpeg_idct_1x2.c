char __cdecl jpeg_idct_1x2(int a1, int a2, __int16 *a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // edx
  int v6; // esi
  int v7; // eax
  int v8; // ecx
  char result; // al

  v5 = *(_DWORD **)(a2 + 84);
  v6 = v5[8] * a3[8];
  v7 = *v5 * *a3 + 4;
  v8 = *(_DWORD *)(a1 + 292) + 128;
  *(_BYTE *)(*a4 + a5) = *(_BYTE *)((((v6 + v7) >> 3) & 0x3FF) + v8);
  result = *(_BYTE *)((((v7 - v6) >> 3) & 0x3FF) + v8);
  *(_BYTE *)(a4[1] + a5) = result;
  return result;
}
