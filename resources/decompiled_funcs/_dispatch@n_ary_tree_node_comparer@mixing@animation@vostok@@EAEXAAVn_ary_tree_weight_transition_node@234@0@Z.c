void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *left,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *right)
{
  left->m_from->accept(left->m_from, this, right->m_from);
  if ( this->result == equal )
    left->m_to->accept(left->m_to, this, right->m_to);
}
