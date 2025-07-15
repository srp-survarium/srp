void __thiscall vostok::ui::ui_progress_bar::draw(
        vostok::ui::ui_progress_bar *this,
        vostok::render::ui::renderer *renderer,
        vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view)
{
  vostok::ui::ui_progress_bar *v4; // ecx
  vostok::ui::ui_progress_bar *v5; // ecx
  vostok::render::ui::renderer *p_m_draw_text; // [esp+Ch] [ebp-4h]

  vostok::ui::ui_window::draw((vostok::ui::ui_window *)this, renderer, scene_view);
  p_m_draw_text = (vostok::render::ui::renderer *)&this[-1].m_draw_text;
  vostok::ui::ui_progress_bar::draw_back_rectangle(
    v4,
    (vostok::ui::ui_progress_bar *)((char *)this - 4),
    renderer,
    scene_view);
  if ( this->m_maximum != this->m_border_height )
    vostok::ui::ui_progress_bar::draw_front_rectangle(
      v5,
      (int)p_m_draw_text,
      renderer,
      (vostok::render::ui::renderer *)scene_view);
  if ( this->m_text.m_buffer[28] )
    vostok::ui::ui_progress_bar::draw_text(
      (vostok::ui::ui_progress_bar *)p_m_draw_text,
      *(float *)&p_m_draw_text,
      renderer,
      scene_view);
}
