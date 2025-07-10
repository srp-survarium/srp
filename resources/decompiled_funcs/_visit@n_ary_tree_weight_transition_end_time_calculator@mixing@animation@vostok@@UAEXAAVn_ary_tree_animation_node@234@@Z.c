void __thiscall vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator *this,
        vostok::animation::mixing::n_ary_tree_animation_node *node)
{
  unsigned int m_operands_count; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v4; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *v5; // ebp
  unsigned int m_weight_transition_end_time_in_ms; // edi
  float m_min_weight; // xmm1_4
  float v8; // xmm0_4
  float min_weight; // [esp+10h] [ebp+4h]

  m_operands_count = node->m_operands_count;
  v4 = node + 1;
  v5 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)node + 4 * m_operands_count + 88);
  if ( m_operands_count
    && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v4->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 3))(v4->__vftable) )
  {
    v4 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)node + 92);
  }
  this->m_min_weight = float_max_16;
  for ( this->m_weight_transition_end_time_in_ms = -1;
        v4 != v5;
        v4 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v4 + 4) )
  {
    m_weight_transition_end_time_in_ms = this->m_weight_transition_end_time_in_ms;
    min_weight = this->m_min_weight;
    this->m_min_weight = float_max_16;
    this->m_weight_transition_end_time_in_ms = -1;
    (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator *))v4->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
     + 2))(
      v4->__vftable,
      this);
    m_min_weight = this->m_min_weight;
    if ( m_min_weight <= min_weight )
    {
      if ( m_min_weight == min_weight )
      {
        if ( min_weight == 0.0 )
          this->m_weight_transition_end_time_in_ms = m_weight_transition_end_time_in_ms;
        else
          this->m_weight_transition_end_time_in_ms = m_weight_transition_end_time_in_ms
                                                   + (this->m_weight_transition_end_time_in_ms < m_weight_transition_end_time_in_ms
                                                    ? this->m_weight_transition_end_time_in_ms
                                                    - m_weight_transition_end_time_in_ms
                                                    : 0);
      }
    }
    else
    {
      this->m_min_weight = min_weight;
      if ( min_weight == 0.0 )
        this->m_weight_transition_end_time_in_ms = m_weight_transition_end_time_in_ms;
      else
        this->m_weight_transition_end_time_in_ms = m_weight_transition_end_time_in_ms
                                                 + (this->m_weight_transition_end_time_in_ms < m_weight_transition_end_time_in_ms
                                                  ? this->m_weight_transition_end_time_in_ms
                                                  - m_weight_transition_end_time_in_ms
                                                  : 0);
    }
  }
  if ( this->m_weight_transition_end_time_in_ms == -1 )
  {
    this->m_event_type = 0;
  }
  else
  {
    v8 = this->m_min_weight;
    this->m_event_type = 256;
    if ( v8 == 0.0 )
      this->m_event_type = 258;
  }
}
