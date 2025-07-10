void __thiscall vostok::particle::particle_action_orbit::load(
        vostok::particle::particle_action_orbit *this,
        vostok::configs::binary_config_value *prop_config)
{
  vostok::particle::particle_action::load(this, prop_config);
  vostok::particle::particle_action_orbit::load_impl<vostok::configs::binary_config_value>(this, prop_config);
}
