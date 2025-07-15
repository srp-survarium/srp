void __userpurge vostok::math::curve_line_ranged_xyz_float::free_memory(
        vostok::math::curve_line_ranged_xyz_float *this@<ecx>,
        int a2@<esi>,
        vostok::math::curve_line_points<float,0> *allocator)
{
  vostok::math::curve_line_ranged_base *v3; // ecx
  vostok::math::curve_line_ranged_base *v4; // ecx

  vostok::math::curve_line_ranged_base::free_memory(&this->m_line_x, a2, allocator);
  vostok::math::curve_line_ranged_base::free_memory(v3, a2 + 64, allocator);
  vostok::math::curve_line_ranged_base::free_memory(v4, a2 + 128, allocator);
}
