void __thiscall vostok::particle::particle_event::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_event *this,
        const vostok::configs::binary_config_value *config)
{
  this->m_inherit_position = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                               config,
                               "InheritPosition",
                               &this->m_inherit_position);
}
