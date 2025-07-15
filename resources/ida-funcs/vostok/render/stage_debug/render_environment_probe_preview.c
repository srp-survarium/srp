void __thiscall vostok::render::stage_debug::render_environment_probe_preview(
        vostok::render::stage_debug *this,
        int a2)
{
  vostok::render::environment_probe **v2; // ecx
  bool i; // zf
  vostok::render::environment_probe *v4; // ebx
  bool is_valid_textures; // al
  float z; // xmm2_4
  float y; // xmm1_4
  float x; // xmm0_4
  float *v9; // eax
  BOOL v10; // eax
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  vostok::math::float4x4 *v14; // eax
  int v15; // ecx
  int v16; // esi
  int z_low; // edi
  float v18; // esi
  vostok::render::sky_dome_geometry *v19; // ecx
  vostok::render::res_texture *m_object; // edi
  vostok::render::backend *v21; // ecx
  vostok::render::resource_manager *v22; // ecx
  vostok::render::res_texture *v23; // edi
  vostok::render::backend *v24; // ecx
  vostok::render::resource_manager *v25; // ecx
  vostok::render::backend *v26; // ecx
  unsigned int v27; // [esp+0h] [ebp-10Ch]
  vostok::math::float4x4 v28; // [esp+10h] [ebp-FCh] BYREF
  vostok::math::float4x4 v29; // [esp+50h] [ebp-BCh] BYREF
  vostok::math::float4x4 v30; // [esp+90h] [ebp-7Ch] BYREF
  vostok::math::float3 v31; // [esp+D0h] [ebp-3Ch] BYREF
  vostok::math::float3 v32; // [esp+DCh] [ebp-30h] BYREF
  vostok::render::environment_probe **v33; // [esp+E8h] [ebp-24h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v34; // [esp+ECh] [ebp-20h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v35; // [esp+F0h] [ebp-1Ch] BYREF
  unsigned int v36; // [esp+F4h] [ebp-18h]
  vostok::render::environment_probe **v37; // [esp+F8h] [ebp-14h]
  int arg; // [esp+FCh] [ebp-10h] BYREF
  unsigned int v39; // [esp+100h] [ebp-Ch]
  bool v40; // [esp+107h] [ebp-5h]

  v2 = *(vostok::render::environment_probe ***)(*(_DWORD *)(*(_DWORD *)(a2 + 4) + 16268) + 52460);
  v33 = *(vostok::render::environment_probe ***)(*(_DWORD *)(*(_DWORD *)(a2 + 4) + 16268) + 52464);
  for ( i = v2 == v33; ; i = v37 + 1 == v33 )
  {
    v37 = v2;
    if ( i )
      break;
    v4 = *v2;
    is_valid_textures = vostok::render::environment_probe::is_valid_textures(*v2);
    z = v4->m_properties.location.z;
    y = v4->m_properties.location.y;
    x = v4->m_properties.location.x;
    v40 = is_valid_textures;
    v9 = *(float **)(a2 + 4);
    v10 = fsqrt(
            (float)((float)((float)(z - v9[5285]) * (float)(z - v9[5285]))
                  + (float)((float)(y - v9[5284]) * (float)(y - v9[5284])))
          + (float)((float)(x - v9[5283]) * (float)(x - v9[5283]))) < 7.0;
    v39 = 0;
    v36 = 2 * v10 + 1;
    if ( 2 * v10 != -1 )
    {
      do
      {
        if ( v39 <= 1 )
          v11 = s_bm_current_air_resistance;
        else
          v11 = c_anim_center;
        if ( v39 )
          v12 = c_anim_center;
        else
          v12 = s_bm_current_air_resistance;
        v32.x = v4->m_properties.location.x;
        v13 = v4->m_properties.location.y
            + (float)((float)((float)(v39 > 1) * 0.5) + (float)((float)(v39 != 0) * 0.85000002));
        v32.z = v4->m_properties.location.z;
        v32.y = v13;
        v31.x = (float)(v12 * v11) * 0.5;
        v31.y = v31.x;
        v31.z = v31.x;
        arg = (int)vostok::math::create_translation(&v32, &v29);
        v14 = vostok::math::create_scale(&v31, &v28);
        vostok::math::mul4x3((const vostok::math::float4x4 *)arg, v14, &v30);
        if ( v40 )
        {
          v15 = v39;
          if ( v39 )
          {
            if ( v39 > 1 )
              v15 = 1;
          }
          else
          {
            v15 = 0;
          }
        }
        else
        {
          v15 = 2;
        }
        v16 = a2;
        vostok::render::res_effect::apply((vostok::render::res_effect *)v15, *(_DWORD *)(a2 + 16));
        z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
        if ( v40 && v39 )
        {
          v18 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
          vostok::render::backend::set_ps_constant<vostok::math::float4>(
            (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            *(const vostok::render::shader_constant_host **)(a2 + 64),
            v4->m_properties.face_average_colors,
            v27);
          arg = v39 - 1;
          vostok::render::backend::set_ps_constant<unsigned int>(
            (vostok::render::backend *)LODWORD(v18),
            *(const vostok::render::shader_constant_host **)(a2 + 60),
            &arg);
          v16 = a2;
        }
        vostok::render::renderer_context::set_w(&v30, *(vostok::render::renderer_context **)(v16 + 4));
        if ( v40 )
        {
          vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
            &v35,
            &v4->m_texture);
          m_object = v35.m_object;
          vostok::render::backend::set_ps_texture(
            v21,
            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            "t_probe_cubemap",
            v35.m_object);
          if ( m_object )
          {
            i = m_object->m_reference_count-- == 1;
            if ( i )
              vostok::render::resource_manager::release(
                v22,
                (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                m_object);
          }
          vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
            &v34,
            &v4->m_texture_diffuse);
          v23 = v34.m_object;
          vostok::render::backend::set_ps_texture(
            v24,
            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            "t_probe_cubemap_diffuse",
            v34.m_object);
          if ( v23 )
          {
            i = v23->m_reference_count-- == 1;
            if ( i )
              vostok::render::resource_manager::release(
                v25,
                (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                v23);
          }
          z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
          vostok::render::backend::set_ps_constant<unsigned int>(
            (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            *(const vostok::render::shader_constant_host **)(a2 + 56),
            (const int *)&v4->m_properties.preview_mip);
          v16 = a2;
        }
        if ( v39 == 2 )
        {
          vostok::render::backend::set_declaration(
            (vostok::render::backend *)z_low,
            *(vostok::render::res_declaration **)(v16 + 40));
          vostok::render::backend::set_vb(
            (vostok::render::backend *)z_low,
            *(vostok::render::untyped_buffer **)(a2 + 44),
            *(_DWORD *)(v16 + 52));
          vostok::render::backend::set_ib(*(vostok::render::backend **)(a2 + 48), z_low);
          vostok::render::backend::render_indexed(
            (vostok::render::backend *)z_low,
            0x24u,
            v26,
            D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
            0,
            0);
        }
        else
        {
          vostok::render::sky_dome_geometry::draw(v19, v16 + 20);
        }
        ++v39;
      }
      while ( v39 < v36 );
    }
    v2 = v37 + 1;
  }
}
