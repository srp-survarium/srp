void __thiscall vostok::animation::mixing::n_ary_tree_target_time_scale_calculator::visit(
        vostok::animation::mixing::n_ary_tree_target_time_scale_calculator *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  this->m_result = node->m_time_scale;
}
