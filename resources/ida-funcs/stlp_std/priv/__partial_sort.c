void __usercall stlp_std::priv::__partial_sort<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        unsigned int *__first@<eax>,
        unsigned int *__middle,
        unsigned int *__last,
        unsigned int *__formal)
{
  unsigned int *v4; // ebx
  unsigned int v6; // eax
  unsigned int *v7; // [esp+0h] [ebp-10h]
  int *v8; // [esp+4h] [ebp-Ch]

  v4 = __middle;
  stlp_std::__make_heap<unsigned int *,vostok::render::culling::portal_id_closer_to_point,unsigned int,int>(
    __first,
    __middle,
    (vostok::render::culling::portal_id_closer_to_point)__formal,
    v7,
    v8);
  if ( __middle < __last )
  {
    do
    {
      v6 = *v4;
      if ( *(float *)&__formal[*__first] > *(float *)&__formal[*v4] )
      {
        *v4 = *__first;
        stlp_std::__adjust_heap<unsigned int *,int,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
          __first,
          0,
          __middle - __first,
          v6,
          (vostok::render::culling::portal_id_closer_to_point)__formal);
      }
      ++v4;
    }
    while ( v4 < __last );
  }
  stlp_std::sort_heap<unsigned int *,vostok::render::culling::portal_id_closer_to_point>(
    __first,
    __middle,
    (vostok::render::culling::portal_id_closer_to_point)__formal);
}


void __usercall stlp_std::priv::__partial_sort<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        unsigned int *__first@<eax>,
        unsigned int *__middle,
        unsigned int *__last,
        unsigned int *__formal)
{
  unsigned int *i; // edi
  unsigned int v6; // eax
  unsigned int *v7; // [esp+0h] [ebp-10h]
  int *v8; // [esp+4h] [ebp-Ch]

  stlp_std::__make_heap<unsigned int *,stlp_std::less<unsigned int>,unsigned int,int>(
    __first,
    __middle,
    (stlp_std::less<unsigned int>)__formal,
    v7,
    v8);
  for ( i = __middle; i < __last; ++i )
  {
    v6 = *i;
    if ( *i < *__first )
    {
      *i = *__first;
      stlp_std::__adjust_heap<void const * *,int,void const *,stlp_std::less<void const *>>(
        __first,
        0,
        __middle - __first,
        v6,
        (stlp_std::less<unsigned int>)__formal);
    }
  }
  stlp_std::sort_heap<unsigned int *,stlp_std::less<unsigned int>>(
    __first,
    __middle,
    (stlp_std::less<unsigned int>)__formal);
}


void __usercall stlp_std::priv::__partial_sort<float *,float,stlp_std::less<float>>(
        float *__first@<eax>,
        float *__middle,
        float *__last,
        float *__formal)
{
  float *i; // ebx
  float *v7; // [esp+8h] [ebp-10h]
  int *v8; // [esp+Ch] [ebp-Ch]
  float *__middlea; // [esp+1Ch] [ebp+4h]

  stlp_std::__make_heap<float *,stlp_std::less<float>,float,int>(
    __first,
    __middle,
    (stlp_std::less<float>)__formal,
    v7,
    v8);
  for ( i = __middle; i < __last; ++i )
  {
    __middlea = *(float **)i;
    if ( *__first > *i )
    {
      *i = *__first;
      stlp_std::__adjust_heap<float *,int,float,stlp_std::less<float>>(
        __first,
        0,
        __middle - __first,
        *(float *)&__middlea,
        (stlp_std::less<float>)__formal);
    }
  }
  stlp_std::sort_heap<float *,stlp_std::less<float>>(__first, __middle, (stlp_std::less<float>)__formal);
}


void __cdecl stlp_std::priv::__partial_sort<survarium::anomaly_state * *,survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
        const vostok::ai::sound_item **__first,
        const vostok::ai::sound_item **__middle,
        const vostok::ai::sound_item **__last,
        const vostok::ai::sound_item **__formal,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  const vostok::ai::sound_item **i; // [esp+4h] [ebp-Ch]
  const vostok::ai::sound_item *__val; // [esp+8h] [ebp-8h]
  const vostok::ai::sound_item **__i; // [esp+Ch] [ebp-4h]

  stlp_std::make_heap<vostok::ai::planning::goal * *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
    __first,
    __middle,
    __comp);
  for ( __i = __middle; __i < __last; ++__i )
  {
    if ( __comp(*__i, *__first) )
    {
      __val = *__i;
      *__i = *__first;
      stlp_std::__adjust_heap<vostok::ai::planning::goal * *,int,vostok::ai::planning::goal *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
        __first,
        0,
        __middle - __first,
        __val,
        __comp);
    }
  }
  for ( i = __middle; i - __first > 1; --i )
    stlp_std::pop_heap<vostok::ai::animation_item const * *,bool (__cdecl *)(vostok::ai::animation_item const *,vostok::ai::animation_item const *)>(
      __first,
      i,
      __comp);
}


