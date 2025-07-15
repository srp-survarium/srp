void __usercall vostok::tasks::thread_pool::log(
        vostok::tasks::thread_pool *this@<ecx>,
        vostok::tasks::thread_tls *tls@<eax>,
        char *format,
        ...)
{
  int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // ecx
  vostok::buffer_string *i; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+8h] [ebp-230h] BYREF
  _BYTE *v11; // [esp+28h] [ebp-210h] BYREF
  _BYTE *v12; // [esp+2Ch] [ebp-20Ch]
  char *v13; // [esp+30h] [ebp-208h]
  _BYTE v14[512]; // [esp+34h] [ebp-204h] BYREF
  char v15; // [esp+234h] [ebp-4h] BYREF
  va_list va; // [esp+244h] [ebp+Ch] BYREF

  va_start(va, format);
  if ( this->m_do_logging )
  {
    v4 = this->m_task_thread_tls.m_end - this->m_task_thread_tls.m_begin;
    v14[0] = 0;
    v5 = 0x50u / (v4 + 1);
    v11 = v14;
    v12 = v14;
    v13 = &v15;
    if ( !tls || tls->thread_type )
      v6 = 0;
    else
      v6 = tls->thread_index + 1;
    for ( i = (vostok::buffer_string *)(v5 * v6); i; *v12 = 0 )
    {
      *v12++ = 32;
      i = (vostok::buffer_string *)((char *)i - 1);
    }
    vostok::buffer_string::appendf_va_list(i, &v11, format, va);
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v8,
      &log_callback);
    vostok::logging::append(
      &log_callback,
      (void *const)1,
      (vostok::logging::log_format *)&vostok::logging::format_message,
      ".\\tasks_thread_pool_utils.cpp",
      0xC5u,
      "void __cdecl vostok::tasks::thread_pool::log(class vostok::tasks::thread_tls *,const char *,...)",
      "tasks:",
      info,
      (char *)&stru_7F9BE8.allocator,
      v11);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v9,
      (int *)&log_callback);
  }
}
