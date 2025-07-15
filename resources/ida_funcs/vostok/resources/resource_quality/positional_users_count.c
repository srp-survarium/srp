unsigned int __thiscall vostok::resources::resource_quality::positional_users_count(
        vostok::resources::resource_quality *this,
        const vostok::resources::resource_base *resource_user)
{
  vostok::resources::resource_quality *v2; // ebx
  vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *p_m_parent_resources; // esi
  vostok::threading::simple_lock *v5; // ebp
  const vostok::resources::resource_link *m_first; // eax
  const vostok::resources::resource_link *v7; // esi
  int v8; // edi
  const vostok::resources::resource_link *i; // eax

  v2 = this;
  if ( resource_user )
  {
    this = (vostok::resources::resource_quality *)resource_user->m_flags.m_flags;
    if ( ((unsigned __int8)this & 8) != 0 )
      return 1;
    p_m_parent_resources = &resource_user->m_parent_resources;
  }
  else
  {
    p_m_parent_resources = &this->m_parent_resources;
  }
  if ( p_m_parent_resources )
    v5 = &p_m_parent_resources->vostok::threading::simple_lock;
  else
    v5 = 0;
  vostok::threading::simple_lock::lock((vostok::threading::simple_lock *)this, v5);
  m_first = p_m_parent_resources->m_first;
  if ( m_first && (m_first->resource->m_flags.m_flags & 0x800) != 0 )
    m_first = vostok::resources::resource_link_list_next_no_dying(m_first);
  v7 = m_first;
  v8 = 0;
  if ( m_first )
  {
    do
    {
      v8 += vostok::resources::resource_quality::positional_users_count(v2, v7->resource);
      for ( i = v7->next_link; i; i = i->next_link )
      {
        if ( (i->resource->m_flags.m_flags & 0x800) == 0 )
          break;
      }
      v7 = i;
    }
    while ( i );
  }
  if ( v5->m_lock-- == 1 )
    _InterlockedExchange(&v5->m_thread_id, 0);
  return v8;
}
