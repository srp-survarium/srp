bool __thiscall vostok::animation::mixing::n_ary_tree_comparer::new_time_scale(
        vostok::animation::mixing::n_ary_tree_comparer *this,
        vostok::animation::mixing::n_ary_tree_comparer *new_time_driving_animation,
        vostok::animation::mixing::n_ary_tree_animation_node *new_driving_animation_length)
{
  unsigned int m_time_synchronization_group_id; // edx
  vostok::animation::mixing::n_ary_tree_animation_node *m_weight_root; // esi
  bool result; // al
  vostok::animation::mixing::animation_state *m_animation_state; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *m_time_root; // eax
  int animation_interval_id; // edi
  float v10; // xmm0_4
  vostok::animation::mixing::animation_state *m_current_time_in_ms; // eax
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v12; // edi
  char v13; // bl
  float m_time_scale; // xmm0_4
  const vostok::animation::base_interpolator *m_interpolator; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v16; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *v17; // ebx
  void (__thiscall *v18)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, _DWORD *); // edx
  bool v19; // zf
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v20; // esi
  const vostok::math::float4x4 *v21; // xmm0_4
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v22; // esi
  const vostok::math::float4x4 *v23; // xmm0_4
  float new_time_driving_animation_target_time_scale; // [esp+10h] [ebp-44h]
  float directional_time_scale_factor; // [esp+14h] [ebp-40h]
  void **v26; // [esp+18h] [ebp-3Ch] BYREF
  _DWORD v27[3]; // [esp+1Ch] [ebp-38h] BYREF
  vostok::animation::mixing::n_ary_tree_time_scale_calculator time_scale_calculator; // [esp+28h] [ebp-2Ch] BYREF
  float new_driving_animation_lengthc; // [esp+5Ch] [ebp+8h]
  float new_driving_animation_lengtha; // [esp+5Ch] [ebp+8h]
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *new_driving_animation_lengthb; // [esp+5Ch] [ebp+8h]

  m_time_synchronization_group_id = new_driving_animation_length->m_time_synchronization_group_id;
  m_weight_root = new_time_driving_animation->m_from->m_weight_root;
  if ( !m_weight_root )
    return 0;
  while ( m_weight_root->m_time_driving_animation
       || m_weight_root->m_time_synchronization_group_id != m_time_synchronization_group_id )
  {
    m_weight_root = m_weight_root->m_next_weight_animation;
    if ( !m_weight_root )
      return 0;
  }
  m_animation_state = m_weight_root->m_animation_state;
  if ( m_animation_state->is_freezed )
    return 0;
  m_time_root = new_time_driving_animation->m_to->m_time_root;
  if ( m_time_root )
  {
    while ( m_time_root->m_time_synchronization_group_id != m_time_synchronization_group_id )
    {
      m_time_root = m_time_root->m_next_time_animation;
      if ( !m_time_root )
        goto LABEL_12;
    }
    if ( m_time_root != new_driving_animation_length )
      return 0;
  }
