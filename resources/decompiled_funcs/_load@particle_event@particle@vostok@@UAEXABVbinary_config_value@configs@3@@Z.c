void __thiscall vostok::particle::particle_event::load(
        vostok::particle::particle_event *this,
        const vostok::configs::binary_config_value *prop_config)
{
  vostok::particle::particle_action::load(this, prop_config);
  vostok::particle::particle_event::load_impl<vostok::configs::binary_config_value>(this, prop_config);
}
