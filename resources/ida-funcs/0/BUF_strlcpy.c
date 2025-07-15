unsigned int __cdecl BUF_strlcpy(char *dst, const char *src, unsigned int size)
{
  unsigned int v3; // ecx
  int i; // edi

  v3 = size;
  for ( i = 0; v3 > 1; ++i )
  {
    if ( !*src )
      break;
    *dst = *src;
    --v3;
    ++dst;
    ++src;
  }
  if ( v3 )
    *dst = 0;
  return i + strlen(src);
}
