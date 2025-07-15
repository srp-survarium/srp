int __cdecl png_check_chunk_name(int a1, unsigned int a2)
{
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 1; i <= 4; ++i )
  {
    if ( (unsigned __int8)a2 < 0x41u
      || (unsigned __int8)a2 > 0x7Au
      || (unsigned __int8)a2 > 0x5Au && (unsigned __int8)a2 < 0x61u )
    {
      png_chunk_error(a1, (int)"invalid chunk type");
    }
    a2 >>= 8;
    result = i + 1;
  }
  return result;
}
