vostok::render::light_data *__usercall stlp_std::priv::__find<vostok::render::light_data *,unsigned int>@<eax>(
        vostok::render::light_data *__first@<eax>,
        vostok::render::light_data *__last@<esi>,
        const unsigned int *__val@<edi>)
{
  int v3; // ecx
  int v4; // edx

  v3 = ((char *)__last - (char *)__first) >> 5;
  if ( v3 <= 0 )
  {
LABEL_8:
    if ( __last - __first != 1 )
    {
      if ( __last - __first != 2 )
      {
        if ( __last - __first != 3 )
          return __last;
        if ( __first->id == *__val )
          return __first;
        ++__first;
      }
      if ( __first->id == *__val )
        return __first;
      ++__first;
    }
    if ( __first->id == *__val )
      return __first;
    return __last;
  }
  v4 = *__val;
  while ( __first->id != v4 )
  {
    ++__first;
    if ( __first->id == v4 )
      break;
    ++__first;
    if ( __first->id == v4 )
      break;
    ++__first;
    if ( __first->id == v4 )
      break;
    --v3;
    ++__first;
    if ( v3 <= 0 )
      goto LABEL_8;
  }
  return __first;
}
