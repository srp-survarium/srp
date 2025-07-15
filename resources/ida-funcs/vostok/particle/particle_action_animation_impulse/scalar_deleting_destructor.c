vostok::particle::particle_action_gravity *__thiscall vostok::particle::particle_action_animation_impulse::`scalar deleting destructor'(
        vostok::particle::particle_action_gravity *this,
        char a2)
{
  this->__vftable = (vostok::particle::particle_action_gravity_vtbl *)&vostok::particle::particle_action::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
