vostok::physics::base_physics_object **__cdecl stlp_std::remove_if<vostok::physics::base_physics_object * *,bool (__cdecl *)(vostok::physics::base_physics_object *)>(
        vostok::physics::base_physics_object **__first,
        vostok::physics::base_physics_object **__last,
        bool (__cdecl *__pred)(vostok::physics::base_physics_object *))
{
  vostok::physics::base_physics_object **v4; // [esp+0h] [ebp-Ch]
  vostok::physics::base_physics_object **i; // [esp+4h] [ebp-8h]
  vostok::physics::base_physics_object **__firsta; // [esp+14h] [ebp+8h]

  __firsta = stlp_std::find_if<vostok::physics::base_physics_object * *,bool (__cdecl *)(vostok::physics::base_physics_object *)>(
               __first,
               __last,
               __pred);
  if ( __firsta == __last )
    return __firsta;
  v4 = __firsta;
  for ( i = __firsta + 1; i != __last; ++i )
  {
    if ( !__pred(*i) )
      *v4++ = *i;
  }
  return v4;
}
