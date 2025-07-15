void __thiscall vostok::particle::particle_action_animation_impulse::load(
        vostok::particle::particle_action_animation_impulse *this,
        vostok::memory::base_allocator *allocator,
        const vostok::configs::binary_config_value *prop_config)
{
  vostok::configs::binary_config_value *v4; // ecx
  vostok::configs::binary_config_value *v5; // ecx

  vostok::particle::particle_action::load(this, allocator, prop_config);
  LODWORD(this->m_fade_time) = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                                 "FadeTime",
                                 v4,
                                 prop_config,
                                 (const vostok::configs::binary_config_value *)&this->m_fade_time);
  LODWORD(this->m_magnitude) = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                                 "Magnitude",
                                 v5,
                                 prop_config,
                                 (const vostok::configs::binary_config_value *)&this->m_magnitude);
}
