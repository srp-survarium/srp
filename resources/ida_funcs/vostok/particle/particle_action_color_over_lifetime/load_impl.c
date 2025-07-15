void __thiscall vostok::particle::particle_action_color_over_lifetime::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_action_color_over_lifetime *this,
        vostok::configs::binary_config_value *prop_config)
{
  vostok::configs::binary_config_value v2; // [esp-18h] [ebp-ECh]

  v2 = *vostok::configs::binary_config_value::operator[](prop_config, "ColorLifeMatrix");
  vostok::particle::color_matrix::load<vostok::configs::binary_config_value>(&this->m_color_over_life, v2);
}
