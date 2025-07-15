void __usercall stlp_std::priv::__unguarded_insertion_sort_aux<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        unsigned int *__first@<eax>,
        unsigned int *__last,
        unsigned int *__formal)
{
  unsigned int *i; // esi
  unsigned int v4; // edi
  unsigned int *v5; // edx
  unsigned int *j; // eax

  for ( i = __first; i != __last; *v5 = v4 )
  {
    v4 = *i;
    v5 = i;
    for ( j = i - 1; *(float *)&__formal[*j] > *(float *)&__formal[v4]; --j )
    {
      *v5 = *j;
      v5 = j;
    }
    ++i;
  }
}


void __usercall stlp_std::priv::__unguarded_insertion_sort_aux<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        unsigned int *__first@<eax>,
        unsigned int *__last)
{
  unsigned int *i; // edi
  unsigned int v3; // esi
  unsigned int v4; // ecx
  unsigned int *v5; // eax
  unsigned int *v6; // edx

  for ( i = __first; i != __last; *v6 = v3 )
  {
    v3 = *i;
    v4 = *(i - 1);
    v5 = i - 1;
    v6 = i;
    if ( *i < v4 )
    {
      do
      {
        *v6 = v4;
        v4 = *(v5 - 1);
        v6 = v5--;
      }
      while ( v3 < v4 );
    }
    ++i;
  }
}


void __cdecl stlp_std::priv::__unguarded_insertion_sort_aux<survarium::anomaly_state * *,survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
        const vostok::ai::sound_item **__first,
        const vostok::ai::sound_item **__last,
        const vostok::ai::sound_item **__formal,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  while ( __first != __last )
  {
    stlp_std::priv::__unguarded_linear_insert<vostok::ai::planning::goal * *,vostok::ai::planning::goal *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
      __first,
      *__first,
      __comp);
    ++__first;
  }
}


void __usercall stlp_std::priv::__unguarded_insertion_sort_aux<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first@<eax>,
        vostok::render::grass_patch **__last,
        __int64 __formal,
        float __comp_8)
{
  vostok::render::grass_patch **i; // edi
  vostok::render::sort_grass_patch_predicate v5; // [esp-Ch] [ebp-18h]

  for ( i = __first; i != __last; ++i )
  {
    *(_QWORD *)&v5.m_view_pos.x = __formal;
    v5.m_view_pos.z = __comp_8;
    stlp_std::priv::__unguarded_linear_insert<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
      i,
      *i,
      v5);
  }
}


void __usercall stlp_std::priv::__unguarded_insertion_sort_aux<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key_compare_predicate *a1@<edi>,
        vostok::command_line::key **__first,
        vostok::command_line::key **__last)
{
  const vostok::command_line::key **v3; // ebx
  const vostok::command_line::key *v4; // esi
  const vostok::command_line::key *v5; // edi
  const vostok::command_line::key **v6; // ebp
  const vostok::command_line::key **i; // ebx
  vostok::command_line::key_compare_predicate *v8; // [esp-Ch] [ebp-10h]

  v3 = (const vostok::command_line::key **)__first;
  if ( __first != __last )
  {
    v8 = a1;
    while ( 1 )
    {
      v4 = *v3;
      v5 = *(v3 - 1);
      v6 = v3;
      for ( i = v3 - 1; vostok::command_line::key_compare_predicate::operator()(v4, v5, v8); --i )
      {
        *v6 = v5;
        v5 = *(i - 1);
        v6 = i;
      }
      *v6 = v4;
      if ( ++__first == __last )
        break;
      v3 = (const vostok::command_line::key **)__first;
    }
  }
}


void __usercall stlp_std::priv::__unguarded_insertion_sort_aux<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
        vostok::resources::query_result **__first@<eax>,
        vostok::resources::query_result **__last)
{
  vostok::resources::query_result **i; // esi
  vostok::resources::query_result *v3; // edi
  vostok::resources::query_result **v4; // ecx
  vostok::resources::query_result **j; // eax

  for ( i = __first; i != __last; *v4 = v3 )
  {
    v3 = *i;
    v4 = i;
    for ( j = i - 1; v3->m_quality_index >= (*j)->m_quality_index; --j )
    {
      *v4 = *j;
      v4 = j;
    }
    ++i;
  }
}


void __cdecl stlp_std::priv::__unguarded_insertion_sort_aux<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,packets_predicate>(
        vostok::network_core::udp_match_packet **__first,
        vostok::network_core::udp_match_packet **__last,
        vostok::network_core::udp_match_packet **__formal,
        packets_predicate __comp)
{
  while ( __first != __last )
  {
    stlp_std::priv::__unguarded_linear_insert<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,packets_predicate>(
      __first,
      *__first,
      __comp);
    ++__first;
  }
}


