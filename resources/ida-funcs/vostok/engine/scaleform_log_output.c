void __cdecl vostok::engine::scaleform_log_output(unsigned __int8 message_type, char *fmt)
{
  vostok::buffer_string *v2; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v3; // ecx
  bool v4; // al
  int *p_log_callback; // esi
  bool has_passed_filters; // al
  _DWORD v7[515]; // [esp-80Ch] [ebp-106Ch] BYREF
  int v8; // [esp+Ch] [ebp-854h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-850h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v10; // [esp+30h] [ebp-830h] BYREF
  _DWORD v11[515]; // [esp+50h] [ebp-810h] BYREF
  char v12; // [esp+85Ch] [ebp-4h] BYREF

  v8 = 0;
  v11[0] = &v11[3];
  v11[1] = &v11[3];
  v11[2] = &v12;
  LOBYTE(v11[3]) = 0;
  vostok::buffer_string::append(v2, (int)v11, fmt);
  if ( message_type == 2 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&stru_7F9BE8,
                                 (const char *)3),
          v3 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v7[514],
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v3,
        &v10);
      v8 = 1;
      qmemcpy(v7, v11, sizeof(v7));
      vostok::logging::append(
        &v10,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\engine_scaleform_initialize.cpp",
        0x27u,
        &stru_7F9BE8.filter_stack.gap0,
        (char *)&stru_7F9BE8,
        warning,
        (char *)&stru_7F9BE8.allocator);
    }
    if ( (v8 & 1) != 0 )
    {
      p_log_callback = (int *)&v10;
      goto LABEL_13;
    }
  }
  else if ( message_type == 3 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v4 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)&stru_7F9BE8, (const char *)2),
          v3 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v7[514],
          v4) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v3,
        &log_callback);
      v8 = 2;
      qmemcpy(v7, v11, sizeof(v7));
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\engine_scaleform_initialize.cpp",
        0x2Bu,
        &stru_7F9BE8.filter_stack.gap0,
        (char *)&stru_7F9BE8,
        error,
        (char *)&stru_7F9BE8.allocator);
    }
    if ( (v8 & 2) != 0 )
    {
      p_log_callback = (int *)&log_callback;
LABEL_13:
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v3,
        p_log_callback);
    }
  }
}
