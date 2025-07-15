void __usercall vostok::tasks::thread_pool::log(
        vostok::tasks::thread_pool *this@<eax>,
        vostok::tasks::thread_tls *tls@<ecx>,
        const char *format,
        ...)
{
  unsigned int v3; // eax
  unsigned int v4; // ecx
  int i; // ecx
  void (__cdecl *v6)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+8h] [ebp-230h] BYREF
  vostok::fixed_string<512> output; // [esp+28h] [ebp-210h] BYREF
  char v10; // [esp+234h] [ebp-4h] BYREF
  va_list argptr; // [esp+244h] [ebp+Ch] BYREF

  va_start(argptr, format);
  if ( this->m_do_logging )
  {
    v3 = 0x50u / (this->m_task_thread_tls.m_end - this->m_task_thread_tls.m_begin + 1);
    output.m_begin = output.m_buffer;
    output.m_end = output.m_buffer;
    output.m_max_end = &v10;
    output.m_buffer[0] = 0;
    if ( !tls || tls->thread_type )
      v4 = 0;
    else
      v4 = tls->thread_index + 1;
    for ( i = v3 * v4; i; *output.m_end = 0 )
    {
      *output.m_end = 32;
      --i;
      ++output.m_end;
    }
    vostok::buffer_string::appendf_va_list(&output, format, argptr);
    v6 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v6 )
    {
      log_callback.functor.obj_ptr = v6;
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
      ".\\tasks_thread_pool_utils.cpp",
      0xC5u,
      "void __cdecl vostok::tasks::thread_pool::log(class vostok::tasks::thread_tls *,const char *,...)",
      (const char *)&stru_95C280.m_max_end,
      info,
      "%s",
      output.m_begin);
    if ( log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
    {
      v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v7 )
        v7(&log_callback.functor, &log_callback.functor, 2);
    }
  }
}
