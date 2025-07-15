void __thiscall vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator *this,
        vostok::animation::mixing::n_ary_tree_animation_node *node)
{
  unsigned int m_operands_count; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v3; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *v4; // ebx
  float m_min_weight; // xmm0_4
  unsigned int m_weight_transition_end_time_in_ms; // ebx
  float v8; // xmm1_4
  unsigned __int16 v9; // ax
  float v10; // xmm0_4
  vostok::animation::mixing::n_ary_tree_animation_node *v11; // [esp+Ch] [ebp-4h]

  m_operands_count = node->m_operands_count;
  v3 = node + 1;
  v4 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)node + 4 * m_operands_count + 88);
  v11 = v4;
  if ( m_operands_count
    && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v3->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 3))(v3->__vftable) )
  {
    v3 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)node + 92);
  }
  this->m_weight_transition_end_time_in_ms = -1;
  this->m_min_weight = float_max_32;
  if ( v3 != v4 )
  {
    while ( 1 )
    {
      m_min_weight = this->m_min_weight;
      m_weight_transition_end_time_in_ms = this->m_weight_transition_end_time_in_ms;
      this->m_weight_transition_end_time_in_ms = -1;
      this->m_min_weight = float_max_32;
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator *))v3->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
       + 2))(
        v3->__vftable,
        this);
      v8 = this->m_min_weight;
      if ( v8 > m_min_weight )
        break;
      if ( v8 == m_min_weight )
        goto LABEL_8;
LABEL_11:
      v3 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v3 + 4);
      if ( v3 == v11 )
        goto LABEL_12;
    }
    this->m_min_weight = m_min_weight;
LABEL_8:
    if ( m_min_weight == 0.0 )
      this->m_weight_transition_end_time_in_ms = m_weight_transition_end_time_in_ms;
    else
      this->m_weight_transition_end_time_in_ms = m_weight_transition_end_time_in_ms
                                               + (this->m_weight_transition_end_time_in_ms < m_weight_transition_end_time_in_ms
                                                ? this->m_weight_transition_end_time_in_ms
                                                - m_weight_transition_end_time_in_ms
                                                : 0);
    goto LABEL_11;
  }
LABEL_12:
  if ( this->m_weight_transition_end_time_in_ms == -1 )
  {
    v9 = 0;
  }
  else
  {
    v10 = this->m_min_weight;
    this->m_event_type = 256;
    if ( v10 != 0.0 )
      return;
    v9 = 258;
  }
  this->m_event_type = v9;
}


void __thiscall vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator *this,
        vostok::animation::mixing::n_ary_tree_weight_node *node)
{
  this->m_min_weight = node->m_weight;
}


void __thiscall vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  unsigned int m_start_time_in_ms; // ebp
  unsigned int v5; // edi
  float m_min_weight; // xmm0_4
  float v7; // [esp+4h] [ebp-14h]

  node->m_from->accept(node->m_from, this);
  m_start_time_in_ms = node->m_start_time_in_ms;
  v7 = ((double (__thiscall *)(const vostok::animation::base_interpolator *))node->m_interpolator->transition_time)(node->m_interpolator)
     * 1000.0;
  v5 = m_start_time_in_ms + vostok::math::floor(v7);
  if ( node->m_to->is_transition(node->m_to) )
    m_min_weight = this->m_min_weight;
  else
    m_min_weight = *(float *)&node->m_to[2].__vftable;
  if ( this->m_min_weight == m_min_weight )
  {
    this->m_weight_transition_end_time_in_ms += v5 < this->m_weight_transition_end_time_in_ms
                                              ? v5 - this->m_weight_transition_end_time_in_ms
                                              : 0;
  }
  else
  {
    this->m_min_weight = m_min_weight;
    this->m_weight_transition_end_time_in_ms = v5;
  }
}
