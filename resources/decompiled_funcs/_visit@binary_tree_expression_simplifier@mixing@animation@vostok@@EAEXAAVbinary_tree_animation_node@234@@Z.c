void __thiscall vostok::animation::mixing::binary_tree_expression_simplifier::visit(
        vostok::animation::mixing::binary_tree_expression_simplifier *this,
        vostok::animation::mixing::binary_tree_animation_node *node)
{
  vostok::animation::mixing::binary_tree_animation_node *v2; // eax
  vostok::animation::mixing::binary_tree_base_node *v3; // edx
  vostok::animation::mixing::binary_tree_base_node *m_object; // eax

  v2 = 0;
  if ( node )
  {
    ++node->m_reference_count;
    v2 = node;
  }
  v3 = v2;
  m_object = this->m_result.m_object;
  this->m_result.m_object = v3;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))m_object->~vostok::animation::mixing::binary_tree_base_node)(
        m_object,
        0);
  }
}
