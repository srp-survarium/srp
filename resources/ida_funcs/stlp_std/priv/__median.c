vostok::animation::mixing::animation_state *const *__cdecl stlp_std::priv::__median<vostok::animation::mixing::animation_state *,event_iterator_predicate>(
        vostok::animation::mixing::animation_state *const *__a,
        vostok::animation::mixing::animation_state *const *__b,
        vostok::animation::mixing::animation_state *const *__c)
{
  vostok::animation::mixing::animation_state *const *v3; // ebp
  bool is_less; // al
  vostok::animation::mixing::n_ary_tree_event_iterator *p_event_iterator; // esi
  bool v6; // zf
  vostok::animation::mixing::animation_state *const *result; // eax

  v3 = __b;
  is_less = vostok::animation::mixing::n_ary_tree_event_iterator::is_less(
              &(*__a)->event_iterator,
              &(*__b)->event_iterator);
  p_event_iterator = &(*__c)->event_iterator;
  if ( !is_less )
  {
    if ( vostok::animation::mixing::n_ary_tree_event_iterator::is_less(&(*__a)->event_iterator, p_event_iterator) )
      return __a;
LABEL_4:
    v6 = !vostok::animation::mixing::n_ary_tree_event_iterator::is_less(&(*v3)->event_iterator, &(*__c)->event_iterator);
    result = __c;
    if ( !v6 )
      return result;
    return v3;
  }
  if ( !vostok::animation::mixing::n_ary_tree_event_iterator::is_less(&(*__b)->event_iterator, p_event_iterator) )
  {
    v3 = __a;
    goto LABEL_4;
  }
  return v3;
}


const vostok::ai::sound_item **__cdecl stlp_std::priv::__median<survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
        const vostok::ai::sound_item **__a,
        const vostok::ai::sound_item **__b,
        const vostok::ai::sound_item **__c,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  if ( __comp(*__a, *__b) )
  {
    if ( __comp(*__b, *__c) )
    {
      return __b;
    }
    else if ( __comp(*__a, *__c) )
    {
      return __c;
    }
    else
    {
      return __a;
    }
  }
  else if ( __comp(*__a, *__c) )
  {
    return __a;
  }
  else if ( __comp(*__b, *__c) )
  {
    return __c;
  }
  else
  {
    return __b;
  }
}


