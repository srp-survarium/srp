void __usercall vostok::testing::on_exception(
        const char *description@<edx>,
        vostok::assert_enum assert_type,
        _EXCEPTION_POINTERS *exception_information,
        bool is_assertion)
{
  void *v4; // esp
  char *m_end; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *p_log_callback; // ecx
  int v7; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v8; // ecx
  int v9; // [esp-Ch] [ebp-2054h] BYREF
  vostok::buffer_string v10; // [esp+0h] [ebp-2048h] BYREF
  _BYTE v11[8192]; // [esp+Ch] [ebp-203Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+200Ch] [ebp-3Ch] BYREF
  const char *v13; // [esp+202Ch] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+2030h] [ebp-18h]

  v4 = alloca(8240);
  ms_exc.old_esp = (DWORD)&v9;
  if ( s_environment.awaited_exception && s_environment.awaited_exception == assert_type )
  {
    s_environment.caught_awaited_exception = 1;
    RaiseException((DWORD)&vostok::memory::s_CRT_arena[56359], 0, 0, 0);
  }
  else
  {
    ms_exc.registration.TryLevel = 0;
    if ( *description == 10 )
      ++description;
    m_end = v11;
    v10.m_begin = v11;
    v10.m_end = v11;
    p_log_callback = &log_callback;
    v10.m_max_end = (char *)&log_callback;
    v11[0] = 0;
    v13 = description;
    if ( description )
    {
      while ( 1 )
      {
        LOBYTE(p_log_callback) = *description;
        if ( !*description || m_end >= v10.m_max_end )
          break;
        *m_end = (char)p_log_callback;
        m_end = ++v10.m_end;
        v13 = ++description;
      }
      *m_end = 0;
      m_end = v10.m_end;
    }
    v7 = m_end - v10.m_begin;
    if ( v7 )
    {
      if ( *vostok::buffer_string::operator[](&v10, v7 - 1) != 10 )
      {
        *v10.m_end++ = 10;
        *v10.m_end = 0;
      }
    }
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(p_log_callback);
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
      v10.m_begin);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v8,
      (int *)&log_callback);
    vostok::debug::dump_call_stack(
      0,
      (const char *)&stru_95AAC4,
      1,
      is_assertion ? 3 : 0,
      s_environment.num_top_callstack_frames_to_skip,
      exception_information,
      0);
    ++s_environment.exception_index;
  }
}
