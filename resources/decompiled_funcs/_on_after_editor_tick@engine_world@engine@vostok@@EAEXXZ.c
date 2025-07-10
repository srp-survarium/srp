void __thiscall vostok::engine::engine_world::on_after_editor_tick(vostok::engine::engine_world *this)
{
  vostok::engine::engine_world::on_after_editor_tick_impl(this);
  ++this->m_render_window_handle;
}
