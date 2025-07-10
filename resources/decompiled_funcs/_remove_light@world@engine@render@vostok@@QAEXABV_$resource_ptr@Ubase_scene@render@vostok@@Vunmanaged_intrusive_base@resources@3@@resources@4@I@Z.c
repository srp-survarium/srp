void __thiscall vostok::render::engine::world::remove_light(
        vostok::render::engine::world *this,
        vostok::render::lights_db *in_scene,
        unsigned int id)
{
  vostok::render::lights_db::remove_light(
    in_scene,
    (vostok::render::lights_db *)in_scene->m_lights._M_impl._M_start[118].light.m_object,
    id);
}
