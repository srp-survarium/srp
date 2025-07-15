void __thiscall vostok::render::res_state::apply(vostok::render::res_state *this)
{
  const char *m_conflicted_key_name; // eax
  ID3D11RasterizerState *m_rasterizer_state; // esi
  bool v3; // zf
  ID3D11DepthStencilState *m_depth_stencil_state; // esi
  ID3D11BlendState *m_blend_state; // esi
  unsigned int m_stencil_ref; // ecx

  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  m_rasterizer_state = this->m_rasterizer_state;
  v3 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 30) == (_DWORD)m_rasterizer_state;
  *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 30) = m_rasterizer_state;
  *((_BYTE *)m_conflicted_key_name + 146) |= !v3;
  m_depth_stencil_state = this->m_depth_stencil_state;
  v3 = *((_DWORD *)m_conflicted_key_name + 31) == (_DWORD)m_depth_stencil_state;
  *((_DWORD *)m_conflicted_key_name + 31) = m_depth_stencil_state;
  *((_BYTE *)m_conflicted_key_name + 147) |= !v3;
  m_blend_state = this->m_blend_state;
  v3 = *((_DWORD *)m_conflicted_key_name + 32) == (_DWORD)m_blend_state;
  *((_DWORD *)m_conflicted_key_name + 32) = m_blend_state;
  *((_BYTE *)m_conflicted_key_name + 148) |= !v3;
  m_stencil_ref = this->m_stencil_ref;
  v3 = *((_DWORD *)m_conflicted_key_name + 33) == m_stencil_ref;
  *((_DWORD *)m_conflicted_key_name + 33) = m_stencil_ref;
  *((_BYTE *)m_conflicted_key_name + 147) |= !v3;
}
