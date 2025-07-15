void __thiscall vostok::math::curve_line_points<float,0>::sort_points_by_time(
        vostok::math::curve_line_points<float,0> *this)
{
  unsigned int num_points; // eax
  vostok::math::curve_point<float> *pointer; // esi
  bool (__cdecl *v3)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *); // eax
  bool (__cdecl *v4)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *); // edi
  int v5; // eax
  int v6; // ecx

  num_points = this->num_points;
  if ( num_points )
  {
    pointer = this->points.pointer;
    v3 = (bool (__cdecl *)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))&pointer[num_points];
    v4 = v3;
    if ( pointer != (vostok::math::curve_point<float> *)v3 )
    {
      v5 = ((char *)v3 - (char *)pointer) / 24;
      v6 = 0;
      while ( v5 != 1 )
      {
        ++v6;
        v5 >>= 1;
      }
      stlp_std::priv::__introsort_loop<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,int,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        v4,
        pointer,
        (vostok::math::curve_point<float> *)v4,
        0,
        2 * v6,
        (bool (__cdecl *)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))vostok::math::curve_line_points_float_0_::sort_points_by_time_::_5_::predicate::compare);
      stlp_std::priv::__final_insertion_sort<vostok::math::curve_point<float> *,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>((vostok::math::curve_point<float> *)v4);
    }
  }
}
