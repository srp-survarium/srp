void __userpurge vostok::render::radiance_volume::inject_occluder_geometry(
        vostok::render::radiance_volume *this@<ecx>,
        int a2@<eax>,
        vostok::render::renderer_context *context,
        const vostok::math::float3 *light_position,
        const vostok::math::float3 *light_direction,
        const vostok::render::vector<vostok::math::float4x4> *transforms)
{
  int v7; // eax
  vostok::render::radiance_volume *v8; // ecx
  const char *m_conflicted_key_name; // eax
  vostok::render::res_effect *v10; // ecx
  _DWORD *v11; // eax
  int v12; // eax
  int v13; // ecx
  const char *v14; // edi
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  vostok::render::backend *v18; // ecx
  vostok::math::float4x4 *M_start; // ebp
  vostok::math::float4x4 *M_finish; // ebx
  vostok::render::box_geometry *v21; // ecx
  int v22; // eax
  survarium::game *m_game; // edx
  unsigned int v24; // [esp+0h] [ebp-2Ch]
  char v25[4]; // [esp+14h] [ebp-18h] BYREF
  char src_ptr[4]; // [esp+18h] [ebp-14h] BYREF
  int v27; // [esp+1Ch] [ebp-10h]
  int v28; // [esp+20h] [ebp-Ch]
  float v29; // [esp+24h] [ebp-8h]

  if ( (((char *)transforms->_M_impl._M_finish - (char *)transforms->_M_impl._M_start) & 0xFFFFFFC0) != 0 )
  {
    v7 = *(_DWORD *)(a2 + 388);
    if ( v7 )
      v8 = *(vostok::render::radiance_volume **)(v7 + 16);
    else
      v8 = 0;
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    if ( *((vostok::render::radiance_volume **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
         + 535) != v8 )
    {
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = v8;
      *((_BYTE *)m_conflicted_key_name + 163) = 1;
    }
    if ( *((_DWORD *)m_conflicted_key_name + 536) )
    {
      *((_DWORD *)m_conflicted_key_name + 536) = 0;
      *((_BYTE *)m_conflicted_key_name + 164) = 1;
    }
    if ( *((_DWORD *)m_conflicted_key_name + 537) )
    {
      *((_DWORD *)m_conflicted_key_name + 537) = 0;
      *((_BYTE *)m_conflicted_key_name + 165) = 1;
    }
    if ( *((_DWORD *)m_conflicted_key_name + 538) )
    {
      *((_DWORD *)m_conflicted_key_name + 538) = 0;
      *((_BYTE *)m_conflicted_key_name + 166) = 1;
    }
    vostok::render::radiance_volume::begin_render_to_cells(v8, a2);
    v11 = *(_DWORD **)(a2 + 400);
    if ( (unsigned int)((v11[71] - v11[70]) >> 2) > 3 )
    {
      v11[69] = 3;
      vostok::render::res_effect::apply_pass(v10, v24);
    }
    v12 = *(_DWORD *)(a2 + 416);
    v13 = *(_DWORD *)(v12 + 36);
    v14 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    *(_DWORD *)src_ptr = *(_DWORD *)(a2 + 204);
    v27 = *(_DWORD *)(a2 + 208);
    v28 = *(_DWORD *)(a2 + 212);
    v29 = *(float *)&clear_value / *(float *)(a2 + 192);
    if ( v13 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                + 572) )
    {
      v15 = *(unsigned __int16 *)(v12 + 12);
      if ( v15 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          *(unsigned __int16 *)(v12 + 14),
          (unsigned __int8)*(_WORD *)(v12 + 8),
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                   + 51)
                                                                 + 16)
                                                     + 4 * v15),
          src_ptr);
    }
    ++*((_DWORD *)v14 + 23);
    v16 = *(_DWORD *)(a2 + 408);
    *(float *)v25 = (float)*(unsigned int *)(a2 + 200);
    if ( *(_DWORD *)(v16 + 44) == *((_DWORD *)v14 + 574) )
    {
      v17 = *(unsigned __int16 *)(v16 + 28);
      if ( v17 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          *(unsigned __int16 *)(v16 + 30),
          (unsigned __int8)*(_WORD *)(v16 + 24),
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v14 + 211) + 16) + 4 * v17),
          v25);
    }
    ++*((_DWORD *)v14 + 23);
    vostok::render::constants_handler<2>::set_constant<vostok::math::float3>(
      *(const vostok::render::shader_constant_host **)(a2 + 432),
      (vostok::render::constants_handler<2> *)(v14 + 836),
      light_position);
    ++*((_DWORD *)v14 + 23);
    vostok::render::constants_handler<2>::set_constant<vostok::math::float3>(
      *(const vostok::render::shader_constant_host **)(a2 + 428),
      (vostok::render::constants_handler<2> *)(v14 + 836),
      light_direction);
    ++*((_DWORD *)v14 + 23);
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      *(const vostok::render::shader_constant_host **)(a2 + 432),
      (vostok::render::constants_handler<1> *)v14 + 123,
      light_position);
    ++*((_DWORD *)v14 + 23);
    M_start = transforms->_M_impl._M_start;
    M_finish = transforms->_M_impl._M_finish;
    if ( transforms->_M_impl._M_start != M_finish )
    {
      do
      {
        vostok::render::renderer_context::set_w(context, M_start);
        vostok::render::box_geometry::draw(v21);
        ++M_start;
      }
      while ( M_start != M_finish );
      v14 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    }
    vostok::render::backend::reset_render_targets(v18, (int)v14);
    v22 = *((_DWORD *)v14 + 547);
    m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
    *((_BYTE *)v14 + 167) |= *((_DWORD *)v14 + 539) != v22;
    *((_DWORD *)v14 + 539) = v22;
    (*(void (__stdcall **)(int, int, int))(*(_DWORD *)m_game->m_game_world.m_mouse_pos.y + 176))(
      m_game->m_game_world.m_mouse_pos.y,
      1,
      a2 + 96);
  }
}
