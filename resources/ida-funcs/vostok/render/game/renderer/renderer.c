void __userpurge vostok::render::game::renderer::renderer(
        vostok::render::game::renderer *this@<esi>,
        vostok::render::engine::world *engine_world@<edi>,
        vostok::render::world *world)
{
  vostok::render::debug::renderer *v3; // eax
  vostok::memory::base_allocator *v4; // ecx
  vostok::render::ui::renderer *v5; // eax
  vostok::memory::base_allocator *v6; // edx
  int *v7; // eax
  vostok::render::scene_renderer *v8; // eax
  vostok::math::frustum *v9; // [esp+0h] [ebp-8h]

  this->m_world = world;
  this->m_render_engine_world = engine_world;
  v3 = (vostok::render::debug::renderer *)vostok::memory::doug_lea_allocator::malloc_impl(
                                            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                            0x84u);
  if ( v3 )
  {
    v4 = vostok::render::logic::g_allocator;
    v3->m_render_engine_world = engine_world;
    v3->m_channel = &world->m_logic_channel;
    v3->m_allocator = v4;
  }
  else
  {
    v3 = 0;
  }
  this->m_debug = v3;
  v5 = (vostok::render::ui::renderer *)vostok::memory::doug_lea_allocator::malloc_impl(
                                         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                         0xCu);
  if ( v5 )
  {
    v6 = vostok::render::logic::g_allocator;
    v5->m_channel = &world->m_logic_channel;
    v5->m_render_engine_world = engine_world;
    v5->m_allocator = v6;
  }
  else
  {
    v5 = 0;
  }
  this->m_ui = v5;
  v7 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         0x90u);
  if ( v7 )
  {
    vostok::render::scene_renderer::scene_renderer(
      &world->m_logic_channel,
      engine_world,
      (vostok::render::scene_renderer *)v7,
      &this->m_debug->frustum,
      v9);
    this->m_scene = v8;
  }
  else
  {
    this->m_scene = 0;
  }
}