void __usercall stlp_std::priv::__partial_sort<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first@<eax>,
        vostok::render::grass_patch **__middle,
        vostok::render::grass_patch **__last,
        __int64 __formal,
        float __comp_8)
{
  vostok::render::grass_patch **v5; // ebx
  int v7; // ebp
  float v8; // xmm6_4
  vostok::render::grass_patch *v9; // eax
  vostok::render::sort_grass_patch_predicate v10; // [esp-1Ch] [ebp-28h]
  vostok::render::sort_grass_patch_predicate v11; // [esp-1Ch] [ebp-28h]

  v5 = __middle;
  v7 = __middle - __first;
  if ( v7 >= 2 )
    stlp_std::__make_heap<vostok::render::grass_patch * *,vostok::render::sort_grass_patch_predicate,vostok::render::grass_patch *,int>(
      __first,
      __middle);
  if ( __middle < __last )
  {
    v8 = __comp_8;
    do
    {
      v9 = *v5;
      if ( (float)((float)((float)((float)((*__first)->m_origin.z - v8) * (float)((*__first)->m_origin.z - v8))
                         + (float)((float)((*__first)->m_origin.y - *((float *)&__formal + 1))
                                 * (float)((*__first)->m_origin.y - *((float *)&__formal + 1))))
                 + (float)((float)((*__first)->m_origin.x - *(float *)&__formal)
                         * (float)((*__first)->m_origin.x - *(float *)&__formal))) > (float)((float)((float)((float)((*v5)->m_origin.z - v8) * (float)((*v5)->m_origin.z - v8)) + (float)((float)((*v5)->m_origin.y - *((float *)&__formal + 1)) * (float)((*v5)->m_origin.y - *((float *)&__formal + 1))))
                                                                                           + (float)((float)((*v5)->m_origin.x - *(float *)&__formal) * (float)((*v5)->m_origin.x - *(float *)&__formal))) )
      {
        *v5 = *__first;
        *(_QWORD *)&v10.m_view_pos.x = __formal;
        v10.m_view_pos.z = __comp_8;
        stlp_std::__adjust_heap<vostok::render::grass_patch * *,int,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
          __first,
          0,
          v7,
          v9,
          v10);
        v8 = __comp_8;
      }
      ++v5;
    }
    while ( v5 < __last );
  }
  *(_QWORD *)&v11.m_view_pos.x = __formal;
  v11.m_view_pos.z = __comp_8;
  stlp_std::sort_heap<vostok::render::grass_patch * *,vostok::render::sort_grass_patch_predicate>(
    __first,
    __middle,
    v11);
}


void __usercall stlp_std::priv::__partial_sort<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
        vostok::animation::mixing::n_ary_tree_base_node **__first@<eax>,
        vostok::animation::mixing::n_ary_tree_base_node **__middle,
        vostok::animation::mixing::n_ary_tree_base_node **__last,
        vostok::animation::mixing::n_ary_tree_base_node **__formal)
{
  vostok::animation::mixing::n_ary_tree_base_node **v4; // ebx
  int v6; // ebp
  vostok::animation::mixing::n_ary_tree_base_node *v7; // ecx
  void (__thiscall *accept)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_double_dispatcher *, vostok::animation::mixing::n_ary_tree_base_node *); // eax
  vostok::animation::mixing::n_ary_tree_base_node *v9; // [esp-8h] [ebp-28h]
  vostok::animation::mixing::n_ary_tree_base_node *v10; // [esp-4h] [ebp-24h]
  void **v11; // [esp+18h] [ebp-8h] BYREF
  int v12; // [esp+1Ch] [ebp-4h]

  v4 = __middle;
  v6 = __middle - __first;
  if ( v6 >= 2 )
    stlp_std::__make_heap<vostok::animation::mixing::n_ary_tree_base_node * *,node_predicate,vostok::animation::mixing::n_ary_tree_base_node *,int>(
      __first,
      __middle);
  if ( __middle < __last )
  {
    do
    {
      v7 = *v4;
      accept = (*v4)->accept;
      v10 = *__first;
      v11 = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
      v12 = 0;
      accept(v7, (vostok::animation::mixing::n_ary_tree_double_dispatcher *)&v11, v10);
      if ( v12 == 1 )
      {
        v9 = *v4;
        *v4 = *__first;
        stlp_std::__adjust_heap<vostok::animation::mixing::n_ary_tree_base_node * *,int,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
          __first,
          0,
          v6,
          v9,
          (node_predicate)__formal);
      }
      ++v4;
    }
    while ( v4 < __last );
  }
  stlp_std::sort_heap<vostok::animation::mixing::n_ary_tree_base_node * *,node_predicate>(
    __first,
    __middle,
    (node_predicate)__formal);
}


