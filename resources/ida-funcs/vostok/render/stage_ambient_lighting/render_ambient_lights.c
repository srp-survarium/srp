void __thiscall vostok::render::stage_ambient_lighting::render_ambient_lights(
        vostok::render::stage_ambient_lighting *this,
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> wszName)
{
  vostok::render::render_target *m_object; // ebx
  vostok::render::renderer_context *v3; // ecx
  vostok::render::render_target *m_next_in_increase_quality_queue; // edx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v5; // eax
  float z; // esi
  vostok::render::res_pass *v7; // ecx
  vostok::render::render_target *v8; // eax
  int v9; // edi
  bool v10; // zf
  vostok::render::render_target *v11; // eax
  unsigned int m_reference_count; // eax
  float v13; // xmm0_4
  vostok::math::float4x4 *v14; // eax
  vostok::math::float4x4 *v15; // esi
  vostok::render::res_pass *v16; // ecx
  ID3D11Texture3D *m_surface_3d; // eax
  vostok::render::res_pass *v18; // esi
  vostok::render::res_pass *QueryInterface; // eax
  vostok::render::res_pass *v20; // edi
  _DWORD *v21; // eax
  vostok::render::effect_manager *v22; // ecx
  vostok::render::backend *v23; // ecx
  unsigned int v24; // eax
  unsigned int v25; // esi
  float v26; // xmm1_4
  int v27; // edi
  vostok::render::res_geometry *v28; // ecx
  vostok::strings::shared::profile *v29; // eax
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm3_4
  int v33; // edi
  float v34; // xmm4_4
  int v35; // eax
  BOOL v36; // ecx
  int v37; // xmm0_4
  float v38; // esi
  vostok::render::backend *v39; // ecx
  unsigned int v40; // edi
  int v41; // xmm0_4
  vostok::render::backend *v42; // ecx
  vostok::render::backend *v43; // ecx
  vostok::render::res_geometry *v44; // ecx
  vostok::render::backend *v45; // ecx
  unsigned int v46; // eax
  vostok::math::float4x4 *v47; // eax
  vostok::render::backend *v48; // ecx
  float v49; // xmm0_4
  vostok::render::backend *v50; // ecx
  vostok::render::res_geometry *v51; // ecx
  vostok::render::res_texture *v52; // eax
  vostok::render::res_pass *v53; // edi
  vostok::render::res_pass *v54; // eax
  vostok::render::res_pass *v55; // esi
  _DWORD *v56; // eax
  vostok::render::effect_manager *v57; // ecx
  vostok::render::render_target *v58; // esi
  vostok::render::render_target *v59; // ebx
  vostok::render::render_target *v60; // ecx
  vostok::render::render_target *v61; // ecx
  vostok::render::render_target *v62; // eax
  vostok::render::render_target *v63; // eax
  vostok::render::system_renderer *v64; // [esp-1Ch] [ebp-1E0h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v65; // [esp-18h] [ebp-1DCh] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v66; // [esp-14h] [ebp-1D8h] BYREF
  vostok::render::render_target *v67; // [esp-10h] [ebp-1D4h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v68; // [esp-Ch] [ebp-1D0h]
  const vostok::render::shader_constant_host *m_order; // [esp-8h] [ebp-1CCh]
  unsigned int v70; // [esp-4h] [ebp-1C8h]
  float v71; // [esp+0h] [ebp-1C4h]
  float v72; // [esp+4h] [ebp-1C0h]
  float v73; // [esp+8h] [ebp-1BCh]
  float v74; // [esp+Ch] [ebp-1B8h]
  vostok::math::float4x4 v75; // [esp+10h] [ebp-1B4h] BYREF
  vostok::math::float4x4 v76; // [esp+50h] [ebp-174h] BYREF
  vostok::math::float4x4 v77; // [esp+90h] [ebp-134h] BYREF
  vostok::math::float4x4 v78; // [esp+D0h] [ebp-F4h] BYREF
  vostok::math::float4x4 v79; // [esp+110h] [ebp-B4h] BYREF
  vostok::math::float3 v80; // [esp+150h] [ebp-74h] BYREF
  int v81; // [esp+15Ch] [ebp-68h]
  vostok::math::float3 v82; // [esp+160h] [ebp-64h] BYREF
  int v83; // [esp+16Ch] [ebp-58h]
  vostok::math::float3 v84; // [esp+170h] [ebp-54h] BYREF
  vostok::math::float3 v85; // [esp+17Ch] [ebp-48h] BYREF
  vostok::math::float3 v86; // [esp+188h] [ebp-3Ch] BYREF
  vostok::math::float3 v87; // [esp+194h] [ebp-30h]
  float v88; // [esp+1A0h] [ebp-24h]
  float v89; // [esp+1A4h] [ebp-20h]
  int *v90; // [esp+1A8h] [ebp-1Ch]
  float v91; // [esp+1ACh] [ebp-18h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v92; // [esp+1B0h] [ebp-14h]
  unsigned int v93; // [esp+1B4h] [ebp-10h]
  vostok::render::render_target *m_quality_levels_count; // [esp+1B8h] [ebp-Ch] BYREF
  vostok::render::render_target *rt; // [esp+1BCh] [ebp-8h] BYREF

  m_object = wszName.m_object;
  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    (pix_event_wrapper_dx11 *)this,
    (pix_event_wrapper_dx11 *)&wszName.m_object + 3,
    (int)L"render_ambient_lights");
  v3 = (vostok::render::renderer_context *)m_object->m_name.m_pointer.m_object;
  m_next_in_increase_quality_queue = (vostok::render::render_target *)v3->m_scene_view.m_object[231].m_next_in_increase_quality_queue;
  m_quality_levels_count = (vostok::render::render_target *)v3->m_scene_view.m_object[231].m_quality_levels_count;
  wszName.m_object = m_next_in_increase_quality_queue;
  v5 = vostok::render::renderer_context::get_rt(
         v3,
         rt_accumulator_ambient_lights,
         (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v5->m_object,
    0,
    0,
    0);
  v8 = rt;
  if ( rt )
  {
    --rt->m_reference_count;
    if ( !v8->m_reference_count )
    {
      vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    }
  }
  v9 = *(_DWORD *)(LODWORD(z) + 7440);
  v10 = *(_DWORD *)(LODWORD(z) + 7384) == v9;
  *(_DWORD *)(LODWORD(z) + 7384) = v9;
  LOBYTE(v7) = !v10;
  *(_BYTE *)(LODWORD(z) + 117) |= !v10;
  v92.m_object = (vostok::render::render_target *)&m_object->m_name.m_pointer.m_object[1308].next_in_hashset;
  v11 = wszName.m_object;
  if ( wszName.m_object != m_quality_levels_count )
  {
    while ( 1 )
    {
      m_reference_count = v11->m_reference_count;
      v10 = *(_DWORD *)(m_reference_count + 108) == 0;
      v13 = *(float *)(m_reference_count + 96);
      v93 = m_reference_count;
      if ( v10 )
      {
        v86.x = v13;
        v86.y = v13;
        v86.z = v13;
        rt = (vostok::render::render_target *)vostok::math::create_translation(
                                                (const vostok::math::float3 *)(m_reference_count + 68),
                                                &v75);
        v14 = vostok::math::create_scale(&v86, &v76);
        vostok::math::mul4x3((const vostok::math::float4x4 *)rt, v14, &v77);
        v15 = &v77;
      }
      else
      {
        v15 = (vostok::math::float4x4 *)(m_reference_count + 4);
      }
      v70 = (unsigned int)m_object->m_name.m_pointer.m_object;
      qmemcpy(&v79, v15, sizeof(v79));
      vostok::render::renderer_context::set_w(&v79, (vostok::render::renderer_context *)v70);
      m_surface_3d = m_object->m_surface_3d;
      v18 = 0;
      m_surface_3d[5512].lpVtbl = 0;
      QueryInterface = (vostok::render::res_pass *)m_surface_3d[5513].QueryInterface;
      v20 = 0;
      if ( QueryInterface )
      {
        v20 = QueryInterface;
        ++QueryInterface->m_reference_count;
      }
      v21 = (_DWORD *)v20->m_vs.m_object->m_reference_count;
      if ( v21 )
      {
        v18 = (vostok::render::res_pass *)v20->m_vs.m_object->m_reference_count;
        ++*v21;
      }
      vostok::render::res_pass::apply(v16, (int)v18);
      if ( v18 )
      {
        if ( !--v18->m_reference_count )
          vostok::render::effect_manager::delete_pass(
            v22,
            (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
            v18);
      }
      if ( !--v20->m_reference_count )
      {
        vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v20);
        v22 = (vostok::render::effect_manager *)v70;
      }
      if ( *(_DWORD *)(v93 + 108) )
      {
        vostok::render::res_geometry::apply((vostok::render::res_geometry *)v22, m_object[3].m_format);
        v70 = 0;
        m_order = 0;
        v68.m_object = (vostok::render::render_target *)4;
        v24 = 36;
      }
      else
      {
        vostok::render::res_geometry::apply((vostok::render::res_geometry *)v22, (int)m_object[3].m_texture.m_object);
        v70 = 0;
        m_order = 0;
        v68.m_object = (vostok::render::render_target *)4;
        v24 = 540;
      }
      vostok::render::backend::render_indexed(
        (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        v24,
        v23,
        (D3D_PRIMITIVE_TOPOLOGY)v68.m_object,
        (unsigned int)m_order,
        v70);
      v25 = v93;
      v26 = *(float *)(v93 + 92);
      v27 = (int)m_object[3].m_texture.m_object;
      v89 = *(float *)(v93 + 80) * v26;
      v91 = *(float *)(v93 + 84) * v26;
      v88 = *(float *)(v93 + 88) * v26;
      vostok::render::res_geometry::apply(v28, v27);
      v10 = *(_BYTE *)(v25 + 114) == 0;
      v29 = m_object->m_name.m_pointer.m_object;
      v30 = *(float *)(v25 + 72);
      v31 = *(float *)(v25 + 76);
      v32 = *(float *)(v25 + 68);
      v33 = *(unsigned __int8 *)(v25 + 113);
      v34 = *(float *)&v29[1220].m_length;
      v87.x = (float)((float)((float)(*(float *)&v29[1220].next_in_hashset * v30)
                            + (float)(*(float *)&v29[1221].next_in_hashset * v31))
                    + (float)(v32 * *(float *)&v29[1219].next_in_hashset))
            + *(float *)&v29[1222].next_in_hashset;
      v87.y = (float)((float)((float)(*(float *)&v29[1219].m_length * v32) + (float)(v34 * v30))
                    + (float)(*(float *)&v29[1221].m_length * v31))
            + *(float *)&v29[1222].m_length;
      v87.z = (float)((float)((float)(*(float *)&v29[1219].m_checksum * v32)
                            + (float)(*(float *)&v29[1220].m_checksum * v30))
                    + (float)(*(float *)&v29[1221].m_checksum * v31))
            + *(float *)&v29[1222].m_checksum;
      if ( !v10 )
        v33 = 2;
      vostok::math::mul4x3((const vostok::math::float4x4 *)&v29[1219].next_in_hashset, &v79, &v78);
      vostok::math::float4x4::try_invert(&v78, &v78);
      vostok::math::float4x4::get_scale(&v79, &v84);
      v35 = *(_DWORD *)(v25 + 108);
      v36 = *(_BYTE *)(v25 + 115) != 0;
      if ( v35 > 0 )
      {
        if ( v35 > 1 )
          v35 = 1;
      }
      else
      {
        v35 = 0;
      }
      rt = 0;
      v82 = v87;
      *(_QWORD *)&v80.x = __PAIR64__(LODWORD(v91), LODWORD(v89));
      v90 = (int *)(&m_object->m_memory_usage + 4 * v33 + 2 * v36 + v35 + 1);
      v80.z = v88;
      while ( 1 )
      {
        vostok::render::res_effect::apply((vostok::render::res_effect *)rt, *v90);
        v37 = *(_DWORD *)(v25 + 96);
        v38 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        v70 = (unsigned int)&v82;
        m_order = (const vostok::render::shader_constant_host *)*(&m_object[1].m_memory_usage + 1);
        v83 = v37;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v39,
          (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          m_order,
          &v82);
        v40 = v93;
        v41 = *(_DWORD *)(v93 + 100);
        v70 = (unsigned int)&v80;
        m_order = (const vostok::render::shader_constant_host *)m_object[1].m_order;
        v81 = v41;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v42,
          (vostok::render::constants_handler<1> *)LODWORD(v38),
          m_order,
          &v80);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v43,
          (vostok::render::constants_handler<1> *)LODWORD(v38),
          (const vostok::render::shader_constant_host *)HIDWORD(m_object[1].m_order),
          (const vostok::math::float3 *)v92.m_object);
        if ( *(_DWORD *)(v40 + 108) )
        {
          v47 = vostok::math::transpose(&v78, &v76);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v48,
            (vostok::render::constants_handler<1> *)LODWORD(v38),
            (const vostok::render::shader_constant_host *)HIDWORD(m_object[2].m_order),
            (const vostok::math::float3 *)v47);
          v49 = *(float *)(v40 + 104);
          v70 = (unsigned int)&v85;
          m_order = *(const vostok::render::shader_constant_host **)&m_object[2].m_is_registered;
          v85.x = v49 / v84.x;
          v85.y = v49 / v84.y;
          v85.z = v49 / v84.z;
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v50,
            (vostok::render::constants_handler<1> *)LODWORD(v38),
            m_order,
            &v85);
          vostok::render::res_geometry::apply(v51, m_object[3].m_format);
          v70 = 0;
          m_order = 0;
          v68.m_object = (vostok::render::render_target *)4;
          v46 = 36;
        }
        else
        {
          vostok::render::res_geometry::apply(v44, (int)m_object[3].m_texture.m_object);
          v70 = 0;
          m_order = 0;
          v68.m_object = (vostok::render::render_target *)4;
          v46 = 540;
        }
        vostok::render::backend::render_indexed(
          (vostok::render::backend *)LODWORD(v38),
          v46,
          v45,
          (D3D_PRIMITIVE_TOPOLOGY)v68.m_object,
          (unsigned int)m_order,
          v70);
        rt = (vostok::render::render_target *)((char *)rt + 1);
        if ( (unsigned int)rt >= 2 )
          break;
        v25 = v93;
      }
      wszName.m_object = (vostok::render::render_target *)((char *)wszName.m_object + 4);
      if ( wszName.m_object == m_quality_levels_count )
        break;
      v11 = wszName.m_object;
    }
  }
  v52 = m_object[1].m_texture.m_object;
  v53 = 0;
  *(_DWORD *)&v52[47].m_name.m_string.m_buffer[252] = 0;
  v54 = **(vostok::render::res_pass ***)&v52[47].m_name.m_string.m_buffer[256];
  v55 = 0;
  if ( v54 )
  {
    v55 = v54;
    ++v54->m_reference_count;
  }
  v56 = (_DWORD *)v55->m_vs.m_object->m_reference_count;
  if ( v56 )
  {
    v53 = (vostok::render::res_pass *)v55->m_vs.m_object->m_reference_count;
    ++*v56;
  }
  vostok::render::res_pass::apply(v7, (int)v53);
  if ( v53 )
  {
    if ( !--v53->m_reference_count )
      vostok::render::effect_manager::delete_pass(
        v57,
        (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
        v53);
  }
  if ( !--v55->m_reference_count )
    vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v55);
  v70 = 1;
  m_order = 0;
  v68.m_object = 0;
  v67 = 0;
  v58 = vostok::render::renderer_context::get_rt(
          (vostok::render::renderer_context *)m_object->m_name.m_pointer.m_object,
          rt_accumulator_specular,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&m_quality_levels_count)->m_object;
  v59 = vostok::render::renderer_context::get_rt(
          (vostok::render::renderer_context *)m_object->m_name.m_pointer.m_object,
          rt_accumulator_diffuse,
          &wszName)->m_object;
  v66.m_object = v60;
  v92.m_object = (vostok::render::render_target *)vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v66,
    v58);
  v65.m_object = v61;
  v64 = (vostok::render::system_renderer *)v61;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v65,
    v59);
  vostok::render::system_renderer::fill_surface(
    v64,
    v92,
    v65.m_object,
    v66.m_object,
    v67,
    v68,
    (vostok::render::render_target *)m_order,
    (D3D11_VIEWPORT *)v70,
    v71,
    v72,
    v73,
    v74);
  v62 = wszName.m_object;
  if ( wszName.m_object )
  {
    --wszName.m_object->m_reference_count;
    if ( !v62->m_reference_count )
      vostok::render::resource_manager::release(
        wszName.m_object,
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  v63 = m_quality_levels_count;
  if ( m_quality_levels_count )
  {
    --m_quality_levels_count->m_reference_count;
    if ( !v63->m_reference_count )
      vostok::render::resource_manager::release(
        m_quality_levels_count,
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  D3DPERF_EndEvent();
}
