double __usercall vostok::resources::resource_quality::update_satisfaction_for_resource_with_quality@<st0>(
        vostok::resources::resource_quality *this@<ecx>,
        vostok::resources::resource_quality *a2@<edi>,
        double a3@<st0>)
{
  vostok::threading::simple_lock *v3; // esi
  vostok::resources::resource_link *m_first; // eax
  unsigned int i; // ecx
  double result; // st7

  v3 = &a2->m_children_resources.vostok::threading::simple_lock;
  vostok::threading::simple_lock::lock(
    (vostok::threading::simple_lock *)this,
    &a2->m_children_resources.vostok::threading::simple_lock);
  m_first = a2->m_children_resources.m_first;
  for ( i = -1; m_first; m_first = m_first->next_link )
  {
    if ( i == -1 || m_first->quality_value < i )
      i = m_first->quality_value;
  }
  if ( v3->m_lock-- == 1 )
    _InterlockedExchange(&a2->m_children_resources.m_thread_id, 0);
  result = vostok::resources::resource_quality::satisfaction(a2, a3, i, 0, 0);
  a2->m_current_satisfaction = result;
  return result;
}
