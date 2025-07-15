void __thiscall vostok::particle::particle_action_beam::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_action_beam *this,
        const vostok::configs::binary_config_value *prop_config)
{
  this->m_beamtrail_parameters.num_sheets = vostok::particle::read_config_value<unsigned int,vostok::configs::binary_config_value>(
                                              prop_config,
                                              "SheetsCount",
                                              &this->m_beamtrail_parameters.num_sheets);
  this->m_beamtrail_parameters.num_texture_tiles = vostok::particle::read_config_value<unsigned int,vostok::configs::binary_config_value>(
                                                     prop_config,
                                                     "TextureTile",
                                                     &this->m_beamtrail_parameters.num_texture_tiles);
  this->m_beamtrail_parameters.num_beams = vostok::particle::read_config_value<unsigned int,vostok::configs::binary_config_value>(
                                             prop_config,
                                             "BeamsCount",
                                             &this->m_beamtrail_parameters.num_beams);
  this->m_speed = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                    prop_config,
                    "Speed",
                    &this->m_speed);
  this->m_noise = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                    prop_config,
                    "Noise",
                    &this->m_noise);
  this->m_frequency = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                        prop_config,
                        "Frequency",
                        &this->m_frequency);
  vostok::math::clamp<unsigned int>(&this->m_beamtrail_parameters.num_sheets, 0, 0x3E8u);
  vostok::math::clamp<unsigned int>(&this->m_beamtrail_parameters.num_texture_tiles, 0, 0x3E8u);
  vostok::math::clamp<unsigned int>(&this->m_beamtrail_parameters.num_beams, 1u, 0x3E8u);
  vostok::math::clamp<float>(&this->m_speed, 0.0, 1000.0);
  vostok::math::clamp<float>(&this->m_noise, 0.0, 1000.0);
  vostok::math::clamp<float>(&this->m_frequency, 0.0, 1000.0);
}
