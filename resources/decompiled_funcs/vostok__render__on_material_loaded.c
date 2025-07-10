void __cdecl vostok::render::on_material_loaded(vostok::resources::queries_result *data, volatile int *waiting_for)
{
  char v2; // bl
  volatile int m_pending_queries_count; // edi
  void (__cdecl *v4)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v6)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-40h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v9; // [esp+30h] [ebp-20h] BYREF

  v2 = 0;
  if ( vostok::resources::g_resources_manager.m_initialized )
    m_pending_queries_count = vostok::resources::g_resources_manager.m_variable->m_pending_queries_count;
  else
    m_pending_queries_count = 0;
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", error) )
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
    v2 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\render_engine_world_pc_dx11.cpp",
      0x1F2u,
      "void __cdecl vostok::render::on_material_loaded(class vostok::resources::queries_result &,volatile long *)",
      "render_pc_dx11:",
      error,
      "pending qc:%d",
      m_pending_queries_count);
  }
  if ( (v2 & 1) != 0 )
  {
    v2 &= ~1u;
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
  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[0] = (survarium::options_tab *)((char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[0] + data->m_size);
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", error) )
  {
    v6 = vostok::core::g_log_callback;
    v9.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &v9.functor,
        &v9.functor,
        destroy_functor_tag);
    if ( v6 )
    {
      v9.functor.obj_ptr = v6;
      v9.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                         + 1);
    }
    else
    {
      v9.vtable = 0;
    }
    v2 |= 2u;
    vostok::logging::append(
      &v9,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\render_engine_world_pc_dx11.cpp",
      0x1F6u,
      "void __cdecl vostok::render::on_material_loaded(class vostok::resources::queries_result &,volatile long *)",
      "render_pc_dx11:",
      error,
      "num nmtls:%d",
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[0]);
  }
  if ( (v2 & 2) != 0 )
  {
    if ( v9.vtable )
    {
      if ( ((int)v9.vtable & 1) == 0 )
      {
        v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v9.vtable & 0xFFFFFFFE);
        if ( v7 )
          v7(&v9.functor, &v9.functor, 2);
      }
    }
  }
  if ( waiting_for )
    _InterlockedExchange(waiting_for, 0);
}
