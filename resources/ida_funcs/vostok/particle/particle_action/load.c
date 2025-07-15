void __thiscall vostok::particle::particle_action::load(
        vostok::particle::particle_action *this,
        const vostok::configs::binary_config_value *config)
{
  vostok::particle::particle_action::load_impl<vostok::configs::binary_config_value>(this, config);
}