const vostok::render::grass_patch **__usercall stlp_std::priv::__median<vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>@<eax>(
        const vostok::render::grass_patch **__b@<edi>,
        vostok::render::grass_patch **__c@<esi>,
        const vostok::render::grass_patch **__a,
        vostok::render::sort_grass_patch_predicate __comp)
{
  const vostok::render::grass_patch *v4; // edx
  vostok::render::grass_patch *v5; // eax
  const vostok::render::grass_patch *v6; // ecx
  float v7; // xmm6_4
  const vostok::render::grass_patch **result; // eax
  bool v9; // zf

  v4 = *__b;
  v5 = *__c;
  v6 = *__a;
  v7 = (*__c)->m_origin.x - __comp.m_view_pos.x;
  if ( (float)((float)((float)((float)((*__b)->m_origin.z - __comp.m_view_pos.z)
                             * (float)((*__b)->m_origin.z - __comp.m_view_pos.z))
                     + (float)((float)((*__b)->m_origin.y - __comp.m_view_pos.y)
                             * (float)((*__b)->m_origin.y - __comp.m_view_pos.y)))
             + (float)((float)((*__b)->m_origin.x - __comp.m_view_pos.x)
                     * (float)((*__b)->m_origin.x - __comp.m_view_pos.x))) > (float)((float)((float)((float)((*__a)->m_origin.z - __comp.m_view_pos.z) * (float)((*__a)->m_origin.z - __comp.m_view_pos.z))
                                                                                           + (float)((float)((*__a)->m_origin.y - __comp.m_view_pos.y) * (float)((*__a)->m_origin.y - __comp.m_view_pos.y)))
                                                                                   + (float)((float)((*__a)->m_origin.x - __comp.m_view_pos.x)
                                                                                           * (float)((*__a)->m_origin.x - __comp.m_view_pos.x))) )
  {
    if ( (float)((float)((float)((float)(v5->m_origin.z - __comp.m_view_pos.z)
                               * (float)(v5->m_origin.z - __comp.m_view_pos.z))
                       + (float)((float)(v5->m_origin.y - __comp.m_view_pos.y)
                               * (float)(v5->m_origin.y - __comp.m_view_pos.y)))
               + (float)(v7 * v7)) <= (float)((float)((float)((float)(v4->m_origin.z - __comp.m_view_pos.z)
                                                            * (float)(v4->m_origin.z - __comp.m_view_pos.z))
                                                    + (float)((float)(v4->m_origin.y - __comp.m_view_pos.y)
                                                            * (float)(v4->m_origin.y - __comp.m_view_pos.y)))
                                            + (float)((float)(v4->m_origin.x - __comp.m_view_pos.x)
                                                    * (float)(v4->m_origin.x - __comp.m_view_pos.x))) )
    {
      if ( vostok::render::sort_grass_patch_predicate::operator()(v6, v5, &__comp) )
        return (const vostok::render::grass_patch **)__c;
      return __a;
    }
    return __b;
  }
  if ( (float)((float)((float)((float)(v5->m_origin.z - __comp.m_view_pos.z)
                             * (float)(v5->m_origin.z - __comp.m_view_pos.z))
                     + (float)((float)(v5->m_origin.y - __comp.m_view_pos.y)
                             * (float)(v5->m_origin.y - __comp.m_view_pos.y)))
             + (float)(v7 * v7)) > (float)((float)((float)((float)(v6->m_origin.z - __comp.m_view_pos.z)
                                                         * (float)(v6->m_origin.z - __comp.m_view_pos.z))
                                                 + (float)((float)(v6->m_origin.y - __comp.m_view_pos.y)
                                                         * (float)(v6->m_origin.y - __comp.m_view_pos.y)))
                                         + (float)((float)(v6->m_origin.x - __comp.m_view_pos.x)
                                                 * (float)(v6->m_origin.x - __comp.m_view_pos.x))) )
    return __a;
  v9 = !vostok::render::sort_grass_patch_predicate::operator()(v4, v5, &__comp);
  result = (const vostok::render::grass_patch **)__c;
  if ( v9 )
    return __b;
  return result;
}


vostok::animation::mixing::n_ary_tree_base_node *const *__usercall stlp_std::priv::__median<vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>@<eax>(
        vostok::animation::mixing::n_ary_tree_base_node *const *__b@<edi>,
        vostok::animation::mixing::n_ary_tree_base_node **__c@<esi>,
        vostok::animation::mixing::n_ary_tree_base_node *const *__a)
{
  int v3; // ecx
  void (__thiscall *v4)(int, void ***, int); // eax
  bool v5; // zf
  int v6; // ecx
  void (__thiscall *v7)(int, void ***, vostok::animation::mixing::n_ary_tree_base_node *); // eax
  vostok::animation::mixing::n_ary_tree_base_node *const *result; // eax
  int v9; // ecx
  void (__thiscall *v10)(int, void ***, vostok::animation::mixing::n_ary_tree_base_node *); // eax
  int v11; // [esp+8h] [ebp-18h]
  vostok::animation::mixing::n_ary_tree_base_node *v12; // [esp+8h] [ebp-18h]
  vostok::animation::mixing::n_ary_tree_base_node *v13; // [esp+8h] [ebp-18h]
  vostok::animation::mixing::n_ary_tree_base_node *v14; // [esp+10h] [ebp-10h]
  void **v15; // [esp+14h] [ebp-Ch] BYREF
  int v16; // [esp+18h] [ebp-8h]
  void **v17; // [esp+1Ch] [ebp-4h] BYREF
  void *retaddr; // [esp+20h] [ebp+0h]

  v3 = (int)*__a;
  v4 = *(void (__thiscall **)(int, void ***, int))(**(_DWORD **)__a + 4);
  v11 = (int)*__b;
  v15 = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  v16 = 0;
  v4(v3, &v15, v11);
  v14 = *__c;
  v5 = retaddr == (void *)1;
  v17 = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  retaddr = 0;
  if ( v5 )
  {
    (*(void (__thiscall **)(_DWORD, void ***, vostok::animation::mixing::n_ary_tree_base_node *))(**(_DWORD **)__b + 4))(
      *__b,
      &v17,
      v14);
    if ( v16 != 1 )
    {
      v6 = (int)*__a;
      v7 = *(void (__thiscall **)(int, void ***, vostok::animation::mixing::n_ary_tree_base_node *))(**(_DWORD **)__a + 4);
      v12 = *__c;
      v15 = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
      v16 = 0;
      v7(v6, &v15, v12);
      if ( v16 == 1 )
        return __c;
      return __a;
    }
    return __b;
  }
  (*(void (__thiscall **)(_DWORD, void ***, vostok::animation::mixing::n_ary_tree_base_node *))(**(_DWORD **)__a + 4))(
    *__a,
    &v17,
    v14);
  if ( v16 == 1 )
    return __a;
  v9 = (int)*__b;
  v10 = *(void (__thiscall **)(int, void ***, vostok::animation::mixing::n_ary_tree_base_node *))(**(_DWORD **)__b + 4);
  v13 = *__c;
  v15 = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  v16 = 0;
  v10(v9, &v15, v13);
  result = __c;
  if ( v16 != 1 )
    return __b;
  return result;
}


