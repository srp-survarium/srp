char __userpurge vostok::render::hw_hiz_occlusion_manager::quary_and_get_results_if_ready@<al>(
        vostok::render::hw_hiz_occlusion_manager *this@<ecx>,
        _DWORD *a2@<edi>,
        unsigned int out_results,
        unsigned int in_num_results)
{
  unsigned __int8 *v4; // ebx
  int v5; // ebp
  int v6; // esi
  _BYTE *v7; // esi
  unsigned int v9; // ecx
  int v10; // edx
  unsigned int v11; // ecx
  unsigned int *v12; // [esp+0h] [ebp-Ch]
  bool v13; // [esp+4h] [ebp-8h]

  v4 = (unsigned __int8 *)out_results;
  v5 = 0;
  if ( in_num_results )
  {
    v6 = a2[68];
    if ( v6 )
    {
      out_results = 0;
      v7 = vostok::render::res_texture::map2D((vostok::render::res_texture *)this, v6, &out_results, 1, v12, v13);
      if ( !v7 )
        return 0;
      if ( a2[65] )
      {
        v9 = a2[64];
        while ( 1 )
        {
          v10 = 0;
          if ( v9 )
            break;
LABEL_10:
          v7 += out_results;
          if ( (unsigned int)++v5 >= a2[65] )
            goto LABEL_11;
        }
        while ( 1 )
        {
          v11 = v10 + v5 * v9;
          if ( v11 > in_num_results - 1 )
            break;
          v4[v11] = v7[v10];
          v9 = a2[64];
          if ( ++v10 >= v9 )
            goto LABEL_10;
        }
      }
LABEL_11:
      (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                 + 60))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        *(_DWORD *)(a2[68] + 420),
        0);
    }
  }
  return 1;
}
