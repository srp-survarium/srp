void __cdecl sub_36F9B0(int a1, int a2, int a3)
{
  int v3; // [esp+0h] [ebp-8h]

  *(_DWORD *)(a1 + 120) = a2;
  *(_DWORD *)(a1 + 124) = 0;
  do
  {
    if ( !*(_DWORD *)(a1 + 124) )
    {
      *(_DWORD *)(a1 + 124) = a3;
      a3 = 0;
    }
    if ( deflate((z_stream_s *)(a1 + 120), 0) )
    {
      if ( *(_DWORD *)(a1 + 144) )
        png_error(a1, *(_DWORD *)(a1 + 144));
      png_error(a1, (int)"zlib error");
    }
    if ( !*(_DWORD *)(a1 + 136) )
      png_write_IDAT(a1, *(unsigned __int8 **)(a1 + 176), *(_DWORD *)(a1 + 180));
  }
  while ( a3 || *(_DWORD *)(a1 + 124) );
  if ( *(_DWORD *)(a1 + 260) )
  {
    v3 = *(_DWORD *)(a1 + 260);
    *(_DWORD *)(a1 + 260) = *(_DWORD *)(a1 + 264);
    *(_DWORD *)(a1 + 264) = v3;
  }
  png_write_finish_row(a1);
  ++*(_DWORD *)(a1 + 368);
  if ( *(_DWORD *)(a1 + 364) && *(_DWORD *)(a1 + 368) >= *(_DWORD *)(a1 + 364) )
    png_write_flush(a1);
}
