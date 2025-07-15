void __thiscall vostok::render::engine::world::add_light(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *in_scene,
        unsigned int id,
        vostok::render::light_props *props)
{
  vostok::render::lights_db::add_light(
    (int)in_scene,
    id,
    (vostok::render::lights_db *)in_scene->m_object[3].m_next_in_increase_quality_queue,
    props);
}