void __usercall stlp_std::priv::__partial_sort<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,vostok::render::sort_by_ps_predicate>(
        vostok::render::render_surface_instance **__first@<eax>,
        vostok::render::render_surface_instance **__middle,
        vostok::render::render_surface_instance **__last,
        vostok::render::render_surface_instance **__formal,
        vostok::render::sort_by_ps_predicate __comp)
{
  const vostok::render::render_surface_instance **v5; // ebx
  int v7; // ebp
  vostok::render::sort_by_ps_predicate v8; // [esp-8h] [ebp-24h]
  vostok::render::render_surface_instance *__val; // [esp+10h] [ebp-Ch]

  v5 = (const vostok::render::render_surface_instance **)__middle;
  v7 = __middle - __first;
  if ( v7 >= 2 )
    stlp_std::__make_heap<vostok::render::render_surface_instance * *,vostok::render::sort_by_vs_predicate,vostok::render::render_surface_instance *,int>(
      __first,
      __middle);
  if ( __middle < __last )
  {
    do
    {
      __val = (vostok::render::render_surface_instance *)*v5;
      if ( vostok::render::sort_by_vs_predicate::operator()(
             (vostok::render::sort_by_ps_predicate *)&__formal,
             *v5,
             *__first) )
      {
        v8 = (vostok::render::sort_by_ps_predicate)__PAIR64__(__comp.m_stage_type, (unsigned int)__formal);
        *v5 = *__first;
        stlp_std::__adjust_heap<vostok::render::render_surface_instance * *,int,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
          __first,
          0,
          v7,
          __val,
          v8);
      }
      ++v5;
    }
    while ( v5 < (const vostok::render::render_surface_instance **)__last );
  }
  stlp_std::sort_heap<vostok::render::render_surface_instance * *,vostok::render::sort_by_vs_predicate>(
    __first,
    __middle,
    (vostok::render::sort_by_ps_predicate)__PAIR64__(__comp.m_stage_type, (unsigned int)__formal));
}


void __cdecl stlp_std::priv::__partial_sort<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key **__first,
        vostok::command_line::key **__middle,
        vostok::command_line::key **__last,
        vostok::command_line::key **__formal)
{
  const vostok::command_line::key **v4; // ebx
  vostok::command_line::key **v5; // esi
  int v6; // ebp
  const vostok::command_line::key *v7; // edi
  vostok::command_line::key *v8; // esi
  vostok::command_line::key_compare_predicate *v9; // [esp+0h] [ebp-14h]

  v4 = (const vostok::command_line::key **)__middle;
  v5 = __first;
  v6 = __middle - __first;
  if ( v6 >= 2 )
    stlp_std::__make_heap<vostok::command_line::key * *,vostok::command_line::key_compare_predicate,vostok::command_line::key *,int>(
      __first,
      __middle);
  if ( __middle < __last )
  {
    do
    {
      v7 = *v5;
      v8 = (vostok::command_line::key *)*v4;
      if ( vostok::command_line::key_compare_predicate::operator()(*v4, v7, v9) )
      {
        *v4 = v7;
        stlp_std::__adjust_heap<vostok::command_line::key * *,int,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
          __first,
          0,
          v6,
          v8,
          (vostok::command_line::key_compare_predicate)__formal);
      }
      v5 = __first;
      ++v4;
    }
    while ( v4 < (const vostok::command_line::key **)__last );
    v4 = (const vostok::command_line::key **)__middle;
  }
  stlp_std::sort_heap<vostok::command_line::key * *,vostok::command_line::key_compare_predicate>(
    v5,
    (vostok::command_line::key **)v4,
    (vostok::command_line::key_compare_predicate)__formal);
}


void __usercall stlp_std::priv::__partial_sort<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::hdd_manager_sorting_predicate>(
        vostok::resources::query_result **__first@<eax>,
        vostok::resources::query_result **__middle,
        vostok::resources::query_result **__last,
        vostok::resources::query_result **__formal)
{
  vostok::resources::query_result **v4; // ebx
  int v6; // ebp
  vostok::resources::query_result *v7; // [esp-8h] [ebp-20h]
  vostok::resources::query_result *v8; // [esp+0h] [ebp-18h]

  v4 = __middle;
  v6 = __middle - __first;
  if ( v6 >= 2 )
    stlp_std::__make_heap<vostok::resources::query_result * *,vostok::resources::hdd_manager_sorting_predicate,vostok::resources::query_result *,int>(
      __first,
      __middle);
  if ( __middle < __last )
  {
    do
    {
      if ( vostok::resources::hdd_manager_sorting_predicate::operator()(
             *v4,
             (vostok::resources::hdd_manager_sorting_predicate *)*__first,
             v8) )
      {
        v7 = *v4;
        *v4 = *__first;
        stlp_std::__adjust_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::hdd_manager_sorting_predicate>(
          __first,
          0,
          v6,
          v7,
          (vostok::resources::hdd_manager_sorting_predicate)__formal);
      }
      ++v4;
    }
    while ( v4 < __last );
  }
  stlp_std::sort_heap<vostok::resources::query_result * *,vostok::resources::hdd_manager_sorting_predicate>(
    __first,
    __middle,
    (vostok::resources::hdd_manager_sorting_predicate)__formal);
}


void __usercall stlp_std::priv::__partial_sort<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
        vostok::resources::query_result **__first@<ecx>,
        vostok::resources::query_result **__middle@<eax>,
        vostok::resources::query_result **__last,
        vostok::resources::query_result **__formal)
{
  int v6; // ebp
  vostok::resources::query_result **i; // ebx
  vostok::resources::query_result *v8; // eax

  v6 = __middle - __first;
  if ( v6 >= 2 )
    stlp_std::__make_heap<vostok::resources::query_result * *,vostok::resources::sorting_predicate,vostok::resources::query_result *,int>(
      __first,
      __middle);
  for ( i = __middle; i < __last; ++i )
  {
    v8 = *i;
    if ( (*i)->m_quality_index >= (*__first)->m_quality_index )
    {
      *i = *__first;
      stlp_std::__adjust_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
        __first,
        0,
        v6,
        v8,
        (vostok::resources::sorting_predicate)__formal);
    }
  }
  stlp_std::sort_heap<vostok::resources::query_result * *,vostok::resources::sorting_predicate>(
    __first,
    __middle,
    (vostok::resources::sorting_predicate)__formal);
}


