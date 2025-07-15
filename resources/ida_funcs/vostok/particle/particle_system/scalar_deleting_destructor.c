vostok::particle::particle_system *__thiscall vostok::particle::particle_system::`scalar deleting destructor'(
        vostok::particle::particle_system *this,
        char a2)
{
  vostok::particle::particle_system::~particle_system(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
