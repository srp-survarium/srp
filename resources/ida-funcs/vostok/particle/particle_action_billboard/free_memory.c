void __thiscall vostok::particle::particle_action_billboard::free_memory(
        vostok::particle::particle_action_billboard *this,
        vostok::math::curve_line_points<float,0> *allocator)
{
  vostok::math::curve_line_ranged_base *v3; // ecx

  vostok::math::curve_line_ranged_base::free_memory(
    (vostok::math::curve_line_ranged_base *)this,
    (int)&this->m_subimage_index,
    allocator);
  vostok::math::curve_line_ranged_base::free_memory(v3, (int)&this->m_movie_start_frame, allocator);
}
