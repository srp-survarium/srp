int __cdecl jpeg_alloc_huff_table(int a1)
{
  int result; // eax

  result = (**(int (__cdecl ***)(int, _DWORD, int))(a1 + 4))(a1, 0, 274);
  *(_BYTE *)(result + 273) = 0;
  return result;
}
