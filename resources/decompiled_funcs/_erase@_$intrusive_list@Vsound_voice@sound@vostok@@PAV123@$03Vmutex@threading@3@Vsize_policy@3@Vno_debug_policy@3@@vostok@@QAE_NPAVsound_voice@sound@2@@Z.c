char __thiscall vostok::intrusive_list<vostok::sound::sound_voice,vostok::sound::sound_voice *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<vostok::sound::sound_voice,vostok::sound::sound_voice *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::sound_voice *object)
{
  vostok::sound::sound_voice *m_first; // [esp+0h] [ebp-2Ch]
  vostok::threading::mutex *v5; // [esp+14h] [ebp-18h]
  vostok::sound::sound_voice *i; // [esp+24h] [ebp-8h]
  vostok::sound::sound_voice *previous_i; // [esp+28h] [ebp-4h]

  if ( !this->m_first )
    return 0;
  if ( this )
    v5 = &this->vostok::threading::mutex;
  else
    v5 = 0;
  vostok::threading::mutex::lock(v5);
  previous_i = 0;
  for ( i = this->m_first; i && i != object; i = i->m_next_for_active )
    previous_i = i;
  if ( i == object )
  {
    --this->m_size;
    if ( previous_i )
      previous_i->m_next_for_active = i->m_next_for_active;
    else
      this->m_first = i->m_next_for_active;
    if ( !i->m_next_for_active )
    {
      if ( previous_i )
        m_first = previous_i;
      else
        m_first = this->m_first;
      this->m_last = m_first;
    }
    vostok::threading::mutex::unlock(v5);
    return 1;
  }
  else
  {
    vostok::threading::mutex::unlock(v5);
    return 0;
  }
}
