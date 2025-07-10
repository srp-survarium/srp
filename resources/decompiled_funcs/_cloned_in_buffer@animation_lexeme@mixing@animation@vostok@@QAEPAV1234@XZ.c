vostok::mutable_buffer *__usercall vostok::animation::mixing::animation_lexeme::cloned_in_buffer@<eax>(
        vostok::animation::mixing::animation_lexeme *this@<ecx>,
        vostok::animation::mixing::base_lexeme *a2@<esi>)
{
  vostok::animation::mixing::animation_lexeme *v3; // eax
  vostok::animation::mixing::animation_lexeme *v4; // ecx
  vostok::mutable_buffer *v5; // eax
  vostok::mutable_buffer *m_buffer; // ecx

  if ( a2[15].m_cloned )
    return (vostok::mutable_buffer *)a2;
  if ( !a2[16].m_buffer )
  {
    v3 = vostok::animation::mixing::base_lexeme::cloned_in_buffer<vostok::animation::mixing::animation_lexeme>(a2 + 15);
    v4 = 0;
    if ( v3 )
    {
      ++v3->m_reference_count;
      v4 = v3;
    }
    v5 = (vostok::mutable_buffer *)v4;
    m_buffer = a2[16].m_buffer;
    a2[16].m_buffer = v5;
    if ( m_buffer )
    {
      if ( m_buffer[2].m_data-- == (char *)1 )
        (*(void (__thiscall **)(vostok::mutable_buffer *, _DWORD))m_buffer->m_data)(m_buffer, 0);
    }
  }
  return a2[16].m_buffer;
}
