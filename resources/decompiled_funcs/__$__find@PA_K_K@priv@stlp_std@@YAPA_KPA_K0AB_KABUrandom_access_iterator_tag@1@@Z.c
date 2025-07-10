unsigned __int64 *__cdecl stlp_std::priv::__find<unsigned __int64 *,unsigned __int64>(
        unsigned __int64 *__first,
        unsigned __int64 *__last,
        const unsigned __int64 *__val)
{
  int v4; // [esp+18h] [ebp-28h]
  int __trip_count; // [esp+3Ch] [ebp-4h]
  unsigned __int64 *__firsta; // [esp+48h] [ebp+8h]
  unsigned __int64 *__firstb; // [esp+48h] [ebp+8h]
  unsigned __int64 *__firstc; // [esp+48h] [ebp+8h]

  for ( __trip_count = ((char *)__last - (char *)__first) >> 5; __trip_count > 0; --__trip_count )
  {
    if ( *(_DWORD *)__first == *(_DWORD *)__val && *((_DWORD *)__first + 1) == *((_DWORD *)__val + 1) )
      return __first;
    __firsta = __first + 1;
    if ( *(_DWORD *)__firsta == *(_DWORD *)__val && *((_DWORD *)__firsta + 1) == *((_DWORD *)__val + 1) )
      return __firsta;
    __firstb = __firsta + 1;
    if ( *(_DWORD *)__firstb == *(_DWORD *)__val && *((_DWORD *)__firstb + 1) == *((_DWORD *)__val + 1) )
      return __firstb;
    __firstc = __firstb + 1;
    if ( *(_DWORD *)__firstc == *(_DWORD *)__val && *((_DWORD *)__firstc + 1) == *((_DWORD *)__val + 1) )
      return __firstc;
    __first = __firstc + 1;
  }
  v4 = __last - __first;
  if ( v4 != 1 )
  {
    if ( v4 != 2 )
    {
      if ( v4 != 3 )
        return __last;
      if ( *(_DWORD *)__first == *(_DWORD *)__val && *((_DWORD *)__first + 1) == *((_DWORD *)__val + 1) )
        return __first;
      ++__first;
    }
    if ( *(_DWORD *)__first == *(_DWORD *)__val && *((_DWORD *)__first + 1) == *((_DWORD *)__val + 1) )
      return __first;
    ++__first;
  }
  if ( *(_DWORD *)__first == *(_DWORD *)__val && *((_DWORD *)__first + 1) == *((_DWORD *)__val + 1) )
    return __first;
  return __last;
}
