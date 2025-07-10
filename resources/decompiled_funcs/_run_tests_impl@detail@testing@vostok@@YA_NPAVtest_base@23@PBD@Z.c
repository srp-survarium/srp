bool __usercall vostok::testing::detail::run_tests_impl@<al>(
        vostok::testing::test_base *test@<eax>,
        vostok::command_line::key *a2@<ecx>,
        const char *suite_name)
{
  unsigned int v5; // edi
  int v6; // ebp
  unsigned __int64 QuadPart; // rax
  vostok::logging::verbosity v8; // edi
  void (__cdecl *v9)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  unsigned __int64 v10; // rax
  void (__cdecl *v11)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::core::engine *engine; // ecx
  unsigned int v13; // esi
  int v14; // eax
  bool is_debugger_present; // al
  int v16; // eax
  unsigned int num_failed_tests; // [esp+14h] [ebp-454h]
  LARGE_INTEGER PerformanceCount; // [esp+18h] [ebp-450h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+20h] [ebp-448h] BYREF
  vostok::timing::timer timer; // [esp+40h] [ebp-428h] BYREF
  vostok::fixed_string<1024> result_string; // [esp+58h] [ebp-410h] BYREF
  char v22; // [esp+464h] [ebp-4h] BYREF

  if ( !vostok::testing::run_tests_command_line(a2) )
    return 1;
  _InterlockedExchange(&s_environment.is_testing, 1);
  v5 = 0;
  num_failed_tests = 0;
  v6 = 0;
  vostok::timing::timer::timer(&timer);
  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    QuadPart = __rdtsc();
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    QuadPart = PerformanceCount.QuadPart;
  }
  timer.m_start_time = QuadPart;
  timer.m_current_time = 0;
  if ( test )
  {
    do
    {
      s_environment.awaited_exception = assert_untyped;
      s_environment.exception_index = 0;
      _InterlockedExchangeAdd(&s_environment.current_test_number, 1u);
      vostok::debug::protected_call(vostok::testing::run_protected_test_helper, test);
      if ( s_environment.exception_index )
        ++v5;
      test = test->m_next_test;
      ++v6;
    }
    while ( test );
    num_failed_tests = v5;
  }
  result_string.m_end = result_string.m_buffer;
  v8 = 3 - (v5 != 0);
  result_string.m_begin = result_string.m_buffer;
  result_string.m_max_end = &v22;
  result_string.m_buffer[0] = 0;
  if ( num_failed_tests )
    vostok::buffer_string::appendf(
      (vostok::buffer_string *)&stru_95AAC4.configuration[1],
      suite_name,
      num_failed_tests,
      v6);
  else
    vostok::buffer_string::appendf((vostok::buffer_string *)&stru_95AAF4, suite_name, v6);
  v9 = vostok::core::g_log_callback;
  log_callback.vtable = 0;
  if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
    `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
      &log_callback.functor,
      &log_callback.functor,
      destroy_functor_tag);
  if ( v9 )
  {
    log_callback.functor.obj_ptr = v9;
    log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                 + 1);
  }
  else
  {
    log_callback.vtable = 0;
  }
  v10 = 1000 * vostok::timing::timer::get_elapsed_ticks(&timer) / vostok::timing::g_qpc_per_second.QuadPart;
  vostok::logging::append(
    &log_callback,
    0,
    &vostok::logging::format_message,
    ".\\testing_impl.cpp",
    0x153u,
    "bool __cdecl vostok::testing::detail::run_tests_impl(class vostok::testing::test_base *,const char *)",
    "test:",
    v8,
    "------------------------------------------------------------------------------\n"
    "%s (%d ms)\n"
    "------------------------------------------------------------------------------",
    result_string.m_begin,
    (_DWORD)v10);
  if ( log_callback.vtable )
  {
    if ( ((int)log_callback.vtable & 1) == 0 )
    {
      v11 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v11 )
        v11(&log_callback.functor, &log_callback.functor, 2);
    }
  }
  s_environment.num_failed_tests += num_failed_tests;
  _InterlockedExchangeAdd(&s_environment.num_suites_executed, 1u);
  if ( s_environment.num_suites_executed == s_environment.num_suites_total )
  {
    engine = s_environment.engine;
    v13 = s_environment.num_failed_tests;
    if ( s_environment.engine )
    {
      v14 = s_environment.engine->get_exit_code(s_environment.engine);
      engine = s_environment.engine;
      v13 += v14;
    }
    if ( vostok::testing::g_run_tests_and_exit.m_type == type_unset )
    {
      vostok::testing::g_run_tests_and_exit.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
      engine = s_environment.engine;
    }
    if ( vostok::testing::g_run_tests_and_exit.m_type != type_recursive )
    {
      if ( s_environment.num_failed_tests )
      {
        is_debugger_present = vostok::debug::is_debugger_present();
        engine = s_environment.engine;
        if ( !is_debugger_present )
        {
          v16 = s_environment.engine->get_exit_code(s_environment.engine);
          vostok::debug::terminate(v16 + s_environment.num_failed_tests + 10000, (char *)&buf);
        }
      }
      if ( engine )
        engine->exit(engine, v13);
    }
  }
  _InterlockedExchange(&s_environment.is_testing, 0);
  return num_failed_tests == 0;
}
