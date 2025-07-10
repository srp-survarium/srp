void __cdecl png_write_flush(int a1)
{
  int v1; // [esp+4h] [ebp-4h]

  if ( a1 && *(_DWORD *)(a1 + 252) < *(_DWORD *)(a1 + 236) )
  {
    do
    {
      v1 = 0;
      if ( deflate((z_stream_s *)(a1 + 120), 2) )
      {
        if ( *(_DWORD *)(a1 + 144) )
          png_error(a1, *(_DWORD *)(a1 + 144));
        png_error(a1, (int)"zlib error");
      }
      if ( !*(_DWORD *)(a1 + 136) )
      {
        png_write_IDAT(a1, *(unsigned __int8 **)(a1 + 176), *(_DWORD *)(a1 + 180));
        v1 = 1;
      }
    }
    while ( v1 == 1 );
    if ( *(_DWORD *)(a1 + 180) != *(_DWORD *)(a1 + 136) )
      png_write_IDAT(a1, *(unsigned __int8 **)(a1 + 176), *(_DWORD *)(a1 + 180) - *(_DWORD *)(a1 + 136));
    *(_DWORD *)(a1 + 368) = 0;
    png_flush(a1);
  }
}
