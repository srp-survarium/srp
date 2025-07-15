void __thiscall vostok::ui::ui_text_edit::draw_cursor(
        vostok::ui::ui_text_edit *this,
        vostok::ui::ui_text_edit *render,
        vostok::render::ui::renderer *scene_view,
        vostok::render::ui::renderer *scene_viewa)
{
  float *v4; // eax
  float v5; // xmm0_4
  int v6; // eax
  unsigned __int16 m_caret_pos; // si
  float v8; // xmm4_4
  const char *v9; // eax
  vostok::math::float2 pos; // [esp+10h] [ebp-78h] BYREF
  vostok::render::ui::vertex vertices[4]; // [esp+18h] [ebp-70h] BYREF
  _UNKNOWN *retaddr; // [esp+88h] [ebp+0h] BYREF

  v4 = (float *)render->get_position(&render->vostok::ui::ui_window);
  pos.x = *v4;
  v5 = v4[1];
  pos.y = v5;
  vostok::ui::client_to_screen(&render->vostok::ui::ui_window, &pos);
  v6 = (int)render->get_size(&render->vostok::ui::ui_window);
  m_caret_pos = render->m_caret_pos;
  v8 = *(float *)(v6 + 4) - 4.0;
  if ( m_caret_pos )
  {
    v9 = render->get_text(&render->vostok::ui::ui_text<vostok::ui::dynamic_text>);
    vostok::ui::calc_string_length_n(render->m_font, v9, m_caret_pos);
  }
  else
  {
    v5 = 0.0;
  }
  vertices[0].m_color = render->m_cursor_color;
  vertices[1].m_color = vertices[0].m_color;
  vertices[2].m_color = vertices[0].m_color;
  vertices[3].m_color = vertices[0].m_color;
  vertices[0].m_position.x = v5 + pos.x;
  vertices[1].m_position.x = v5 + pos.x;
  vertices[0].m_position.y = pos.y + 2.0;
  *(_QWORD *)&vertices[0].m_position.elements[2] = 0;
  vertices[0].m_uv = 0;
  vertices[1].m_position.y = (float)(pos.y + 2.0) + v8;
  *(_QWORD *)&vertices[1].m_position.elements[2] = 0;
  vertices[1].m_uv = 0;
  vertices[2].m_position.x = (float)(v5 + pos.x) + *(float *)&clear_value;
  vertices[2].m_position.y = pos.y + 2.0;
  *(_QWORD *)&vertices[2].m_position.elements[2] = 0;
  vertices[2].m_uv = 0;
  vertices[3].m_position.x = vertices[2].m_position.x;
  vertices[3].m_position.y = vertices[1].m_position.y;
  *(_QWORD *)&vertices[3].m_position.elements[2] = 0;
  vertices[3].m_uv = 0;
  vostok::render::ui::renderer::draw_vertices(
    scene_viewa,
    (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)scene_viewa,
    vertices,
    (const vostok::render::ui::vertex *)&retaddr,
    1u,
    1u);
}
