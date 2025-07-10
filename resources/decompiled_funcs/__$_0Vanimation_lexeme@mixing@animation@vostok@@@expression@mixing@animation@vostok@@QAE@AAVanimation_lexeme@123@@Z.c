void __usercall vostok::animation::mixing::expression::expression(
        vostok::animation::mixing::expression *this@<edi>,
        vostok::animation::mixing::base_lexeme *lexeme@<eax>,
        vostok::animation::mixing::animation_lexeme *a3@<ecx>)
{
  vostok::animation::mixing::base_lexeme *v3; // esi
  vostok::animation::mixing::binary_tree_base_node *v4; // eax
  vostok::animation::mixing::binary_tree_base_node *m_object; // ecx

  this->m_node.m_object = 0;
  v3 = (vostok::animation::mixing::base_lexeme *)vostok::animation::mixing::animation_lexeme::cloned_in_buffer(
                                                   a3,
                                                   lexeme);
  v4 = 0;
  if ( v3 )
  {
    ++v3[2].m_buffer;
    v4 = (vostok::animation::mixing::binary_tree_base_node *)v3;
  }
  m_object = this->m_node.m_object;
  this->m_node.m_object = v4;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))m_object->~vostok::animation::mixing::binary_tree_base_node)(
        m_object,
        0);
  }
  if ( v3 )
    this->m_lexeme = v3 + 15;
  else
    this->m_lexeme = 0;
}
