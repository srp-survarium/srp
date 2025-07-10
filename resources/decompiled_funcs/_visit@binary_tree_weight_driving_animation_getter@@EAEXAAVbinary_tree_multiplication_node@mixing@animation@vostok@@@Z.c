void __thiscall binary_tree_weight_driving_animation_getter::visit(
        binary_tree_weight_driving_animation_getter *this,
        vostok::animation::mixing::binary_tree_addition_node *node)
{
  node->m_left.m_object->accept(node->m_left.m_object, this);
  node->m_right.m_object->accept(node->m_right.m_object, this);
}
