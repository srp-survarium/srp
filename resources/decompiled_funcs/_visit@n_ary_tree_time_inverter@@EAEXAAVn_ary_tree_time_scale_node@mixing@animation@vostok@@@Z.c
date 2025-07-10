void __thiscall n_ary_tree_time_inverter::visit(
        n_ary_tree_time_inverter *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  node->m_time_scale_start_time_in_ms = this->m_current_time_in_ms - node->m_time_scale_start_time_in_ms;
}
