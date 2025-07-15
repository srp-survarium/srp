void __thiscall vostok::particle::particle_action_gravity::load(
        vostok::particle::particle_action_gravity *this,
        vostok::memory::base_allocator *allocator,
        const vostok::configs::binary_config_value *prop_config)
{
  vostok::configs::binary_config_value *v4; // ecx

  vostok::particle::particle_action::load(this, allocator, prop_config);
  LODWORD(this->m_force) = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                             "Force",
                             v4,
                             prop_config,
                             (const vostok::configs::binary_config_value *)&this->m_force);
}
