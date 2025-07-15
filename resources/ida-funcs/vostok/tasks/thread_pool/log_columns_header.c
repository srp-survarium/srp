void __thiscall vostok::tasks::thread_pool::log_columns_header(vostok::tasks::thread_pool *this)
{
  unsigned int v1; // ebx
  int v2; // eax
  int v3; // ecx
  unsigned int v4; // edi
  unsigned int v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  vostok::buffer_string v7; // [esp+10h] [ebp-448h] BYREF
  _BYTE v8[512]; // [esp+1Ch] [ebp-43Ch] BYREF
  char v9; // [esp+21Ch] [ebp-23Ch] BYREF
  vostok::buffer_string v10; // [esp+220h] [ebp-238h] BYREF
  _BYTE v11[512]; // [esp+22Ch] [ebp-22Ch] BYREF
  char v12; // [esp+42Ch] [ebp-2Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+430h] [ebp-28h] BYREF
  unsigned int v14; // [esp+454h] [ebp-4h]

  v1 = 0;
  if ( this->m_do_logging )
  {
    v2 = (char *)this->m_task_thread_tls.m_end - (char *)this->m_task_thread_tls.m_begin;
    v3 = 360;
    v8[0] = 0;
    v4 = v2 / 360 + 1;
    v14 = 0x50 / v4;
    v7.m_begin = v8;
    v7.m_end = v8;
    v7.m_max_end = &v9;
    if ( v2 / 360 != -1 )
    {
      do
      {
        v10.m_begin = v11;
        v10.m_end = v11;
        v10.m_max_end = &v12;
        v11[0] = 0;
        if ( v1 )
          vostok::buffer_string::appendf(
            &v10,
            (vostok::buffer_string *)v3,
            (vostok::buffer_string *)"task %d",
            (const char *)(v1 - 1));
        else
          vostok::buffer_string::operator+=(&v10, "user");
        if ( v10.m_end - v10.m_begin < v14 )
        {
          v5 = v14 - (v10.m_end - v10.m_begin);
          do
          {
            *v10.m_end++ = 32;
            --v5;
            *v10.m_end = 0;
          }
          while ( v5 );
        }
        vostok::buffer_string::append(&v7, v10.m_end, v10.m_begin);
        ++v1;
      }
      while ( v1 < v4 );
    }
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v3,
      &log_callback);
    vostok::logging::append(
      &log_callback,
      (void *const)1,
      (vostok::logging::log_format *)&vostok::logging::format_message,
      ".\\tasks_thread_pool_utils.cpp",
      0xAFu,
      "void __thiscall vostok::tasks::thread_pool::log_columns_header(void)",
      "tasks:",
      info,
      (char *)&stru_7F9BE8.allocator,
      v7.m_begin);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v6,
      (int *)&log_callback);
  }
}
