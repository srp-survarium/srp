void __thiscall vostok::particle::particle_system_instance_impl::play_impl(
        vostok::particle::particle_system_instance_impl *this,
        vostok::particle::particle_world *particle_world)
{
  this->m_particle_world = particle_world;
  vostok::particle::particle_system_instance_impl::prepare_render_resources(this);
  vostok::threading::interlocked_exchange_pointer(&this->m_is_playing, 1);
  this->m_no_more_create = 0;
}


void __thiscall vostok::particle::particle_system_instance_impl::play_impl(
        vostok::particle::particle_system_instance_impl *this,
        vostok::particle::particle_world *particle_world,
        const vostok::math::float4x4 *transform)
{
  vostok::particle::particle_system_instance_impl::set_transform(this, transform);
  vostok::particle::particle_system_instance_impl::play_impl(this, particle_world);
}
