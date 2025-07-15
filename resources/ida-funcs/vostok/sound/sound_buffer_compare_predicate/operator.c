bool __thiscall vostok::sound::sound_buffer_compare_predicate::operator()(
        vostok::sound::sound_buffer_compare_predicate *this,
        const vostok::sound::sound_buffer *lhs,
        const vostok::sound::sound_buffer *rhs)
{
  if ( lhs->m_encoded_sound.m_object < rhs->m_encoded_sound.m_object )
    return 1;
  if ( rhs->m_encoded_sound.m_object >= lhs->m_encoded_sound.m_object )
    return lhs->m_cached_offset < rhs->m_cached_offset;
  return 0;
}
