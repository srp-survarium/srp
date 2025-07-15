void __usercall stlp_std::priv::__introsort_loop<unsigned int *,unsigned int,int,vostok::render::culling::portal_id_closer_to_point>(
        vostok::render::culling::portal_id_closer_to_point a1@<edi>,
        unsigned int *__first,
        unsigned int *__last,
        unsigned int *__formal,
        int __depth_limit,
        vostok::render::culling::portal_id_closer_to_point __comp)
{
  unsigned int *v6; // ebp
  int v7; // kr00_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  unsigned int *v11; // eax
  unsigned int *v12; // esi

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    do
    {
      if ( !__depth_limit )
      {
        stlp_std::priv::__partial_sort<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
          __first,
          v6,
          v6,
          (unsigned int *)__comp.m_distances,
          a1);
        return;
      }
      --__depth_limit;
      v7 = v6 - __first;
      v8 = *(float *)((_DWORD)__comp.m_distances + 4 * *__first);
      v9 = *(float *)((_DWORD)__comp.m_distances + 4 * __first[v7 / 2]);
      v10 = *(float *)((_DWORD)__comp.m_distances + 4 * *(v6 - 1));
      v11 = &__first[v7 / 2];
      if ( v9 <= v8 )
      {
        if ( v10 > v8 )
          goto LABEL_8;
        if ( v10 > v9 )
LABEL_10:
          v11 = v6 - 1;
      }
      else if ( v10 <= v9 )
      {
        if ( v10 > v8 )
          goto LABEL_10;
LABEL_8:
        v11 = __first;
      }
      v12 = stlp_std::priv::__unguarded_partition<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
              __first,
              v6,
              *v11,
              __comp);
      stlp_std::priv::__introsort_loop<unsigned int *,unsigned int,int,vostok::render::culling::portal_id_closer_to_point>(
        v12,
        v6,
        0,
        __depth_limit,
        __comp);
      v6 = v12;
    }
    while ( (int)(((char *)v12 - (char *)__first) & 0xFFFFFFFC) > 64 );
  }
}


void __usercall stlp_std::priv::__introsort_loop<unsigned int *,unsigned int,int,stlp_std::less<unsigned int>>(
        stlp_std::less<unsigned int> a1@<sil>,
        unsigned int *__first,
        unsigned int *__last,
        unsigned int *__formal,
        int __depth_limit,
        unsigned int *__comp)
{
  unsigned int *v6; // ebx
  unsigned int v8; // ecx
  int v9; // kr00_4
  unsigned int v10; // edx
  unsigned int *v11; // eax
  unsigned int v12; // ebp
  unsigned int *v13; // esi
  int __depth_limita; // [esp+18h] [ebp+10h]

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    do
    {
      if ( !__depth_limit )
      {
        stlp_std::priv::__partial_sort<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
          __first,
          v6,
          v6,
          __comp,
          a1);
        return;
      }
      v8 = *__first;
      v9 = v6 - __first;
      v10 = __first[v9 / 2];
      v11 = &__first[v9 / 2];
      __depth_limita = __depth_limit - 1;
      v12 = *(v6 - 1);
      if ( *__first >= v10 )
      {
        if ( v8 < v12 )
          goto LABEL_8;
        if ( v10 < v12 )
LABEL_10:
          v11 = v6 - 1;
      }
      else if ( v10 >= v12 )
      {
        if ( v8 < v12 )
          goto LABEL_10;
LABEL_8:
        v11 = __first;
      }
      __depth_limit = __depth_limita;
      v13 = stlp_std::priv::__unguarded_partition<void const * *,void const *,stlp_std::less<void const *>>(
              __first,
              v6,
              *v11,
              (stlp_std::less<unsigned int>)__comp);
      stlp_std::priv::__introsort_loop<unsigned int *,unsigned int,int,stlp_std::less<unsigned int>>(
        v13,
        v6,
        0,
        __depth_limita,
        (stlp_std::less<unsigned int>)__comp);
      v6 = v13;
    }
    while ( (int)(((char *)v13 - (char *)__first) & 0xFFFFFFFC) > 64 );
  }
}


