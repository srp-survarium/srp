void __thiscall vostok::tasks::thread_pool::initialize(
        vostok::tasks::thread_pool *this,
        vostok::tasks::thread_pool *thisa)
{
  int v2; // ecx
  int v3; // esi
  unsigned int v4; // edi
  unsigned int v5; // ebp
  vostok::tasks::thread_tls *v6; // esi
  bool v7; // zf
  unsigned int v8; // edx
  char *m_begin; // eax
  int v10; // ebp
  void (__cdecl *v11)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  LARGE_INTEGER v12; // rax
  vostok::threading *v13; // [esp+0h] [ebp-478h]
  void **v14; // [esp+4h] [ebp-474h]
  int v15; // [esp+14h] [ebp-464h]
  unsigned int max_task_threads; // [esp+18h] [ebp-460h]
  __int64 v17; // [esp+1Ch] [ebp-45Ch]
  LARGE_INTEGER PerformanceCount; // [esp+28h] [ebp-450h] BYREF
  boost::function<void __cdecl(void)> function_to_call; // [esp+30h] [ebp-448h] BYREF
  vostok::tasks::thread_tls *v20; // [esp+50h] [ebp-428h]
  vostok::tasks::thread_tls *v21; // [esp+54h] [ebp-424h]
  vostok::fixed_string<512> thread_name_for_logging; // [esp+58h] [ebp-420h] BYREF
  char v23; // [esp+264h] [ebp-214h] BYREF
  vostok::fixed_string<512> thread_name_for_debugger; // [esp+268h] [ebp-210h] BYREF
  char v25; // [esp+474h] [ebp-4h] BYREF

  v2 = (char *)thisa->m_task_thread_tls.m_end - (char *)thisa->m_task_thread_tls.m_begin;
  v3 = v2 / 360;
  max_task_threads = v2 / 360;
  v4 = 0;
  if ( v2 / 360 )
  {
    v15 = 0;
    do
    {
      v5 = v4 + 1;
      thread_name_for_debugger.m_begin = thread_name_for_debugger.m_buffer;
      thread_name_for_debugger.m_end = thread_name_for_debugger.m_buffer;
      thread_name_for_debugger.m_max_end = &v25;
      thread_name_for_debugger.m_buffer[0] = 0;
      vostok::buffer_string::assignf(&thread_name_for_debugger, "task #%d", v4 + 1);
      thread_name_for_logging.m_begin = thread_name_for_logging.m_buffer;
      thread_name_for_logging.m_end = thread_name_for_logging.m_buffer;
      thread_name_for_logging.m_max_end = &v23;
      thread_name_for_logging.m_buffer[0] = 0;
      vostok::buffer_string::assignf(&thread_name_for_logging, "task #%d", v4 + 1);
      v6 = &thisa->m_task_thread_tls.m_begin[v15];
      v7 = s_logical_core_count == 0;
      v6->pool = thisa;
      v6->thread_index = v4;
      if ( v7 )
        vostok::threading::initialize_core_count(v13);
      v8 = v4 % s_logical_core_count;
      v6->thread_type = type_task_thread;
      v6->hardware_thread = v8;
      v6->state = 1;
      if ( &v6->thread_name != (vostok::fixed_string<32> *)&thread_name_for_logging )
      {
        m_begin = v6->thread_name.m_begin;
        v6->thread_name.m_end = m_begin;
        *m_begin = 0;
        v10 = thread_name_for_logging.m_end - thread_name_for_logging.m_begin;
        memcpy(
          (unsigned __int8 *)v6->thread_name.m_end,
          (unsigned __int8 *)thread_name_for_logging.m_begin,
          thread_name_for_logging.m_end - thread_name_for_logging.m_begin);
        v6->thread_name.m_end += v10;
        v5 = v4 + 1;
        *v6->thread_name.m_end = 0;
      }
      LODWORD(v17) = vostok::tasks::thread_tls::thread_proc;
      v20 = v6;
      v21 = v6;
      HIDWORD(v17) = v6;
      if ( survarium::generate_shaders_world::is_loading() )
      {
        function_to_call.vtable = 0;
      }
      else
      {
        *(_QWORD *)&function_to_call.functor.obj_ptr = v17;
        function_to_call.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::tasks::thread_tls>,boost::_bi::list1<boost::_bi::value<vostok::tasks::thread_tls *>>>>'::`2'::stored_vtable
                                                                         + 1);
      }
      v6->thread_id = vostok::threading::spawn(
                        &function_to_call,
                        thread_name_for_debugger.m_begin,
                        thread_name_for_logging.m_begin,
                        v6->hardware_thread,
                        0,
                        (vostok::threading::tasks_awareness)v13,
                        v14);
      if ( function_to_call.vtable )
      {
        if ( ((int)function_to_call.vtable & 1) == 0 )
        {
          v11 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)function_to_call.vtable & 0xFFFFFFFE);
          if ( v11 )
            v11(&function_to_call.functor, &function_to_call.functor, 2);
        }
        function_to_call.vtable = 0;
      }
      ++v15;
      v4 = v5;
    }
    while ( v5 < max_task_threads );
    v3 = max_task_threads;
    v4 = 0;
  }
  vostok::tasks::thread_pool::log_columns_header((vostok::tasks::thread_pool *)v2, thisa);
  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    v12.QuadPart = __rdtsc();
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    v12 = PerformanceCount;
  }
  thisa->m_timer.m_start_time = v12.QuadPart;
  LODWORD(thisa->m_timer.m_current_time) = 0;
  for ( HIDWORD(thisa->m_timer.m_current_time) = 0; v3; --v3 )
  {
    SetEvent(*(HANDLE *)&thisa->m_task_thread_tls.m_begin->event_start_thread_work.m_event[v4]);
    v4 += 360;
  }
  WaitForSingleObject(*(HANDLE *)thisa->m_all_task_threads_started.m_event, 0xFFFFFFFF);
  thisa->m_initialized = 1;
}
