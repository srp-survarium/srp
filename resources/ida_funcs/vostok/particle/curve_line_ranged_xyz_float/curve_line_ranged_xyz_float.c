void __thiscall vostok::particle::curve_line_ranged_xyz_float::curve_line_ranged_xyz_float(
        vostok::particle::curve_line_ranged_xyz_float *this)
{
  this->m_line_x.m_upper.points.max_storage = 0;
  this->m_line_x.m_lower.points.max_storage = 0;
  this->m_line_y.m_upper.points.max_storage = 0;
  this->m_line_y.m_lower.points.max_storage = 0;
  this->m_line_z.m_upper.points.max_storage = 0;
  this->m_line_z.m_lower.points.max_storage = 0;
  this->m_evaluate_type = age_evaluate_type;
}