void __usercall stlp_std::priv::__introsort_loop<float *,float,int,stlp_std::less<float>>(
        stlp_std::less<float> a1@<sil>,
        float *__first,
        float *__last,
        float *__formal,
        int __depth_limit,
        float *__comp)
{
  float *v6; // ebx
  float v8; // xmm0_4
  float v9; // xmm2_4
  int v10; // kr00_4
  float v11; // xmm1_4
  float *v12; // eax
  float v13; // xmm0_4
  float *v14; // eax
  float *i; // esi
  float v16; // xmm1_4
  float v17; // xmm1_4

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( 1 )
    {
      if ( !__depth_limit )
      {
        stlp_std::priv::__partial_sort<float *,float,stlp_std::less<float>>(__first, v6, v6, __comp, a1);
        return;
      }
      v8 = *__first;
      v9 = *(v6 - 1);
      v10 = v6 - __first;
      v11 = __first[v10 / 2];
      v12 = &__first[v10 / 2];
      --__depth_limit;
      if ( v11 > *__first )
        break;
      if ( v9 > v8 )
        goto LABEL_8;
      if ( v9 > v11 )
        goto LABEL_10;
LABEL_11:
      v13 = *v12;
      v14 = v6;
      for ( i = __first; ; ++i )
      {
        while ( v13 > *i )
          ++i;
        do
          v16 = *--v14;
        while ( v16 > v13 );
        if ( i >= v14 )
          break;
        v17 = *i;
        *i = *v14;
        *v14 = v17;
      }
      stlp_std::priv::__introsort_loop<float *,float,int,stlp_std::less<float>>(
        i,
        v6,
        0,
        __depth_limit,
        (stlp_std::less<float>)__comp);
      v6 = i;
      if ( (int)(((char *)i - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    if ( v9 > v11 )
      goto LABEL_11;
    if ( v9 <= v8 )
    {
LABEL_8:
      v12 = __first;
      goto LABEL_11;
    }
LABEL_10:
    v12 = v6 - 1;
    goto LABEL_11;
  }
}


void __cdecl stlp_std::priv::__introsort_loop<vostok::render::grass_patch * *,vostok::render::grass_patch *,int,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first,
        vostok::render::grass_patch **__last,
        vostok::render::grass_patch **__formal,
        int __depth_limit,
        vostok::render::sort_grass_patch_predicate __comp)
{
  vostok::render::grass_patch **v5; // ebx
  vostok::render::grass_patch **v6; // eax
  vostok::render::grass_patch **v7; // esi
  __int128 v8; // [esp-Ch] [ebp-1Ch]

  v5 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( 1 )
    {
      *(vostok::render::sort_grass_patch_predicate *)&v8 = __comp;
      if ( !__depth_limit )
        break;
      --__depth_limit;
      v6 = (vostok::render::grass_patch **)stlp_std::priv::__median<vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
                                             __first,
                                             &__first[(v5 - __first) / 2],
                                             v5 - 1,
                                             __comp);
      v7 = stlp_std::priv::__unguarded_partition<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
             __first,
             v5,
             *v6,
             __comp);
      stlp_std::priv::__introsort_loop<vostok::render::grass_patch * *,vostok::render::grass_patch *,int,vostok::render::sort_grass_patch_predicate>(
        v7,
        v5,
        0,
        __depth_limit,
        __comp);
      v5 = v7;
      if ( (int)(((char *)v7 - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    stlp_std::priv::__partial_sort<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
      __first,
      v5,
      v5,
      (vostok::render::grass_patch **)LODWORD(__comp.m_view_pos.x),
      *(vostok::render::sort_grass_patch_predicate *)((char *)&v8 + 4));
  }
}


void __cdecl stlp_std::priv::__introsort_loop<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,int,node_predicate>(
        vostok::animation::mixing::n_ary_tree_base_node **__first,
        vostok::animation::mixing::n_ary_tree_base_node **__last,
        vostok::animation::mixing::n_ary_tree_base_node **__formal,
        int __depth_limit,
        vostok::animation::mixing::n_ary_tree_base_node **__comp)
{
  vostok::animation::mixing::n_ary_tree_base_node **v5; // ebx
  vostok::animation::mixing::n_ary_tree_base_node **v6; // eax
  vostok::animation::mixing::n_ary_tree_base_node **v7; // esi
  node_predicate v8; // [esp+0h] [ebp-10h]

  v5 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( __depth_limit )
    {
      --__depth_limit;
      v6 = (vostok::animation::mixing::n_ary_tree_base_node **)stlp_std::priv::__median<vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
                                                                 __first,
                                                                 &__first[(v5 - __first) / 2],
                                                                 v5 - 1,
                                                                 (node_predicate)__comp);
      v7 = stlp_std::priv::__unguarded_partition<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
             __first,
             v5,
             *v6,
             (node_predicate)__comp);
      stlp_std::priv::__introsort_loop<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,int,node_predicate>(
        v7,
        v5,
        0,
        __depth_limit,
        (node_predicate)__comp);
      v5 = v7;
      if ( (int)(((char *)v7 - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    stlp_std::priv::__partial_sort<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
      __first,
      v5,
      v5,
      __comp,
      v8);
  }
}


void __cdecl stlp_std::priv::__introsort_loop<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,int,vostok::render::sort_by_ps_predicate>(
        vostok::render::render_surface_instance **__first,
        vostok::render::render_surface_instance **__last,
        vostok::render::render_surface_instance **__formal,
        int __depth_limit,
        vostok::render::sort_by_ps_predicate __comp)
{
  vostok::render::render_surface_instance **v5; // edi
  vostok::render::render_surface_instance **v7; // eax
  vostok::render::render_surface_instance **v8; // esi
  vostok::render::sort_by_ps_predicate v9; // [esp-4h] [ebp-18h]

  v5 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( __depth_limit )
    {
      --__depth_limit;
      v7 = (vostok::render::render_surface_instance **)stlp_std::priv::__median<vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
                                                         __first,
                                                         &__first[(v5 - __first) / 2],
                                                         v5 - 1,
                                                         __comp);
      v8 = (vostok::render::render_surface_instance **)stlp_std::priv::__unguarded_partition<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
                                                         (const vostok::render::render_surface_instance **)__first,
                                                         v5,
                                                         *v7,
                                                         __comp);
      stlp_std::priv::__introsort_loop<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,int,vostok::render::sort_by_ps_predicate>(
        v8,
        v5,
        0,
        __depth_limit,
        __comp);
      v5 = v8;
      if ( (int)(((char *)v8 - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    v9.m_stage_type = __comp.m_tech_index;
    stlp_std::priv::__partial_sort<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,vostok::render::sort_by_ps_predicate>(
      __first,
      v5,
      v5,
      (vostok::render::render_surface_instance **)__comp.m_stage_type,
      v9);
  }
}


void __cdecl stlp_std::priv::__introsort_loop<vostok::ai::planning::goal * *,vostok::ai::planning::goal *,int,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
        const vostok::ai::sound_item **__first,
        const vostok::ai::sound_item **__last,
        const vostok::ai::sound_item **__formal,
        int __depth_limit,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  const vostok::ai::sound_item **v5; // eax
  const vostok::ai::sound_item **__cut; // [esp+0h] [ebp-4h]

  while ( __last - __first > 16 )
  {
    if ( !__depth_limit )
    {
      stlp_std::partial_sort<vostok::ai::planning::goal * *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
        __first,
        __last,
        __last,
        __comp);
      return;
    }
    --__depth_limit;
    v5 = (const vostok::ai::sound_item **)stlp_std::priv::__median<survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
                                            __first,
                                            &__first[(__last - __first) / 2],
                                            __last - 1,
                                            __comp);
    __cut = stlp_std::priv::__unguarded_partition<survarium::anomaly_state * *,survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
              __first,
              __last,
              *v5,
              __comp);
    stlp_std::priv::__introsort_loop<vostok::ai::planning::goal * *,vostok::ai::planning::goal *,int,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
      __cut,
      __last,
      0,
      __depth_limit,
      __comp);
    __last = __cut;
  }
}


