void __thiscall vostok::particle::particle_action_initial_size::load(
        vostok::particle::particle_action_initial_size *this,
        vostok::memory::base_allocator *allocator,
        const vostok::configs::binary_config_value *prop_config)
{
  vostok::configs::binary_config_value *v4; // ecx
  _BYTE v5[28]; // [esp-1Ch] [ebp-28h] BYREF

  vostok::particle::particle_action::load(this, allocator, prop_config);
  *(_DWORD *)v5 = allocator;
  qmemcpy(&v5[4], vostok::configs::binary_config_value::operator[](prop_config, "InitSize"), 0x18u);
  vostok::math::curve_line_ranged_xyz_float::load<vostok::configs::binary_config_value>(
    0,
    &this->m_init_size.m_line_x.m_upper,
    *(vostok::configs::binary_config_value *)v5,
    *(int *)&v5[24]);
  this->m_is_square = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                        "IsSquare",
                        v4,
                        prop_config,
                        &this->m_is_square);
}
