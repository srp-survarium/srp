void __usercall stlp_std::priv::__final_insertion_sort<vostok::render::grass_patch * *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first@<eax>,
        vostok::render::grass_patch **__last@<edi>,
        vostok::render::sort_grass_patch_predicate __comp)
{
  vostok::render::grass_patch **v3; // esi
  vostok::render::sort_grass_patch_predicate v4; // [esp-8h] [ebp-18h]

  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    if ( __first != __last )
      stlp_std::priv::__insertion_sort<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
        __first,
        __last);
  }
  else
  {
    v3 = __first + 16;
    stlp_std::priv::__insertion_sort<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
      __first,
      __first + 16);
    *(_QWORD *)&v4.m_view_pos.x = *(_QWORD *)&__comp.m_view_pos.elements[1];
    stlp_std::priv::__unguarded_insertion_sort_aux<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
      v3,
      __last,
      (vostok::render::grass_patch **)LODWORD(__comp.m_view_pos.x),
      v4);
  }
}


void __usercall stlp_std::priv::__final_insertion_sort<vostok::animation::mixing::n_ary_tree_base_node * *,node_predicate>(
        vostok::animation::mixing::n_ary_tree_base_node **__first@<eax>,
        vostok::animation::mixing::n_ary_tree_base_node **__last,
        node_predicate __comp)
{
  vostok::animation::mixing::n_ary_tree_base_node **v4; // ebx
  vostok::animation::mixing::n_ary_tree_base_node **j; // esi
  vostok::animation::mixing::n_ary_tree_base_node **v6; // esi
  vostok::animation::mixing::n_ary_tree_base_node **i; // esi

  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    if ( __first != __last )
    {
      for ( i = __first + 1; i != __last; ++i )
        stlp_std::priv::__linear_insert<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
          __first,
          i,
          *i,
          __comp);
    }
  }
  else
  {
    v4 = __first + 16;
    for ( j = __first + 1; j != v4; ++j )
      stlp_std::priv::__linear_insert<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
        __first,
        j,
        *j,
        __comp);
    v6 = __first + 16;
    if ( v4 != __last )
    {
      do
      {
        stlp_std::priv::__unguarded_linear_insert<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
          v6,
          *v6,
          __comp);
        ++v6;
      }
      while ( v6 != __last );
    }
  }
}


void __usercall stlp_std::priv::__final_insertion_sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_ps_predicate>(
        vostok::render::render_surface_instance **__first@<eax>,
        vostok::render::render_surface_instance **__last@<edi>,
        vostok::render::sort_by_ps_predicate __comp)
{
  vostok::render::render_surface_instance **v3; // esi
  vostok::render::enum_render_stage_type m_stage_type; // ebx
  unsigned int i; // ebp
  vostok::render::sort_by_ps_predicate v6; // [esp+0h] [ebp-1Ch]
  vostok::render::sort_by_ps_predicate v7; // [esp+10h] [ebp-Ch] BYREF

  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    v7 = __comp;
    if ( __first != __last )
      stlp_std::priv::__insertion_sort<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
        __first,
        __last,
        (vostok::render::render_surface_instance **)&v7,
        v6);
  }
  else
  {
    v3 = __first + 16;
    stlp_std::priv::__insertion_sort<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
      __first,
      __first + 16,
      (vostok::render::render_surface_instance **)&__comp,
      v6);
    m_stage_type = __comp.m_stage_type;
    for ( i = __comp.m_tech_index; v3 != __last; ++v3 )
      stlp_std::priv::__unguarded_linear_insert<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,vostok::render::sort_by_ps_predicate>(
        v3,
        *v3,
        (vostok::render::sort_by_ps_predicate)__PAIR64__(i, m_stage_type));
  }
}


void __usercall stlp_std::priv::__final_insertion_sort<vostok::command_line::key * *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key **__first@<eax>,
        vostok::command_line::key **__last@<edi>,
        int a3@<ecx>,
        vostok::command_line::key_compare_predicate a4@<sil>,
        vostok::command_line::key **__comp)
{
  vostok::command_line::key **v5; // esi
  vostok::command_line::key_compare_predicate v7; // [esp-4h] [ebp-8h]
  vostok::command_line::key_compare_predicate v8[4]; // [esp+0h] [ebp-4h] BYREF

  *(_DWORD *)v8 = a3;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    v8[0] = (vostok::command_line::key_compare_predicate)__comp;
    if ( __first != __last )
      stlp_std::priv::__insertion_sort<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        __first,
        __last,
        (vostok::command_line::key **)v8,
        v8[0]);
  }
  else
  {
    v5 = __first + 16;
    stlp_std::priv::__insertion_sort<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
      __first,
      __first + 16,
      (vostok::command_line::key **)&__comp,
      a4);
    stlp_std::priv::__unguarded_insertion_sort_aux<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
      v5,
      __last,
      __comp,
      v7);
  }
}


