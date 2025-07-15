bool __usercall vostok::resources::resource_freeing_functionality::try_collect_to_free@<al>(
        vostok::resources::resource_freeing_functionality *this@<ecx>,
        vostok::resources::resource_freeing_functionality *a2@<edi>)
{
  vostok::resources::resources_to_free_collection *m_collection; // eax
  float m_target_satisfaction; // xmm0_4
  vostok::resources::resource_base *i; // esi
  vostok::resources::resource_link *v5; // eax
  vostok::resources::quality_decreasing_functionality *v6; // ecx
  vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,184,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> out_quality_resources; // [esp+4h] [ebp-1Ch] BYREF
  vostok::resources::quality_decreasing_functionality v9; // [esp+14h] [ebp-Ch] BYREF
  bool v10; // [esp+1Eh] [ebp-2h] BYREF
  bool v11; // [esp+1Fh] [ebp-1h] BYREF

  m_collection = a2->m_collection;
  m_target_satisfaction = a2->m_collection->query->m_target_satisfaction;
  v9.m_freeing_functionality = a2;
  v9.m_lowest_satisfaction_level = m_target_satisfaction;
  for ( i = m_collection->info->resources.m_first; i; i = i->m_next_in_memory_type )
  {
    v10 = 0;
    v11 = 0;
    if ( vostok::resources::resource_freeing_functionality::can_be_freed(a2, i, &v10, &v11) )
    {
      if ( !v11 )
        goto LABEL_11;
      if ( (i->m_flags.m_flags & 0x20) == 0 )
      {
        if ( !vostok::resources::resource_quality::is_on_quality_branch(i) )
          goto LABEL_11;
        out_quality_resources.m_size = 0;
        out_quality_resources.m_first = 0;
        out_quality_resources.m_last = 0;
        if ( !vostok::resources::quality_decreasing_functionality::collect_quality_resources(
                &v9,
                i,
                &out_quality_resources) )
          goto LABEL_11;
        while ( out_quality_resources.m_first )
        {
          v5 = (vostok::resources::resource_link *)vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,184,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front(&out_quality_resources);
          vostok::resources::quality_decreasing_functionality::decrease_for_parents(
            v6,
            (vostok::resources::resource_base *)&v9,
            v5);
        }
        if ( !vostok::resources::resource_freeing_functionality::try_collect_to_free_resource(
                v9.m_freeing_functionality,
                i) )
        {
LABEL_11:
          if ( v10 )
            vostok::resources::resource_freeing_functionality::try_collect_to_free_resource(a2, i);
        }
      }
      if ( a2->m_collection->collected_memory.size >= a2->m_collection->required_memory.size )
        break;
    }
  }
  return a2->m_collection->collected_memory.size != 0;
}
