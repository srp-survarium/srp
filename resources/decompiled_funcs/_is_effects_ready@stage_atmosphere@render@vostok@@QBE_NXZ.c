BOOL __thiscall vostok::render::stage_atmosphere::is_effects_ready(vostok::render::stage_atmosphere *this)
{
  return this->m_atmospheric_scattering_effect.m_object != 0;
}
