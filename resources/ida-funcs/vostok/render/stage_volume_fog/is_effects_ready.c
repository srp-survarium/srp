BOOL __thiscall vostok::render::stage_volume_fog::is_effects_ready(vostok::render::stage_volume_fog *this)
{
  return this->m_exponential_volume_fog_effect.m_object != 0;
}
