void __thiscall vostok::render::stage_ambient_lighting::render_environment_probes(
        vostok::render::stage_ambient_lighting *this,
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> wszName)
{
  vostok::render::render_target *m_object; // ebx
  vostok::strings::shared::profile *v3; // eax
  const vostok::math::float3 *p_next_in_hashset; // ecx
  float v5; // eax
  pix_event_wrapper_dx11 *v6; // edx
  vostok::fixed_vector<vostok::render::environment_probe *,1024> *v7; // eax
  bool v8; // zf
  pix_event_wrapper_dx11 *m_begin; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v10; // eax
  float z; // esi
  vostok::render::render_target *v12; // eax
  vostok::render::render_target *v13; // eax
  vostok::render::render_target *v14; // esi
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v15; // eax
  vostok::render::render_target *v16; // eax
  vostok::render::render_target *v17; // eax
  int v18; // edi
  vostok::render::render_target **v19; // eax
  vostok::render::render_target *v20; // eax
  float v21; // xmm0_4
  ID3D11RenderTargetView *m_rt; // xmm1_4
  vostok::math::float4x4 *v23; // eax
  vostok::math::float4x4 *v24; // esi
  int m_surface_3d; // eax
  vostok::render::res_effect *v26; // ecx
  vostok::render::res_geometry *v27; // ecx
  vostok::render::backend *v28; // ecx
  vostok::render::backend *v29; // ecx
  vostok::render::render_target *v30; // esi
  vostok::render::enum_rt_usage m_usage; // edi
  int v32; // eax
  vostok::render::res_texture *v33; // edi
  vostok::render::backend *v34; // ecx
  vostok::render::resource_manager *v35; // ecx
  vostok::render::res_texture *v36; // edi
  vostok::render::backend *v37; // ecx
  vostok::render::resource_manager *v38; // ecx
  float v39; // esi
  vostok::render::backend *v40; // ecx
  vostok::render::backend *v41; // ecx
  vostok::render::render_target *v42; // edi
  vostok::render::backend *v43; // ecx
  vostok::math::float3 *scale; // eax
  vostok::render::backend *v45; // ecx
  vostok::math::float3 *v46; // eax
  vostok::render::backend *v47; // ecx
  vostok::render::res_geometry *v48; // ecx
  vostok::render::backend *v49; // ecx
  vostok::math::float4x4 *v50; // eax
  vostok::render::backend *v51; // ecx
  vostok::math::float4x4 *v52; // eax
  vostok::render::backend *v53; // ecx
  vostok::render::res_geometry *v54; // ecx
  vostok::render::backend *v55; // ecx
  const vostok::render::render_target *v56; // [esp-Ch] [ebp-248h]
  const vostok::render::shader_constant_host *v57; // [esp-8h] [ebp-244h]
  vostok::render::renderer_context *v58; // [esp-4h] [ebp-240h]
  vostok::math::float4x4 v59; // [esp+10h] [ebp-22Ch] BYREF
  vostok::math::float4x4 v60; // [esp+50h] [ebp-1ECh] BYREF
  vostok::math::float4x4 v61; // [esp+90h] [ebp-1ACh] BYREF
  vostok::math::float4x4 v62; // [esp+D0h] [ebp-16Ch] BYREF
  vostok::math::float4x4 v63; // [esp+110h] [ebp-12Ch] BYREF
  vostok::math::float4x4 v64; // [esp+150h] [ebp-ECh] BYREF
  vostok::math::float4x4 v65; // [esp+190h] [ebp-ACh] BYREF
  vostok::math::float3 v66; // [esp+1D0h] [ebp-6Ch] BYREF
  vostok::math::float3 v67; // [esp+1DCh] [ebp-60h] BYREF
  vostok::math::float3 v68; // [esp+1E8h] [ebp-54h] BYREF
  int v69; // [esp+1F4h] [ebp-48h]
  vostok::math::float3 v70; // [esp+1F8h] [ebp-44h] BYREF
  int *v71; // [esp+204h] [ebp-38h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v72; // [esp+208h] [ebp-34h] BYREF
  unsigned int v73; // [esp+20Ch] [ebp-30h]
  const vostok::math::float3 *v74; // [esp+210h] [ebp-2Ch]
  float v75; // [esp+214h] [ebp-28h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v76; // [esp+218h] [ebp-24h] BYREF
  vostok::math::float3 v77; // [esp+21Ch] [ebp-20h] BYREF
  vostok::render::render_target **v78; // [esp+228h] [ebp-14h]
  vostok::render::environment_probe **v79; // [esp+22Ch] [ebp-10h]
  vostok::render::render_target *rt; // [esp+230h] [ebp-Ch] BYREF
  vostok::render::render_target *v81; // [esp+234h] [ebp-8h] BYREF

  m_object = wszName.m_object;
  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    (pix_event_wrapper_dx11 *)this,
    (pix_event_wrapper_dx11 *)&wszName.m_object + 3,
    (int)L"render_environment_probes");
  v3 = m_object->m_name.m_pointer.m_object;
  p_next_in_hashset = (const vostok::math::float3 *)&v3[1308].next_in_hashset;
  v5 = *(float *)&v3[1016].m_checksum;
  v6 = *(pix_event_wrapper_dx11 **)(LODWORD(v5) + 52464);
  v77.z = v5;
  v7 = (vostok::fixed_vector<vostok::render::environment_probe *,1024> *)(LODWORD(v5) + 52460);
  v8 = BYTE1(m_object[1].m_memory_usage) == 0;
  v74 = p_next_in_hashset;
  m_begin = (pix_event_wrapper_dx11 *)v7->m_begin;
  v79 = v7->m_begin;
  v78 = (vostok::render::render_target **)v6;
  if ( v8 || m_begin == v6 )
    goto LABEL_42;
  vostok::render::stage_ambient_lighting::make_probe_indices_map(
    v7,
    m_begin,
    (vostok::render::environment_probe **)m_object);
  if ( !s_no_probe_spec || vostok::quasi_singleton<vostok::render::options>::pinst->current.m_lighting_quality )
  {
    v14 = vostok::render::renderer_context::get_rt(
            (vostok::render::renderer_context *)m_object->m_name.m_pointer.m_object,
            rt_accumulator_specular,
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v81)->m_object;
    v15 = vostok::render::renderer_context::get_rt(
            (vostok::render::renderer_context *)m_object->m_name.m_pointer.m_object,
            rt_accumulator_diffuse,
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
    v56 = v14;
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v15->m_object,
      v56,
      0,
      0);
    v16 = rt;
    if ( rt )
    {
      --rt->m_reference_count;
      if ( !v16->m_reference_count )
      {
        vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
        z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      }
    }
    v17 = v81;
    if ( !v81 )
      goto LABEL_15;
    --v81->m_reference_count;
    if ( v17->m_reference_count )
      goto LABEL_15;
    v13 = v81;
    goto LABEL_14;
  }
  v10 = vostok::render::renderer_context::get_rt(
          (vostok::render::renderer_context *)m_object->m_name.m_pointer.m_object,
          rt_accumulator_diffuse,
          &wszName);
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v10->m_object,
    0,
    0,
    0);
  v12 = wszName.m_object;
  if ( wszName.m_object )
  {
    --wszName.m_object->m_reference_count;
    if ( !v12->m_reference_count )
    {
      v13 = wszName.m_object;
LABEL_14:
      vostok::render::resource_manager::release(v13, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    }
  }
LABEL_15:
  v18 = *(_DWORD *)(LODWORD(z) + 7440);
  v8 = *(_DWORD *)(LODWORD(z) + 7384) == v18;
  *(_DWORD *)(LODWORD(z) + 7384) = v18;
  v19 = (vostok::render::render_target **)v79;
  *(_BYTE *)(LODWORD(z) + 117) |= !v8;
  rt = 0;
  if ( v19 != v78 )
  {
    while ( 1 )
    {
      v20 = *v19;
      v8 = v20[7].m_usage == enum_rt_usage_depth_stencil;
      v21 = *(float *)&v20[7].m_surface_3d;
      m_rt = v20[7].m_rt;
      wszName.m_object = v20;
      v77.y = v21;
      v75 = *(float *)&m_rt;
      if ( v8 )
      {
        v70.x = v21;
        v70.y = v21;
        v70.z = v21;
        v81 = (vostok::render::render_target *)vostok::math::create_translation(
                                                 (const vostok::math::float3 *)&v20[7].m_name,
                                                 &v61);
        v23 = vostok::math::create_scale(&v70, &v59);
        vostok::math::mul4x3((const vostok::math::float4x4 *)v81, v23, &v60);
        v20 = wszName.m_object;
        v24 = &v60;
      }
      else
      {
        v24 = (vostok::math::float4x4 *)(&v20[3].m_is_registered + 4);
      }
      qmemcpy(&v63, v24, sizeof(v63));
      v58 = (vostok::render::renderer_context *)m_object->m_name.m_pointer.m_object;
      qmemcpy(&v62, (char *)&v20[4].m_order + 4, sizeof(v62));
      vostok::render::renderer_context::set_w(&v63, v58);
      m_surface_3d = (int)m_object->m_surface_3d;
      *(_DWORD *)(m_surface_3d + 22048) = 0;
      vostok::render::res_effect::apply_pass(v26, m_surface_3d);
      if ( wszName.m_object[7].m_usage )
      {
        vostok::render::res_geometry::apply(v27, m_object[3].m_format);
        vostok::render::backend::render_indexed(
          (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          0x24u,
          v29,
          D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
          0,
          0);
      }
      else
      {
        vostok::render::res_geometry::apply(v27, (int)m_object[3].m_texture.m_object);
        vostok::render::backend::render_indexed(
          (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          0x21Cu,
          v28,
          D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
          0,
          0);
      }
      qmemcpy(&v65, &wszName.m_object[3].m_is_registered + 4, sizeof(v65));
      vostok::math::float4x4::try_invert(&v65, &v65);
      qmemcpy(&v64, (char *)&wszName.m_object[4].m_order + 4, sizeof(v64));
      vostok::math::float4x4::try_invert(&v64, &v64);
      v30 = wszName.m_object;
      m_usage = wszName.m_object[7].m_usage;
      if ( m_usage )
      {
        if ( (unsigned int)m_usage > enum_rt_usage_render_target )
          m_usage = enum_rt_usage_render_target;
      }
      else
      {
        m_usage = enum_rt_usage_depth_stencil;
      }
      v32 = BYTE2(wszName.m_object[7].m_format);
      v81 = 0;
      v73 = s_two_passes + 1;
      if ( s_two_passes != -1 )
      {
        v77.x = v75 - 0.050000001;
        v71 = (int *)&(&(&m_object->m_rt)[2 * m_usage])[v32];
        v68.z = 0.0;
        v69 = 0;
        while ( 1 )
        {
          vostok::render::res_effect::apply((vostok::render::res_effect *)v81, *v71);
          vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
            &v76,
            (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v30[8].m_zrt);
          v33 = v76.m_object;
          vostok::render::backend::set_ps_texture(
            v34,
            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            "t_probe_cubemap",
            v76.m_object);
          if ( v33 )
          {
            v8 = v33->m_reference_count-- == 1;
            if ( v8 )
              vostok::render::resource_manager::release(
                v35,
                (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                v33);
          }
          vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
            &v72,
            (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&wszName.m_object[8].m_rt);
          v36 = v72.m_object;
          vostok::render::backend::set_ps_texture(
            v37,
            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            "t_probe_cubemap_diffuse",
            v72.m_object);
          if ( v36 )
          {
            v8 = v36->m_reference_count-- == 1;
            if ( v8 )
              vostok::render::resource_manager::release(
                v38,
                (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                v36);
          }
          v39 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            (vostok::render::backend *)v38,
            (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            (const vostok::render::shader_constant_host *)HIDWORD(m_object[1].m_order),
            v74);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v40,
            (vostok::render::constants_handler<1> *)LODWORD(v39),
            (const vostok::render::shader_constant_host *)m_object[2].m_name.m_pointer.m_object,
            (vostok::math::float3 *)&v77.elements[1]);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v41,
            (vostok::render::constants_handler<1> *)LODWORD(v39),
            (const vostok::render::shader_constant_host *)m_object[2].m_memory_usage_type,
            &v77);
          vostok::render::backend::set_ps_constant<unsigned int>(
            (vostok::render::backend *)LODWORD(v39),
            (const vostok::render::shader_constant_host *)m_object[2].m_surface,
            (const int *)&wszName.m_object[8].m_name);
          v42 = wszName.m_object;
          v68.x = *(float *)&wszName.m_object[7].m_zrt * *(float *)(LODWORD(v77.z) + 644);
          v57 = (const vostok::render::shader_constant_host *)m_object[2].m_surface_3d;
          v68.y = *(float *)&wszName.m_object[7].m_texture.m_object * *(float *)(LODWORD(v77.z) + 648);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v43,
            (vostok::render::constants_handler<1> *)LODWORD(v39),
            v57,
            &v68);
          vostok::render::backend::set_ps_constant<unsigned int>(
            (vostok::render::backend *)LODWORD(v39),
            (const vostok::render::shader_constant_host *)m_object[3].m_surface_3d,
            (const int *)&rt);
          scale = vostok::math::float4x4::get_scale(&v63, &v67);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v45,
            (vostok::render::constants_handler<1> *)LODWORD(v39),
            *((const vostok::render::shader_constant_host **)&m_object[2].m_memory_usage + 1),
            scale);
          v46 = vostok::math::float4x4::get_scale(&v62, &v66);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v47,
            (vostok::render::constants_handler<1> *)LODWORD(v39),
            (const vostok::render::shader_constant_host *)m_object[2].m_order,
            v46);
          if ( v42[7].m_usage )
          {
            v50 = vostok::math::transpose(&v65, &v59);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v51,
              (vostok::render::constants_handler<1> *)LODWORD(v39),
              (const vostok::render::shader_constant_host *)m_object[3].m_surface,
              (const vostok::math::float3 *)v50);
            v52 = vostok::math::transpose(&v64, &v61);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v53,
              (vostok::render::constants_handler<1> *)LODWORD(v39),
              (const vostok::render::shader_constant_host *)m_object[3].m_memory_usage_type,
              (const vostok::math::float3 *)v52);
            vostok::render::res_geometry::apply(v54, m_object[3].m_format);
            vostok::render::backend::render_indexed(
              (vostok::render::backend *)LODWORD(v39),
              0x24u,
              v55,
              D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
              0,
              0);
          }
          else
          {
            vostok::render::res_geometry::apply(v48, (int)m_object[3].m_texture.m_object);
            vostok::render::backend::render_indexed(
              (vostok::render::backend *)LODWORD(v39),
              0x21Cu,
              v49,
              D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
              0,
              0);
          }
          v81 = (vostok::render::render_target *)((char *)v81 + 1);
          if ( (unsigned int)v81 >= v73 )
            break;
          v30 = wszName.m_object;
        }
      }
      ++v79;
      rt = (vostok::render::render_target *)((char *)rt + 1);
      if ( v79 == (vostok::render::environment_probe **)v78 )
        break;
      v19 = (vostok::render::render_target **)v79;
    }
  }
LABEL_42:
  D3DPERF_EndEvent();
}
