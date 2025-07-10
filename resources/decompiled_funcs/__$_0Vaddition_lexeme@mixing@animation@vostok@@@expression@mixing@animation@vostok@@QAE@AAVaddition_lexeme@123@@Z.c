void __thiscall vostok::animation::mixing::expression::expression(
        vostok::animation::mixing::expression *this,
        vostok::animation::mixing::expression *lexeme)
{
  vostok::animation::mixing::expression *m_buffer; // esi
  vostok::animation::mixing::base_lexeme *m_lexeme; // eax
  vostok::animation::mixing::addition_lexeme_vtbl *v4; // eax
  vostok::animation::mixing::addition_lexeme_vtbl *m_object; // ecx

  lexeme->m_node.m_object = 0;
  if ( LOBYTE(this[4].m_node.m_object) )
  {
    m_buffer = this;
  }
  else
  {
    m_lexeme = this[3].m_lexeme;
    m_buffer = (vostok::animation::mixing::expression *)m_lexeme->m_buffer;
    *(_DWORD *)&m_lexeme->m_cloned -= 36;
    m_lexeme->m_buffer = (vostok::mutable_buffer *)&m_buffer[4].m_lexeme;
    if ( m_buffer )
      vostok::animation::mixing::addition_lexeme::addition_lexeme(
        (vostok::animation::mixing::addition_lexeme *)m_buffer,
        (const vostok::animation::mixing::addition_lexeme *)this);
    LOBYTE(m_buffer[4].m_node.m_object) = 1;
  }
  v4 = 0;
  if ( m_buffer )
  {
    ++m_buffer[2].m_node.m_object;
    v4 = (vostok::animation::mixing::addition_lexeme_vtbl *)m_buffer;
  }
  m_object = (vostok::animation::mixing::addition_lexeme_vtbl *)lexeme->m_node.m_object;
  lexeme->m_node.m_object = (vostok::animation::mixing::binary_tree_base_node *)v4;
  if ( m_object )
  {
    if ( m_object[1].accept-- == (void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, vostok::animation::mixing::binary_tree_visitor *))1 )
      (*(void (__thiscall **)(vostok::animation::mixing::addition_lexeme_vtbl *, _DWORD))m_object->~vostok::animation::mixing::binary_tree_base_node)(
        m_object,
        0);
  }
  if ( m_buffer )
    lexeme->m_lexeme = (vostok::animation::mixing::base_lexeme *)&m_buffer[3].m_lexeme;
  else
    lexeme->m_lexeme = 0;
}
