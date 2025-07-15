int __cdecl png_write_chunk_end(int a1)
{
  int v1; // ecx
  int result; // eax
  int v3; // [esp+0h] [ebp-4h] BYREF

  v3 = v1;
  if ( a1 )
  {
    *(_DWORD *)(a1 + 684) = 130;
    png_save_uint_32(&v3, *(_DWORD *)(a1 + 292));
    return png_write_data(a1, (int)&v3, 4);
  }
  return result;
}
