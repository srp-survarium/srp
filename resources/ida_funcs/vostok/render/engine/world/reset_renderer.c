void __thiscall vostok::render::engine::world::reset_renderer(vostok::render::engine::world *this, bool async_effects)
{
  char v2; // bl
  vostok::render::engine::world *v3; // edi
  vostok::render::renderer *v4; // ecx
  void (__cdecl *v5)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  stlp_std::reverse_iterator<vostok::render::stage * *> v7; // esi
  vostok::render::grass_render_model *m_object; // edi
  vostok::render::stage **current; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::renderer *v11; // eax
  vostok::render::renderer *v12; // eax
  survarium::game_action_id m_conflicted_action_to_bind; // edx
  void (__cdecl *v14)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v15)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-20h] BYREF

  v2 = 0;
  v3 = this;
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", info) )
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
      ".\\render_engine_world_pc_dx11.cpp",
      0x323u,
      "void __thiscall vostok::render::engine::world::reset_renderer(bool)",
      "render_pc_dx11:",
      info,
      "Renderer creating started...");
  }
  if ( (v2 & 1) != 0 )
  {
    v2 &= ~1u;
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
  v7.current = (vostok::render::stage **)v3->m_renderer;
  if ( v3->m_renderer )
  {
    m_object = vostok::render::g_allocator.m_object;
    vostok::render::renderer::~renderer(v4, v7);
    current = v7.current;
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, current);
    this->m_renderer = 0;
    v3 = this;
  }
  *(_BYTE *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind + 20) = !async_effects;
  v11 = (vostok::render::renderer *)vostok::memory::doug_lea_allocator::malloc_impl(
                                      (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                      0x280u);
  if ( v11 )
    vostok::render::renderer::renderer(
      (vostok::render::renderer *)s_singletons_on_initialize.m_variable,
      v11,
      &s_singletons_on_initialize.m_variable->renderer_context);
  else
    v12 = 0;
  m_conflicted_action_to_bind = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind;
  v3->m_renderer = v12;
  *(_BYTE *)(m_conflicted_action_to_bind + 20) = 0;
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", info) )
  {
    v14 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v14 )
    {
      log_callback.functor.obj_ptr = v14;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    v2 |= 2u;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\render_engine_world_pc_dx11.cpp",
      0x32Eu,
      "void __thiscall vostok::render::engine::world::reset_renderer(bool)",
      "render_pc_dx11:",
      info,
      "Renderer creating finished.");
  }
  if ( (v2 & 2) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
  {
    v15 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
    if ( v15 )
      v15(&log_callback.functor, &log_callback.functor, 2);
  }
}
