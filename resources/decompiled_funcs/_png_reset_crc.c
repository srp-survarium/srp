unsigned int __cdecl png_reset_crc(int a1)
{
  unsigned int result; // eax

  result = crc32(0, 0, 0);
  *(_DWORD *)(a1 + 292) = result;
  return result;
}
