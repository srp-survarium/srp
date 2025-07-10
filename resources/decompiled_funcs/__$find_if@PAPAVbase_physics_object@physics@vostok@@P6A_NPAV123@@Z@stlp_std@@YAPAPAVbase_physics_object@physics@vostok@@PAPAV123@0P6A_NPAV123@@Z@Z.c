vostok::physics::base_physics_object **__cdecl stlp_std::find_if<vostok::physics::base_physics_object * *,bool (__cdecl *)(vostok::physics::base_physics_object *)>(
        vostok::physics::base_physics_object **__first,
        vostok::physics::base_physics_object **__last,
        bool (__cdecl *__pred)(vostok::physics::base_physics_object *))
{
  stlp_std::random_access_iterator_tag __formal; // [esp+7h] [ebp-1h] BYREF

  return stlp_std::priv::__find_if<vostok::physics::base_physics_object * *,bool (__cdecl *)(vostok::physics::base_physics_object *)>(
           __first,
           __last,
           __pred,
           &__formal);
}
