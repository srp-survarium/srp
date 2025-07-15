void __thiscall survarium::camera_director::apply(survarium::camera_director *this, survarium::camera_director *a2)
{
  survarium::game_camera *m_active_camera; // eax
  vostok::math::float4x4 *p_m_inverted_view_matrix; // esi
  survarium::base_game_scene *m_game_scene; // eax
  vostok::math::float2 v5; // [esp+10h] [ebp-48h] BYREF
  vostok::math::float4x4 v6; // [esp+18h] [ebp-40h] BYREF

  m_active_camera = a2->m_active_camera;
  if ( m_active_camera )
  {
    p_m_inverted_view_matrix = &m_active_camera->m_inverted_view_matrix;
    m_game_scene = a2->m_game_scene;
    qmemcpy(&a2->m_inverted_view, p_m_inverted_view_matrix, sizeof(a2->m_inverted_view));
    m_game_scene->m_game->m_engine->get_render_window_size(m_game_scene->m_game->m_engine, &v5);
    if ( COERCE_FLOAT(LODWORD(v5.x) & 0x7FFFFFFF) >= 0.0000099999997 )
      qmemcpy(
        &a2->m_projection,
        a2->m_active_camera->get_projection_matrix(a2->m_active_camera, &v6, &v5),
        sizeof(a2->m_projection));
  }
  survarium::base_game_scene::apply_camera(a2, a2->m_game_scene);
}
