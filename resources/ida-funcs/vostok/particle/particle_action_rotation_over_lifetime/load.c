void __thiscall vostok::particle::particle_action_rotation_over_lifetime::load(
        vostok::particle::particle_action_rotation_over_lifetime *this,
        vostok::memory::base_allocator *allocator,
        const vostok::configs::binary_config_value *prop_config)
{
  _BYTE v4[28]; // [esp-1Ch] [ebp-28h] BYREF

  vostok::particle::particle_action::load(this, allocator, prop_config);
  *(_DWORD *)v4 = allocator;
  qmemcpy(&v4[4], vostok::configs::binary_config_value::operator[](prop_config, "RotationOverLife"), 0x18u);
  vostok::math::curve_line_ranged_xyz_float::load<vostok::configs::binary_config_value>(
    0,
    &this->m_rotation_over_life.m_line_x.m_upper,
    *(vostok::configs::binary_config_value *)v4,
    *(int *)&v4[24]);
}
