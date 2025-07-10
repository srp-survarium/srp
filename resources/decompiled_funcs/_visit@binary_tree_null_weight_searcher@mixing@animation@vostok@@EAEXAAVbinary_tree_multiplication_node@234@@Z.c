void __thiscall vostok::animation::mixing::binary_tree_null_weight_searcher::visit(
        vostok::animation::mixing::binary_tree_null_weight_searcher *this,
        vostok::animation::mixing::binary_tree_multiplication_node *node)
{
  node->m_left.m_object->accept(node->m_left.m_object, this);
  node->m_right.m_object->accept(node->m_right.m_object, this);
}
