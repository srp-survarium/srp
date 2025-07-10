void __thiscall vostok::render::engine::world::add_decal(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *in_scene,
        const vostok::render::decal_properties *id,
        const vostok::render::decal_properties *properties)
{
  vostok::render::scene::add_decal(
    (vostok::render::scene *)this,
    (vostok::render::scene *)in_scene->m_object,
    id,
    properties);
}