void __usercall stlp_std::priv::__introsort_loop<vostok::command_line::key * *,vostok::command_line::key *,int,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key_compare_predicate a1@<sil>,
        vostok::command_line::key **__first,
        vostok::command_line::key **__last,
        vostok::command_line::key **__formal,
        int __depth_limit,
        vostok::command_line::key **__comp)
{
  vostok::command_line::key **v6; // edi
  vostok::command_line::key **v8; // eax
  vostok::command_line::key **v9; // esi

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( __depth_limit )
    {
      --__depth_limit;
      v8 = (vostok::command_line::key **)stlp_std::priv::__median<vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
                                           __first,
                                           &__first[(v6 - __first) / 2],
                                           v6 - 1,
                                           (vostok::command_line::key_compare_predicate)__comp);
      v9 = stlp_std::priv::__unguarded_partition<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
             __first,
             v6,
             *v8,
             (vostok::command_line::key_compare_predicate)__comp);
      stlp_std::priv::__introsort_loop<vostok::command_line::key * *,vostok::command_line::key *,int,vostok::command_line::key_compare_predicate>(
        v9,
        v6,
        0,
        __depth_limit,
        (vostok::command_line::key_compare_predicate)__comp);
      v6 = v9;
      if ( (int)(((char *)v9 - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    stlp_std::priv::__partial_sort<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
      __first,
      v6,
      v6,
      __comp,
      a1);
  }
}


void __usercall stlp_std::priv::__introsort_loop<vostok::resources::query_result * *,vostok::resources::query_result *,int,vostok::resources::sorting_predicate>(
        vostok::resources::sorting_predicate a1@<sil>,
        vostok::resources::query_result **__first,
        vostok::resources::query_result **__last,
        vostok::resources::query_result **__formal,
        int __depth_limit,
        vostok::resources::query_result **__comp)
{
  vostok::resources::query_result **v6; // ebx
  unsigned int m_quality_index; // ecx
  int v9; // kr00_4
  unsigned int v10; // edx
  vostok::resources::query_result **v11; // eax
  unsigned int v12; // ebp
  vostok::resources::query_result **v13; // esi
  int __depth_limita; // [esp+18h] [ebp+10h]

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    do
    {
      if ( !__depth_limit )
      {
        stlp_std::priv::__partial_sort<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
          __first,
          v6,
          v6,
          __comp,
          a1);
        return;
      }
      m_quality_index = (*__first)->m_quality_index;
      v9 = v6 - __first;
      v10 = __first[v9 / 2]->m_quality_index;
      v11 = &__first[v9 / 2];
      __depth_limita = __depth_limit - 1;
      v12 = (*(v6 - 1))->m_quality_index;
      if ( m_quality_index < v10 )
      {
        if ( m_quality_index >= v12 )
          goto LABEL_8;
        if ( v10 >= v12 )
LABEL_10:
          v11 = v6 - 1;
      }
      else if ( v10 < v12 )
      {
        if ( m_quality_index >= v12 )
          goto LABEL_10;
LABEL_8:
        v11 = __first;
      }
      __depth_limit = __depth_limita;
      v13 = stlp_std::priv::__unguarded_partition<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
              __first,
              v6,
              *v11,
              (vostok::resources::sorting_predicate)__comp);
      stlp_std::priv::__introsort_loop<vostok::resources::query_result * *,vostok::resources::query_result *,int,vostok::resources::sorting_predicate>(
        v13,
        v6,
        0,
        __depth_limita,
        (vostok::resources::sorting_predicate)__comp);
      v6 = v13;
    }
    while ( (int)(((char *)v13 - (char *)__first) & 0xFFFFFFFC) > 64 );
  }
}


