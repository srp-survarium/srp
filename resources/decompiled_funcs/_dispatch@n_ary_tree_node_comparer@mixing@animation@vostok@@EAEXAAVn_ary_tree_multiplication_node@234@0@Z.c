void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_multiplication_node *left,
        vostok::animation::mixing::n_ary_tree_multiplication_node *right)
{
  vostok::animation::mixing::n_ary_tree_node_comparer::propagate<vostok::animation::mixing::n_ary_tree_addition_node>(
    (vostok::animation::mixing::n_ary_tree_addition_node *)left,
    (vostok::animation::mixing::n_ary_tree_addition_node *)right,
    this);
}
