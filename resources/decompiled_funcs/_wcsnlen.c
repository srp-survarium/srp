unsigned int __cdecl wcsnlen(const wchar_t *wcs, unsigned int maxsize)
{
  unsigned int result; // eax

  for ( result = 0; result < maxsize; ++wcs )
  {
    if ( !*wcs )
      break;
    ++result;
  }
  return result;
}
