void __thiscall vostok::particle::particle_action_initial_color::set_defaults(
        vostok::particle::particle_action_initial_color *this,
        bool mt_alloc)
{
  this->m_next.pointer = 0;
  this->m_visibility = 1;
  vostok::math::curve_line_color::set_defaults(&this->m_init_color);
}
