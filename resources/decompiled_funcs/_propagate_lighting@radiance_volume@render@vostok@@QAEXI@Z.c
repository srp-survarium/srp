void __thiscall vostok::render::radiance_volume::propagate_lighting(
        vostok::render::radiance_volume *this,
        unsigned int cascade_index,
        unsigned int cascade_indexa)
{
  unsigned int v3; // ebp
  const char *m_conflicted_key_name; // ebx
  _DWORD *v5; // eax
  unsigned int v6; // ecx
  char v7; // al
  const char *v8; // ecx
  const char *v9; // esi
  char v10; // al
  const char *v11; // ecx
  vostok::render::backend *v12; // ecx
  int v13; // eax
  int v14; // esi
  int v15; // edx
  int v16; // eax
  char *v17; // ecx
  int v18; // eax
  int v19; // eax
  _DWORD *v20; // eax
  char *v21; // esi
  char v22; // al
  const char *v23; // ecx
  const char *v24; // esi
  char v25; // al
  const char *v26; // ecx
  const char *v27; // esi
  char v28; // al
  const char *v29; // ecx
  int v30; // eax
  const char *v31; // esi
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  int v35; // ecx
  int v36; // eax
  const char *v37; // esi
  int v38; // eax
  int v39; // eax
  _DWORD *v40; // eax
  unsigned int v41; // ecx
  int v42; // eax
  vostok::render::textures_handler<0> *v43; // ecx
  char v44; // al
  const char *v45; // ecx
  const char *v46; // esi
  char v47; // al
  const char *v48; // ecx
  const char *v49; // esi
  char v50; // al
  const char *v51; // ecx
  int v52; // eax
  int v53; // ecx
  int v54; // eax
  int v55; // ecx
  int v56; // eax
  int v57; // ecx
  int v58; // eax
  int v59; // ecx
  int v60; // eax
  int v61; // ecx
  const char *v62; // esi
  int v63; // eax
  survarium::game *m_game; // edx
  unsigned int v65; // [esp+0h] [ebp-14h]
  char src_ptr[4]; // [esp+10h] [ebp-4h] BYREF

  v3 = cascade_index;
  vostok::render::radiance_volume::begin_render_to_cells(this, cascade_index);
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  vostok::render::backend::set_render_targets(
    *(ID3D11RenderTargetView **)(v3 + 340),
    *(const vostok::render::render_target **)(v3 + 344),
    *(const vostok::render::render_target **)(v3 + 348),
    0,
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  v5 = *(_DWORD **)(v3 + 400);
  v6 = (v5[71] - v5[70]) >> 2;
  if ( v6 > 5 )
  {
    v5[69] = 5;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v6, v65);
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  }
  v7 = vostok::render::textures_handler<0>::set_overwrite(
         (vostok::render::textures_handler<0> *)v6,
         (char *)m_conflicted_key_name + 1488,
         (vostok::render::res_texture *)&stru_964DF4.m_desc.ArraySize,
         *(vostok::render::res_texture **)(v3 + 304));
  v8 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)m_conflicted_key_name + 159) = v7;
  v9 = v8;
  v10 = vostok::render::textures_handler<0>::set_overwrite(
          (vostok::render::textures_handler<0> *)(v8 + 1488),
          (char *)v8 + 1488,
          (vostok::render::res_texture *)&stru_964DF4.m_desc.Usage,
          *(vostok::render::res_texture **)(v3 + 308));
  v11 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v9 + 159) = v10;
  *((_BYTE *)v11 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                            (vostok::render::textures_handler<0> *)(v11 + 1488),
                            (char *)v11 + 1488,
                            (vostok::render::res_texture *)&stru_964DF4.m_desc_3d,
                            *(vostok::render::res_texture **)(v3 + 312));
  vostok::render::sliced_cube_geometry::draw((vostok::render::sliced_cube_geometry *)(v3 + 168));
  for ( cascade_index = 0; cascade_index < *(_DWORD *)(v3 + 264); ++cascade_index )
  {
    if ( (cascade_index & 1) != 0 )
    {
      v33 = *(_DWORD *)(v3 + 292);
      v34 = *(_DWORD *)(v3 + 300);
      v35 = *(_DWORD *)(v3 + 296);
      if ( v33 )
        v36 = *(_DWORD *)(v33 + 16);
      else
        v36 = 0;
      v37 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) != v36 )
      {
        *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = v36;
        *((_BYTE *)v37 + 163) = 1;
      }
      if ( v35 )
        v38 = *(_DWORD *)(v35 + 16);
      else
        v38 = 0;
      if ( *((_DWORD *)v37 + 536) != v38 )
      {
        *((_DWORD *)v37 + 536) = v38;
        *((_BYTE *)v37 + 164) = 1;
      }
      if ( v34 )
        v39 = *(_DWORD *)(v34 + 16);
      else
        v39 = 0;
      if ( *((_DWORD *)v37 + 537) != v39 )
      {
        *((_DWORD *)v37 + 537) = v39;
        *((_BYTE *)v37 + 165) = 1;
      }
      if ( *((_DWORD *)v37 + 538) )
      {
        *((_DWORD *)v37 + 538) = 0;
        *((_BYTE *)v37 + 166) = 1;
      }
      v40 = *(_DWORD **)(v3 + 400);
      v41 = (v40[71] - v40[70]) >> 2;
      if ( v41 > 4 )
      {
        v40[69] = 4;
        vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v41, v65);
        v37 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      }
      v42 = *(_DWORD *)(v3 + 408);
      *(float *)src_ptr = (float)*(unsigned int *)(v3 + 200);
      v43 = *(vostok::render::textures_handler<0> **)(v42 + 44);
      if ( v43 == *((vostok::render::textures_handler<0> **)v37 + 574) )
      {
        v43 = (vostok::render::textures_handler<0> *)*(unsigned __int16 *)(v42 + 28);
        if ( v43 != (vostok::render::textures_handler<0> *)0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v42 + 30),
            (unsigned __int8)*(_WORD *)(v42 + 24),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v37 + 211) + 16) + 4 * (_DWORD)v43),
            src_ptr);
      }
      ++*((_DWORD *)v37 + 23);
      v44 = vostok::render::textures_handler<0>::set_overwrite(
              v43,
              (char *)v37 + 1488,
              (vostok::render::res_texture *)&stru_964DF4.m_desc.ArraySize,
              *(vostok::render::res_texture **)(v3 + 352));
      v45 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)v37 + 159) = v44;
      v46 = v45;
      v47 = vostok::render::textures_handler<0>::set_overwrite(
              (vostok::render::textures_handler<0> *)(v45 + 1488),
              (char *)v45 + 1488,
              (vostok::render::res_texture *)&stru_964DF4.m_desc.Usage,
              *(vostok::render::res_texture **)(v3 + 356));
      v48 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)v46 + 159) = v47;
      v49 = v48;
      v50 = vostok::render::textures_handler<0>::set_overwrite(
              (vostok::render::textures_handler<0> *)(v48 + 1488),
              (char *)v48 + 1488,
              (vostok::render::res_texture *)&stru_964DF4.m_desc_3d,
              *(vostok::render::res_texture **)(v3 + 360));
      v51 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)v49 + 159) = v50;
      *((_BYTE *)v51 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                (vostok::render::textures_handler<0> *)(v51 + 1488),
                                (char *)v51 + 1488,
                                (vostok::render::res_texture *)&texture,
                                *(vostok::render::res_texture **)(v3 + 392));
      v52 = *(_DWORD *)(v3 + 424);
      *(float *)src_ptr = (float)*(unsigned int *)(v3 + 200);
      v31 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *(_DWORD *)(v52 + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                    + 573) )
      {
        v53 = *(unsigned __int16 *)(v52 + 20);
        if ( v53 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v52 + 22),
            (unsigned __int8)*(_WORD *)(v52 + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 371)
                                                                   + 16)
                                                       + 4 * v53),
            src_ptr);
      }
    }
    else
    {
      v13 = *(_DWORD *)(v3 + 364);
      v14 = *(_DWORD *)(v3 + 372);
      v15 = *(_DWORD *)(v3 + 368);
      if ( v13 )
        v16 = *(_DWORD *)(v13 + 16);
      else
        v16 = 0;
      v17 = (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) != v16 )
      {
        *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = v16;
        v17[163] = 1;
      }
      if ( v15 )
        v18 = *(_DWORD *)(v15 + 16);
      else
        v18 = 0;
      if ( *((_DWORD *)v17 + 536) != v18 )
      {
        *((_DWORD *)v17 + 536) = v18;
        v17[164] = 1;
      }
      if ( v14 )
        v19 = *(_DWORD *)(v14 + 16);
      else
        v19 = 0;
      if ( *((_DWORD *)v17 + 537) != v19 )
      {
        *((_DWORD *)v17 + 537) = v19;
        v17[165] = 1;
      }
      if ( *((_DWORD *)v17 + 538) )
      {
        *((_DWORD *)v17 + 538) = 0;
        v17[166] = 1;
      }
      v20 = *(_DWORD **)(v3 + 400);
      if ( (unsigned int)((v20[71] - v20[70]) >> 2) > 4 )
      {
        v20[69] = 4;
        vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v17, v65);
        v17 = (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      }
      v21 = v17;
      v22 = vostok::render::textures_handler<0>::set_overwrite(
              (vostok::render::textures_handler<0> *)(v17 + 1488),
              v17 + 1488,
              (vostok::render::res_texture *)&stru_964DF4.m_desc.ArraySize,
              *(vostok::render::res_texture **)(v3 + 304));
      v23 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v21[159] = v22;
      v24 = v23;
      v25 = vostok::render::textures_handler<0>::set_overwrite(
              (vostok::render::textures_handler<0> *)(v23 + 1488),
              (char *)v23 + 1488,
              (vostok::render::res_texture *)&stru_964DF4.m_desc.Usage,
              *(vostok::render::res_texture **)(v3 + 308));
      v26 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)v24 + 159) = v25;
      v27 = v26;
      v28 = vostok::render::textures_handler<0>::set_overwrite(
              (vostok::render::textures_handler<0> *)(v26 + 1488),
              (char *)v26 + 1488,
              (vostok::render::res_texture *)&stru_964DF4.m_desc_3d,
              *(vostok::render::res_texture **)(v3 + 312));
      v29 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)v27 + 159) = v28;
      *((_BYTE *)v29 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                (vostok::render::textures_handler<0> *)(v29 + 1488),
                                (char *)v29 + 1488,
                                (vostok::render::res_texture *)&texture,
                                *(vostok::render::res_texture **)(v3 + 392));
      v30 = *(_DWORD *)(v3 + 424);
      *(float *)src_ptr = (float)*(unsigned int *)(v3 + 200);
      v31 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *(_DWORD *)(v30 + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                    + 573) )
      {
        v32 = *(unsigned __int16 *)(v30 + 20);
        if ( v32 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v30 + 22),
            (unsigned __int8)*(_WORD *)(v30 + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 371)
                                                                   + 16)
                                                       + 4 * v32),
            src_ptr);
      }
    }
    ++*((_DWORD *)v31 + 23);
    v54 = *(_DWORD *)(v3 + 436);
    if ( *(_DWORD *)(v54 + 40) == *((_DWORD *)v31 + 573) )
    {
      v55 = *(unsigned __int16 *)(v54 + 20);
      if ( v55 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          *(unsigned __int16 *)(v54 + 22),
          (unsigned __int8)*(_WORD *)(v54 + 16),
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v31 + 371) + 16) + 4 * v55),
          (const char *)&cascade_index);
    }
    ++*((_DWORD *)v31 + 23);
    v56 = *(_DWORD *)(v3 + 444);
    if ( *(_DWORD *)(v56 + 40) == *((_DWORD *)v31 + 573) )
    {
      v57 = *(unsigned __int16 *)(v56 + 20);
      if ( v57 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          *(unsigned __int16 *)(v56 + 22),
          (unsigned __int8)*(_WORD *)(v56 + 16),
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v31 + 371) + 16) + 4 * v57),
          (const char *)(v3 + 196));
    }
    ++*((_DWORD *)v31 + 23);
    v58 = *(_DWORD *)(v3 + 452);
    if ( *(_DWORD *)(v58 + 40) == *((_DWORD *)v31 + 573) )
    {
      v59 = *(unsigned __int16 *)(v58 + 20);
      if ( v59 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          *(unsigned __int16 *)(v58 + 22),
          (unsigned __int8)*(_WORD *)(v58 + 16),
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v31 + 371) + 16) + 4 * v59),
          (const char *)&cascade_indexa);
    }
    ++*((_DWORD *)v31 + 23);
    v60 = *(_DWORD *)(v3 + 456);
    if ( *(_DWORD *)(v60 + 40) == *((_DWORD *)v31 + 573) )
    {
      v61 = *(unsigned __int16 *)(v60 + 20);
      if ( v61 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          *(unsigned __int16 *)(v60 + 22),
          (unsigned __int8)*(_WORD *)(v60 + 16),
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v31 + 371) + 16) + 4 * v61),
          (const char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
        + 28);
    }
    ++*((_DWORD *)v31 + 23);
    vostok::render::sliced_cube_geometry::draw((vostok::render::sliced_cube_geometry *)(v3 + 168));
  }
  v62 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  vostok::render::backend::reset_render_targets(
    v12,
    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  v63 = *((_DWORD *)v62 + 547);
  m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
  *((_BYTE *)v62 + 167) |= *((_DWORD *)v62 + 539) != v63;
  *((_DWORD *)v62 + 539) = v63;
  (*(void (__stdcall **)(int, int, unsigned int))(*(_DWORD *)m_game->m_game_world.m_mouse_pos.y + 176))(
    m_game->m_game_world.m_mouse_pos.y,
    1,
    v3 + 96);
}
