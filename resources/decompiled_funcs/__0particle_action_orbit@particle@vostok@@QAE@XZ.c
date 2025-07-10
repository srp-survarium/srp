void __thiscall vostok::particle::particle_action_orbit::particle_action_orbit(
        vostok::particle::particle_action_orbit *this)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_next);
  this->__vftable = (vostok::particle::particle_action_orbit_vtbl *)&vostok::particle::particle_action::`vftable';
  this->m_next.pointer = 0;
  HIDWORD(this->m_next.max_storage) = 0;
  this->m_next.pointer = 0;
  this->__vftable = (vostok::particle::particle_action_orbit_vtbl *)&vostok::particle::particle_modifier::`vftable';
  this->__vftable = (vostok::particle::particle_action_orbit_vtbl *)&vostok::particle::particle_action_orbit::`vftable';
  vostok::particle::curve_line_ranged_xyz_float::curve_line_ranged_xyz_float(&this->m_offset_amount);
  vostok::particle::curve_line_ranged_xyz_float::curve_line_ranged_xyz_float(&this->m_rotation_amount);
  vostok::particle::curve_line_ranged_xyz_float::curve_line_ranged_xyz_float(&this->m_rotation_rate_amount);
}
