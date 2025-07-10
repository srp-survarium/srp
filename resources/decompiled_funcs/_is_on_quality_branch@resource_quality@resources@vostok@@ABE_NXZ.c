char __thiscall vostok::resources::resource_quality::is_on_quality_branch(vostok::resources::resource_quality *this)
{
  vostok::threading::simple_lock *p_m_children_resources; // ecx
  vostok::threading::simple_lock *v3; // edi
  vostok::resources::resource_link *m_first; // esi
  bool v5; // zf

  if ( (this->m_flags.m_flags & 0x100) != 0 )
    return 1;
  p_m_children_resources = (vostok::threading::simple_lock *)&this->m_children_resources;
  if ( this == (vostok::resources::resource_quality *)-36 )
    v3 = 0;
  else
    v3 = &this->m_children_resources.vostok::threading::simple_lock;
  vostok::threading::simple_lock::lock(p_m_children_resources, v3);
  m_first = this->m_parent_resources.m_first;
  if ( m_first )
  {
    while ( !vostok::resources::resource_quality::is_on_quality_branch(m_first->resource) )
    {
      m_first = m_first->next_link;
      if ( !m_first )
        goto LABEL_8;
    }
    v5 = v3->m_lock-- == 1;
    if ( v5 )
      _InterlockedExchange(&v3->m_thread_id, 0);
    return 1;
  }
LABEL_8:
  v5 = v3->m_lock-- == 1;
  if ( v5 )
    _InterlockedExchange(&v3->m_thread_id, 0);
  return 0;
}
