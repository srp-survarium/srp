int __cdecl sub_478660(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  __m128i *v6; // [esp+0h] [ebp-118h]
  int v7; // [esp+4h] [ebp-114h]
  __m128i *src; // [esp+8h] [ebp-110h]
  int v9; // [esp+Ch] [ebp-10Ch]
  _BYTE v10[256]; // [esp+10h] [ebp-108h] BYREF
  int v11; // [esp+114h] [ebp-4h]
  int v12; // [esp+128h] [ebp+10h]

  a5[2] = 0;
  a5[3] = 0;
  a5[4] = 0;
  *a5 = 0;
  a5[1] = a3;
  if ( a4 == -1 )
  {
    *a5 = a2;
    return a3;
  }
  else
  {
    if ( a4 >= 3 )
    {
      png_warning_parameter_signed((int)v10, 1, 1, a4);
      png_formatted_warning(a1, (int)v10, "Unknown compression type @1");
    }
    sub_478AC0(a1, 2);
    *(_DWORD *)(a1 + 124) = a3;
    *(_DWORD *)(a1 + 120) = a2;
    *(_DWORD *)(a1 + 136) = *(_DWORD *)(a1 + 180);
    *(_DWORD *)(a1 + 132) = *(_DWORD *)(a1 + 176);
    do
    {
      v11 = deflate((z_stream_s *)(a1 + 120), 0);
      if ( v11 )
      {
        if ( *(_DWORD *)(a1 + 144) )
          png_error(a1, *(_DWORD *)(a1 + 144));
        png_error(a1, (int)"zlib error");
      }
      if ( !*(_DWORD *)(a1 + 136) )
      {
        if ( a5[2] >= a5[3] )
        {
          v9 = a5[3];
          a5[3] = a5[2] + 4;
          if ( a5[4] )
          {
            src = (__m128i *)a5[4];
            a5[4] = png_malloc(a1, 4 * a5[3]);
            memcpy(a5[4], src, 4 * v9);
            png_free(a1, src);
          }
          else
          {
            a5[4] = png_malloc(a1, 4 * a5[3]);
          }
        }
        *(_DWORD *)(a5[4] + 4 * a5[2]) = png_malloc(a1, *(_DWORD *)(a1 + 180));
        memcpy(*(_DWORD *)(a5[4] + 4 * a5[2]++), *(const __m128i **)(a1 + 176), *(_DWORD *)(a1 + 180));
        *(_DWORD *)(a1 + 136) = *(_DWORD *)(a1 + 180);
        *(_DWORD *)(a1 + 132) = *(_DWORD *)(a1 + 176);
      }
    }
    while ( *(_DWORD *)(a1 + 124) );
    do
    {
      v11 = deflate((z_stream_s *)(a1 + 120), 4);
      if ( v11 )
      {
        if ( v11 != 1 )
        {
          if ( *(_DWORD *)(a1 + 144) )
            png_error(a1, *(_DWORD *)(a1 + 144));
          png_error(a1, (int)"zlib error");
        }
      }
      else if ( !*(_DWORD *)(a1 + 136) )
      {
        if ( a5[2] >= a5[3] )
        {
          v7 = a5[3];
          a5[3] = a5[2] + 4;
          if ( a5[4] )
          {
            v6 = (__m128i *)a5[4];
            a5[4] = png_malloc(a1, 4 * a5[3]);
            memcpy(a5[4], v6, 4 * v7);
            png_free(a1, v6);
          }
          else
          {
            a5[4] = png_malloc(a1, 4 * a5[3]);
          }
        }
        *(_DWORD *)(a5[4] + 4 * a5[2]) = png_malloc(a1, *(_DWORD *)(a1 + 180));
        memcpy(*(_DWORD *)(a5[4] + 4 * a5[2]++), *(const __m128i **)(a1 + 176), *(_DWORD *)(a1 + 180));
        *(_DWORD *)(a1 + 136) = *(_DWORD *)(a1 + 180);
        *(_DWORD *)(a1 + 132) = *(_DWORD *)(a1 + 176);
      }
    }
    while ( v11 != 1 );
    v12 = a5[2] * *(_DWORD *)(a1 + 180);
    if ( *(_DWORD *)(a1 + 136) < *(_DWORD *)(a1 + 180) )
      v12 += *(_DWORD *)(a1 + 180) - *(_DWORD *)(a1 + 136);
    return v12;
  }
}
