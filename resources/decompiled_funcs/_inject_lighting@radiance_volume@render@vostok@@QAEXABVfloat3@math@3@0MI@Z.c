void __thiscall vostok::render::radiance_volume::inject_lighting(
        vostok::render::radiance_volume *this,
        float light_position,
        float light_direction,
        const vostok::math::float3 *light_fov,
        float rsm_size,
        unsigned int rsm_sizea)
{
  vostok::math::float3 *v6; // ebx
  vostok::render::radiance_volume *v7; // ecx
  float y; // eax
  int v9; // ecx
  const char *m_conflicted_key_name; // esi
  char v11; // al
  const char *v12; // ecx
  const char *v13; // esi
  char v14; // al
  const char *v15; // ecx
  float z; // eax
  int v17; // edx
  const char *v18; // esi
  int v19; // ecx
  float x; // eax
  int v21; // ecx
  const vostok::math::float3 *v22; // edx
  const vostok::math::float3 *v23; // eax
  const vostok::math::float3 *v24; // ecx
  const vostok::math::float3 *v25; // edx
  float _X; // xmm0_4
  long double v27; // st7
  vostok::render::injection_geometry *v28; // ecx
  float v29; // eax
  int v30; // edx
  vostok::render::radiance_volume *v31; // ecx
  unsigned int v32; // [esp+4h] [ebp-20h]
  char src_ptr[4]; // [esp+14h] [ebp-10h] BYREF
  float v34; // [esp+18h] [ebp-Ch]
  float v35; // [esp+1Ch] [ebp-8h]
  float v36; // [esp+20h] [ebp-4h]

  v6 = (vostok::math::float3 *)LODWORD(light_position);
  vostok::render::backend::set_render_targets(
    *(ID3D11RenderTargetView **)(LODWORD(light_position) + 292),
    *(const vostok::render::render_target **)(LODWORD(light_position) + 296),
    *(const vostok::render::render_target **)(LODWORD(light_position) + 300),
    0,
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  vostok::render::radiance_volume::begin_render_to_cells(v7, (int)v6);
  y = v6[33].y;
  v9 = (*(_DWORD *)(LODWORD(y) + 284) - *(_DWORD *)(LODWORD(y) + 280)) >> 2;
  if ( v9 )
  {
    *(_DWORD *)(LODWORD(y) + 276) = 0;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v9, v32);
  }
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v11 = vostok::render::textures_handler<0>::set_overwrite(
          (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                + 208),
          (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 208,
          (vostok::render::res_texture *)&texture.m_mem_usage,
          (vostok::render::res_texture *)LODWORD(v6[4].y));
  v12 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)m_conflicted_key_name + 151) = v11;
  v13 = v12;
  v14 = vostok::render::textures_handler<0>::set_overwrite(
          (vostok::render::textures_handler<0> *)(v12 + 208),
          (char *)v12 + 208,
          (vostok::render::res_texture *)&texture.num_mips,
          (vostok::render::res_texture *)LODWORD(v6[5].x));
  v15 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v13 + 151) = v14;
  *((_BYTE *)v15 + 151) = vostok::render::textures_handler<0>::set_overwrite(
                            (vostok::render::textures_handler<0> *)(v15 + 208),
                            (char *)v15 + 208,
                            (vostok::render::res_texture *)&texture.m_rescale_max,
                            (vostok::render::res_texture *)LODWORD(v6[5].z));
  z = v6[34].z;
  v17 = *(_DWORD *)(LODWORD(z) + 36);
  v18 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *(float *)src_ptr = v6[17].x;
  v34 = v6[17].y;
  v35 = v6[17].z;
  v36 = *(float *)&clear_value / v6[16].x;
  if ( v17 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 572) )
  {
    v19 = *(unsigned __int16 *)(LODWORD(z) + 12);
    if ( v19 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        *(unsigned __int16 *)(LODWORD(z) + 14),
        (unsigned __int8)*(_WORD *)(LODWORD(z) + 8),
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 51)
                                                               + 16)
                                                   + 4 * v19),
        src_ptr);
  }
  ++*((_DWORD *)v18 + 23);
  x = v6[34].x;
  light_position = (float)LODWORD(v6[16].z);
  if ( *(_DWORD *)(LODWORD(x) + 44) == *((_DWORD *)v18 + 574) )
  {
    v21 = *(unsigned __int16 *)(LODWORD(x) + 28);
    if ( v21 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        *(unsigned __int16 *)(LODWORD(x) + 30),
        (unsigned __int8)*(_WORD *)(LODWORD(x) + 24),
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v18 + 211) + 16) + 4 * v21),
        (const char *)&light_position);
  }
  v22 = (const vostok::math::float3 *)LODWORD(light_direction);
  ++*((_DWORD *)v18 + 23);
  vostok::render::constants_handler<2>::set_constant<vostok::math::float3>(
    (const vostok::render::shader_constant_host *)LODWORD(v6[36].x),
    (vostok::render::constants_handler<2> *)(v18 + 836),
    v22);
  v23 = light_fov;
  ++*((_DWORD *)v18 + 23);
  vostok::render::constants_handler<2>::set_constant<vostok::math::float3>(
    (const vostok::render::shader_constant_host *)LODWORD(v6[35].z),
    (vostok::render::constants_handler<2> *)(v18 + 836),
    v23);
  v24 = (const vostok::math::float3 *)LODWORD(light_direction);
  ++*((_DWORD *)v18 + 23);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    (const vostok::render::shader_constant_host *)LODWORD(v6[36].x),
    (vostok::render::constants_handler<1> *)v18 + 123,
    v24);
  v25 = light_fov;
  ++*((_DWORD *)v18 + 23);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    (const vostok::render::shader_constant_host *)LODWORD(v6[35].z),
    (vostok::render::constants_handler<1> *)v18 + 123,
    v25);
  _X = rsm_size * 0.5;
  ++*((_DWORD *)v18 + 23);
  v27 = tanf(_X);
  v28 = (vostok::render::injection_geometry *)(rsm_sizea * rsm_sizea);
  LODWORD(light_direction) = rsm_sizea * rsm_sizea;
  v29 = v6[36].z;
  v30 = *(_DWORD *)(LODWORD(v29) + 40);
  light_direction = v27 * v27 * 4.0 / (double)(rsm_sizea * rsm_sizea) * 30.0;
  if ( v30 == *((_DWORD *)v18 + 573) )
  {
    v28 = (vostok::render::injection_geometry *)*(unsigned __int16 *)(LODWORD(v29) + 20);
    if ( v28 != (vostok::render::injection_geometry *)0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        *(unsigned __int16 *)(LODWORD(v29) + 22),
        (unsigned __int8)*(_WORD *)(LODWORD(v29) + 16),
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v18 + 371) + 16) + 4 * (_DWORD)v28),
        (const char *)&light_direction);
  }
  ++*((_DWORD *)v18 + 23);
  vostok::render::injection_geometry::draw(v28, (int *)&v6[10]);
  vostok::render::radiance_volume::end_render_to_cells(v31, (vostok::render::radiance_volume *)v6);
}
