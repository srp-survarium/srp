void __thiscall vostok::particle::particle_action_initial_rotation_rate::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_action_initial_rotation_rate *this,
        vostok::configs::binary_config_value *prop_config)
{
  vostok::configs::binary_config_value v2; // [esp-18h] [ebp-30h]

  v2 = *vostok::configs::binary_config_value::operator[](prop_config, "InitRotRate");
  vostok::particle::curve_line_ranged_xyz_float::load<vostok::configs::binary_config_value>(&this->m_init_rate, v2);
}
