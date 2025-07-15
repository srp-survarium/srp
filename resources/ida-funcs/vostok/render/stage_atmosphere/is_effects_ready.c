BOOL __thiscall vostok::render::stage_atmosphere::is_effects_ready(vostok::render::stage_atmosphere *this)
{
  BOOL result; // eax

  result = 0;
  if ( this->m_atmospheric_scattering_effect[0].m_object )
    return this->m_atmospheric_scattering_effect[1].m_object != 0;
  return result;
}
