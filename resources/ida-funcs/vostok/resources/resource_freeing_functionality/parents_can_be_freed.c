char __userpurge vostok::resources::resource_freeing_functionality::parents_can_be_freed@<al>(
        vostok::resources::resource_base *resource@<eax>,
        vostok::threading::simple_lock *a2@<ecx>,
        vostok::resources::resource_freeing_functionality *this,
        bool *can_try_free,
        bool *can_try_decrease_quality)
{
  bool *v5; // ebp
  vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *p_m_parent_resources; // esi
  vostok::threading::simple_lock *v7; // edi
  bool *v8; // eax
  const vostok::resources::resource_link *m_first; // eax
  const vostok::resources::resource_link *v10; // esi
  vostok::resources::resource_base *v11; // eax
  int v12; // eax
  const vostok::resources::resource_link *i; // eax
  bool v14; // zf
  bool parent_can_try_decrease_quality; // [esp+13h] [ebp-1h] BYREF

  v5 = can_try_free;
  p_m_parent_resources = &resource->m_parent_resources;
  if ( resource == (vostok::resources::resource_base *)-60 )
    v7 = 0;
  else
    v7 = &resource->m_parent_resources.vostok::threading::simple_lock;
  vostok::threading::simple_lock::lock(a2, v7);
  v8 = can_try_decrease_quality;
  *v5 = 1;
  *v8 = 1;
  m_first = p_m_parent_resources->m_first;
  if ( m_first && (m_first->resource->m_flags.m_flags & 0x800) != 0 )
    m_first = vostok::resources::resource_link_list_next_no_dying(m_first);
  v10 = m_first;
  if ( m_first )
  {
    while ( 1 )
    {
      v11 = v10->resource;
      LOBYTE(can_try_free) = 0;
      parent_can_try_decrease_quality = 0;
      if ( (v11->m_flags.m_flags & 1) != 0 && v11 )
        v12 = (int)(&v11[1].vostok::resources::resource_flags + 1);
      else
        v12 = (v11->m_flags.m_flags & 4) != 0 && v11 ? (int)&v11[1] : 0;
      if ( (*(_DWORD *)(v12 + 4) & 1) == 0
        || (vostok::resources::resource_freeing_functionality::can_be_freed(
              this,
              v10->resource,
              (bool *)&can_try_free,
              &parent_can_try_decrease_quality),
            !(_BYTE)can_try_free) )
      {
        *v5 = 0;
        if ( v10->quality_value == -1 )
          break;
      }
      for ( i = v10->next_link; i; i = i->next_link )
      {
        if ( (i->resource->m_flags.m_flags & 0x800) == 0 )
          break;
      }
      v10 = i;
      if ( !i )
        goto LABEL_22;
    }
    *can_try_decrease_quality = 0;
    v14 = v7->m_lock-- == 1;
    if ( v14 )
      _InterlockedExchange(&v7->m_thread_id, 0);
    return 0;
  }
  else
  {
LABEL_22:
    v14 = v7->m_lock-- == 1;
    if ( v14 )
      _InterlockedExchange(&v7->m_thread_id, 0);
    return 1;
  }
}
