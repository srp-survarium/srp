void __thiscall vostok::render::res_texture::~res_texture(vostok::render::res_texture *this)
{
  ID3D11Resource **p_m_surface; // edi
  ID3D11Resource *m_surface; // eax
  ID3D11ShaderResourceView **p_m_sh_res_view; // esi

  p_m_surface = &this->m_surface;
  this->__vftable = (vostok::render::res_texture_vtbl *)&vostok::render::res_texture::`vftable';
  m_surface = this->m_surface;
  if ( m_surface )
  {
    m_surface->Release(m_surface);
    *p_m_surface = 0;
  }
  p_m_sh_res_view = &this->m_sh_res_view;
  if ( *p_m_sh_res_view )
  {
    (*p_m_sh_res_view)->Release(*p_m_sh_res_view);
    *p_m_sh_res_view = 0;
  }
}
