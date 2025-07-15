void __usercall vostok::render::backend::reset(vostok::render::backend *this@<ecx>, int a2@<esi>)
{
  bool v2; // zf
  bool v3; // dl
  int v4; // eax
  int v5; // eax
  const vostok::render::res_sampler_list *v6; // eax
  int v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // eax
  const vostok::render::res_texture_list *v10; // eax
  int v11; // eax
  const vostok::render::res_sampler_list *v12; // eax
  int v13; // ecx
  unsigned int v14; // eax
  unsigned int v15; // eax
  const vostok::render::res_texture_list *v16; // eax
  bool v17; // dl
  int v18; // eax
  const vostok::render::res_sampler_list *v19; // eax
  int v20; // ecx
  unsigned int v21; // eax
  unsigned int v22; // eax
  const vostok::render::res_texture_list *v23; // eax
  int v24; // edx
  bool v25; // al
  bool v26; // al
  int y; // eax
  survarium::game *m_game; // eax
  unsigned int v29; // [esp-10h] [ebp-3Ch]
  unsigned int v30; // [esp-10h] [ebp-3Ch]
  unsigned int v31; // [esp-10h] [ebp-3Ch]
  _QWORD v32[4]; // [esp+8h] [ebp-24h] BYREF

  *(_BYTE *)(a2 + 147) |= *(_DWORD *)(a2 + 132) != 0;
  v2 = *(_DWORD *)(a2 + 136) == -1;
  *(_DWORD *)(a2 + 132) = 0;
  *(_BYTE *)(a2 + 148) |= !v2;
  *(_DWORD *)(a2 + 136) = -1;
  if ( *(_DWORD *)(a2 + 2132) )
  {
    *(_DWORD *)(a2 + 2132) = 0;
    *(_BYTE *)(a2 + 144) = 1;
    *(_DWORD *)(a2 + 2136) = 0;
    *(_BYTE *)(a2 + 145) = 1;
  }
  else
  {
    *(_BYTE *)(a2 + 145) = 0;
  }
  v2 = *(_DWORD *)(a2 + 120) == 0;
  *(_DWORD *)(a2 + 120) = 0;
  *(_BYTE *)(a2 + 146) |= !v2;
  v2 = *(_DWORD *)(a2 + 124) == 0;
  *(_DWORD *)(a2 + 124) = 0;
  *(_BYTE *)(a2 + 147) |= !v2;
  v2 = *(_DWORD *)(a2 + 128) == 0;
  *(_DWORD *)(a2 + 128) = 0;
  *(_BYTE *)(a2 + 148) |= !v2;
  v2 = *(_DWORD *)(a2 + 184) == 0;
  *(_DWORD *)(a2 + 184) = 0;
  v3 = !v2;
  v2 = (!v2 | *(_BYTE *)(a2 + 149)) == 0;
  *(_BYTE *)(a2 + 149) |= v3;
  LOBYTE(this) = *(_BYTE *)(a2 + 149);
  if ( !v2 )
    ++*(_DWORD *)a2;
  if ( (_BYTE)this )
    v4 = 0;
  else
    v4 = *(_DWORD *)(a2 + 2136);
  *(_DWORD *)(a2 + 2136) = v4;
  *(_BYTE *)(a2 + 145) = (_BYTE)this;
  if ( *(_DWORD *)(a2 + 204) )
  {
    ++*(_DWORD *)(a2 + 12);
    vostok::render::constants_handler<0>::assign((vostok::render::constants_handler<0> *)(a2 + 196), 0);
    v5 = *(_DWORD *)(a2 + 2284);
    *(_BYTE *)(a2 + 150) = 1;
    *(_DWORD *)(a2 + 2288) = v5;
  }
  if ( *(_DWORD *)(a2 + 828) )
  {
    ++*(_DWORD *)(a2 + 20);
    *(_DWORD *)(a2 + 756) = 0;
    *(_DWORD *)(a2 + 760) = 0;
    v6 = *(const vostok::render::res_sampler_list **)(a2 + 828);
    *(_DWORD *)(a2 + 828) = 0;
    if ( v6 )
    {
      v2 = v6->m_reference_count-- == 1;
      if ( v2 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v6);
    }
    *(_BYTE *)(a2 + 152) = 1;
  }
  if ( *(_DWORD *)(a2 + 208) )
  {
    ++*(_DWORD *)(a2 + 16);
    v7 = *(_DWORD *)(a2 + 208);
    if ( v7 )
      v8 = (*(_DWORD *)(v7 + 8) - *(_DWORD *)(v7 + 4)) >> 2;
    else
      v8 = 0;
    v9 = vostok::math::max(v8, 0);
    v29 = *(_DWORD *)(a2 + 216);
    *(_DWORD *)(a2 + 212) = 0;
    *(_DWORD *)(a2 + 216) = vostok::math::max(v29, v9);
    v10 = *(const vostok::render::res_texture_list **)(a2 + 208);
    *(_DWORD *)(a2 + 208) = 0;
    if ( v10 )
    {
      v2 = v10->m_reference_count-- == 1;
      if ( v2 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v10);
    }
    *(_BYTE *)(a2 + 151) = 1;
  }
  v2 = *(_DWORD *)(a2 + 192) == 0;
  *(_DWORD *)(a2 + 192) = 0;
  *(_BYTE *)(a2 + 153) |= !v2;
  if ( *(_DWORD *)(a2 + 844) )
  {
    vostok::render::constants_handler<2>::assign((vostok::render::constants_handler<2> *)(a2 + 836), 0);
    v11 = *(_DWORD *)(a2 + 2284);
    *(_BYTE *)(a2 + 154) = 1;
    *(_DWORD *)(a2 + 2296) = v11;
  }
  if ( *(_DWORD *)(a2 + 1468) )
  {
    *(_DWORD *)(a2 + 1396) = 0;
    *(_DWORD *)(a2 + 1400) = 0;
    v12 = *(const vostok::render::res_sampler_list **)(a2 + 1468);
    *(_DWORD *)(a2 + 1468) = 0;
    if ( v12 )
    {
      v2 = v12->m_reference_count-- == 1;
      if ( v2 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v12);
    }
    *(_BYTE *)(a2 + 156) = 1;
  }
  if ( *(_DWORD *)(a2 + 848) )
  {
    v13 = *(_DWORD *)(a2 + 848);
    if ( v13 )
      v14 = (*(_DWORD *)(v13 + 8) - *(_DWORD *)(v13 + 4)) >> 2;
    else
      v14 = 0;
    v15 = vostok::math::max(v14, 0);
    v30 = *(_DWORD *)(a2 + 856);
    *(_DWORD *)(a2 + 852) = 0;
    *(_DWORD *)(a2 + 856) = vostok::math::max(v30, v15);
    v16 = *(const vostok::render::res_texture_list **)(a2 + 848);
    *(_DWORD *)(a2 + 848) = 0;
    if ( v16 )
    {
      v2 = v16->m_reference_count-- == 1;
      if ( v2 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v16);
    }
    *(_BYTE *)(a2 + 155) = 1;
  }
  v17 = *(_DWORD *)(a2 + 188) != 0;
  v2 = (v17 | *(_BYTE *)(a2 + 157)) == 0;
  *(_BYTE *)(a2 + 157) |= v17;
  if ( !v2 )
    ++*(_DWORD *)(a2 + 4);
  *(_DWORD *)(a2 + 188) = 0;
  if ( *(_DWORD *)(a2 + 1484) )
  {
    ++*(_DWORD *)(a2 + 24);
    vostok::render::constants_handler<1>::assign((vostok::render::constants_handler<1> *)(a2 + 1476), 0);
    v18 = *(_DWORD *)(a2 + 2284);
    *(_BYTE *)(a2 + 158) = 1;
    *(_DWORD *)(a2 + 2292) = v18;
  }
  if ( *(_DWORD *)(a2 + 2108) )
  {
    ++*(_DWORD *)(a2 + 32);
    *(_DWORD *)(a2 + 2036) = 0;
    *(_DWORD *)(a2 + 2040) = 0;
    v19 = *(const vostok::render::res_sampler_list **)(a2 + 2108);
    *(_DWORD *)(a2 + 2108) = 0;
    if ( v19 )
    {
      v2 = v19->m_reference_count-- == 1;
      if ( v2 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v19);
    }
    *(_BYTE *)(a2 + 160) = 1;
  }
  if ( *(_DWORD *)(a2 + 1488) )
  {
    ++*(_DWORD *)(a2 + 28);
    v20 = *(_DWORD *)(a2 + 1488);
    if ( v20 )
      v21 = (*(_DWORD *)(v20 + 8) - *(_DWORD *)(v20 + 4)) >> 2;
    else
      v21 = 0;
    v22 = vostok::math::max(v21, 0);
    v31 = *(_DWORD *)(a2 + 1496);
    *(_DWORD *)(a2 + 1492) = 0;
    *(_DWORD *)(a2 + 1496) = vostok::math::max(v31, v22);
    v23 = *(const vostok::render::res_texture_list **)(a2 + 1488);
    *(_DWORD *)(a2 + 1488) = 0;
    if ( v23 )
    {
      v2 = v23->m_reference_count-- == 1;
      if ( v2 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v23);
    }
    *(_BYTE *)(a2 + 159) = 1;
  }
  if ( *(_DWORD *)(a2 + 204) )
  {
    ++*(_DWORD *)(a2 + 12);
    vostok::render::constants_handler<0>::assign((vostok::render::constants_handler<0> *)(a2 + 196), 0);
    v24 = *(_DWORD *)(a2 + 2284);
    *(_BYTE *)(a2 + 150) = 1;
    *(_DWORD *)(a2 + 2288) = v24;
  }
  v25 = *(_DWORD *)(a2 + 168) || *(_DWORD *)(a2 + 2192) || *(_DWORD *)(a2 + 2196);
  *(_BYTE *)(a2 + 140) |= v25;
  *(_DWORD *)(a2 + 168) = 0;
  *(_DWORD *)(a2 + 2192) = 0;
  *(_DWORD *)(a2 + 2196) = 0;
  v26 = *(_DWORD *)(a2 + 180) || *(_DWORD *)(a2 + 2216);
  *(_BYTE *)(a2 + 143) |= v26;
  *(_DWORD *)(a2 + 180) = 0;
  *(_DWORD *)(a2 + 2216) = 0;
  if ( *(_DWORD *)(a2 + 2140) )
  {
    *(_DWORD *)(a2 + 2140) = 0;
    *(_BYTE *)(a2 + 163) = 1;
  }
  if ( *(_DWORD *)(a2 + 2144) )
  {
    *(_DWORD *)(a2 + 2144) = 0;
    *(_BYTE *)(a2 + 164) = 1;
  }
  if ( *(_DWORD *)(a2 + 2148) )
  {
    *(_DWORD *)(a2 + 2148) = 0;
    *(_BYTE *)(a2 + 165) = 1;
  }
  if ( *(_DWORD *)(a2 + 2152) )
  {
    *(_DWORD *)(a2 + 2152) = 0;
    *(_BYTE *)(a2 + 166) = 1;
  }
  *(_BYTE *)(a2 + 167) |= *(_DWORD *)(a2 + 2156) != 0;
  *(_DWORD *)(a2 + 2156) = 0;
  vostok::render::backend::flush_rt_shader_resources(this, (vostok::render::backend *)a2);
  y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  memset(v32, 0, sizeof(v32));
  (*(void (__stdcall **)(int, int, _QWORD *, _DWORD))(*(_DWORD *)y + 132))(y, 8, v32, 0);
  ++*(_DWORD *)(a2 + 2284);
  m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
  *(_DWORD *)(a2 + 2116) = 0;
  (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)m_game->m_game_world.m_mouse_pos.y + 96))(
    m_game->m_game_world.m_mouse_pos.y,
    0);
}
