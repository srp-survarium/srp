int __thiscall vostok::animation::animation_event_channels::get_channel_id(
        vostok::animation::animation_event_channels *this,
        char *name)
{
  unsigned int m_channels_count; // eax
  unsigned int m_internal_memory_position; // edx
  const vostok::animation::event_channel *v5; // edi
  char *v6; // esi
  const vostok::animation::event_channel *v7; // eax

  m_channels_count = this->m_channels_count;
  if ( this->m_channels_count == -1 )
    return -1;
  if ( !m_channels_count )
    return -1;
  m_internal_memory_position = this->m_internal_memory_position;
  v5 = (const vostok::animation::event_channel *)((char *)this + 44 * m_channels_count + m_internal_memory_position);
  v6 = (char *)this + m_internal_memory_position;
  v7 = stlp_std::priv::__find_if<vostok::animation::event_channel const *,vostok::animation::find_predicate>(
         (const vostok::animation::event_channel *)((char *)this + m_internal_memory_position),
         v5,
         name);
  if ( v7 == v5 )
    return -1;
  else
    return ((char *)v7 - v6) / 44;
}
