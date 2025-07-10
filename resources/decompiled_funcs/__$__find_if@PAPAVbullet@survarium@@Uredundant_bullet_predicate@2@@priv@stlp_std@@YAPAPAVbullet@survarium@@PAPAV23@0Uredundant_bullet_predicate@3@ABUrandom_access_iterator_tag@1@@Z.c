survarium::bullet **__cdecl stlp_std::priv::__find_if<survarium::bullet * *,survarium::redundant_bullet_predicate>(
        survarium::bullet **__first,
        survarium::bullet **__last,
        survarium::redundant_bullet_predicate __pred)
{
  int v4; // [esp+0h] [ebp-5Ch]
  int __trip_count; // [esp+58h] [ebp-4h]
  survarium::bullet **__firsta; // [esp+64h] [ebp+8h]
  survarium::bullet **__firstb; // [esp+64h] [ebp+8h]
  survarium::bullet **__firstc; // [esp+64h] [ebp+8h]

  for ( __trip_count = ((char *)__last - (char *)__first) >> 4; __trip_count > 0; --__trip_count )
  {
    if ( survarium::redundant_bullet_predicate::operator()(&__pred, *__first) )
      return __first;
    __firsta = __first + 1;
    if ( survarium::redundant_bullet_predicate::operator()(&__pred, *__firsta) )
      return __firsta;
    __firstb = __firsta + 1;
    if ( survarium::redundant_bullet_predicate::operator()(&__pred, *__firstb) )
      return __firstb;
    __firstc = __firstb + 1;
    if ( survarium::redundant_bullet_predicate::operator()(&__pred, *__firstc) )
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
      if ( survarium::redundant_bullet_predicate::operator()(&__pred, *__first) )
        return __first;
      ++__first;
    }
    if ( survarium::redundant_bullet_predicate::operator()(&__pred, *__first) )
      return __first;
    ++__first;
  }
  if ( survarium::redundant_bullet_predicate::operator()(&__pred, *__first) )
    return __first;
  return __last;
}
