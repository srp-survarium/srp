void __fastcall survarium::base_game_scene::apply_camera(
        int a1,
        survarium::camera_director *cd,
        survarium::base_game_scene *this)
{
  vostok::math::float4x4 *p_m_inverted_view_matrix; // eax

  p_m_inverted_view_matrix = &this->m_inverted_view_matrix;
  qmemcpy((void *)&this->m_inverted_view_matrix, &cd->m_inverted_view, sizeof(this->m_inverted_view_matrix));
  qmemcpy((void *)&this->m_projection_matrix, &cd->m_projection, sizeof(this->m_projection_matrix));
  invert_impl(
    p_m_inverted_view_matrix,
    (float)((float)((float)((float)(p_m_inverted_view_matrix->j.y * p_m_inverted_view_matrix->k.z)
                          - (float)(p_m_inverted_view_matrix->j.z * p_m_inverted_view_matrix->k.y))
                  * p_m_inverted_view_matrix->i.x)
          - (float)((float)((float)(p_m_inverted_view_matrix->j.x * p_m_inverted_view_matrix->k.z)
                          - (float)(p_m_inverted_view_matrix->k.x * p_m_inverted_view_matrix->j.z))
                  * p_m_inverted_view_matrix->i.y))
  + (float)((float)((float)(p_m_inverted_view_matrix->j.x * p_m_inverted_view_matrix->k.y)
                  - (float)(p_m_inverted_view_matrix->k.x * p_m_inverted_view_matrix->j.y))
          * p_m_inverted_view_matrix->i.z));
  vostok::render::scene_renderer::set_view_matrix(
    (vostok::render::scene_renderer *)this->m_game,
    (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)this->m_game->m_renderer->m_scene,
    (const vostok::math::float4x4 *)&this->m_render_scene_view);
  vostok::render::scene_renderer::set_projection_matrix(
    (vostok::render::scene_renderer *)this->m_game,
    (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)this->m_game->m_renderer->m_scene,
    (const vostok::math::float4x4 *)&this->m_render_scene_view);
}
