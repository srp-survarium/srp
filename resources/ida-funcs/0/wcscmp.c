int __cdecl wcscmp(const wchar_t *src, const wchar_t *dst)
{
  int result; // eax

  while ( 1 )
  {
    result = *src - *dst;
    if ( result || !*dst )
      break;
    ++src;
    ++dst;
  }
  if ( result < 0 )
    return -1;
  if ( result > 0 )
    return 1;
  return result;
}