void __usercall stlp_std::priv::__introsort_loop<vostok::resources::resource_base * *,vostok::resources::resource_base *,int,vostok::resources::sorting_predicate>(
        vostok::resources::sorting_predicate a1@<dil>,
        vostok::resources::resource_base **__first,
        vostok::resources::resource_base **__last,
        vostok::resources::resource_base **__formal,
        int __depth_limit,
        vostok::resources::resource_base **__comp)
{
  vostok::resources::resource_base **v6; // ebx
  vostok::resources::resource_base **v7; // eax
  vostok::resources::resource_base **v8; // esi

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( __depth_limit )
    {
      --__depth_limit;
      v7 = (vostok::resources::resource_base **)stlp_std::priv::__median<vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
                                                  __first,
                                                  &__first[(v6 - __first) / 2],
                                                  v6 - 1,
                                                  (vostok::resources::sorting_predicate)__comp);
      v8 = stlp_std::priv::__unguarded_partition<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
             __first,
             v6,
             *v7,
             (vostok::resources::sorting_predicate)__comp);
      stlp_std::priv::__introsort_loop<vostok::resources::resource_base * *,vostok::resources::resource_base *,int,vostok::resources::sorting_predicate>(
        v8,
        v6,
        0,
        __depth_limit,
        (vostok::resources::sorting_predicate)__comp);
      v6 = v8;
      if ( (int)(((char *)v8 - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    stlp_std::priv::__partial_sort<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
      __first,
      v6,
      v6,
      __comp,
      a1);
  }
}


void __cdecl stlp_std::priv::__introsort_loop<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,int,packets_predicate>(
        vostok::network_core::udp_match_packet **__first,
        vostok::network_core::udp_match_packet **__last,
        vostok::network_core::udp_match_packet **__formal,
        int __depth_limit,
        packets_predicate __comp)
{
  vostok::network_core::udp_match_packet **matched; // eax
  vostok::network_core::udp_match_packet **__cut; // [esp+28h] [ebp-4h]

  while ( __last - __first > 16 )
  {
    if ( !__depth_limit )
    {
      stlp_std::partial_sort<vostok::network_core::udp_match_packet * *,packets_predicate>(
        __first,
        __last,
        __last,
        __comp);
      return;
    }
    --__depth_limit;
    matched = (vostok::network_core::udp_match_packet **)stlp_std::priv::__median<vostok::network_core::udp_match_packet *,packets_predicate>(
                                                           __first,
                                                           &__first[(__last - __first) / 2],
                                                           __last - 1,
                                                           __comp);
    __cut = stlp_std::priv::__unguarded_partition<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,packets_predicate>(
              __first,
              __last,
              *matched,
              __comp);
    stlp_std::priv::__introsort_loop<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,int,packets_predicate>(
      __cut,
      __last,
      0,
      __depth_limit,
      __comp);
    __last = __cut;
  }
}