const vostok::render::render_surface_instance **__cdecl stlp_std::priv::__median<vostok::render::render_surface_instance *,vostok::render::sort_by_distance_predicate>(
        const vostok::render::render_surface_instance **__a,
        const vostok::render::render_surface_instance **__b,
        const vostok::render::render_surface_instance **__c,
        vostok::render::sort_by_distance_predicate __comp)
{
  const vostok::render::render_surface_instance *v4; // ebx
  const vostok::render::render_surface_instance *v5; // edi
  const vostok::render::render_surface_instance *v6; // ebp
  const vostok::render::render_surface_instance **result; // eax
  const vostok::render::render_surface_instance *v8; // ebp
  bool v9; // zf

  v4 = *__a;
  v5 = *__b;
  if ( vostok::render::sort_by_distance_predicate::operator()(&__comp, *__a, *__b) )
  {
    v6 = *__c;
    if ( !vostok::render::sort_by_distance_predicate::operator()(&__comp, v5, *__c) )
    {
      if ( vostok::render::sort_by_distance_predicate::operator()(&__comp, v4, v6) )
        return __c;
      return __a;
    }
    return __b;
  }
  v8 = *__c;
  if ( vostok::render::sort_by_distance_predicate::operator()(&__comp, v4, *__c) )
    return __a;
  v9 = !vostok::render::sort_by_distance_predicate::operator()(&__comp, v5, v8);
  result = __c;
  if ( v9 )
    return __b;
  return result;
}


const vostok::render::render_surface_instance **__cdecl stlp_std::priv::__median<vostok::render::render_surface_instance *,vostok::render::sort_by_texture_predicate>(
        const vostok::render::render_surface_instance **__a,
        const vostok::render::render_surface_instance **__b,
        const vostok::render::render_surface_instance **__c,
        vostok::render::sort_by_texture_predicate __comp)
{
  const vostok::render::render_surface_instance *v4; // esi
  const vostok::render::render_surface_instance *v5; // edi
  bool v6; // al
  const vostok::render::render_surface_instance *v7; // ebx
  const vostok::render::render_surface_instance **result; // eax
  bool v9; // zf
  const vostok::render::render_surface_instance *v10; // [esp-4h] [ebp-14h]

  v4 = *__b;
  v5 = *__a;
  v6 = vostok::render::sort_by_texture_predicate::operator()(&__comp, *__a, *__b);
  v7 = *__c;
  v10 = *__c;
  if ( v6 )
  {
    if ( !vostok::render::sort_by_texture_predicate::operator()(&__comp, v4, v10) )
    {
      if ( vostok::render::sort_by_texture_predicate::operator()(&__comp, v5, v7) )
        return __c;
      return __a;
    }
    return __b;
  }
  if ( vostok::render::sort_by_texture_predicate::operator()(&__comp, v5, v10) )
    return __a;
  v9 = !vostok::render::sort_by_texture_predicate::operator()(&__comp, v4, v7);
  result = __c;
  if ( v9 )
    return __b;
  return result;
}


