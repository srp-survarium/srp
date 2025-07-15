int __cdecl png_write_hIST(int a1, int a2, int a3)
{
  unsigned __int8 buf[4]; // [esp+0h] [ebp-8h] BYREF
  int i; // [esp+4h] [ebp-4h]

  if ( a3 > *(unsigned __int16 *)(a1 + 300) )
    return png_warning(a1, "Invalid number of histogram entries specified");
  sub_36AD20((_DWORD *)a1, 1749635924, 2 * a3);
  for ( i = 0; i < a3; ++i )
  {
    png_save_uint_16(buf, *(_WORD *)(a2 + 2 * i));
    png_write_chunk_data((_DWORD *)a1, buf, 2);
  }
  return png_write_chunk_end(a1);
}
