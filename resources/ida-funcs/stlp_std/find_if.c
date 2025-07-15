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


survarium::bullet **__cdecl stlp_std::find_if<survarium::bullet * *,survarium::redundant_bullet_predicate>(
        survarium::bullet **__first,
        survarium::bullet **__last,
        survarium::redundant_bullet_predicate __pred)
{
  stlp_std::random_access_iterator_tag __formal; // [esp+5Bh] [ebp-1h] BYREF

  return stlp_std::priv::__find_if<survarium::bullet * *,survarium::redundant_bullet_predicate>(
           __first,
           __last,
           __pred,
           &__formal);
}


vostok::network_core::udp_match_packet **__cdecl stlp_std::find_if<vostok::network_core::udp_match_packet * *,packets_in_list_predicate>(
        vostok::network_core::udp_match_packet **__first,
        vostok::network_core::udp_match_packet **__last,
        packets_in_list_predicate __pred)
{
  _DWORD v4[6]; // [esp-8h] [ebp-1Ch] BYREF
  stlp_std::random_access_iterator_tag __formal; // [esp+13h] [ebp-1h] BYREF

  v4[4] = v4;
  return stlp_std::priv::__find_if<vostok::network_core::udp_match_packet * *,packets_in_list_predicate>(
           __first,
           __last,
           __pred,
           &__formal);
}


vostok::logging::initiator_filter *__cdecl stlp_std::find_if<vostok::logging::initiator_filter *,vostok::logging::filter_name_eq>(
        vostok::logging::initiator_filter *__first,
        vostok::logging::initiator_filter *__last,
        vostok::logging::filter_name_eq __pred)
{
  stlp_std::random_access_iterator_tag __formal; // [esp+Fh] [ebp-1h] BYREF

  return stlp_std::priv::__find_if<vostok::logging::initiator_filter *,vostok::logging::filter_name_eq>(
           __first,
           __last,
           __pred,
           &__formal);
}


vostok::sound::unique_propagator_info *__cdecl stlp_std::find_if<vostok::sound::unique_propagator_info *,vostok::sound::compare_by_propagator>(
        vostok::sound::unique_propagator_info *__first,
        vostok::sound::unique_propagator_info *__last,
        vostok::sound::compare_by_propagator __pred)
{
  stlp_std::random_access_iterator_tag __formal; // [esp+7h] [ebp-1h] BYREF

  return stlp_std::priv::__find_if<vostok::sound::unique_propagator_info *,vostok::sound::compare_by_propagator>(
           __first,
           __last,
           __pred,
           &__formal);
}


const vostok::fixed_string<16> *__cdecl stlp_std::find_if<vostok::fixed_string<16> const *,survarium::compare_body_parts_predicate>(
        const vostok::fixed_string<16> *__first,
        const vostok::fixed_string<16> *__last,
        survarium::compare_body_parts_predicate __pred)
{
  stlp_std::random_access_iterator_tag __formal; // [esp+17h] [ebp-1h] BYREF

  return stlp_std::priv::__find_if<vostok::fixed_string<16> const *,survarium::compare_body_parts_predicate>(
           __first,
           __last,
           __pred,
           &__formal);
}
