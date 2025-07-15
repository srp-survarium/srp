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


survarium::bullet **__cdecl stlp_std::remove_if<survarium::bullet * *,survarium::redundant_bullet_predicate>(
        survarium::bullet **__first,
        survarium::bullet **__last,
        survarium::redundant_bullet_predicate __pred)
{
  survarium::redundant_bullet_predicate v4; // [esp+0h] [ebp-1Ch] BYREF
  survarium::bullet **v5; // [esp+4h] [ebp-18h]
  survarium::bullet **i; // [esp+8h] [ebp-14h]
  survarium::bullet **__next; // [esp+18h] [ebp-4h]
  survarium::bullet **__firsta; // [esp+24h] [ebp+8h]

  __firsta = stlp_std::find_if<survarium::bullet * *,survarium::redundant_bullet_predicate>(__first, __last, __pred);
  if ( __firsta == __last )
    return __firsta;
  __next = __firsta + 1;
  v4.bullet_manager = __pred.bullet_manager;
  v5 = __firsta;
  for ( i = __firsta + 1; i != __last; ++i )
  {
    if ( !survarium::redundant_bullet_predicate::operator()(&v4, *i) )
      *v5++ = *i;
  }
  return v5;
}


vostok::network_core::udp_match_packet **__cdecl stlp_std::remove_if<vostok::network_core::udp_match_packet * *,packets_in_list_predicate>(
        vostok::network_core::udp_match_packet **__first,
        vostok::network_core::udp_match_packet **__last,
        packets_in_list_predicate __pred)
{
  int v4; // [esp-4h] [ebp-2Ch] BYREF
  vostok::network_core::udp_match_packet **matched; // [esp+4h] [ebp-24h]
  vostok::network_core::udp_match_packet **v6; // [esp+8h] [ebp-20h]
  vostok::network_core::udp_match_packet **i; // [esp+Ch] [ebp-1Ch]
  unsigned __int16 m_number; // [esp+12h] [ebp-16h] BYREF
  unsigned __int16 *v9; // [esp+14h] [ebp-14h]
  int *v10; // [esp+18h] [ebp-10h]
  vostok::network_core::udp_match_packet **__next; // [esp+24h] [ebp-4h]

  v10 = &v4;
  matched = stlp_std::find_if<vostok::network_core::udp_match_packet * *,packets_in_list_predicate>(
              __first,
              __last,
              __pred);
  if ( matched == __last )
    return matched;
  __next = matched + 1;
  v9 = &m_number;
  m_number = __pred.m_sequence_id.m_number;
  v6 = matched;
  for ( i = matched + 1; i != __last; ++i )
  {
    if ( (*i)->sequence_id.m_number != m_number )
      *v6++ = *i;
  }
  return v6;
}


vostok::collision::ray_triangle_result *__usercall stlp_std::remove_if<vostok::collision::ray_triangle_result *,negative_distance_detector>@<eax>(
        vostok::collision::ray_triangle_result *__first@<ecx>,
        vostok::collision::ray_triangle_result *__last@<eax>,
        negative_distance_detector __pred)
{
  vostok::collision::ray_triangle_result *result; // eax
  vostok::collision::ray_triangle_result *i; // ecx
  const stlp_std::random_access_iterator_tag *v6; // [esp+0h] [ebp-4h]

  result = stlp_std::priv::__find_if<vostok::collision::ray_triangle_result *,negative_distance_detector>(
             __first,
             __last,
             __pred,
             v6);
  if ( result != __last )
  {
    for ( i = result + 1; i != __last; ++i )
    {
      if ( i->distance >= 0.0 )
      {
        *(_QWORD *)&result->object = *(_QWORD *)&i->object;
        result->distance = i->distance;
        ++result;
      }
    }
  }
  return result;
}
