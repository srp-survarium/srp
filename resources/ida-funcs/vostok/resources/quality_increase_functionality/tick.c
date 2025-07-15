void __thiscall vostok::resources::quality_increase_functionality::tick(
        vostok::resources::quality_increase_functionality *this,
        vostok::resources::quality_increase_functionality *thisa)
{
  vostok::resources::quality_increase_functionality *v2; // ecx
  double elapsed_sec; // st7
  vostok::resources::memory_type *i; // esi
  unsigned __int64 v5; // rax
  vostok::resources::quality_increase_functionality *v6; // [esp+0h] [ebp-20h]
  vostok::intrusive_list<vostok::resources::resource_quality,vostok::resources::resource_base *,104,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> increase_queue; // [esp+10h] [ebp-10h] BYREF

  if ( (unsigned int)(1000
                    * vostok::timing::timer::get_elapsed_ticks(&vostok::resources::quality_increase_functionality::s_tick_timer)
                    / vostok::timing::g_qpc_per_second.QuadPart) >= 0x12C
    || vostok::testing::run_tests_command_line((vostok::command_line::key *)vostok::timing::g_qpc_per_second.LowPart) )
  {
    elapsed_sec = vostok::timing::timer::get_elapsed_sec(&thisa->m_data->increase_quality_timer);
    vostok::resources::quality_increase_functionality::s_elapsed_sec_from_start = elapsed_sec;
    for ( i = thisa->m_data->memory_types.m_first; i; i = i->m_next )
      vostok::resources::quality_increase_functionality::update_current_satisfaction_for_memory_type(
        thisa,
        i,
        elapsed_sec);
    increase_queue.m_size = 0;
    increase_queue.m_first = 0;
    increase_queue.m_last = 0;
    vostok::resources::quality_increase_functionality::select_to_increase_quality(
      v2,
      (int *)thisa,
      elapsed_sec,
      &increase_queue);
    vostok::resources::quality_increase_functionality::schedule_to_increase_quality(&increase_queue, v6);
    ++thisa->m_data->current_increase_quality_tick;
    if ( vostok::timing::g_cpu_supports_time_stamp )
    {
      v5 = __rdtsc();
    }
    else
    {
      QueryPerformanceCounter((LARGE_INTEGER *)&increase_queue);
      v5 = *(_QWORD *)&increase_queue.m_size;
    }
    vostok::resources::quality_increase_functionality::s_tick_timer.m_start_time = v5;
    vostok::resources::quality_increase_functionality::s_tick_timer.m_current_time = 0;
  }
}
