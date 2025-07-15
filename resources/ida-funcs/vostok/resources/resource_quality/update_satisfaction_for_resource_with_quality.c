double __usercall vostok::resources::resource_quality::update_satisfaction_for_resource_with_quality@<st0>(
        vostok::resources::resource_quality *this@<ecx>,
        vostok::resources::resource_quality *a2@<esi>)
{
  vostok::threading::simple_lock *v2; // edi
  vostok::resources::resource_link *m_first; // eax
  unsigned int quality_value; // ecx
  double result; // st7

  v2 = &a2->m_children_resources.vostok::threading::simple_lock;
  vostok::threading::simple_lock::lock(
    (vostok::threading::simple_lock *)this,
    (int)&a2->m_children_resources.vostok::threading::simple_lock);
  m_first = a2->m_children_resources.m_first;
  quality_value = -1;
  while ( m_first )
  {
    if ( quality_value == -1 || m_first->quality_value < quality_value )
      quality_value = m_first->quality_value;
    m_first = m_first->next_link;
  }
  if ( v2->m_lock-- == 1 )
    _InterlockedExchange(&a2->m_children_resources.m_thread_id, 0);
  result = vostok::resources::resource_quality::satisfaction(a2, quality_value, 0, 0);
  a2->m_current_satisfaction = result;
  return result;
}
