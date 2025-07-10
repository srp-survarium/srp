const wchar_t *__cdecl stlp_std::priv::__find<wchar_t const *,wchar_t>(
        const wchar_t *__first,
        const wchar_t *__last,
        const wchar_t *__val)
{
  const wchar_t *result; // eax
  int v4; // ecx
  __int16 v5; // dx

  result = __first;
  v4 = ((char *)__last - (char *)__first) >> 3;
  if ( v4 <= 0 )
  {
LABEL_8:
    if ( __last - result != 1 )
    {
      if ( __last - result != 2 )
      {
        if ( __last - result != 3 )
          return __last;
        if ( *result == *__val )
          return result;
        ++result;
      }
      if ( *result == *__val )
        return result;
      ++result;
    }
    if ( *result == *__val )
      return result;
    return __last;
  }
  v5 = *__val;
  while ( *result != v5 )
  {
    if ( *++result == v5 )
      break;
    if ( *++result == v5 )
      break;
    if ( *++result == v5 )
      break;
    --v4;
    ++result;
    if ( v4 <= 0 )
      goto LABEL_8;
  }
  return result;
}
