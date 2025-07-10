void __userpurge vostok::render::hw_hiz_occlusion_manager::process_culling(
        vostok::render::hw_hiz_occlusion_manager *this@<eax>,
        unsigned int in_num_bounds_and_results@<edi>,
        vostok::render::hw_hiz_occlusion_manager *a3@<ecx>,
        vostok::render::renderer_context *in_context,
        vostok::render::hw_hiz_point_list *in_bounds)
{
  vostok::render::hw_hiz_occlusion_manager *v6; // ecx

  if ( in_num_bounds_and_results && this->m_hiz_occlusion_effect.m_object )
  {
    *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 104) = 0;
    if ( this->m_use_scene_depth_buffer )
      vostok::render::hw_hiz_occlusion_manager::copy_scene_depth(a3, (int)this);
    else
      vostok::render::hw_hiz_occlusion_manager::render_occluders(a3, this, in_context);
    vostok::render::hw_hiz_occlusion_manager::downsample_occlusion_buffer(v6, this);
    vostok::render::hw_hiz_occlusion_manager::render_model_bounds(
      this,
      in_num_bounds_and_results,
      (bool)in_context,
      (unsigned int)this,
      in_context,
      in_bounds);
    (*(void (__stdcall **)(int, ID3D11Resource *, ID3D11Resource *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                   + 188))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      this->m_t_culling_result_lockable.m_object->m_surface,
      this->m_t_culling_result.m_object->m_surface);
    *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 104) = 1;
  }
}
