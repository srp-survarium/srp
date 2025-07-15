void __thiscall vostok::particle::particle_action_orbit::~particle_action_orbit(
        vostok::particle::particle_action_orbit *this)
{
  vostok::particle::curve_line_ranged_xyz_float::~curve_line_ranged_xyz_float(&this->m_rotation_rate_amount);
  vostok::particle::curve_line_ranged_xyz_float::~curve_line_ranged_xyz_float(&this->m_rotation_amount);
  vostok::particle::curve_line_ranged_xyz_float::~curve_line_ranged_xyz_float(&this->m_offset_amount);
  this->__vftable = (vostok::particle::particle_action_orbit_vtbl *)&vostok::particle::particle_modifier::`vftable';
  this->__vftable = (vostok::particle::particle_action_orbit_vtbl *)&vostok::particle::particle_action::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_next);
}
