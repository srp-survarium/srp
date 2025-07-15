BOOL __thiscall vostok::render::stage_ambient_lighting::is_effects_ready(vostok::render::stage_ambient_lighting *this)
{
  BOOL result; // eax

  result = 0;
  if ( this->m_skylight_effect.m_object
    && this->m_sky_ambient_occlusion_effect.m_object
    && this->m_ambient_volume_effect.m_object
    && this->m_ambient_light_effect[0][0][0].m_object
    && this->m_ambient_light_effect[1][0][0].m_object
    && this->m_ambient_light_effect[2][0][0].m_object
    && this->m_ambient_light_effect[0][1][0].m_object
    && this->m_ambient_light_effect[1][1][0].m_object
    && this->m_ambient_light_effect[2][1][0].m_object
    && this->m_ambient_light_effect[0][0][1].m_object
    && this->m_ambient_light_effect[1][0][1].m_object
    && this->m_ambient_light_effect[2][0][1].m_object
    && this->m_ambient_light_effect[0][1][1].m_object
    && this->m_ambient_light_effect[1][1][1].m_object
    && this->m_ambient_light_effect[2][1][1].m_object
    && this->m_apply_ambient_lights_effect.m_object
    && this->m_environment_probe_lighting_effect[0][0].m_object
    && this->m_environment_probe_lighting_effect[1][0].m_object
    && this->m_environment_probe_lighting_effect[0][1].m_object
    && this->m_environment_probe_lighting_effect[1][1].m_object
    && this->m_environment_probe_index_effect.m_object
    && this->m_reflection_mask_effect.m_object )
  {
    if ( this->m_apply_ssao_effect.m_object )
      return this->m_sh_ssao_downsample_position_and_normal.m_object != 0;
  }
  return result;
}
