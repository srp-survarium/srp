void __thiscall vostok::particle::particle_action_orbit::free_memory(
        vostok::particle::particle_action_orbit *this,
        vostok::math::curve_line_points<float,0> *allocator)
{
  vostok::math::curve_line_ranged_xyz_float *v3; // ecx
  vostok::math::curve_line_ranged_xyz_float *v4; // ecx
  vostok::math::curve_line_ranged_base *v5; // ecx
  vostok::math::curve_line_ranged_xyz_float *v6; // ecx

  vostok::math::curve_line_ranged_xyz_float::free_memory(
    (vostok::math::curve_line_ranged_xyz_float *)this,
    (int)&this->m_radius,
    allocator);
  vostok::math::curve_line_ranged_xyz_float::free_memory(v3, (int)&this->m_spin, allocator);
  vostok::math::curve_line_ranged_xyz_float::free_memory(v4, (int)&this->m_spin_offset, allocator);
  vostok::math::curve_line_ranged_base::free_memory(v5, (int)&this->m_speed, allocator);
  vostok::math::curve_line_ranged_xyz_float::free_memory(v6, (int)&this->m_rotation, allocator);
}
