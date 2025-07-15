bool __cdecl stlp_std::priv::__valid_grouping(
        const char *first1,
        const char *last1,
        const char *first2,
        const char *last2)
{
  const char *v4; // ecx
  const char *v5; // eax

  if ( first1 == last1 )
    return 1;
  v4 = first2;
  if ( first2 == last2 )
    return 1;
  v5 = last1 - 1;
  if ( first1 == last1 - 1 )
    return *v5 <= *v4;
  while ( *v5 == *v4 )
  {
    --v5;
    if ( v4 != last2 - 1 )
      ++v4;
    if ( first1 == v5 )
      return *v5 <= *v4;
  }
  return 0;
}
