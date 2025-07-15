void __usercall vostok::render::res_texture::clone(
        vostok::render::res_texture *this@<eax>,
        vostok::render::res_texture *other@<edi>)
{
  ID3D11Resource *m_surface; // eax
  ID3D11ShaderResourceView *m_sh_res_view; // eax
  int v5; // ecx
  ID3D11Resource *v6; // eax
  ID3D11ShaderResourceView *v7; // esi

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
  v5 = *((_DWORD *)this + 12);
  this->m_loaded = other->m_loaded;
  *((_DWORD *)this + 12) ^= (*((_DWORD *)other + 12) ^ v5) & 1;
  *((_DWORD *)this + 12) ^= ((unsigned __int8)*((_DWORD *)this + 12) ^ (unsigned __int8)*((_DWORD *)other + 12)) & 2;
  this->m_mem_usage = other->m_mem_usage;
  this->m_bind = other->m_bind;
  this->m_surface = other->m_surface;
  this->m_desc_cache_surface = other->m_desc_cache_surface;
  this->m_sh_res_view = other->m_sh_res_view;
  this->m_desc = other->m_desc;
  this->m_mip_level_cut = other->m_mip_level_cut;
  this->m_desc_valid = other->m_desc_valid;
  this->m_pool_texture = other->m_pool_texture;
  v6 = this->m_surface;
  if ( v6 )
    v6->AddRef(this->m_surface);
  v7 = this->m_sh_res_view;
  if ( v7 )
    v7->AddRef(v7);
}
