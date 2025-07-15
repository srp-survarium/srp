int __cdecl sub_478AC0(int a1, int a2)
{
  unsigned int v2; // eax
  int result; // eax
  unsigned int v4; // [esp+8h] [ebp-54h]
  _BYTE v5[68]; // [esp+Ch] [ebp-50h] BYREF
  int v6; // [esp+54h] [ebp-8h]
  char *v7; // [esp+58h] [ebp-4h]

  if ( (*(_DWORD *)(a1 + 184) & 4) != 0 )
    png_error(a1, (int)"zstream already in use (internal error)");
  if ( *(_DWORD *)(a1 + 184) != a2 )
  {
    v6 = 0;
    v7 = "-";
    if ( *(_DWORD *)(a1 + 184) )
    {
      v6 = deflateEnd((z_stream_s *)(a1 + 120));
      v7 = "end";
      *(_DWORD *)(a1 + 184) = 0;
    }
    if ( !v6 )
    {
      if ( a2 == 1 )
      {
        v6 = deflateInit2_(
               (z_stream_s *)(a1 + 120),
               *(_DWORD *)(a1 + 188),
               *(_DWORD *)(a1 + 192),
               *(_DWORD *)(a1 + 196),
               *(_DWORD *)(a1 + 200),
               *(_DWORD *)(a1 + 204),
               "1.2.7",
               56);
        v7 = "IDAT";
      }
      else
      {
        if ( a2 != 2 )
          png_error(a1, (int)"invalid zlib state");
        v6 = deflateInit2_(
               (z_stream_s *)(a1 + 120),
               *(_DWORD *)(a1 + 208),
               *(_DWORD *)(a1 + 212),
               *(_DWORD *)(a1 + 216),
               *(_DWORD *)(a1 + 220),
               *(_DWORD *)(a1 + 224),
               "1.2.7",
               56);
        v7 = "text";
      }
    }
    if ( v6 )
    {
      v2 = png_safecat((int)v5, 0x40u, 0, "zlib failed to initialize compressor (");
      v4 = png_safecat((int)v5, 0x40u, v2, v7);
      switch ( v6 )
      {
        case -6:
          png_safecat((int)v5, 0x40u, v4, ") version error");
          break;
        case -4:
          png_safecat((int)v5, 0x40u, v4, ") memory error");
          break;
        case -2:
          png_safecat((int)v5, 0x40u, v4, ") stream error");
          break;
        default:
          png_safecat((int)v5, 0x40u, v4, ") unknown error");
          break;
      }
      png_error(a1, (int)v5);
    }
    *(_DWORD *)(a1 + 184) = a2;
  }
  result = a1;
  *(_DWORD *)(a1 + 184) |= 4u;
  return result;
}