const vostok::render::render_surface_instance **__cdecl stlp_std::priv::__median<vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
        const vostok::render::render_surface_instance **__a,
        const vostok::render::render_surface_instance **__b,
        const vostok::render::render_surface_instance **__c,
        vostok::render::sort_by_ps_predicate __comp)
{
  const vostok::render::render_surface_instance *v4; // ebx
  const vostok::render::render_surface_instance *v5; // esi
  const vostok::render::render_surface_instance *v6; // ebp
  const vostok::render::render_surface_instance **result; // eax
  const vostok::render::render_surface_instance *v8; // ebp
  bool v9; // zf

  v4 = *__a;
  v5 = *__b;
  if ( vostok::render::sort_by_vs_predicate::operator()(&__comp, *__a, *__b) )
  {
    v6 = *__c;
    if ( !vostok::render::sort_by_vs_predicate::operator()(&__comp, v5, *__c) )
    {
      if ( vostok::render::sort_by_vs_predicate::operator()(&__comp, v4, v6) )
        return __c;
      return __a;
    }
    return __b;
  }
  v8 = *__c;
  if ( vostok::render::sort_by_vs_predicate::operator()(&__comp, v4, *__c) )
    return __a;
  v9 = !vostok::render::sort_by_vs_predicate::operator()(&__comp, v5, v8);
  result = __c;
  if ( v9 )
    return __b;
  return result;
}


const vostok::command_line::key *const *__cdecl stlp_std::priv::__median<vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        const vostok::command_line::key *const *__a,
        const vostok::command_line::key *const *__b,
        const vostok::command_line::key *const *__c)
{
  const vostok::command_line::key *v3; // ebx
  const vostok::command_line::key *v4; // ebp
  const vostok::command_line::key *v5; // esi
  const vostok::command_line::key *v6; // edi
  const vostok::command_line::key *const *result; // eax
  const vostok::command_line::key *v8; // edi
  bool v9; // zf
  vostok::command_line::key_compare_predicate *v10; // [esp+0h] [ebp-10h]
  vostok::command_line::key_compare_predicate *v11; // [esp+0h] [ebp-10h]
  vostok::command_line::key_compare_predicate *v12; // [esp+0h] [ebp-10h]
  vostok::command_line::key_compare_predicate *v13; // [esp+0h] [ebp-10h]

  v3 = *__b;
  v4 = *__a;
  v5 = *__a;
  if ( vostok::command_line::key_compare_predicate::operator()(*__a, *__b, v10) )
  {
    v6 = *__c;
    if ( !vostok::command_line::key_compare_predicate::operator()(v3, *__c, v11) )
    {
      if ( vostok::command_line::key_compare_predicate::operator()(v4, v6, v12) )
        return __c;
      return __a;
    }
    return __b;
  }
  v8 = *__c;
  if ( vostok::command_line::key_compare_predicate::operator()(v5, *__c, v11) )
    return __a;
  v9 = !vostok::command_line::key_compare_predicate::operator()(v3, v8, v13);
  result = __c;
  if ( v9 )
    return __b;
  return result;
}


