void __thiscall vostok::particle::particle_action_rotation_over_velocity::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_action_rotation_over_velocity *this,
        vostok::configs::binary_config_value *prop_config)
{
  vostok::configs::binary_config_value v2; // [esp-18h] [ebp-30h]

  this->m_affect_x = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                       prop_config,
                       "AffectX",
                       &this->m_affect_x);
  this->m_affect_y = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                       prop_config,
                       "AffectY",
                       &this->m_affect_y);
  this->m_affect_z = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                       prop_config,
                       "AffectZ",
                       &this->m_affect_z);
  v2 = *vostok::configs::binary_config_value::operator[](prop_config, "RotationOverVelocity");
  vostok::particle::curve_line_ranged_xyz_float::load<vostok::configs::binary_config_value>(
    &this->m_rotation_over_velocity,
    v2);
}
