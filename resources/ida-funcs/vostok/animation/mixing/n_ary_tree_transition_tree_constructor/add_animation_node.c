vostok::animation::mixing::n_ary_tree_animation_node *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation_node@<eax>(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this@<esi>,
        const vostok::animation::mixing::animation_state *previous_animation_state@<edi>,
        vostok::animation::mixing::n_ary_tree_animation_node *new_animation,
        unsigned int animation_interval_id,
        float animation_interval_time,
        bool is_new_animation)
{
  unsigned int m_current_time_in_ms; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v7; // ecx
  unsigned int m_operands_count; // edx
  vostok::animation::mixing::animation_state *m_new_animation_state; // eax
  float m_weight; // xmm0_4
  unsigned int v11; // edx
  float v12; // xmm1_4
  float animation_time_threshold; // xmm2_4
  vostok::animation::mixing::n_ary_tree_weight_calculator v15; // [esp+4h] [ebp-2Ch] BYREF
  vostok::animation::mixing::n_ary_tree_animation_node *v16; // [esp+28h] [ebp-8h]
  int v17; // [esp+2Ch] [ebp-4h]
  vostok::animation::mixing::n_ary_tree_animation_node *v18; // [esp+44h] [ebp+14h]

  *this->m_new_animation_event++ = this->m_new_animation_state;
  v17 = 0;
  if ( is_new_animation )
  {
    v17 = 129;
  }
  else if ( previous_animation_state && !previous_animation_state->are_there_any_weight_transitions )
  {
    v17 = 128;
  }
  m_current_time_in_ms = this->m_current_time_in_ms;
  v15.__vftable = (vostok::animation::mixing::n_ary_tree_weight_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_calculator::`vftable';
  memset((void *)&v15.m_animation, 0, 12);
  v15.m_current_time_in_ms = m_current_time_in_ms;
  memset(&v15.m_weight, 0, 13);
  vostok::animation::mixing::n_ary_tree_weight_calculator::visit(&v15, new_animation);
  v7 = new_animation;
  m_operands_count = new_animation->m_operands_count;
  new_animation->m_animation_state = this->m_new_animation_state;
  v16 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)new_animation + 4 * m_operands_count + 88);
  v18 = new_animation + 1;
  if ( &new_animation[1] != v16 )
  {
    do
    {
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v18->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
       + 3))(v18->__vftable);
      v18 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v18 + 4);
    }
    while ( v18 != v16 );
    v7 = new_animation;
  }
  if ( !previous_animation_state
    || previous_animation_state->event_iterator.m_animation_node->m_is_transitting_to_zero
    && !v7->m_is_transitting_to_zero
    && previous_animation_state->is_freezed )
  {
    m_new_animation_state = this->m_new_animation_state;
    if ( m_new_animation_state )
    {
      m_weight = v15.m_weight;
      v11 = animation_interval_id;
      m_new_animation_state->bone_matrices_computer.previous_object_movement.rotation.z = animation_interval_time;
      m_new_animation_state->bone_matrices_computer.previous_object_movement.rotation.x = 0.0;
      m_new_animation_state->bone_matrices_computer.previous_object_movement.rotation.w = 0.0;
      goto LABEL_17;
    }
  }
  else
  {
    m_new_animation_state = this->m_new_animation_state;
    if ( m_new_animation_state )
    {
      m_weight = v15.m_weight;
      v11 = previous_animation_state->animation_interval_id;
      v12 = previous_animation_state->animation_interval_time;
      animation_time_threshold = previous_animation_state->animation_time_threshold;
      LODWORD(m_new_animation_state->bone_matrices_computer.previous_object_movement.rotation.x) = previous_animation_state;
      m_new_animation_state->bone_matrices_computer.previous_object_movement.rotation.z = v12;
      m_new_animation_state->bone_matrices_computer.previous_object_movement.rotation.w = animation_time_threshold;
LABEL_17:
      LODWORD(m_new_animation_state->bone_matrices_computer.previous_object_movement.rotation.y) = v11;
      LOWORD(m_new_animation_state->bone_matrices_computer.previous_object_movement.translation.elements[1]) = v17;
      m_new_animation_state->bone_matrices_computer.previous_object_movement.translation.x = m_weight;
    }
  }
  ++this->m_new_animation_state;
  return v7;
}