void __usercall stlp_std::priv::__partial_sort<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
        vostok::resources::resource_base **__first@<eax>,
        vostok::resources::resource_base **__middle,
        vostok::resources::resource_base **__last,
        vostok::resources::resource_base **__formal)
{
  vostok::resources::resource_base **v4; // ebp
  int v6; // ebx
  vostok::resources::resource_base *v7; // ecx
  vostok::resources::resource_base *v8; // eax
  float m_current_satisfaction; // xmm1_4

  v4 = __middle;
  v6 = __middle - __first;
  if ( v6 >= 2 )
    stlp_std::__make_heap<vostok::resources::resource_base * *,vostok::resources::sorting_predicate,vostok::resources::resource_base *,int>(
      __first,
      __middle);
  if ( __middle < __last )
  {
    while ( 1 )
    {
      v7 = *v4;
      v8 = *__first;
      m_current_satisfaction = (*__first)->m_current_satisfaction;
      if ( fabs((*v4)->m_current_satisfaction - m_current_satisfaction) >= 0.050000001 )
        break;
      if ( v7->m_reconstruction_size < v8->m_reconstruction_size )
        goto LABEL_6;
LABEL_7:
      if ( ++v4 >= __last )
        goto LABEL_8;
    }
    if ( (*v4)->m_current_satisfaction <= m_current_satisfaction )
      goto LABEL_7;
LABEL_6:
    *v4 = v8;
    stlp_std::__adjust_heap<vostok::resources::resource_base * *,int,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
      __first,
      0,
      v6,
      v7,
      (vostok::resources::sorting_predicate)__formal);
    goto LABEL_7;
  }
LABEL_8:
  stlp_std::sort_heap<vostok::resources::resource_base * *,vostok::resources::sorting_predicate>(
    __first,
    __middle,
    (vostok::resources::sorting_predicate)__formal);
}


void __cdecl stlp_std::priv::__partial_sort<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,packets_predicate>(
        vostok::network_core::udp_match_packet **__first,
        vostok::network_core::udp_match_packet **__middle,
        vostok::network_core::udp_match_packet **__last,
        vostok::network_core::udp_match_packet **__formal,
        packets_predicate __comp)
{
  survarium::base_project::resolve_link_object *v5; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v6; // ecx
  vostok::network_core::udp_match_packet **i; // [esp+Ch] [ebp-18h]
  vostok::network_core::udp_match_packet *__val; // [esp+14h] [ebp-10h]
  int v9; // [esp+1Ch] [ebp-8h]
  vostok::network_core::udp_match_packet **__i; // [esp+20h] [ebp-4h]

  stlp_std::make_heap<vostok::network_core::udp_match_packet * *,packets_predicate>(__first, __middle, __comp);
  for ( __i = __middle; __i < __last; ++__i )
  {
    v9 = (int)*__i;
    v5 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)*__first,
           (int)*__first);
    if ( stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           v6,
           v9) < v5 )
    {
      __val = *__i;
      *__i = *__first;
      stlp_std::__adjust_heap<vostok::network_core::udp_match_packet * *,int,vostok::network_core::udp_match_packet *,packets_predicate>(
        __first,
        0,
        __middle - __first,
        __val,
        __comp);
    }
  }
  for ( i = __middle; i - __first > 1; --i )
    stlp_std::pop_heap<vostok::network_core::udp_match_packet * *,packets_predicate>(__first, i, __comp);
}


void __usercall stlp_std::priv::__partial_sort<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
        const char **__first@<eax>,
        const char **__middle,
        const char **__last,
        const char **__formal)
{
  const char **v4; // esi
  int v6; // ebx
  const char *v7; // [esp-8h] [ebp-18h]

  v4 = __middle;
  v6 = __middle - __first;
  if ( v6 >= 2 )
    stlp_std::__make_heap<char const * *,bool (__cdecl *)(char const *,char const *),char const *,int>(
      __first,
      __middle,
      (bool (__cdecl *)(const char *, const char *))__formal);
  if ( __middle < __last )
  {
    do
    {
      if ( ((unsigned __int8 (__cdecl *)(const char *, _DWORD))__formal)(*v4, *__first) )
      {
        v7 = *v4;
        *v4 = *__first;
        stlp_std::__adjust_heap<char const * *,int,char const *,bool (__cdecl *)(char const *,char const *)>(
          __first,
          0,
          v6,
          v7,
          (bool (__cdecl *)(const char *, const char *))__formal);
      }
      ++v4;
    }
    while ( v4 < __last );
  }
  stlp_std::sort_heap<char const * *,bool (__cdecl *)(char const *,char const *)>(
    __first,
    __middle,
    (bool (__cdecl *)(const char *, const char *))__formal);
}


