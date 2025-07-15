vostok::animation::mixing::base_lexeme *__thiscall vostok::animation::mixing::base_lexeme::cloned_in_buffer<vostok::animation::mixing::animation_lexeme>(
        vostok::animation::mixing::base_lexeme *this)
{
  vostok::mutable_buffer *m_buffer; // eax
  vostok::animation::mixing::animation_lexeme *m_data; // esi

  if ( this->m_cloned )
    return this - 15;
  m_buffer = this->m_buffer;
  m_buffer->m_size -= 132;
  m_data = (vostok::animation::mixing::animation_lexeme *)m_buffer->m_data;
  m_buffer->m_data += 132;
  if ( m_data )
    vostok::animation::mixing::animation_lexeme::animation_lexeme(
      m_data,
      (const vostok::animation::mixing::animation_lexeme *)&this[-15]);
  m_data->m_cloned = 1;
  return (vostok::animation::mixing::base_lexeme *)m_data;
}
