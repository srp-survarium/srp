void __thiscall vostok::particle::particle_action_size_over_lifetime::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_action_size_over_lifetime *this,
        vostok::configs::binary_config_value *prop_config)
{
  vostok::configs::binary_config_value v2; // [esp-18h] [ebp-30h]

  this->m_multiply_x = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                         prop_config,
                         "MultiplyX",
                         &this->m_multiply_x);
  this->m_multiply_y = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                         prop_config,
                         "MultiplyY",
                         &this->m_multiply_y);
  this->m_multiply_z = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                         prop_config,
                         "MultiplyZ",
                         &this->m_multiply_z);
  v2 = *vostok::configs::binary_config_value::operator[](prop_config, "SizeLife");
  vostok::particle::curve_line_ranged_xyz_float::load<vostok::configs::binary_config_value>(&this->m_size_over_life, v2);
}
