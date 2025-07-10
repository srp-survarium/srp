void __thiscall vostok::animation::mixing::n_ary_tree_destroyer::visit(
        vostok::animation::mixing::n_ary_tree_destroyer *this,
        vostok::animation::mixing::n_ary_tree_weight_node *node)
{
  ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_weight_node *, _DWORD))node->~vostok::animation::mixing::n_ary_tree_base_node)(
    node,
    0);
}
