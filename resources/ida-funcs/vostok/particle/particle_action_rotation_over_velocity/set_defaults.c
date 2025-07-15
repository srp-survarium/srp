void __thiscall vostok::particle::particle_action_rotation_over_velocity::set_defaults(
        vostok::particle::particle_action_rotation_over_velocity *this,
        bool mt_alloc)
{
  vostok::particle::particle_action::set_defaults(this, mt_alloc);
  vostok::particle::curve_line_ranged_xyz_float::set_defaults(&this->m_rotation_over_velocity);
  this->m_affect_x = 0;
  this->m_affect_y = 0;
  this->m_affect_z = 0;
}
