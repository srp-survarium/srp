void __usercall vostok::resources::quality_increase_functionality::tick(
        vostok::resources::quality_increase_functionality *this@<ecx>,
        vostok::resources::quality_increase_functionality *a2@<edi>)
{
  vostok::timing::timer *v2; // ecx
  vostok::resources::quality_increase_functionality *v3; // ecx
  vostok::resources::quality_increase_functionality *v4; // ecx
  vostok::intrusive_list<vostok::resources::resource_quality,vostok::resources::resource_base *,104,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> v5; // [esp+8h] [ebp-10h] BYREF

  if ( (unsigned int)vostok::timing::timer::get_elapsed_msec(
                       (vostok::timing::timer *)this,
                       (int)&vostok::resources::quality_increase_functionality::s_tick_timer) >= 0x12C
    || vostok::testing::run_tests_command_line((vostok::command_line::key *)v2) )
  {
    vostok::resources::quality_increase_functionality::s_elapsed_sec_from_start = vostok::timing::timer::get_elapsed_sec(
                                                                                    v2,
                                                                                    (int)&a2->m_data->increase_quality_timer);
    vostok::resources::quality_increase_functionality::update_current_satisfaction(v3, a2);
    v5.m_size = 0;
    v5.m_first = 0;
    v5.m_last = 0;
    vostok::resources::quality_increase_functionality::select_to_increase_quality(
      v4,
      (vostok::resources::resource_base_vtbl **)a2,
      &v5);
    vostok::resources::quality_increase_functionality::schedule_to_increase_quality(&v5);
    ++a2->m_data->current_increase_quality_tick;
    vostok::resources::quality_increase_functionality::s_tick_timer.m_start_time = vostok::timing::get_QPC().QuadPart;
    vostok::resources::quality_increase_functionality::s_tick_timer.m_current_time = 0;
  }
}
