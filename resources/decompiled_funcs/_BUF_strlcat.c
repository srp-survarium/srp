unsigned int __cdecl BUF_strlcat(char *dst, const char *src, unsigned int size)
{
  unsigned int v3; // eax
  int i; // ebx
  int j; // edi

  v3 = size;
  for ( i = 0; v3; ++dst )
  {
    if ( !*dst )
      break;
    --v3;
    ++i;
  }
  for ( j = 0; v3 > 1; ++j )
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
  return i + j + strlen(src);
}
