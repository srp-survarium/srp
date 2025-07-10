void __thiscall vostok::particle::particle_action_acceleration::load(
        vostok::particle::particle_action_acceleration *this,
        vostok::configs::binary_config_value *prop_config)
{
  vostok::configs::binary_config_value v2; // [esp-18h] [ebp-30h]

  vostok::particle::particle_action::load(this, prop_config);
  v2 = *vostok::configs::binary_config_value::operator[](prop_config, "Acceleration");
  vostok::particle::curve_line_ranged_xyz_float::load<vostok::configs::binary_config_value>(&this->m_acceleration, v2);
}
