void __userpurge vostok::ui::ui_text_edit::draw_highlighted_rect(
        vostok::ui::ui_text_edit *this@<ecx>,
        int a2@<esi>,
        vostok::render::ui::renderer *render,
        vostok::render::ui::renderer *scene_view)
{
  int (__thiscall *v4)(int); // eax
  int v5; // eax
  unsigned __int16 v6; // di
  float v7; // xmm0_4
  const char *v8; // eax
  unsigned __int16 v9; // di
  float v10; // xmm0_4
  float x; // xmm5_4
  const char *v12; // eax
  vostok::math::float2 pos1; // [esp+Ch] [ebp-88h] BYREF
  float h; // [esp+14h] [ebp-80h]
  vostok::render::ui::vertex vertices[4]; // [esp+18h] [ebp-7Ch] BYREF
  vostok::math::float2 pos2; // [esp+88h] [ebp-Ch] BYREF

  if ( *(_WORD *)(a2 + 680) != *(_WORD *)(a2 + 682) )
  {
    pos1 = *(vostok::math::float2 *)(*(int (__thiscall **)(int))(*(_DWORD *)(a2 + 8) + 4))(a2 + 8);
    vostok::ui::client_to_screen((const vostok::ui::ui_window *)(a2 + 8), &pos1);
    v4 = *(int (__thiscall **)(int))(*(_DWORD *)(a2 + 8) + 12);
    pos2.x = pos1.x;
    v5 = v4(a2 + 8);
    v6 = *(_WORD *)(a2 + 680);
    v7 = *(float *)(v5 + 4);
    h = v7;
    if ( v6 )
    {
      v8 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)(a2 + 4) + 12))(a2 + 4);
      vostok::ui::calc_string_length_n(*(const vostok::ui::ui_font **)(a2 + 596), v8, v6);
    }
    else
    {
      v7 = 0.0;
    }
    v9 = *(_WORD *)(a2 + 682);
    v10 = v7 + pos1.x;
    x = v10;
    pos1.x = v10;
    if ( v9 )
    {
      v12 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)(a2 + 4) + 12))(a2 + 4);
      vostok::ui::calc_string_length_n(*(const vostok::ui::ui_font **)(a2 + 596), v12, v9);
      x = pos1.x;
    }
    else
    {
      v10 = 0.0;
    }
    vertices[0].m_color = 822083583;
    vertices[1].m_color = 822083583;
    vertices[2].m_color = 822083583;
    vertices[3].m_color = 822083583;
    vertices[0].m_position.x = x;
    vertices[0].m_position.y = pos1.y + h;
    *(_QWORD *)&vertices[0].m_position.elements[2] = 0;
    vertices[0].m_uv.x = 0.0;
    LODWORD(vertices[0].m_uv.y) = clear_value;
    vertices[1].m_position.x = x;
    *(_QWORD *)&vertices[1].m_position.elements[1] = LODWORD(pos1.y);
    vertices[1].m_position.w = 0.0;
    vertices[1].m_uv = 0;
    vertices[2].m_position.x = v10 + pos2.x;
    vertices[2].m_position.y = pos1.y + h;
    *(_QWORD *)&vertices[2].m_position.elements[2] = 0;
    LODWORD(vertices[2].m_uv.x) = clear_value;
    LODWORD(vertices[2].m_uv.y) = clear_value;
    vertices[3].m_position.x = v10 + pos2.x;
    *(_QWORD *)&vertices[3].m_position.elements[1] = LODWORD(pos1.y);
    vertices[3].m_position.w = 0.0;
    vertices[3].m_uv = (vostok::math::float2)(unsigned int)clear_value;
    vostok::render::ui::renderer::draw_vertices(
      scene_view,
      (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)scene_view,
      vertices,
      (const vostok::render::ui::vertex *)&pos2,
      0,
      2u);
  }
}
