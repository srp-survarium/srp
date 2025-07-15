void __thiscall vostok::particle::particle_action::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_action *this,
        const vostok::configs::binary_config_value *config)
{
  bool default_value; // [esp+7h] [ebp-1h] BYREF

  default_value = 1;
  this->m_visibility = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                         config,
                         "Enabled",
                         &default_value);
}
