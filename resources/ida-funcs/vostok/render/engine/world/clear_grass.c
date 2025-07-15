void __thiscall vostok::render::engine::world::clear_grass(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *s)
{
  vostok::render::grass_world::clear(
    (vostok::render::grass_world *)s->m_object,
    (vostok::render::grass_world *)LODWORD(s->m_object[3].m_target_satisfaction));
}
