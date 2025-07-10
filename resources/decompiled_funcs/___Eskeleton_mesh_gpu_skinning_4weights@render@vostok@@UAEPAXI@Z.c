vostok::render::skeleton_mesh_gpu_skinning_4weights *__thiscall vostok::render::skeleton_mesh_gpu_skinning_4weights::`vector deleting destructor'(
        vostok::render::skeleton_mesh_gpu_skinning_4weights *this,
        char a2)
{
  vostok::render::untyped_buffer *m_object; // eax

  this->__vftable = (vostok::render::skeleton_mesh_gpu_skinning_4weights_vtbl *)&stru_966A14.m_mem_usage;
  m_object = this->m_vertex_buffer.m_object;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        this->m_vertex_buffer.m_object);
  }
  vostok::render::render_surface::~render_surface(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
