void __usercall vostok::particle::particle_system_instance_impl::play_impl(
        vostok::particle::particle_system_instance_impl *this@<ecx>,
        vostok::particle::particle_world *particle_world@<eax>)
{
  this->m_particle_world = particle_world;
  vostok::particle::particle_system_instance_impl::prepare_render_resources(this, (int)this);
  _InterlockedExchange(&this->m_is_playing, 1);
  this->m_no_more_create = 0;
}
