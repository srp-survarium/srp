vostok::sound::sound_buffer *__thiscall vostok::sound::sound_buffer_factory::find_least_recently_used(
        vostok::sound::sound_buffer_factory *this)
{
  vostok::sound::sound_buffer *ptr; // [esp+8h] [ebp-4h]

  for ( ptr = this->m_lru_sound_buffers.m_first; ptr->m_reference_count; ptr = ptr->m_next )
    ;
  return ptr;
}
