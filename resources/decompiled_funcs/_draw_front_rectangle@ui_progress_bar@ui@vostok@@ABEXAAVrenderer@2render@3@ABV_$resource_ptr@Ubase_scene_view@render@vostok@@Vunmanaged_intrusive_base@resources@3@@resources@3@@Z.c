void __userpurge vostok::ui::ui_progress_bar::draw_front_rectangle(
        vostok::ui::ui_progress_bar *this@<ecx>,
        int a2@<eax>,
        vostok::render::ui::renderer *renderer,
        vostok::render::ui::renderer *scene_view)
{
  int v5; // ebx
  float *v6; // eax
  float v7; // xmm2_4
  float v8; // xmm1_4
  double v9; // st7
  int v10; // eax
  double v11; // st7
  double v12; // st6
  unsigned int v13; // esi
  float v14; // [esp+Ch] [ebp-88h]
  float v15; // [esp+Ch] [ebp-88h]
  vostok::math::float2 pos; // [esp+10h] [ebp-84h] BYREF
  vostok::math::float2 inner_size; // [esp+18h] [ebp-7Ch]
  vostok::render::ui::vertex top_vertices[4]; // [esp+20h] [ebp-74h] BYREF
  char v19; // [esp+90h] [ebp-4h] BYREF

  v5 = a2 + 4;
  pos = *(vostok::math::float2 *)(*(int (__thiscall **)(int))(*(_DWORD *)(a2 + 4) + 4))(a2 + 4);
  vostok::ui::client_to_screen((const vostok::ui::ui_window *)(a2 + 4), &pos);
  v6 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a2 + 4);
  v7 = v6[1];
  v14 = (float)*(unsigned int *)(a2 + 84);
  v8 = v14;
  v9 = (double)*(unsigned int *)(a2 + 88);
  inner_size.x = *v6 - (float)(v14 * 2.0);
  v10 = *(_DWORD *)(a2 + 92);
  v15 = v9;
  v11 = (double)(unsigned int)(*(_DWORD *)(a2 + 100) - v10);
  v12 = (double)(unsigned int)(*(_DWORD *)(a2 + 96) - v10);
  v13 = *(_DWORD *)(a2 + 76);
  top_vertices[0].m_position.x = v8 + pos.x;
  top_vertices[1].m_position.x = v8 + pos.x;
  *(_QWORD *)&top_vertices[0].m_position.elements[1] = COERCE_UNSIGNED_INT((float)(v7 - (float)(v15 * 2.0)) + (float)(v15 + pos.y));
  top_vertices[0].m_position.w = 0.0;
  top_vertices[0].m_color = v13;
  top_vertices[0].m_uv.x = 0.0;
  LODWORD(top_vertices[0].m_uv.y) = clear_value;
  *(_QWORD *)&top_vertices[1].m_position.elements[1] = COERCE_UNSIGNED_INT(v15 + pos.y);
  top_vertices[1].m_position.w = 0.0;
  top_vertices[1].m_color = v13;
  top_vertices[1].m_uv = 0;
  *(_QWORD *)&top_vertices[2].m_position.elements[1] = *(_QWORD *)&top_vertices[0].m_position.elements[1];
  top_vertices[2].m_position.w = 0.0;
  top_vertices[2].m_color = v13;
  LODWORD(top_vertices[2].m_uv.x) = clear_value;
  LODWORD(top_vertices[2].m_uv.y) = clear_value;
  *(_QWORD *)&top_vertices[3].m_position.elements[1] = *(_QWORD *)&top_vertices[1].m_position.elements[1];
  top_vertices[3].m_position.w = 0.0;
  top_vertices[3].m_color = v13;
  top_vertices[3].m_uv = (vostok::math::float2)(unsigned int)clear_value;
  inner_size.x = v11 / v12 * inner_size.x;
  top_vertices[2].m_position.x = (float)(v8 + pos.x) + inner_size.x;
  top_vertices[3].m_position.x = top_vertices[2].m_position.x;
  vostok::render::ui::renderer::draw_vertices(
    scene_view,
    (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)scene_view,
    top_vertices,
    (const vostok::render::ui::vertex *)&v19,
    0,
    2u);
}
