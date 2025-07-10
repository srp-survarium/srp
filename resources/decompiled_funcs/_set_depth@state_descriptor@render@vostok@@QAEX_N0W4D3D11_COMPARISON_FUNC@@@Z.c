void __userpurge vostok::render::state_descriptor::set_depth(
        vostok::render::state_descriptor *this@<eax>,
        bool enable@<cl>,
        bool write_enable,
        D3D11_COMPARISON_FUNC cmp_func)
{
  this->m_depth_stencil_desc.DepthEnable = enable;
  this->m_depth_stencil_desc.DepthFunc = cmp_func;
  this->m_depth_stencil_desc_updated = 1;
  this->m_depth_stencil_desc.DepthWriteMask = write_enable;
}
