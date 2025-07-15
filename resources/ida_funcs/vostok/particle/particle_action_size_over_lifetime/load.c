void __thiscall vostok::particle::particle_action_size_over_lifetime::load(
        vostok::particle::particle_action_size_over_lifetime *this,
        vostok::configs::binary_config_value *prop_config)
{
  vostok::particle::particle_action::load(this, prop_config);
  vostok::particle::particle_action_size_over_lifetime::load_impl<vostok::configs::binary_config_value>(
    this,
    prop_config);
}