vostok::resources::resource_base *const *__usercall stlp_std::priv::__median<vostok::resources::resource_base *,vostok::resources::sorting_predicate>@<eax>(
        vostok::resources::resource_base *const *__b@<eax>,
        vostok::resources::resource_base *const *__c@<edi>,
        vostok::resources::resource_base *const *__a)
{
  int v3; // ecx
  float m_current_satisfaction; // xmm2_4
  int v5; // edx
  int v6; // esi
  float v7; // xmm2_4
  float v8; // xmm2_4
  int v9; // esi
  float v10; // xmm2_4
  float v11; // xmm2_4

  v3 = (int)*__b;
  m_current_satisfaction = (*__b)->m_current_satisfaction;
  v5 = (int)*__a;
  if ( fabs((*__a)->m_current_satisfaction - m_current_satisfaction) < 0.050000001 )
  {
    if ( *(_DWORD *)(v5 + 24) < *(_DWORD *)(v3 + 24) )
      goto LABEL_3;
LABEL_9:
    v9 = (int)*__c;
    v10 = (*__c)->m_current_satisfaction;
    if ( fabs(*(float *)(v5 + 112) - v10) >= 0.050000001 )
    {
      if ( *(float *)(v5 + 112) > v10 )
        return __a;
    }
    else if ( *(_DWORD *)(v5 + 24) < *(_DWORD *)(v9 + 24) )
    {
      return __a;
    }
    v11 = *(float *)(v9 + 112);
    if ( fabs(*(float *)(v3 + 112) - v11) >= 0.050000001 )
    {
      if ( *(float *)(v3 + 112) <= v11 )
        return __b;
    }
    else if ( *(_DWORD *)(v3 + 24) >= *(_DWORD *)(v9 + 24) )
    {
      return __b;
    }
    return __c;
  }
  if ( (*__a)->m_current_satisfaction <= m_current_satisfaction )
    goto LABEL_9;
LABEL_3:
  v6 = (int)*__c;
  v7 = (*__c)->m_current_satisfaction;
  if ( fabs(*(float *)(v3 + 112) - v7) < 0.050000001 )
  {
    if ( *(_DWORD *)(v3 + 24) < *(_DWORD *)(v6 + 24) )
      return __b;
    goto LABEL_5;
  }
  if ( *(float *)(v3 + 112) <= v7 )
  {
LABEL_5:
    v8 = *(float *)(v6 + 112);
    if ( fabs(*(float *)(v5 + 112) - v8) >= 0.050000001 )
    {
      if ( *(float *)(v5 + 112) <= v8 )
        return __a;
    }
    else if ( *(_DWORD *)(v5 + 24) >= *(_DWORD *)(v6 + 24) )
    {
      return __a;
    }
    return __c;
  }
  return __b;
}


stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > **__cdecl stlp_std::priv::__median<vostok::network_core::udp_match_packet *,packets_predicate>(
        vostok::network_core::udp_match_packet *const *__a,
        stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > **__b,
        stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > **__c)
{
  survarium::base_project::resolve_link_object *v3; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v4; // ecx
  survarium::base_project::resolve_link_object *v5; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v6; // ecx
  survarium::base_project::resolve_link_object *v8; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v9; // ecx
  survarium::base_project::resolve_link_object *v10; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v11; // ecx
  survarium::base_project::resolve_link_object *v12; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v13; // ecx
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v14; // [esp+8h] [ebp-24h]
  int v15; // [esp+10h] [ebp-1Ch]
  int v16; // [esp+18h] [ebp-14h]
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v17; // [esp+20h] [ebp-Ch]
  int v18; // [esp+28h] [ebp-4h]

  v18 = (int)*__a;
  v3 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
         *__b,
         (int)*__b);
  if ( stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
         v4,
         v18) >= v3 )
  {
    v15 = (int)*__a;
    v10 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
            *__c,
            (int)*__c);
    if ( stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           v11,
           v15) >= v10 )
    {
      v14 = *__b;
      v12 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
              *__c,
              (int)*__c);
      if ( stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
             v13,
             (int)v14) >= v12 )
        return __b;
      else
        return __c;
    }
    else
    {
      return (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > **)__a;
    }
  }
  else
  {
    v17 = *__b;
    v5 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           *__c,
           (int)*__c);
    if ( stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           v6,
           (int)v17) >= v5 )
    {
      v16 = (int)*__a;
      v8 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
             *__c,
             (int)*__c);
      if ( stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
             v9,
             v16) >= v8 )
        return (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > **)__a;
      else
        return __c;
    }
    else
    {
      return __b;
    }
  }
}


const char *const *__usercall stlp_std::priv::__median<char const *,bool (__cdecl *)(char const *,char const *)>@<eax>(
        const char **__c@<edi>,
        bool (__cdecl *__comp)(const char *, const char *)@<esi>,
        const char **__a,
        const char **__b)
{
  const char *const *result; // eax
  bool v5; // zf

  if ( __comp(*__a, *__b) )
  {
    if ( !__comp(*__b, *__c) )
    {
      if ( __comp(*__a, *__c) )
        return __c;
      return __a;
    }
    return __b;
  }
  if ( __comp(*__a, *__c) )
    return __a;
  v5 = !__comp(*__b, *__c);
  result = __c;
  if ( v5 )
    return __b;
  return result;
}


