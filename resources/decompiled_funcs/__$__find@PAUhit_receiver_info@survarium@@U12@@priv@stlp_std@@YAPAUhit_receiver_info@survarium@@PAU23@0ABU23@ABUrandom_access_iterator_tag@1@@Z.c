survarium::hit_receiver_info *__cdecl stlp_std::priv::__find<survarium::hit_receiver_info *,survarium::hit_receiver_info>(
        survarium::hit_receiver_info *__first,
        survarium::hit_receiver_info *__last,
        const survarium::hit_receiver_info *__val)
{
  int v4; // [esp+0h] [ebp-8h]
  int __trip_count; // [esp+4h] [ebp-4h]
  survarium::hit_receiver_info *__firsta; // [esp+10h] [ebp+8h]
  survarium::hit_receiver_info *__firstb; // [esp+10h] [ebp+8h]
  survarium::hit_receiver_info *__firstc; // [esp+10h] [ebp+8h]

  for ( __trip_count = (__last - __first) >> 2; __trip_count > 0; --__trip_count )
  {
    if ( survarium::hit_receiver_info::operator==(__first, __val) )
      return __first;
    __firsta = __first + 1;
    if ( survarium::hit_receiver_info::operator==(__firsta, __val) )
      return __firsta;
    __firstb = __firsta + 1;
    if ( survarium::hit_receiver_info::operator==(__firstb, __val) )
      return __firstb;
    __firstc = __firstb + 1;
    if ( survarium::hit_receiver_info::operator==(__firstc, __val) )
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
      if ( survarium::hit_receiver_info::operator==(__first, __val) )
        return __first;
      ++__first;
    }
    if ( survarium::hit_receiver_info::operator==(__first, __val) )
      return __first;
    ++__first;
  }
  if ( survarium::hit_receiver_info::operator==(__first, __val) )
    return __first;
  return __last;
}