void __usercall stlp_std::priv::__unguarded_insertion_sort_aux<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result *__first@<eax>,
        vostok::physics::closest_ray_result *__last@<edi>,
        __int64 __formal,
        float __comp_8)
{
  vostok::physics::closest_ray_result *i; // esi
  vostok::physics::distance_predicate v5; // [esp-Ch] [ebp-10h]

  for ( i = __first; i != __last; ++i )
  {
    *(_QWORD *)&v5.m_from.x = __formal;
    v5.m_from.z = __comp_8;
    stlp_std::priv::__unguarded_linear_insert<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
      i,
      *i,
      v5);
  }
}


void __cdecl stlp_std::priv::__unguarded_insertion_sort_aux<vostok::sound::propagator_info *,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        vostok::sound::propagator_info *__first,
        vostok::sound::propagator_info *__last,
        vostok::sound::propagator_info *__formal,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  while ( __first != __last )
  {
    stlp_std::priv::__unguarded_linear_insert<vostok::sound::propagator_info *,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
      __first,
      *__first,
      __comp);
    ++__first;
  }
}


void __cdecl stlp_std::priv::__unguarded_insertion_sort_aux<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__first,
        vostok::math::curve_point<float> *__last,
        vostok::math::curve_point<float> *__formal,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  vostok::math::curve_point<float> *i; // esi

  for ( i = __first; i != __last; ++i )
    stlp_std::priv::__unguarded_linear_insert<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
      i,
      *i,
      __comp);
}


void __cdecl stlp_std::priv::__unguarded_insertion_sort_aux<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        vostok::particle::curve_point<float> *__first,
        vostok::particle::curve_point<float> *__last,
        vostok::particle::curve_point<float> *__formal,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<float> *, const vostok::particle::curve_point<float> *))
{
  while ( __first != __last )
  {
    stlp_std::priv::__unguarded_linear_insert<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
      __first,
      *__first,
      __comp);
    ++__first;
  }
}


void __cdecl stlp_std::priv::__unguarded_insertion_sort_aux<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        stlp_std::pair<vostok::ai::npc const *,float> *__first,
        stlp_std::pair<vostok::ai::npc const *,float> *__last,
        stlp_std::pair<vostok::ai::npc const *,float> *__formal,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::npc const *,float> *, const stlp_std::pair<vostok::ai::npc const *,float> *))
{
  _DWORD v4[5]; // [esp-Ch] [ebp-18h] BYREF
  stlp_std::pair<vostok::ai::npc const *,float> *__i; // [esp+8h] [ebp-4h]

  for ( __i = __first; __i != __last; ++__i )
  {
    v4[2] = __comp;
    v4[3] = v4;
    stlp_std::priv::__unguarded_linear_insert<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
      (stlp_std::pair<vostok::ai::weapon const *,unsigned int> *)__i,
      *(stlp_std::pair<vostok::ai::weapon const *,unsigned int> *)__i,
      (bool (__cdecl *)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))__comp);
  }
}


void __cdecl stlp_std::priv::__unguarded_insertion_sort_aux<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__first,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__last,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__formal,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))
{
  _DWORD v4[5]; // [esp-Ch] [ebp-18h] BYREF
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__i; // [esp+8h] [ebp-4h]

  for ( __i = __first; __i != __last; ++__i )
  {
    v4[2] = __comp;
    v4[3] = v4;
    stlp_std::priv::__unguarded_linear_insert<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
      __i,
      *__i,
      __comp);
  }
}


void __usercall stlp_std::priv::__unguarded_insertion_sort_aux<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        vostok::render::custom_config_value *__first@<eax>,
        vostok::render::custom_config_value *__last@<edi>)
{
  vostok::render::custom_config_value *i; // esi
  bool (__cdecl *v3)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *); // [esp+0h] [ebp-4h]

  for ( i = __first; i != __last; ++i )
    stlp_std::priv::__unguarded_linear_insert<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
      i,
      *i,
      v3);
}


void __usercall stlp_std::priv::__unguarded_insertion_sort_aux<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        vostok::render::shader_constant *__first@<eax>,
        vostok::render::shader_constant *__last@<edi>)
{
  vostok::render::shader_constant *i; // esi
  vostok::render::shader_constant v3; // [esp-18h] [ebp-1Ch]
  bool (__cdecl *v4)(const vostok::render::shader_constant *, const vostok::render::shader_constant *); // [esp+0h] [ebp-4h]

  for ( i = __first; i != __last; ++i )
  {
    v3.m_slot.m_value = i->m_slot.m_value;
    v3.m_source.m_pointer = i->m_source.m_pointer;
    v3.m_source.m_size = i->m_source.m_size;
    v3.m_host = i->m_host;
    stlp_std::priv::__unguarded_linear_insert<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
      i,
      v3,
      v4);
  }
}
