vostok::physics::base_physics_object **__cdecl stlp_std::find_if<vostok::physics::base_physics_object * *,survarium::left_objects_predicate>(
        vostok::physics::base_physics_object **__first,
        vostok::physics::base_physics_object **__last,
        survarium::left_objects_predicate __pred)
{
  stlp_std::random_access_iterator_tag __formal; // [esp+CBh] [ebp-1h] BYREF

  return stlp_std::priv::__find_if<vostok::physics::base_physics_object * *,survarium::left_objects_predicate>(
           __first,
           __last,
           __pred,
           &__formal);
}
