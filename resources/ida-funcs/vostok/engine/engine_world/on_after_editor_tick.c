void __thiscall vostok::engine::engine_world::on_after_editor_tick(vostok::engine::engine_world *this)
{
  vostok::engine::engine_world *v2; // edi
  vostok::tasks *v3; // ecx

  v2 = (vostok::engine::engine_world *)((char *)this - 8);
  if ( vostok::threading::core_count(this) != 1 && v2->command_line_editor_singlethread(v2) )
  {
    while ( v2->m_logic_frame_id > v2->m_render_world->m_engine_renderer->m_render_engine_world->m_frame_id + 1
         && !v2->m_destruction_started )
      vostok::threading::yield(0, v3);
  }
  ++this->m_render_window_handle;
}
