void __thiscall vostok::render::engine::world::update_lpv_occluder(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *in_scene,
        const vostok::math::float4x4 *id,
        const vostok::math::float4x4 *transform)
{
  vostok::render::scene::update_lpv_occluder(
    (vostok::render::scene *)this,
    (vostok::render::scene *)in_scene->m_object,
    id,
    transform);
}
