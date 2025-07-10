void __thiscall vostok::particle::curve_line_points<vostok::math::float4_pod,1>::sort_points_by_time(
        vostok::particle::curve_line_points<vostok::math::float4_pod,1> *this)
{
  if ( this->num_points )
    stlp_std::sort<vostok::particle::curve_point<vostok::math::float4_pod> *,bool (__cdecl *)(vostok::particle::curve_point<vostok::math::float4_pod> const &,vostok::particle::curve_point<vostok::math::float4_pod> const &)>(
      this->points.pointer,
      &this->points.pointer[this->num_points],
      vostok::particle::curve_line_points_vostok::math::float4_pod_1_::sort_points_by_time_::_5_::predicate::compare);
}
