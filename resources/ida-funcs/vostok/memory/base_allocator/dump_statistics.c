void __usercall vostok::memory::base_allocator::dump_statistics(
        vostok::memory::base_allocator *this@<ecx>,
        int a2@<edi>)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v2; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // ecx
  bool v8; // zf
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-48h] BYREF
  __int64 v11; // [esp+30h] [ebp-28h]
  int v12; // [esp+38h] [ebp-20h]
  int v13; // [esp+40h] [ebp-18h]
  char *format[2]; // [esp+48h] [ebp-10h]
  int v15; // [esp+50h] [ebp-8h]
  float v16; // [esp+54h] [ebp-4h]

  v12 = (*(int (__thiscall **)(int))(*(_DWORD *)a2 + 8))(a2);
  v13 = (*(int (__thiscall **)(int))(*(_DWORD *)a2 + 12))(a2);
  boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
    v2,
    &log_callback);
  vostok::logging::append(
    &log_callback,
    0,
    (vostok::logging::log_format *)&vostok::logging::format_message,
    ".\\memory_base_allocator.cpp",
    0x4Eu,
    "void __thiscall vostok::memory::base_allocator::dump_statistics(void) const",
    "core:",
    info,
    "--------------- memory stats for arena [%s] ---------------",
    *(const char **)(a2 + 12));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&log_callback);
  *(_QWORD *)format = 0;
  v15 = v12;
  v16 = (double)(unsigned int)v12 - (double)0LL;
  if ( v16 == 0.0 )
  {
    format[1] = 0;
  }
  else
  {
    v11 = (unsigned int)v13;
    format[0] = 0;
    *(float *)&format[1] = ((double)(unsigned int)v13 - (double)0LL) / v16 * s_spot_max_distance;
  }
  boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
    (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)0x80000000,
    &log_callback);
  vostok::logging::append(
    &log_callback,
    0,
    (vostok::logging::log_format *)&vostok::logging::format_message,
    ".\\memory_base_allocator.cpp",
    0x4Fu,
    "void __thiscall vostok::memory::base_allocator::dump_statistics(void) const",
    "core:",
    info,
    "used:   %11I64d (%6.2f%%)",
    (unsigned __int64)(unsigned int)v13,
    *(float *)&format[1]);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&log_callback);
  if ( v16 == 0.0 )
  {
    format[1] = 0;
  }
  else
  {
    v5 = 0;
    LODWORD(v11) = v12 - v13;
    format[0] = 0;
    HIDWORD(v11) = (((unsigned int)v12 - (unsigned __int64)(unsigned int)v13) >> 32) & 0x7FFFFFFF;
    *(float *)&format[1] = (double)((unsigned int)v12 - (unsigned __int64)(unsigned int)v13) / v16 * s_spot_max_distance;
  }
  boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
    v5,
    &log_callback);
  vostok::logging::append(
    &log_callback,
    0,
    (vostok::logging::log_format *)&vostok::logging::format_message,
    ".\\memory_base_allocator.cpp",
    0x50u,
    "void __thiscall vostok::memory::base_allocator::dump_statistics(void) const",
    "core:",
    info,
    "free:   %11I64d (%6.2f%%)",
    (unsigned int)v12 - (unsigned __int64)(unsigned int)v13,
    *(float *)&format[1]);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v6,
    (int *)&log_callback);
  v8 = *(_DWORD *)(a2 + 4) == 0;
  format[1] = "size:   %11I64d, start address: 0x%09I64x, end address: 0x%09I64x";
  if ( v8 )
    format[1] = "size:   %11I64d";
  boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
    v7,
    &log_callback);
  vostok::logging::append(
    &log_callback,
    0,
    (vostok::logging::log_format *)&vostok::logging::format_message,
    ".\\memory_base_allocator.cpp",
    0x5Cu,
    "void __thiscall vostok::memory::base_allocator::dump_statistics(void) const",
    "core:",
    info,
    format[1],
    v12,
    0,
    *(_DWORD *)(a2 + 4),
    0,
    *(_DWORD *)(a2 + 8),
    0);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v9,
    (int *)&log_callback);
}
