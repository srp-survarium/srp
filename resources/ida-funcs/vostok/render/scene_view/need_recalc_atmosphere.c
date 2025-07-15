bool __thiscall vostok::render::scene_view::need_recalc_atmosphere(vostok::render::scene_view *this)
{
  bool result; // al
  bool atmosphere_use_sun_illumination; // al

  if ( !this->m_force_recalc_atmosphere
    && this->m_environment_properties.atmosphere_rayleighSun_multiplier == this->atmosphere_rayleighSun_multiplier
    && this->m_environment_properties.atmosphere_mieSun_multiplier == this->atmosphere_mieSun_multiplier
    && this->m_environment_properties.atmosphere_rayleighPi_multiplier == this->atmosphere_rayleighPi_multiplier
    && this->m_environment_properties.atmosphere_miePi_multiplier == this->atmosphere_miePi_multiplier
    && this->m_environment_properties.atmosphere_use_sun_illumination == this->atmosphere_use_sun_illumination
    && this->m_environment_properties.sun_position_azimut == this->sun_position_azimut
    && this->m_environment_properties.sun_angle == this->sun_angle )
  {
    return 0;
  }
  atmosphere_use_sun_illumination = this->m_environment_properties.atmosphere_use_sun_illumination;
  this->atmosphere_rayleighSun_multiplier = this->m_environment_properties.atmosphere_rayleighSun_multiplier;
  this->atmosphere_use_sun_illumination = atmosphere_use_sun_illumination;
  result = 1;
  this->atmosphere_mieSun_multiplier = this->m_environment_properties.atmosphere_mieSun_multiplier;
  this->atmosphere_rayleighPi_multiplier = this->m_environment_properties.atmosphere_rayleighPi_multiplier;
  this->atmosphere_miePi_multiplier = this->m_environment_properties.atmosphere_miePi_multiplier;
  this->sun_position_azimut = this->m_environment_properties.sun_position_azimut;
  this->sun_angle = this->m_environment_properties.sun_angle;
  return result;
}
