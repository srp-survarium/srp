char __thiscall vostok::intrusive_list<vostok::sound::new_sound_propagator,vostok::sound::new_sound_propagator *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<vostok::sound::new_sound_propagator,vostok::sound::new_sound_propagator *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::new_sound_propagator *object)
{
  vostok::sound::new_sound_propagator *m_first; // eax
  vostok::sound::new_sound_propagator *v4; // edx
  vostok::sound::new_sound_propagator *m_next_for_proxies; // esi

  m_first = this->m_first;
  if ( !m_first )
    return 0;
  v4 = 0;
  while ( m_first != object )
  {
    v4 = m_first;
    m_first = m_first->m_next_for_proxies;
    if ( !m_first )
    {
      if ( object )
        return 0;
      break;
    }
  }
  --this->m_size;
  m_next_for_proxies = m_first->m_next_for_proxies;
  if ( v4 )
    v4->m_next_for_proxies = m_next_for_proxies;
  else
    this->m_first = m_next_for_proxies;
  if ( !m_first->m_next_for_proxies )
  {
    if ( !v4 )
      v4 = this->m_first;
    this->m_last = v4;
  }
  return 1;
}
