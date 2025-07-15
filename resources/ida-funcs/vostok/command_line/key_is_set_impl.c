bool __usercall vostok::command_line::key_is_set_impl@<al>(
        boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *command_line@<ecx>,
        char *key_raw@<eax>)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v2; // edi
  bool has_passed_filters; // al
  vostok::strings::detail::tuples *v5; // ecx
  void *v6; // esp
  vostok::strings::detail::tuples *v7; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // esi
  char vtable; // dl
  _BYTE *v10; // ecx
  unsigned __int8 *v11; // eax
  unsigned __int8 v12; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v13; // [esp-4h] [ebp-54h]
  char v14[16]; // [esp+0h] [ebp-50h] BYREF
  vostok::strings::detail::tuples v15; // [esp+10h] [ebp-40h] BYREF
  int v16; // [esp+4Ch] [ebp-4h]

  v2 = command_line;
  v16 = 0;
  if ( !*key_raw )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&stru_8028DC,
                                 (const char *)3),
          command_line = v13,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        command_line,
        &v15.m_strings[2].first);
      v16 = 1;
      vostok::logging::append(
        (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v15.m_strings[2],
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\command_line.cpp",
        0x204u,
        (const char *)&stru_8028DC.filter_stack.m_policy.m_mutex.m_mutex[1] + 4,
        (char *)&stru_8028DC,
        warning,
        (char *)&stru_8028DC.filter_stack.m_first);
    }
    if ( (v16 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)command_line,
        (int *)&v15.m_strings[2]);
    return 0;
  }
  vostok::strings::detail::tuples::tuples((vostok::strings::detail::tuples *)command_line, &v15, "-", key_raw);
  v6 = alloca(vostok::strings::detail::tuples::size(v5, (unsigned int *)&v15));
  v16 = (int)v14;
  vostok::strings::detail::tuples::concat(v7, (int)&v15, v14);
  v8 = v2;
  if ( !LOBYTE(v2->vtable) )
    return 0;
  vtable = (char)v2->vtable;
  while ( 1 )
  {
    v10 = (_BYTE *)v16;
    v11 = (unsigned __int8 *)v8;
    if ( vtable )
      break;
LABEL_14:
    if ( !*v10 )
      goto LABEL_17;
    v8 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)((char *)v8 + 1);
    vtable = (char)v8->vtable;
    if ( !LOBYTE(v8->vtable) )
      return 0;
  }
  while ( *v10 )
  {
    if ( *v11 == *v10 )
    {
      ++v11;
      ++v10;
      if ( *v11 )
        continue;
    }
    goto LABEL_14;
  }
LABEL_17:
  v12 = *v11;
  return !v12 || vostok::command_line::is_delimiter(v12, " \t=");
}
