vostok::sound::sound_buffer *__thiscall vostok::intrusive_list<vostok::sound::sound_buffer,vostok::sound::sound_buffer *,16,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front(
        vostok::intrusive_list<vostok::sound::sound_buffer,vostok::sound::sound_buffer *,16,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this)
{
  vostok::sound::sound_buffer *result; // [esp+14h] [ebp-8h]

  if ( !this->m_first )
    return 0;
  --this->m_size;
  result = this->m_first;
  this->m_first = result->m_next;
  if ( !this->m_first )
    this->m_last = 0;
  result->m_next = 0;
  return result;
}
