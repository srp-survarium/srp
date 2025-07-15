void __thiscall survarium::camera_director::apply(survarium::camera_director *this, survarium::camera_director *thisa)
{
  survarium::game_camera *m_active_camera; // eax
  vostok::math::float4x4 *p_m_inverted_view_matrix; // esi
  survarium::base_game_scene *m_game_scene; // eax
  vostok::math::float2 window_size; // [esp+10h] [ebp-48h] BYREF
  vostok::math::float4x4 v6; // [esp+18h] [ebp-40h] BYREF

  m_active_camera = thisa->m_active_camera;
  if ( m_active_camera )
  {
    p_m_inverted_view_matrix = &m_active_camera->m_inverted_view_matrix;
    m_game_scene = thisa->m_game_scene;
    qmemcpy((void *)&thisa->m_inverted_view, p_m_inverted_view_matrix, sizeof(thisa->m_inverted_view));
    m_game_scene->m_game->m_engine->get_render_window_size(m_game_scene->m_game->m_engine, &window_size);
    qmemcpy(
      (void *)&thisa->m_projection,
      thisa->m_active_camera->get_projection_matrix(thisa->m_active_camera, &v6, &window_size),
      sizeof(thisa->m_projection));
  }
  survarium::base_game_scene::apply_camera(thisa->m_game_scene, thisa);
}
