void __thiscall vostok::animation::mixing::binary_tree_initializer::visit(
        vostok::animation::mixing::binary_tree_initializer *this,
        vostok::animation::mixing::binary_tree_subtraction_node *node)
{
  node->m_left.m_object->accept(node->m_left.m_object, this);
  node->m_right.m_object->accept(node->m_right.m_object, this);
  node->m_next_weight = 0;
  node->m_same_weight = 0;
  node->m_next_unique_interpolator = 0;
}
