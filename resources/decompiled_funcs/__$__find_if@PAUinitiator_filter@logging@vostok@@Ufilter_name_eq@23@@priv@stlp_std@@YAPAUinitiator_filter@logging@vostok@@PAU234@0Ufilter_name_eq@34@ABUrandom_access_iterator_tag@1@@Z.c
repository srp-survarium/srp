vostok::logging::initiator_filter *__cdecl stlp_std::priv::__find_if<vostok::logging::initiator_filter *,vostok::logging::filter_name_eq>(
        vostok::logging::initiator_filter *__first,
        vostok::logging::initiator_filter *__last,
        vostok::logging::filter_name_eq __pred)
{
  int v4; // [esp+0h] [ebp-14h]
  int __trip_count; // [esp+10h] [ebp-4h]
  vostok::logging::initiator_filter *__firsta; // [esp+1Ch] [ebp+8h]
  vostok::logging::initiator_filter *__firstb; // [esp+1Ch] [ebp+8h]
  vostok::logging::initiator_filter *__firstc; // [esp+1Ch] [ebp+8h]

  for ( __trip_count = (__last - __first) >> 2; __trip_count > 0; --__trip_count )
  {
    if ( vostok::operator==(&__first->initiator, __pred.name) )
      return __first;
    __firsta = __first + 1;
    if ( vostok::operator==(&__firsta->initiator, __pred.name) )
      return __firsta;
    __firstb = __firsta + 1;
    if ( vostok::operator==(&__firstb->initiator, __pred.name) )
      return __firstb;
    __firstc = __firstb + 1;
    if ( vostok::operator==(&__firstc->initiator, __pred.name) )
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
      if ( vostok::operator==(&__first->initiator, __pred.name) )
        return __first;
      ++__first;
    }
    if ( vostok::operator==(&__first->initiator, __pred.name) )
      return __first;
    ++__first;
  }
  if ( vostok::operator==(&__first->initiator, __pred.name) )
    return __first;
  return __last;
}
