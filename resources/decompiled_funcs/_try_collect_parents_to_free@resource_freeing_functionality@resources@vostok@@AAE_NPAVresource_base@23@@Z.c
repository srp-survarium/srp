char __userpurge vostok::resources::resource_freeing_functionality::try_collect_parents_to_free@<al>(
        vostok::resources::resource_base *resource@<eax>,
        vostok::threading::simple_lock *a2@<ecx>,
        vostok::resources::resource_freeing_functionality *this)
{
  vostok::threading::simple_lock *v4; // edi
  vostok::resources::resource_link *m_first; // eax
  vostok::resources::resource_link *v6; // esi
  vostok::resources::resource_link *i; // eax
  bool v8; // zf

  if ( !resource->m_parent_resources.m_first )
    return 1;
  v4 = &resource->m_parent_resources.vostok::threading::simple_lock;
  vostok::threading::simple_lock::lock(a2, &resource->m_parent_resources.vostok::threading::simple_lock);
  m_first = resource->m_parent_resources.m_first;
  if ( m_first && (m_first->resource->m_flags.m_flags & 0x800) != 0 )
    m_first = vostok::resources::resource_link_list_next_no_dying(m_first);
  v6 = m_first;
  if ( !m_first )
  {
LABEL_11:
    v8 = v4->m_lock-- == 1;
    if ( v8 )
      _InterlockedExchange(&v4->m_thread_id, 0);
    return 1;
  }
  while ( vostok::resources::resource_freeing_functionality::try_collect_to_free_resource(this, v6->resource) )
  {
    for ( i = v6->next_link; i; i = i->next_link )
    {
      if ( (i->resource->m_flags.m_flags & 0x800) == 0 )
        break;
    }
    v6 = i;
    if ( !i )
      goto LABEL_11;
  }
  v8 = v4->m_lock-- == 1;
  if ( v8 )
    _InterlockedExchange(&v4->m_thread_id, 0);
  return 0;
}
