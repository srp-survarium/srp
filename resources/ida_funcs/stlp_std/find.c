survarium::hit_receiver_info *__cdecl stlp_std::find<survarium::hit_receiver_info *,survarium::hit_receiver_info>(
        survarium::hit_receiver_info *__first,
        survarium::hit_receiver_info *__last,
        const survarium::hit_receiver_info *__val)
{
  stlp_std::random_access_iterator_tag __formal; // [esp+7h] [ebp-1h] BYREF

  return stlp_std::priv::__find<survarium::hit_receiver_info *,survarium::hit_receiver_info>(
           __first,
           __last,
           __val,
           &__formal);
}


unsigned __int64 *__cdecl stlp_std::find<unsigned __int64 *,unsigned __int64>(
        unsigned __int64 *__first,
        unsigned __int64 *__last,
        const unsigned __int64 *__val)
{
  stlp_std::random_access_iterator_tag __formal; // [esp+7h] [ebp-1h] BYREF

  return stlp_std::priv::__find<unsigned __int64 *,unsigned __int64>(__first, __last, __val, &__formal);
}


survarium::collision_geometry_subscriber **__cdecl stlp_std::find<vostok::physics::base_physics_object * const *,vostok::physics::base_physics_object *>(
        survarium::collision_geometry_subscriber **__first,
        survarium::collision_geometry_subscriber **__last,
        survarium::collision_geometry_subscriber *const *__val)
{
  stlp_std::random_access_iterator_tag __formal; // [esp+7h] [ebp-1h] BYREF

  return stlp_std::priv::__find<enum survarium::profile_slot_enum const *,enum survarium::profile_slot_enum>(
           __first,
           __last,
           __val,
           &__formal);
}
