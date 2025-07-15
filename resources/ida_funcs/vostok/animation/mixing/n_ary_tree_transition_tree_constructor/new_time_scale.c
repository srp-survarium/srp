vostok::animation::mixing::n_ary_tree_time_scale_transition_node *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_time_scale@<eax>(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this@<ecx>,
        int a2@<eax>,
        vostok::animation::mixing::n_ary_tree_animation_node *new_time_driving_animation,
        float animation_interval_id,
        vostok::animation::mixing::n_ary_tree_base_node *animation_interval_time)
{
  unsigned int m_time_synchronization_group_id; // ecx
  int v7; // esi
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *result; // eax
  int v9; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *v10; // eax
  unsigned int v11; // ebx
  vostok::animation::mixing::animation_interval *v12; // ecx
  double v13; // st7
  vostok::animation::mixing::n_ary_tree_animation_node *v14; // ebp
  char m_is_positive_event_direction; // al
  float v16; // xmm0_4
  bool v17; // zf
  float v18; // xmm0_4
  unsigned int v19; // eax
  float *v20; // ebx
  void (__thiscall *v21)(float *, vostok::animation::mixing::n_ary_tree_time_scale_calculator *); // edx
  float m_time_scale; // xmm0_4
  char v23; // al
  const vostok::animation::base_interpolator *m_interpolator; // ebx
  vostok::animation::mixing::n_ary_tree_cloner *v25; // ecx
  int v26; // ecx
  float v27; // xmm0_4
  int v28; // ebp
  int v29; // esi
  vostok::animation::mixing::n_ary_tree_base_node *v30; // xmm0_4
  vostok::animation::mixing::n_ary_tree_cloner *v31; // ecx
  const vostok::animation::base_interpolator *v32; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v33; // ecx
  vostok::animation::mixing::n_ary_tree_base_node_vtbl *v34; // edx
  float v35; // xmm0_4
  _DWORD *v36; // ecx
  _DWORD *v37; // ecx
  int v38; // ecx
  int v39; // edx
  float v40; // xmm0_4
  _DWORD *v41; // edx
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *v42; // esi
  unsigned int v43; // edx
  vostok::animation::mixing::n_ary_tree_base_node *v44; // ebx
  _DWORD *v45; // edi
  _DWORD *v46; // edi
  const vostok::animation::base_interpolator *v47; // eax
  int v48; // ecx
  int v49; // edx
  float v50; // xmm0_4
  _DWORD *v51; // edi
  _DWORD *v52; // edi
  bool v53; // [esp+0h] [ebp-48h]
  vostok::animation::mixing::n_ary_tree_base_node *time_scale_node[2]; // [esp+10h] [ebp-38h] BYREF
  float new_time_driving_animation_time_offset; // [esp+18h] [ebp-30h]
  float new_driving_animation_length; // [esp+1Ch] [ebp-2Ch]
  vostok::animation::mixing::n_ary_tree_time_scale_calculator time_scale_calculator; // [esp+20h] [ebp-28h] BYREF

  m_time_synchronization_group_id = new_time_driving_animation->m_time_synchronization_group_id;
  v7 = *(_DWORD *)(*(_DWORD *)(a2 + 72) + 4);
  time_scale_node[0] = 0;
  if ( !v7 )
    return 0;
  while ( *(_DWORD *)(v7 + 20) || *(_DWORD *)(v7 + 52) != m_time_synchronization_group_id )
  {
    v7 = *(_DWORD *)(v7 + 40);
    if ( !v7 )
      return 0;
  }
  v9 = *(_DWORD *)(v7 + 28);
  if ( *(_BYTE *)(v9 + 117) )
    return 0;
  v10 = *(vostok::animation::mixing::n_ary_tree_animation_node **)(*(_DWORD *)(a2 + 76) + 8);
  if ( v10 )
  {
    while ( v10->m_time_synchronization_group_id != m_time_synchronization_group_id )
    {
      v10 = v10->m_next_time_animation;
      if ( !v10 )
        goto LABEL_12;
    }
    if ( v10 != new_time_driving_animation )
      return 0;
  }
LABEL_12:
  if ( new_time_driving_animation->m_override_existing_animation )
    v11 = new_time_driving_animation->m_animation_state->animation_interval_id;
  else
    v11 = *(_DWORD *)(v9 + 92);
  new_driving_animation_length = vostok::animation::mixing::animation_interval::length(&new_time_driving_animation->m_animation_intervals[v11]);
  v12 = (vostok::animation::mixing::animation_interval *)(*(_DWORD *)(v7 + 16) + 12 * v11);
  *(_DWORD *)LODWORD(animation_interval_id) = v11;
  v13 = vostok::animation::mixing::animation_interval::length(v12);
  v14 = new_time_driving_animation;
  m_is_positive_event_direction = new_time_driving_animation->m_is_positive_event_direction;
  animation_interval_id = new_driving_animation_length / v13;
  if ( m_is_positive_event_direction == *(_BYTE *)(v7 + 83) )
    v16 = *(float *)&clear_value;
  else
    v16 = -1.0;
  v17 = !new_time_driving_animation->m_override_existing_animation;
  new_driving_animation_length = v16 * animation_interval_id;
  if ( v17 )
    v18 = *(float *)(*(_DWORD *)(v7 + 28) + 100) * animation_interval_id;
  else
    v18 = new_time_driving_animation->m_animation_state->animation_interval_time;
  *(float *)&animation_interval_time->__vftable = v18;
  v19 = *(_DWORD *)(a2 + 132);
  new_time_driving_animation_time_offset = v18;
  time_scale_calculator.__vftable = (vostok::animation::mixing::n_ary_tree_time_scale_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_time_scale_calculator::`vftable';
  memset((void *)&time_scale_calculator.m_animation, 0, 12);
  time_scale_calculator.m_current_time_in_ms = v19;
  time_scale_calculator.m_previous_animation_time = 0.0;
  time_scale_calculator.m_previous_time_in_ms = v19;
  memset(&time_scale_calculator.m_time_scale, 0, 12);
  if ( v14->m_operands_count )
  {
    v20 = (float *)v14[1].__vftable;
    animation_interval_time = (vostok::animation::mixing::n_ary_tree_base_node *)v20;
    if ( v20 && (*(unsigned __int8 (__thiscall **)(float *))(*(_DWORD *)v20 + 12))(v20) )
    {
      v21 = *(void (__thiscall **)(float *, vostok::animation::mixing::n_ary_tree_time_scale_calculator *))(*(_DWORD *)v20 + 8);
      LOBYTE(animation_interval_id) = 1;
      v21(v20, &time_scale_calculator);
      m_time_scale = time_scale_calculator.m_time_scale;
      v23 = LOBYTE(animation_interval_id);
      goto LABEL_27;
    }
  }
  else
  {
    animation_interval_time = 0;
  }
  m_time_scale = *(float *)&clear_value;
  v23 = 0;
LABEL_27:
  m_interpolator = time_scale_calculator.m_interpolator;
  animation_interval_id = m_time_scale;
  if ( !v23 )
    m_interpolator = v14->m_weight_interpolator;
  if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))m_interpolator->transition_time)(m_interpolator) <= 0.0 )
  {
    if ( animation_interval_id != *(float *)&clear_value )
    {
      v47 = vostok::animation::mixing::n_ary_tree_cloner::clone(v25, a2 + 32, m_interpolator, v53);
      v48 = **(_DWORD **)(a2 + 68);
      if ( v48 )
      {
        v49 = *(_DWORD *)(a2 + 132);
        *(float *)(v48 + 8) = animation_interval_id;
        v50 = new_time_driving_animation_time_offset;
        *(_DWORD *)(v48 + 4) = v47;
        *(_DWORD *)v48 = &vostok::animation::mixing::n_ary_tree_time_scale_node::`vftable';
        *(float *)(v48 + 12) = v50;
        *(_DWORD *)(v48 + 16) = v49;
        v51 = *(_DWORD **)(a2 + 68);
        *v51 += 20;
        v51[1] -= 20;
        time_scale_node[0] = (vostok::animation::mixing::n_ary_tree_base_node *)v48;
        return (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)v48;
      }
      v52 = *(_DWORD **)(a2 + 68);
      *v52 += 20;
      v52[1] -= 20;
      time_scale_node[0] = 0;
    }
    return (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)time_scale_node[0];
  }
  if ( *(_DWORD *)(v7 + 4)
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(v7 + 88) + 12))(*(_DWORD *)(v7 + 88))
    && (v26 = *(_DWORD *)(v7 + 88)) != 0 )
  {
    v27 = new_driving_animation_length;
    *(_DWORD *)(a2 + 36) = 0;
    *(float *)(a2 + 64) = v27;
    *(_DWORD *)(a2 + 52) = 0;
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v26 + 8))(v26, a2 + 32);
    *(_DWORD *)(a2 + 64) = clear_value;
    v28 = *(_DWORD *)(a2 + 36);
  }
  else
  {
    v28 = 0;
  }
  v17 = *(_DWORD *)(v7 + 4) == 0;
  time_scale_node[0] = (vostok::animation::mixing::n_ary_tree_base_node *)&vostok::animation::mixing::n_ary_tree_target_time_scale_calculator::`vftable';
  if ( !v17 && (v29 = *(_DWORD *)(v7 + 88)) != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v29 + 12))(v29) )
  {
    (*(void (__thiscall **)(int, vostok::animation::mixing::n_ary_tree_base_node **))(*(_DWORD *)v29 + 8))(
      v29,
      time_scale_node);
    v30 = time_scale_node[1];
  }
  else
  {
    v30 = (vostok::animation::mixing::n_ary_tree_base_node *)clear_value;
  }
  time_scale_node[0] = (vostok::animation::mixing::n_ary_tree_base_node *)v28;
  if ( animation_interval_id == (float)(*(float *)&v30 * new_driving_animation_length)
    || (v31 = (vostok::animation::mixing::n_ary_tree_cloner *)animation_interval_time) != 0
    && animation_interval_time->is_transition(animation_interval_time) )
  {
    if ( animation_interval_id == 0.0 && !(*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v28 + 20))(v28) )
    {
      result = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)time_scale_node[0];
      *(float *)(v28 + 12) = new_time_driving_animation->m_animation_state->animation_time;
      return result;
    }
    return (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)time_scale_node[0];
  }
  v32 = vostok::animation::mixing::n_ary_tree_cloner::clone(v31, a2 + 32, m_interpolator, v53);
  if ( !v28 )
  {
    v33 = **(vostok::animation::mixing::n_ary_tree_base_node ***)(a2 + 68);
    if ( v33 )
    {
      v34 = *(vostok::animation::mixing::n_ary_tree_base_node_vtbl **)(a2 + 132);
      v33[2].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)clear_value;
      v35 = new_time_driving_animation_time_offset;
      v33->__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)&vostok::animation::mixing::n_ary_tree_time_scale_node::`vftable';
      v33[1].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)v32;
      *(float *)&v33[3].__vftable = v35;
      v33[4].__vftable = v34;
      time_scale_node[0] = v33;
      v36 = *(_DWORD **)(a2 + 68);
      *v36 += 20;
      v36[1] -= 20;
    }
    else
    {
      v37 = *(_DWORD **)(a2 + 68);
      *v37 += 20;
      v37[1] -= 20;
      time_scale_node[0] = 0;
    }
  }
  v38 = **(_DWORD **)(a2 + 68);
  if ( v38 )
  {
    v39 = *(_DWORD *)(a2 + 132);
    *(float *)(v38 + 8) = animation_interval_id;
    v40 = new_time_driving_animation_time_offset;
    *(_DWORD *)v38 = &vostok::animation::mixing::n_ary_tree_time_scale_node::`vftable';
    *(_DWORD *)(v38 + 4) = v32;
    *(float *)(v38 + 12) = v40;
    *(_DWORD *)(v38 + 16) = v39;
  }
  else
  {
    v38 = 0;
  }
  v41 = *(_DWORD **)(a2 + 68);
  *v41 += 20;
  v41[1] -= 20;
  v42 = **(vostok::animation::mixing::n_ary_tree_time_scale_transition_node ***)(a2 + 68);
  if ( v42 )
  {
    v43 = *(_DWORD *)(a2 + 132);
    v44 = time_scale_node[0];
    v42->m_interpolator = v32;
    v42->m_to = (vostok::animation::mixing::n_ary_tree_base_node *)v38;
    v42->m_from = v44;
    v42->m_start_time_in_ms = v43;
    v42->__vftable = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node_vtbl *)&vostok::animation::mixing::n_ary_tree_time_scale_transition_node::`vftable';
    new_time_driving_animation = (vostok::animation::mixing::n_ary_tree_animation_node *)&vostok::animation::mixing::time_scale_transition_debug::`vftable';
    vostok::animation::mixing::n_ary_tree_time_scale_transition_node::accept(
      v42,
      (vostok::animation::mixing::n_ary_tree_visitor *)&new_time_driving_animation);
    v45 = *(_DWORD **)(a2 + 68);
    *v45 += 20;
    v45[1] -= 20;
    time_scale_node[0] = v42;
    return v42;
  }
  else
  {
    v46 = *(_DWORD **)(a2 + 68);
    *v46 += 20;
    v46[1] -= 20;
    time_scale_node[0] = 0;
    return 0;
  }
}
