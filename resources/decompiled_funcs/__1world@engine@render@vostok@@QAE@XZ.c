void __thiscall vostok::render::engine::world::~world(
        vostok::render::engine::world *this,
        vostok::render::engine::world *thisa)
{
  vostok::render::system_renderer *v2; // ecx
  vostok::render::renderer *v3; // ecx
  vostok::render::grass_render_model *m_object; // edi
  stlp_std::reverse_iterator<vostok::render::stage * *> v5; // esi
  vostok::render::stage **current; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  singletons_on_initialize *m_variable; // ebp
  vostok::render::material_manager *v9; // ecx
  vostok::render::renderer_context *v10; // ecx
  singletons_on_preinitialize *v11; // ecx
  vostok::render *v12; // [esp+0h] [ebp-18h]
  vostok::particle *v13; // [esp+0h] [ebp-18h]
  vostok::render *v14; // [esp+0h] [ebp-18h]
  vostok::particle *v15; // [esp+0h] [ebp-18h]

  vostok::render::material::finalize_nomaterial_material();
  vostok::render::finalize_speedtree(v12);
  vostok::render::system_renderer::~system_renderer(v2, s_system_renderer.m_variable);
  m_object = vostok::render::g_allocator.m_object;
  s_system_renderer.m_initialized = 0;
  v5.current = (vostok::render::stage **)thisa->m_renderer;
  if ( thisa->m_renderer )
  {
    vostok::render::renderer::~renderer(v3, v5);
    current = v5.current;
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, current);
    thisa->m_renderer = 0;
  }
  m_variable = s_singletons_on_initialize.m_variable;
  vostok::render::decal_shader_constants_and_geometry::~decal_shader_constants_and_geometry(
    (vostok::render::decal_shader_constants_and_geometry *)v3,
    (int)&s_singletons_on_initialize.m_variable->decal_shader_constants_and_geometry);
  *(_DWORD *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_is_active = 0;
  vostok::render::material_manager::~material_manager(v9);
  vostok::render::renderer_context::~renderer_context(v10, &m_variable->renderer_context);
  s_singletons_on_initialize.m_initialized = 0;
  singletons_on_preinitialize::~singletons_on_preinitialize(v11, (int)s_singletons_on_preinitialize.m_variable);
  s_singletons_on_preinitialize.m_initialized = 0;
  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start = 0;
  s_options.m_initialized = 0;
  vostok::particle::finalize(v13);
  vostok::render::unregister_texture_cook(v14);
  vostok::particle::finalize(v15);
}
