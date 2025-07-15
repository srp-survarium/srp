void __thiscall vostok::memory::base_allocator::dump_statistics(
        vostok::memory::base_allocator *this,
        const vostok::memory::base_allocator *thisa)
{
  int v3; // eax
  void (__cdecl *v4)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  int v5; // edi
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  double v7; // st7
  void (__cdecl *v8)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // eax
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v10)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // eax
  void (__cdecl *v11)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  const char *v12; // edi
  void (__cdecl *v13)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  void (__cdecl *v14)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  float v15; // [esp+1Ch] [ebp-34h]
  void (__cdecl *v16)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // [esp+20h] [ebp-30h]
  void (__cdecl *v17)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // [esp+20h] [ebp-30h]
  int total_size; // [esp+28h] [ebp-28h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+30h] [ebp-20h] BYREF
  float thisb; // [esp+54h] [ebp+4h]
  float thisc; // [esp+54h] [ebp+4h]

  total_size = thisa->total_size((vostok::memory::base_allocator *)thisa);
  v3 = thisa->allocated_size((vostok::memory::base_allocator *)thisa);
  v4 = vostok::core::g_log_callback;
  v5 = v3;
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
  vostok::logging::append(
    &log_callback,
    0,
    &vostok::logging::format_message,
    ".\\memory_base_allocator.cpp",
    0x4Eu,
    "void __thiscall vostok::memory::base_allocator::dump_statistics(void) const",
    "core:",
    info,
    "--------------- memory stats for arena [%s] ---------------",
    thisa->m_arena_id);
  if ( log_callback.vtable )
  {
    if ( ((int)log_callback.vtable & 1) == 0 )
    {
      v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v6 )
        v6(&log_callback.functor, &log_callback.functor, 2);
    }
  }
  v7 = (double)(unsigned int)total_size - (double)0LL;
  v15 = v7;
  if ( v7 == 0.0 )
    thisb = 0.0;
  else
    thisb = (double)(unsigned int)v5 / v7 * 100.0;
  v8 = vostok::core::g_log_callback;
  v16 = vostok::core::g_log_callback;
  log_callback.vtable = 0;
  if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
  {
    `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
      &log_callback.functor,
      &log_callback.functor,
      destroy_functor_tag);
    v8 = v16;
  }
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
    0,
    &vostok::logging::format_message,
    ".\\memory_base_allocator.cpp",
    0x4Fu,
    "void __thiscall vostok::memory::base_allocator::dump_statistics(void) const",
    "core:",
    info,
    "used: %10I64d (%6.2f%%)",
    (unsigned __int64)(unsigned int)v5,
    thisb);
  if ( log_callback.vtable )
  {
    if ( ((int)log_callback.vtable & 1) == 0 )
    {
      v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v9 )
        v9(&log_callback.functor, &log_callback.functor, 2);
    }
  }
  if ( v15 == 0.0 )
    thisc = 0.0;
  else
    thisc = (double)((unsigned int)total_size - (unsigned __int64)(unsigned int)v5) / v15 * 100.0;
  v10 = vostok::core::g_log_callback;
  v17 = vostok::core::g_log_callback;
  log_callback.vtable = 0;
  if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
  {
    `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
      &log_callback.functor,
      &log_callback.functor,
      destroy_functor_tag);
    v10 = v17;
  }
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
    0,
    &vostok::logging::format_message,
    ".\\memory_base_allocator.cpp",
    0x50u,
    "void __thiscall vostok::memory::base_allocator::dump_statistics(void) const",
    "core:",
    info,
    "free: %10I64d (%6.2f%%)",
    (unsigned int)total_size - (unsigned __int64)(unsigned int)v5,
    thisc);
  if ( log_callback.vtable )
  {
    if ( ((int)log_callback.vtable & 1) == 0 )
    {
      v11 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v11 )
        v11(&log_callback.functor, &log_callback.functor, 2);
    }
  }
  v12 = "size: %10I64d, start address: 0x%09I64x, end address: 0x%09I64x";
  if ( !thisa->m_arena_start )
    v12 = "size: %10I64d";
  v13 = vostok::core::g_log_callback;
  log_callback.vtable = 0;
  if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
    `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
      &log_callback.functor,
      &log_callback.functor,
      destroy_functor_tag);
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
    ".\\memory_base_allocator.cpp",
    0x5Cu,
    "void __thiscall vostok::memory::base_allocator::dump_statistics(void) const",
    "core:",
    info,
    v12,
    total_size,
    0,
    thisa->m_arena_start,
    0,
    thisa->m_arena_end,
    0);
  if ( log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
  {
    v14 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
    if ( v14 )
      v14(&log_callback.functor, &log_callback.functor, 2);
  }
}
