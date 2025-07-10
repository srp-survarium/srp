void __usercall vostok::console_commands::show_help(vostok::console_commands::console_command *command@<eax>)
{
  void (__thiscall *info)(vostok::console_commands::console_command *, char (*)[512]); // edx
  char v3; // bl
  vostok::strings::detail::tuples *v4; // ecx
  void *v5; // esp
  vostok::strings::detail::tuples *v6; // ecx
  void (__cdecl *v7)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  char v9[16]; // [esp+0h] [ebp-268h] BYREF
  char info_buff[512]; // [esp+10h] [ebp-258h] BYREF
  vostok::strings::detail::tuples STR_JOINA_tuples_unique_identifier; // [esp+210h] [ebp-58h] BYREF
  int v12; // [esp+244h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+248h] [ebp-20h] BYREF

  info = command->info;
  v3 = 0;
  v12 = 0;
  info(command, (char (*)[512])info_buff);
  vostok::strings::detail::tuples::tuples(
    &STR_JOINA_tuples_unique_identifier,
    command->m_name,
    (const char *)&stru_95963C.m_max_end,
    info_buff);
  v5 = alloca(vostok::strings::detail::tuples::size(v4, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
  vostok::strings::detail::tuples::size(v6, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
  vostok::strings::detail::tuples::concat(v9, &STR_JOINA_tuples_unique_identifier);
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "core:", info) )
  {
    v7 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v7 )
    {
      log_callback.functor.obj_ptr = v7;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    v3 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      &stru_95AD3C.m_string.m_buffer[100],
      0x1Au,
      stru_95AD3C.m_string.m_buffer,
      "core:",
      info,
      v9);
  }
  if ( (v3 & 1) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
  {
    v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
    if ( v8 )
      v8(&log_callback.functor, &log_callback.functor, 2);
  }
}
