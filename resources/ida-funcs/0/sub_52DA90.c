int __cdecl sub_52DA90(int a1, int a2)
{
  int result; // eax

  *(_BYTE *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 12) = 0;
  result = a1;
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 16) = a2;
  return result;
}
