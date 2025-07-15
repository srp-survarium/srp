void __cdecl vostok::command_line::check_keys()
{
  void (__cdecl *v0)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v1)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+8h] [ebp-24h] BYREF

  if ( vostok::command_line::s_command_line_error.m_end != vostok::command_line::s_command_line_error.m_begin )
  {
    v0 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v0 )
    {
      log_callback.functor.obj_ptr = v0;
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
      ".\\command_line.cpp",
      0x157u,
      "void __cdecl vostok::command_line::check_keys(void)",
      "core:",
      info,
      "%s",
      vostok::command_line::s_command_line_error.m_begin);
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v1 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v1 )
          v1(&log_callback.functor, &log_callback.functor, 2);
      }
    }
    if ( vostok::debug::is_debugger_present() )
      __debugbreak();
    if ( s_engine )
      s_engine->exit(s_engine, 0);
  }
  vostok::command_line::iterate_keys<vostok::command_line::checker>();
}
