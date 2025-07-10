unsigned int __cdecl sub_364840(int a1, int a2, int a3, int a4, unsigned int a5)
{
  int count; // [esp+8h] [ebp-14h]
  int v7; // [esp+10h] [ebp-Ch]
  unsigned int v8; // [esp+14h] [ebp-8h]
  unsigned int v9; // [esp+18h] [ebp-4h]

  v9 = 0;
  *(_DWORD *)(a1 + 120) = a2;
  *(_DWORD *)(a1 + 124) = 0;
  do
  {
    if ( !*(_DWORD *)(a1 + 124) && a3 )
    {
      *(_DWORD *)(a1 + 124) = a3;
      a3 = 0;
    }
    *(_DWORD *)(a1 + 132) = *(_DWORD *)(a1 + 176);
    *(_DWORD *)(a1 + 136) = *(_DWORD *)(a1 + 180);
    v8 = inflate((z_stream_s *)(a1 + 120), 0);
    v7 = *(_DWORD *)(a1 + 180) - *(_DWORD *)(a1 + 136);
    if ( v8 <= 1 && v7 > 0 )
    {
      if ( a4 && a5 > v9 )
      {
        count = a5 - v9;
        if ( v7 < a5 - v9 )
          count = *(_DWORD *)(a1 + 180) - *(_DWORD *)(a1 + 136);
        memcpy((unsigned __int8 *)(v9 + a4), *(unsigned __int8 **)(a1 + 176), count);
      }
      v9 += v7;
    }
  }
  while ( !v8 );
  *(_DWORD *)(a1 + 124) = 0;
  inflateReset((z_stream_s *)(a1 + 120));
  if ( v8 == 1 )
    return v9;
  if ( *(_DWORD *)(a1 + 144) )
  {
    png_chunk_warning(a1, *(_BYTE **)(a1 + 144));
  }
  else if ( v8 == -5 )
  {
    png_chunk_warning(a1, "Buffer error in compressed datastream");
  }
  else if ( v8 == -3 )
  {
    png_chunk_warning(a1, "Data error in compressed datastream");
  }
  else
  {
    png_chunk_warning(a1, "Incomplete compressed datastream");
  }
  return 0;
}