void __cdecl stlp_std::priv::__partial_sort<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
        const char **__first,
        const char **__middle,
        const char **__last,
        const char **__formal)
{
  const char **v4; // esi
  const char *v5; // edi

  v4 = __middle;
  if ( __middle - __first >= 2 )
    stlp_std::__make_heap<char const * *,vostok::render::shader_macros_dort_predicate,char const *,int>(
      __first,
      __middle);
  if ( __middle < __last )
  {
    do
    {
      v5 = *v4;
      if ( strcmp(*v4, *__first) < 0 )
      {
        *v4 = *__first;
        stlp_std::__adjust_heap<char const * *,int,char const *,vostok::render::shader_macros_dort_predicate>(
          __first,
          0,
          __middle - __first,
          v5,
          (vostok::render::shader_macros_dort_predicate)__formal);
      }
      ++v4;
    }
    while ( v4 < __last );
    v4 = __middle;
  }
  stlp_std::sort_heap<char const * *,vostok::render::shader_macros_dort_predicate>(
    __first,
    v4,
    (vostok::render::shader_macros_dort_predicate)__formal);
}


void __cdecl stlp_std::priv::__partial_sort<char const * *,char const *,vostok::tips_sorting_predicate>(
        const char **__first,
        const char **__middle,
        const char **__last,
        const char **__formal)
{
  unsigned __int8 **v4; // ebx
  const char **v5; // esi
  unsigned __int8 *v6; // ebp
  char *v7; // edi
  int v8; // eax
  int v9; // esi
  int v10; // eax
  unsigned __int8 *v11; // [esp-10h] [ebp-20h]

  v4 = (unsigned __int8 **)__middle;
  v5 = __first;
  if ( __middle - __first >= 2 )
    stlp_std::__make_heap<char const * *,vostok::tips_sorting_predicate,char const *,int>(__first, __middle);
  if ( __middle < __last )
  {
    do
    {
      v6 = *v4;
      v7 = (char *)*v5;
      strstr(*v4, (unsigned __int8 *)__formal);
      v9 = v8;
      strstr((unsigned __int8 *)v7, (unsigned __int8 *)__formal);
      if ( v9 - (int)v6 < v10 - (int)v7 )
      {
        v11 = *v4;
        *v4 = (unsigned __int8 *)*__first;
        stlp_std::__adjust_heap<char const * *,int,char const *,vostok::tips_sorting_predicate>(
          __first,
          0,
          __middle - __first,
          (const char *)v11,
          (vostok::tips_sorting_predicate)__formal);
      }
      v5 = __first;
      ++v4;
    }
    while ( v4 < (unsigned __int8 **)__last );
    v4 = (unsigned __int8 **)__middle;
  }
  stlp_std::sort_heap<char const * *,vostok::tips_sorting_predicate>(
    v5,
    (const char **)v4,
    (vostok::tips_sorting_predicate)__formal);
}


void __usercall stlp_std::priv::__partial_sort<void const * *,void const *,stlp_std::less<void const *>>(
        const void **__first@<eax>,
        const void **__middle,
        const void **__last,
        const void **__formal)
{
  unsigned int *v5; // ebx
  unsigned int v6; // eax
  const void **v7; // [esp+0h] [ebp-10h]
  int *v8; // [esp+4h] [ebp-Ch]

  stlp_std::__make_heap<void const * *,stlp_std::less<void const *>,void const *,int>(
    __first,
    __middle,
    (stlp_std::less<void const *>)__formal,
    v7,
    v8);
  v5 = (unsigned int *)__middle;
  if ( __middle < __last )
  {
    do
    {
      v6 = *v5;
      if ( *v5 < (unsigned int)*__first )
      {
        *v5 = (unsigned int)*__first;
        stlp_std::__adjust_heap<void const * *,int,void const *,stlp_std::less<void const *>>(
          (unsigned int *)__first,
          0,
          __middle - __first,
          v6,
          (stlp_std::less<unsigned int>)__formal);
      }
      ++v5;
    }
    while ( v5 < (unsigned int *)__last );
  }
  stlp_std::sort_heap<void const * *,stlp_std::less<void const *>>(
    __first,
    __middle,
    (stlp_std::less<void const *>)__formal);
}


