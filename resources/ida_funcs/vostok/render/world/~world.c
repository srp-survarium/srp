void __thiscall vostok::render::world::~world(vostok::render::world *this, vostok::render::world *thisa)
{
  vostok::render::grass_render_model *m_object; // ecx
  vostok::render::game::renderer *m_game_renderer; // edi
  vostok::render::grass_render_model *v4; // esi
  char *m_engine_renderer; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::one_way_render_channel *v7; // ecx
  vostok::render::one_way_render_channel *v8; // ecx

  m_object = vostok::render::g_allocator.m_object;
  m_game_renderer = thisa->m_game_renderer;
  v4 = vostok::render::g_allocator.m_object;
  if ( m_game_renderer )
  {
    vostok::render::game::renderer::~renderer(
      (vostok::render::game::renderer *)vostok::render::g_allocator.m_object,
      m_game_renderer);
    BYTE2(v4->m_children_resources.m_lock) = 0;
    vostok_mspace_free((malloc_state *)HIDWORD(v4->m_reconstruction_info_actuality_tick), (char *)m_game_renderer);
    thisa->m_game_renderer = 0;
    m_object = vostok::render::g_allocator.m_object;
  }
  m_engine_renderer = (char *)thisa->m_engine_renderer;
  if ( m_engine_renderer )
  {
    m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, m_engine_renderer);
    thisa->m_engine_renderer = 0;
  }
  vostok::render::engine::world::~world((vostok::render::engine::world *)m_object, s_world_1.m_variable);
  s_world_1.m_initialized = 0;
  thisa->m_render_engine_world = 0;
  vostok::render::one_way_render_channel::~one_way_render_channel(v7, (int)&thisa->m_editor_channel);
  vostok::render::one_way_render_channel::~one_way_render_channel(v8, (int)thisa);
}
