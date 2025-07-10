void __thiscall vostok::animation::mixing::binary_tree_expression_simplifier::visit(
        vostok::animation::mixing::binary_tree_expression_simplifier *this,
        vostok::animation::mixing::binary_tree_subtraction_node *node)
{
  vostok::animation::mixing::binary_tree_expression_simplifier::process<vostok::animation::mixing::binary_tree_subtraction_node,stlp_std::minus<float>>(
    this,
    node);
}