const char **__usercall stlp_std::priv::__median<char const *,vostok::render::shader_macros_dort_predicate>@<eax>(
        const char **__b@<eax>,
        const char **__a,
        const char **__c)
{
  if ( strcmp(*__a, *__b) < 0 )
  {
    if ( strcmp(*__b, *__c) < 0 )
      return __b;
    if ( strcmp(*__a, *__c) >= 0 )
      return __a;
    return __c;
  }
  if ( strcmp(*__a, *__c) < 0 )
    return __a;
  if ( strcmp(*__b, *__c) < 0 )
    return __c;
  return __b;
}


const char **__cdecl stlp_std::priv::__median<char const *,vostok::tips_sorting_predicate>(
        const char **__a,
        char **__b,
        char **__c,
        vostok::tips_sorting_predicate __comp)
{
  unsigned __int8 *v4; // ebx
  char *v5; // edi
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // eax
  char *v10; // edi
  char *v11; // ebx
  int v12; // eax
  int v13; // esi
  int v14; // eax
  const char **result; // eax
  char **v16; // esi
  bool v17; // al
  unsigned __int8 *v18; // ebx
  int v19; // eax
  int v20; // esi
  int v21; // eax
  bool v22; // zf

  v4 = (unsigned __int8 *)*__a;
  v5 = *__b;
  strstr((unsigned __int8 *)*__a, (unsigned __int8 *)__comp.editor_str);
  v7 = v6;
  strstr((unsigned __int8 *)v5, (unsigned __int8 *)__comp.editor_str);
  v9 = v8 - (_DWORD)v5;
  v10 = *__c;
  if ( v7 - (int)v4 >= v9 )
  {
    v18 = (unsigned __int8 *)*__a;
    strstr((unsigned __int8 *)*__a, (unsigned __int8 *)__comp.editor_str);
    v20 = v19;
    strstr((unsigned __int8 *)v10, (unsigned __int8 *)__comp.editor_str);
    if ( v20 - (int)v18 < v21 - (int)v10 )
      return __a;
    v16 = __b;
    v17 = vostok::tips_sorting_predicate::operator()(*__c, &__comp, *__b);
  }
  else
  {
    v11 = *__b;
    strstr((unsigned __int8 *)*__b, (unsigned __int8 *)__comp.editor_str);
    v13 = v12;
    strstr((unsigned __int8 *)v10, (unsigned __int8 *)__comp.editor_str);
    if ( v13 - (int)v11 < v14 - (int)v10 )
      return (const char **)__b;
    v16 = (char **)__a;
    v17 = vostok::tips_sorting_predicate::operator()(*__c, &__comp, (char *)*__a);
  }
  v22 = !v17;
  result = (const char **)__c;
  if ( v22 )
    return (const char **)v16;
  return result;
}


const vostok::ai::movement_target **__cdecl stlp_std::priv::__median<vostok::ai::movement_target const *,vostok::ai::selectors::sort_by_distance_predicate>(
        const vostok::ai::movement_target **__a,
        const vostok::ai::movement_target **__b,
        const vostok::ai::movement_target **__c,
        vostok::ai::selectors::sort_by_distance_predicate __comp)
{
  if ( vostok::ai::selectors::sort_by_distance_predicate::operator()(&__comp, *__a, *__b) )
  {
    if ( vostok::ai::selectors::sort_by_distance_predicate::operator()(&__comp, *__b, *__c) )
    {
      return __b;
    }
    else if ( vostok::ai::selectors::sort_by_distance_predicate::operator()(&__comp, *__a, *__c) )
    {
      return __c;
    }
    else
    {
      return __a;
    }
  }
  else if ( vostok::ai::selectors::sort_by_distance_predicate::operator()(&__comp, *__a, *__c) )
  {
    return __a;
  }
  else if ( vostok::ai::selectors::sort_by_distance_predicate::operator()(&__comp, *__b, *__c) )
  {
    return __c;
  }
  else
  {
    return __b;
  }
}


