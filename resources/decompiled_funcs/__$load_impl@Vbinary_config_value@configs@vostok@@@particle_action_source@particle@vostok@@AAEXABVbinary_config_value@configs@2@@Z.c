void __thiscall vostok::particle::particle_action_source::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_action_source *this,
        const vostok::configs::binary_config_value *prop_config)
{
  vostok::particle::particle_domain_complex::load(&this->m_domain, prop_config);
}