void __usercall stlp_std::priv::__introsort_loop<char const * *,char const *,int,bool (__cdecl *)(char const *,char const *)>(
        bool (__cdecl *a1)(const char *, const char *)@<edi>,
        const char **__first,
        const char **__last,
        const char **__formal,
        int __depth_limit,
        bool (__cdecl *__comp)(const char *, const char *))
{
  const char **v6; // ebx
  const char **v7; // eax
  const char **v8; // edi

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( __depth_limit )
    {
      --__depth_limit;
      v7 = (const char **)stlp_std::priv::__median<char const *,bool (__cdecl *)(char const *,char const *)>(
                            __first,
                            &__first[(v6 - __first) / 2],
                            v6 - 1,
                            __comp);
      v8 = stlp_std::priv::__unguarded_partition<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
             __first,
             v6,
             *v7,
             __comp);
      stlp_std::priv::__introsort_loop<char const * *,char const *,int,bool (__cdecl *)(char const *,char const *)>(
        v8,
        v6,
        0,
        __depth_limit,
        __comp);
      v6 = v8;
      if ( (int)(((char *)v8 - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    stlp_std::priv::__partial_sort<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
      __first,
      v6,
      v6,
      (const char **)__comp,
      a1);
  }
}


void __usercall stlp_std::priv::__introsort_loop<char const * *,char const *,int,vostok::render::shader_macros_dort_predicate>(
        vostok::render::shader_macros_dort_predicate a1@<dil>,
        const char **__first,
        const char **__last,
        const char **__formal,
        int __depth_limit,
        const char **__comp)
{
  const char **v6; // ebx
  const char **v7; // eax
  const char **v8; // esi

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( __depth_limit )
    {
      --__depth_limit;
      v7 = (const char **)stlp_std::priv::__median<char const *,vostok::render::shader_macros_dort_predicate>(
                            __first,
                            &__first[(v6 - __first) / 2],
                            v6 - 1,
                            (vostok::render::shader_macros_dort_predicate)__comp);
      v8 = stlp_std::priv::__unguarded_partition<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
             __first,
             v6,
             *v7,
             (vostok::render::shader_macros_dort_predicate)__comp);
      stlp_std::priv::__introsort_loop<char const * *,char const *,int,vostok::render::shader_macros_dort_predicate>(
        v8,
        v6,
        0,
        __depth_limit,
        (vostok::render::shader_macros_dort_predicate)__comp);
      v6 = v8;
      if ( (int)(((char *)v8 - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    stlp_std::priv::__partial_sort<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
      __first,
      v6,
      v6,
      __comp,
      a1);
  }
}


void __usercall stlp_std::priv::__introsort_loop<char const * *,char const *,int,vostok::tips_sorting_predicate>(
        vostok::tips_sorting_predicate a1@<esi>,
        const char **__first,
        const char **__last,
        const char **__formal,
        int __depth_limit,
        vostok::tips_sorting_predicate __comp)
{
  const char **v6; // edi
  const char **v8; // eax
  const char **v9; // esi

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( __depth_limit )
    {
      --__depth_limit;
      v8 = (const char **)stlp_std::priv::__median<char const *,vostok::tips_sorting_predicate>(
                            __first,
                            &__first[(v6 - __first) / 2],
                            v6 - 1,
                            __comp);
      v9 = stlp_std::priv::__unguarded_partition<char const * *,char const *,vostok::tips_sorting_predicate>(
             __first,
             v6,
             *v8,
             __comp);
      stlp_std::priv::__introsort_loop<char const * *,char const *,int,vostok::tips_sorting_predicate>(
        v9,
        v6,
        0,
        __depth_limit,
        __comp);
      v6 = v9;
      if ( (int)(((char *)v9 - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    stlp_std::priv::__partial_sort<char const * *,char const *,vostok::tips_sorting_predicate>(
      __first,
      v6,
      v6,
      (const char **)__comp.editor_str,
      a1);
  }
}


void __usercall stlp_std::priv::__introsort_loop<void const * *,void const *,int,stlp_std::less<void const *>>(
        stlp_std::less<void const *> a1@<sil>,
        const void **__first,
        const void **__last,
        const void **__formal,
        int __depth_limit,
        const void **__comp)
{
  const void **v6; // ebx
  const void *v8; // ecx
  int v9; // kr00_4
  const void *v10; // edx
  const void **v11; // eax
  unsigned int v12; // ebp
  unsigned int *v13; // esi
  int __depth_limita; // [esp+18h] [ebp+10h]

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    do
    {
      if ( !__depth_limit )
      {
        stlp_std::priv::__partial_sort<void const * *,void const *,stlp_std::less<void const *>>(
          __first,
          v6,
          v6,
          __comp,
          a1);
        return;
      }
      v8 = *__first;
      v9 = v6 - __first;
      v10 = __first[v9 / 2];
      v11 = &__first[v9 / 2];
      __depth_limita = __depth_limit - 1;
      v12 = (unsigned int)*(v6 - 1);
      if ( *__first >= v10 )
      {
        if ( (unsigned int)v8 < v12 )
          goto LABEL_8;
        if ( (unsigned int)v10 < v12 )
LABEL_10:
          v11 = v6 - 1;
      }
      else if ( (unsigned int)v10 >= v12 )
      {
        if ( (unsigned int)v8 < v12 )
          goto LABEL_10;
LABEL_8:
        v11 = __first;
      }
      __depth_limit = __depth_limita;
      v13 = stlp_std::priv::__unguarded_partition<void const * *,void const *,stlp_std::less<void const *>>(
              (unsigned int *)v6,
              (unsigned int)*v11,
              (unsigned int *)__first);
      stlp_std::priv::__introsort_loop<void const * *,void const *,int,stlp_std::less<void const *>>(
        (const void **)v13,
        v6,
        0,
        __depth_limita,
        (stlp_std::less<void const *>)__comp);
      v6 = (const void **)v13;
    }
    while ( (int)(((char *)v13 - (char *)__first) & 0xFFFFFFFC) > 64 );
  }
}


void __cdecl stlp_std::priv::__introsort_loop<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,int,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result *__first,
        vostok::physics::closest_ray_result *__last,
        vostok::physics::closest_ray_result *__formal,
        int __depth_limit,
        vostok::physics::distance_predicate __comp)
{
  vostok::physics::closest_ray_result *v5; // edi
  vostok::physics::closest_ray_result *v7; // eax
  vostok::physics::closest_ray_result *v8; // esi
  __int128 v9; // [esp-Ch] [ebp-1Ch]

  v5 = __last;
  if ( __last - __first > 16 )
  {
    while ( 1 )
    {
      *(_QWORD *)&v9 = *(_QWORD *)&__comp.m_from.x;
      if ( !__depth_limit )
        break;
      DWORD2(v9) = LODWORD(__comp.m_from.z);
      --__depth_limit;
      v7 = (vostok::physics::closest_ray_result *)stlp_std::priv::__median<vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
                                                    __first,
                                                    &__first[(v5 - __first) / 2],
                                                    v5 - 1,
                                                    (vostok::physics::distance_predicate)v9);
      v8 = stlp_std::priv::__unguarded_partition<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
             __first,
             v5,
             *v7,
             __comp);
      stlp_std::priv::__introsort_loop<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,int,vostok::physics::distance_predicate>(
        v8,
        v5,
        0,
        __depth_limit,
        __comp);
      v5 = v8;
      if ( v8 - __first <= 16 )
        return;
    }
    DWORD2(v9) = LODWORD(__comp.m_from.z);
    stlp_std::priv::__partial_sort<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
      __first,
      v5,
      v5,
      (vostok::physics::closest_ray_result *)LODWORD(__comp.m_from.x),
      *(vostok::physics::distance_predicate *)((char *)&v9 + 4));
  }
}


