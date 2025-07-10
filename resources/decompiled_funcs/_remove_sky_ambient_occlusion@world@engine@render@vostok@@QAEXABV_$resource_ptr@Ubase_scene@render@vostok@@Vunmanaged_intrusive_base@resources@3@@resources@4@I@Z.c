void __thiscall vostok::render::engine::world::remove_sky_ambient_occlusion(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *in_scene,
        unsigned int id)
{
  vostok::render::scene::remove_sky_ambient_occlusion(
    (vostok::render::find_by_id_predicate<vostok::render::sky_ambient_occlusion>)id,
    (vostok::render::scene *)in_scene->m_object);
}
