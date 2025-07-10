char __thiscall vostok::intrusive_list<vostok::sound::proxy_statistic,vostok::sound::proxy_statistic *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<vostok::sound::proxy_statistic,vostok::sound::proxy_statistic *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::proxy_statistic *object)
{
  vostok::sound::proxy_statistic *m_first; // [esp+0h] [ebp-24h]
  vostok::sound::proxy_statistic *i; // [esp+1Ch] [ebp-8h]
  vostok::sound::proxy_statistic *previous_i; // [esp+20h] [ebp-4h]

  if ( !this->m_first )
    return 0;
  previous_i = 0;
  for ( i = this->m_first; i && i != object; i = i->next )
    previous_i = i;
  if ( i != object )
    return 0;
  --this->m_size;
  if ( previous_i )
    previous_i->next = i->next;
  else
    this->m_first = i->next;
  if ( !i->next )
  {
    if ( previous_i )
      m_first = previous_i;
    else
      m_first = this->m_first;
    this->m_last = m_first;
  }
  return 1;
}
