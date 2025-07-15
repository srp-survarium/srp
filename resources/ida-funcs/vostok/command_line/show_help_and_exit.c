int vostok::command_line::show_help_and_exit()
{
  void *v0; // esp
  vostok::command_line::key **p_m_first; // esi
  vostok::threading::mutex_tasks_unaware *v2; // ebx
  vostok::command_line::key *v3; // esi
  vostok::command_line::key **v4; // esi
  vostok::command_line::key **v5; // edi
  int v6; // eax
  int v7; // ecx
  unsigned int v8; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  vostok::fixed_string<512> *v10; // ecx
  vostok::command_line::key **v11; // eax
  const char *v12; // esi
  char *v13; // esi
  char *m_begin; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v15; // ecx
  const char *v16; // eax
  vostok::buffer_string *v17; // ecx
  bool v18; // zf
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v19; // ecx
  const char *v21; // [esp-8h] [ebp-8C0h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v22; // [esp-4h] [ebp-8BCh]
  vostok::buffer_string *v23; // [esp-4h] [ebp-8BCh]
  vostok::buffer_string *v24; // [esp-4h] [ebp-8BCh]
  _DWORD v25[4]; // [esp+0h] [ebp-8B8h] BYREF
  vostok::buffer_string v26; // [esp+10h] [ebp-8A8h] BYREF
  char *format[3]; // [esp+220h] [ebp-698h] BYREF
  _BYTE v28[512]; // [esp+22Ch] [ebp-68Ch] BYREF
  char v29; // [esp+42Ch] [ebp-48Ch] BYREF
  _DWORD v30[3]; // [esp+430h] [ebp-488h] BYREF
  _BYTE v31[512]; // [esp+43Ch] [ebp-47Ch] BYREF
  char v32; // [esp+63Ch] [ebp-27Ch] BYREF
  vostok::buffer_string out_dest; // [esp+640h] [ebp-278h] BYREF
  _BYTE v34[512]; // [esp+64Ch] [ebp-26Ch] BYREF
  char v35; // [esp+84Ch] [ebp-6Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+850h] [ebp-68h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v37; // [esp+870h] [ebp-48h] BYREF
  vostok::command_line::command_line_key_adder v38; // [esp+894h] [ebp-24h] BYREF
  char *right; // [esp+8A0h] [ebp-18h]
  vostok::command_line::key **__first; // [esp+8A4h] [ebp-14h] BYREF
  vostok::command_line::key **__last; // [esp+8A8h] [ebp-10h]
  _DWORD *v42; // [esp+8ACh] [ebp-Ch]
  vostok::command_line::key_compare_predicate __comp[4]; // [esp+8B0h] [ebp-8h]
  const char *m_next_key; // [esp+8B4h] [ebp-4h]

  v0 = alloca(4 * HIDWORD(s_command_line_keys_creation.m_mutex[0]));
  __first = (vostok::command_line::key **)v25;
  __last = (vostok::command_line::key **)v25;
  v38.keys_ = (vostok::buffer_vector<vostok::command_line::key *> *)&__first;
  v42 = &v25[HIDWORD(s_command_line_keys_creation.m_mutex[0])];
  p_m_first = &s_command_line_keys->m_first;
  v38.longest_short_key_name = 0;
  v38.longest_full_key_name = 0;
  if ( s_command_line_keys->m_first )
  {
    v2 = &s_command_line_keys->vostok::threading::mutex_tasks_unaware;
    EnterCriticalSection((LPCRITICAL_SECTION)&s_command_line_keys->vostok::threading::mutex_tasks_unaware);
    v3 = *p_m_first;
    if ( v3 )
    {
      do
      {
        m_next_key = (const char *)v3->m_next_key;
        vostok::command_line::command_line_key_adder::operator()(&v38, v3);
        v3 = (vostok::command_line::key *)m_next_key;
      }
      while ( m_next_key );
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)v2);
  }
  v4 = __first;
  __comp[0] = 0;
  v5 = __last;
  if ( __first != __last )
  {
    v6 = __last - __first;
    v7 = 0;
    while ( v6 != 1 )
    {
      ++v7;
      v6 >>= 1;
    }
    stlp_std::priv::__introsort_loop<vostok::command_line::key * *,vostok::command_line::key *,int,vostok::command_line::key_compare_predicate>(
      (vostok::command_line::key_compare_predicate *)__last,
      __first,
      __last,
      0,
      2 * v7,
      *(vostok::command_line::key ***)__comp);
    stlp_std::priv::__final_insertion_sort<vostok::command_line::key * *,vostok::command_line::key_compare_predicate>(
      v4,
      v5,
      *(vostok::command_line::key **)__comp);
  }
  format[0] = v28;
  format[1] = v28;
  format[2] = &v29;
  v28[0] = 0;
  vostok::fs_new::path_string_impl::assignf(
    (int)format,
    (vostok::buffer_string *)v38.longest_short_key_name,
    (vostok::buffer_string *)&stru_8027D4,
    (const char *)(v38.longest_full_key_name + v38.longest_short_key_name + 5));
  boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
    v22,
    &log_callback);
  v21 = s_build_date;
  v8 = build_id((char *)s_build_date);
  vostok::logging::append(
    &log_callback,
    (void *const)1,
    (vostok::logging::log_format *)&vostok::logging::format_message,
    ".\\command_line.cpp",
    0x1C8u,
    "void __cdecl vostok::command_line::show_help_and_exit(void)",
    "core:",
    info,
    "               Vostok Engine v0.20e, build %d, %s\n"
    "                  Copyright(C) Vostok Games - 2013\n"
    "      Finger print info: %s",
    v8,
    v21,
    (const char *)&s_command_line_keys_creation.m_mutex[2]);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v9,
    (int *)&log_callback);
  v11 = __first;
  right = (char *)uri;
  *(_DWORD *)__comp = __first;
  while ( v11 != __last )
  {
    v12 = **(const char ***)__comp;
    m_next_key = **(const char ***)__comp;
    if ( *(vostok::command_line::key ***)__comp == __first
      || vostok::strings::compare(*((const char **)v12 + 134), right) )
    {
      v13 = (char *)*((_DWORD *)v12 + 134);
      if ( !*v13 )
        v13 = "global";
      vostok::fixed_string<512>::fixed_string<512>(v10, &v26, v13);
      out_dest.m_begin = v34;
      out_dest.m_end = v34;
      out_dest.m_max_end = &v35;
      v34[0] = 0;
      vostok::buffer_string::substr(0, (char *)1, &out_dest, &v26);
      if ( out_dest.m_end != out_dest.m_begin )
        _strupr_s(out_dest.m_begin, out_dest.m_end - out_dest.m_begin + 1);
      m_begin = v26.m_begin;
      *v26.m_begin = *out_dest.m_begin;
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)m_begin,
        &v37);
      vostok::logging::append(
        &v37,
        (void *const)1,
        (vostok::logging::log_format *)&vostok::logging::format_message,
        ".\\command_line.cpp",
        0x1D9u,
        "void __cdecl vostok::command_line::show_help_and_exit(void)",
        "core:",
        info,
        "\n%s options: ",
        v26.m_begin);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v15,
        (int *)&v37);
      v12 = m_next_key;
      right = (char *)*((_DWORD *)m_next_key + 134);
    }
    v30[0] = v31;
    v30[1] = v31;
    v30[2] = &v32;
    v31[0] = 0;
    v16 = (const char *)*((_DWORD *)v12 + 133);
    if ( !*v16 )
      goto LABEL_22;
    v10 = (vostok::fixed_string<512> *)*((_DWORD *)v12 + 132);
    if ( LOBYTE(v10->m_begin) )
    {
      vostok::fs_new::path_string_impl::assignf(
        (int)v30,
        v10,
        (vostok::buffer_string *)&stru_8028C0,
        (const char *)v10,
        v16);
      goto LABEL_24;
    }
    if ( !*v16 )
