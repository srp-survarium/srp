vostok::animation::mixing::animated_object_holder *__usercall stlp_std::priv::__find<vostok::animation::mixing::animated_object_holder *,void const *>@<eax>(
        vostok::animation::mixing::animated_object_holder *__first@<ecx>,
        vostok::animation::mixing::animated_object_holder *__last@<esi>,
        const void *const *__val@<edi>)
{
  int v3; // eax
  const void *v4; // edx
  vostok::animation::mixing::animated_object_holder *result; // eax

  v3 = (__last - __first) >> 2;
  if ( v3 > 0 )
  {
    v4 = *__val;
    while ( __first->animated_object != v4 )
    {
      ++__first;
      if ( __first->animated_object == v4 )
        break;
      ++__first;
      if ( __first->animated_object == v4 )
        break;
      ++__first;
      if ( __first->animated_object == v4 )
        break;
      --v3;
      ++__first;
      if ( v3 <= 0 )
        goto LABEL_8;
    }
    return __first;
  }
LABEL_8:
  switch ( __last - __first )
  {
    case 1:
LABEL_15:
      result = __first;
      if ( __first->animated_object == *__val )
        return result;
      return __last;
    case 2:
      goto LABEL_13;
    case 3:
      if ( __first->animated_object == *__val )
        return __first;
      ++__first;
LABEL_13:
      if ( __first->animated_object != *__val )
      {
        ++__first;
        goto LABEL_15;
      }
      return __first;
  }
  return __last;
}
