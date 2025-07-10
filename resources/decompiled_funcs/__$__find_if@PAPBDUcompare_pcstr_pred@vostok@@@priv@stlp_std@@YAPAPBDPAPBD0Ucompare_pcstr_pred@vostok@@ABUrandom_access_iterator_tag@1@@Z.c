const char **__usercall stlp_std::priv::__find_if<char const * *,vostok::compare_pcstr_pred>@<eax>(
        const char **__first@<eax>,
        const char **__last,
        vostok::compare_pcstr_pred __pred)
{
  int v3; // esi
  const char *v4; // edx
  const char *v5; // edx
  const char *v6; // edx

  v3 = ((char *)__last - (char *)__first) >> 4;
  if ( v3 <= 0 )
  {
LABEL_7:
    if ( __last - __first != 1 )
    {
      if ( __last - __first != 2 )
      {
        if ( __last - __first != 3 )
          return __last;
        if ( !strcmp(__pred.str, *__first) )
          return __first;
        ++__first;
      }
      if ( !strcmp(__pred.str, *__first) )
        return __first;
      ++__first;
    }
    if ( !strcmp(__pred.str, *__first) )
      return __first;
    return __last;
  }
  while ( strcmp(__pred.str, *__first) )
  {
    v4 = __first[1];
    ++__first;
    if ( !strcmp(__pred.str, v4) )
      break;
    v5 = __first[1];
    ++__first;
    if ( !strcmp(__pred.str, v5) )
      break;
    v6 = __first[1];
    ++__first;
    if ( !strcmp(__pred.str, v6) )
      break;
    --v3;
    ++__first;
    if ( v3 <= 0 )
      goto LABEL_7;
  }
  return __first;
}
