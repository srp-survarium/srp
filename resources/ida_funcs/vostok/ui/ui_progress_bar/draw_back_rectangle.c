void __thiscall vostok::ui::ui_progress_bar::draw_back_rectangle(
        vostok::ui::ui_progress_bar *this,
        const vostok::ui::ui_progress_bar *renderer,
        vostok::render::ui::renderer *scene_view,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_viewa)
{
  float *v4; // eax
  float v5; // xmm1_4
  float v6; // xmm0_4
  vostok::math::float2 pos; // [esp+10h] [ebp-78h] BYREF
  vostok::render::ui::vertex back_vertices[4]; // [esp+18h] [ebp-70h] BYREF
  _UNKNOWN *retaddr; // [esp+88h] [ebp+0h] BYREF

  pos = *renderer->get_position(&renderer->vostok::ui::ui_window);
  vostok::ui::client_to_screen(&renderer->vostok::ui::ui_window, &pos);
  v4 = (float *)renderer->get_size(&renderer->vostok::ui::ui_window);
  v5 = *v4;
  v6 = v4[1];
  back_vertices[0].m_color = renderer->m_back_color.m_value;
  back_vertices[1].m_color = back_vertices[0].m_color;
  back_vertices[2].m_color = back_vertices[0].m_color;
  back_vertices[3].m_color = back_vertices[0].m_color;
  back_vertices[0].m_position.x = pos.x;
  *(_QWORD *)&back_vertices[0].m_position.elements[1] = COERCE_UNSIGNED_INT(v6 + pos.y);
  back_vertices[0].m_position.w = 0.0;
  back_vertices[0].m_uv.x = 0.0;
  LODWORD(back_vertices[0].m_uv.y) = clear_value;
  *(vostok::math::float2 *)&back_vertices[1].m_position.x = pos;
  *(_QWORD *)&back_vertices[1].m_position.elements[2] = 0;
  back_vertices[1].m_uv = 0;
  back_vertices[2].m_position.x = v5 + pos.x;
  *(_QWORD *)&back_vertices[2].m_position.elements[1] = *(_QWORD *)&back_vertices[0].m_position.elements[1];
  back_vertices[2].m_position.w = 0.0;
  LODWORD(back_vertices[2].m_uv.x) = clear_value;
  LODWORD(back_vertices[2].m_uv.y) = clear_value;
  back_vertices[3].m_position.x = v5 + pos.x;
  *(_QWORD *)&back_vertices[3].m_position.elements[1] = LODWORD(pos.y);
  back_vertices[3].m_position.w = 0.0;
  back_vertices[3].m_uv = (vostok::math::float2)(unsigned int)clear_value;
  vostok::render::ui::renderer::draw_vertices(
    (vostok::render::ui::renderer *)back_vertices,
    scene_viewa,
    back_vertices,
    (const vostok::render::ui::vertex *)&retaddr,
    0,
    2u);
}
