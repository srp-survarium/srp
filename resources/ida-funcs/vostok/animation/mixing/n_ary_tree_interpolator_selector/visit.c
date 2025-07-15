void __thiscall vostok::animation::mixing::n_ary_tree_interpolator_selector::visit(
        vostok::animation::mixing::n_ary_tree_interpolator_selector *this,
        vostok::animation::mixing::n_ary_tree_weight_node *node)
{
  this->m_result = node->m_interpolator;
}
