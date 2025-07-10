const wchar_t *__cdecl stlp_std::priv::__find_if<wchar_t const *,stlp_std::_Ctype_w_is_mask>(
        const wchar_t *__first,
        const wchar_t *__last,
        stlp_std::_Ctype_w_is_mask __pred)
{
  const wchar_t *result; // eax
  int v4; // ecx
  wchar_t v5; // dx
  wchar_t v6; // dx
  wchar_t v7; // dx

  result = __first;
  v4 = ((char *)__last - (char *)__first) >> 3;
  if ( v4 <= 0 )
  {
LABEL_11:
    if ( __last - result != 1 )
    {
      if ( __last - result != 2 )
      {
        if ( __last - result != 3 )
          return __last;
        if ( *result < 0x100u && (__pred.M & __pred.table[*result]) != 0 )
          return result;
        ++result;
      }
      if ( *result < 0x100u && (__pred.M & __pred.table[*result]) != 0 )
        return result;
      ++result;
    }
    if ( *result < 0x100u && (__pred.M & __pred.table[*result]) != 0 )
      return result;
    return __last;
  }
  while ( *result >= 0x100u || (__pred.M & __pred.table[*result]) == 0 )
  {
    v5 = result[1];
    ++result;
    if ( v5 < 0x100u && (__pred.M & __pred.table[v5]) != 0 )
      break;
    v6 = result[1];
    ++result;
    if ( v6 < 0x100u && (__pred.M & __pred.table[v6]) != 0 )
      break;
    v7 = result[1];
    ++result;
    if ( v7 < 0x100u && (__pred.M & __pred.table[v7]) != 0 )
      break;
    --v4;
    ++result;
    if ( v4 <= 0 )
      goto LABEL_11;
  }
  return result;
}
