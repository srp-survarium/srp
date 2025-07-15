void __userpurge vostok::particle::particle_action_gravity::load(
        vostok::particle::particle_action_gravity *this@<ecx>,
        float a2@<xmm0>,
        vostok::configs::binary_config_value *prop_config)
{
  vostok::particle::particle_action::load(this, prop_config);
  this->m_force = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                    a2,
                    prop_config,
                    "Force",
                    &this->m_force);
}
