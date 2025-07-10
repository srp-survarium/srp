void __cdecl vostok::memory::dump_statistics(bool dump_stats_for_empty_arenas_as_well)
{
  allocator_data *m_begin; // esi
  allocator_data *m_end; // edi
  unsigned int v3; // ebx
  int v4; // eax
  unsigned int v5; // et0
  void (__cdecl *v6)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // eax
  unsigned __int64 v7; // kr18_8
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v9)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // eax
  void (__cdecl *v10)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v11)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  void (__cdecl *v12)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v13)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // eax
  void (__cdecl *v14)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v15)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v16)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  float v17; // [esp+48h] [ebp-40h]
  const allocator_data *e; // [esp+4Ch] [ebp-3Ch]
  const allocator_data *ea; // [esp+4Ch] [ebp-3Ch]
  float eb; // [esp+4Ch] [ebp-3Ch]
  float ec; // [esp+4Ch] [ebp-3Ch]
  float ed; // [esp+4Ch] [ebp-3Ch]
  unsigned __int64 process_allocated_size; // [esp+50h] [ebp-38h]
  void (__cdecl *process_allocated_sizea)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // [esp+50h] [ebp-38h]
  void (__cdecl *process_allocated_sizeb)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // [esp+50h] [ebp-38h]
  unsigned __int64 total_size; // [esp+58h] [ebp-30h]
  unsigned int allocated_size_4; // [esp+64h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+68h] [ebp-20h] BYREF

  m_begin = s_allocators.m_variable->m_begin;
  m_end = s_allocators.m_variable->m_end;
  v3 = 0;
  process_allocated_size = 0;
  total_size = 0;
  allocated_size_4 = 0;
  e = m_end;
  if ( s_allocators.m_variable->m_begin != m_end )
  {
    do
    {
      total_size += m_begin->allocator->total_size(m_begin->allocator);
      v4 = m_begin->allocator->allocated_size(m_begin->allocator);
      v5 = ((unsigned int)v4 + __PAIR64__(allocated_size_4, v3)) >> 32;
      v3 += v4;
      allocated_size_4 = v5;
      if ( m_begin->allocator == &s_process_allocator )
      {
        m_end = (allocator_data *)e;
        process_allocated_size = (unsigned int)v4;
      }
      if ( v4 || dump_stats_for_empty_arenas_as_well )
        vostok::memory::base_allocator::dump_statistics(0, m_begin->allocator);
      ++m_begin;
    }
    while ( m_begin != m_end );
  }
  v6 = vostok::core::g_log_callback;
  ea = (const allocator_data *)vostok::core::g_log_callback;
  v7 = __PAIR64__(allocated_size_4, v3) - process_allocated_size;
  log_callback.vtable = 0;
  if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
  {
    `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
      &log_callback.functor,
      &log_callback.functor,
      destroy_functor_tag);
    v6 = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))ea;
  }
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
    0,
    &vostok::logging::format_message,
    ".\\memory.cpp",
    0x164u,
    "void __cdecl vostok::memory::dump_statistics(const bool)",
    "core:",
    info,
    "---------------overall memory stats---------------");
  if ( log_callback.vtable )
  {
    if ( ((int)log_callback.vtable & 1) == 0 )
    {
      v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v8 )
        v8(&log_callback.functor, &log_callback.functor, 2);
    }
  }
  v17 = (float)total_size;
  if ( (double)total_size == 0.0 )
    eb = 0.0;
  else
    eb = (double)v7 / (double)total_size * 100.0;
  v9 = vostok::core::g_log_callback;
  process_allocated_sizea = vostok::core::g_log_callback;
  log_callback.vtable = 0;
  if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
  {
    `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
      &log_callback.functor,
      &log_callback.functor,
      destroy_functor_tag);
    v9 = process_allocated_sizea;
  }
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
  vostok::logging::append(
    &log_callback,
    0,
    &vostok::logging::format_message,
    ".\\memory.cpp",
    0x165u,
    "void __cdecl vostok::memory::dump_statistics(const bool)",
    "core:",
    info,
    "vostok: %10I64d (%6.2f%%)",
    v7,
    eb);
  if ( log_callback.vtable )
  {
    if ( ((int)log_callback.vtable & 1) == 0 )
    {
      v10 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v10 )
        v10(&log_callback.functor, &log_callback.functor, 2);
    }
  }
  if ( v17 == 0.0 )
    ec = 0.0;
  else
    ec = (double)__PAIR64__(allocated_size_4, v3) / v17 * 100.0;
  v11 = vostok::core::g_log_callback;
  log_callback.vtable = 0;
  if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
    `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
      &log_callback.functor,
      &log_callback.functor,
      destroy_functor_tag);
  if ( v11 )
  {
    log_callback.functor.obj_ptr = v11;
    log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                 + 1);
  }
  else
  {
    log_callback.vtable = 0;
  }
  vostok::logging::append(
    &log_callback,
    0,
    &vostok::logging::format_message,
    ".\\memory.cpp",
    0x166u,
    "void __cdecl vostok::memory::dump_statistics(const bool)",
    "core:",
    info,
    "used: %10I64d (%6.2f%%)",
    __PAIR64__(allocated_size_4, v3),
    ec);
  if ( log_callback.vtable )
  {
    if ( ((int)log_callback.vtable & 1) == 0 )
    {
      v12 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v12 )
        v12(&log_callback.functor, &log_callback.functor, 2);
    }
  }
  if ( v17 == 0.0 )
    ed = 0.0;
  else
    ed = (double)(total_size - __PAIR64__(allocated_size_4, v3)) / v17 * 100.0;
  v13 = vostok::core::g_log_callback;
  process_allocated_sizeb = vostok::core::g_log_callback;
  log_callback.vtable = 0;
  if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
  {
    `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
      &log_callback.functor,
      &log_callback.functor,
      destroy_functor_tag);
    v13 = process_allocated_sizeb;
  }
  if ( v13 )
  {
    log_callback.functor.obj_ptr = v13;
    log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                 + 1);
  }
  else
  {
    log_callback.vtable = 0;
  }
  vostok::logging::append(
    &log_callback,
    0,
    &vostok::logging::format_message,
    ".\\memory.cpp",
    0x167u,
    "void __cdecl vostok::memory::dump_statistics(const bool)",
    "core:",
    info,
    "free: %10I64d (%6.2f%%)",
    total_size - __PAIR64__(allocated_size_4, v3),
    ed);
  if ( log_callback.vtable )
  {
    if ( ((int)log_callback.vtable & 1) == 0 )
    {
      v14 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v14 )
        v14(&log_callback.functor, &log_callback.functor, 2);
    }
  }
  v15 = vostok::core::g_log_callback;
  log_callback.vtable = 0;
  if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
    `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
      &log_callback.functor,
      &log_callback.functor,
      destroy_functor_tag);
  if ( v15 )
  {
    log_callback.functor.obj_ptr = v15;
    log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                 + 1);
  }
  else
  {
    log_callback.vtable = 0;
  }
  vostok::logging::append(
    &log_callback,
    0,
    &vostok::logging::format_message,
    ".\\memory.cpp",
    0x168u,
    "void __cdecl vostok::memory::dump_statistics(const bool)",
    "core:",
    info,
    "size: %10I64d",
    total_size);
  if ( log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
  {
    v16 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
    if ( v16 )
      v16(&log_callback.functor, &log_callback.functor, 2);
  }
}
