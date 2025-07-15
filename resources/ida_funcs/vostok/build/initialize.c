void __cdecl vostok::build::initialize()
{
  unsigned int v0; // eax
  void (__cdecl *v1)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  unsigned int v2; // edi
  unsigned int v3; // eax
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v5)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  const char *v7; // [esp-4h] [ebp-38h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-24h] BYREF

  v0 = build_id(s_build_date);
  v1 = vostok::core::g_log_callback;
  v2 = v0;
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
  v7 = s_build_date;
  v3 = vostok::build::build_station_build_id();
  vostok::logging::append(
    &log_callback,
    0,
    &vostok::core::g_log_format,
    ".\\build_extensions.cpp",
    0x7Du,
    "void __cdecl vostok::build::initialize(struct vostok::core::engine *)",
    "core:",
    info,
    "%s build %d(internal id %d), %s",
    "Vostok Engine v0.1",
    v3,
    v2,
    v7);
  if ( log_callback.vtable )
  {
    if ( ((int)log_callback.vtable & 1) == 0 )
    {
      v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v4 )
        v4(&log_callback.functor, &log_callback.functor, 2);
    }
  }
  if ( s_print_build_id.m_type == type_unset )
  {
    s_print_build_id.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( s_print_build_id.m_type != type_recursive )
  {
    v5 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v5 )
    {
      log_callback.functor.obj_ptr = v5;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    vostok::logging::append(
      &log_callback,
      (void *const)1,
      &vostok::logging::format_message,
      ".\\build_extensions.cpp",
      0x89u,
      "void __cdecl vostok::build::initialize(struct vostok::core::engine *)",
      "core:",
      info,
      "%d",
      v2);
    if ( log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
    {
      v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v6 )
        v6(&log_callback.functor, &log_callback.functor, 2);
    }
    vostok::debug::terminate((char *)&buf);
  }
}
