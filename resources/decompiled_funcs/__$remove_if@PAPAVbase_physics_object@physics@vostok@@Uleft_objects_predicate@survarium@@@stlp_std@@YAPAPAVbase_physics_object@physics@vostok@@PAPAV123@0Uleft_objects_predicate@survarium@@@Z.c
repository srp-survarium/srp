vostok::physics::base_physics_object **__cdecl stlp_std::remove_if<vostok::physics::base_physics_object * *,survarium::left_objects_predicate>(
        vostok::physics::base_physics_object **__first,
        vostok::physics::base_physics_object **__last,
        survarium::left_objects_predicate __pred)
{
  survarium::left_objects_predicate v4; // [esp+0h] [ebp-30h] BYREF
  vostok::physics::base_physics_object **v5; // [esp+8h] [ebp-28h]
  vostok::physics::base_physics_object **i; // [esp+Ch] [ebp-24h]
  vostok::physics::base_physics_object **__next; // [esp+2Ch] [ebp-4h]
  vostok::physics::base_physics_object **__firsta; // [esp+38h] [ebp+8h]

  __firsta = stlp_std::find_if<vostok::physics::base_physics_object * *,survarium::left_objects_predicate>(
               __first,
               __last,
               __pred);
  if ( __firsta == __last )
    return __firsta;
  __next = __firsta + 1;
  v4 = __pred;
  v5 = __firsta;
  for ( i = __firsta + 1; i != __last; ++i )
  {
    if ( !survarium::left_objects_predicate::operator()(&v4, *i) )
      *v5++ = *i;
  }
  return v5;
}
