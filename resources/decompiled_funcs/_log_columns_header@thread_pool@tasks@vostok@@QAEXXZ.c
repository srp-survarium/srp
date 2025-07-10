void __usercall vostok::tasks::thread_pool::log_columns_header(
        vostok::tasks::thread_pool *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ebp
  unsigned int v3; // edi
  char *m_buffer; // eax
  const char *v5; // ecx
  char *m_end; // eax
  unsigned __int8 *m_begin; // ecx
  unsigned int v8; // ecx
  int v9; // esi
  void (__cdecl *v10)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v11)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  unsigned int column_width; // [esp+14h] [ebp-448h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-444h] BYREF
  vostok::fixed_string<512> column_output; // [esp+38h] [ebp-424h] BYREF
  char v15; // [esp+244h] [ebp-218h] BYREF
  vostok::fixed_string<512> output; // [esp+248h] [ebp-214h] BYREF
  char v17; // [esp+454h] [ebp-8h] BYREF

  if ( a2[40] )
  {
    v2 = (a2[30] - a2[29]) / 360 + 1;
    v3 = 0;
    output.m_begin = output.m_buffer;
    output.m_end = output.m_buffer;
    output.m_buffer[0] = 0;
    column_width = 0x50 / v2;
    output.m_max_end = &v17;
    do
    {
      m_buffer = column_output.m_buffer;
      column_output.m_begin = column_output.m_buffer;
      column_output.m_end = column_output.m_buffer;
      column_output.m_max_end = &v15;
      column_output.m_buffer[0] = 0;
      if ( v3 )
      {
        vostok::buffer_string::appendf((vostok::buffer_string *)&stru_95C280, (const char *)(v3 - 1));
      }
      else
      {
        v5 = "user";
        do
        {
          if ( m_buffer >= column_output.m_max_end )
            break;
          *m_buffer = *v5;
          m_buffer = column_output.m_end + 1;
          ++v5;
          ++column_output.m_end;
        }
        while ( *v5 );
        *m_buffer = 0;
      }
      m_end = column_output.m_end;
      m_begin = (unsigned __int8 *)column_output.m_begin;
      if ( column_output.m_end - column_output.m_begin < column_width )
      {
        v8 = column_width - (column_output.m_end - column_output.m_begin);
        do
        {
          *m_end = 32;
          --v8;
          *++column_output.m_end = 0;
          m_end = column_output.m_end;
        }
        while ( v8 );
        m_begin = (unsigned __int8 *)column_output.m_begin;
      }
      v9 = m_end - (char *)m_begin;
      memcpy((unsigned __int8 *)output.m_end, m_begin, m_end - (char *)m_begin);
      ++v3;
      output.m_end += v9;
      *output.m_end = 0;
    }
    while ( v3 < v2 );
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
    vostok::logging::append(
      &log_callback,
      (void *const)1,
      &vostok::logging::format_message,
      ".\\tasks_thread_pool_utils.cpp",
      0xAFu,
      "void __thiscall vostok::tasks::thread_pool::log_columns_header(void)",
      (const char *)&stru_95C280.m_max_end,
      info,
      "%s",
      output.m_begin);
    if ( log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
    {
      v11 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v11 )
        v11(&log_callback.functor, &log_callback.functor, 2);
    }
  }
}
