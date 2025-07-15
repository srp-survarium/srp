BOOL __thiscall vostok::render::stage_rain::is_effects_ready(vostok::render::stage_rain *this)
{
  BOOL result; // eax

  result = 0;
  if ( this->m_rain_effect.m_object )
    return this->m_effect_shadow_direct.m_object != 0;
  return result;
}
