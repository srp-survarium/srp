void __usercall vostok::render::stage_debug::render_environment_probe_preview(
        vostok::render::stage_debug *this@<ecx>,
        int a2@<edi>)
{
  vostok::render::environment_probe **v2; // ebx
  vostok::render::environment_probe **v3; // eax
  vostok::render::environment_probe *v4; // esi
  const vostok::math::float4x4 *v5; // eax
  _DWORD *v6; // eax
  int v7; // ecx
  const char *m_conflicted_key_name; // ebp
  char v9; // al
  vostok::render::constants_handler<1> *v10; // esi
  const vostok::math::float3 *p_preview_mip; // [esp-4h] [ebp-D8h]
  unsigned int v12; // [esp+0h] [ebp-D4h]
  vostok::render::environment_probe **end; // [esp+Ch] [ebp-C8h]
  vostok::math::float4x4 dst; // [esp+10h] [ebp-C4h] BYREF
  vostok::math::float4x4 world_transform; // [esp+50h] [ebp-84h] BYREF
  vostok::math::float4x4 result; // [esp+90h] [ebp-44h] BYREF

  v2 = *(vostok::render::environment_probe ***)(*(_DWORD *)(*(_DWORD *)(a2 + 4) + 12392) + 1376);
  v3 = *(vostok::render::environment_probe ***)(*(_DWORD *)(*(_DWORD *)(a2 + 4) + 12392) + 1380);
  for ( end = v3; v2 != v3; ++v2 )
  {
    v4 = *v2;
    if ( (!*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
           + 288)
       || !v4->m_occluded)
      && v4->m_texture.m_object
      && v4->m_properties.enabled )
    {
      memset((int)&dst, 0, sizeof(dst));
      dst.i.x = FLOAT_0_5;
      dst.j.y = FLOAT_0_5;
      dst.k.z = FLOAT_0_5;
      LODWORD(dst.c.w) = clear_value;
      v5 = vostok::math::create_translation(&result, &v4->m_properties.location);
      vostok::math::mul4x3(&world_transform, &dst, v5);
      v6 = *(_DWORD **)(a2 + 16);
      v7 = (v6[71] - v6[70]) >> 2;
      if ( v7 )
      {
        v6[69] = 0;
        vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v7, v12);
      }
      vostok::render::renderer_context::set_w(*(vostok::render::renderer_context **)(a2 + 4), &world_transform);
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v9 = vostok::render::textures_handler<0>::set_overwrite(
             (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                   + 1488),
             (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 1488,
             (vostok::render::res_texture *)&stru_9642F8,
             v4->m_texture.m_object);
      p_preview_mip = (const vostok::math::float3 *)&v4->m_properties.preview_mip;
      v10 = (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)m_conflicted_key_name + 159) = v9;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        *(const vostok::render::shader_constant_host **)(a2 + 40),
        v10 + 123,
        p_preview_mip);
      ++v10[7].m_current.m_object;
      vostok::render::sphere_geometry::draw((vostok::render::sphere_geometry *)(a2 + 20));
      v3 = end;
    }
  }
}
