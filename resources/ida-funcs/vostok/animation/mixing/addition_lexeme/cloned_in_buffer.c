vostok::animation::mixing::addition_lexeme *__thiscall vostok::animation::mixing::addition_lexeme::cloned_in_buffer(
        vostok::animation::mixing::addition_lexeme *this)
{
  vostok::mutable_buffer *m_buffer; // eax
  char *m_data; // esi
  vostok::animation::mixing::binary_operation_lexeme *v5; // eax

  if ( this->m_cloned )
    return this;
  m_buffer = this->m_buffer;
  m_buffer->m_size -= 36;
  m_data = m_buffer->m_data;
  m_buffer->m_data += 36;
  if ( m_data )
  {
    vostok::animation::mixing::binary_tree_binary_operation_node::binary_tree_binary_operation_node(this, m_data);
    *(_DWORD *)m_data = &vostok::animation::mixing::binary_tree_addition_node::`vftable';
    if ( this )
      v5 = &this->vostok::animation::mixing::binary_operation_lexeme;
    else
      v5 = 0;
    *((_DWORD *)m_data + 7) = v5->m_buffer;
    m_data[32] = 0;
    *(_DWORD *)m_data = &vostok::animation::mixing::addition_lexeme::`vftable';
  }
  m_data[32] = 1;
  return (vostok::animation::mixing::addition_lexeme *)m_data;
}
