void __thiscall vostok::animation::mixing::n_ary_tree_cloner::visit(
        vostok::animation::mixing::n_ary_tree_cloner *this,
        vostok::animation::mixing::n_ary_tree_addition_node *node)
{
  vostok::animation::mixing::n_ary_tree_cloner::propagate<vostok::animation::mixing::n_ary_tree_addition_node>(
    this,
    node);
}
