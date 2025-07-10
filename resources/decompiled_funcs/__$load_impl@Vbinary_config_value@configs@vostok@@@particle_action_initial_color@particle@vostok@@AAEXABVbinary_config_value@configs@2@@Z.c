void __thiscall vostok::particle::particle_action_initial_color::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_action_initial_color *this,
        vostok::configs::binary_config_value *prop_config)
{
  vostok::configs::binary_config_value v2; // [esp-18h] [ebp-124h]

  v2 = *vostok::configs::binary_config_value::operator[](prop_config, "InitColor");
  vostok::particle::curve_line_color::load<vostok::configs::binary_config_value>(&this->m_init_color, v2);
}
