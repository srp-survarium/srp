void __thiscall vostok::ui::ui_text_edit::draw(
        vostok::ui::ui_text_edit *this,
        vostok::render::ui::renderer *render,
        vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view)
{
  vostok::ui::ui_text_edit *v4; // esi
  vostok::ui::ui_text_edit *v5; // ecx
  int v6; // eax
  vostok::ui::ui_text_edit *v7; // ecx

  vostok::ui::ui_text<vostok::ui::dynamic_text>::draw_internal(
    (vostok::ui::ui_text<vostok::ui::dynamic_text> *)LOWORD(this->m_cursor_color),
    (int)&this[-1].m_shift_state,
    render,
    scene_view,
    LOWORD(this->m_cursor_color),
    HIWORD(this->m_cursor_color),
    (vostok::math::color)-16711423);
  v4 = (vostok::ui::ui_text_edit *)((char *)this - 8);
  vostok::ui::ui_text_edit::draw_highlighted_rect(
    v5,
    (int)&this[-1].m_sel_start,
    render,
    (vostok::render::ui::renderer *)scene_view);
  v6 = (int)v4->w(v4);
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 56))(v6) )
    vostok::ui::ui_text_edit::draw_cursor(v7, v4, render, (vostok::render::ui::renderer *)scene_view);
}
