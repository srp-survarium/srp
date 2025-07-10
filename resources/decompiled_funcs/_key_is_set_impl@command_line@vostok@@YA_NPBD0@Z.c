void __usercall vostok::command_line::key_is_set_impl(const char *key_raw@<eax>, char *command_line)
{
  bool v2; // zf
  const char *v3; // esi
  char v4; // bl
  void (__cdecl *v5)(vostok::strings::detail::tuples::pair *, vostok::strings::detail::tuples::pair *, int); // eax
  vostok::strings::detail::tuples *v6; // ecx
  void *v7; // esp
  vostok::strings::detail::tuples *v8; // ecx
  char v9; // dl
  const char *v10; // esi
  unsigned __int8 *v11; // eax
  char *v12; // ecx
  unsigned __int8 v13; // al
  char v14[16]; // [esp+0h] [ebp-54h] BYREF
  vostok::strings::detail::tuples STR_JOINA_tuples_unique_identifier; // [esp+10h] [ebp-44h] BYREF
  int v16; // [esp+4Ch] [ebp-8h]

  v2 = *key_raw == 0;
  v16 = 0;
  if ( v2 )
  {
    if ( vostok::core::g_log_filter_tree
      && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "command_line_key:", warning) )
    {
      v4 = v16;
    }
    else
    {
      v3 = (const char *)vostok::core::g_log_callback;
      STR_JOINA_tuples_unique_identifier.m_strings[2].first = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          (const boost::detail::function::function_buffer *)&STR_JOINA_tuples_unique_identifier.m_strings[3],
          (boost::detail::function::function_buffer *)&STR_JOINA_tuples_unique_identifier.m_strings[3],
          destroy_functor_tag);
      if ( v3 )
      {
        STR_JOINA_tuples_unique_identifier.m_strings[3].first = v3;
        STR_JOINA_tuples_unique_identifier.m_strings[2].first = (char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1;
      }
      else
      {
        STR_JOINA_tuples_unique_identifier.m_strings[2].first = 0;
      }
      v4 = 1;
      vostok::logging::append(
        (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&STR_JOINA_tuples_unique_identifier.m_strings[2],
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\command_line.cpp",
        0x203u,
        "bool __cdecl vostok::command_line::key_is_set_impl(const char *,const char *)",
        "command_line_key:",
        warning,
        "empty key specified to ");
    }
    if ( (v4 & 1) != 0
      && STR_JOINA_tuples_unique_identifier.m_strings[2].first
      && ((int)STR_JOINA_tuples_unique_identifier.m_strings[2].first & 1) == 0 )
    {
      v5 = *(void (__cdecl **)(vostok::strings::detail::tuples::pair *, vostok::strings::detail::tuples::pair *, int))((int)STR_JOINA_tuples_unique_identifier.m_strings[2].first & 0xFFFFFFFE);
      if ( v5 )
        v5(&STR_JOINA_tuples_unique_identifier.m_strings[3], &STR_JOINA_tuples_unique_identifier.m_strings[3], 2);
    }
  }
  else
  {
    vostok::strings::detail::tuples::tuples(&STR_JOINA_tuples_unique_identifier, "-", key_raw);
    v7 = alloca(vostok::strings::detail::tuples::size(v6, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
    vostok::strings::detail::tuples::size(v8, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
    vostok::strings::detail::tuples::concat(v14, &STR_JOINA_tuples_unique_identifier);
    v9 = *command_line;
    v10 = command_line;
    if ( *command_line )
    {
      while ( 1 )
      {
        v11 = (unsigned __int8 *)v10;
        v12 = v14;
        if ( v9 )
          break;
LABEL_22:
        if ( !*v12 )
          goto LABEL_25;
        v9 = *++v10;
        if ( !v9 )
          return;
      }
      while ( *v12 )
      {
        if ( *v11 == *v12 )
        {
          ++v11;
          ++v12;
          if ( *v11 )
            continue;
        }
        goto LABEL_22;
      }
LABEL_25:
      v13 = *v11;
      if ( v13 )
        strchr(" \t=", v13);
    }
  }
}
