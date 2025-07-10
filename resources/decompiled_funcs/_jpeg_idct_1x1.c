int __cdecl jpeg_idct_1x1(int a1, int a2, __int16 *a3, _DWORD *a4, int a5)
{
  int result; // eax

  result = a5;
  *(_BYTE *)(a5 + *a4) = *(_BYTE *)((((**(_DWORD **)(a2 + 84) * *a3 + 4) >> 3) & 0x3FF) + *(_DWORD *)(a1 + 292) + 128);
  return result;
}
