void __thiscall vostok::math::curve_line_color::set_defaults(vostok::math::curve_line_color *this)
{
  this->m_evaluate_type = age_evaluate_type;
  this->points.pointer = 0;
  this->num_points = 0;
  *(_QWORD *)&this->curve_value_min.x = 0;
  *(_QWORD *)&this->curve_value_min.elements[2] = 0;
  *(_QWORD *)&this->curve_value_max.x = 0;
  *(_QWORD *)&this->curve_value_max.elements[2] = 0;
  this->curve_time_min = 0.0;
  this->curve_time_max = 0.0;
}