void __cdecl stlp_std::priv::__introsort_loop<vostok::sound::propagator_info *,vostok::sound::propagator_info,int,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        vostok::sound::propagator_info *__first,
        vostok::sound::propagator_info *__last,
        vostok::sound::propagator_info *__formal,
        int __depth_limit,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  vostok::sound::propagator_info v5; // [esp-18h] [ebp-30h]
  vostok::sound::propagator_info *__cut; // [esp+14h] [ebp-4h]

  while ( __last - __first > 16 )
  {
    if ( !__depth_limit )
    {
      stlp_std::partial_sort<vostok::sound::propagator_info *,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        __first,
        __last,
        __last,
        __comp);
      return;
    }
    --__depth_limit;
    v5 = *stlp_std::priv::__median<vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
            __first,
            &__first[(__last - __first) / 2],
            __last - 1,
            __comp);
    __cut = stlp_std::priv::__unguarded_partition<vostok::sound::propagator_info *,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
              __first,
              __last,
              v5,
              __comp);
    stlp_std::priv::__introsort_loop<vostok::sound::propagator_info *,vostok::sound::propagator_info,int,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
      __cut,
      __last,
      0,
      __depth_limit,
      __comp);
    __last = __cut;
  }
}


void __cdecl stlp_std::priv::__introsort_loop<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,int,vostok::render::sort_indices_predicate>(
        vostok::render::grass_patch::sort_info *__first,
        vostok::render::grass_patch::sort_info *__last,
        vostok::render::grass_patch::sort_info *__formal,
        int __depth_limit,
        vostok::render::sort_indices_predicate __comp)
{
  vostok::render::grass_patch::sort_info *v5; // edi
  vostok::render::grass_patch::sort_info *v7; // eax
  vostok::render::grass_patch::sort_info *v8; // esi
  _BYTE v9[20]; // [esp-10h] [ebp-20h]

  v5 = __last;
  if ( __last - __first > 16 )
  {
    while ( 1 )
    {
      *(vostok::render::sort_indices_predicate *)v9 = __comp;
      if ( !__depth_limit )
        break;
      --__depth_limit;
      v7 = (vostok::render::grass_patch::sort_info *)stlp_std::priv::__median<vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
                                                       __first,
                                                       &__first[(v5 - __first) / 2],
                                                       v5 - 1,
                                                       __comp);
      v8 = stlp_std::priv::__unguarded_partition<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
             __first,
             v5,
             *v7,
             __comp);
      stlp_std::priv::__introsort_loop<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,int,vostok::render::sort_indices_predicate>(
        v8,
        v5,
        0,
        __depth_limit,
        __comp);
      v5 = v8;
      if ( v8 - __first <= 16 )
        return;
    }
    stlp_std::priv::__partial_sort<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
      __first,
      v5,
      v5,
      (vostok::render::grass_patch::sort_info *)__comp.m_patch,
      *(vostok::render::sort_indices_predicate *)&v9[4]);
  }
}


void __cdecl stlp_std::priv::__introsort_loop<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,int,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__first,
        vostok::math::curve_point<float> *__last,
        vostok::math::curve_point<float> *__formal,
        int __depth_limit,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  vostok::math::curve_point<float> *v5; // ebx
  const vostok::math::curve_point<float> *v6; // esi
  bool v7; // zf
  vostok::math::curve_point<float> *v8; // ecx
  bool v9; // al
  vostok::math::curve_point<float> *v10; // esi
  const vostok::math::curve_point<float> *v11; // [esp-4h] [ebp-14h]

  v5 = __last;
  if ( __last - __first > 16 )
  {
    do
    {
      if ( !__depth_limit )
      {
        stlp_std::priv::__partial_sort<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
          __first,
          v5,
          v5,
          0,
          __comp);
        return;
      }
      --__depth_limit;
      v6 = &__first[(v5 - __first) / 2];
      v7 = !__comp(__first, v6);
      v11 = v5 - 1;
      if ( v7 )
      {
        if ( __comp(__first, v11) )
        {
          v8 = __first;
        }
        else
        {
          v9 = __comp(v6, v5 - 1);
          v8 = v5 - 1;
          if ( !v9 )
            goto LABEL_10;
        }
      }
      else
      {
        if ( __comp(v6, v11) || (v6 = v5 - 1, __comp(__first, v5 - 1)) )
        {
LABEL_10:
          v8 = (vostok::math::curve_point<float> *)v6;
          goto LABEL_11;
        }
        v8 = __first;
      }
LABEL_11:
      v10 = stlp_std::priv::__unguarded_partition<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
              __first,
              v5,
              *v8,
              __comp);
      stlp_std::priv::__introsort_loop<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,int,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        v10,
        v5,
        0,
        __depth_limit,
        __comp);
      v5 = v10;
    }
    while ( v10 - __first > 16 );
  }
}


