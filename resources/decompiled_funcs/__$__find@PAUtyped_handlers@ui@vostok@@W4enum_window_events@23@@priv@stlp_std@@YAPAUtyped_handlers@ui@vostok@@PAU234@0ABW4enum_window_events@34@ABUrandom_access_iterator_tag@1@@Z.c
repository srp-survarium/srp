vostok::ui::typed_handlers *__usercall stlp_std::priv::__find<vostok::ui::typed_handlers *,enum vostok::ui::enum_window_events>@<eax>(
        vostok::ui::typed_handlers *__first@<ecx>,
        vostok::ui::typed_handlers *__last@<esi>,
        const vostok::ui::enum_window_events *__val@<edi>)
{
  int v3; // eax
  int v4; // edx
  vostok::ui::typed_handlers *result; // eax

  v3 = (__last - __first) >> 2;
  if ( v3 > 0 )
  {
    v4 = *__val;
    while ( __first->type != v4 )
    {
      ++__first;
      if ( __first->type == v4 )
        break;
      ++__first;
      if ( __first->type == v4 )
        break;
      ++__first;
      if ( __first->type == v4 )
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
      if ( __first->type == *__val )
        return result;
      return __last;
    case 2:
      goto LABEL_13;
    case 3:
      if ( __first->type == *__val )
        return __first;
      ++__first;
LABEL_13:
      if ( __first->type != *__val )
      {
        ++__first;
        goto LABEL_15;
      }
      return __first;
  }
  return __last;
}