void __usercall stlp_std::priv::__final_insertion_sort<vostok::resources::resource_base * *,vostok::resources::sorting_predicate>(
        vostok::resources::resource_base **__first@<eax>,
        vostok::resources::sorting_predicate a2@<sil>,
        vostok::resources::resource_base **__last,
        vostok::resources::sorting_predicate __comp)
{
  vostok::resources::resource_base **v4; // ebx
  vostok::resources::resource_base **v5; // esi
  vostok::resources::sorting_predicate v6; // bp
  vostok::resources::sorting_predicate v8; // [esp+0h] [ebp-4h]

  v4 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    LOBYTE(__last) = __comp;
    if ( __first != v4 )
      stlp_std::priv::__insertion_sort<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
        __first,
        v4,
        (vostok::resources::resource_base **)&__last,
        v8);
  }
  else
  {
    v5 = __first + 16;
    stlp_std::priv::__insertion_sort<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
      __first,
      __first + 16,
      (vostok::resources::resource_base **)&__comp,
      a2);
    LOBYTE(__last) = __comp;
    if ( v5 != v4 )
    {
      v6 = (vostok::resources::sorting_predicate)__last;
      do
      {
        stlp_std::priv::__unguarded_linear_insert<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
          v5,
          *v5,
          v6);
        ++v5;
      }
      while ( v5 != v4 );
    }
  }
}


void __cdecl stlp_std::priv::__final_insertion_sort<vostok::network_core::udp_match_packet * *,packets_predicate>(
        vostok::network_core::udp_match_packet **__first,
        vostok::network_core::udp_match_packet **__last,
        packets_predicate __comp)
{
  if ( __last - __first <= 16 )
  {
    stlp_std::priv::__insertion_sort<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,packets_predicate>(
      __first,
      __last,
      0,
      __comp);
  }
  else
  {
    stlp_std::priv::__insertion_sort<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,packets_predicate>(
      __first,
      __first + 16,
      0,
      __comp);
    stlp_std::priv::__unguarded_insertion_sort_aux<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,packets_predicate>(
      __first + 16,
      __last,
      0,
      __comp);
  }
}


void __usercall stlp_std::priv::__final_insertion_sort<char const * *,bool (__cdecl *)(char const *,char const *)>(
        const char **__first@<eax>,
        bool (__cdecl *a2)(const char *, const char *)@<ebx>,
        const char **__last)
{
  const char **j; // esi
  const char **k; // esi
  const char **i; // esi
  bool (__cdecl *v7)(const char *, const char *); // [esp-4h] [ebp-10h]
  bool (__cdecl *v8)(const char *, const char *); // [esp+0h] [ebp-Ch]

  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    if ( __first != __last )
    {
      for ( i = __first + 1; i != __last; ++i )
        stlp_std::priv::__linear_insert<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
          __first,
          i,
          *i,
          v8);
    }
  }
  else
  {
    v7 = a2;
    for ( j = __first + 1; j != __first + 16; ++j )
      stlp_std::priv::__linear_insert<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
        __first,
        j,
        *j,
        v7);
    for ( k = __first + 16; k != __last; ++k )
      stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
        k,
        *k,
        v8);
  }
}


void __usercall stlp_std::priv::__final_insertion_sort<char const * *,vostok::render::shader_macros_dort_predicate>(
        const char **__first@<eax>,
        const char **__last,
        vostok::render::shader_macros_dort_predicate __comp)
{
  const char **j; // esi
  const char **k; // esi
  const char **i; // esi

  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    if ( __first != __last )
    {
      for ( i = __first + 1; i != __last; ++i )
        stlp_std::priv::__linear_insert<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
          __first,
          i,
          *i,
          __comp);
    }
  }
  else
  {
    for ( j = __first + 1; j != __first + 16; ++j )
      stlp_std::priv::__linear_insert<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
        __first,
        j,
        *j,
        __comp);
    for ( k = __first + 16; k != __last; ++k )
      stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
        k,
        *k,
        __comp);
  }
}