void __cdecl stlp_std::priv::__introsort_loop<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,int,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        vostok::particle::curve_point<float> *__first,
        vostok::particle::curve_point<float> *__last,
        vostok::particle::curve_point<float> *__formal,
        int __depth_limit,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<float> *, const vostok::particle::curve_point<float> *))
{
  const vostok::sound::propagator_info *v5; // eax
  vostok::particle::curve_point<float> v6; // [esp-1Ch] [ebp-38h]
  vostok::particle::curve_point<float> *__cut; // [esp+18h] [ebp-4h]

  while ( __last - __first > 16 )
  {
    if ( !__depth_limit )
    {
      stlp_std::partial_sort<vostok::particle::curve_point<float> *,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        __first,
        __last,
        __last,
        __comp);
      return;
    }
    --__depth_limit;
    v5 = stlp_std::priv::__median<vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
           (const vostok::sound::propagator_info *)__first,
           (const vostok::sound::propagator_info *)&__first[(__last - __first) / 2],
           (const vostok::sound::propagator_info *)&__last[-1],
           (bool (__cdecl *)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))__comp);
    *(_QWORD *)&v6.upper_value = *(_QWORD *)&v5->in_graph_position.x;
    *(_QWORD *)&v6.tangent_in = *(_QWORD *)&v5->in_graph_position.elements[2];
    *(_QWORD *)&v6.time = *(_QWORD *)&v5->prop;
    __cut = stlp_std::priv::__unguarded_partition<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
              __first,
              __last,
              v6,
              __comp);
    stlp_std::priv::__introsort_loop<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,int,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
      __cut,
      __last,
      0,
      __depth_limit,
      __comp);
    __last = __cut;
  }
}


void __cdecl stlp_std::priv::__introsort_loop<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,int,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        stlp_std::pair<vostok::ai::npc const *,float> *__first,
        stlp_std::pair<vostok::ai::npc const *,float> *__last,
        stlp_std::pair<vostok::ai::npc const *,float> *__formal,
        int __depth_limit,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::npc const *,float> *, const stlp_std::pair<vostok::ai::npc const *,float> *))
{
  stlp_std::pair<vostok::ai::npc const *,float> v5; // [esp-Ch] [ebp-20h] BYREF
  bool (__cdecl *v6)(const stlp_std::pair<vostok::ai::npc const *,float> *, const stlp_std::pair<vostok::ai::npc const *,float> *); // [esp-4h] [ebp-18h]
  stlp_std::pair<vostok::ai::npc const *,float> *v7; // [esp+0h] [ebp-14h]
  const vostok::sound::propagator_info *v8; // [esp+4h] [ebp-10h]
  stlp_std::pair<vostok::ai::npc const *,float> *v9; // [esp+8h] [ebp-Ch]
  stlp_std::pair<vostok::ai::npc const *,float> *__cut; // [esp+10h] [ebp-4h]

  while ( __last - __first > 16 )
  {
    if ( !__depth_limit )
    {
      stlp_std::partial_sort<stlp_std::pair<vostok::ai::npc const *,float> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        __first,
        __last,
        __last,
        __comp);
      return;
    }
    --__depth_limit;
    v6 = __comp;
    v8 = stlp_std::priv::__median<vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
           (const vostok::sound::propagator_info *)__first,
           (const vostok::sound::propagator_info *)&__first[(__last - __first) / 2],
           (const vostok::sound::propagator_info *)&__last[-1],
           (bool (__cdecl *)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))__comp);
    v9 = &v5;
    v5.first = (const vostok::ai::npc *)LODWORD(v8->in_graph_position.x);
    v5.second = v8->in_graph_position.y;
    v7 = stlp_std::priv::__unguarded_partition<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
           __first,
           __last,
           v5,
           v6);
    __cut = v7;
    stlp_std::priv::__introsort_loop<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,int,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
      v7,
      __last,
      0,
      __depth_limit,
      __comp);
    __last = __cut;
  }
}


void __cdecl stlp_std::priv::__introsort_loop<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,int,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__first,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__last,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__formal,
        int __depth_limit,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))
{
  int v5; // [esp-Ch] [ebp-20h] BYREF
  bool (__cdecl *v6)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *); // [esp-4h] [ebp-18h]
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *v7; // [esp+0h] [ebp-14h]
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *v8; // [esp+4h] [ebp-10h]
  int *v9; // [esp+8h] [ebp-Ch]
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__cut; // [esp+10h] [ebp-4h]

  while ( __last - __first > 16 )
  {
    if ( !__depth_limit )
    {
      stlp_std::partial_sort<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        __first,
        __last,
        __last,
        __comp);
      return;
    }
    --__depth_limit;
    v6 = __comp;
    v8 = (stlp_std::pair<vostok::ai::weapon const *,unsigned int> *)stlp_std::priv::__median<vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
                                                                      (const vostok::sound::propagator_info *)__first,
                                                                      (const vostok::sound::propagator_info *)&__first[(__last - __first) / 2],
                                                                      (const vostok::sound::propagator_info *)&__last[-1],
                                                                      (bool (__cdecl *)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))__comp);
    v9 = &v5;
    v7 = stlp_std::priv::__unguarded_partition<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
           __first,
           __last,
           *v8,
           v6);
    __cut = v7;
    stlp_std::priv::__introsort_loop<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,int,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
      v7,
      __last,
      0,
      __depth_limit,
      __comp);
    __last = __cut;
  }
}


