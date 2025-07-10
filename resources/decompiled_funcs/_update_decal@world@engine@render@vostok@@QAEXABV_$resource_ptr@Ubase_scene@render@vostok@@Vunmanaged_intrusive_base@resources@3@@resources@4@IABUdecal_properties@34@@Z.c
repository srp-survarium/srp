void __thiscall vostok::render::engine::world::update_decal(
        vostok::render::engine::world *this,
        vostok::render::decal_instance *in_scene,
        const vostok::render::decal_properties *id,
        const vostok::render::decal_properties *properties)
{
  vostok::render::scene::update_decal(properties, in_scene, (vostok::render::scene *)in_scene->m_reference_count, id);
}
