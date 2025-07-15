void __userpurge vostok::render::resource_manager::copy(
        vostok::render::untyped_buffer *source@<edx>,
        vostok::render::resource_manager *this,
        vostok::render::untyped_buffer *dest)
{
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->CopyResource(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    (ID3D11Resource *)this->sl_created,
    source->m_hardware_buffer);
}