void __cdecl stlp_std::priv::__introsort_loop<vostok::render::custom_config_value *,vostok::render::custom_config_value,int,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        vostok::render::custom_config_value *__first,
        vostok::render::custom_config_value *__last,
        vostok::render::custom_config_value *__formal,
        int __depth_limit,
        bool (__cdecl *__comp)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *))
{
  vostok::render::custom_config_value *v5; // ebx
  const vostok::render::custom_config_value *v6; // esi
  bool v7; // zf
  vostok::render::custom_config_value *v8; // ecx
  bool v9; // al
  vostok::render::custom_config_value *v10; // esi
  const vostok::render::custom_config_value *v11; // [esp-4h] [ebp-14h]
  bool (__cdecl *v12)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *); // [esp+0h] [ebp-10h]

  v5 = __last;
  if ( __last - __first > 16 )
  {
    do
    {
      if ( !__depth_limit )
      {
        stlp_std::priv::__partial_sort<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
          __first,
          v5,
          v5,
          (vostok::render::custom_config_value *)__comp,
          v12);
        return;
      }
      --__depth_limit;
      v6 = &__first[(v5 - __first) / 2];
      v7 = !__comp(__first, v6);
      v11 = v5 - 1;
      if ( v7 )
      {
        if ( __comp(__first, v11) )
        {
          v8 = __first;
        }
        else
        {
          v9 = __comp(v6, v5 - 1);
          v8 = v5 - 1;
          if ( !v9 )
            goto LABEL_10;
        }
      }
      else
      {
        if ( __comp(v6, v11) || (v6 = v5 - 1, __comp(__first, v5 - 1)) )
        {
LABEL_10:
          v8 = v6;
          goto LABEL_11;
        }
        v8 = __first;
      }
LABEL_11:
      v10 = stlp_std::priv::__unguarded_partition<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
              __first,
              v5,
              *v8,
              __comp);
      stlp_std::priv::__introsort_loop<vostok::render::custom_config_value *,vostok::render::custom_config_value,int,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        v10,
        v5,
        0,
        __depth_limit,
        __comp);
      v5 = v10;
    }
    while ( v10 - __first > 16 );
  }
}


void __cdecl stlp_std::priv::__introsort_loop<vostok::render::shader_constant *,vostok::render::shader_constant,int,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        vostok::render::shader_constant *__first,
        vostok::render::shader_constant *__last,
        vostok::render::shader_constant *__formal,
        int __depth_limit,
        bool (__cdecl *__comp)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))
{
  vostok::render::shader_constant *v5; // ebx
  const vostok::render::shader_constant *v6; // esi
  bool v7; // zf
  vostok::render::shader_constant *v8; // ecx
  bool v9; // al
  vostok::render::shader_constant *v10; // esi
  vostok::render::shader_constant v11; // [esp-1Ch] [ebp-2Ch]
  const vostok::render::shader_constant *v12; // [esp-4h] [ebp-14h]
  bool (__cdecl *v13)(const vostok::render::shader_constant *, const vostok::render::shader_constant *); // [esp-4h] [ebp-14h]
  bool (__cdecl *v14)(const vostok::render::shader_constant *, const vostok::render::shader_constant *); // [esp+0h] [ebp-10h]

  v5 = __last;
  if ( __last - __first > 16 )
  {
    do
    {
      if ( !__depth_limit )
      {
        stlp_std::priv::__partial_sort<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
          __first,
          v5,
          v5,
          (vostok::render::shader_constant *)__comp,
          v14);
        return;
      }
      --__depth_limit;
      v6 = &__first[(v5 - __first) / 2];
      v7 = !__comp(__first, v6);
      v12 = v5 - 1;
      if ( v7 )
      {
        if ( __comp(__first, v12) )
        {
          v8 = __first;
        }
        else
        {
          v9 = __comp(v6, v5 - 1);
          v8 = v5 - 1;
          if ( !v9 )
            goto LABEL_10;
        }
      }
      else
      {
        if ( __comp(v6, v12) || (v6 = v5 - 1, __comp(__first, v5 - 1)) )
        {
LABEL_10:
          v8 = (vostok::render::shader_constant *)v6;
          goto LABEL_11;
        }
        v8 = __first;
      }
LABEL_11:
      *(unsigned __int64 *)((char *)&v11.m_slot.m_value + 4) = v8->m_slot.m_value;
      v11.m_source.m_size = (const unsigned int)v8->m_source.m_pointer;
      *(_QWORD *)&v11.m_host = *(_QWORD *)&v8->m_source.m_size;
      *(_DWORD *)&v11.m_slot.m_class_id = __comp;
      v10 = stlp_std::priv::__unguarded_partition<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
              __first,
              v5,
              v11,
              v13);
      stlp_std::priv::__introsort_loop<vostok::render::shader_constant *,vostok::render::shader_constant,int,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        v10,
        v5,
        0,
        __depth_limit,
        __comp);
      v5 = v10;
    }
    while ( v10 - __first > 16 );
  }
}
