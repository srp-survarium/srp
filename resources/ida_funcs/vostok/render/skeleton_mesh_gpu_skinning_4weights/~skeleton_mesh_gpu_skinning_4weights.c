void __thiscall vostok::render::skeleton_mesh_gpu_skinning_4weights::~skeleton_mesh_gpu_skinning_4weights(
        vostok::render::skeleton_mesh_gpu_skinning_4weights *this)
{
  vostok::render::untyped_buffer *m_object; // eax

  this->__vftable = (vostok::render::skeleton_mesh_gpu_skinning_4weights_vtbl *)&stru_966A14.m_mem_usage;
  m_object = this->m_vertex_buffer.m_object;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)this->m_vertex_buffer.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  vostok::render::render_surface::~render_surface(this);
}
