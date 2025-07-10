void __userpurge vostok::render::radiance_volume::inject_occluders(
        vostok::render::radiance_volume *this@<ecx>,
        int a2@<eax>,
        vostok::render::renderer_context *context,
        const vostok::math::float3 *light_position,
        const vostok::math::float3 *light_direction,
        unsigned int rsm_size)
{
  int v7; // eax
  vostok::render::radiance_volume *v8; // ecx
  const char *m_conflicted_key_name; // eax
  _DWORD *v10; // eax
  unsigned int v11; // ecx
  int v12; // eax
  int v13; // edx
  const char *v14; // edi
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  vostok::render::textures_handler<0> *v18; // ecx
  char v19; // al
  const char *v20; // ecx
  vostok::render::injection_geometry *v21; // ecx
  vostok::render::radiance_volume *v22; // ecx
  unsigned int v23; // [esp+0h] [ebp-2Ch]
  char v24[4]; // [esp+14h] [ebp-18h] BYREF
  char src_ptr[4]; // [esp+18h] [ebp-14h] BYREF
  int v26; // [esp+1Ch] [ebp-10h]
  int v27; // [esp+20h] [ebp-Ch]
  float v28; // [esp+24h] [ebp-8h]

  if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
       + 275) )
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
    v10 = *(_DWORD **)(a2 + 400);
    v11 = (v10[71] - v10[70]) >> 2;
    if ( v11 > 1 )
    {
      v10[69] = 1;
      vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v11, v23);
    }
    v12 = *(_DWORD *)(a2 + 416);
    v13 = *(_DWORD *)(v12 + 36);
    v14 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    *(_DWORD *)src_ptr = *(_DWORD *)(a2 + 204);
    v26 = *(_DWORD *)(a2 + 208);
    v27 = *(_DWORD *)(a2 + 212);
    v28 = *(float *)&clear_value / *(float *)(a2 + 192);
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
    *(float *)v24 = (float)*(unsigned int *)(a2 + 200);
    if ( *(_DWORD *)(v16 + 44) == *((_DWORD *)v14 + 574) )
    {
      v17 = *(unsigned __int16 *)(v16 + 28);
      if ( v17 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          *(unsigned __int16 *)(v16 + 30),
          (unsigned __int8)*(_WORD *)(v16 + 24),
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v14 + 211) + 16) + 4 * v17),
          v24);
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
    v19 = vostok::render::textures_handler<0>::set_overwrite(
            v18,
            (char *)v14 + 208,
            (vostok::render::res_texture *)&texture.num_mips,
            *(vostok::render::res_texture **)(a2 + 60));
    v20 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    *((_BYTE *)v14 + 151) = v19;
    *((_BYTE *)v20 + 151) = vostok::render::textures_handler<0>::set_overwrite(
                              (vostok::render::textures_handler<0> *)(v20 + 208),
                              (char *)v20 + 208,
                              (vostok::render::res_texture *)&texture.m_rescale_max,
                              *(vostok::render::res_texture **)(a2 + 68));
    vostok::render::injection_geometry::draw(v21, (int *)(a2 + 120));
    vostok::render::radiance_volume::end_render_to_cells(v22, (vostok::render::radiance_volume *)a2);
  }
}
