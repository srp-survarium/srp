void __thiscall vostok::math::curve_line_ranged_base::set_defaults(vostok::math::curve_line_ranged_base *this)
{
  vostok::math::curve_line_points<float,0> *p_m_lower; // ecx

  this->m_upper.points.pointer = 0;
  this->m_upper.num_points = 0;
  this->m_upper.curve_value_min = 0.0;
  this->m_upper.curve_value_max = 0.0;
  this->m_upper.curve_time_min = 0.0;
  this->m_upper.curve_time_max = 0.0;
  p_m_lower = &this->m_lower;
  p_m_lower->points.pointer = 0;
  p_m_lower->num_points = 0;
  p_m_lower->curve_value_min = 0.0;
  p_m_lower->curve_value_max = 0.0;
  p_m_lower->curve_time_min = 0.0;
  p_m_lower->curve_time_max = 0.0;
}
