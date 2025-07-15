void __thiscall vostok::particle::particle_event::load(
        vostok::particle::particle_event *this,
        vostok::memory::base_allocator *allocator,
        const vostok::configs::binary_config_value *prop_config)
{
  vostok::configs::binary_config_value *v4; // ecx

  vostok::particle::particle_action::load(this, allocator, prop_config);
  this->m_inherit_position = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                               "InheritPosition",
                               v4,
                               prop_config,
                               &this->m_inherit_position);
}
