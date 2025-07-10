char *__usercall stlp_std::priv::__find<unsigned short *,unsigned short>@<eax>(
        char *__first@<eax>,
        char *__last@<esi>,
        const unsigned __int16 *__val@<edi>)
{
  int v3; // ecx
  __int16 v4; // dx

  v3 = (__last - __first) >> 3;
  if ( v3 <= 0 )
  {
LABEL_8:
    if ( (__last - __first) >> 1 != 1 )
    {
      if ( (__last - __first) >> 1 != 2 )
      {
        if ( (__last - __first) >> 1 != 3 )
          return __last;
        if ( *(_WORD *)__first == *__val )
          return __first;
        __first += 2;
      }
      if ( *(_WORD *)__first == *__val )
        return __first;
      __first += 2;
    }
    if ( *(_WORD *)__first == *__val )
      return __first;
    return __last;
  }
  v4 = *__val;
  while ( *(_WORD *)__first != v4 )
  {
    __first += 2;
    if ( *(_WORD *)__first == v4 )
      break;
    __first += 2;
    if ( *(_WORD *)__first == v4 )
      break;
    __first += 2;
    if ( *(_WORD *)__first == v4 )
      break;
    --v3;
    __first += 2;
    if ( v3 <= 0 )
      goto LABEL_8;
  }
  return __first;
}
