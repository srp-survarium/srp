void __usercall vostok::particle::particle_action_turbulence::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_action_turbulence *this@<eax>,
        const vostok::configs::binary_config_value *prop_config@<edi>,
        vostok::configs::binary_config_value *a3@<ecx>)
{
  vostok::configs::binary_config_value *v4; // ecx
  vostok::configs::binary_config_value *v5; // ecx
  vostok::configs::binary_config_value *v6; // ecx
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // ecx
  vostok::configs::binary_config_value *v10; // ecx
  vostok::particle::particle_domain_complex *v11; // ecx

  LODWORD(this->m_magnitude) = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                                 "Magnitude",
                                 a3,
                                 prop_config,
                                 (const vostok::configs::binary_config_value *)&this->m_magnitude);
  LODWORD(this->m_min_magnitude) = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                                     "MinMagnitude",
                                     v4,
                                     prop_config,
                                     (const vostok::configs::binary_config_value *)&this->m_min_magnitude);
  LODWORD(this->m_attenuation) = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                                   "Attenuation",
                                   v5,
                                   prop_config,
                                   (const vostok::configs::binary_config_value *)&this->m_attenuation);
  LODWORD(this->m_frequency) = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                                 "Frequency",
                                 v6,
                                 prop_config,
                                 (const vostok::configs::binary_config_value *)&this->m_frequency);
  this->m_octaves = (unsigned int)vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
                                    "Octaves",
                                    v7,
                                    prop_config,
                                    (const vostok::configs::binary_config_value *)&this->m_octaves);
  LODWORD(this->m_ratio_x) = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                               "RatioX",
                               v8,
                               prop_config,
                               (const vostok::configs::binary_config_value *)&this->m_ratio_x);
  LODWORD(this->m_ratio_y) = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                               "RatioY",
                               v9,
                               prop_config,
                               (const vostok::configs::binary_config_value *)&this->m_ratio_y);
  LODWORD(this->m_ratio_z) = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                               "RatioZ",
                               v10,
                               prop_config,
                               (const vostok::configs::binary_config_value *)&this->m_ratio_z);
  vostok::particle::particle_domain_complex::load_impl<vostok::configs::binary_config_value>(
    v11,
    (const vostok::configs::binary_config_value *)&this->m_domain,
    (vostok::math::float3 *)prop_config);
}
