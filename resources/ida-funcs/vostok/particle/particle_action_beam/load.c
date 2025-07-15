void __thiscall vostok::particle::particle_action_beam::load(
        vostok::particle::particle_action_beam *this,
        vostok::memory::base_allocator *allocator,
        const vostok::configs::binary_config_value *prop_config)
{
  vostok::particle::particle_action_beam *v4; // ecx
  const vostok::configs::binary_config_value *v5; // [esp+0h] [ebp-4h]

  vostok::particle::particle_action::load(this, allocator, prop_config);
  vostok::particle::particle_action_beam::load_impl<vostok::configs::binary_config_value>(
    v4,
    (int)this,
    prop_config,
    v5);
}
