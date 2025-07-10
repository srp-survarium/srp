void __thiscall vostok::particle::curve_line_color::curve_line_color(vostok::particle::curve_line_color *this)
{
  vostok::platform_pointer_selector<vostok::particle::curve_point<vostok::math::float4_pod>,1>::helper *p_points; // ecx

  p_points = &this->points;
  p_points->pointer = 0;
  HIDWORD(p_points->max_storage) = 0;
  this->m_evaluate_type = age_evaluate_type;
}
