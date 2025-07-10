void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::binary_tree_multiplication_node *node)
{
  vostok::animation::mixing::n_ary_tree_comparer *m_comparer; // eax
  vostok::animation::mixing::n_ary_tree_comparer *v4; // eax

  m_comparer = this->m_comparer;
  if ( m_comparer )
    m_comparer->m_needed_buffer_size += 8;
  else
    this->m_size += 8;
  v4 = this->m_comparer;
  if ( v4 )
    v4->m_needed_buffer_size += 4;
  else
    this->m_size += 4;
  node->m_left.m_object->accept(node->m_left.m_object, this);
  node->m_right.m_object->accept(node->m_right.m_object, this);
}
