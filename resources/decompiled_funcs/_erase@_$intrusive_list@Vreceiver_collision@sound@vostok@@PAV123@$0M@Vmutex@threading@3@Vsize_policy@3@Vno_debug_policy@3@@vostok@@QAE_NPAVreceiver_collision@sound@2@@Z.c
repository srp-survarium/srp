char __thiscall vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::receiver_collision *object)
{
  vostok::sound::receiver_collision *m_first; // [esp+0h] [ebp-2Ch]
  vostok::threading::mutex *v5; // [esp+14h] [ebp-18h]
  vostok::sound::receiver_collision *i; // [esp+24h] [ebp-8h]
  vostok::sound::receiver_collision *previous_i; // [esp+28h] [ebp-4h]

  if ( !this->m_first )
    return 0;
  if ( this )
    v5 = &this->vostok::threading::mutex;
  else
    v5 = 0;
  vostok::threading::mutex::lock(v5);
  previous_i = 0;
  for ( i = this->m_first; i && i != object; i = i->m_next )
    previous_i = i;
  if ( i == object )
  {
    --this->m_size;
    if ( previous_i )
      previous_i->m_next = i->m_next;
    else
      this->m_first = i->m_next;
    if ( !i->m_next )
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
