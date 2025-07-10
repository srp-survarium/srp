void __userpurge vostok::render::debug::renderer::renderer(
        vostok::render::debug::renderer *this@<eax>,
        vostok::render::engine::world *engine_world@<ecx>,
        vostok::render::one_way_render_channel *channel,
        vostok::memory::base_allocator *allocator)
{
  vostok::memory::base_allocator *v4; // ecx

  this->m_render_engine_world = engine_world;
  v4 = vostok::render::logic::g_allocator;
  this->m_channel = channel;
  this->m_allocator = v4;
}
