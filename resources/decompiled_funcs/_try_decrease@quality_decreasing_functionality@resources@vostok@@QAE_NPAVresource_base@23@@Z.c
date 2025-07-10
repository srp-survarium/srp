bool __userpurge vostok::resources::quality_decreasing_functionality::try_decrease@<al>(
        vostok::resources::quality_decreasing_functionality *this@<ecx>,
        vostok::resources::quality_decreasing_functionality *a2@<edi>,
        double a3@<st0>,
        vostok::resources::resource_base *resource)
{
  vostok::resources::resource_base *i; // eax
  vostok::resources::resource_base *m_next_for_grm_observer_list; // ecx
  vostok::threading::simple_lock *v7; // edx
  vostok::resources::resource_base **p_m_next_for_grm_observer_list; // eax
  vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,184,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> quality_resources; // [esp+8h] [ebp-10h] BYREF

  if ( (resource->m_flags.m_flags & 0x20) != 0 )
    return 1;
  if ( !vostok::resources::resource_quality::is_on_quality_branch(resource) )
    return 0;
  quality_resources.m_size = 0;
  quality_resources.m_first = 0;
  quality_resources.m_last = 0;
  if ( !vostok::resources::quality_decreasing_functionality::collect_quality_resources(
          a2,
          a3,
          resource,
          &quality_resources) )
    return 0;
  for ( i = quality_resources.m_first; quality_resources.m_first; i = quality_resources.m_first )
  {
    --quality_resources.m_size;
    m_next_for_grm_observer_list = i->m_next_for_grm_observer_list;
    v7 = (vostok::threading::simple_lock *)i;
    p_m_next_for_grm_observer_list = &i->m_next_for_grm_observer_list;
    quality_resources.m_first = m_next_for_grm_observer_list;
    if ( !m_next_for_grm_observer_list )
      quality_resources.m_last = 0;
    *p_m_next_for_grm_observer_list = 0;
    vostok::resources::quality_decreasing_functionality::decrease_for_parents(
      (vostok::resources::quality_decreasing_functionality *)m_next_for_grm_observer_list,
      (vostok::resources::resource_base *)a2,
      v7);
  }
  return vostok::resources::resource_freeing_functionality::try_collect_to_free_resource(
           a2->m_freeing_functionality,
           resource);
}
