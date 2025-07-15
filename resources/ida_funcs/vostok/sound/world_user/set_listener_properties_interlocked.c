void __thiscall vostok::sound::world_user::set_listener_properties_interlocked(
        vostok::sound::world_user *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *scene,
        const vostok::math::float3 *position,
        const vostok::math::float3 *orient_front,
        const vostok::math::float3 *orient_top)
{
  vostok::sound::sound_scene::set_listener_properties(
    (vostok::sound::sound_scene *)scene->m_object,
    position,
    orient_front,
    orient_top);
}
