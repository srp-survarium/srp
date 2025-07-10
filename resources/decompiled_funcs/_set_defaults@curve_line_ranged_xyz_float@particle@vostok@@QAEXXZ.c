void __thiscall vostok::particle::curve_line_ranged_xyz_float::set_defaults(
        vostok::particle::curve_line_ranged_xyz_float *this)
{
  vostok::particle::curve_line_ranged_base *p_m_line_x; // [esp+1Ch] [ebp-Ch]

  p_m_line_x = &this->m_line_x;
  vostok::particle::curve_line_points<float,0>::set_defaults(&this->m_line_x.m_upper);
  vostok::particle::curve_line_points<float,0>::set_defaults(&p_m_line_x->m_lower);
  vostok::particle::curve_line_points<float,0>::set_defaults(&this->m_line_y.m_upper);
  vostok::particle::curve_line_points<float,0>::set_defaults(&this->m_line_y.m_lower);
  vostok::particle::curve_line_points<float,0>::set_defaults(&this->m_line_z.m_upper);
  vostok::particle::curve_line_points<float,0>::set_defaults(&this->m_line_z.m_lower);
}
