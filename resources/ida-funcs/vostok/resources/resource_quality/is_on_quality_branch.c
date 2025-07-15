char __thiscall vostok::resources::resource_quality::is_on_quality_branch(vostok::resources::resource_quality *this)
{
  vostok::threading::simple_lock *v3; // eax
  vostok::resources::resource_link *m_first; // esi
  char v5; // bl
  vostok::threading::simple_lock::mutex_raii v6; // [esp+8h] [ebp-8h] BYREF

  if ( (this->m_flags.m_flags & 0x100) != 0 )
    return 1;
  if ( this == (vostok::resources::resource_quality *)-36 )
    v3 = 0;
  else
    v3 = &this->m_children_resources.vostok::threading::simple_lock;
  v6.lock = v3;
  vostok::threading::simple_lock::lock((vostok::threading::simple_lock *)this, (int)v3);
  m_first = this->m_parent_resources.m_first;
  v6.locked = 1;
  while ( 1 )
  {
    if ( !m_first )
    {
      v5 = 0;
      goto LABEL_12;
    }
    if ( vostok::resources::resource_quality::is_on_quality_branch(m_first->resource) )
      break;
    m_first = m_first->next_link;
  }
  v5 = 1;
LABEL_12:
  vostok::threading::simple_lock::mutex_raii::~mutex_raii(&v6);
  return v5;
}
