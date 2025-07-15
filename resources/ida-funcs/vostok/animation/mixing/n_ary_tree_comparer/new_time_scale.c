char __userpurge vostok::animation::mixing::n_ary_tree_comparer::new_time_scale@<al>(
        vostok::animation::mixing::n_ary_tree_animation_node *new_time_driving_animation@<eax>,
        vostok::animation::mixing::n_ary_tree_comparer *this)
{
  unsigned int m_time_synchronization_group_id; // edx
  vostok::animation::mixing::n_ary_tree_animation_node *i; // ebx
  vostok::animation::mixing::animation_state *m_animation_state; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *j; // eax
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v11; // esi
  void (__thiscall *v12)(struct vostok::animation::mixing::n_ary_tree_n_ary_operation_node *); // eax
  float v13; // xmm0_4
  int v14; // eax
  void (__thiscall *v15)(struct vostok::animation::mixing::n_ary_tree_n_ary_operation_node *, vostok::animation::mixing::n_ary_tree_visitor *); // eax
  bool v16; // zf
  float *v17; // ecx
  vostok::animation::mixing::n_ary_tree_comparer *v18; // ebx
  vostok::animation::mixing::n_ary_tree_comparer *v19; // esi
  int v20; // eax
  bool v21; // al
  unsigned int m_current_time_in_ms; // [esp-8h] [ebp-5Ch]
  unsigned int v23; // [esp+0h] [ebp-54h]
  struct vostok::animation::mixing::n_ary_tree_animation_node *v24; // [esp+4h] [ebp-50h]
  char v25[12]; // [esp+10h] [ebp-44h] BYREF
  float *v26; // [esp+1Ch] [ebp-38h]
  float v27; // [esp+2Ch] [ebp-28h]
  vostok::animation::mixing::n_ary_tree_target_time_scale_calculator v28; // [esp+38h] [ebp-1Ch] BYREF
  float v29; // [esp+40h] [ebp-14h]
  float v30; // [esp+44h] [ebp-10h]
  float v31; // [esp+48h] [ebp-Ch] BYREF
  char v32; // [esp+4Fh] [ebp-5h]

  v29 = 0.0;
  m_time_synchronization_group_id = new_time_driving_animation->m_time_synchronization_group_id;
  for ( i = this->m_from->m_weight_root; ; i = i->m_next_weight_animation )
  {
    if ( !i )
      return 0;
    if ( !i->m_time_driving_animation && i->m_time_synchronization_group_id == m_time_synchronization_group_id )
      break;
  }
  m_animation_state = i->m_animation_state;
  if ( m_animation_state->is_freezed )
    return 0;
  for ( j = this->m_to->m_time_root; j; j = j->m_next_time_animation )
  {
    if ( j->m_time_synchronization_group_id == m_time_synchronization_group_id )
    {
      if ( j != new_time_driving_animation )
        return 0;
      break;
    }
  }
  v8 = new_time_driving_animation->m_animation_intervals[m_animation_state->animation_interval_id].m_length
     / i->m_animation_intervals[m_animation_state->animation_interval_id].m_length;
  v9 = new_time_driving_animation->m_is_positive_event_direction == i->m_is_positive_event_direction
     ? s_bm_current_air_resistance
     : FLOAT_N1_0;
  v16 = !new_time_driving_animation->m_override_existing_animation;
  v30 = v9 * v8;
  v10 = v16
      ? m_animation_state->animation_interval_time * v8
      : new_time_driving_animation->m_animation_state->animation_interval_time;
  m_current_time_in_ms = this->m_current_time_in_ms;
  v31 = v10;
  vostok::animation::mixing::n_ary_tree_time_scale_calculator::n_ary_tree_time_scale_calculator(
    0,
    (int)v25,
    0,
    m_current_time_in_ms,
    *(float *)&m_current_time_in_ms,
    v23,
    v24);
  if ( new_time_driving_animation->m_operands_count
    && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))new_time_driving_animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 3))(new_time_driving_animation[1].__vftable) )
  {
    v11 = new_time_driving_animation[1].__vftable;
  }
  else
  {
    v11 = 0;
  }
  if ( v11
    && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v11->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 3))(v11) )
  {
    v12 = v11->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node;
    v32 = 1;
    (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, char *))v12 + 2))(v11, v25);
  }
  else
  {
    v32 = 0;
  }
  v13 = v11
     && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v11->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
         + 3))(v11)
      ? v27
      : s_bm_current_air_resistance;
  v29 = v13;
  vostok::animation::mixing::n_ary_tree_target_time_scale_calculator::n_ary_tree_target_time_scale_calculator(&v28, i);
  if ( v29 == (float)(*(float *)(v14 + 4) * v30)
    || v11
    && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v11->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 5))(v11) )
  {
    if ( v11 )
    {
      v15 = (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v11->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
             + 5))(v11)
          ? v11->accept
          : (void (__thiscall *)(struct vostok::animation::mixing::n_ary_tree_n_ary_operation_node *, vostok::animation::mixing::n_ary_tree_visitor *))v11;
      v16 = v31 == *((float *)v15 + 3);
    }
    else
    {
      v16 = v31 == 0.0;
    }
    if ( v16 )
      return 0;
  }
  if ( v32 )
  {
    v17 = v26;
  }
  else
  {
    v31 = COERCE_FLOAT(&vostok::animation::instant_interpolator::`vftable');
    v17 = &v31;
  }
  if ( ((double (__thiscall *)(float *))*(_DWORD *)(*(_DWORD *)v17 + 16))(v17) <= 0.0 )
  {
    this->m_needed_buffer_size += 20;
    vostok::animation::mixing::n_ary_tree_target_time_scale_calculator::n_ary_tree_target_time_scale_calculator(&v28, i);
    v21 = this->m_equal
       && v29 == (float)(*(float *)(v20 + 4) * v30)
       && (!v11
        || !(*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v11->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
             + 5))(v11));
    this->m_equal = v21;
  }
  else
  {
    if ( i->m_operands_count
      && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))i[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
          + 3))(i[1].__vftable) )
    {
      v18 = (vostok::animation::mixing::n_ary_tree_comparer *)i[1].__vftable;
    }
    else
    {
      v18 = 0;
    }
    if ( v18 )
    {
      v19 = this;
      vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(v18, (int)this);
    }
    else
    {
      this->m_needed_buffer_size += 20;
      v19 = this;
    }
    v19->m_needed_buffer_size += 40;
    v19->m_equal = 0;
  }
  return 1;
}
