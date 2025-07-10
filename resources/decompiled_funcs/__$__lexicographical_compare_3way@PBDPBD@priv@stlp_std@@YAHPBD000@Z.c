int __cdecl stlp_std::priv::__lexicographical_compare_3way<char const *,char const *>(
        const char *__first1,
        const char *__last1,
        const char *__first2,
        const char *__last2)
{
  const char *v4; // eax

  v4 = __first1;
  if ( __first1 != __last1 )
  {
    while ( __first2 != __last2 )
    {
      if ( *__first2 > *v4 )
        return -1;
      if ( *__first2 < *v4 )
        return 1;
      ++v4;
      ++__first2;
      if ( v4 == __last1 )
        goto LABEL_6;
    }
    return v4 != __last1;
  }
LABEL_6:
  if ( __first2 == __last2 )
    return v4 != __last1;
  return -1;
}
