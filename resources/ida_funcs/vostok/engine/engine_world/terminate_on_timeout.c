void __thiscall __noreturn vostok::engine::engine_world::terminate_on_timeout(
        vostok::engine::engine_world *this,
        float time_limit)
{
  unsigned __int64 QuadPart; // rax
  vostok::tasks::thread_pool *v3; // ecx
  vostok::tasks::thread_pool *v4; // ecx
  void (__cdecl *v5)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  float v7; // [esp+40h] [ebp-48h]
  char v8; // [esp+44h] [ebp-44h]
  LARGE_INTEGER PerformanceCount; // [esp+48h] [ebp-40h] BYREF
  vostok::timing::timer app_closing_timer; // [esp+50h] [ebp-38h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+68h] [ebp-20h] BYREF

  v8 = 0;
  vostok::timing::timer::timer(&app_closing_timer);
  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    QuadPart = __rdtsc();
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    QuadPart = PerformanceCount.QuadPart;
  }
  app_closing_timer.m_start_time = QuadPart;
  app_closing_timer.m_current_time = 0;
  v7 = time_limit * 1000.0;
  for ( PerformanceCount.LowPart = 1000
                                 * vostok::timing::timer::get_elapsed_ticks(&app_closing_timer)
                                 / vostok::timing::g_qpc_per_second.QuadPart;
        v7 > (double)PerformanceCount.LowPart;
        PerformanceCount.LowPart = 1000
                                 * vostok::timing::timer::get_elapsed_ticks(&app_closing_timer)
                                 / vostok::timing::g_qpc_per_second.QuadPart )
  {
    if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
      vostok::tasks::thread_pool::on_current_thread_locks(v3, s_thread_pool.m_variable);
    Sleep(0x3E8u);
    if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
      vostok::tasks::thread_pool::on_current_thread_unlocks(v4, s_thread_pool.m_variable);
  }
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "process termination thread:", error) )
  {
    v5 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v5 )
    {
      log_callback.functor.obj_ptr = v5;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    v8 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\engine_world_terminate_on_timeout.cpp",
      0x20u,
      "void __thiscall vostok::engine::engine_world::terminate_on_timeout(float)",
      "process termination thread:",
      error,
      "interval %d sec for application closing expired",
      (unsigned int)COERCE_UNSIGNED_INT64(time_limit));
  }
  if ( (v8 & 1) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
  {
    v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
    if ( v6 )
      v6(&log_callback.functor, &log_callback.functor, 2);
  }
  vostok::debug::terminate((char *)&buf);
}
