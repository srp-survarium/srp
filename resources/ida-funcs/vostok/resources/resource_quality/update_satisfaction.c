double __userpurge vostok::resources::resource_quality::update_satisfaction@<st0>(
        vostok::resources::resource_quality *this@<ecx>,
        double updated@<st0>,
        unsigned __int64 update_tick)
{
  vostok::resources::resource_quality *v3; // esi
  bool v5; // zf
  vostok::threading::simple_lock *v6; // edi
  vostok::resources::resource_quality *m_flags; // ecx
  const vostok::resources::resource_link *m_first; // eax
  const vostok::resources::resource_link *v9; // ebx
  unsigned int quality_value; // eax
  vostok::resources::resource_quality *resource; // ecx
  const vostok::resources::resource_link *i; // eax
  float min_satisfaction; // [esp+14h] [ebp-8h]
  float v14; // [esp+18h] [ebp-4h]

  v3 = this;
  if ( LODWORD(this->m_current_satisfaction_update_tick) == (_DWORD)update_tick )
  {
    this = (vostok::resources::resource_quality *)HIDWORD(this->m_current_satisfaction_update_tick);
    if ( this == (vostok::resources::resource_quality *)HIDWORD(update_tick) )
      return v3->m_current_satisfaction;
  }
  v5 = v3->m_quality_levels_count == 1;
  v3->m_current_satisfaction_update_tick = update_tick;
  if ( !v5 )
    return vostok::resources::resource_quality::update_satisfaction_for_resource_with_quality(this, v3, updated);
  if ( v3 == (vostok::resources::resource_quality *)-60 )
    v6 = 0;
  else
    v6 = &v3->m_parent_resources.vostok::threading::simple_lock;
  vostok::threading::simple_lock::lock((vostok::threading::simple_lock *)this, v6);
  m_first = v3->m_parent_resources.m_first;
  if ( m_first )
  {
    m_flags = (vostok::resources::resource_quality *)m_first->resource->m_flags.m_flags;
    if ( ((unsigned __int16)m_flags & 0x800) != 0 )
      m_first = vostok::resources::resource_link_list_next_no_dying(m_first);
  }
  v9 = m_first;
  min_satisfaction = 2048.0;
  if ( !m_first )
    goto LABEL_23;
  do
  {
    quality_value = v9->quality_value;
    resource = v9->resource;
    if ( quality_value == -1 )
      updated = vostok::resources::resource_quality::update_satisfaction(resource, update_tick);
    else
      updated = vostok::resources::resource_quality::satisfaction(resource, updated, quality_value, 0, 0);
    if ( min_satisfaction > updated )
    {
      v14 = updated;
      min_satisfaction = v14;
    }
    for ( i = v9->next_link; i; i = i->next_link )
    {
      m_flags = (vostok::resources::resource_quality *)i->resource->m_flags.m_flags;
      if ( ((unsigned __int16)m_flags & 0x800) == 0 )
        break;
    }
    v9 = i;
  }
  while ( i );
  if ( min_satisfaction >= 1024.0 )
LABEL_23:
    min_satisfaction = vostok::resources::resource_quality::calculate_best_satisfaction_based_on_size(m_flags, v3);
  v3->m_current_satisfaction = min_satisfaction;
  v5 = v6->m_lock-- == 1;
  if ( v5 )
    _InterlockedExchange(&v6->m_thread_id, 0);
  return min_satisfaction;
}
