vostok::animation::mixing::expression *__usercall vostok::animation::mixing::expression::operator=@<eax>(
        vostok::animation::mixing::expression *this@<esi>,
        const vostok::animation::mixing::expression *__that@<edi>)
{
  vostok::animation::mixing::binary_tree_base_node *m_object; // eax
  vostok::animation::mixing::binary_tree_base_node *v3; // ecx

  m_object = 0;
  if ( __that->m_node.m_object )
  {
    m_object = __that->m_node.m_object;
    ++__that->m_node.m_object->m_reference_count;
  }
  v3 = this->m_node.m_object;
  this->m_node.m_object = m_object;
  if ( v3 )
  {
    if ( v3->m_reference_count-- == 1 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v3->~vostok::animation::mixing::binary_tree_base_node)(
        v3,
        0);
  }
  this->m_lexeme = __that->m_lexeme;
  return this;
}
