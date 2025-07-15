double __userpurge vostok::resources::resource_quality::satisfaction@<st0>(
        vostok::resources::resource_quality *this@<ecx>,
        double result@<st0>,
        unsigned int quality_level,
        const vostok::resources::resource_base *resource_user,
        unsigned int positional_users_count)
{
  vostok::resources::cook_base *cook; // eax
  vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *p_m_parent_resources; // edi
  vostok::threading::simple_lock *v8; // ebp
  vostok::resources::resource_quality *m_flags; // ecx
  const vostok::resources::resource_link *m_first; // eax
  const vostok::resources::resource_link *v11; // edi
  double v13; // st7
  const vostok::resources::resource_link *i; // eax
  float parent_worst_satisfaction; // [esp+14h] [ebp+4h]
  float min_satisfaction; // [esp+18h] [ebp+8h]

  if ( (this->m_flags.m_flags & 2) != 0 && this )
  {
    ((void (__thiscall *)(vostok::resources::resource_quality *, unsigned int))this->__vftable[1].~vostok::resources::resource_quality)(
      this,
      quality_level);
    return result;
  }
  if ( resource_user )
  {
    if ( (resource_user->m_flags.m_flags & 8) != 0 )
    {
      cook = vostok::resources::resources_manager::find_cook(this->m_class_id);
      cook->satisfaction_with(
        cook,
        quality_level,
        (const vostok::math::float4x4 *)&resource_user[1].m_children_resources.m_last,
        positional_users_count);
      return result;
    }
    p_m_parent_resources = &resource_user->m_parent_resources;
  }
  else
  {
    positional_users_count = vostok::resources::resource_quality::positional_users_count(this, 0);
    p_m_parent_resources = &this->m_parent_resources;
  }
  if ( p_m_parent_resources )
    v8 = &p_m_parent_resources->vostok::threading::simple_lock;
  else
    v8 = 0;
  vostok::threading::simple_lock::lock((vostok::threading::simple_lock *)this, v8);
  m_first = p_m_parent_resources->m_first;
  if ( m_first )
  {
    m_flags = (vostok::resources::resource_quality *)m_first->resource->m_flags.m_flags;
    if ( ((unsigned __int16)m_flags & 0x800) != 0 )
      m_first = vostok::resources::resource_link_list_next_no_dying(m_first);
  }
  v11 = m_first;
  min_satisfaction = 2048.0;
  if ( !m_first )
    goto LABEL_23;
  do
  {
    v13 = vostok::resources::resource_quality::satisfaction(this, quality_level, v11->resource, positional_users_count);
    if ( v13 <= min_satisfaction )
    {
      parent_worst_satisfaction = v13;
      min_satisfaction = parent_worst_satisfaction;
    }
    for ( i = v11->next_link; i; i = i->next_link )
    {
      m_flags = (vostok::resources::resource_quality *)i->resource->m_flags.m_flags;
      if ( ((unsigned __int16)m_flags & 0x800) == 0 )
        break;
    }
    v11 = i;
  }
  while ( i );
  if ( min_satisfaction < 1024.0 )
    result = min_satisfaction;
  else
LABEL_23:
    result = vostok::resources::resource_quality::calculate_best_satisfaction_based_on_size(m_flags, this);
  if ( v8->m_lock-- == 1 )
    _InterlockedExchange(&v8->m_thread_id, 0);
  return result;
}
