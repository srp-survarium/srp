void __thiscall n_ary_tree_time_inverter::visit(
        n_ary_tree_time_inverter *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  unsigned int v3; // eax
  vostok::animation::mixing::n_ary_tree_base_node *m_from; // ecx

  v3 = this->m_current_time_in_ms - node->m_start_time_in_ms;
  m_from = node->m_from;
  node->m_start_time_in_ms = v3;
  m_from->accept(m_from, this);
  node->m_to->accept(node->m_to, this);
}
