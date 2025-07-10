int *__thiscall vostok::memory::doug_lea_allocator::malloc_impl(
        vostok::memory::doug_lea_allocator *this,
        unsigned int size)
{
  char v2; // bl
  int *v5; // esi
  bool v6; // zf
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v7; // ecx
  void (__cdecl *v8)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  const char *m_arena_id; // [esp+10h] [ebp-28h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-20h] BYREF

  v2 = 0;
  if ( this->m_out_of_memory )
    return 0;
  v5 = vostok_mspace_malloc((malloc_state *)this->m_arena, size);
  v6 = v5 == 0;
  if ( !v5 )
  {
    if ( !this->m_return_null_after_out_of_memory )
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "core:", error) )
      {
        m_arena_id = this->m_arena_id;
        if ( !m_arena_id )
          m_arena_id = (const char *)&buf;
        v8 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
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
        v2 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\memory_doug_lea_allocator.cpp",
          0x91u,
          "void *__thiscall vostok::memory::doug_lea_allocator::malloc_impl(unsigned int)",
          "core:",
          error,
          "out of memory!!!! (%s)",
          m_arena_id);
        v5 = 0;
      }
      if ( (v2 & 1) != 0 )
      {
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v7,
          (int *)&log_callback);
        v5 = 0;
      }
    }
    v6 = v5 == 0;
  }
  this->m_out_of_memory = this->m_return_null_after_out_of_memory && v6;
  return v5;
}
