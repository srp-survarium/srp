bool __cdecl compare_parts(const char *s1, const char *s2)
{
  bool v4; // [esp+4h] [ebp-Ch]

  while ( *s1 && *s1 != 58 )
  {
    if ( !*s2 || *s2 == 58 )
      return 0;
    if ( *s1 != *s2 )
      return *s1 < *s2;
    ++s1;
    ++s2;
  }
  v4 = !*s2 || *s2 == 58;
  return !v4;
}
