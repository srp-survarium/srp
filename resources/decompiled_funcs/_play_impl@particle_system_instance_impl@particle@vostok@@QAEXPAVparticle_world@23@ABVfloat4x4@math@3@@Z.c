void __thiscall vostok::particle::particle_system_instance_impl::play_impl(
        vostok::particle::particle_system_instance_impl *this,
        vostok::particle::particle_world *particle_world,
        const vostok::math::float4x4 *transform)
{
  vostok::particle::particle_system_instance_impl::set_transform(this, transform);
  vostok::particle::particle_system_instance_impl::play_impl(this, particle_world);
}
