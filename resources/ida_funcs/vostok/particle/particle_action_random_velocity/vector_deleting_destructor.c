vostok::particle::particle_action_source *__thiscall vostok::particle::particle_action_random_velocity::`vector deleting destructor'(
        vostok::particle::particle_action_source *this,
        char a2)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_domain);
  this->__vftable = (vostok::particle::particle_action_source_vtbl *)&vostok::particle::particle_modifier::`vftable';
  this->__vftable = (vostok::particle::particle_action_source_vtbl *)&vostok::particle::particle_action::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_next);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
