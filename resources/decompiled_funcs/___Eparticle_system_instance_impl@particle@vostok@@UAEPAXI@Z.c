vostok::particle::particle_system_instance_impl *__thiscall vostok::particle::particle_system_instance_impl::`vector deleting destructor'(
        vostok::particle::particle_system_instance_impl *this,
        char a2)
{
  vostok::particle::particle_system_instance_impl::~particle_system_instance_impl(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
