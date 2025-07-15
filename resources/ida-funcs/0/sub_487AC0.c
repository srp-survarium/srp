int __cdecl sub_487AC0(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 432);
  *(_BYTE *)(result + 36) = 0;
  *(_DWORD *)(result + 44) = *(_DWORD *)(a1 + 96);
  return result;
}
