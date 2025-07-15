void __cdecl vostok::core::debug_log_callback(
        const char *initiator,
        bool is_error_verbosity,
        bool log_only_user_string,
        const char *message)
{
  vostok::command_line::key::type_enum m_type; // eax
  vostok::strings::detail::tuples *v5; // ecx
  void *v6; // esp
  vostok::strings::detail::tuples *v7; // ecx
  void (__cdecl *v8)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  char v10[12]; // [esp+0h] [ebp-64h] BYREF
  vostok::strings::detail::tuples STR_JOINA_tuples_unique_identifier; // [esp+Ch] [ebp-58h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+40h] [ebp-24h] BYREF
  vostok::core::log_flags_enum log_flags; // [esp+60h] [ebp-4h] BYREF

  m_type = s_write_errors_to_stderr.m_type;
  if ( s_write_errors_to_stderr.m_type == type_unset )
  {
    LOBYTE(log_flags) = 0;
    s_write_errors_to_stderr.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    m_type = s_write_errors_to_stderr.m_type;
  }
  log_flags = m_type != type_recursive ? log_to_stderr : log_to_stdout;
  vostok::strings::detail::tuples::tuples(
    &STR_JOINA_tuples_unique_identifier,
    initiator,
    (const char *)&stru_95963C.m_max_end);
  v6 = alloca(vostok::strings::detail::tuples::size(v5, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
  vostok::strings::detail::tuples::size(v7, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
  vostok::strings::detail::tuples::concat(v10, &STR_JOINA_tuples_unique_identifier);
  v8 = vostok::core::g_log_callback;
  log_callback.vtable = 0;
  if ( log_only_user_string )
  {
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v8 )
    {
      log_callback.functor.obj_ptr = v8;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    vostok::logging::append(
      &log_callback,
      &log_flags,
      &vostok::logging::format_message,
      ".\\logging_extensions.cpp",
      0xC4u,
      "void __cdecl vostok::core::debug_log_callback(const char *,bool,bool,const char *)",
      v10,
      (vostok::logging::verbosity)(2 * !is_error_verbosity + 2),
      "%s",
      message);
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v9 )
LABEL_21:
          v9(&log_callback.functor, &log_callback.functor, 2);
      }
    }
  }
  else
  {
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v8 )
    {
      log_callback.functor.obj_ptr = v8;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    vostok::logging::append(
      &log_callback,
      &log_flags,
      &vostok::core::g_log_format,
      ".\\logging_extensions.cpp",
      0xC8u,
      "void __cdecl vostok::core::debug_log_callback(const char *,bool,bool,const char *)",
      v10,
      (vostok::logging::verbosity)(2 * !is_error_verbosity + 2),
      "%s",
      message);
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v9 )
          goto LABEL_21;
      }
    }
  }
  if ( vostok::core::g_log_file )
    vostok::logging::log_file::flush(vostok::core::g_log_file, 0);
}
