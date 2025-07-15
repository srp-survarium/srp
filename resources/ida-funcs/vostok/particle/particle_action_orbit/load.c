void __thiscall vostok::particle::particle_action_orbit::load(
        vostok::particle::particle_action_orbit *this,
        vostok::memory::base_allocator *allocator,
        const vostok::configs::binary_config_value *prop_config)
{
  vostok::particle::particle_action_orbit *v4; // ecx

  vostok::particle::particle_action::load(this, allocator, prop_config);
  vostok::particle::particle_action_orbit::load_impl<vostok::configs::binary_config_value>(
    v4,
    (vostok::memory::base_allocator *)this,
    (const vostok::configs::binary_config_value *)allocator,
    prop_config);
}
