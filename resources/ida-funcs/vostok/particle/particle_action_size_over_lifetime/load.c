void __thiscall vostok::particle::particle_action_size_over_lifetime::load(
        vostok::particle::particle_action_size_over_lifetime *this,
        vostok::memory::base_allocator *allocator,
        const vostok::configs::binary_config_value *prop_config)
{
  vostok::configs::binary_config_value *v4; // ecx

  vostok::particle::particle_action::load(this, allocator, prop_config);
  vostok::particle::particle_action_size_over_lifetime::load_impl<vostok::configs::binary_config_value>(
    prop_config,
    v4,
    this,
    allocator);
}
