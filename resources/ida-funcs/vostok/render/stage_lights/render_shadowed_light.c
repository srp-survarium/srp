void __thiscall vostok::render::stage_lights::render_shadowed_light(
        vostok::render::stage_lights *this,
        vostok::render::light *l,
        unsigned int a3)
{
  float x; // eax
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm3_4
  float *v17; // eax
  float *p_z; // esi
  unsigned int v19; // xmm1_4
  unsigned int v20; // xmm2_4
  char v21; // cl
  unsigned int v22; // xmm0_4
  float v23; // xmm2_4
  long double v24; // rdi
  vostok::render::render_surface_instance ***v25; // esi
  vostok::render::backend *v26; // ecx
  int v27; // edi
  vostok::render::stage_lights *v28; // ecx
  vostok::render::render_target *m_object; // edi
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v30; // eax
  float z; // edi
  vostok::render::res_pass *v32; // ecx
  vostok::render::render_target *v33; // eax
  vostok::render::render_target *v34; // eax
  int v35; // esi
  bool v36; // zf
  float v37; // eax
  vostok::render::res_pass *v38; // esi
  vostok::render::res_pass *v39; // eax
  vostok::render::res_pass *v40; // edi
  _DWORD *m_reference_count; // eax
  vostok::render::effect_manager *v42; // ecx
  vostok::render::backend *v43; // ecx
  unsigned int v44; // edi
  int v45; // eax
  int v46; // esi
  vostok::render::backend *v47; // ecx
  vostok::math::float4x4 *v48; // eax
  vostok::render::backend *v49; // ecx
  vostok::render::backend *v50; // ecx
  vostok::render::backend *v51; // ecx
  vostok::render::backend *v52; // ecx
  vostok::render::backend *v53; // ecx
  float v54; // esi
  vostok::render::backend *v55; // ecx
  vostok::render::backend *v56; // ecx
  vostok::render::backend *v57; // ecx
  vostok::render::backend *v58; // ecx
  vostok::render::backend *v59; // ecx
  vostok::render::backend *v60; // ecx
  vostok::render::backend *v61; // ecx
  vostok::render::backend *v62; // ecx
  vostok::render::res_geometry *v63; // ecx
  vostok::render::backend *v64; // ecx
  int z_low; // esi
  vostok::render::backend *v66; // ecx
  vostok::math::float4x4 *v67; // eax
  vostok::render::backend *v68; // ecx
  vostok::render::backend *v69; // ecx
  vostok::render::backend *v70; // ecx
  vostok::render::backend *v71; // ecx
  vostok::render::backend *v72; // ecx
  float v73; // esi
  vostok::render::backend *v74; // ecx
  vostok::render::backend *v75; // ecx
  vostok::render::backend *v76; // ecx
  vostok::render::backend *v77; // ecx
  unsigned int v78; // edi
  float v79; // esi
  vostok::render::backend *v80; // ecx
  vostok::render::backend *v81; // ecx
  vostok::render::backend *v82; // ecx
  vostok::render::backend *v83; // ecx
  vostok::render::res_geometry *v84; // ecx
  vostok::render::backend *v85; // ecx
  int v86; // esi
  vostok::render::backend *v87; // ecx
  vostok::math::float4x4 *v88; // eax
  vostok::render::backend *v89; // ecx
  vostok::render::backend *v90; // ecx
  vostok::render::backend *v91; // ecx
  vostok::render::backend *v92; // ecx
  vostok::render::backend *v93; // ecx
  float v94; // esi
  vostok::render::backend *v95; // ecx
  vostok::render::backend *v96; // ecx
  vostok::render::backend *v97; // ecx
  vostok::render::backend *v98; // ecx
  vostok::render::backend *v99; // ecx
  vostok::render::backend *v100; // ecx
  vostok::render::backend *v101; // ecx
  vostok::render::backend *v102; // ecx
  vostok::render::res_geometry *v103; // ecx
  vostok::render::backend *v104; // ecx
  vostok::render::res_pass *v105; // eax
  const vostok::render::render_target *v106; // [esp+Ch] [ebp-204h]
  vostok::render::effect_manager *v107; // [esp+14h] [ebp-1FCh]
  long double v108; // [esp+18h] [ebp-1F8h]
  unsigned int v109; // [esp+18h] [ebp-1F8h]
  vostok::math::float4x4 v110; // [esp+28h] [ebp-1E8h] BYREF
  vostok::math::float4x4 v111; // [esp+68h] [ebp-1A8h] BYREF
  vostok::math::float4x4 v112; // [esp+A8h] [ebp-168h] BYREF
  vostok::math::float4x4 v113; // [esp+E8h] [ebp-128h] BYREF
  vostok::math::float4x4 v114; // [esp+128h] [ebp-E8h] BYREF
  vostok::math::float4x4 v115; // [esp+168h] [ebp-A8h] BYREF
  int v116; // [esp+1A8h] [ebp-68h] BYREF
  vostok::math::float3 v117; // [esp+1ACh] [ebp-64h] BYREF
  vostok::math::float3 v118; // [esp+1B8h] [ebp-58h] BYREF
  vostok::math::float3 v119; // [esp+1C4h] [ebp-4Ch] BYREF
  vostok::math::float3 v120; // [esp+1D0h] [ebp-40h] BYREF
  vostok::math::float3 v121; // [esp+1DCh] [ebp-34h] BYREF
  float v122; // [esp+1E8h] [ebp-28h]
  vostok::render::render_target *v123; // [esp+1ECh] [ebp-24h] BYREF
  vostok::render::render_target *rt; // [esp+1F0h] [ebp-20h] BYREF
  vostok::render::res_texture **v125; // [esp+1F4h] [ebp-1Ch]
  unsigned int v126; // [esp+1F8h] [ebp-18h]
  float *i; // [esp+1FCh] [ebp-14h]
  unsigned int v128; // [esp+200h] [ebp-10h]
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v129; // [esp+204h] [ebp-Ch] BYREF
  float v130; // [esp+208h] [ebp-8h] BYREF
  vostok::render::res_effect *v131; // [esp+20Ch] [ebp-4h]
  char v132; // [esp+21Bh] [ebp+Bh]

  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    (pix_event_wrapper_dx11 *)this,
    (pix_event_wrapper_dx11 *)&a3 + 3,
    (int)L"render_shadowed_light");
  if ( *(float *)(a3 + 608) <= 0.1 )
    v130 = FLOAT_0_1;
  else
    v130 = *(float *)(a3 + 608);
  x = l->m_view_to_light[0].i.x;
  v5 = *(float *)(a3 + 536);
  v6 = *(float *)(a3 + 540);
  v7 = *(float *)(a3 + 532);
  v8 = *(float *)(LODWORD(x) + 19524);
  v9 = *(float *)(LODWORD(x) + 19540);
  LODWORD(x) += 19508;
  v10 = (float)((float)((float)(v8 * v5) + (float)(v9 * v6)) + (float)(v7 * *(float *)LODWORD(x)))
      + *(float *)(LODWORD(x) + 48);
  v11 = *(float *)(LODWORD(x) + 20);
  v121.y = v10;
  v121.z = (float)((float)((float)(*(float *)(LODWORD(x) + 4) * v7) + (float)(v11 * v5))
                 + (float)(*(float *)(LODWORD(x) + 36) * v6))
         + *(float *)(LODWORD(x) + 52);
  v12 = *(float *)(LODWORD(x) + 8) * v7;
  v13 = *(float *)(LODWORD(x) + 24);
  v117.x = *(float *)(a3 + 516);
  v14 = v13 * v5;
  v15 = *(float *)(LODWORD(x) + 40) * v6;
  v117.y = *(float *)(a3 + 520);
  v16 = (float)((float)(v12 + v14) + v15) + *(float *)(LODWORD(x) + 56);
  v117.z = *(float *)(a3 + 524);
  v122 = v16;
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v129,
    (const vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&l[2].m_view_to_light[5].lines[3].elements[3]);
  v128 = 0;
  __libm_sse2_tan(v108);
  v17 = (float *)a3;
  v126 = 0;
  p_z = &view_matrix_parameters[0][1].z;
  v119.x = (float)0.7853981852531433 * v130;
  v119.y = v119.x;
  v119.z = v130;
  v125 = (vostok::render::res_texture **)(a3 + 724);
  for ( i = &view_matrix_parameters[0][1].z; ; p_z = i )
  {
    *(float *)&v19 = v17[134] + *(p_z - 1);
    *(float *)&v20 = v17[135] + *p_z;
    v21 = *((_BYTE *)v17 + v128 + 864);
    v118.x = *(p_z - 2) + v17[133];
    *(float *)&v22 = *(p_z - 5) + v17[133];
    *(_QWORD *)&v118.elements[1] = __PAIR64__(v20, v19);
    v23 = *(p_z - 3) + v17[135];
    v132 = v21;
    *(_QWORD *)&v120.x = __PAIR64__(*(p_z - 4) + v17[134], v22);
    v120.z = v23;
    vostok::math::create_camera_at(&v120, &v118, &v113, (const vostok::math::float3 *)(p_z + 1));
    vostok::math::create_scale(&v119, &v112);
    qmemcpy(&v115, &v113, sizeof(v115));
    vostok::math::float4x4::try_invert(&v115, &v115);
    vostok::math::mul4x3(&v115, &v112, &v114);
    qmemcpy(&v115, &v114, sizeof(v115));
    HIDWORD(v24) = &v115;
    LODWORD(v24) = &v116;
    if ( v132 )
    {
      vostok::math::create_perspective_projection(
        v24,
        1.8849558,
        (vostok::math *)&v114,
        COERCE_STRUCT_VOSTOK_MATH_FLOAT4X4_(1.0),
        s_shadow_z_near_value,
        v130);
      v25 = (vostok::render::render_surface_instance ***)(a3 + 900);
      v26 = *(vostok::render::backend **)(a3 + 900);
      v27 = 1024 >> (char)v26;
      vostok::render::backend::flush_rt_shader_resources(
        v26,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
      vostok::render::stage_lights::render_to_hw_shadowmap(
        v28,
        l,
        a3,
        *(float *)(a3 + 848),
        (const vostok::math::float4x4 *)v27,
        *v25,
        &v113,
        &v114,
        v128,
        v109);
    }
    vostok::render::renderer_context::set_w(
      &v115,
      (vostok::render::renderer_context *)LODWORD(l->m_view_to_light[0].i.x));
    m_object = vostok::render::renderer_context::get_rt(
                 (vostok::render::renderer_context *)LODWORD(l->m_view_to_light[0].i.x),
                 rt_accumulator_specular,
                 (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v123)->m_object;
    v30 = vostok::render::renderer_context::get_rt(
            (vostok::render::renderer_context *)LODWORD(l->m_view_to_light[0].i.x),
            rt_accumulator_diffuse,
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
    v106 = m_object;
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v30->m_object,
      v106,
      0,
      0);
    v33 = rt;
    if ( rt )
    {
      --rt->m_reference_count;
      if ( !v33->m_reference_count )
      {
        vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
        z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      }
    }
    v34 = v123;
    if ( v123 )
    {
      --v123->m_reference_count;
      if ( !v34->m_reference_count )
      {
        vostok::render::resource_manager::release(
          v123,
          vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
        z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      }
    }
    v35 = *(_DWORD *)(LODWORD(z) + 7440);
    v36 = *(_DWORD *)(LODWORD(z) + 7384) == v35;
    *(_DWORD *)(LODWORD(z) + 7384) = v35;
    *(_BYTE *)(LODWORD(z) + 117) |= !v36;
    v37 = l[2].m_view_to_light[4].k.z;
    v38 = 0;
    *(_DWORD *)(LODWORD(v37) + 22048) = 0;
    v39 = **(vostok::render::res_pass ***)(LODWORD(v37) + 22052);
    v40 = 0;
    if ( v39 )
    {
      v40 = v39;
      ++v39->m_reference_count;
    }
    m_reference_count = (_DWORD *)v40->m_vs.m_object->m_reference_count;
    if ( m_reference_count )
    {
      v38 = (vostok::render::res_pass *)v40->m_vs.m_object->m_reference_count;
      ++*m_reference_count;
    }
    LOBYTE(v32) = !v36;
    vostok::render::res_pass::apply(v32, (int)v38);
    if ( v38 )
    {
      if ( !--v38->m_reference_count )
        vostok::render::effect_manager::delete_pass(
          v42,
          (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
          v38);
    }
    if ( !--v40->m_reference_count )
    {
      vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v40);
      v42 = v107;
    }
    vostok::render::res_geometry::apply((vostok::render::res_geometry *)v42, (int)v129.m_object);
    vostok::render::backend::render_indexed(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      0x12u,
      v43,
      D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
      0,
      0);
    v44 = a3;
    v45 = *(_DWORD *)(a3 + 860) & 0xF;
    v131 = 0;
    if ( v45 )
    {
      if ( v45 == 2 )
      {
        while ( 1 )
        {
          if ( v132 )
          {
            vostok::render::res_effect::apply(v131, LODWORD(l[2].m_view_to_light[5].i.z));
            z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v66,
              (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
              (const vostok::render::shader_constant_host *)l[2].m_lod,
              (const vostok::math::float3 *)(v44 + 612));
            v67 = vostok::math::transpose(
                    (const vostok::math::float4x4 *)&l[2].previous_static_shadow_visible_objects_count[2],
                    &v113);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v68,
              (vostok::render::constants_handler<1> *)z_low,
              (const vostok::render::shader_constant_host *)LODWORD(l[2].attenuation_power),
              (const vostok::math::float3 *)v67);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v69,
              (vostok::render::constants_handler<1> *)z_low,
              (const vostok::render::shader_constant_host *)LODWORD(l[2].range),
              (const vostok::math::float3 *)&l[2].m_color_curve.curve_value_min);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v70,
              (vostok::render::constants_handler<1> *)z_low,
              (const vostok::render::shader_constant_host *)LODWORD(l[2].shadow_transparency),
              (const vostok::math::float3 *)&l[2].m_color_curve.curve_value_min.elements[1]);
            vostok::render::backend::set_ps_texture(
              v71,
              z_low,
              "shadowmap_texture",
              *((vostok::render::res_texture **)&l->m_view_to_light[2].i.y + *(_DWORD *)(v44 + 900)));
          }
          else
          {
            vostok::render::res_effect::apply(v131, LODWORD(l[2].m_view_to_light[5].i.y));
          }
          v73 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v72,
            (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            (const vostok::render::shader_constant_host *)LODWORD(l[2].color.y),
            (vostok::math::float3 *)&v121.elements[1]);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v74,
            (vostok::render::constants_handler<1> *)LODWORD(v73),
            (const vostok::render::shader_constant_host *)LODWORD(l[2].position.x),
            (const vostok::math::float3 *)&v130);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v75,
            (vostok::render::constants_handler<1> *)LODWORD(v73),
            (const vostok::render::shader_constant_host *)LODWORD(l[2].intensity),
            (const vostok::math::float3 *)(v44 + 604));
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v76,
            (vostok::render::constants_handler<1> *)LODWORD(v73),
            (const vostok::render::shader_constant_host *)LODWORD(l[2].spot_umbra_angle),
            (const vostok::math::float3 *)(v44 + 828));
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v77,
            (vostok::render::constants_handler<1> *)LODWORD(v73),
            (const vostok::render::shader_constant_host *)LODWORD(l[2].direction.x),
            (const vostok::math::float3 *)(v44 + 832));
          qmemcpy(&v111, (const void *)(v44 + 388), sizeof(v111));
          v78 = a3;
          vostok::math::float4x4::set_scale(&v111, (const vostok::math::float3 *)(a3 + 592));
          vostok::math::mul4x3(
            (const vostok::math::float4x4 *)(LODWORD(l->m_view_to_light[0].i.x) + 19508),
            &v111,
            &v114);
          v79 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v80,
            (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            (const vostok::render::shader_constant_host *)LODWORD(l[2].scale.x),
            (const vostok::math::float3 *)&v114);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v81,
            (vostok::render::constants_handler<1> *)LODWORD(v79),
            (const vostok::render::shader_constant_host *)LODWORD(l[2].m_plane_spot_xform.c.w),
            &v117);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v82,
            (vostok::render::constants_handler<1> *)LODWORD(v79),
            (const vostok::render::shader_constant_host *)LODWORD(l[2].color.x),
            (const vostok::math::float3 *)(v78 + 528));
          vostok::render::backend::set_ps_constant<unsigned int>(
            (vostok::render::backend *)LODWORD(v79),
            (const vostok::render::shader_constant_host *)l[2].previous_static_shadow_visible_objects_count[0],
            (const int *)(v78 + 856));
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v83,
            (vostok::render::constants_handler<1> *)LODWORD(v79),
            (const vostok::render::shader_constant_host *)LODWORD(l[2].scale.y),
            (const vostok::math::float3 *)(LODWORD(l->m_view_to_light[0].i.x) + 20932));
          vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
            (vostok::render::backend *)LODWORD(v79),
            (const vostok::render::shader_constant_host *)LODWORD(l[2].scale.z),
            (const unsigned int *)(LODWORD(l->m_view_to_light[0].i.x) + 16224));
          vostok::render::res_geometry::apply(v84, (int)v129.m_object);
          vostok::render::backend::render_indexed(
            (vostok::render::backend *)LODWORD(v79),
            0x12u,
            v85,
            D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
            0,
            0);
          v131 = (vostok::render::res_effect *)((char *)v131 + 1);
          if ( (unsigned int)v131 >= 2 )
            break;
          v44 = a3;
        }
      }
      else
      {
        while ( 1 )
        {
          if ( v132 )
          {
            vostok::render::res_effect::apply(v131, LODWORD(l[2].m_view_to_light[5].j.x));
            v46 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v47,
              (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
              (const vostok::render::shader_constant_host *)l[2].m_lod,
              (const vostok::math::float3 *)(v44 + 612));
            v48 = vostok::math::transpose(
                    (const vostok::math::float4x4 *)&l[2].previous_static_shadow_visible_objects_count[2],
                    &v112);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v49,
              (vostok::render::constants_handler<1> *)v46,
              (const vostok::render::shader_constant_host *)LODWORD(l[2].attenuation_power),
              (const vostok::math::float3 *)v48);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v50,
              (vostok::render::constants_handler<1> *)v46,
              (const vostok::render::shader_constant_host *)LODWORD(l[2].range),
              (const vostok::math::float3 *)&l[2].m_color_curve.curve_value_min);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v51,
              (vostok::render::constants_handler<1> *)v46,
              (const vostok::render::shader_constant_host *)LODWORD(l[2].shadow_transparency),
              (const vostok::math::float3 *)&l[2].m_color_curve.curve_value_min.elements[1]);
            vostok::render::backend::set_ps_texture(
              v52,
              v46,
              "shadowmap_texture",
              *((vostok::render::res_texture **)&l->m_view_to_light[2].i.y + *(_DWORD *)(v44 + 900)));
          }
          else
          {
            vostok::render::res_effect::apply(v131, LODWORD(l[2].m_view_to_light[5].i.w));
          }
          v54 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v53,
            (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            (const vostok::render::shader_constant_host *)LODWORD(l[2].color.y),
            (vostok::math::float3 *)&v121.elements[1]);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v55,
            (vostok::render::constants_handler<1> *)LODWORD(v54),
            (const vostok::render::shader_constant_host *)LODWORD(l[2].position.x),
            (const vostok::math::float3 *)&v130);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v56,
            (vostok::render::constants_handler<1> *)LODWORD(v54),
            (const vostok::render::shader_constant_host *)LODWORD(l[2].intensity),
            (const vostok::math::float3 *)(v44 + 604));
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v57,
            (vostok::render::constants_handler<1> *)LODWORD(v54),
            (const vostok::render::shader_constant_host *)LODWORD(l[2].spot_umbra_angle),
            (const vostok::math::float3 *)(v44 + 828));
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v58,
            (vostok::render::constants_handler<1> *)LODWORD(v54),
            (const vostok::render::shader_constant_host *)LODWORD(l[2].direction.x),
            (const vostok::math::float3 *)(v44 + 832));
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v59,
            (vostok::render::constants_handler<1> *)LODWORD(v54),
            (const vostok::render::shader_constant_host *)LODWORD(l[2].spot_falloff),
            (const vostok::math::float3 *)(v44 + 592));
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v60,
            (vostok::render::constants_handler<1> *)LODWORD(v54),
            (const vostok::render::shader_constant_host *)LODWORD(l[2].m_plane_spot_xform.c.w),
            &v117);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v61,
            (vostok::render::constants_handler<1> *)LODWORD(v54),
            (const vostok::render::shader_constant_host *)LODWORD(l[2].color.x),
            (const vostok::math::float3 *)(v44 + 528));
          vostok::render::backend::set_ps_constant<unsigned int>(
            (vostok::render::backend *)LODWORD(v54),
            (const vostok::render::shader_constant_host *)l[2].previous_static_shadow_visible_objects_count[0],
            (const int *)(v44 + 856));
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v62,
            (vostok::render::constants_handler<1> *)LODWORD(v54),
            (const vostok::render::shader_constant_host *)LODWORD(l[2].scale.y),
            (const vostok::math::float3 *)(LODWORD(l->m_view_to_light[0].i.x) + 20932));
          vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
            (vostok::render::backend *)LODWORD(v54),
            (const vostok::render::shader_constant_host *)LODWORD(l[2].scale.z),
            (const unsigned int *)(LODWORD(l->m_view_to_light[0].i.x) + 16224));
          vostok::render::res_geometry::apply(v63, (int)v129.m_object);
          vostok::render::backend::render_indexed(
            (vostok::render::backend *)LODWORD(v54),
            0x12u,
            v64,
            D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
            0,
            0);
          v131 = (vostok::render::res_effect *)((char *)v131 + 1);
          if ( (unsigned int)v131 >= 2 )
            break;
          v44 = a3;
        }
      }
    }
    else
    {
      v121.x = 0.0;
      while ( 1 )
      {
        if ( v132 )
        {
          vostok::render::res_effect::apply(v131, LODWORD(l[2].m_view_to_light[4].c.y));
          v86 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v87,
            (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            (const vostok::render::shader_constant_host *)l[2].m_lod,
            (const vostok::math::float3 *)(v44 + 612));
          v88 = vostok::math::transpose(
                  (const vostok::math::float4x4 *)&l[2].previous_static_shadow_visible_objects_count[2],
                  &v110);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v89,
            (vostok::render::constants_handler<1> *)v86,
            (const vostok::render::shader_constant_host *)LODWORD(l[2].attenuation_power),
            (const vostok::math::float3 *)v88);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v90,
            (vostok::render::constants_handler<1> *)v86,
            (const vostok::render::shader_constant_host *)LODWORD(l[2].range),
            (const vostok::math::float3 *)&l[2].m_color_curve.curve_value_min);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v91,
            (vostok::render::constants_handler<1> *)v86,
            (const vostok::render::shader_constant_host *)LODWORD(l[2].shadow_transparency),
            (const vostok::math::float3 *)&l[2].m_color_curve.curve_value_min.elements[1]);
          if ( *(_BYTE *)(v44 + 625) )
            vostok::render::backend::set_ps_texture(v92, v86, "shadowmap_texture", *v125);
          else
            vostok::render::backend::set_ps_texture(
              v92,
              v86,
              "shadowmap_texture",
              *((vostok::render::res_texture **)&l->m_view_to_light[2].i.y + *(_DWORD *)(v44 + 900)));
        }
        else
        {
          vostok::render::res_effect::apply(v131, LODWORD(l[2].m_view_to_light[4].c.x));
        }
        v94 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v93,
          (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::render::shader_constant_host *)LODWORD(l[2].color.y),
          (vostok::math::float3 *)&v121.elements[1]);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v95,
          (vostok::render::constants_handler<1> *)LODWORD(v94),
          (const vostok::render::shader_constant_host *)LODWORD(l[2].position.x),
          (const vostok::math::float3 *)(v44 + 608));
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v96,
          (vostok::render::constants_handler<1> *)LODWORD(v94),
          (const vostok::render::shader_constant_host *)LODWORD(l[2].intensity),
          (const vostok::math::float3 *)(v44 + 604));
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v97,
          (vostok::render::constants_handler<1> *)LODWORD(v94),
          (const vostok::render::shader_constant_host *)LODWORD(l[2].spot_umbra_angle),
          (const vostok::math::float3 *)(v44 + 828));
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v98,
          (vostok::render::constants_handler<1> *)LODWORD(v94),
          (const vostok::render::shader_constant_host *)LODWORD(l[2].direction.x),
          (const vostok::math::float3 *)(v44 + 832));
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v99,
          (vostok::render::constants_handler<1> *)LODWORD(v94),
          (const vostok::render::shader_constant_host *)LODWORD(l[2].direction.y),
          &v121);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v100,
          (vostok::render::constants_handler<1> *)LODWORD(v94),
          (const vostok::render::shader_constant_host *)LODWORD(l[2].m_plane_spot_xform.c.w),
          &v117);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v101,
          (vostok::render::constants_handler<1> *)LODWORD(v94),
          (const vostok::render::shader_constant_host *)LODWORD(l[2].color.x),
          (const vostok::math::float3 *)(v44 + 528));
        vostok::render::backend::set_ps_constant<unsigned int>(
          (vostok::render::backend *)LODWORD(v94),
          (const vostok::render::shader_constant_host *)l[2].previous_static_shadow_visible_objects_count[0],
          (const int *)(v44 + 856));
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v102,
          (vostok::render::constants_handler<1> *)LODWORD(v94),
          (const vostok::render::shader_constant_host *)LODWORD(l[2].scale.y),
          (const vostok::math::float3 *)(LODWORD(l->m_view_to_light[0].i.x) + 20932));
        vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
          (vostok::render::backend *)LODWORD(v94),
          (const vostok::render::shader_constant_host *)LODWORD(l[2].scale.z),
          (const unsigned int *)(LODWORD(l->m_view_to_light[0].i.x) + 16224));
        vostok::render::res_geometry::apply(v103, (int)v129.m_object);
        vostok::render::backend::render_indexed(
          (vostok::render::backend *)LODWORD(v94),
          0x12u,
          v104,
          D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
          0,
          0);
        v131 = (vostok::render::res_effect *)((char *)v131 + 1);
        if ( (unsigned int)v131 >= 2 )
          break;
        v44 = a3;
      }
    }
    v126 += 36;
    ++v128;
    i += 9;
    ++v125;
    if ( v126 >= 0xD8 )
      break;
    v17 = (float *)a3;
  }
  v105 = (vostok::render::res_pass *)v129.m_object;
  if ( v129.m_object )
  {
    v36 = v129.m_object->m_reference_count-- == 1;
    if ( v36 )
      vostok::render::resource_manager::release(vostok::quasi_singleton<vostok::render::resource_manager>::pinst, v105);
  }
  D3DPERF_EndEvent();
}
