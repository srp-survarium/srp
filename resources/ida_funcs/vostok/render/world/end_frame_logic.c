void __thiscall vostok::render::world::end_frame_logic(vostok::render::world *this)
{
  vostok::render::one_way_render_channel::render_on_end_frame(&this->m_logic_channel);
  this->m_is_logic_frame_ended = 1;
  if ( this->m_is_editor_frame_ended )
  {
    ++this->m_render_engine_world->m_frame_id;
    if ( this->m_is_logic_enabled )
      this->m_is_logic_frame_ended = 0;
    if ( this->m_is_editor )
      this->m_is_editor_frame_ended = 0;
  }
}
