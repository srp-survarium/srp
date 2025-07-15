vostok::particle::particle_system_instance *__thiscall vostok::particle::particle_system_instance::`scalar deleting destructor'(
        vostok::particle::particle_system_instance *this,
        char a2)
{
  vostok::particle::particle_system_instance::~particle_system_instance(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
