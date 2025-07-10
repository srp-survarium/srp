void __userpurge vostok::render::ui::renderer::renderer(
        vostok::render::ui::renderer *this@<ecx>,
        vostok::render::ui::renderer **a2@<eax>,
        vostok::render::engine::world *channel,
        vostok::memory::base_allocator *allocator,
        vostok::render::engine::world *engine_world)
{
  vostok::memory::base_allocator *v5; // ecx

  *a2 = this;
  v5 = vostok::render::logic::g_allocator;
  a2[1] = (vostok::render::ui::renderer *)channel;
  a2[2] = (vostok::render::ui::renderer *)v5;
}
