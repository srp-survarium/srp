void __thiscall vostok::particle::particle_action_velocity_over_lifetime::load(
        vostok::particle::particle_action_velocity_over_lifetime *this,
        vostok::configs::binary_config_value *prop_config)
{
  vostok::configs::binary_config_value v2; // [esp-18h] [ebp-30h]

  vostok::particle::particle_action::load(this, prop_config);
  v2 = *vostok::configs::binary_config_value::operator[](prop_config, "VelocityLife");
  vostok::particle::curve_line_ranged_xyz_float::load<vostok::configs::binary_config_value>(
    &this->m_velocity_over_life,
    v2);
}
