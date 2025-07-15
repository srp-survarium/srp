void __thiscall vostok::render::render_output_window_cook::render_output_window_cook(
        vostok::render::render_output_window_cook *this)
{
  render_output_window_cook.__vftable = (vostok::render::render_output_window_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  render_output_window_cook.m_cook_users_count.m_count = 0;
  render_output_window_cook.m_class_id = render_output_window_class;
  render_output_window_cook.m_reuse_type = reuse_false;
  render_output_window_cook.m_creation_thread_id = -1;
  render_output_window_cook.m_allocate_thread_id = GetCurrentThreadId();
  render_output_window_cook.m_next = 0;
  render_output_window_cook.m_flags.m_flags = 8;
  render_output_window_cook.__vftable = (vostok::render::render_output_window_cook_vtbl *)&vostok::render::render_output_window_cook::`vftable';
}
