void __thiscall vostok::particle::curve_line_ranged_float::curve_line_ranged_float(
        vostok::particle::curve_line_ranged_float *this)
{
  this->m_line.m_upper.points.max_storage = 0;
  this->m_line.m_lower.points.max_storage = 0;
  this->m_evaluate_type = age_evaluate_type;
}
