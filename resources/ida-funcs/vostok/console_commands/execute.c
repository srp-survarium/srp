void __usercall vostok::console_commands::execute(
        char *command_to_execute@<eax>,
        vostok::console_commands::execution_filter filter)
{
  int v3; // eax
  int v4; // ebx
  void *v5; // esp
  const char *v6; // esi
  const char *v7; // ebx
  vostok::console_commands::console_command *v8; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v9; // ecx
  void (__cdecl *v10)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  char v11; // bl
  void (__cdecl *v12)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  char v13; // bl
  char v14[16]; // [esp+0h] [ebp-23Ch] BYREF
  char buff[512]; // [esp+10h] [ebp-22Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+210h] [ebp-2Ch] BYREF
  int v17; // [esp+230h] [ebp-Ch]
  char *v18; // [esp+234h] [ebp-8h]

  v17 = 0;
  strchr(command_to_execute, 0x20u);
  v4 = v3;
  if ( v3 )
  {
    v5 = alloca(v3 - (_DWORD)command_to_execute + 1);
    v18 = v14;
    strncpy_s(v14, v3 - (_DWORD)command_to_execute + 1, command_to_execute, v3 - (_DWORD)command_to_execute);
    v6 = v18;
    v7 = (const char *)(v4 + 1);
  }
  else
  {
    v6 = command_to_execute;
    v7 = 0;
  }
  v8 = vostok::console_commands::find(v6);
  if ( v8 )
  {
    if ( filter == execution_filter_all || v8->m_execution_type == filter )
    {
      if ( v7 && strlen(v7) || !v8->m_need_args )
      {
        v8->execute(v8, v7);
      }
      else
      {
        v8->status(v8, (char (*)[512])buff);
        if ( vostok::core::g_log_filter_tree
          && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "core:", info) )
        {
          v13 = v17;
        }
        else
        {
          v12 = vostok::core::g_log_callback;
          log_callback.vtable = 0;
          if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
            `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
              &log_callback.functor,
              &log_callback.functor,
              destroy_functor_tag);
          if ( v12 )
          {
            log_callback.functor.obj_ptr = v12;
            log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                         + 1);
          }
          else
          {
            log_callback.vtable = 0;
          }
          v13 = 2;
          vostok::logging::append(
            &log_callback,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            &stru_95AD3C.m_string.m_buffer[100],
            0x7Cu,
            &stru_95AD3C.m_string.m_buffer[160],
            "core:",
            info,
            buff);
        }
        if ( (v13 & 2) != 0 )
          goto LABEL_16;
      }
    }
  }
  else if ( filter )
  {
    if ( vostok::core::g_log_filter_tree
      && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "core:", warning) )
    {
      v11 = v17;
    }
    else
    {
      v10 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v10 )
      {
        log_callback.functor.obj_ptr = v10;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v11 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        &stru_95AD3C.m_string.m_buffer[100],
        0x71u,
        &stru_95AD3C.m_string.m_buffer[160],
        "core:",
        warning,
        &stru_95AD3C.m_string.m_buffer[132],
        v6);
    }
    if ( (v11 & 1) != 0 )
LABEL_16:
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        v9,
        (int *)&log_callback);
  }
}
