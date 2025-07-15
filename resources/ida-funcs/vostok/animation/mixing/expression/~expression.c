void __thiscall vostok::animation::mixing::expression::~expression(vostok::animation::mixing::expression *this)
{
  vostok::animation::mixing::binary_tree_base_node *m_object; // eax

  m_object = this->m_node.m_object;
  if ( this->m_node.m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))this->m_node.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        this->m_node.m_object,
        0);
  }
}