LABEL_22:
      v16 = (const char *)*((_DWORD *)v12 + 132);
    vostok::fs_new::path_string_impl::assignf((int)v30, v10, (vostok::buffer_string *)&stru_8028CC, v16);
    v17 = v23;
LABEL_24:
    if ( **((_BYTE **)v12 + 136) )
    {
      vostok::buffer_string::appendf(v30, v17, (vostok::buffer_string *)&stru_8028CC.m_end, *((const char **)v12 + 136));
      v17 = v24;
    }
    v18 = **((_BYTE **)v12 + 135) == 0;
    m_next_key = ":";
    if ( v18 )
      m_next_key = uri;
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v17,
      &v37);
    vostok::logging::append(
      &v37,
      (void *const)1,
      (vostok::logging::log_format *)&vostok::logging::format_message,
      ".\\command_line.cpp",
      0x1E9u,
      "void __cdecl vostok::command_line::show_help_and_exit(void)",
      "core:",
      info,
      format[0],
      v30[0],
      m_next_key,
      *((_DWORD *)v12 + 135));
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v19,
      (int *)&v37);
    *(_DWORD *)__comp += 4;
    v11 = *(vostok::command_line::key ***)__comp;
  }
  if ( !HIDWORD(s_command_line_keys_creation.m_mutex[1]) )
    vostok::debug::terminate((char *)uri);
  return (*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)HIDWORD(s_command_line_keys_creation.m_mutex[1]) + 64))(
           HIDWORD(s_command_line_keys_creation.m_mutex[1]),
           0);
}
