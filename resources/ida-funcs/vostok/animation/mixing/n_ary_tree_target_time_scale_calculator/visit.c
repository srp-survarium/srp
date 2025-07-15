void __thiscall vostok::animation::mixing::n_ary_tree_target_time_scale_calculator::visit(
        vostok::animation::mixing::n_ary_tree_target_time_scale_calculator *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  this->m_result = node->m_time_scale;
}


void __thiscall vostok::animation::mixing::n_ary_tree_target_time_scale_calculator::visit(
        vostok::animation::mixing::n_ary_tree_interpolator_selector *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  node->m_to->accept(node->m_to, this);
}
