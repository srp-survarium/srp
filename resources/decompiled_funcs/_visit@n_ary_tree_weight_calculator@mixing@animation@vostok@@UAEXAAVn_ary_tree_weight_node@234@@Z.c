void __thiscall vostok::animation::mixing::n_ary_tree_weight_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this,
        vostok::animation::mixing::n_ary_tree_weight_node *node)
{
  double m_weight; // st7
  unsigned int m_current_time_in_ms; // edx

  m_weight = node->m_weight;
  this->m_result = 0;
  this->m_weight = m_weight;
  m_current_time_in_ms = this->m_current_time_in_ms;
  this->m_null_weight_found = this->m_weight == 0.0;
  this->m_weight_transition_ended_time_in_ms = m_current_time_in_ms;
}
