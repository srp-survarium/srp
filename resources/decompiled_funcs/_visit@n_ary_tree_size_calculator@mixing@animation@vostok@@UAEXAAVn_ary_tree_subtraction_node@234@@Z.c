void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::n_ary_tree_subtraction_node *node)
{
  vostok::animation::mixing::n_ary_tree_size_calculator::propagate<vostok::animation::mixing::n_ary_tree_multiplication_node>(
    (vostok::animation::mixing::n_ary_tree_size_calculator *)((char *)this - 4),
    (vostok::animation::mixing::n_ary_tree_addition_node *)node);
}
