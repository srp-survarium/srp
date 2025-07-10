void __thiscall vostok::animation::mixing::n_ary_tree_interpolator_selector::visit(
        vostok::animation::mixing::n_ary_tree_interpolator_selector *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  node->m_to->accept(node->m_to, this);
}
