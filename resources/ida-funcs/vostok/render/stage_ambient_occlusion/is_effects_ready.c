BOOL __thiscall vostok::render::stage_ambient_occlusion::is_effects_ready(
        vostok::render::stage_ambient_occlusion *this)
{
  BOOL result; // eax

  result = 0;
  if ( this->m_sh_ssao_accumulation.m_object )
  {
    if ( this->m_sh_ssao_filter4x4.m_object )
      return this->m_sh_ssao_downsample_position_and_normal.m_object != 0;
  }
  return result;
}
