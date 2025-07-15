void __thiscall vostok::particle::particle_action_random_velocity::load(
        vostok::particle::particle_action_random_velocity *this,
        vostok::memory::base_allocator *allocator,
        const vostok::configs::binary_config_value *prop_config)
{
  vostok::particle::particle_domain_complex *v4; // ecx
  vostok::configs::binary_config_value *v5; // ecx

  vostok::particle::particle_action::load(this, allocator, prop_config);
  vostok::particle::particle_domain_complex::load_impl<vostok::configs::binary_config_value>(
    v4,
    (const vostok::configs::binary_config_value *)&this->m_domain,
    (vostok::math::float3 *)prop_config);
  LODWORD(this->m_velocity_multiplier) = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                                           "VelocityMultiplier",
                                           v5,
                                           prop_config,
                                           (const vostok::configs::binary_config_value *)&this->m_velocity_multiplier);
}
