void __thiscall __noreturn survarium::generate_shaders_world::tick(
        survarium::generate_shaders_world *this,
        unsigned int current_frame_id)
{
  char v2; // bl
  survarium::generate_shaders_world *v4; // ecx
  survarium::generate_shaders_world *v5; // ecx
  volatile int m_pending_queries_count; // ebp
  void (__cdecl *v7)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-20h] BYREF

  v2 = 0;
  if ( !this->m_first_call_reset_renderer )
  {
    vostok::render::scene_renderer::reset_renderer(this->m_renderer->m_scene, this->m_renderer->m_scene);
    survarium::generate_shaders_world::generate_renderer_shaders(v4, this);
    survarium::generate_shaders_world::generate_materials_shaders(v5, this);
    this->m_first_call_reset_renderer = 1;
  }
  if ( !(tick_id % 0x64) )
  {
    if ( vostok::resources::g_resources_manager.m_initialized )
      m_pending_queries_count = vostok::resources::g_resources_manager.m_variable->m_pending_queries_count;
    else
      m_pending_queries_count = 0;
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
    {
      v7 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v7 )
      {
        log_callback.functor.obj_ptr = v7;
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
        ".\\game_generate_shaders.cpp",
        0x96u,
        "void __thiscall survarium::generate_shaders_world::tick(unsigned int)",
        "game:",
        error,
        "pending_queries_count:%d",
        m_pending_queries_count);
    }
    if ( (v2 & 1) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
    {
      v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v8 )
        v8(&log_callback.functor, &log_callback.functor, 2);
    }
  }
  vostok::debug::debug_message_box("shaders generated");
  vostok::debug::terminate((char *)&buf);
}
