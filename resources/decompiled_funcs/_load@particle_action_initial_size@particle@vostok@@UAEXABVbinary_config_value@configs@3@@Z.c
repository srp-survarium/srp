void __thiscall vostok::particle::particle_action_initial_size::load(
        vostok::particle::particle_action_initial_size *this,
        vostok::configs::binary_config_value *prop_config)
{
  vostok::particle::particle_action::load(this, prop_config);
  vostok::particle::particle_action_initial_size::load_impl<vostok::configs::binary_config_value>(this, prop_config);
}
