void __thiscall vostok::particle::curve_line_points<float,0>::sort_points_by_time(
        vostok::particle::curve_line_points<float,0> *this)
{
  if ( this->num_points )
    stlp_std::sort<vostok::particle::curve_point<float> *,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
      this->points.pointer,
      &this->points.pointer[this->num_points],
      vostok::particle::curve_line_points_float_0_::sort_points_by_time_::_5_::predicate::compare);
}
