void __userpurge vostok::particle::particle_action_kill_volume::load(
        vostok::particle::particle_action_kill_volume *this@<ecx>,
        float a2@<xmm0>,
        vostok::configs::binary_config_value *prop_config)
{
  vostok::particle::particle_action::load(this, prop_config);
  vostok::particle::particle_domain_complex::load(&this->m_domain, a2, prop_config);
  this->m_kill_inside = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                          prop_config,
                          "KillInside",
                          &this->m_kill_inside);
}