const vostok::physics::closest_ray_result *__usercall stlp_std::priv::__median<vostok::physics::closest_ray_result,vostok::physics::distance_predicate>@<eax>(
        const vostok::physics::closest_ray_result *__b@<eax>,
        const vostok::physics::closest_ray_result *__c@<ecx>,
        const vostok::physics::closest_ray_result *__a,
        vostok::physics::distance_predicate __comp)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v6; // xmm4_4
  float v7; // xmm6_4

  y = __comp.m_from.y;
  z = __comp.m_from.z;
  v6 = (float)((float)((float)(__b->hit_point_world.z - __comp.m_from.z)
                     * (float)(__b->hit_point_world.z - __comp.m_from.z))
             + (float)((float)(__b->hit_point_world.y - __comp.m_from.y)
                     * (float)(__b->hit_point_world.y - __comp.m_from.y)))
     + (float)((float)(__b->hit_point_world.x - __comp.m_from.x) * (float)(__b->hit_point_world.x - __comp.m_from.x));
  __comp.m_from.y = __c->hit_point_world.y - __comp.m_from.y;
  v7 = __c->hit_point_world.x - __comp.m_from.x;
  __comp.m_from.z = __c->hit_point_world.z - __comp.m_from.z;
  if ( v6 > (float)((float)((float)((float)(__a->hit_point_world.z - z) * (float)(__a->hit_point_world.z - z))
                          + (float)((float)(__a->hit_point_world.x - __comp.m_from.x)
                                  * (float)(__a->hit_point_world.x - __comp.m_from.x)))
                  + (float)((float)(__a->hit_point_world.y - y) * (float)(__a->hit_point_world.y - y))) )
  {
    if ( (float)((float)((float)(v7 * v7) + (float)(__comp.m_from.z * __comp.m_from.z))
               + (float)(__comp.m_from.y * __comp.m_from.y)) > (float)((float)((float)((float)(__b->hit_point_world.y - y)
                                                                                     * (float)(__b->hit_point_world.y - y))
                                                                             + (float)((float)(__b->hit_point_world.x
                                                                                             - __comp.m_from.x)
                                                                                     * (float)(__b->hit_point_world.x
                                                                                             - __comp.m_from.x)))
                                                                     + (float)((float)(__b->hit_point_world.z - z)
                                                                             * (float)(__b->hit_point_world.z - z))) )
      return __b;
    if ( (float)((float)((float)((float)(__c->hit_point_world.x - __comp.m_from.x)
                               * (float)(__c->hit_point_world.x - __comp.m_from.x))
                       + (float)((float)(__c->hit_point_world.z - z) * (float)(__c->hit_point_world.z - z)))
               + (float)((float)(__c->hit_point_world.y - y) * (float)(__c->hit_point_world.y - y))) <= (float)((float)((float)((float)(__a->hit_point_world.x - __comp.m_from.x) * (float)(__a->hit_point_world.x - __comp.m_from.x)) + (float)((float)(__a->hit_point_world.z - z) * (float)(__a->hit_point_world.z - z))) + (float)((float)(__a->hit_point_world.y - y) * (float)(__a->hit_point_world.y - y))) )
      return __a;
    return __c;
  }
  if ( (float)((float)((float)(v7 * v7) + (float)(__comp.m_from.z * __comp.m_from.z))
             + (float)(__comp.m_from.y * __comp.m_from.y)) > (float)((float)((float)((float)(__a->hit_point_world.x
                                                                                           - __comp.m_from.x)
                                                                                   * (float)(__a->hit_point_world.x
                                                                                           - __comp.m_from.x))
                                                                           + (float)((float)(__a->hit_point_world.z - z)
                                                                                   * (float)(__a->hit_point_world.z - z)))
                                                                   + (float)((float)(__a->hit_point_world.y - y)
                                                                           * (float)(__a->hit_point_world.y - y))) )
    return __a;
  if ( (float)((float)((float)((float)(__c->hit_point_world.x - __comp.m_from.x)
                             * (float)(__c->hit_point_world.x - __comp.m_from.x))
                     + (float)((float)(__c->hit_point_world.z - z) * (float)(__c->hit_point_world.z - z)))
             + (float)((float)(__c->hit_point_world.y - y) * (float)(__c->hit_point_world.y - y))) > (float)((float)((float)((float)(__b->hit_point_world.x - __comp.m_from.x) * (float)(__b->hit_point_world.x - __comp.m_from.x)) + (float)((float)(__b->hit_point_world.z - z) * (float)(__b->hit_point_world.z - z))) + (float)((float)(__b->hit_point_world.y - y) * (float)(__b->hit_point_world.y - y))) )
    return __c;
  return __b;
}