void __usercall stlp_std::priv::__partial_sort<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result *__first@<eax>,
        int *a2@<edi>,
        vostok::physics::closest_ray_result *__middle,
        vostok::physics::closest_ray_result *__last,
        __int64 __formal,
        float __comp_8)
{
  vostok::physics::closest_ray_result *v7; // esi
  float v8; // xmm6_4
  vostok::physics::distance_predicate v9; // [esp-18h] [ebp-28h]
  vostok::physics::distance_predicate v10; // [esp-18h] [ebp-28h]
  int *v11; // [esp-Ch] [ebp-1Ch]

  v11 = a2;
  if ( __middle - __first >= 2 )
    stlp_std::__make_heap<vostok::physics::closest_ray_result *,vostok::physics::distance_predicate,vostok::physics::closest_ray_result,int>(
      __first,
      __middle);
  v7 = __middle;
  if ( __middle < __last )
  {
    v8 = __comp_8;
    do
    {
      if ( (float)((float)((float)((float)(__first->hit_point_world.z - v8) * (float)(__first->hit_point_world.z - v8))
                         + (float)((float)(__first->hit_point_world.y - *((float *)&__formal + 1))
                                 * (float)(__first->hit_point_world.y - *((float *)&__formal + 1))))
                 + (float)((float)(__first->hit_point_world.x - *(float *)&__formal)
                         * (float)(__first->hit_point_world.x - *(float *)&__formal))) > (float)((float)((float)((float)(v7->hit_point_world.z - v8) * (float)(v7->hit_point_world.z - v8)) + (float)((float)(v7->hit_point_world.x - *(float *)&__formal) * (float)(v7->hit_point_world.x - *(float *)&__formal)))
                                                                                               + (float)((float)(v7->hit_point_world.y - *((float *)&__formal + 1)) * (float)(v7->hit_point_world.y - *((float *)&__formal + 1)))) )
      {
        *(_QWORD *)&v9.m_from.x = __formal;
        v9.m_from.z = __comp_8;
        stlp_std::__pop_heap<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate,int>(
          __first,
          __middle,
          v7,
          *v7,
          v9,
          v11);
        v8 = __comp_8;
      }
      ++v7;
    }
    while ( v7 < __last );
  }
  *(_QWORD *)&v10.m_from.x = __formal;
  v10.m_from.z = __comp_8;
  stlp_std::sort_heap<vostok::physics::closest_ray_result *,vostok::physics::distance_predicate>(__first, __middle, v10);
}


void __cdecl stlp_std::priv::__partial_sort<vostok::sound::propagator_info *,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        vostok::sound::propagator_info *__first,
        vostok::sound::propagator_info *__middle,
        vostok::sound::propagator_info *__last,
        vostok::sound::propagator_info *__formal,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  vostok::sound::propagator_info *i; // [esp+4h] [ebp-1Ch]
  vostok::sound::propagator_info v6; // [esp+8h] [ebp-18h]
  vostok::sound::propagator_info *__i; // [esp+1Ch] [ebp-4h]

  stlp_std::make_heap<vostok::sound::propagator_info *,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
    __first,
    __middle,
    __comp);
  for ( __i = __middle; __i < __last; ++__i )
  {
    if ( __comp(__i, __first) )
    {
      v6 = *__i;
      *__i = *__first;
      stlp_std::__adjust_heap<vostok::sound::propagator_info *,int,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        __first,
        0,
        __middle - __first,
        v6,
        __comp);
    }
  }
  for ( i = __middle; i - __first > 1; --i )
    stlp_std::pop_heap<vostok::sound::propagator_info *,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
      __first,
      i,
      __comp);
}


void __usercall stlp_std::priv::__partial_sort<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
        vostok::render::grass_patch::sort_info *__first@<eax>,
        int *a2@<edi>,
        vostok::render::grass_patch::sort_info *__middle,
        vostok::render::grass_patch::sort_info *__last,
        __int64 __formal,
        __int64 __comp_8)
{
  vostok::render::grass_patch::sort_info *v7; // esi
  float v8; // xmm6_4
  vostok::render::sort_indices_predicate v9; // [esp-20h] [ebp-30h]
  vostok::render::sort_indices_predicate v10; // [esp-20h] [ebp-30h]
  int *v11; // [esp-10h] [ebp-20h]

  v11 = a2;
  if ( __middle - __first >= 2 )
    stlp_std::__make_heap<vostok::render::grass_patch::sort_info *,vostok::render::sort_indices_predicate,vostok::render::grass_patch::sort_info,int>(
      __first,
      __middle);
  v7 = __middle;
  if ( __middle < __last )
  {
    v8 = *((float *)&__comp_8 + 1);
    do
    {
      if ( (float)((float)((float)((float)(__first->position.x - *((float *)&__formal + 1))
                                 * (float)(__first->position.x - *((float *)&__formal + 1)))
                         + (float)((float)(__first->position.z - v8) * (float)(__first->position.z - v8)))
                 + (float)((float)(__first->position.y - *(float *)&__comp_8)
                         * (float)(__first->position.y - *(float *)&__comp_8))) > (float)((float)((float)((float)(v7->position.x - *((float *)&__formal + 1)) * (float)(v7->position.x - *((float *)&__formal + 1)))
                                                                                                + (float)((float)(v7->position.z - v8) * (float)(v7->position.z - v8)))
                                                                                        + (float)((float)(v7->position.y - *(float *)&__comp_8)
                                                                                                * (float)(v7->position.y - *(float *)&__comp_8))) )
      {
        *(_QWORD *)&v9.m_patch = __formal;
        *(_QWORD *)&v9.m_view_pos.elements[1] = __comp_8;
        stlp_std::__pop_heap<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate,int>(
          __first,
          __middle,
          v7,
          *v7,
          v9,
          v11);
        v8 = *((float *)&__comp_8 + 1);
      }
      ++v7;
    }
    while ( v7 < __last );
  }
  *(_QWORD *)&v10.m_patch = __formal;
  *(_QWORD *)&v10.m_view_pos.elements[1] = __comp_8;
  stlp_std::sort_heap<vostok::render::grass_patch::sort_info *,vostok::render::sort_indices_predicate>(
    __first,
    __middle,
    v10);
}


