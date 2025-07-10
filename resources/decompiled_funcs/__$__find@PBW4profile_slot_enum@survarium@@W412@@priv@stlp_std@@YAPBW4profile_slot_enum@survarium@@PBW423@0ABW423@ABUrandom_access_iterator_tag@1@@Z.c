survarium::collision_geometry_subscriber **__cdecl stlp_std::priv::__find<enum survarium::profile_slot_enum const *,enum survarium::profile_slot_enum>(
        survarium::collision_geometry_subscriber **__first,
        survarium::collision_geometry_subscriber **__last,
        survarium::collision_geometry_subscriber **__val)
{
  int v4; // [esp+0h] [ebp-8h]
  int __trip_count; // [esp+4h] [ebp-4h]
  survarium::collision_geometry_subscriber **__firsta; // [esp+10h] [ebp+8h]
  survarium::collision_geometry_subscriber **__firstb; // [esp+10h] [ebp+8h]
  survarium::collision_geometry_subscriber **__firstc; // [esp+10h] [ebp+8h]

  for ( __trip_count = ((char *)__last - (char *)__first) >> 4; __trip_count > 0; --__trip_count )
  {
    if ( *__first == *__val )
      return __first;
    __firsta = __first + 1;
    if ( *__firsta == *__val )
      return __firsta;
    __firstb = __firsta + 1;
    if ( *__firstb == *__val )
      return __firstb;
    __firstc = __firstb + 1;
    if ( *__firstc == *__val )
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
      if ( *__first == *__val )
        return __first;
      ++__first;
    }
    if ( *__first == *__val )
      return __first;
    ++__first;
  }
  if ( *__first == *__val )
    return __first;
  return __last;
}
