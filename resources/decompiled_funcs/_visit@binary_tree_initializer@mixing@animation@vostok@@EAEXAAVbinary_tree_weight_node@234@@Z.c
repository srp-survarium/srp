void __thiscall vostok::animation::mixing::binary_tree_initializer::visit(
        vostok::animation::mixing::binary_tree_initializer *this,
        vostok::animation::mixing::binary_tree_weight_node *node)
{
  node->m_next_weight = 0;
  node->m_same_weight = 0;
  node->m_next_unique_interpolator = 0;
}
