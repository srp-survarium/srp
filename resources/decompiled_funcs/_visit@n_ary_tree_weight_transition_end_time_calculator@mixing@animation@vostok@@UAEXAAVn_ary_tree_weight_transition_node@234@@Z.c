void __thiscall vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  unsigned int m_start_time_in_ms; // ebp
  unsigned int v5; // esi
  float m_min_weight; // xmm0_4
  float value; // [esp+4h] [ebp-14h]

  node->m_from->accept(node->m_from, this);
  m_start_time_in_ms = node->m_start_time_in_ms;
  value = ((double (__thiscall *)(const vostok::animation::base_interpolator *))node->m_interpolator->transition_time)(node->m_interpolator)
        * 1000.0;
  v5 = m_start_time_in_ms + vostok::math::floor(value);
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
    this->m_weight_transition_end_time_in_ms = v5;
    this->m_min_weight = m_min_weight;
  }
}
