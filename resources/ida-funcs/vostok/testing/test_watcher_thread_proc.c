int __thiscall vostok::testing::test_watcher_thread_proc(vostok::threading::event *ecx0)
{
  volatile int result; // eax
  volatile int current_test_number; // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v3; // ecx
  bool v4; // al
  int *p_log_callback; // esi
  bool has_passed_filters; // al
  int v7; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // [esp+Ch] [ebp-5Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp+Ch] [ebp-5Ch]
  bool v10; // [esp+23h] [ebp-45h]
  int v11; // [esp+24h] [ebp-44h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+28h] [ebp-40h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v13; // [esp+48h] [ebp-20h] BYREF

  result = s_environment.num_suites_executed;
  v11 = 0;
  s_environment.test_watcher_thread_started = 1;
  while ( s_environment.num_suites_executed != s_environment.num_suites_total )
  {
    current_test_number = s_environment.current_test_number;
    v10 = s_environment.is_testing != 0;
    vostok::threading::event::wait(
      ecx0,
      (HANDLE *)&s_environment.test_watcher_thread_must_exit,
      s_environment.is_testing == 0 ? 600000 : 100000);
    result = s_environment.num_suites_executed;
    if ( s_environment.num_suites_executed == s_environment.num_suites_total )
      break;
    if ( v10 )
    {
      if ( s_environment.is_testing && s_environment.current_test_number == current_test_number )
      {
        if ( !vostok::debug::is_debugger_present() )
        {
          if ( !vostok::core::g_log_filter_tree
            || (has_passed_filters = vostok::logging::has_passed_filters(
                                       (vostok::logging::filter_tree *)&stru_803D84,
                                       (const char *)2),
                v3 = v9,
                has_passed_filters) )
          {
            boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
              v3,
              &v13);
            v11 |= 2u;
            vostok::logging::append(
              &v13,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\testing_impl.cpp",
              0x82u,
              "void __cdecl vostok::testing::test_watcher_thread_proc(void)",
              (char *)&stru_803D84,
              error,
              "%.4f sec. passed and test %s (suite %s) is still executing",
              600.0,
              s_environment.current_test,
              s_environment.current_suite);
          }
          if ( (v11 & 2) != 0 )
          {
            v11 &= ~2u;
            p_log_callback = (int *)&v13;
LABEL_20:
            boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
              (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v3,
              p_log_callback);
          }
        }
LABEL_21:
        if ( !vostok::debug::is_debugger_present() )
        {
          v7 = s_environment.engine->get_exit_code(s_environment.engine);
          vostok::debug::terminate(v7 + s_environment.num_failed_tests + 10001, (char *)uri);
        }
      }
    }
    else if ( !s_environment.is_testing && s_environment.current_test_number == current_test_number )
    {
      if ( !vostok::debug::is_debugger_present() )
      {
        if ( !vostok::core::g_log_filter_tree
          || (v4 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)&stru_803D84, (const char *)2),
              v3 = v8,
              v4) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            v3,
            &log_callback);
          v11 |= 1u;
          vostok::logging::append(
            &log_callback,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\testing_impl.cpp",
            0x7Au,
            "void __cdecl vostok::testing::test_watcher_thread_proc(void)",
            (char *)&stru_803D84,
            error,
            (char *)&stru_803D84.initiator_tree,
            600.0);
        }
        if ( (v11 & 1) != 0 )
        {
          v11 &= ~1u;
          p_log_callback = (int *)&log_callback;
          goto LABEL_20;
        }
      }
      goto LABEL_21;
    }
    result = s_environment.num_suites_executed;
  }
  s_environment.test_watcher_thread_exited = 1;
  return result;
}