void __usercall stlp_std::priv::__final_insertion_sort<char const * *,vostok::tips_sorting_predicate>(
        const char **__first@<edi>,
        const char **__last,
        vostok::tips_sorting_predicate __comp)
{
  const char **j; // esi
  const char **k; // esi
  const char **i; // esi

  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    if ( __first != __last )
    {
      for ( i = __first + 1; i != __last; ++i )
        stlp_std::priv::__linear_insert<char const * *,char const *,vostok::tips_sorting_predicate>(
          __first,
          i,
          *i,
          __comp);
    }
  }
  else
  {
    for ( j = __first + 1; j != __first + 16; ++j )
      stlp_std::priv::__linear_insert<char const * *,char const *,vostok::tips_sorting_predicate>(
        __first,
        j,
        *j,
        __comp);
    for ( k = __first + 16; k != __last; ++k )
      stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,vostok::tips_sorting_predicate>(
        k,
        *k,
        __comp);
  }
}


void __cdecl stlp_std::priv::__final_insertion_sort<vostok::ai::sound_item const * *,bool (__cdecl *)(vostok::ai::sound_item const *,vostok::ai::sound_item const *)>(
        const vostok::ai::sound_item **__first,
        const vostok::ai::sound_item **__last,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  if ( __last - __first <= 16 )
  {
    stlp_std::priv::__insertion_sort<vostok::ai::planning::goal * *,vostok::ai::planning::goal *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
      __first,
      __last,
      0,
      __comp);
  }
  else
  {
    stlp_std::priv::__insertion_sort<vostok::ai::planning::goal * *,vostok::ai::planning::goal *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
      __first,
      __first + 16,
      0,
      __comp);
    stlp_std::priv::__unguarded_insertion_sort_aux<survarium::anomaly_state * *,survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
      __first + 16,
      __last,
      0,
      __comp);
  }
}


void __usercall stlp_std::priv::__final_insertion_sort<vostok::physics::closest_ray_result *,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result *__first@<esi>,
        vostok::physics::closest_ray_result *__last@<eax>,
        vostok::physics::distance_predicate __comp)
{
  vostok::physics::distance_predicate v4; // [esp-8h] [ebp-1Ch]

  if ( __last - __first <= 16 )
  {
    if ( __first != __last )
      stlp_std::priv::__insertion_sort<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
        __first,
        __last);
  }
  else
  {
    stlp_std::priv::__insertion_sort<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
      __first,
      __first + 16);
    *(_QWORD *)&v4.m_from.x = *(_QWORD *)&__comp.m_from.elements[1];
    stlp_std::priv::__unguarded_insertion_sort_aux<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
      __first + 16,
      __last,
      (vostok::physics::closest_ray_result *)LODWORD(__comp.m_from.x),
      v4);
  }
}


void __cdecl stlp_std::priv::__final_insertion_sort<vostok::sound::propagator_info *,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        vostok::sound::propagator_info *__first,
        vostok::sound::propagator_info *__last,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  if ( __last - __first <= 16 )
  {
    stlp_std::priv::__insertion_sort<vostok::sound::propagator_info *,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
      __first,
      __last,
      0,
      __comp);
  }
  else
  {
    stlp_std::priv::__insertion_sort<vostok::sound::propagator_info *,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
      __first,
      __first + 16,
      0,
      __comp);
    stlp_std::priv::__unguarded_insertion_sort_aux<vostok::sound::propagator_info *,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
      __first + 16,
      __last,
      0,
      __comp);
  }
}


void __usercall stlp_std::priv::__final_insertion_sort<vostok::render::grass_patch::sort_info *,vostok::render::sort_indices_predicate>(
        vostok::render::grass_patch::sort_info *__first@<esi>,
        vostok::render::grass_patch::sort_info *__last@<eax>,
        vostok::render::sort_indices_predicate __comp)
{
  vostok::render::sort_indices_predicate v4; // [esp-Ch] [ebp-24h]

  if ( __last - __first <= 16 )
  {
    if ( __first != __last )
      stlp_std::priv::__insertion_sort<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
        __first,
        __last);
  }
  else
  {
    stlp_std::priv::__insertion_sort<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
      __first,
      __first + 16);
    *(vostok::math::float3 *)&v4.m_patch = __comp.m_view_pos;
    stlp_std::priv::__unguarded_insertion_sort_aux<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
      __first + 16,
      __last,
      (vostok::render::grass_patch::sort_info *)__comp.m_patch,
      v4);
  }
}


void __cdecl stlp_std::priv::__final_insertion_sort<vostok::math::curve_point<float> *,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__first,
        vostok::math::curve_point<float> *__last,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  if ( __last - __first <= 16 )
  {
    stlp_std::priv::__insertion_sort<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
      __first,
      __last,
      0,
      __comp);
  }
  else
  {
    stlp_std::priv::__insertion_sort<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
      __first,
      __first + 16,
      0,
      __comp);
    stlp_std::priv::__unguarded_insertion_sort_aux<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
      __first + 16,
      __last,
      0,
      __comp);
  }
}


