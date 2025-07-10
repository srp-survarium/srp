const char *__cdecl stlp_std::priv::__find_if<char const *,stlp_std::_Ctype_not_mask>(
        const char *__first,
        const char *__last,
        stlp_std::_Ctype_not_mask __pred)
{
  const char *result; // eax
  int v4; // ecx
  int v5; // ebx
  int v6; // ebx
  int v7; // ebx

  result = __first;
  v4 = (__last - __first) >> 2;
  if ( v4 <= 0 )
  {
LABEL_7:
    if ( __last - result != 1 )
    {
      if ( __last - result != 2 )
      {
        if ( __last - result != 3 )
          return __last;
        if ( (__pred._Mask & __pred._M_table[*(unsigned __int8 *)result]) == 0 )
          return result;
        ++result;
      }
      if ( (__pred._Mask & __pred._M_table[*(unsigned __int8 *)result]) == 0 )
        return result;
      ++result;
    }
    if ( (__pred._Mask & __pred._M_table[*(unsigned __int8 *)result]) == 0 )
      return result;
    return __last;
  }
  while ( (__pred._Mask & __pred._M_table[*(unsigned __int8 *)result]) != 0 )
  {
    v5 = *(unsigned __int8 *)++result;
    if ( (__pred._Mask & __pred._M_table[v5]) == 0 )
      break;
    v6 = *(unsigned __int8 *)++result;
    if ( (__pred._Mask & __pred._M_table[v6]) == 0 )
      break;
    v7 = *(unsigned __int8 *)++result;
    if ( (__pred._Mask & __pred._M_table[v7]) == 0 )
      break;
    --v4;
    ++result;
    if ( v4 <= 0 )
      goto LABEL_7;
  }
  return result;
}
