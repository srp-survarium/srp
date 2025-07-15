void __thiscall survarium::bullet_manager::play_particle_impl(
        survarium::bullet_manager *this,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *particle,
        const vostok::math::float3 *position,
        const vostok::math::float3 *direction,
        const vostok::math::float3 *normal)
{
  this->m_engine->play_particle(this->m_engine, particle, position, direction, normal);
}
