void __thiscall vostok::animation::mixing::n_ary_tree_destroyer::visit(
        vostok::animation::mixing::n_ary_tree_destroyer *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  node->m_from->accept(node->m_from, this);
  node->m_to->accept(node->m_to, this);
  ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_weight_transition_node *, _DWORD))node->~vostok::animation::mixing::n_ary_tree_base_node)(
    node,
    0);
}
