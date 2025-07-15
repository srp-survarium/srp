unsigned int __thiscall vostok::resources::resource_quality::child_quality(
        vostok::resources::resource_quality *this,
        vostok::resources::resource_base *parent)
{
  vostok::threading::simple_lock *v3; // esi
  vostok::resources::resource_link *m_first; // eax
  bool v5; // zf
  unsigned int result; // eax

  if ( this == (vostok::resources::resource_quality *)-36 )
    v3 = 0;
  else
    v3 = &this->m_children_resources.vostok::threading::simple_lock;
  vostok::threading::simple_lock::lock((vostok::threading::simple_lock *)this, v3);
  m_first = this->m_children_resources.m_first;
  if ( m_first )
  {
    while ( m_first->resource != parent )
    {
      m_first = m_first->next_link;
      if ( !m_first )
        goto LABEL_7;
    }
    result = m_first->quality_value;
    v5 = v3->m_lock-- == 1;
    if ( v5 )
      _InterlockedExchange(&v3->m_thread_id, 0);
  }
  else
  {
LABEL_7:
    v5 = v3->m_lock-- == 1;
    if ( v5 )
      _InterlockedExchange(&v3->m_thread_id, 0);
    return 0;
  }
  return result;
}
