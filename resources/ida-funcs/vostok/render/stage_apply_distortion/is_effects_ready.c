BOOL __thiscall vostok::render::stage_apply_distortion::is_effects_ready(vostok::render::stage_apply_distortion *this)
{
  BOOL result; // eax

  result = 0;
  if ( this->m_sh_apply_distortion.m_object )
    return this->m_olta_effect.m_object != 0;
  return result;
}
