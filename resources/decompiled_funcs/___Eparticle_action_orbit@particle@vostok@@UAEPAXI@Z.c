vostok::particle::particle_action_orbit *__thiscall vostok::particle::particle_action_orbit::`vector deleting destructor'(
        vostok::particle::particle_action_orbit *this,
        char a2)
{
  vostok::particle::particle_action_orbit::~particle_action_orbit(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