void __cdecl stlp_std::priv::__partial_sort<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__first,
        vostok::math::curve_point<float> *__middle,
        vostok::math::curve_point<float> *__last,
        vostok::math::curve_point<float> *__formal,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  vostok::math::curve_point<float> *i; // esi
  int *v6; // [esp+0h] [ebp-10h]

  if ( __middle - __first >= 2 )
    stlp_std::__make_heap<vostok::math::curve_point<float> *,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &),vostok::math::curve_point<float>,int>(
      __first,
      __middle,
      __comp);
  for ( i = __middle; i < __last; ++i )
  {
    if ( __comp(i, __first) )
      stlp_std::__pop_heap<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &),int>(
        __first,
        __middle,
        i,
        *i,
        __comp,
        v6);
  }
  stlp_std::sort_heap<vostok::math::curve_point<float> *,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
    __first,
    __middle,
    __comp);
}


void __cdecl stlp_std::priv::__partial_sort<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        vostok::particle::curve_point<float> *__first,
        vostok::particle::curve_point<float> *__middle,
        vostok::particle::curve_point<float> *__last,
        vostok::particle::curve_point<float> *__formal,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<float> *, const vostok::particle::curve_point<float> *))
{
  vostok::particle::curve_point<float> *i; // [esp+4h] [ebp-20h]
  vostok::particle::curve_point<float> v6; // [esp+8h] [ebp-1Ch]
  vostok::particle::curve_point<float> *__i; // [esp+20h] [ebp-4h]

  stlp_std::make_heap<vostok::particle::curve_point<float> *,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
    __first,
    __middle,
    __comp);
  for ( __i = __middle; __i < __last; ++__i )
  {
    if ( __comp(__i, __first) )
    {
      v6 = *__i;
      *__i = *__first;
      stlp_std::__adjust_heap<vostok::particle::curve_point<float> *,int,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        __first,
        0,
        __middle - __first,
        v6,
        __comp);
    }
  }
  for ( i = __middle; i - __first > 1; --i )
    stlp_std::pop_heap<vostok::particle::curve_point<float> *,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
      __first,
      i,
      __comp);
}


void __cdecl stlp_std::priv::__partial_sort<vostok::math::curve_point<vostok::math::float4_pod> *,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
        vostok::math::curve_point<vostok::math::float4_pod> *__first,
        vostok::math::curve_point<vostok::math::float4_pod> *__middle,
        vostok::math::curve_point<vostok::math::float4_pod> *__last,
        vostok::math::curve_point<vostok::math::float4_pod> *__formal,
        bool (__cdecl *__comp)(const vostok::math::curve_point<vostok::math::float4_pod> *, const vostok::math::curve_point<vostok::math::float4_pod> *))
{
  vostok::math::curve_point<vostok::math::float4_pod> *v5; // esi
  vostok::math::curve_point<vostok::math::float4_pod> *v6; // edi
  vostok::math::curve_point<vostok::math::float4_pod> *i; // ebx
  int v8; // edx
  vostok::math::curve_point<vostok::math::float4_pod> v9; // [esp-4Ch] [ebp-A4h] BYREF
  int __len; // [esp+Ch] [ebp-4Ch]
  _BYTE v11[72]; // [esp+10h] [ebp-48h] BYREF

  v5 = __first;
  v6 = __middle;
  __len = __middle - __first;
  if ( __len >= 2 )
    stlp_std::__make_heap<vostok::math::curve_point<vostok::math::float4_pod> *,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &),vostok::math::curve_point<vostok::math::float4_pod>,int>(
      __first,
      __middle,
      __comp);
  for ( i = __middle; i < __last; ++i )
  {
    if ( __comp(i, v5) )
    {
      v8 = __len;
      qmemcpy(v11, i, sizeof(v11));
      qmemcpy(i, __first, sizeof(vostok::math::curve_point<vostok::math::float4_pod>));
      qmemcpy(&v9, v11, sizeof(v9));
      stlp_std::__adjust_heap<vostok::math::curve_point<vostok::math::float4_pod> *,int,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
        __first,
        0,
        v8,
        v9,
        __comp);
      v6 = __middle;
      v5 = __first;
    }
  }
  stlp_std::sort_heap<vostok::math::curve_point<vostok::math::float4_pod> *,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
    v5,
    v6,
    __comp);
}


