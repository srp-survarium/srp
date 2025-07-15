void __thiscall vostok::particle::particle_action_random_velocity::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_action_random_velocity *this,
        const vostok::configs::binary_config_value *prop_config)
{
  vostok::particle::particle_domain_complex::load(&this->m_domain, prop_config);
  this->m_velocity_multiplier = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                                  prop_config,
                                  "VelocityMultiplier",
                                  &this->m_velocity_multiplier);
}
