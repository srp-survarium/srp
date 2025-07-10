void __usercall vostok::memory::managed_allocator_base::log_nodes(
        vostok::memory::managed_allocator_base *this@<ecx>,
        _DWORD *a2@<eax>)
{
  int v3; // ebx
  void (__cdecl *v4)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  _DWORD *i; // edi
  vostok::fixed_string<512> *v7; // eax
  unsigned int v8; // esi
  void (__cdecl *v9)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v10)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-44Ch] BYREF
  int v12; // [esp+34h] [ebp-428h]
  vostok::fixed_string<512> node_name; // [esp+38h] [ebp-424h] BYREF
  char v14; // [esp+244h] [ebp-218h] BYREF
  _BYTE v15[528]; // [esp+24Ch] [ebp-210h] BYREF

  v3 = 0;
  v12 = 0;
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "resources:allocator:", info) )
  {
    v4 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v4 )
    {
      log_callback.functor.obj_ptr = v4;
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
      ".\\managed_allocator_base.cpp",
      0x1B0u,
      "void __thiscall vostok::memory::managed_allocator_base::log_nodes(bool) const",
      "resources:allocator:",
      info,
      "arena size: %d, free size: %d",
      a2[7],
      a2[5]);
  }
  if ( (v3 & 1) != 0 )
  {
    v3 &= ~1u;
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v5 )
          v5(&log_callback.functor, &log_callback.functor, 2);
      }
    }
  }
  for ( i = (_DWORD *)a2[6]; i; i = (_DWORD *)i[1] )
  {
    if ( !*((_BYTE *)i + 48) )
    {
      node_name.m_begin = node_name.m_buffer;
      node_name.m_end = node_name.m_buffer;
      node_name.m_max_end = &v14;
      node_name.m_buffer[0] = 0;
      if ( *((_BYTE *)i + 48) == 1 )
      {
        vostok::buffer_string::appendf((vostok::buffer_string *)&stru_95D540, (const char *)i[10]);
      }
      else
      {
        v7 = (vostok::fixed_string<512> *)(*(int (__thiscall **)(_DWORD, _BYTE *))(*(_DWORD *)*i + 8))(*i, v15);
        if ( &node_name != v7 )
        {
          node_name.m_end = node_name.m_begin;
          *node_name.m_begin = 0;
          v8 = v7->m_end - v7->m_begin;
          memcpy((unsigned __int8 *)node_name.m_end, (unsigned __int8 *)v7->m_begin, v8);
          node_name.m_end += v8;
          *node_name.m_end = 0;
        }
      }
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "resources:allocator:", info) )
      {
        v9 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v9 )
        {
          log_callback.functor.obj_ptr = v9;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v3 |= 2u;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\managed_allocator_base.cpp",
          0x1C9u,
          "void __thiscall vostok::memory::managed_allocator_base::log_nodes(bool) const",
          "resources:allocator:",
          info,
          node_name.m_begin);
      }
      if ( (v3 & 2) != 0 )
      {
        v3 &= ~2u;
        if ( log_callback.vtable )
        {
          if ( ((int)log_callback.vtable & 1) == 0 )
          {
            v10 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
            if ( v10 )
              v10(&log_callback.functor, &log_callback.functor, 2);
          }
        }
      }
    }
  }
}
