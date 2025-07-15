void __userpurge vostok::render::stage_clouds::fill_cloud_texture(
        vostok::render::stage_clouds *this@<ecx>,
        _DWORD *a2@<edi>,
        unsigned int index)
{
  unsigned int v3; // ebx
  int v4; // esi
  unsigned __int8 *v5; // eax
  int v6; // edx
  int v7; // edx
  unsigned int v8; // [esp+0h] [ebp-8h]
  unsigned int *v9; // [esp+4h] [ebp-4h]

  v3 = index;
  v4 = a2[index + 4];
  index = 0;
  v5 = (unsigned __int8 *)vostok::render::res_texture::map3D((vostok::render::res_texture *)this, v4, &index, v8, v9);
  if ( v5 )
  {
    v6 = *(_DWORD *)(*(_DWORD *)(a2[1] + 12388) + 960);
    if ( v3 )
      v7 = *(_DWORD *)(v6 + 2396);
    else
      v7 = *(_DWORD *)(v6 + 2284);
    memcpy(v5, *(unsigned __int8 **)(v7 + 80), 4 * a2[60] * a2[61] * a2[62]);
  }
  (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                             + 60))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    *(_DWORD *)(a2[v3 + 4] + 420),
    0);
}
