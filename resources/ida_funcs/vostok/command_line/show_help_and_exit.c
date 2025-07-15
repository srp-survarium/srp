void __cdecl vostok::command_line::show_help_and_exit()
{
  void *v0; // esp
  void (__cdecl *v1)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  unsigned int v2; // eax
  void (__cdecl *v3)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::command_line::key **v4; // eax
  vostok::command_line::key **v5; // ecx
  vostok::command_line::key *v6; // edi
  const char *m_category; // ecx
  char *m_begin; // edx
  char *m_end; // eax
  char *v10; // ecx
  char *v11; // esi
  char *v12; // eax
  char *v13; // esi
  void (__cdecl *v14)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v15)(char *, char *, int); // eax
  const char *m_short_name; // eax
  const char *m_full_name; // ecx
  char **p_m_max_end; // esi
  void (__cdecl *v19)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  void (__cdecl *v20)(char *, char *, int); // eax
  const char *v21; // [esp-8h] [ebp-8C0h]
  _BYTE v22[16]; // [esp+0h] [ebp-8B8h] BYREF
  vostok::buffer_string v23; // [esp+10h] [ebp-8A8h] BYREF
  _BYTE v24[512]; // [esp+1Ch] [ebp-89Ch] BYREF
  char v25; // [esp+21Ch] [ebp-69Ch] BYREF
  vostok::buffer_string v26; // [esp+220h] [ebp-698h] BYREF
  _BYTE v27[512]; // [esp+22Ch] [ebp-68Ch] BYREF
  char v28; // [esp+42Ch] [ebp-48Ch] BYREF
  vostok::buffer_string string; // [esp+430h] [ebp-488h] BYREF
  _BYTE v30[512]; // [esp+43Ch] [ebp-47Ch] BYREF
  char v31; // [esp+63Ch] [ebp-27Ch] BYREF
  vostok::buffer_string v32; // [esp+640h] [ebp-278h] BYREF
  _BYTE v33[512]; // [esp+64Ch] [ebp-26Ch] BYREF
  char v34; // [esp+84Ch] [ebp-6Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+850h] [ebp-68h] BYREF
  vostok::intrusive_list<vostok::command_line::key,vostok::command_line::key *,552,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy> v36; // [esp+874h] [ebp-44h] BYREF
  vostok::command_line::key **v37; // [esp+8A4h] [ebp-14h]
  vostok::command_line::key **__first; // [esp+8A8h] [ebp-10h] BYREF
  vostok::command_line::key **__last; // [esp+8ACh] [ebp-Ch]
  vostok::command_line::key *v40; // [esp+8B0h] [ebp-8h]
  vostok::intrusive_list<vostok::command_line::key,vostok::command_line::key *,552,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::command_line::command_line_key_adder> pred; // [esp+8B4h] [ebp-4h] BYREF

  v0 = alloca(4 * s_command_line_keys_count);
  __first = (vostok::command_line::key **)v22;
  __last = (vostok::command_line::key **)v22;
  v36.m_size = (unsigned int)&__first;
  *((_DWORD *)&v36.vostok::size_policy + 1) = 0;
  LODWORD(v36.m_mutex[0]) = 0;
  pred.m_predicate_ref = (vostok::command_line::command_line_key_adder *)&v36;
  vostok::intrusive_list<vostok::command_line::key,vostok::command_line::key *,552,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<vostok::command_line::key,vostok::command_line::key *,552,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::command_line::command_line_key_adder>>(
    &v36,
    (int)s_command_line_keys,
    &pred);
  LOBYTE(pred.m_predicate_ref) = 0;
  stlp_std::sort<vostok::command_line::key * *,vostok::command_line::key_compare_predicate>(__first, __last, 0);
  v23.m_begin = v24;
  v23.m_end = v24;
  v23.m_max_end = &v25;
  v24[0] = 0;
  vostok::buffer_string::assignf(
    &v23,
    "    %%-%ds  %%s %%s",
    LODWORD(v36.m_mutex[0]) + *((_DWORD *)&v36.vostok::size_policy + 1) + 5);
  v1 = vostok::core::g_log_callback;
  log_callback.vtable = 0;
  if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
    `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
      &log_callback.functor,
      &log_callback.functor,
      destroy_functor_tag);
  if ( v1 )
  {
    log_callback.functor.obj_ptr = v1;
    log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                 + 1);
  }
  else
  {
    log_callback.vtable = 0;
  }
  v21 = s_build_date;
  v2 = build_id(s_build_date);
  vostok::logging::append(
    &log_callback,
    (void *const)1,
    &vostok::logging::format_message,
    ".\\command_line.cpp",
    0x1C7u,
    "void __cdecl vostok::command_line::show_help_and_exit(void)",
    "core:",
    info,
    "               Vostok Engine v0.1, build %d, %s\n"
    "                  Copyright(C) Vostok Games - 2013\n"
    "      Finger print info: %s",
    v2,
    v21,
    (const char *)&vostok::memory::g_crt_allocator.m_arena_start);
  if ( log_callback.vtable )
  {
    if ( ((int)log_callback.vtable & 1) == 0 )
    {
      v3 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v3 )
        v3(&log_callback.functor, &log_callback.functor, 2);
    }
    log_callback.vtable = 0;
  }
  v4 = __first;
  v5 = __first;
  pred.m_predicate_ref = (vostok::command_line::command_line_key_adder *)&buf;
  v37 = __first;
  if ( __first != __last )
  {
    while ( 1 )
    {
      v6 = *v5;
      v40 = *v5;
      if ( v5 == v4 || strcmp(v6->m_category, (const char *)pred.m_predicate_ref) )
      {
        m_category = v6->m_category;
        if ( !*m_category )
          m_category = "global";
        m_begin = v33;
        m_end = v33;
        v32.m_begin = v33;
        v32.m_end = v33;
        v32.m_max_end = &v34;
        v33[0] = 0;
        if ( m_category )
        {
          for ( ; *m_category; ++v32.m_end )
          {
            if ( m_end >= v32.m_max_end )
              break;
            v6 = v40;
            *m_end = *m_category;
            m_end = v32.m_end + 1;
            ++m_category;
          }
          *m_end = 0;
          m_end = v32.m_end;
          m_begin = v32.m_begin;
        }
        string.m_begin = v30;
        string.m_max_end = &v31;
        v10 = v30;
        string.m_end = v30;
        v30[0] = 0;
        v11 = &m_begin[m_end != m_begin];
        v12 = m_begin;
        if ( m_begin != v11 )
        {
          do
          {
            *v10 = *v12++;
            v10 = ++string.m_end;
          }
          while ( v12 != v11 );
          v6 = v40;
        }
        *v10 = 0;
        if ( string.m_end != string.m_begin )
          _strupr_s(string.m_begin, string.m_end - string.m_begin + 1);
        v13 = vostok::buffer_string::operator[](&string, 0);
        *vostok::buffer_string::operator[](&v32, 0) = *v13;
        v14 = vostok::core::g_log_callback;
        HIDWORD(v36.m_mutex[0]) = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            (const boost::detail::function::function_buffer *)((char *)&v36.m_mutex[1] + 4),
            (boost::detail::function::function_buffer *)((char *)&v36.m_mutex[1] + 4),
            destroy_functor_tag);
        if ( v14 )
        {
          HIDWORD(v36.m_mutex[1]) = v14;
          HIDWORD(v36.m_mutex[0]) = (char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                  + 1;
        }
        else
        {
          HIDWORD(v36.m_mutex[0]) = 0;
        }
        vostok::logging::append(
          (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)((char *)v36.m_mutex + 4),
          (void *const)1,
          &vostok::logging::format_message,
          ".\\command_line.cpp",
          0x1D8u,
          "void __cdecl vostok::command_line::show_help_and_exit(void)",
          "core:",
          info,
          "\n%s options: ",
          v32.m_begin);
        if ( HIDWORD(v36.m_mutex[0]) )
        {
          if ( (v36.m_mutex[0] & 0x100000000LL) == 0 )
          {
            v15 = *(void (__cdecl **)(char *, char *, int))(HIDWORD(v36.m_mutex[0]) & 0xFFFFFFFE);
            if ( v15 )
              v15((char *)&v36.m_mutex[1] + 4, (char *)&v36.m_mutex[1] + 4, 2);
          }
        }
        pred.m_predicate_ref = (vostok::command_line::command_line_key_adder *)v6->m_category;
      }
      v26.m_begin = v27;
      v26.m_end = v27;
      v26.m_max_end = &v28;
      v27[0] = 0;
      m_short_name = v6->m_short_name;
      if ( !*m_short_name )
        goto LABEL_42;
      m_full_name = v6->m_full_name;
      if ( *m_full_name )
      {
        vostok::buffer_string::assignf(&v26, "-%s [-%s]", m_full_name, m_short_name);
        goto LABEL_44;
      }
      if ( !*m_short_name )
LABEL_42:
        m_short_name = v6->m_full_name;
      vostok::buffer_string::assignf(&v26, "-%s", m_short_name);
LABEL_44:
      if ( *v6->m_argument_description )
        vostok::buffer_string::appendf((vostok::buffer_string *)&stru_95963C, v6->m_argument_description);
      p_m_max_end = &stru_95963C.m_max_end;
      if ( !*v6->m_description )
        p_m_max_end = (char **)&buf;
      v19 = vostok::core::g_log_callback;
      HIDWORD(v36.m_mutex[0]) = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          (const boost::detail::function::function_buffer *)((char *)&v36.m_mutex[1] + 4),
          (boost::detail::function::function_buffer *)((char *)&v36.m_mutex[1] + 4),
          destroy_functor_tag);
      if ( v19 )
      {
        HIDWORD(v36.m_mutex[1]) = v19;
        HIDWORD(v36.m_mutex[0]) = (char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                + 1;
      }
      else
      {
        HIDWORD(v36.m_mutex[0]) = 0;
      }
      vostok::logging::append(
        (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)((char *)v36.m_mutex + 4),
        (void *const)1,
        &vostok::logging::format_message,
        ".\\command_line.cpp",
        0x1E8u,
        "void __cdecl vostok::command_line::show_help_and_exit(void)",
        "core:",
        info,
        v23.m_begin,
        v26.m_begin,
        p_m_max_end,
        v40->m_description);
      if ( HIDWORD(v36.m_mutex[0]) )
      {
        if ( (v36.m_mutex[0] & 0x100000000LL) == 0 )
        {
          v20 = *(void (__cdecl **)(char *, char *, int))(HIDWORD(v36.m_mutex[0]) & 0xFFFFFFFE);
          if ( v20 )
            v20((char *)&v36.m_mutex[1] + 4, (char *)&v36.m_mutex[1] + 4, 2);
        }
        HIDWORD(v36.m_mutex[0]) = 0;
      }
      if ( ++v37 == __last )
        break;
      v4 = __first;
      v5 = v37;
    }
  }
  if ( !s_engine )
    vostok::debug::terminate((char *)&buf);
  s_engine->exit(s_engine, 0);
}
