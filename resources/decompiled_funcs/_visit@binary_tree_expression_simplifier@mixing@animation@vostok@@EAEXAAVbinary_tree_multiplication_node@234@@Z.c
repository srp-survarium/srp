void __thiscall vostok::animation::mixing::binary_tree_expression_simplifier::visit(
        vostok::animation::mixing::binary_tree_expression_simplifier *this,
        vostok::animation::mixing::binary_tree_multiplication_node *node)
{
  vostok::animation::mixing::binary_tree_expression_simplifier::process<vostok::animation::mixing::binary_tree_multiplication_node,stlp_std::multiplies<float>>(
    this,
    node);
}
