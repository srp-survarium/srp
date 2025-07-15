BOOL __thiscall vostok::render::stage_composition::is_effects_ready(vostok::render::stage_composition *this)
{
  BOOL result; // eax

  result = 0;
  if ( this->m_composition_effect[0].m_object )
  {
    if ( this->m_composition_effect[1].m_object )
      return this->m_debug_modify_gbuffer_effect.m_object != 0;
  }
  return result;
}
