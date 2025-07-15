void __thiscall vostok::animation::mixing::n_ary_tree_transition_tree_constructor::merge_trees(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        const vostok::animation::base_interpolator *from,
        const vostok::animation::mixing::n_ary_tree *to,
        int a4)
{
  vostok::animation::mixing::n_ary_tree_animation_node *m_weight_root; // edx
  unsigned int m_weight_synchronization_group_id; // ecx
  const vostok::animation::base_interpolator *v6; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *v7; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v8; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *v9; // esi
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *m_constructor; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v11; // eax
  unsigned int v12; // eax
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v13; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v14; // eax
  unsigned int v15; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *v16; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v17; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v18; // eax
  unsigned int v19; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *v20; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *i; // eax
  vostok::animation::mixing::animation_state *m_animation_state; // ecx
  char v23; // dl
  unsigned int m_time_synchronization_group_id; // esi
  vostok::animation::mixing::n_ary_tree_animation_node **j; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v26; // esi
  void *v27; // esp
  vostok::animation::mixing::n_ary_tree_animation_node *v28; // eax
  vostok::animation::mixing::n_ary_tree_animation_node **v29; // esi
  int v30; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node **v31; // eax
  int v32; // edx
  int v33; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *k; // esi
  vostok::animation::mixing::animation_state *v35; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *m_time_driving_animation; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v37; // ecx
  unsigned int animation_interval_id; // ebx
  const vostok::animation::mixing::animation_interval *m_animation_intervals; // edx
  float z; // xmm0_4
  float x; // eax
  float v42; // xmm0_4
  unsigned __int8 v43; // al
  vostok::resources::pinned_ptr_mutable<unsigned char> *v44; // ecx
  vostok::animation::mixing::animation_state *v45; // edi
  vostok::animation::base_interpolator_vtbl *v46; // [esp+14h] [ebp-24h] BYREF
  _BYTE v47[8]; // [esp+18h] [ebp-20h] BYREF
  unsigned __int16 initial_event_types[2]; // [esp+20h] [ebp-18h]
  float weight; // [esp+24h] [ebp-14h]
  vostok::animation::mixing::bone_matrices_computer_data *__that; // [esp+28h] [ebp-10h]
  float animation_time_threshold; // [esp+2Ch] [ebp-Ch]
  unsigned int previous_animation_interval_id; // [esp+30h] [ebp-8h]
  bool is_freezed[4]; // [esp+34h] [ebp-4h]
  vostok::animation::mixing::n_ary_tree_animation_node *v54; // [esp+48h] [ebp+10h]
  const vostok::animation::mixing::animation_interval *animation_interval_time; // [esp+48h] [ebp+10h]

  m_weight_root = to->m_weight_root;
  m_weight_synchronization_group_id = m_weight_root->m_weight_synchronization_group_id;
  v6 = from;
  previous_animation_interval_id = (unsigned int)m_weight_root;
  v7 = m_weight_root;
  do
  {
    if ( v7->m_weight_synchronization_group_id != m_weight_synchronization_group_id )
      break;
    v7 = v7->m_next_weight_animation;
  }
  while ( v7 );
  v8 = v7;
  v9 = *(vostok::animation::mixing::n_ary_tree_animation_node **)(a4 + 4);
  m_constructor = (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)v9->m_weight_synchronization_group_id;
  *(_DWORD *)is_freezed = v7;
  v11 = v9;
  do
  {
    if ( (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)v11->m_weight_synchronization_group_id != m_constructor )
      break;
    v11 = v11->m_next_weight_animation;
  }
  while ( v11 );
  v54 = v11;
  while ( v9 )
  {
    v12 = v9->m_weight_synchronization_group_id;
    v13 = (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)m_weight_root->m_weight_synchronization_group_id;
    if ( (unsigned int)v13 >= v12 )
    {
      if ( (unsigned int)v13 > v12 )
      {
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_weight_synchronization_group(
          v9,
          v13,
          from,
          v54);
        v16 = v54;
        v9 = v54;
        if ( v54 )
        {
          m_constructor = (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)v54->m_weight_synchronization_group_id;
          do
          {
            if ( (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)v16->m_weight_synchronization_group_id != m_constructor )
              break;
            v16 = v16->m_next_weight_animation;
          }
          while ( v16 );
          v54 = v16;
        }
        goto LABEL_32;
      }
      vostok::animation::mixing::n_ary_tree_transition_tree_constructor::change_weight_synchronization_group(
        (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)from,
        (vostok::animation::mixing::n_ary_tree_subtraction_node *)v9,
        v13,
        m_weight_root,
        v8,
        v54);
      previous_animation_interval_id = *(_DWORD *)is_freezed;
      if ( *(_DWORD *)is_freezed )
      {
        m_constructor = *(vostok::animation::mixing::n_ary_tree_transition_tree_constructor **)is_freezed;
        do
        {
          if ( m_constructor->m_cloner.m_start_time_in_ms != *(_DWORD *)(*(_DWORD *)is_freezed + 56) )
            break;
          m_constructor = m_constructor->m_cloner.m_constructor;
        }
        while ( m_constructor );
        *(_DWORD *)is_freezed = m_constructor;
      }
      v9 = v54;
      if ( v54 )
      {
        v17 = v54;
        m_constructor = (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)v54->m_weight_synchronization_group_id;
        do
        {
          if ( (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)v17->m_weight_synchronization_group_id != m_constructor )
            break;
          v17 = v17->m_next_weight_animation;
        }
        while ( v17 );
        v54 = v17;
      }
    }
    else
    {
      vostok::animation::mixing::n_ary_tree_transition_tree_constructor::remove_weight_synchronization_group(
        v13,
        (vostok::resources::managed_resource *)from,
        m_weight_root,
        v8);
      previous_animation_interval_id = (unsigned int)v8;
      if ( !v8 )
        goto LABEL_39;
      v14 = v8;
      v15 = v8->m_weight_synchronization_group_id;
      do
      {
        if ( v14->m_weight_synchronization_group_id != v15 )
          break;
        v14 = v14->m_next_weight_animation;
      }
      while ( v14 );
      *(_DWORD *)is_freezed = v14;
    }
    v8 = *(vostok::animation::mixing::n_ary_tree_animation_node **)is_freezed;
LABEL_32:
    m_weight_root = (vostok::animation::mixing::n_ary_tree_animation_node *)previous_animation_interval_id;
    if ( !previous_animation_interval_id )
      break;
  }
  if ( m_weight_root )
  {
    while ( 1 )
    {
      vostok::animation::mixing::n_ary_tree_transition_tree_constructor::remove_weight_synchronization_group(
        m_constructor,
        (vostok::resources::managed_resource *)from,
        m_weight_root,
        v8);
      previous_animation_interval_id = (unsigned int)v8;
      if ( !v8 )
        break;
      v18 = v8;
      v19 = v8->m_weight_synchronization_group_id;
      do
      {
        if ( v18->m_weight_synchronization_group_id != v19 )
          break;
        v18 = v18->m_next_weight_animation;
      }
      while ( v18 );
      m_weight_root = (vostok::animation::mixing::n_ary_tree_animation_node *)previous_animation_interval_id;
      *(_DWORD *)is_freezed = v18;
      v8 = v18;
    }
  }
LABEL_39:
  if ( v9 )
  {
    while ( 1 )
    {
      vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_weight_synchronization_group(
        v9,
        m_constructor,
        from,
        v54);
      v20 = v54;
      v9 = v54;
      if ( !v54 )
        break;
      m_constructor = (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)v54->m_weight_synchronization_group_id;
      do
      {
        if ( (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)v20->m_weight_synchronization_group_id != m_constructor )
          break;
        v20 = v20->m_next_weight_animation;
      }
      while ( v20 );
      v54 = v20;
    }
  }
  for ( i = (vostok::animation::mixing::n_ary_tree_animation_node *)from[22].__vftable; i; i = i->m_next_weight_animation )
  {
    m_animation_state = i->m_animation_state;
    if ( LODWORD(m_animation_state->bone_matrices_computer.previous_object_movement.rotation.x) )
      v23 = *(_BYTE *)(LODWORD(m_animation_state->bone_matrices_computer.previous_object_movement.rotation.x) + 117);
    else
      v23 = 0;
    m_time_synchronization_group_id = i->m_time_synchronization_group_id;
    if ( m_time_synchronization_group_id != -1 )
    {
      for ( j = (vostok::animation::mixing::n_ary_tree_animation_node **)from[24].__vftable; ; ++j )
      {
        if ( j == (vostok::animation::mixing::n_ary_tree_animation_node **)from[25].__vftable )
        {
          v26 = 0;
          goto LABEL_55;
        }
        if ( (*j)->m_time_synchronization_group_id == m_time_synchronization_group_id )
          break;
      }
      v26 = *j;
LABEL_55:
      if ( v26 && v26 != i && !v23 )
        i->m_time_driving_animation = v26;
    }
  }
  v27 = alloca(4 * (int)from[34].__vftable);
  v28 = (vostok::animation::mixing::n_ary_tree_animation_node *)from[22].__vftable;
  v29 = (vostok::animation::mixing::n_ary_tree_animation_node **)&v46;
  while ( v28 )
  {
    *v29 = v28;
    v28 = v28->m_next_weight_animation;
    ++v29;
  }
  LOBYTE(animation_time_threshold) = 0;
  stlp_std::sort<vostok::animation::mixing::n_ary_tree_animation_node * *,vostok::animation::mixing::time_animations_predicate>(
    (vostok::animation::mixing::n_ary_tree_animation_node **)&v46,
    v29,
    (vostok::animation::mixing::n_ary_tree_animation_node **)LODWORD(animation_time_threshold));
  v30 = (int)&v46;
  from[23].__vftable = v46;
  v31 = (vostok::animation::mixing::n_ary_tree_animation_node **)v47;
  if ( v47 != (_BYTE *)v29 )
  {
    v30 = -4;
    do
    {
      v32 = (int)*(v31 - 1);
      v33 = (int)*v31++;
      *(_DWORD *)(v32 + 44) = v33;
    }
    while ( v31 != v29 );
  }
  for ( k = (vostok::animation::mixing::n_ary_tree_animation_node *)from[23].__vftable; k; k = k->m_next_time_animation )
  {
    v35 = k->m_animation_state;
    *(_DWORD *)initial_event_types = LOWORD(v35->bone_matrices_computer.previous_object_movement.translation.elements[1]);
    m_time_driving_animation = k->m_time_driving_animation;
    if ( m_time_driving_animation )
    {
      v37 = k->m_time_driving_animation;
      animation_interval_id = v37->m_animation_state->animation_interval_id;
      m_animation_intervals = k->m_animation_intervals;
      v30 = (int)v37->m_animation_intervals;
      __that = &m_time_driving_animation->m_animation_state->bone_matrices_computer;
      previous_animation_interval_id = LODWORD(__that[1].previous_object_movement.rotation.x);
      z = (float)(m_animation_intervals[previous_animation_interval_id].m_length
                / *(float *)(20 * animation_interval_id + v30 + 16))
        * __that[1].previous_object_movement.rotation.z;
      v6 = from;
    }
    else
    {
      z = v35->bone_matrices_computer.previous_object_movement.rotation.z;
      previous_animation_interval_id = LODWORD(v35->bone_matrices_computer.previous_object_movement.rotation.y);
    }
    x = v35->bone_matrices_computer.previous_object_movement.rotation.x;
    animation_interval_time = (const vostok::animation::mixing::animation_interval *)LODWORD(z);
    animation_time_threshold = v35->bone_matrices_computer.previous_object_movement.rotation.w;
    v42 = v35->bone_matrices_computer.previous_object_movement.translation.x;
    weight = v42;
    __that = (vostok::animation::mixing::bone_matrices_computer_data *)LODWORD(x);
    if ( x == 0.0 )
      is_freezed[0] = 0;
    else
      is_freezed[0] = *(_BYTE *)(LODWORD(x) + 117);
    if ( v35 )
    {
      v43 = disabled_channel_ids(
              v42,
              (const boost::function<unsigned char __cdecl(void const *)> *)v6[20].__vftable,
              k,
              previous_animation_interval_id,
              animation_interval_time,
              (unsigned int)v6[33].__vftable,
              to);
      vostok::animation::mixing::animation_state::animation_state(
        previous_animation_interval_id,
        v44,
        v35,
        k,
        (unsigned int)v6[33].__vftable,
        initial_event_types[0],
        previous_animation_interval_id,
        *(float *)&animation_interval_time,
        animation_time_threshold,
        weight,
        is_freezed[0],
        (vostok::resources::managed_resource *)v43);
    }
    v45 = k->m_animation_state;
    v45->are_there_any_weight_transitions = vostok::animation::mixing::n_ary_tree_event_iterator::are_there_any_weight_transitions(
                                              (vostok::animation::mixing::n_ary_tree_event_iterator *)v30,
                                              (int)&v45->event_iterator);
    if ( __that )
      vostok::animation::mixing::bone_matrices_computer_data::operator=(
        __that,
        &k->m_animation_state->bone_matrices_computer);
  }
  stlp_std::sort<vostok::animation::mixing::animated_object_holder *,vostok::animation::mixing::animated_object_id_predicate>(
    (vostok::animation::mixing::animated_object_holder *)v6[29].__vftable,
    (vostok::animation::mixing::animated_object_holder *)v6[29].__vftable + (int)v6[35].__vftable,
    0);
  v6[24].__vftable = 0;
  v6[25].__vftable = 0;
}
