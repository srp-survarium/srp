vostok::particle::particle_action_initial_size *__thiscall vostok::particle::particle_action_size_over_lifetime::`scalar deleting destructor'(
        vostok::particle::particle_action_initial_size *this,
        char a2)
{
  vostok::particle::curve_line_ranged_xyz_float::~curve_line_ranged_xyz_float(&this->m_init_size);
  this->__vftable = (vostok::particle::particle_action_initial_size_vtbl *)&vostok::particle::particle_modifier::`vftable';
  this->__vftable = (vostok::particle::particle_action_initial_size_vtbl *)&vostok::particle::particle_action::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_next);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
