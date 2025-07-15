vostok::animation::mixing::animation_state **__usercall stlp_std::remove<vostok::animation::mixing::animation_state * *,vostok::animation::mixing::animation_state *>@<eax>(
        vostok::animation::mixing::animation_state **__first@<eax>,
        vostok::animation::mixing::animation_state **__val@<edi>,
        vostok::animation::mixing::animation_state **__last)
{
  int v3; // ecx
  vostok::animation::mixing::animation_state *v4; // edx
  vostok::animation::mixing::animation_state **i; // ecx

  v3 = ((char *)__last - (char *)__first) >> 4;
  if ( v3 <= 0 )
  {
LABEL_8:
    if ( __last - __first != 1 )
    {
      if ( __last - __first != 2 )
      {
        if ( __last - __first != 3 )
        {
LABEL_16:
          __first = __last;
          goto LABEL_17;
        }
        if ( *__first == *__val )
          goto LABEL_17;
        ++__first;
      }
      if ( *__first == *__val )
        goto LABEL_17;
      ++__first;
    }
    if ( *__first == *__val )
      goto LABEL_17;
    goto LABEL_16;
  }
  v4 = *__val;
  while ( *__first != v4 )
  {
    if ( *++__first == v4 )
      break;
    if ( *++__first == v4 )
      break;
    if ( *++__first == v4 )
      break;
    ++__first;
    if ( --v3 <= 0 )
      goto LABEL_8;
  }
LABEL_17:
  if ( __first != __last )
  {
    for ( i = __first + 1; i != __last; ++i )
    {
      if ( *i != *__val )
        *__first++ = *i;
    }
  }
  return __first;
}
