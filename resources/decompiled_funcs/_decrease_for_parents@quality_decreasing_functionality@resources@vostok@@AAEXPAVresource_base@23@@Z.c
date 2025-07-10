void __thiscall vostok::resources::quality_decreasing_functionality::decrease_for_parents(
        vostok::resources::quality_decreasing_functionality *this,
        vostok::resources::resource_base *top_resource,
        vostok::threading::simple_lock *a3)
{
  unsigned int *p_m_thread_id; // ebp
  vostok::resources::resource_link *m_thread_id; // eax
  vostok::resources::resource_link *next_link; // edi
  unsigned int quality_value; // edx
  vostok::resources::resource_base *resource; // esi
  unsigned int v8; // ecx
  unsigned __int64 QuadPart; // rax
  unsigned int v10; // eax
  unsigned int v11; // eax
  bool v12; // zf
  unsigned int v13; // eax
  vostok::threading::simple_lock *v14; // eax
  bool comparison_result[4]; // [esp+8h] [ebp-2034h] BYREF
  vostok::threading::simple_lock *v16; // [esp+Ch] [ebp-2030h]
  vostok::resources::quality_increase_functionality v17; // [esp+10h] [ebp-202Ch] BYREF
  unsigned int i; // [esp+14h] [ebp-2028h]
  LARGE_INTEGER PerformanceCount; // [esp+18h] [ebp-2024h] BYREF
  vostok::debug::detail::compare_result<unsigned int,unsigned int> operands_and_result; // [esp+20h] [ebp-201Ch] BYREF
  vostok::debug::detail::compare_result<unsigned int,unsigned int> v21; // [esp+2Ch] [ebp-2010h] BYREF
  vostok::debug::detail::string_helper out_helper; // [esp+38h] [ebp-2004h] BYREF
  vostok::debug::detail::string_helper v23; // [esp+1038h] [ebp-1004h] BYREF

  p_m_thread_id = (unsigned int *)&a3[7].m_thread_id;
  if ( a3 == (vostok::threading::simple_lock *)-60 )
    v16 = 0;
  else
    v16 = a3 + 8;
  vostok::threading::simple_lock::lock(v16, v16);
  m_thread_id = (vostok::resources::resource_link *)a3[9].m_thread_id;
  if ( !m_thread_id )
    goto LABEL_37;
  if ( (m_thread_id->resource->m_flags.m_flags & 0x800) != 0 )
    m_thread_id = vostok::resources::resource_link_list_next_no_dying(m_thread_id);
  if ( !m_thread_id )
    goto LABEL_37;
  while ( 1 )
  {
    next_link = m_thread_id->next_link;
    for ( i = *p_m_thread_id; next_link; next_link = next_link->next_link )
    {
      if ( (next_link->resource->m_flags.m_flags & 0x800) == 0 )
        break;
    }
    quality_value = m_thread_id->quality_value;
    if ( quality_value == -1 )
      goto LABEL_19;
    resource = m_thread_id->resource;
    v8 = m_thread_id->resource->m_quality_levels_count - 1;
    if ( !debug_macro_helper_ignore_always_21 )
      break;
    resource->decrease_quality(resource, quality_value + 1);
    v17.m_data = (vostok::resources::game_resources_manager_data *)top_resource->log_string;
    if ( !vostok::resources::quality_increase_functionality::s_started_tick_timer )
    {
      vostok::resources::quality_increase_functionality::s_started_tick_timer = 1;
      if ( vostok::timing::g_cpu_supports_time_stamp )
      {
        QuadPart = __rdtsc();
      }
      else
      {
        QueryPerformanceCounter(&PerformanceCount);
        QuadPart = PerformanceCount.QuadPart;
      }
      vostok::resources::quality_increase_functionality::s_tick_timer.m_start_time = QuadPart;
      vostok::resources::quality_increase_functionality::s_tick_timer.m_current_time = 0;
    }
    vostok::resources::quality_increase_functionality::update_current_satisfaction_for_resource(&v17, resource);
    v10 = *p_m_thread_id;
    if ( !debug_macro_helper_ignore_always_22 )
    {
      v21.operands.right = i;
      v21.result = v10 < i;
      v23.m_buffer[0] = 0;
      v21.operands.left = v10;
      vostok::debug::detail::make_fail_message<unsigned int,unsigned int>(
        (vostok::debug::detail::string_helper *)&v21,
        &comparison_result[3],
        &v23);
      if ( !comparison_result[3] )
      {
        v13 = occurances_left_22;
        if ( occurances_left_22 == -1 )
          v13 = 10;
        occurances_left_22 = v13 - 1;
        if ( v13 )
        {
          if ( !debug_macro_helper_ignore_always_22 )
          {
            comparison_result[1] = 0;
            vostok::debug::on_error(
              0,
              &comparison_result[1],
              process_error_false,
              &debug_macro_helper_ignore_always_22,
              assert_untyped,
              "assertion_failed",
              "current_parents_count < previous_parents_count",
              ".\\game_resman_quality_decrease.cpp",
              "vostok::resources::quality_decreasing_functionality::decrease_for_parents",
              0x65u,
              "%s",
              v23.m_buffer);
            if ( !vostok::debug::is_debugger_present() )
            {
              v12 = !comparison_result[1];
              goto LABEL_35;
            }
            goto LABEL_36;
          }
        }
      }
      goto LABEL_37;
    }
LABEL_19:
    m_thread_id = next_link;
    if ( !next_link )
      goto LABEL_37;
  }
  operands_and_result.operands.left = m_thread_id->quality_value;
  operands_and_result.operands.right = v8;
  operands_and_result.result = quality_value != v8;
  out_helper.m_buffer[0] = 0;
  vostok::debug::detail::make_fail_message<unsigned int,unsigned int>(
    (vostok::debug::detail::string_helper *)&operands_and_result,
    &comparison_result[2],
    &out_helper);
  if ( !comparison_result[2] )
  {
    v11 = occurances_left_21;
    if ( occurances_left_21 == -1 )
      v11 = 10;
    occurances_left_21 = v11 - 1;
    if ( v11 )
    {
      if ( !debug_macro_helper_ignore_always_21 )
      {
        comparison_result[0] = 0;
        vostok::debug::on_error(
          0,
          comparison_result,
          process_error_false,
          &debug_macro_helper_ignore_always_21,
          assert_untyped,
          "assertion_failed",
          "it_link->quality_value != worst_quality_level",
          ".\\game_resman_quality_decrease.cpp",
          "vostok::resources::quality_decreasing_functionality::decrease_for_parents",
          0x56u,
          "%s",
          out_helper.m_buffer);
        if ( !vostok::debug::is_debugger_present() )
        {
          v12 = !comparison_result[0];
LABEL_35:
          if ( v12 )
            goto LABEL_37;
        }
LABEL_36:
        __debugbreak();
      }
    }
  }
LABEL_37:
  v14 = v16;
  v12 = v16->m_lock-- == 1;
  if ( v12 )
    _InterlockedExchange(&v14->m_thread_id, 0);
}
