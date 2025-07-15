void __thiscall vostok::particle::particle_action_orbit::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_action_orbit *this,
        vostok::memory::base_allocator *allocator,
        const vostok::configs::binary_config_value *prop_config,
        vostok::configs::binary_config_value *config_4)
{
  _BYTE v4[28]; // [esp-1Ch] [ebp-28h] BYREF

  *(_DWORD *)v4 = prop_config;
  qmemcpy(&v4[4], vostok::configs::binary_config_value::operator[](config_4, "Radius"), 0x18u);
  vostok::math::curve_line_ranged_xyz_float::load<vostok::configs::binary_config_value>(
    0,
    (vostok::math::curve_line_points<float,0> *)&allocator[1].m_arena_start,
    *(vostok::configs::binary_config_value *)v4,
    *(int *)&v4[24]);
  *(_DWORD *)v4 = prop_config;
  qmemcpy(&v4[4], vostok::configs::binary_config_value::operator[](config_4, "Spin"), 0x18u);
  vostok::math::curve_line_ranged_xyz_float::load<vostok::configs::binary_config_value>(
    0,
    (vostok::math::curve_line_points<float,0> *)&allocator[11].m_arena_start,
    *(vostok::configs::binary_config_value *)v4,
    *(int *)&v4[24]);
  *(_DWORD *)v4 = prop_config;
  qmemcpy(&v4[4], vostok::configs::binary_config_value::operator[](config_4, "SpinOffset"), 0x18u);
  vostok::math::curve_line_ranged_xyz_float::load<vostok::configs::binary_config_value>(
    0,
    (vostok::math::curve_line_points<float,0> *)&allocator[21].m_arena_start,
    *(vostok::configs::binary_config_value *)v4,
    *(int *)&v4[24]);
  *(_DWORD *)v4 = prop_config;
  qmemcpy(&v4[4], vostok::configs::binary_config_value::operator[](config_4, "Speed"), 0x18u);
  vostok::math::curve_line_ranged_float::load<vostok::configs::binary_config_value>(
    0,
    (vostok::memory::base_allocator *)((char *)allocator + 624),
    *(vostok::configs::binary_config_value *)v4,
    *(int *)&v4[24]);
  *(_DWORD *)v4 = prop_config;
  qmemcpy(&v4[4], vostok::configs::binary_config_value::operator[](config_4, "Rotation"), 0x18u);
  vostok::math::curve_line_ranged_xyz_float::load<vostok::configs::binary_config_value>(
    0,
    (vostok::math::curve_line_points<float,0> *)&allocator[34].m_use_memory_monitor,
    *(vostok::configs::binary_config_value *)v4,
    *(int *)&v4[24]);
}
