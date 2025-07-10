void __usercall vostok::render::backend::flush(vostok::render::backend *this@<ecx>, int a2@<edi>)
{
  int y; // eax
  int v3; // edx
  vostok::render::constants_handler<0> *v4; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  ID3D11Buffer *v11; // eax
  ID3D11Buffer *v12; // ecx
  ID3D11Buffer *v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  int v16; // eax
  int v17; // ecx
  vostok::render::constants_handler<0> *v18; // ecx
  vostok::render::constants_handler<0> *v19; // ecx
  vostok::render::constants_handler<0> *v20; // ecx
  int v21; // [esp+50h] [ebp-38h]
  ID3D11Buffer *buffer[2]; // [esp+64h] [ebp-24h] BYREF
  unsigned int offsets[2]; // [esp+6Ch] [ebp-1Ch] BYREF
  ID3D11Buffer *buffers[2]; // [esp+74h] [ebp-14h] BYREF
  const vostok::math::float4x4 *v25; // [esp+7Ch] [ebp-Ch]
  const vostok::math::float4x4 *v26; // [esp+80h] [ebp-8h]

  if ( *(_BYTE *)(a2 + 146) )
    (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                       + 172))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      *(_DWORD *)(a2 + 120));
  if ( *(_BYTE *)(a2 + 147) )
    (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                               + 144))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      *(_DWORD *)(a2 + 124),
      *(_DWORD *)(a2 + 132));
  if ( *(_BYTE *)(a2 + 148) )
  {
    y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
    v21 = *(_DWORD *)(a2 + 136);
    v3 = *(_DWORD *)(a2 + 128);
    buffers[0] = (ID3D11Buffer *)clear_value;
    buffers[1] = (ID3D11Buffer *)clear_value;
    v25 = clear_value;
    v26 = clear_value;
    (*(void (__stdcall **)(int, int, ID3D11Buffer **, int))(*(_DWORD *)y + 140))(y, v3, buffers, v21);
  }
  vostok::render::backend::flush_rt(this, a2);
  if ( *(_BYTE *)(a2 + 149) )
  {
    v5 = *(_DWORD *)(a2 + 184);
    if ( v5 )
      v6 = *(_DWORD *)(v5 + 8);
    else
      v6 = 0;
    (*(void (__stdcall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 44))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v6,
      0,
      0);
  }
  if ( *(_BYTE *)(a2 + 153) )
  {
    v7 = *(_DWORD *)(a2 + 192);
    if ( v7 )
      v8 = *(_DWORD *)(v7 + 8);
    else
      v8 = 0;
    (*(void (__stdcall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 92))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v8,
      0,
      0);
  }
  if ( *(_BYTE *)(a2 + 157) )
  {
    v9 = *(_DWORD *)(a2 + 188);
    if ( v9 )
      v10 = *(_DWORD *)(v9 + 8);
    else
      v10 = 0;
    (*(void (__stdcall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 36))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v10,
      0,
      0);
  }
  if ( *(_BYTE *)(a2 + 140) || *(_BYTE *)(a2 + 141) )
  {
    v11 = *(ID3D11Buffer **)(a2 + 168);
    if ( *(_BYTE *)(a2 + 141) )
    {
      if ( v11 )
        v12 = (ID3D11Buffer *)v11[1].lpVtbl;
      else
        v12 = 0;
      v13 = *(ID3D11Buffer **)(a2 + 172);
      if ( v13 )
        v13 = (ID3D11Buffer *)v13[1].lpVtbl;
      buffer[1] = *(ID3D11Buffer **)(a2 + 2200);
      buffers[1] = v13;
      offsets[0] = *(_DWORD *)(a2 + 2196);
      v14 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
      buffers[0] = v12;
      buffer[0] = *(ID3D11Buffer **)(a2 + 2192);
      offsets[1] = *(_DWORD *)(a2 + 2204);
      (*(void (__stdcall **)(int, _DWORD, int, ID3D11Buffer **, ID3D11Buffer **, unsigned int *))(*(_DWORD *)v14 + 72))(
        v14,
        0,
        2,
        buffers,
        buffer,
        offsets);
    }
    else
    {
      if ( v11 )
        v11 = (ID3D11Buffer *)v11[1].lpVtbl;
      buffer[0] = v11;
      (*(void (__stdcall **)(int, _DWORD, int, ID3D11Buffer **, int, int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                         + 72))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        0,
        1,
        buffer,
        a2 + 2192,
        a2 + 2196);
      if ( *(_BYTE *)(a2 + 142) )
      {
        v15 = *(_DWORD *)(a2 + 176);
        if ( v15 )
          v15 = *(_DWORD *)(v15 + 4);
        offsets[0] = v15;
        (*(void (__stdcall **)(int, int, int, unsigned int *, int, int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                       + 72))(
          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
          1,
          1,
          offsets,
          a2 + 2208,
          a2 + 2212);
      }
    }
  }
  if ( *(_BYTE *)(a2 + 143) )
  {
    v16 = *(_DWORD *)(a2 + 180);
    if ( v16 )
      v17 = *(_DWORD *)(v16 + 4);
    else
      v17 = 0;
    (*(void (__stdcall **)(int, int, int, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                 + 76))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v17,
      57,
      *(_DWORD *)(a2 + 2216));
  }
  vostok::render::constants_handler<0>::update_buffers(v4, a2 + 196);
  vostok::render::constants_handler<0>::update_buffers(v18, a2 + 836);
  vostok::render::constants_handler<0>::update_buffers(v19, a2 + 1476);
  if ( *(_BYTE *)(a2 + 150) )
    vostok::render::constants_handler<0>::apply(v20);
  if ( *(_BYTE *)(a2 + 151) )
    vostok::render::textures_handler<0>::apply((vostok::render::textures_handler<0> *)v20);
  if ( *(_BYTE *)(a2 + 152) )
    vostok::render::samplers_handler<0>::apply((vostok::render::samplers_handler<0> *)v20);
  if ( *(_BYTE *)(a2 + 154) )
    vostok::render::constants_handler<2>::apply((vostok::render::constants_handler<2> *)v20);
  if ( *(_BYTE *)(a2 + 155) )
    vostok::render::textures_handler<2>::apply((vostok::render::textures_handler<2> *)v20);
  if ( *(_BYTE *)(a2 + 156) )
    vostok::render::samplers_handler<2>::apply((vostok::render::samplers_handler<2> *)v20);
  if ( *(_BYTE *)(a2 + 158) )
    vostok::render::constants_handler<1>::apply((vostok::render::constants_handler<1> *)v20);
  if ( *(_BYTE *)(a2 + 159) )
    vostok::render::textures_handler<1>::apply((vostok::render::textures_handler<1> *)(a2 + 1488));
  if ( *(_BYTE *)(a2 + 160) )
    vostok::render::samplers_handler<1>::apply((vostok::render::samplers_handler<1> *)v20);
  if ( *(_BYTE *)(a2 + 162) )
    (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                       + 96))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      *(_DWORD *)(a2 + 2116));
  ++*(_DWORD *)(a2 + 2284);
  vostok::render::backend::update_input_layout((vostok::render::backend *)v20, a2);
  *(_QWORD *)(a2 + 140) = 0;
  *(_QWORD *)(a2 + 148) = 0;
  *(_DWORD *)(a2 + 156) = 0;
  *(_WORD *)(a2 + 160) = 0;
  *(_BYTE *)(a2 + 162) = 0;
}
