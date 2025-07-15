char __thiscall vostok::intrusive_list<vostok::sound::voice_bridge,vostok::sound::voice_bridge *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::contains_object(
        vostok::intrusive_list<vostok::sound::voice_bridge,vostok::sound::voice_bridge *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::voice_bridge *object)
{
  vostok::sound::voice_bridge *m_next; // [esp+0h] [ebp-18h]
  vostok::sound::voice_bridge *i; // [esp+10h] [ebp-8h]

  if ( !this->m_first )
    return 0;
  for ( i = this->m_first; i; i = m_next )
  {
    if ( i == object )
      return 1;
    if ( i->m_next )
      m_next = i->m_next;
    else
      m_next = 0;
  }
  return 0;
}
