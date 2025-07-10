vostok::render::world *__usercall vostok::render::create_world@<eax>(
        vostok::render::engine::world *in_config@<ecx>,
        bool is_editor@<al>,
        vostok::memory::base_allocator *logic_allocator,
        vostok::memory::base_allocator *editor_allocator)
{
  vostok::render::world::world(
    logic_allocator,
    (vostok::render::one_way_render_channel *)editor_allocator,
    (vostok::render::world *)&s_world_0,
    in_config,
    is_editor);
  _InterlockedExchange(&s_world_0.m_initialized, 1);
  return s_world_0.m_variable;
}
