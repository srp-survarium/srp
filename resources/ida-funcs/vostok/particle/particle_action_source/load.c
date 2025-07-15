void __thiscall vostok::particle::particle_action_source::load(
        vostok::particle::particle_action_source *this,
        vostok::memory::base_allocator *allocator,
        const vostok::configs::binary_config_value *prop_config)
{
  vostok::particle::particle_domain_complex *v4; // ecx

  vostok::particle::particle_action::load(this, allocator, prop_config);
  vostok::particle::particle_domain_complex::load_impl<vostok::configs::binary_config_value>(
    v4,
    (const vostok::configs::binary_config_value *)&this->m_domain,
    (vostok::math::float3 *)prop_config);
}
