void __thiscall vostok::engine::engine_world::enter_editor_mode(vostok::engine::engine_world *this)
{
  if ( this->m_render_world )
    (*(void (__thiscall **)(vostok::render::world *, int))&this->m_render_world->m_logic_channel.m_channel.m_forward_queue.m_head->m_cache_line_pad_$29[6])(
      this->m_render_world,
      1);
}
