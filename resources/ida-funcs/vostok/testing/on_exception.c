void __cdecl vostok::testing::on_exception(
        vostok::assert_enum assert_type,
        _EXCEPTION_POINTERS *exception_information,
        bool is_assertion)
{
  char *v3; // ecx
  char *v4; // eax
  char *m_end; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  const char *v7; // [esp+0h] [ebp-2054h]
  vostok::buffer_string v8; // [esp+Ch] [ebp-2048h] BYREF
  vostok::buffer_string v9[682]; // [esp+18h] [ebp-203Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+2018h] [ebp-3Ch] BYREF
  int v11; // [esp+2038h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+203Ch] [ebp-18h]

  if ( s_environment.awaited_exception && s_environment.awaited_exception == assert_type )
  {
    s_environment.caught_awaited_exception = 1;
    RaiseException(0xABCDEFu, 0, 0, 0);
  }
  else
  {
    ms_exc.registration.TryLevel = 0;
    v4 = v3 + 1;
    if ( *v3 != 10 )
      v4 = v3;
    v11 = 0x2000;
    vostok::buffer_string::buffer_string(v9, &v8, (char *)&v11, v4, v7);
    m_end = v8.m_end;
    if ( v8.m_end != v8.m_begin && *(v8.m_end - 1) != 10 )
    {
      *v8.m_end++ = 10;
      *v8.m_end = 0;
    }
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)m_end,
      &log_callback);
    vostok::logging::append(
      &log_callback,
      0,
      &vostok::core::g_log_format,
      ".\\testing_impl.cpp",
      0xFBu,
      "void __cdecl vostok::testing::on_exception(enum vostok::assert_enum,const char *,struct _EXCEPTION_POINTERS *,bool)",
      "test:",
      error,
      "-------------------------------------------------------------\n"
      "EXCEPTION #%d in test '%s', suite '%s'\n"
      "-------------------------------------------------------------\n"
      "%s",
      s_environment.exception_index + 1,
      s_environment.current_test,
      s_environment.current_suite,
      v8.m_begin);
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::~function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v6);
    vostok::debug::dump_call_stack(
      1,
      (char *)&stru_803D84,
      is_assertion ? 3 : 0,
      s_environment.num_top_callstack_frames_to_skip,
      exception_information);
    ++s_environment.exception_index;
  }
}
