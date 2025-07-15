int __cdecl wcsncmp(const wchar_t *first, const wchar_t *last, unsigned int count)
{
  if ( !count )
    return 0;
  while ( --count && *first && *first == *last )
  {
    ++first;
    ++last;
  }
  return *first - *last;
}
