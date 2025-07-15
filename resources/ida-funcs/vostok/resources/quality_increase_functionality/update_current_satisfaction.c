void __usercall vostok::resources::quality_increase_functionality::update_current_satisfaction(
        vostok::resources::quality_increase_functionality *this@<ecx>,
        vostok::resources::quality_increase_functionality *a2@<eax>)
{
  vostok::resources::memory_type *i; // ebx
  vostok::resources::resource_base *j; // esi

  for ( i = a2->m_data->memory_types.m_first; i; i = i->m_next )
  {
    for ( j = i->resources.m_first; j; j = j->m_next_in_memory_type )
    {
      if ( j->m_quality_levels_count == 1 || j->m_target_quality_level == j->m_current_quality_level )
      {
        vostok::resources::quality_increase_functionality::update_current_satisfaction_for_resource(
          a2,
          j,
          this,
          (vostok::resources::compare_by_target_satisfaction *)i);
      }
      else if ( !j->is_increasing_quality(j) )
      {
        vostok::resources::quality_increase_functionality::update_current_satisfaction_for_resource(
          a2,
          j,
          this,
          (vostok::resources::compare_by_target_satisfaction *)i);
        j->m_last_fail_of_increasing_quality = vostok::resources::quality_increase_functionality::s_elapsed_sec_from_start;
      }
    }
  }
}
