vostok::particle::particle_world *__thiscall vostok::particle::particle_world::`vector deleting destructor'(
        vostok::particle::particle_world *this,
        char a2)
{
  vostok::particle::particle_world::~particle_world(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
