void __thiscall vostok::math::curve_line_points<float,0>::sort_points_by_time(
        vostok::math::curve_line_points<float,0> *this)
{
  unsigned int num_points; // eax

  num_points = this->num_points;
  if ( num_points )
    stlp_std::sort<vostok::math::curve_point<float> *,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
      this->points.pointer,
      &this->points.pointer[num_points],
      vostok::math::curve_line_points_float_0_::sort_points_by_time_::_5_::predicate::compare_63);
}
