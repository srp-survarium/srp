void __thiscall vostok::particle::particle_action_initial_velocity::set_defaults(
        vostok::particle::particle_action_initial_velocity *this,
        bool mt_alloc)
{
  vostok::particle::particle_action::set_defaults(this, mt_alloc);
  vostok::particle::curve_line_ranged_xyz_float::set_defaults(&this->m_init_velocity);
}
