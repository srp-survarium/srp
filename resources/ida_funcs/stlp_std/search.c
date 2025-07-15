const char *__usercall stlp_std::search<char const *,char const *,stlp_std::priv::_Eq_traits<stlp_std::char_traits<char>>>@<eax>(
        const char *__first1@<eax>,
        const char *__last1@<edi>,
        const char *__first2,
        const char *__last2)
{
  const char *v4; // ecx
  const char *v5; // esi
  char v6; // cl
  const char *v7; // ecx

  v4 = __first2;
  if ( __first1 != __last1 && __first2 != __last2 )
  {
    v5 = __first2 + 1;
    if ( __first2 + 1 == __last2 )
    {
      do
      {
        if ( *__first1 == *__first2 )
          break;
        ++__first1;
      }
      while ( __first1 != __last1 );
    }
    else
    {
      while ( 1 )
      {
        if ( __first1 == __last1 )
          return __last1;
        v6 = *v4;
        while ( *__first1 != v6 )
        {
          if ( ++__first1 == __last1 )
            return __last1;
        }
        if ( __first1 == __last1 )
          return __last1;
        v7 = __first1 + 1;
        if ( __first1 + 1 == __last1 )
          return __last1;
        if ( *v7 == *v5 )
          break;
LABEL_20:
        v4 = __first2;
        ++__first1;
      }
      while ( ++v5 != __last2 )
      {
        if ( ++v7 == __last1 )
          return __last1;
        if ( *v7 != *v5 )
        {
          v5 = __first2 + 1;
          goto LABEL_20;
        }
      }
    }
  }
  return __first1;
}
