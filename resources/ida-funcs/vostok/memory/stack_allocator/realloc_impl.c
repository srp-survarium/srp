unsigned __int8 *__userpurge vostok::memory::stack_allocator::realloc_impl@<eax>(
        vostok::memory::stack_allocator *this@<eax>,
        unsigned int new_size@<edx>,
        unsigned __int8 *pointer)
{
  unsigned __int8 *m_arena_current_position; // edi
  char v4; // bl
  void (__cdecl *v5)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  m_arena_current_position = (unsigned __int8 *)this->m_arena_current_position;
  v4 = 0;
  this->m_arena_current_position = &m_arena_current_position[new_size];
  if ( pointer )
    memcpy(m_arena_current_position, pointer, new_size);
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "core:", warning) )
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
    v4 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\memory_stack_allocator.cpp",
      0x59u,
      "void *__thiscall vostok::memory::stack_allocator::realloc_impl(void *,unsigned int)",
      "core:",
      warning,
      "realloc has been called on stack allocator, is it intended behavior?");
  }
  if ( (v4 & 1) != 0 )
  {
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v6 )
          v6(&log_callback.functor, &log_callback.functor, 2);
      }
    }
  }
  return m_arena_current_position;
}
