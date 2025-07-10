void __usercall vostok::resources::game_resources_manager::dispatch_capture(
        vostok::resources::game_resources_manager *this@<ecx>,
        vostok::resources::game_resources_manager *a2@<eax>,
        double a3@<st0>)
{
  vostok::resources::game_resources_manager *v4; // eax
  vostok::resources::game_resources_manager *m_current_time_high; // edi

  if ( a2->m_resources_to_capture.m_first )
  {
    v4 = (vostok::resources::game_resources_manager *)vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
                                                        &this->m_resources_to_capture,
                                                        (int)a2);
    if ( v4 )
    {
      do
      {
        m_current_time_high = (vostok::resources::game_resources_manager *)HIDWORD(v4->m_data.increase_quality_timer.m_current_time);
        vostok::resources::game_resources_manager::dispatch_capture(v4, a2, a3);
        v4 = m_current_time_high;
      }
      while ( m_current_time_high );
    }
  }
}
