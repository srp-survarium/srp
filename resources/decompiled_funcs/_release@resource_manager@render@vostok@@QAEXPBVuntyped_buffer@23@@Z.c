void __userpurge vostok::render::resource_manager::release(
        vostok::render::res_state *buffer@<edi>,
        vostok::render::resource_manager *this)
{
  ID3D11Buffer *m_rasterizer_state; // eax
  vostok::render::grass_render_model *m_object; // esi

  if ( vostok::render::reclaim<vostok::render::untyped_buffer>(
         (vostok::render::vector<vostok::render::res_state *> *)&this->m_buffers,
         buffer) )
  {
    this->m_num_bytes_of_buffers_video_memory -= (unsigned int)buffer->m_depth_stencil_state;
    m_rasterizer_state = (ID3D11Buffer *)buffer->m_rasterizer_state;
    m_object = vostok::render::g_allocator.m_object;
    if ( m_rasterizer_state )
    {
      m_rasterizer_state->Release(buffer->m_rasterizer_state);
      buffer->m_rasterizer_state = 0;
    }
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free((void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), buffer);
  }
}
