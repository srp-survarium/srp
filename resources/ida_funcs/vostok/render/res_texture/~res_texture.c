void __thiscall vostok::render::res_texture::~res_texture(vostok::render::res_texture *this)
{
  ID3D11Resource *m_surface; // eax
  ID3D11ShaderResourceView *m_sh_res_view; // eax

  this->__vftable = (vostok::render::res_texture_vtbl *)&vostok::render::res_texture::`vftable';
  m_surface = this->m_surface;
  if ( m_surface )
  {
    m_surface->Release(m_surface);
    this->m_surface = 0;
  }
  m_sh_res_view = this->m_sh_res_view;
  if ( m_sh_res_view )
  {
    m_sh_res_view->Release(this->m_sh_res_view);
    this->m_sh_res_view = 0;
  }
}