LABEL_12:
  animation_interval_id = m_animation_state->animation_interval_id;
  new_driving_animation_lengthc = vostok::animation::mixing::animation_interval::length(&new_driving_animation_length->m_animation_intervals[animation_interval_id]);
  new_driving_animation_lengtha = new_driving_animation_lengthc
                                / vostok::animation::mixing::animation_interval::length(&m_weight_root->m_animation_intervals[animation_interval_id]);
  if ( new_driving_animation_length->m_is_positive_event_direction == m_weight_root->m_is_positive_event_direction )
    v10 = *(float *)&clear_value;
  else
    v10 = -1.0;
  m_current_time_in_ms = (vostok::animation::mixing::animation_state *)new_time_driving_animation->m_current_time_in_ms;
  directional_time_scale_factor = v10 * new_driving_animation_lengtha;
  time_scale_calculator.__vftable = (vostok::animation::mixing::n_ary_tree_time_scale_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_time_scale_calculator::`vftable';
  memset((void *)&time_scale_calculator.m_animation, 0, 12);
  time_scale_calculator.m_current_time_in_ms = (const unsigned int)m_current_time_in_ms;
  time_scale_calculator.m_previous_animation_time = 0.0;
  time_scale_calculator.m_previous_time_in_ms = (const unsigned int)m_current_time_in_ms;
  memset(&time_scale_calculator.m_time_scale, 0, 12);
  if ( !new_driving_animation_length->m_operands_count )
  {
    new_driving_animation_lengthb = 0;
    v12 = 0;
LABEL_23:
    v13 = 0;
    goto LABEL_19;
  }
  v12 = new_driving_animation_length[1].__vftable;
  new_driving_animation_lengthb = v12;
  if ( !v12
    || !(*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v12->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
         + 3))(v12) )
  {
    goto LABEL_23;
  }
  v13 = 1;
  (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::mixing::n_ary_tree_time_scale_calculator *))v12->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
   + 2))(
    v12,
    &time_scale_calculator);
LABEL_19:
  if ( v12
    && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v12->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 3))(v12) )
  {
    m_time_scale = time_scale_calculator.m_time_scale;
  }
  else
  {
    m_time_scale = *(float *)&clear_value;
  }
  m_interpolator = time_scale_calculator.m_interpolator;
  new_time_driving_animation_target_time_scale = m_time_scale;
  if ( !v13 )
    m_interpolator = new_driving_animation_length->m_weight_interpolator;
  if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))m_interpolator->transition_time)(m_interpolator) <= 0.0 )
  {
    if ( m_time_scale != *(float *)&clear_value )
    {
      new_time_driving_animation->m_needed_buffer_size += 20;
      v19 = m_weight_root->m_operands_count == 0;
      v26 = &vostok::animation::mixing::n_ary_tree_target_time_scale_calculator::`vftable';
      if ( !v19
        && (v22 = m_weight_root[1].__vftable) != 0
        && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v22->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
            + 3))(v22) )
      {
        (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, void ***))v22->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
         + 2))(
          v22,
          &v26);
        v23 = (const vostok::math::float4x4 *)v27[0];
      }
      else
      {
        v23 = clear_value;
      }
      if ( new_time_driving_animation->m_equal
        && new_time_driving_animation_target_time_scale == (float)(*(float *)&v23 * directional_time_scale_factor)
        && (!v12
         || !(*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v12->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
              + 5))(v12)) )
      {
        result = 1;
        new_time_driving_animation->m_equal = 1;
        return result;
      }
      new_time_driving_animation->m_equal = 0;
      return 1;
    }
    return 0;
  }
  if ( !m_weight_root->m_operands_count
    || !(*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))m_weight_root[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
         + 3))(m_weight_root[1].__vftable) )
  {
    v16 = 0;
    goto LABEL_33;
  }
  v16 = m_weight_root[1].__vftable;
  if ( !v16 )
  {
LABEL_33:
    v17 = (vostok::animation::mixing::n_ary_tree_animation_node *)new_time_driving_animation;
    goto LABEL_34;
  }
  v17 = (vostok::animation::mixing::n_ary_tree_animation_node *)new_time_driving_animation;
  v18 = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, _DWORD *))*((_DWORD *)v16->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node + 2);
  v26 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'};
  v27[0] = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
  v27[1] = new_time_driving_animation;
  v27[2] = 0;
  v18(v16, v27);
LABEL_34:
  v19 = m_weight_root->m_operands_count == 0;
  v26 = &vostok::animation::mixing::n_ary_tree_target_time_scale_calculator::`vftable';
  if ( !v19
    && (v20 = m_weight_root[1].__vftable) != 0
    && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v20->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 3))(v20) )
  {
    (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, void ***))v20->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
     + 2))(
      v20,
      &v26);
    v21 = (const vostok::math::float4x4 *)v27[0];
  }
  else
  {
    v21 = clear_value;
  }
  if ( new_time_driving_animation_target_time_scale == (float)(*(float *)&v21 * directional_time_scale_factor)
    || new_driving_animation_lengthb
    && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))new_driving_animation_lengthb->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 5))(new_driving_animation_lengthb) )
  {
    return v16 != 0;
  }
  if ( !v16 )
    v17->m_weight_driving_animation = (vostok::animation::mixing::n_ary_tree_animation_node *const)((char *)v17->m_weight_driving_animation
                                                                                                  + 20);
  v17->m_weight_driving_animation = (vostok::animation::mixing::n_ary_tree_animation_node *const)((char *)v17->m_weight_driving_animation
                                                                                                + 40);
  LOBYTE(v17->m_weight_interpolator) = 0;
  return 1;
}
