void __cdecl vostok::testing::test_watcher_thread_proc()
{
  volatile int current_test_number; // esi
  bool v1; // bl
  void (__cdecl *v2)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v3)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::detail::function::function_buffer *p_functor; // ecx
  boost::detail::function::function_buffer *v5; // edx
  void (__cdecl *v6)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  int v7; // eax
  int v8; // [esp+4Ch] [ebp-44h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+50h] [ebp-40h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v10; // [esp+70h] [ebp-20h] BYREF

  v8 = 0;
  s_environment.test_watcher_thread_started = 1;
  while ( s_environment.num_suites_executed != s_environment.num_suites_total )
  {
    current_test_number = s_environment.current_test_number;
    v1 = s_environment.is_testing != 0;
    vostok::threading::event::wait(
      (vostok::threading::event *)s_environment.is_testing,
      (unsigned int)&s_environment.test_watcher_thread_must_exit);
    if ( s_environment.num_suites_executed == s_environment.num_suites_total )
      break;
    if ( v1 )
    {
      if ( s_environment.is_testing && s_environment.current_test_number == current_test_number )
      {
        if ( !vostok::debug::is_debugger_present() )
        {
          if ( !vostok::core::g_log_filter_tree
            || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "test:", error) )
          {
            v6 = vostok::core::g_log_callback;
            v10.vtable = 0;
            if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
              `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
                &v10.functor,
                &v10.functor,
                destroy_functor_tag);
            if ( v6 )
            {
              v10.functor.obj_ptr = v6;
              v10.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                  + 1);
            }
            else
            {
              v10.vtable = 0;
            }
            v8 |= 2u;
            vostok::logging::append(
              &v10,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\testing_impl.cpp",
              0x82u,
              "void __cdecl vostok::testing::test_watcher_thread_proc(void)",
              "test:",
              error,
              "%.4f sec. passed and test %s (suite %s) is still executing",
              600.0,
              s_environment.current_test,
              s_environment.current_suite);
          }
          if ( (v8 & 2) != 0 )
          {
            v8 &= ~2u;
            if ( v10.vtable )
            {
              if ( ((int)v10.vtable & 1) == 0 )
              {
                v3 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v10.vtable & 0xFFFFFFFE);
                if ( v3 )
                {
                  p_functor = &v10.functor;
                  v5 = &v10.functor;
LABEL_36:
                  v3(v5, p_functor, 2);
                }
              }
            }
          }
        }
LABEL_37:
        if ( !vostok::debug::is_debugger_present() )
        {
          v7 = s_environment.engine->get_exit_code(s_environment.engine);
          vostok::debug::terminate(v7 + s_environment.num_failed_tests + 10001, (char *)&buf);
        }
      }
    }
    else if ( !s_environment.is_testing && s_environment.current_test_number == current_test_number )
    {
      if ( !vostok::debug::is_debugger_present() )
      {
        if ( !vostok::core::g_log_filter_tree
          || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "test:", error) )
        {
          v2 = vostok::core::g_log_callback;
          log_callback.vtable = 0;
          if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
            `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
              &log_callback.functor,
              &log_callback.functor,
              destroy_functor_tag);
          if ( v2 )
          {
            log_callback.functor.obj_ptr = v2;
            log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                         + 1);
          }
          else
          {
            log_callback.vtable = 0;
          }
          v8 |= 1u;
          vostok::logging::append(
            &log_callback,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\testing_impl.cpp",
            0x7Au,
            "void __cdecl vostok::testing::test_watcher_thread_proc(void)",
            "test:",
            error,
            "%.4f sec. passed and still next test is not executed",
            600.0);
        }
        if ( (v8 & 1) != 0 )
        {
          v8 &= ~1u;
          if ( log_callback.vtable )
          {
            if ( ((int)log_callback.vtable & 1) == 0 )
            {
              v3 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
              if ( v3 )
              {
                p_functor = &log_callback.functor;
                v5 = &log_callback.functor;
                goto LABEL_36;
              }
            }
          }
        }
      }
      goto LABEL_37;
    }
  }
  s_environment.test_watcher_thread_exited = 1;
}
