void __userpurge vostok::render::state_descriptor::set_stencil_backface(
        vostok::render::state_descriptor *this@<eax>,
        D3D11_STENCIL_OP zfail@<edx>,
        D3D11_COMPARISON_FUNC func,
        D3D11_STENCIL_OP fail,
        D3D11_STENCIL_OP pass)
{
  this->m_depth_stencil_desc.BackFace.StencilDepthFailOp = zfail;
  this->m_depth_stencil_desc.BackFace.StencilPassOp = fail;
  this->m_depth_stencil_desc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
  this->m_depth_stencil_desc.BackFace.StencilFunc = func;
  this->m_depth_stencil_desc_updated = 1;
}
