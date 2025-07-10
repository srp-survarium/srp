void __thiscall vostok::particle::curve_line_ranged_xyz_float::~curve_line_ranged_xyz_float(
        vostok::particle::curve_line_ranged_xyz_float *this)
{
  vostok::particle::curve_line_ranged_base *p_m_line_z; // [esp+5Ch] [ebp-2Ch]

  p_m_line_z = &this->m_line_z;
  vostok::particle::curve_line_points<float,0>::clear(&this->m_line_z.m_lower);
  vostok::particle::curve_line_points<float,0>::clear(&p_m_line_z->m_upper);
  vostok::particle::curve_line_points<float,0>::clear(&this->m_line_y.m_lower);
  vostok::particle::curve_line_points<float,0>::clear(&this->m_line_y.m_upper);
  vostok::particle::curve_line_points<float,0>::clear(&this->m_line_x.m_lower);
  vostok::particle::curve_line_points<float,0>::clear(&this->m_line_x.m_upper);
}
