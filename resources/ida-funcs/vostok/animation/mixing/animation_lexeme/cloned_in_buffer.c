vostok::animation::mixing::animation_lexeme *__thiscall vostok::animation::mixing::animation_lexeme::cloned_in_buffer(
        vostok::animation::mixing::animation_lexeme *this,
        vostok::animation::mixing::animation_lexeme *a2)
{
  vostok::animation::mixing::animation_lexeme *m_data; // esi
  vostok::mutable_buffer *m_buffer; // eax
  vostok::animation::mixing::animation_lexeme *v5; // eax
  vostok::animation::mixing::animation_lexeme *m_object; // ecx

  if ( a2->m_cloned )
    return a2;
  if ( !a2->m_cloned_instance.m_object )
  {
    if ( a2->m_cloned )
    {
      m_data = a2;
    }
    else
    {
      m_buffer = a2->vostok::animation::mixing::base_lexeme::m_buffer;
      m_data = (vostok::animation::mixing::animation_lexeme *)m_buffer->m_data;
      m_buffer->m_size -= 132;
      m_buffer->m_data = (char *)&m_data[1];
      if ( m_data )
        vostok::animation::mixing::animation_lexeme::animation_lexeme(m_data, a2);
      m_data->m_cloned = 1;
    }
    v5 = 0;
    if ( m_data )
    {
      ++m_data->m_reference_count;
      v5 = m_data;
    }
    m_object = a2->m_cloned_instance.m_object;
    a2->m_cloned_instance.m_object = v5;
    if ( m_object )
    {
      if ( m_object->m_reference_count-- == 1 )
        ((void (__thiscall *)(vostok::animation::mixing::animation_lexeme *, _DWORD))m_object->~vostok::animation::mixing::binary_tree_base_node)(
          m_object,
          0);
    }
  }
  return a2->m_cloned_instance.m_object;
}
