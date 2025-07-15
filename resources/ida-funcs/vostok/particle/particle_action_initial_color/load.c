void __thiscall vostok::particle::particle_action_initial_color::load(
        vostok::particle::particle_action_initial_color *this,
        vostok::memory::base_allocator *allocator,
        const vostok::configs::binary_config_value *prop_config)
{
  _BYTE v4[28]; // [esp-1Ch] [ebp-28h] BYREF

  vostok::particle::particle_action::load(this, allocator, prop_config);
  *(_DWORD *)v4 = allocator;
  qmemcpy(&v4[4], vostok::configs::binary_config_value::operator[](prop_config, "InitColor"), 0x18u);
  vostok::math::curve_line_color::load<vostok::configs::binary_config_value>(
    0,
    (vostok::memory::base_allocator *)&this->m_init_color,
    *(vostok::configs::binary_config_value *)v4,
    *(int *)&v4[24]);
}
