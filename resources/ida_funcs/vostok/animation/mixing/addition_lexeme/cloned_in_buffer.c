vostok::animation::mixing::addition_lexeme *__thiscall vostok::animation::mixing::addition_lexeme::cloned_in_buffer(
        vostok::animation::mixing::addition_lexeme *this)
{
  vostok::mutable_buffer *m_buffer; // eax
  vostok::animation::mixing::addition_lexeme *m_data; // esi

  if ( this->m_cloned )
    return this;
  m_buffer = this->m_buffer;
  m_buffer->m_size -= 36;
  m_data = (vostok::animation::mixing::addition_lexeme *)m_buffer->m_data;
  m_buffer->m_data += 36;
  if ( m_data )
    vostok::animation::mixing::addition_lexeme::addition_lexeme(m_data, this);
  m_data->m_cloned = 1;
  return m_data;
}
