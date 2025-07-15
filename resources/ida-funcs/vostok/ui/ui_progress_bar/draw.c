void __thiscall vostok::ui::ui_progress_bar::draw(
        vostok::ui::ui_progress_bar *this,
        vostok::render::ui::renderer *renderer,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view)
{
  vostok::ui::ui_progress_bar *v4; // ecx
  vostok::ui::ui_progress_bar *v5; // ecx

  vostok::ui::ui_window::draw((vostok::ui::ui_window *)this, renderer, scene_view);
  vostok::ui::ui_progress_bar::draw_back_rectangle(
    v4,
    (vostok::render::ui::renderer *)&this[-1].m_draw_text,
    (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)renderer,
    scene_view);
  if ( this->m_maximum != this->m_border_height )
    vostok::ui::ui_progress_bar::draw_front_rectangle(v5, &this[-1].m_draw_text, renderer, scene_view);
  if ( this->m_text.m_buffer[28] )
    vostok::ui::ui_progress_bar::draw_text(v5, (int)&this[-1].m_draw_text, renderer, scene_view);
}
