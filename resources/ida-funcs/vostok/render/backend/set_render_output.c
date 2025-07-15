void __usercall vostok::render::backend::set_render_output(
        vostok::render::backend *this@<esi>,
        const vostok::render::res_render_output *render_output@<eax>)
{
  const vostok::render::res_render_output *v2; // ecx
  vostok::render::res_render_output *m_object; // eax
  const vostok::render::res_render_output *v5; // eax
  ID3D11RenderTargetView *m_base_rt; // ecx
  ID3D11DepthStencilView *m_base_zb; // eax

  v2 = 0;
  if ( render_output )
  {
    ++render_output->m_reference_count;
    v2 = render_output;
  }
  m_object = (vostok::render::res_render_output *)this->m_render_output.m_object;
  this->m_render_output.m_object = v2;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        m_object);
  }
  v5 = this->m_render_output.m_object;
  if ( v5 )
    m_base_rt = v5->m_base_rt;
  else
    m_base_rt = 0;
  this->m_base_rt = m_base_rt;
  if ( v5 )
    m_base_zb = v5->m_base_zb;
  else
    m_base_zb = 0;
  this->m_base_zb = m_base_zb;
}
