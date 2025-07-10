void __thiscall vostok::particle::particle_action_initial_color::set_defaults(
        vostok::particle::particle_action_initial_color *this,
        bool mt_alloc)
{
  vostok::particle::particle_action::set_defaults(this, mt_alloc);
  vostok::particle::curve_line_points<vostok::math::float4_pod,1>::set_defaults(&this->m_init_color);
}
