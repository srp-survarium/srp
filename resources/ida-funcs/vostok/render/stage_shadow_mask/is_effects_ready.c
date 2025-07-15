BOOL __thiscall vostok::render::stage_shadow_mask::is_effects_ready(vostok::render::stage_shadow_mask *this)
{
  BOOL result; // eax

  result = 0;
  if ( this->m_shadow_mask_effect.m_object
    && this->m_sun_shadow_apply_effect[0][0].m_object
    && this->m_sun_shadow_apply_effect[0][1].m_object
    && this->m_sun_shadow_apply_effect[0][2].m_object
    && this->m_sun_shadow_apply_effect[0][3].m_object
    && this->m_sun_shadow_apply_effect[1][0].m_object
    && this->m_sun_shadow_apply_effect[1][1].m_object
    && this->m_sun_shadow_apply_effect[1][2].m_object )
  {
    if ( this->m_sun_shadow_apply_effect[1][3].m_object )
      return this->m_far_plane_mask_effect.m_object != 0;
  }
  return result;
}
