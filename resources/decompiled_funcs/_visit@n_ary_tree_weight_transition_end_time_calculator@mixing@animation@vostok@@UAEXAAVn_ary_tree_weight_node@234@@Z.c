void __thiscall vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator *this,
        vostok::animation::mixing::n_ary_tree_weight_node *node)
{
  this->m_min_weight = node->m_weight;
}
