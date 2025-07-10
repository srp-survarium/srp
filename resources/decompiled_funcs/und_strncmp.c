int __fastcall und_strncmp(const char *first, const char *last, unsigned int count)
{
  if ( !count )
    return 0;
  while ( --count && *first && *first == *last )
  {
    ++first;
    ++last;
  }
  return *(unsigned __int8 *)first - *(unsigned __int8 *)last;
}
