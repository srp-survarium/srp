int __cdecl sub_478FC0(int a1)
{
  int result; // eax
  char *v2; // [esp+4h] [ebp-10Ch]
  _BYTE v3[256]; // [esp+8h] [ebp-108h] BYREF
  int v4; // [esp+10Ch] [ebp-4h]

  if ( (*(_DWORD *)(a1 + 184) & 4) == 0 )
    return png_warning(a1, "zstream not in use (internal error)");
  v4 = deflateReset((z_stream_s *)(a1 + 120));
  result = a1;
  *(_DWORD *)(a1 + 184) &= ~4u;
  if ( v4 )
  {
    switch ( v4 )
    {
      case -6:
        v2 = "version";
        break;
      case -4:
        v2 = "memory";
        break;
      case -2:
        v2 = "stream";
        break;
      default:
        v2 = "unknown";
        break;
    }
    png_warning_parameter_signed((int)v3, 1, 1, v4);
    png_warning_parameter((int)v3, 2, v2);
    if ( *(_DWORD *)(a1 + 144) )
      png_warning_parameter((int)v3, 3, *(_BYTE **)(a1 + 144));
    else
      png_warning_parameter((int)v3, 3, "[no zlib message]");
    return png_formatted_warning(a1, (int)v3, "zlib failed to reset compressor: @1(@2): @3");
  }
  return result;
}
