void __userpurge vostok::render::resource_manager::copy2D(
        unsigned int size_x@<eax>,
        unsigned int size_y@<edx>,
        vostok::render::resource_manager *this,
        vostok::render::res_texture *dest,
        unsigned int dest_x,
        unsigned int dest_y,
        vostok::render::res_texture *source,
        unsigned int src_x,
        unsigned int src_y,
        unsigned int dest_mip,
        unsigned int src_mip)
{
  vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record *M_data; // ecx
  int y; // eax
  ID3D11Resource *m_surface; // [esp-Ch] [ebp-30h]
  D3D11_BOX box; // [esp+8h] [ebp-1Ch] BYREF

  m_surface = dest->m_surface;
  memset((void *)&box, 0, 12);
  M_data = this->m_rs_cache.states._M_impl._M_end_of_storage._M_data;
  box.right = size_x;
  y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  box.bottom = size_y;
  box.back = 1;
  (*(void (__stdcall **)(int, vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record *, _DWORD, _DWORD, _DWORD, _DWORD, ID3D11Resource *, _DWORD, D3D11_BOX *))(*(_DWORD *)y + 184))(
    y,
    M_data,
    0,
    0,
    0,
    0,
    m_surface,
    0,
    &box);
}
