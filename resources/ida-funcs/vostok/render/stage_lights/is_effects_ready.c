BOOL __thiscall vostok::render::stage_lights::is_effects_ready(vostok::render::stage_lights *this)
{
  BOOL result; // eax

  result = 0;
  if ( this->m_shadow_effect.m_object
    && this->m_effect_accum_mask.m_object
    && this->m_point_light_accumulator.m_object
    && this->m_point_light_shadower.m_object
    && this->m_shadowed_point_light_accumulator.m_object
    && this->m_spot_light_accumulator.m_object
    && this->m_shadowed_spot_light_accumulator.m_object
    && this->m_capsule_light_accumulator.m_object
    && this->m_obb_light_accumulator.m_object
    && this->m_shadowed_obb_light_accumulator.m_object
    && this->m_sphere_light_accumulator.m_object
    && this->m_shadowed_sphere_light_accumulator.m_object
    && this->m_shadowed_plane_spot_light_accumulator.m_object
    && this->m_sh_downsample_skin_irradiance_texture.m_object )
  {
    if ( this->m_sh_fix_irradiance_texture.m_object )
      return this->m_plane_spot_light_accumulator.m_object != 0;
  }
  return result;
}
