vostok::particle::particle_action_billboard *__thiscall vostok::particle::particle_action_billboard::`scalar deleting destructor'(
        vostok::particle::particle_action_billboard *this,
        char a2)
{
  vostok::particle::particle_action_billboard::~particle_action_billboard(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
