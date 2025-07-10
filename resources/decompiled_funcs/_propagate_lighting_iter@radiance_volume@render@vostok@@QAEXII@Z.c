void __thiscall vostok::render::radiance_volume::propagate_lighting_iter(
        vostok::render::radiance_volume *this,
        float cascade_index,
        unsigned int iteration_index,
        unsigned int iteration_indexa)
{
  float v4; // ebp
  const char *m_conflicted_key_name; // ebx
  _DWORD *v6; // eax
  unsigned int v7; // ecx
  char v8; // al
  const char *v9; // ecx
  const char *v10; // esi
  char v11; // al
  const char *v12; // ecx
  const char *v13; // ebx
  _DWORD *v14; // eax
  unsigned int v15; // ecx
  char v16; // al
  const char *v17; // ecx
  const char *v18; // esi
  char v19; // al
  const char *v20; // ecx
  const char *v21; // esi
  char v22; // al
  const char *v23; // ecx
  int v24; // eax
  vostok::render::constants_handler<1> *v25; // esi
  int v26; // ecx
  int v27; // eax
  int v28; // ecx
  int v29; // eax
  int v30; // ecx
  _DWORD *v31; // eax
  unsigned int v32; // ecx
  int v33; // eax
  vostok::render::textures_handler<0> *v34; // ecx
  char v35; // al
  const char *v36; // ecx
  const char *v37; // esi
  char v38; // al
  const char *v39; // ecx
  const char *v40; // esi
  char v41; // al
  const char *v42; // ecx
  int v43; // eax
  int v44; // ecx
  int v45; // eax
  int v46; // ecx
  int v47; // eax
  int v48; // ecx
  survarium::game_action_id *M_start; // edx
  vostok::render::radiance_volume *v50; // ecx
  unsigned int v51; // [esp+0h] [ebp-10h]

  v4 = cascade_index;
  vostok::render::radiance_volume::begin_render_to_cells(this, SLODWORD(cascade_index));
  if ( !iteration_indexa )
  {
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    vostok::render::backend::set_render_targets(
      *(ID3D11RenderTargetView **)(LODWORD(v4) + 340),
      *(const vostok::render::render_target **)(LODWORD(v4) + 344),
      *(const vostok::render::render_target **)(LODWORD(v4) + 348),
      0,
      (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
    v6 = *(_DWORD **)(LODWORD(v4) + 400);
    v7 = (v6[71] - v6[70]) >> 2;
    if ( v7 > 5 )
    {
      v6[69] = 5;
      vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v7, v51);
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    }
    v8 = vostok::render::textures_handler<0>::set_overwrite(
           (vostok::render::textures_handler<0> *)v7,
           (char *)m_conflicted_key_name + 1488,
           (vostok::render::res_texture *)&stru_964DF4.m_desc.ArraySize,
           *(vostok::render::res_texture **)(LODWORD(v4) + 304));
    v9 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    *((_BYTE *)m_conflicted_key_name + 159) = v8;
    v10 = v9;
    v11 = vostok::render::textures_handler<0>::set_overwrite(
            (vostok::render::textures_handler<0> *)(v9 + 1488),
            (char *)v9 + 1488,
            (vostok::render::res_texture *)&stru_964DF4.m_desc.Usage,
            *(vostok::render::res_texture **)(LODWORD(v4) + 308));
    v12 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    *((_BYTE *)v10 + 159) = v11;
    *((_BYTE *)v12 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                              (vostok::render::textures_handler<0> *)(v12 + 1488),
                              (char *)v12 + 1488,
                              (vostok::render::res_texture *)&stru_964DF4.m_desc_3d,
                              *(vostok::render::res_texture **)(LODWORD(v4) + 312));
    vostok::render::sliced_cube_geometry::draw((vostok::render::sliced_cube_geometry *)(LODWORD(v4) + 168));
  }
  v13 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( (iteration_indexa & 1) != 0 )
  {
    vostok::render::backend::set_render_targets(
      *(ID3D11RenderTargetView **)(LODWORD(v4) + 292),
      *(const vostok::render::render_target **)(LODWORD(v4) + 296),
      *(const vostok::render::render_target **)(LODWORD(v4) + 300),
      0,
      (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
    v31 = *(_DWORD **)(LODWORD(v4) + 400);
    v32 = (v31[71] - v31[70]) >> 2;
    if ( v32 > 4 )
    {
      v31[69] = 4;
      vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v32, v51);
      v13 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    }
    v33 = *(_DWORD *)(LODWORD(v4) + 408);
    cascade_index = (float)*(unsigned int *)(LODWORD(v4) + 200);
    v34 = *(vostok::render::textures_handler<0> **)(v33 + 44);
    if ( v34 == *((vostok::render::textures_handler<0> **)v13 + 574) )
    {
      v34 = (vostok::render::textures_handler<0> *)*(unsigned __int16 *)(v33 + 28);
      if ( v34 != (vostok::render::textures_handler<0> *)0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          *(unsigned __int16 *)(v33 + 30),
          (unsigned __int8)*(_WORD *)(v33 + 24),
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v13 + 211) + 16) + 4 * (_DWORD)v34),
          (const char *)&cascade_index);
    }
    ++*((_DWORD *)v13 + 23);
    v35 = vostok::render::textures_handler<0>::set_overwrite(
            v34,
            (char *)v13 + 1488,
            (vostok::render::res_texture *)&stru_964DF4.m_desc.ArraySize,
            *(vostok::render::res_texture **)(LODWORD(v4) + 352));
    v36 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    *((_BYTE *)v13 + 159) = v35;
    v37 = v36;
    v38 = vostok::render::textures_handler<0>::set_overwrite(
            (vostok::render::textures_handler<0> *)(v36 + 1488),
            (char *)v36 + 1488,
            (vostok::render::res_texture *)&stru_964DF4.m_desc.Usage,
            *(vostok::render::res_texture **)(LODWORD(v4) + 356));
    v39 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    *((_BYTE *)v37 + 159) = v38;
    v40 = v39;
    v41 = vostok::render::textures_handler<0>::set_overwrite(
            (vostok::render::textures_handler<0> *)(v39 + 1488),
            (char *)v39 + 1488,
            (vostok::render::res_texture *)&stru_964DF4.m_desc_3d,
            *(vostok::render::res_texture **)(LODWORD(v4) + 360));
    v42 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    *((_BYTE *)v40 + 159) = v41;
    *((_BYTE *)v42 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                              (vostok::render::textures_handler<0> *)(v42 + 1488),
                              (char *)v42 + 1488,
                              (vostok::render::res_texture *)&texture,
                              *(vostok::render::res_texture **)(LODWORD(v4) + 392));
    v43 = *(_DWORD *)(LODWORD(v4) + 424);
    cascade_index = (float)*(unsigned int *)(LODWORD(v4) + 200);
    v25 = (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    if ( *(_DWORD *)(v43 + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                  + 573) )
    {
      v44 = *(unsigned __int16 *)(v43 + 20);
      if ( v44 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          *(unsigned __int16 *)(v43 + 22),
          (unsigned __int8)*(_WORD *)(v43 + 16),
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                   + 371)
                                                                 + 16)
                                                     + 4 * v44),
          (const char *)&cascade_index);
    }
    ++v25[7].m_current.m_object;
    v45 = *(_DWORD *)(LODWORD(v4) + 436);
    if ( *(_DWORD *)(v45 + 40) == v25[191].m_diff_range_start )
    {
      v46 = *(unsigned __int16 *)(v45 + 20);
      if ( v46 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          *(unsigned __int16 *)(v45 + 22),
          (unsigned __int8)*(_WORD *)(v45 + 16),
          v25[123].m_current.m_object->m_const_buffers._M_impl._M_start[v46].m_object,
          (const char *)&iteration_indexa);
    }
    ++v25[7].m_current.m_object;
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      *(const vostok::render::shader_constant_host **)(LODWORD(v4) + 444),
      v25 + 123,
      (const vostok::math::float3 *)(LODWORD(v4) + 196));
    ++v25[7].m_current.m_object;
    v47 = *(_DWORD *)(LODWORD(v4) + 452);
    if ( *(_DWORD *)(v47 + 40) == v25[191].m_diff_range_start )
    {
      v48 = *(unsigned __int16 *)(v47 + 20);
      if ( v48 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          *(unsigned __int16 *)(v47 + 22),
          (unsigned __int8)*(_WORD *)(v47 + 16),
          v25[123].m_current.m_object->m_const_buffers._M_impl._M_start[v48].m_object,
          (const char *)&iteration_index);
    }
  }
  else
  {
    vostok::render::backend::set_render_targets(
      *(ID3D11RenderTargetView **)(LODWORD(v4) + 364),
      *(const vostok::render::render_target **)(LODWORD(v4) + 368),
      *(const vostok::render::render_target **)(LODWORD(v4) + 372),
      0,
      (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
    v14 = *(_DWORD **)(LODWORD(v4) + 400);
    v15 = (v14[71] - v14[70]) >> 2;
    if ( v15 > 4 )
    {
      v14[69] = 4;
      vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v15, v51);
      v13 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    }
    v16 = vostok::render::textures_handler<0>::set_overwrite(
            (vostok::render::textures_handler<0> *)v15,
            (char *)v13 + 1488,
            (vostok::render::res_texture *)&stru_964DF4.m_desc.ArraySize,
            *(vostok::render::res_texture **)(LODWORD(v4) + 304));
    v17 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    *((_BYTE *)v13 + 159) = v16;
    v18 = v17;
    v19 = vostok::render::textures_handler<0>::set_overwrite(
            (vostok::render::textures_handler<0> *)(v17 + 1488),
            (char *)v17 + 1488,
            (vostok::render::res_texture *)&stru_964DF4.m_desc.Usage,
            *(vostok::render::res_texture **)(LODWORD(v4) + 308));
    v20 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    *((_BYTE *)v18 + 159) = v19;
    v21 = v20;
    v22 = vostok::render::textures_handler<0>::set_overwrite(
            (vostok::render::textures_handler<0> *)(v20 + 1488),
            (char *)v20 + 1488,
            (vostok::render::res_texture *)&stru_964DF4.m_desc_3d,
            *(vostok::render::res_texture **)(LODWORD(v4) + 312));
    v23 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    *((_BYTE *)v21 + 159) = v22;
    *((_BYTE *)v23 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                              (vostok::render::textures_handler<0> *)(v23 + 1488),
                              (char *)v23 + 1488,
                              (vostok::render::res_texture *)&texture,
                              *(vostok::render::res_texture **)(LODWORD(v4) + 392));
    v24 = *(_DWORD *)(LODWORD(v4) + 424);
    cascade_index = (float)*(unsigned int *)(LODWORD(v4) + 200);
    v25 = (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    if ( *(_DWORD *)(v24 + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                  + 573) )
    {
      v26 = *(unsigned __int16 *)(v24 + 20);
      if ( v26 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          *(unsigned __int16 *)(v24 + 22),
          (unsigned __int8)*(_WORD *)(v24 + 16),
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                   + 371)
                                                                 + 16)
                                                     + 4 * v26),
          (const char *)&cascade_index);
    }
    ++v25[7].m_current.m_object;
    v27 = *(_DWORD *)(LODWORD(v4) + 436);
    if ( *(_DWORD *)(v27 + 40) == v25[191].m_diff_range_start )
    {
      v28 = *(unsigned __int16 *)(v27 + 20);
      if ( v28 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          *(unsigned __int16 *)(v27 + 22),
          (unsigned __int8)*(_WORD *)(v27 + 16),
          v25[123].m_current.m_object->m_const_buffers._M_impl._M_start[v28].m_object,
          (const char *)&iteration_indexa);
    }
    ++v25[7].m_current.m_object;
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      *(const vostok::render::shader_constant_host **)(LODWORD(v4) + 444),
      v25 + 123,
      (const vostok::math::float3 *)(LODWORD(v4) + 196));
    ++v25[7].m_current.m_object;
    v29 = *(_DWORD *)(LODWORD(v4) + 452);
    if ( *(_DWORD *)(v29 + 40) == v25[191].m_diff_range_start )
    {
      v30 = *(unsigned __int16 *)(v29 + 20);
      if ( v30 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          *(unsigned __int16 *)(v29 + 22),
          (unsigned __int8)*(_WORD *)(v29 + 16),
          v25[123].m_current.m_object->m_const_buffers._M_impl._M_start[v30].m_object,
          (const char *)&iteration_index);
    }
  }
  M_start = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
  ++v25[7].m_current.m_object;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    *(const vostok::render::shader_constant_host **)(LODWORD(v4) + 456),
    v25 + 123,
    (const vostok::math::float3 *)(M_start + 7));
  ++v25[7].m_current.m_object;
  vostok::render::sliced_cube_geometry::draw((vostok::render::sliced_cube_geometry *)(LODWORD(v4) + 168));
  vostok::render::radiance_volume::end_render_to_cells(v50, (vostok::render::radiance_volume *)LODWORD(v4));
}