const vostok::sound::propagator_info *__cdecl stlp_std::priv::__median<vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        const vostok::sound::propagator_info *__a,
        const vostok::sound::propagator_info *__b,
        const vostok::sound::propagator_info *__c,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  if ( __comp(__a, __b) )
  {
    if ( __comp(__b, __c) )
    {
      return __b;
    }
    else if ( __comp(__a, __c) )
    {
      return __c;
    }
    else
    {
      return __a;
    }
  }
  else if ( __comp(__a, __c) )
  {
    return __a;
  }
  else if ( __comp(__b, __c) )
  {
    return __c;
  }
  else
  {
    return __b;
  }
}


const vostok::render::grass_patch::sort_info *__fastcall stlp_std::priv::__median<vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
        const vostok::render::grass_patch::sort_info *__b,
        const vostok::render::grass_patch::sort_info *__c,
        const vostok::render::grass_patch::sort_info *__a,
        vostok::render::sort_indices_predicate __comp)
{
  const vostok::render::grass_patch::sort_info *result; // eax
  float y; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm4_4
  float v11; // xmm6_4
  float v12; // xmm5_4
  float v13; // [esp+0h] [ebp-10h]
  float __aa; // [esp+14h] [ebp+4h]

  result = __a;
  y = __a->position.y;
  v6 = __a->position.x - __comp.m_view_pos.x;
  v7 = __b->position.x - __comp.m_view_pos.x;
  v8 = __a->position.z - __comp.m_view_pos.z;
  __aa = __b->position.y - __comp.m_view_pos.y;
  v9 = y - __comp.m_view_pos.y;
  v10 = __c->position.x - __comp.m_view_pos.x;
  if ( (float)((float)((float)(v7 * v7)
                     + (float)((float)(__b->position.z - __comp.m_view_pos.z)
                             * (float)(__b->position.z - __comp.m_view_pos.z)))
             + (float)(__aa * __aa)) > (float)((float)((float)(v6 * v6) + (float)(v9 * v9)) + (float)(v8 * v8)) )
  {
    v13 = __c->position.z - __comp.m_view_pos.z;
    if ( (float)((float)((float)(v10 * v10) + (float)(v13 * v13))
               + (float)((float)(__c->position.y - __comp.m_view_pos.y) * (float)(__c->position.y - __comp.m_view_pos.y))) <= (float)((float)((float)(v7 * v7) + (float)((float)(__b->position.z - __comp.m_view_pos.z) * (float)(__b->position.z - __comp.m_view_pos.z))) + (float)(__aa * __aa)) )
    {
      if ( (float)((float)((float)(v10 * v10) + (float)(v13 * v13))
                 + (float)((float)(__c->position.y - __comp.m_view_pos.y)
                         * (float)(__c->position.y - __comp.m_view_pos.y))) > (float)((float)((float)(v6 * v6)
                                                                                            + (float)(v8 * v8))
                                                                                    + (float)(v9 * v9)) )
        return __c;
      return result;
    }
    return __b;
  }
  v11 = __c->position.z - __comp.m_view_pos.z;
  v12 = __c->position.y - __comp.m_view_pos.y;
  if ( (float)((float)((float)(v10 * v10) + (float)(v11 * v11)) + (float)(v12 * v12)) <= (float)((float)((float)(v6 * v6) + (float)(v8 * v8))
                                                                                               + (float)(v9 * v9)) )
  {
    result = __c;
    if ( (float)((float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v10 * v10)) <= (float)((float)((float)((float)(__b->position.z - __comp.m_view_pos.z) * (float)(__b->position.z - __comp.m_view_pos.z)) + (float)(__aa * __aa))
                                                                                                 + (float)(v7 * v7)) )
      return __b;
  }
  return result;
}
