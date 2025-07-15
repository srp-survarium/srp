void __thiscall vostok::ui::ui_text_edit::draw(
        vostok::ui::ui_text_edit *this,
        vostok::render::ui::renderer *render,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view)
{
  vostok::ui::ui_text_edit *v4; // ecx
  int v5; // eax
  vostok::ui::ui_text_edit *v6; // ecx

  vostok::ui::ui_text<vostok::ui::dynamic_text>::draw_internal(
    (vostok::ui::ui_text<vostok::ui::dynamic_text> *)this,
    (int)&this[-1].m_shift_state,
    render,
    scene_view,
    LOWORD(this->m_cursor_color),
    HIWORD(this->m_cursor_color),
    (vostok::math::color)-16711423);
  vostok::ui::ui_text_edit::draw_highlighted_rect(v4, (int)&this[-1].m_sel_start, render, scene_view);
  v5 = (*(int (__thiscall **)(unsigned __int16 *))(*(_DWORD *)&this[-1].m_sel_start + 20))(&this[-1].m_sel_start);
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 56))(v5) )
    vostok::ui::ui_text_edit::draw_cursor(v6, (int)&this[-1].m_sel_start, render, scene_view);
}
