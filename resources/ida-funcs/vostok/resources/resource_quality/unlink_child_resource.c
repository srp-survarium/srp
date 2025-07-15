void __thiscall vostok::resources::resource_quality::unlink_child_resource(
        vostok::resources::resource_quality *this,
        vostok::resources::resource_base *child)
{
  vostok::threading::simple_lock *v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // edi
  vostok::threading::simple_lock *v6; // eax
  vostok::resources::resource_link *m_first; // eax
  unsigned int quality_value; // ecx
  vostok::threading::simple_lock::mutex_raii v9; // [esp+4h] [ebp-8h] BYREF

  vostok::resources::resource_children::unlink_child_resource(this, child);
  if ( this->m_quality_levels_count == 1 )
  {
    v4 = 0;
  }
  else
  {
    v5 = -1;
    if ( this == (vostok::resources::resource_quality *)-36 )
      v6 = 0;
    else
      v6 = &this->m_children_resources.vostok::threading::simple_lock;
    v9.lock = v6;
    vostok::threading::simple_lock::lock(v3, (int)v6);
    m_first = this->m_children_resources.m_first;
    v9.locked = 1;
    while ( m_first )
    {
      quality_value = m_first->quality_value;
      if ( quality_value != -1 )
        v5 = quality_value + (v5 < quality_value ? v5 - quality_value : 0);
      m_first = m_first->next_link;
    }
    vostok::threading::simple_lock::mutex_raii::~mutex_raii(&v9);
    v4 = v5;
  }
  this->m_current_quality_level = v4;
}
