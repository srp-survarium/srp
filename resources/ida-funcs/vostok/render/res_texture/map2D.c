void *__userpurge vostok::render::res_texture::map2D@<eax>(
        vostok::render::res_texture *this@<ecx>,
        int a2@<esi>,
        unsigned int *mode,
        bool mip_level,
        unsigned int *row_pitch,
        bool dot_not_wait)
{
  D3D11_RESOURCE_DIMENSION type; // [esp+1Ch] [ebp-10h] BYREF
  D3D11_MAPPED_SUBRESOURCE mapped_res; // [esp+20h] [ebp-Ch] BYREF

  if ( !*(_DWORD *)(a2 + 420) )
    return 0;
  if ( !*(_BYTE *)(a2 + 436) )
    return 0;
  (*(void (__stdcall **)(_DWORD, D3D11_RESOURCE_DIMENSION *))(**(_DWORD **)(a2 + 420) + 28))(
    *(_DWORD *)(a2 + 420),
    &type);
  if ( type != D3D11_RESOURCE_DIMENSION_TEXTURE2D )
    return 0;
  (*(void (__stdcall **)(int, _DWORD, _DWORD, int, char *, D3D11_MAPPED_SUBRESOURCE *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                                      + 56))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    *(_DWORD *)(a2 + 420),
    0,
    1,
    mip_level ? (char *)&loc_FFFFF + 1 : 0,
    &mapped_res);
  *mode = mapped_res.RowPitch;
  return mapped_res.pData;
}
