void __thiscall vostok::particle::particle_action::load(
        vostok::particle::particle_action *this,
        vostok::memory::base_allocator *allocator,
        const vostok::configs::binary_config_value *config)
{
  char v3; // [esp+7h] [ebp-1h] BYREF

  v3 = 1;
  this->m_visibility = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                         "Enabled",
                         (vostok::configs::binary_config_value *)this,
                         config,
                         (const bool *)&v3);
}
