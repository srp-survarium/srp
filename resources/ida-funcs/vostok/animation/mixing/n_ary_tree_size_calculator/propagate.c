void __userpurge vostok::animation::mixing::n_ary_tree_size_calculator::propagate(
        vostok::animation::mixing::binary_tree_binary_operation_node *node@<esi>,
        vostok::animation::mixing::n_ary_tree_size_calculator *this)
{
  node->m_left.m_object->accept(node->m_left.m_object, this);
  node->m_right.m_object->accept(node->m_right.m_object, this);
}
