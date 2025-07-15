void __userpurge vostok::render::radiance_volume::inject_camera_occluders(
        vostok::render::radiance_volume *this@<ecx>,
        int a2@<eax>,
        vostok::render::renderer_context *context)
{
  int v4; // eax
  vostok::render::radiance_volume *v5; // ecx
  const char *m_conflicted_key_name; // eax
  _DWORD *v7; // eax
  unsigned int v8; // ecx
  const char *v9; // edi
  vostok::render::constants_handler<0> *v10; // ebx
  int v11; // eax
  int v12; // ecx
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  vostok::render::renderer_context *v18; // ecx
  vostok::render::injection_geometry *v19; // ecx
  vostok::render::radiance_volume *v20; // ecx
  unsigned int v21; // [esp+0h] [ebp-18h]
  char src_ptr[4]; // [esp+14h] [ebp-4h] BYREF

  if ( *(_BYTE *)(a2 + 460)
    && *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
       + 276) )
  {
    v4 = *(_DWORD *)(a2 + 388);
    if ( v4 )
      v5 = *(vostok::render::radiance_volume **)(v4 + 16);
    else
      v5 = 0;
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    if ( *((vostok::render::radiance_volume **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
         + 535) != v5 )
    {
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = v5;
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
    vostok::render::radiance_volume::begin_render_to_cells(v5, a2);
    v7 = *(_DWORD **)(a2 + 400);
    v8 = (v7[71] - v7[70]) >> 2;
    if ( v8 > 2 )
    {
      v7[69] = 2;
      vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v8, v21);
    }
    v9 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    v10 = (vostok::render::constants_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                 + 196);
    vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
      *(const vostok::render::shader_constant_host **)(a2 + 412),
      (vostok::render::constants_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                             + 196),
      (const vostok::math::float3 *)(a2 + 204));
    ++*((_DWORD *)v9 + 23);
    v11 = *(_DWORD *)(a2 + 420);
    v12 = *(_DWORD *)(v11 + 36);
    *(float *)src_ptr = *(float *)(a2 + 192) / (double)*(unsigned int *)(a2 + 200);
    if ( v12 == *((_DWORD *)v9 + 572) )
    {
      v13 = *(unsigned __int16 *)(v11 + 12);
      if ( v13 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          *(unsigned __int16 *)(v11 + 14),
          (unsigned __int8)*(_WORD *)(v11 + 8),
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v9 + 51) + 16) + 4 * v13),
          src_ptr);
    }
    ++*((_DWORD *)v9 + 23);
    v14 = *(_DWORD *)(a2 + 424);
    *(float *)src_ptr = (float)*(unsigned int *)(a2 + 200);
    if ( *(_DWORD *)(v14 + 36) == *((_DWORD *)v9 + 572) )
    {
      v15 = *(unsigned __int16 *)(v14 + 12);
      if ( v15 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          *(unsigned __int16 *)(v14 + 14),
          (unsigned __int8)*(_WORD *)(v14 + 8),
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v9 + 51) + 16) + 4 * v15),
          src_ptr);
    }
    ++*((_DWORD *)v9 + 23);
    v16 = *(_DWORD *)(a2 + 408);
    *(float *)src_ptr = (float)*(unsigned int *)(a2 + 200);
    if ( *(_DWORD *)(v16 + 44) == *((_DWORD *)v9 + 574) )
    {
      v17 = *(unsigned __int16 *)(v16 + 28);
      if ( v17 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          *(unsigned __int16 *)(v16 + 30),
          (unsigned __int8)*(_WORD *)(v16 + 24),
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v9 + 211) + 16) + 4 * v17),
          src_ptr);
    }
    ++*((_DWORD *)v9 + 23);
    vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
      *(const vostok::render::shader_constant_host **)(a2 + 448),
      v10,
      context->m_eye_rays);
    ++*((_DWORD *)v9 + 23);
    vostok::render::renderer_context::set_v(v18, (const vostok::math::float4x4 *)context);
    vostok::render::renderer_context::set_p(
      (vostok::render::renderer_context *)&context->m_p,
      (const vostok::math::float4x4 *)context);
    vostok::render::injection_geometry::draw(v19, (int *)(a2 + 144));
    vostok::render::radiance_volume::end_render_to_cells(v20, (vostok::render::radiance_volume *)a2);
  }
}
