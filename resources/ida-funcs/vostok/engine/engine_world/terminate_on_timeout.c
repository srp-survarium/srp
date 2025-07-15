void __thiscall __noreturn vostok::engine::engine_world::terminate_on_timeout(
        vostok::engine::engine_world *this,
        float time_limit)
{
  LARGE_INTEGER QPC; // rax
  vostok::timing::timer *v3; // ecx
  int elapsed_msec; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  double i; // st7
  vostok::timing::timer *v7; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp+4h] [ebp-3Ch]
  float v10; // [esp+14h] [ebp-2Ch]
  char v11; // [esp+18h] [ebp-28h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+20h] [ebp-20h] BYREF

  v11 = 0;
  vostok::timing::timer::timer((vostok::timing::timer *)this, (LARGE_INTEGER *)&log_callback);
  QPC = vostok::timing::get_QPC();
  log_callback.vtable = 0;
  (&log_callback.vtable)[1] = 0;
  *(LARGE_INTEGER *)&log_callback.functor.obj_ptr = QPC;
  elapsed_msec = vostok::timing::timer::get_elapsed_msec(v3, (int)&log_callback);
  for ( i = (double)elapsed_msec; ; i = (double)elapsed_msec )
  {
    if ( elapsed_msec < 0 )
      i = i + 4294967300.0;
    v10 = time_limit * 1000.0;
    if ( v10 <= i )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&stru_7F9A50,
                                   (const char *)2),
            v5 = v9,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v5,
          &log_callback);
        v11 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\engine_world_terminate_on_timeout.cpp",
          0x20u,
          "void __thiscall vostok::engine::engine_world::terminate_on_timeout(float)",
          (char *)&stru_7F9A50,
          error,
          (char *)&stru_7F9A50.filter_stack.m_last + 4,
          time_limit);
      }
      if ( (v11 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v5,
          (int *)&log_callback);
      vostok::debug::terminate((char *)uri);
    }
    vostok::threading::yield(0x3E8u, (vostok::tasks *)v5);
    elapsed_msec = vostok::timing::timer::get_elapsed_msec(v7, (int)&log_callback);
  }
}
