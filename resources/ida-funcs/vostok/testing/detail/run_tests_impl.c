bool __usercall vostok::testing::detail::run_tests_impl@<al>(
        vostok::testing::test_base *test@<eax>,
        vostok::command_line::key *a2@<ecx>,
        const char *suite_name)
{
  vostok::buffer_string *v5; // ecx
  vostok::logging::verbosity v6; // edi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // ecx
  const char *v8; // ebx
  vostok::timing::timer *v9; // ecx
  int elapsed_msec; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  int v12; // edi
  vostok::command_line::key *engine; // ecx
  unsigned int num_failed_tests; // esi
  int v15; // eax
  vostok::buffer_string *v16; // [esp-4h] [ebp-468h]
  _DWORD v17[3]; // [esp+10h] [ebp-454h] BYREF
  _BYTE v18[1024]; // [esp+1Ch] [ebp-448h] BYREF
  char v19; // [esp+41Ch] [ebp-48h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+420h] [ebp-44h] BYREF
  LARGE_INTEGER v21[3]; // [esp+440h] [ebp-24h] BYREF
  int v22; // [esp+458h] [ebp-Ch]
  int v23; // [esp+45Ch] [ebp-8h]

  if ( !vostok::testing::run_tests_command_line(a2) )
    return 1;
  _InterlockedExchange(&s_environment.is_testing, 1);
  v23 = 0;
  v22 = 0;
  vostok::timing::timer::timer((vostok::timing::timer *)&s_environment.is_testing, v21);
  v21[1] = vostok::timing::get_QPC();
  v21[0].QuadPart = 0;
  while ( test )
  {
    s_environment.awaited_exception = assert_untyped;
    s_environment.exception_index = 0;
    _InterlockedExchangeAdd(&s_environment.current_test_number, 1u);
    vostok::debug::protected_call(vostok::testing::run_protected_test_helper, test);
    v5 = v16;
    if ( s_environment.exception_index )
      ++v23;
    ++v22;
    test = test->m_next_test;
  }
  v17[0] = v18;
  v17[1] = v18;
  v6 = 3 - (v23 != 0);
  v17[2] = &v19;
  v18[0] = 0;
  if ( v23 )
    vostok::buffer_string::appendf(
      v17,
      v5,
      (vostok::buffer_string *)"TEST SUITE '%s' : FAILED %d of %d tests",
      suite_name,
      v23,
      v22);
  else
    vostok::buffer_string::appendf(
      v17,
      v5,
      (vostok::buffer_string *)"TEST SUITE '%s' : successfull %d tests",
      suite_name,
      v22);
  boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
    v7,
    &log_callback);
  v8 = (const char *)v17[0];
  elapsed_msec = vostok::timing::timer::get_elapsed_msec(v9, (int)v21);
  vostok::logging::append(
    &log_callback,
    0,
    (vostok::logging::log_format *)&vostok::logging::format_message,
    ".\\testing_impl.cpp",
    0x153u,
    "bool __cdecl vostok::testing::detail::run_tests_impl(class vostok::testing::test_base *,const char *)",
    "test:",
    v6,
    "------------------------------------------------------------------------------\n"
    "%s (%d ms)\n"
    "------------------------------------------------------------------------------",
    v8,
    elapsed_msec);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v11,
    (int *)&log_callback);
  v12 = v23;
  s_environment.num_failed_tests += v23;
  _InterlockedExchangeAdd(&s_environment.num_suites_executed, 1u);
  if ( s_environment.num_suites_executed == s_environment.num_suites_total )
  {
    engine = (vostok::command_line::key *)s_environment.engine;
    num_failed_tests = s_environment.num_failed_tests;
    if ( s_environment.engine )
      num_failed_tests += s_environment.engine->get_exit_code(s_environment.engine);
    if ( vostok::command_line::key::is_set(engine, (int)&vostok::testing::g_run_tests_and_exit) )
    {
      if ( s_environment.num_failed_tests && !vostok::debug::is_debugger_present() )
      {
        v15 = s_environment.engine->get_exit_code(s_environment.engine);
        vostok::debug::terminate(v15 + s_environment.num_failed_tests + 10000, (char *)uri);
      }
      if ( s_environment.engine )
        s_environment.engine->exit(s_environment.engine, num_failed_tests);
    }
  }
  _InterlockedExchange(&s_environment.is_testing, 0);
  return v12 == 0;
}
