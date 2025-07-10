bool __userpurge vostok::resources::resource_freeing_functionality::try_collect_to_free@<al>(
        vostok::resources::resource_freeing_functionality *this@<ecx>,
        double a2@<st0>,
        vostok::resources::resource_freeing_functionality *can_try_decrease_quality)
{
  vostok::resources::resource_freeing_functionality *v3; // ebp
  vostok::resources::resources_to_free_collection *m_collection; // eax
  float m_target_satisfaction; // xmm0_4
  vostok::resources::resource_base *i; // esi
  vostok::resources::quality_decreasing_functionality *v7; // ecx
  bool can_try_free; // [esp+Fh] [ebp-9h] BYREF
  vostok::resources::quality_decreasing_functionality quality_decreasing; // [esp+10h] [ebp-8h] BYREF

  v3 = can_try_decrease_quality;
  m_collection = can_try_decrease_quality->m_collection;
  m_target_satisfaction = can_try_decrease_quality->m_collection->query->m_target_satisfaction;
  quality_decreasing.m_freeing_functionality = can_try_decrease_quality;
  quality_decreasing.m_lowest_satisfaction_level = m_target_satisfaction;
  for ( i = m_collection->info->resources.m_first; i; i = i->m_next_in_memory_type )
  {
    can_try_free = 0;
    LOBYTE(can_try_decrease_quality) = 0;
    if ( vostok::resources::resource_freeing_functionality::can_be_freed(
           v3,
           i,
           &can_try_free,
           (bool *)&can_try_decrease_quality) )
    {
      if ( (!(_BYTE)can_try_decrease_quality
         || !vostok::resources::quality_decreasing_functionality::try_decrease(v7, &quality_decreasing, a2, i))
        && can_try_free )
      {
        vostok::resources::resource_freeing_functionality::try_collect_to_free_resource(v3, i);
      }
      if ( v3->m_collection->collected_memory.size >= v3->m_collection->required_memory.size )
        break;
    }
  }
  return v3->m_collection->collected_memory.size != 0;
}
