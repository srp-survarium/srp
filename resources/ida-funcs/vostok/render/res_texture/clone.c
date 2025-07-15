void __thiscall vostok::render::res_texture::clone(
        vostok::render::res_texture *this,
        vostok::render::res_texture *other,
        int a3)
{
  ID3D11Resource *m_surface; // eax
  ID3D11ShaderResourceView *m_sh_res_view; // eax
  ID3D11Resource *v5; // eax
  ID3D11ShaderResourceView *v6; // ebx

  m_surface = other->m_surface;
  if ( m_surface )
  {
    m_surface->Release(other->m_surface);
    other->m_surface = 0;
  }
  m_sh_res_view = other->m_sh_res_view;
  if ( m_sh_res_view )
  {
    m_sh_res_view->Release(other->m_sh_res_view);
    other->m_sh_res_view = 0;
  }
  other->m_loaded = *(_BYTE *)(a3 + 8);
  other->m_mem_usage = *(_DWORD *)(a3 + 64);
  other->m_surface = *(ID3D11Resource **)(a3 + 440);
  other->m_desc_cache_surface = *(ID3D11Resource **)(a3 + 444);
  other->m_sh_res_view = *(ID3D11ShaderResourceView **)(a3 + 448);
  qmemcpy(&other->m_desc, (const void *)(a3 + 84), sizeof(other->m_desc));
  other->m_mip_level_cut = *(_DWORD *)(a3 + 452);
  other->m_desc_valid = *(_BYTE *)(a3 + 456);
  other->m_pool_texture = *(_BYTE *)(a3 + 458);
  v5 = other->m_surface;
  if ( v5 )
    v5->AddRef(other->m_surface);
  v6 = other->m_sh_res_view;
  if ( v6 )
    v6->AddRef(v6);
}
