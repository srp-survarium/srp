void __thiscall vostok::particle::particle_action_initial_size::free_memory(
        vostok::particle::particle_action_animated_source *this,
        vostok::math::curve_line_points<float,0> *allocator)
{
  vostok::math::curve_line_ranged_xyz_float::free_memory(
    (vostok::math::curve_line_ranged_xyz_float *)this,
    (int)&this->m_scale,
    allocator);
}
