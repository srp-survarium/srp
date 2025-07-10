void __thiscall vostok::animation::mixing::n_ary_tree_destroyer::visit(
        vostok::animation::mixing::n_ary_tree_destroyer *this,
        vostok::animation::mixing::n_ary_tree_addition_node *node)
{
  vostok::animation::mixing::n_ary_tree_destroyer::propagate<vostok::animation::mixing::n_ary_tree_multiplication_node>(
    this,
    this,
    node);
}
