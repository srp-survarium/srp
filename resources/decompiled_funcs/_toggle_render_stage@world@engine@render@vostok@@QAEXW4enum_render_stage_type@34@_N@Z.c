void __thiscall vostok::render::engine::world::toggle_render_stage(
        vostok::render::engine::world *this,
        vostok::render::enum_render_stage_type stage_type,
        bool toggle)
{
  vostok::render::stage **m_begin; // eax
  bool v4; // zf
  vostok::render::stage **v5; // eax

  if ( this->m_renderer )
  {
    m_begin = this->m_renderer->m_stages.m_begin;
    v4 = m_begin[stage_type] == 0;
    v5 = &m_begin[stage_type];
    if ( !v4 )
      (*v5)->m_enabled = toggle;
  }
}
