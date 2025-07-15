void __thiscall vostok::particle::particle_action_random_direction::load(
        vostok::particle::particle_action_random_direction *this,
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
  this->m_is_reverse = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                         "ReverseDirection",
                         v5,
                         prop_config,
                         &this->m_is_reverse);
}