void __cdecl stlp_std::priv::__final_insertion_sort<vostok::particle::curve_point<float> *,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        vostok::particle::curve_point<float> *__first,
        vostok::particle::curve_point<float> *__last,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<float> *, const vostok::particle::curve_point<float> *))
{
  if ( __last - __first <= 16 )
  {
    stlp_std::priv::__insertion_sort<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
      __first,
      __last,
      0,
      __comp);
  }
  else
  {
    stlp_std::priv::__insertion_sort<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
      __first,
      __first + 16,
      0,
      __comp);
    stlp_std::priv::__unguarded_insertion_sort_aux<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
      __first + 16,
      __last,
      0,
      __comp);
  }
}


void __cdecl stlp_std::priv::__final_insertion_sort<vostok::math::curve_point<vostok::math::float4_pod> *,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
        vostok::math::curve_point<vostok::math::float4_pod> *__first,
        vostok::math::curve_point<vostok::math::float4_pod> *__last,
        bool (__cdecl *__comp)(const vostok::math::curve_point<vostok::math::float4_pod> *, const vostok::math::curve_point<vostok::math::float4_pod> *))
{
  if ( __last - __first <= 16 )
  {
    stlp_std::priv::__insertion_sort<vostok::math::curve_point<vostok::math::float4_pod> *,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
      __first,
      __last,
      0,
      __comp);
  }
  else
  {
    stlp_std::priv::__insertion_sort<vostok::math::curve_point<vostok::math::float4_pod> *,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
      __first,
      __first + 16,
      0,
      __comp);
    stlp_std::priv::__unguarded_insertion_sort_aux<vostok::math::curve_point<vostok::math::float4_pod> *,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
      __first + 16,
      __last,
      0,
      __comp);
  }
}


void __cdecl stlp_std::priv::__final_insertion_sort<stlp_std::pair<vostok::ai::npc const *,float> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        stlp_std::pair<vostok::ai::npc const *,float> *__first,
        stlp_std::pair<vostok::ai::npc const *,float> *__last,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::npc const *,float> *, const stlp_std::pair<vostok::ai::npc const *,float> *))
{
  if ( __last - __first <= 16 )
  {
    stlp_std::priv::__insertion_sort<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
      __first,
      __last,
      0,
      __comp);
  }
  else
  {
    stlp_std::priv::__insertion_sort<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
      __first,
      __first + 16,
      0,
      __comp);
    stlp_std::priv::__unguarded_insertion_sort_aux<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
      __first + 16,
      __last,
      0,
      __comp);
  }
}


void __cdecl stlp_std::priv::__final_insertion_sort<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__first,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__last,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))
{
  if ( __last - __first <= 16 )
  {
    stlp_std::priv::__insertion_sort<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
      __first,
      __last,
      0,
      __comp);
  }
  else
  {
    stlp_std::priv::__insertion_sort<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
      __first,
      __first + 16,
      0,
      __comp);
    stlp_std::priv::__unguarded_insertion_sort_aux<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
      __first + 16,
      __last,
      0,
      __comp);
  }
}


void __usercall stlp_std::priv::__final_insertion_sort<vostok::render::custom_config_value *,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        vostok::render::custom_config_value *__first@<esi>,
        vostok::render::custom_config_value *__last@<eax>,
        vostok::render::custom_config_value *a3@<ebx>)
{
  bool (__cdecl *v4)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *); // [esp+0h] [ebp-4h]

  if ( __last - __first <= 16 )
  {
    if ( __first != __last )
      stlp_std::priv::__insertion_sort<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        __first,
        __last);
  }
  else
  {
    stlp_std::priv::__insertion_sort<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
      __first,
      __first + 16);
    stlp_std::priv::__unguarded_insertion_sort_aux<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
      __first + 16,
      __last,
      a3,
      v4);
  }
}


void __usercall stlp_std::priv::__final_insertion_sort<vostok::render::shader_constant *,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        vostok::render::shader_constant *__first@<esi>,
        vostok::render::shader_constant *__last@<eax>,
        vostok::render::shader_constant *a3@<ebx>)
{
  bool (__cdecl *v4)(const vostok::render::shader_constant *, const vostok::render::shader_constant *); // [esp+0h] [ebp-4h]

  if ( __last - __first <= 16 )
  {
    if ( __first != __last )
      stlp_std::priv::__insertion_sort<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        __first,
        __last);
  }
  else
  {
    stlp_std::priv::__insertion_sort<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
      __first,
      __first + 16);
    stlp_std::priv::__unguarded_insertion_sort_aux<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
      __first + 16,
      __last,
      a3,
      v4);
  }
}
