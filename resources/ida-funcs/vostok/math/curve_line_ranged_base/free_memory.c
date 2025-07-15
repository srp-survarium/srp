void __userpurge vostok::math::curve_line_ranged_base::free_memory(
        vostok::math::curve_line_ranged_base *this@<ecx>,
        int a2@<eax>,
        vostok::math::curve_line_points<float,0> *allocator)
{
  vostok::math::curve_line_points<float,0>::free_memory(allocator, a2);
  vostok::math::curve_line_points<float,0>::free_memory(allocator, a2 + 32);
}
