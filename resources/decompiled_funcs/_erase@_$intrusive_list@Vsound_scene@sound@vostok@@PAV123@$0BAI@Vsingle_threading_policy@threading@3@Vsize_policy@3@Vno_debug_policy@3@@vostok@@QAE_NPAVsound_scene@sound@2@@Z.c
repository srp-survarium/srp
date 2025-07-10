char __thiscall vostok::intrusive_list<vostok::sound::sound_scene,vostok::sound::sound_scene *,264,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<vostok::sound::sound_scene,vostok::sound::sound_scene *,264,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::sound_scene *object)
{
  vostok::sound::sound_scene *m_first; // [esp+0h] [ebp-24h]
  vostok::sound::sound_scene *i; // [esp+1Ch] [ebp-8h]
  vostok::sound::sound_scene *previous_i; // [esp+20h] [ebp-4h]

  if ( !this->m_first )
    return 0;
  previous_i = 0;
  for ( i = this->m_first; i && i != object; i = i->m_next )
    previous_i = i;
  if ( i != object )
    return 0;
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
  return 1;
}
