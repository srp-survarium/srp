void __thiscall vostok::particle::particle_action_orbit::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_action_orbit *this,
        vostok::configs::binary_config_value *prop_config)
{
  vostok::configs::binary_config_value v2; // [esp-18h] [ebp-58h]
  vostok::configs::binary_config_value v3; // [esp-18h] [ebp-58h]
  vostok::configs::binary_config_value v4; // [esp-18h] [ebp-58h]

  v2 = *vostok::configs::binary_config_value::operator[](prop_config, "OffsetAmount");
  vostok::particle::curve_line_ranged_xyz_float::load<vostok::configs::binary_config_value>(&this->m_offset_amount, v2);
  v3 = *vostok::configs::binary_config_value::operator[](prop_config, "RotationAmount");
  vostok::particle::curve_line_ranged_xyz_float::load<vostok::configs::binary_config_value>(
    &this->m_rotation_amount,
    v3);
  v4 = *vostok::configs::binary_config_value::operator[](prop_config, "RotationRateAmount");
  vostok::particle::curve_line_ranged_xyz_float::load<vostok::configs::binary_config_value>(
    &this->m_rotation_rate_amount,
    v4);
}