void __cdecl stlp_std::priv::__partial_sort<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        stlp_std::pair<vostok::ai::npc const *,float> *__first,
        stlp_std::pair<vostok::ai::npc const *,float> *__middle,
        stlp_std::pair<vostok::ai::npc const *,float> *__last,
        stlp_std::pair<vostok::ai::npc const *,float> *__formal,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::npc const *,float> *, const stlp_std::pair<vostok::ai::npc const *,float> *))
{
  float second; // edx
  stlp_std::pair<vostok::ai::npc const *,float> *v6; // eax
  int v7; // [esp-Ch] [ebp-30h] BYREF
  stlp_std::pair<vostok::ai::npc const *,float> *v8; // [esp+0h] [ebp-24h]
  stlp_std::pair<vostok::ai::npc const *,float> *i; // [esp+4h] [ebp-20h]
  stlp_std::pair<vostok::ai::npc const *,float> v10; // [esp+8h] [ebp-1Ch] BYREF
  int *v11; // [esp+10h] [ebp-14h]
  stlp_std::pair<vostok::ai::npc const *,float> *v12; // [esp+18h] [ebp-Ch]
  stlp_std::pair<vostok::ai::npc const *,float> *__i; // [esp+20h] [ebp-4h]

  stlp_std::make_heap<stlp_std::pair<vostok::ai::npc const *,float> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
    __first,
    __middle,
    __comp);
  for ( __i = __middle; __i < __last; ++__i )
  {
    if ( __comp(__i, __first) )
    {
      v12 = &v10;
      v10 = *__i;
      second = __first->second;
      v6 = __i;
      __i->first = __first->first;
      v6->second = second;
      v11 = &v7;
      stlp_std::__adjust_heap<stlp_std::pair<vostok::ai::npc const *,float> *,int,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        __first,
        0,
        __middle - __first,
        v10,
        __comp);
    }
  }
  for ( i = __middle; i - __first > 1; --i )
  {
    v8 = i;
    stlp_std::pop_heap<stlp_std::pair<vostok::ai::npc const *,float> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
      __first,
      i,
      __comp);
  }
}


void __cdecl stlp_std::priv::__partial_sort<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__first,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__middle,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__last,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__formal,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))
{
  unsigned int second; // eax
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *v6; // ecx
  int v7; // [esp-Ch] [ebp-30h] BYREF
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *v8; // [esp+0h] [ebp-24h]
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *i; // [esp+4h] [ebp-20h]
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> v10; // [esp+8h] [ebp-1Ch] BYREF
  int *v11; // [esp+10h] [ebp-14h]
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *v12; // [esp+18h] [ebp-Ch]
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__i; // [esp+20h] [ebp-4h]

  stlp_std::make_heap<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
    __first,
    __middle,
    __comp);
  for ( __i = __middle; __i < __last; ++__i )
  {
    if ( __comp(__i, __first) )
    {
      v12 = &v10;
      v10 = *__i;
      second = __first->second;
      v6 = __i;
      __i->first = __first->first;
      v6->second = second;
      v11 = &v7;
      stlp_std::__adjust_heap<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,int,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        __first,
        0,
        __middle - __first,
        v10,
        __comp);
    }
  }
  for ( i = __middle; i - __first > 1; --i )
  {
    v8 = i;
    stlp_std::pop_heap<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
      __first,
      i,
      __comp);
  }
}


void __usercall stlp_std::priv::__partial_sort<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        vostok::render::custom_config_value *__first@<eax>,
        vostok::render::custom_config_value *__middle,
        vostok::render::custom_config_value *__last,
        vostok::render::custom_config_value *__formal)
{
  vostok::render::custom_config_value *i; // edi
  int *v6; // [esp+0h] [ebp-10h]

  if ( __middle - __first >= 2 )
    stlp_std::__make_heap<vostok::render::custom_config_value *,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &),vostok::render::custom_config_value,int>(
      __first,
      __middle,
      (bool (__cdecl *)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *))__formal);
  for ( i = __middle; i < __last; ++i )
  {
    if ( ((unsigned __int8 (__cdecl *)(vostok::render::custom_config_value *, vostok::render::custom_config_value *))__formal)(
           i,
           __first) )
    {
      stlp_std::__pop_heap<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &),int>(
        __first,
        __middle,
        i,
        *i,
        (bool (__cdecl *)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *))__formal,
        v6);
    }
  }
  stlp_std::sort_heap<vostok::render::custom_config_value *,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
    __first,
    __middle,
    (bool (__cdecl *)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *))__formal);
}


void __usercall stlp_std::priv::__partial_sort<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        vostok::render::shader_constant *__first@<eax>,
        vostok::render::shader_constant *__middle,
        vostok::render::shader_constant *__last,
        vostok::render::shader_constant *__formal)
{
  vostok::render::shader_constant *i; // esi
  vostok::render::shader_constant v6; // [esp-1Ch] [ebp-2Ch]
  int *v7; // [esp+0h] [ebp-10h]

  if ( __middle - __first >= 2 )
    stlp_std::__make_heap<vostok::render::shader_constant *,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &),vostok::render::shader_constant,int>(
      __first,
      __middle,
      (bool (__cdecl *)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))__formal);
  for ( i = __middle; i < __last; ++i )
  {
    if ( ((unsigned __int8 (__cdecl *)(vostok::render::shader_constant *, vostok::render::shader_constant *))__formal)(
           i,
           __first) )
    {
      v6.m_slot.m_value = i->m_slot.m_value;
      v6.m_source.m_pointer = i->m_source.m_pointer;
      v6.m_source.m_size = i->m_source.m_size;
      v6.m_host = i->m_host;
      stlp_std::__pop_heap<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &),int>(
        __first,
        __middle,
        i,
        v6,
        (bool (__cdecl *)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))__formal,
        v7);
    }
  }
  stlp_std::sort_heap<vostok::render::shader_constant *,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
    __first,
    __middle,
    (bool (__cdecl *)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))__formal);
}
