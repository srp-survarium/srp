BOOL __thiscall vostok::render::stage_gbuffer::is_effects_ready(vostok::render::stage_gbuffer *this)
{
  BOOL result; // eax

  result = 0;
  if ( this->m_copy_depth_rt.m_object )
    return this->m_fill_depth_effect.m_object != 0;
  return result;
}
