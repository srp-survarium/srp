void __cdecl vostok::memory::dump_statistics(const bool dump_stats_for_empty_arenas_as_well)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v1; // ecx
  allocator_data *m_end; // ebx
  int *m_begin; // esi
  int v4; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v12; // ecx
  float v13; // [esp+18h] [ebp-50h]
  __int64 v14; // [esp+20h] [ebp-48h]
  float v15; // [esp+20h] [ebp-48h]
  float v16; // [esp+20h] [ebp-48h]
  float v17; // [esp+20h] [ebp-48h]
  unsigned __int64 i; // [esp+28h] [ebp-40h]
  unsigned __int64 v19; // [esp+30h] [ebp-38h]
  unsigned __int64 v20; // [esp+38h] [ebp-30h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+48h] [ebp-20h] BYREF

  m_end = s_allocators.m_variable->m_end;
  m_begin = (int *)s_allocators.m_variable->m_begin;
  v14 = 0;
  v19 = 0;
  for ( i = 0; m_begin != (int *)m_end; m_begin += 6 )
  {
    v19 += (unsigned int)(*(int (__thiscall **)(int))(*(_DWORD *)*m_begin + 8))(*m_begin);
    v4 = (*(int (__thiscall **)(int))(*(_DWORD *)*m_begin + 12))(*m_begin);
    v1 = 0;
    i += (unsigned int)v4;
    if ( (vostok::memory::process_allocator *)*m_begin == &s_process_allocator )
      v14 = (unsigned int)v4;
    if ( v4 || dump_stats_for_empty_arenas_as_well )
      vostok::memory::base_allocator::dump_statistics(0, *m_begin);
  }
  v20 = i - v14;
  boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
    v1,
    &log_callback);
  vostok::logging::append(
    &log_callback,
    0,
    (vostok::logging::log_format *)&vostok::logging::format_message,
    ".\\memory.cpp",
    0x178u,
    "void __cdecl vostok::memory::dump_statistics(const bool)",
    "core:",
    info,
    "---------------overall memory stats---------------");
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v5,
    (int *)&log_callback);
  v13 = (float)v19;
  if ( v13 == 0.0 )
    v15 = 0.0;
  else
    v15 = (double)v20 / v13 * s_spot_max_distance;
  boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
    (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)0x80000000,
    &log_callback);
  vostok::logging::append(
    &log_callback,
    0,
    (vostok::logging::log_format *)&vostok::logging::format_message,
    ".\\memory.cpp",
    0x179u,
    "void __cdecl vostok::memory::dump_statistics(const bool)",
    "core:",
    info,
    "vostok: %11I64d (%6.2f%%)",
    v20,
    v15);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v6,
    (int *)&log_callback);
  if ( v13 == 0.0 )
    v16 = 0.0;
  else
    v16 = (double)i / v13 * s_spot_max_distance;
  boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
    v7,
    &log_callback);
  vostok::logging::append(
    &log_callback,
    0,
    (vostok::logging::log_format *)&vostok::logging::format_message,
    ".\\memory.cpp",
    0x17Au,
    "void __cdecl vostok::memory::dump_statistics(const bool)",
    "core:",
    info,
    "used:   %11I64d (%6.2f%%)",
    i,
    v16);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v8,
    (int *)&log_callback);
  if ( v13 == 0.0 )
  {
    v17 = 0.0;
  }
  else
  {
    v9 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)(v19 - i);
    v17 = (double)(v19 - i) / v13 * s_spot_max_distance;
  }
  boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
    v9,
    &log_callback);
  vostok::logging::append(
    &log_callback,
    0,
    (vostok::logging::log_format *)&vostok::logging::format_message,
    ".\\memory.cpp",
    0x17Bu,
    "void __cdecl vostok::memory::dump_statistics(const bool)",
    "core:",
    info,
    "free:   %11I64d (%6.2f%%)",
    v19 - i,
    v17);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v10,
    (int *)&log_callback);
  boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
    v11,
    &log_callback);
  vostok::logging::append(
    &log_callback,
    0,
    (vostok::logging::log_format *)&vostok::logging::format_message,
    ".\\memory.cpp",
    0x17Cu,
    "void __cdecl vostok::memory::dump_statistics(const bool)",
    "core:",
    info,
    "size:   %11I64d",
    v19);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v12,
    (int *)&log_callback);
}
