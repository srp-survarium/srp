vostok::physics::base_physics_object **__cdecl stlp_std::priv::__find_if<vostok::physics::base_physics_object * *,bool (__cdecl *)(vostok::physics::base_physics_object *)>(
        vostok::physics::base_physics_object **__first,
        vostok::physics::base_physics_object **__last,
        bool (__cdecl *__pred)(vostok::physics::base_physics_object *))
{
  int v4; // [esp+0h] [ebp-8h]
  int __trip_count; // [esp+4h] [ebp-4h]
  vostok::physics::base_physics_object **__firsta; // [esp+10h] [ebp+8h]
  vostok::physics::base_physics_object **__firstb; // [esp+10h] [ebp+8h]
  vostok::physics::base_physics_object **__firstc; // [esp+10h] [ebp+8h]

  for ( __trip_count = ((char *)__last - (char *)__first) >> 4; __trip_count > 0; --__trip_count )
  {
    if ( __pred(*__first) )
      return __first;
    __firsta = __first + 1;
    if ( __pred(*__firsta) )
      return __firsta;
    __firstb = __firsta + 1;
    if ( __pred(*__firstb) )
      return __firstb;
    __firstc = __firstb + 1;
    if ( __pred(*__firstc) )
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
      if ( __pred(*__first) )
        return __first;
      ++__first;
    }
    if ( __pred(*__first) )
      return __first;
    ++__first;
  }
  if ( __pred(*__first) )
    return __first;
  return __last;
}
