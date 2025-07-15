void __thiscall vostok::particle::particle_action_random_velocity::load(
        vostok::particle::particle_action_random_velocity *this,
        const vostok::configs::binary_config_value *prop_config)
{
  vostok::particle::particle_action::load(this, prop_config);
  vostok::particle::particle_action_random_velocity::load_impl<vostok::configs::binary_config_value>(this, prop_config);
}
