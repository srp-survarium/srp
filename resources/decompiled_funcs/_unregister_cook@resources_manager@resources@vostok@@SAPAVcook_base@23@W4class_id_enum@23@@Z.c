vostok::resources::cook_base *__cdecl vostok::resources::resources_manager::unregister_cook(
        vostok::resources::class_id_enum resource_class)
{
  vostok::resources::cook_base **m_end; // eax
  char v2; // bl
  int v3; // ecx
  vostok::resources::cook_base *v4; // edi
  void (__cdecl *v5)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  m_end = s_cooks_registry.m_end;
  v2 = 0;
  if ( s_cooks_registry.m_begin == s_cooks_registry.m_end )
  {
    v3 = 517;
    do
    {
      if ( m_end )
      {
        *m_end = 0;
        m_end = s_cooks_registry.m_end;
      }
      ++m_end;
      --v3;
      s_cooks_registry.m_end = m_end;
    }
    while ( v3 );
  }
  v4 = s_cooks_registry.m_begin[resource_class];
  if ( v4 && v4->m_cook_users_count.m_count )
  {
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
      v2 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\resources_manager_cook.cpp",
        0x6Eu,
        "class vostok::resources::cook_base *__cdecl vostok::resources::resources_manager::unregister_cook(enum vostok::r"
        "esources::class_id_enum)",
        "core:",
        warning,
        "There are [%d] leaked resource(s). (classid = [%d])",
        v4->m_cook_users_count.m_count,
        resource_class);
    }
    if ( (v2 & 1) != 0 )
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
  }
  s_cooks_registry.m_begin[resource_class] = 0;
  return v4;
}
