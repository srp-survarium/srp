vostok::render::engine::world *__usercall vostok::render::engine::create_world@<eax>(
        vostok::render::engine::world *in_config@<ecx>,
        bool is_editor@<al>)
{
  vostok::render::engine::world::world(
    in_config,
    (int)&s_world_1,
    (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)in_config,
    is_editor);
  _InterlockedExchange(&s_world_1.m_initialized, 1);
  return s_world_1.m_variable;
}
