void __thiscall vostok::render::stage_lights::render_light(
        vostok::render::stage_lights *this,
        vostok::render::res_geometry *l,
        vostok::render::light *shadowers_pass)
{
  vostok::render::res_geometry *v3; // ebx
  vostok::render::light *v4; // ecx
  vostok::render::light *v5; // esi
  int v6; // eax
  vostok::render::stage_lights *v7; // ecx
  float range; // xmm0_4
  float *p_m_reference_count; // eax
  float v10; // xmm3_4
  float v11; // xmm4_4
  float *p_x; // esi
  long double v13; // rdi
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v26; // ecx
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  const vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_m_ib; // eax
  vostok::render::stage_lights *v33; // ecx
  vostok::render::render_target *v34; // esi
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v35; // eax
  float v36; // esi
  vostok::render::res_effect *v37; // ecx
  vostok::render::render_target *v38; // eax
  float v39; // eax
  int v40; // edi
  bool v41; // zf
  int v42; // eax
  vostok::render::res_geometry *v43; // ecx
  vostok::render::light *v44; // edi
  vostok::render::light *v45; // ecx
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  vostok::math::float4x4 *v50; // eax
  int z_low; // esi
  vostok::render::backend *v52; // ecx
  vostok::render::backend *v53; // ecx
  vostok::render::backend *v54; // ecx
  vostok::render::backend *v55; // ecx
  vostok::render::backend *v56; // ecx
  vostok::render::backend *v57; // ecx
  float v58; // esi
  vostok::render::backend *v59; // ecx
  __m128 spot_penumbra_angle_low; // xmm0
  __m128i v61; // xmm0
  vostok::render::backend *v62; // ecx
  vostok::render::backend *v63; // ecx
  vostok::render::backend *v64; // ecx
  vostok::render::backend *v65; // ecx
  vostok::render::backend *v66; // ecx
  vostok::render::backend *v67; // ecx
  vostok::render::backend *v68; // ecx
  vostok::render::backend *v69; // ecx
  float v70; // xmm0_4
  vostok::render::backend *v71; // ecx
  vostok::math::float4x4 *v72; // eax
  vostok::render::backend *v73; // ecx
  vostok::render::backend *v74; // ecx
  vostok::render::backend *v75; // ecx
  vostok::render::backend *v76; // ecx
  vostok::render::res_geometry *v77; // ecx
  float v78; // esi
  vostok::render::backend *v79; // ecx
  vostok::render::backend *v80; // ecx
  vostok::render::backend *v81; // ecx
  vostok::render::backend *v82; // ecx
  vostok::render::backend *v83; // ecx
  vostok::render::backend *v84; // ecx
  vostok::render::backend *v85; // ecx
  vostok::render::backend *v86; // ecx
  vostok::render::backend *v87; // ecx
  vostok::render::backend *v88; // ecx
  vostok::render::res_geometry *v89; // ecx
  float v90; // esi
  vostok::render::backend *v91; // ecx
  vostok::render::backend *v92; // ecx
  vostok::render::backend *v93; // ecx
  vostok::render::backend *v94; // ecx
  vostok::render::backend *v95; // ecx
  vostok::render::backend *v96; // ecx
  vostok::render::backend *v97; // ecx
  vostok::render::backend *v98; // ecx
  vostok::render::backend *v99; // ecx
  vostok::render::backend *v100; // ecx
  vostok::render::backend *v101; // ecx
  vostok::render::backend *v102; // ecx
  vostok::render::res_geometry *v103; // ecx
  float v104; // esi
  vostok::render::backend *v105; // ecx
  vostok::render::backend *v106; // ecx
  vostok::render::backend *v107; // ecx
  vostok::render::backend *v108; // ecx
  vostok::render::backend *v109; // ecx
  vostok::render::backend *v110; // ecx
  vostok::render::light *v111; // edi
  float v112; // esi
  vostok::render::backend *v113; // ecx
  vostok::render::backend *v114; // ecx
  vostok::render::backend *v115; // ecx
  vostok::render::backend *v116; // ecx
  vostok::render::res_geometry *v117; // ecx
  int v118; // esi
  vostok::render::backend *v119; // ecx
  vostok::math::float4x4 *v120; // eax
  vostok::render::backend *v121; // ecx
  vostok::render::backend *v122; // ecx
  vostok::render::backend *v123; // ecx
  vostok::render::backend *v124; // ecx
  vostok::render::backend *v125; // ecx
  float v126; // esi
  vostok::render::backend *v127; // ecx
  __m128 v128; // xmm0
  __m128i v129; // xmm0
  vostok::render::backend *v130; // ecx
  vostok::render::backend *v131; // ecx
  vostok::render::backend *v132; // ecx
  vostok::render::backend *v133; // ecx
  vostok::render::backend *v134; // ecx
  vostok::render::backend *v135; // ecx
  vostok::render::backend *v136; // ecx
  vostok::render::backend *v137; // ecx
  float v138; // xmm0_4
  vostok::render::backend *v139; // ecx
  vostok::render::backend *v140; // ecx
  vostok::render::backend *v141; // ecx
  vostok::render::backend *v142; // ecx
  vostok::render::res_geometry *v143; // ecx
  int v144; // eax
  float v145; // esi
  vostok::render::backend *v146; // ecx
  vostok::render::backend *v147; // ecx
  vostok::render::backend *v148; // ecx
  vostok::render::backend *v149; // ecx
  vostok::render::backend *v150; // ecx
  vostok::render::backend *v151; // ecx
  float v152; // xmm0_4
  vostok::render::backend *v153; // ecx
  vostok::render::backend *v154; // ecx
  vostok::render::backend *v155; // ecx
  vostok::render::res_geometry *v156; // ecx
  vostok::render::res_pass *v157; // eax
  const vostok::render::render_target *v158; // [esp-Ch] [ebp-19Ch]
  const vostok::render::shader_constant_host *m_vb_stride; // [esp-8h] [ebp-198h]
  const vostok::render::shader_constant_host *v160; // [esp-8h] [ebp-198h]
  const vostok::render::shader_constant_host *m_reference_count; // [esp-8h] [ebp-198h]
  const vostok::render::shader_constant_host *v162; // [esp-8h] [ebp-198h]
  const vostok::render::shader_constant_host *v163; // [esp-8h] [ebp-198h]
  const vostok::render::shader_constant_host *v164; // [esp-8h] [ebp-198h]
  const vostok::render::shader_constant_host *v165; // [esp-8h] [ebp-198h]
  const vostok::render::shader_constant_host *v166; // [esp-8h] [ebp-198h]
  const vostok::render::shader_constant_host *v167; // [esp-8h] [ebp-198h]
  vostok::render::renderer_context *m_object; // [esp-4h] [ebp-194h]
  long double v169; // [esp+0h] [ebp-190h]
  long double v170; // [esp+0h] [ebp-190h]
  long double v171; // [esp+0h] [ebp-190h]
  vostok::math::float4x4 v172; // [esp+10h] [ebp-180h] BYREF
  vostok::math::float4x4 v173; // [esp+50h] [ebp-140h] BYREF
  vostok::math::float4x4 v174; // [esp+90h] [ebp-100h] BYREF
  vostok::math::float4x4 v175; // [esp+D0h] [ebp-C0h] BYREF
  vostok::math::float4x4 v176; // [esp+110h] [ebp-80h] BYREF
  vostok::math::float3 v177; // [esp+150h] [ebp-40h] BYREF
  vostok::math::float3 v178; // [esp+15Ch] [ebp-34h] BYREF
  vostok::math::float3 v179; // [esp+168h] [ebp-28h] BYREF
  vostok::math::float3 v180; // [esp+174h] [ebp-1Ch] BYREF
  vostok::math::float3 v181; // [esp+180h] [ebp-10h] BYREF
  vostok::render::render_target *rt; // [esp+18Ch] [ebp-4h] BYREF

  v3 = l;
  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    (pix_event_wrapper_dx11 *)this,
    (pix_event_wrapper_dx11 *)&shadowers_pass + 3,
    (int)L"render_light");
  v5 = shadowers_pass;
  if ( shadowers_pass->is_shadower )
    goto LABEL_81;
  v6 = *(_DWORD *)&shadowers_pass->flags & 0xF;
  if ( v6 == 4 )
    goto LABEL_81;
  if ( (!v6 || v6 == 5 || v6 == 2) && vostok::render::light::is_cast_shadows(v4, (int)shadowers_pass) )
  {
    vostok::render::stage_lights::render_shadowed_light(v7, (vostok::render::light *)v3, (unsigned int)v5);
    goto LABEL_81;
  }
  range = v5->range;
  p_m_reference_count = (float *)&v3->m_vb.m_object->m_reference_count;
  v10 = p_m_reference_count[4881];
  v11 = p_m_reference_count[4885];
  p_x = &v5->color.x;
  v178.x = *p_x++;
  v178.y = *p_x++;
  v178.z = *p_x;
  HIDWORD(v13) = p_x + 1;
  LODWORD(v13) = shadowers_pass;
  y = shadowers_pass->position.y;
  x = shadowers_pass->position.x;
  v180.z = range;
  z = shadowers_pass->position.z;
  v17 = (float)((float)((float)(v10 * y) + (float)(v11 * z)) + (float)(p_m_reference_count[4877] * x))
      + p_m_reference_count[4889];
  v18 = p_m_reference_count[4882];
  v179.x = v17;
  v19 = (float)((float)((float)(p_m_reference_count[4878] * x) + (float)(v18 * y))
              + (float)(p_m_reference_count[4886] * z))
      + p_m_reference_count[4890];
  v20 = p_m_reference_count[4885];
  v179.y = v19;
  v179.z = (float)((float)((float)(p_m_reference_count[4879] * x) + (float)(p_m_reference_count[4883] * y))
                 + (float)(p_m_reference_count[4887] * z))
         + p_m_reference_count[4891];
  v21 = shadowers_pass->direction.y;
  v22 = shadowers_pass->direction.z;
  v23 = shadowers_pass->direction.x;
  v24 = (float)((float)(p_m_reference_count[4881] * v21) + (float)(v20 * v22))
      + (float)(v23 * p_m_reference_count[4877]);
  v25 = p_m_reference_count[4882];
  v177.x = v24;
  v177.y = (float)((float)(p_m_reference_count[4878] * v23) + (float)(v25 * v21))
         + (float)(p_m_reference_count[4886] * v22);
  v177.z = (float)((float)(p_m_reference_count[4879] * v23) + (float)(p_m_reference_count[4883] * v21))
         + (float)(p_m_reference_count[4887] * v22);
  vostok::render::light::xform_calc((vostok::render::light *)&shadowers_pass->direction, v13, (int)shadowers_pass);
  m_object = (vostok::render::renderer_context *)v3->m_vb.m_object;
  LODWORD(v181.z) = LODWORD(v13) + 388;
  vostok::render::renderer_context::set_w((const vostok::math::float4x4 *)(LODWORD(v13) + 388), m_object);
  l = 0;
  v27 = *(_DWORD *)(LODWORD(v13) + 860) & 0xF;
  if ( !v27 )
    goto LABEL_16;
  v28 = v27 - 1;
  if ( !v28 )
  {
    p_m_ib = (const vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v3[91].m_ib;
    goto LABEL_17;
  }
  v29 = v28 - 1;
  if ( !v29 || (v30 = v29 - 1) == 0 )
  {
LABEL_14:
    p_m_ib = (const vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v3[91].m_is_registered;
LABEL_17:
    HIDWORD(v13) = &l;
    vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      v26,
      (int *)&l,
      p_m_ib);
    goto LABEL_18;
  }
  v31 = v30 - 2;
  if ( !v31 )
  {
LABEL_16:
    p_m_ib = (const vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v3[90].m_is_registered;
    goto LABEL_17;
  }
  if ( v31 == 1 )
    goto LABEL_14;
LABEL_18:
  if ( (*(_DWORD *)(LODWORD(v13) + 860) & 0xF) == 1 )
  {
    if ( vostok::render::light::is_cast_shadows((vostok::render::light *)v26, SLODWORD(v13)) )
    {
      HIDWORD(v13) = LODWORD(v13);
      vostok::render::stage_lights::make_spot_light_shadowmap(v13, (vostok::render::light *)v3, LODWORD(v169));
    }
  }
  else if ( (*(_DWORD *)(LODWORD(v13) + 860) & 0xF) == 6
         && vostok::render::light::is_cast_shadows((vostok::render::light *)v26, SLODWORD(v13)) )
  {
    vostok::render::stage_lights::make_plane_spot_light_shadowmap(
      v33,
      v13,
      (vostok::render::light *)v3,
      (vostok::render::light *)LODWORD(v13));
  }
  vostok::render::renderer_context::set_w(
    (const vostok::math::float4x4 *)LODWORD(v181.z),
    (vostok::render::renderer_context *)v3->m_vb.m_object);
  v34 = vostok::render::renderer_context::get_rt(
          (vostok::render::renderer_context *)v3->m_vb.m_object,
          rt_accumulator_specular,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v181)->m_object;
  v35 = vostok::render::renderer_context::get_rt(
          (vostok::render::renderer_context *)v3->m_vb.m_object,
          rt_accumulator_diffuse,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
  v158 = v34;
  v36 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v35->m_object,
    v158,
    0,
    0);
  v38 = rt;
  if ( rt )
  {
    --rt->m_reference_count;
    if ( !v38->m_reference_count )
    {
      vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      v36 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    }
  }
  v39 = v181.x;
  if ( LODWORD(v181.x) )
  {
    --*(_DWORD *)LODWORD(v181.x);
    if ( !*(_DWORD *)LODWORD(v39) )
    {
      vostok::render::resource_manager::release(
        (vostok::render::render_target *)LODWORD(v181.x),
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      v36 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    }
  }
  v40 = *(_DWORD *)(LODWORD(v36) + 7440);
  v41 = *(_DWORD *)(LODWORD(v36) + 7384) == v40;
  *(_DWORD *)(LODWORD(v36) + 7384) = v40;
  LOBYTE(v37) = !v41;
  *(_BYTE *)(LODWORD(v36) + 117) |= !v41;
  v42 = *(_DWORD *)&v3[87].m_is_registered;
  *(_DWORD *)(v42 + 22048) = 0;
  vostok::render::res_effect::apply_pass(v37, v42);
  vostok::render::res_geometry::apply(v43, (int)l);
  v44 = shadowers_pass;
  vostok::render::stage_lights::draw_geometry(shadowers_pass, (vostok::render::stage_lights *)LODWORD(v169));
  v45 = 0;
  v46 = *(_DWORD *)&v44->flags & 0xF;
  rt = 0;
  if ( v46 )
  {
    v47 = v46 - 1;
    if ( v47 )
    {
      v48 = v47 - 1;
      if ( v48 )
      {
        v49 = v48 - 1;
        if ( v49 )
        {
          if ( v49 == 2 )
          {
            v181.y = 0.0;
            while ( 1 )
            {
              vostok::render::res_effect::apply((vostok::render::res_effect *)rt, (int)v3[89].m_ib.m_object);
              v78 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v79,
                (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                (const vostok::render::shader_constant_host *)v3[97].m_reference_count,
                &v179);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v80,
                (vostok::render::constants_handler<1> *)LODWORD(v78),
                (const vostok::render::shader_constant_host *)v3[97].m_vb_stride,
                (vostok::math::float3 *)&v180.elements[2]);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v81,
                (vostok::render::constants_handler<1> *)LODWORD(v78),
                (const vostok::render::shader_constant_host *)v3[97].m_ib.m_object,
                (const vostok::math::float3 *)&v44->attenuation_power);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v82,
                (vostok::render::constants_handler<1> *)LODWORD(v78),
                (const vostok::render::shader_constant_host *)v3[98].m_reference_count,
                (const vostok::math::float3 *)&v44->diffuse_influence_factor);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v83,
                (vostok::render::constants_handler<1> *)LODWORD(v78),
                (const vostok::render::shader_constant_host *)v3[98].m_vb.m_object,
                (const vostok::math::float3 *)&v44->specular_influence_factor);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v84,
                (vostok::render::constants_handler<1> *)LODWORD(v78),
                (const vostok::render::shader_constant_host *)v3[98].m_ib.m_object,
                (vostok::math::float3 *)&v181.elements[1]);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v85,
                (vostok::render::constants_handler<1> *)LODWORD(v78),
                *(const vostok::render::shader_constant_host **)&v3[99].m_is_registered,
                &v44->scale);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v86,
                (vostok::render::constants_handler<1> *)LODWORD(v78),
                (const vostok::render::shader_constant_host *)v3[96].m_dcl.m_object,
                &v178);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v87,
                (vostok::render::constants_handler<1> *)LODWORD(v78),
                *(const vostok::render::shader_constant_host **)&v3[96].m_is_registered,
                (const vostok::math::float3 *)&v44->intensity);
              vostok::render::backend::set_ps_constant<unsigned int>(
                (vostok::render::backend *)LODWORD(v78),
                (const vostok::render::shader_constant_host *)v3[101].m_dcl.m_object,
                (const int *)&v44->lighting_model);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v88,
                (vostok::render::constants_handler<1> *)LODWORD(v78),
                (const vostok::render::shader_constant_host *)v3[100].m_vb.m_object,
                (const vostok::math::float3 *)&v3->m_vb.m_object[654].pool_range);
              vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
                (vostok::render::backend *)LODWORD(v78),
                (const vostok::render::shader_constant_host *)v3[100].m_ib.m_object,
                &v3->m_vb.m_object[507].m_reference_count);
              vostok::render::res_geometry::apply(v89, (int)l);
              vostok::render::stage_lights::draw_geometry(shadowers_pass, (vostok::render::stage_lights *)LODWORD(v169));
              rt = (vostok::render::render_target *)((char *)rt + 1);
              if ( (unsigned int)rt >= 2 )
                break;
              v44 = shadowers_pass;
            }
          }
          else
          {
            v180.x = 0.0;
            while ( 1 )
            {
              if ( vostok::render::light::is_cast_shadows(v45, (int)v44) )
              {
                vostok::render::res_effect::apply((vostok::render::res_effect *)rt, *(_DWORD *)&v3[89].m_is_registered);
                v50 = vostok::math::transpose((const vostok::math::float4x4 *)&v3[102], &v173);
                z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
                vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                  v52,
                  (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                  (const vostok::render::shader_constant_host *)v3[100].m_vb_stride,
                  (const vostok::math::float3 *)v50);
                vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                  v53,
                  (vostok::render::constants_handler<1> *)z_low,
                  (const vostok::render::shader_constant_host *)v3[101].m_vb.m_object,
                  (const vostok::math::float3 *)&v44->shadow_transparency);
                vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                  v54,
                  (vostok::render::constants_handler<1> *)z_low,
                  (const vostok::render::shader_constant_host *)v3[100].m_dcl.m_object,
                  (const vostok::math::float3 *)&v3[107].m_ib);
                vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                  v55,
                  (vostok::render::constants_handler<1> *)z_low,
                  *(const vostok::render::shader_constant_host **)&v3[100].m_is_registered,
                  (const vostok::math::float3 *)&v3[107].m_vb_stride);
                vostok::render::backend::set_ps_texture(
                  v56,
                  z_low,
                  "shadowmap_texture",
                  *((vostok::render::res_texture **)&v3[5].m_dcl.m_object + v44->m_quality_shadow_map_size_index));
              }
              else
              {
                vostok::render::res_effect::apply((vostok::render::res_effect *)rt, (int)v3[89].m_dcl.m_object);
              }
              v58 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v57,
                (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                (const vostok::render::shader_constant_host *)v3[97].m_reference_count,
                &v179);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v59,
                (vostok::render::constants_handler<1> *)LODWORD(v58),
                (const vostok::render::shader_constant_host *)v3[97].m_vb.m_object,
                &v177);
              spot_penumbra_angle_low = (__m128)LODWORD(v44->spot_penumbra_angle);
              spot_penumbra_angle_low.m128_f32[0] = spot_penumbra_angle_low.m128_f32[0] * 0.5;
              v61 = (__m128i)_mm_cvtps_pd(spot_penumbra_angle_low);
              __libm_sse2_sin(v61);
              m_vb_stride = (const vostok::render::shader_constant_host *)v3[97].m_vb_stride;
              *(float *)v61.m128i_i32 = *(double *)v61.m128i_i64;
              v180.y = v180.z / *(float *)v61.m128i_i32;
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v62,
                (vostok::render::constants_handler<1> *)LODWORD(v58),
                m_vb_stride,
                (vostok::math::float3 *)&v180.elements[1]);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v63,
                (vostok::render::constants_handler<1> *)LODWORD(v58),
                (const vostok::render::shader_constant_host *)v3[97].m_ib.m_object,
                (const vostok::math::float3 *)&v44->attenuation_power);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v64,
                (vostok::render::constants_handler<1> *)LODWORD(v58),
                (const vostok::render::shader_constant_host *)v3[98].m_reference_count,
                (const vostok::math::float3 *)&v44->diffuse_influence_factor);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v65,
                (vostok::render::constants_handler<1> *)LODWORD(v58),
                (const vostok::render::shader_constant_host *)v3[98].m_vb.m_object,
                (const vostok::math::float3 *)&v44->specular_influence_factor);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v66,
                (vostok::render::constants_handler<1> *)LODWORD(v58),
                (const vostok::render::shader_constant_host *)v3[98].m_ib.m_object,
                &v180);
              *(double *)v61.m128i_i64 = (float)(v44->spot_penumbra_angle * 0.5);
              __libm_sse2_cos(v169);
              v160 = *(const vostok::render::shader_constant_host **)&v3[98].m_is_registered;
              *(float *)v61.m128i_i32 = *(double *)v61.m128i_i64;
              LODWORD(v181.z) = v61.m128i_i32[0];
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v67,
                (vostok::render::constants_handler<1> *)LODWORD(v58),
                v160,
                (vostok::math::float3 *)&v181.elements[2]);
              *(double *)v61.m128i_i64 = (float)(v44->spot_umbra_angle * 0.5);
              __libm_sse2_cos(v170);
              m_reference_count = (const vostok::render::shader_constant_host *)v3[99].m_reference_count;
              *(float *)v61.m128i_i32 = *(double *)v61.m128i_i64;
              LODWORD(v181.x) = v61.m128i_i32[0];
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v68,
                (vostok::render::constants_handler<1> *)LODWORD(v58),
                m_reference_count,
                &v181);
              v70 = v181.x - v181.z;
              if ( (float)(v181.x - v181.z) <= 0.000099999997 )
                v70 = FLOAT_0_000099999997;
              v162 = (const vostok::render::shader_constant_host *)v3[99].m_vb.m_object;
              v181.y = s_bm_current_air_resistance / v70;
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v69,
                (vostok::render::constants_handler<1> *)LODWORD(v58),
                v162,
                (vostok::math::float3 *)&v181.elements[1]);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v71,
                (vostok::render::constants_handler<1> *)LODWORD(v58),
                (const vostok::render::shader_constant_host *)v3[99].m_ib.m_object,
                (const vostok::math::float3 *)&v44->spot_falloff);
              vostok::math::mul4x3(
                (const vostok::math::float4x4 *)&v3->m_vb.m_object[609].m_size,
                &v44->m_plane_spot_xform,
                &v176);
              v72 = vostok::math::transpose(&v176, &v174);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v73,
                (vostok::render::constants_handler<1> *)LODWORD(v58),
                (const vostok::render::shader_constant_host *)v3[100].m_reference_count,
                (const vostok::math::float3 *)v72);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v74,
                (vostok::render::constants_handler<1> *)LODWORD(v58),
                (const vostok::render::shader_constant_host *)v3[96].m_dcl.m_object,
                &v178);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v75,
                (vostok::render::constants_handler<1> *)LODWORD(v58),
                *(const vostok::render::shader_constant_host **)&v3[96].m_is_registered,
                (const vostok::math::float3 *)&v44->intensity);
              vostok::render::backend::set_ps_constant<unsigned int>(
                (vostok::render::backend *)LODWORD(v58),
                (const vostok::render::shader_constant_host *)v3[101].m_dcl.m_object,
                (const int *)&v44->lighting_model);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v76,
                (vostok::render::constants_handler<1> *)LODWORD(v58),
                (const vostok::render::shader_constant_host *)v3[100].m_vb.m_object,
                (const vostok::math::float3 *)&v3->m_vb.m_object[654].pool_range);
              vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
                (vostok::render::backend *)LODWORD(v58),
                (const vostok::render::shader_constant_host *)v3[100].m_ib.m_object,
                &v3->m_vb.m_object[507].m_reference_count);
              vostok::render::res_geometry::apply(v77, (int)l);
              vostok::render::stage_lights::draw_geometry(shadowers_pass, (vostok::render::stage_lights *)LODWORD(v169));
              rt = (vostok::render::render_target *)((char *)rt + 1);
              if ( (unsigned int)rt >= 2 )
                break;
              v44 = shadowers_pass;
            }
          }
        }
        else
        {
          v181.y = 0.0;
          while ( 1 )
          {
            vostok::render::res_effect::apply((vostok::render::res_effect *)rt, *(_DWORD *)&v3[88].m_is_registered);
            v90 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v91,
              (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
              (const vostok::render::shader_constant_host *)v3[97].m_reference_count,
              &v179);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v92,
              (vostok::render::constants_handler<1> *)LODWORD(v90),
              (const vostok::render::shader_constant_host *)v3[97].m_vb.m_object,
              &v177);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v93,
              (vostok::render::constants_handler<1> *)LODWORD(v90),
              (const vostok::render::shader_constant_host *)v3[97].m_vb_stride,
              (vostok::math::float3 *)&v180.elements[2]);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v94,
              (vostok::render::constants_handler<1> *)LODWORD(v90),
              (const vostok::render::shader_constant_host *)v3[97].m_ib.m_object,
              (const vostok::math::float3 *)&v44->attenuation_power);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v95,
              (vostok::render::constants_handler<1> *)LODWORD(v90),
              (const vostok::render::shader_constant_host *)v3[98].m_reference_count,
              (const vostok::math::float3 *)&v44->diffuse_influence_factor);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v96,
              (vostok::render::constants_handler<1> *)LODWORD(v90),
              (const vostok::render::shader_constant_host *)v3[98].m_vb.m_object,
              (const vostok::math::float3 *)&v44->specular_influence_factor);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v97,
              (vostok::render::constants_handler<1> *)LODWORD(v90),
              (const vostok::render::shader_constant_host *)v3[98].m_ib.m_object,
              (vostok::math::float3 *)&v181.elements[1]);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v98,
              (vostok::render::constants_handler<1> *)LODWORD(v90),
              (const vostok::render::shader_constant_host *)v3[99].m_vb_stride,
              (const vostok::math::float3 *)&v44->scale.elements[2]);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v99,
              (vostok::render::constants_handler<1> *)LODWORD(v90),
              (const vostok::render::shader_constant_host *)v3[99].m_dcl.m_object,
              &v44->scale);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v100,
              (vostok::render::constants_handler<1> *)LODWORD(v90),
              (const vostok::render::shader_constant_host *)v3[96].m_dcl.m_object,
              &v178);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v101,
              (vostok::render::constants_handler<1> *)LODWORD(v90),
              *(const vostok::render::shader_constant_host **)&v3[96].m_is_registered,
              (const vostok::math::float3 *)&v44->intensity);
            vostok::render::backend::set_ps_constant<unsigned int>(
              (vostok::render::backend *)LODWORD(v90),
              (const vostok::render::shader_constant_host *)v3[101].m_dcl.m_object,
              (const int *)&v44->lighting_model);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v102,
              (vostok::render::constants_handler<1> *)LODWORD(v90),
              (const vostok::render::shader_constant_host *)v3[100].m_vb.m_object,
              (const vostok::math::float3 *)&v3->m_vb.m_object[654].pool_range);
            vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
              (vostok::render::backend *)LODWORD(v90),
              (const vostok::render::shader_constant_host *)v3[100].m_ib.m_object,
              &v3->m_vb.m_object[507].m_reference_count);
            vostok::render::res_geometry::apply(v103, (int)l);
            vostok::render::stage_lights::draw_geometry(shadowers_pass, (vostok::render::stage_lights *)LODWORD(v169));
            rt = (vostok::render::render_target *)((char *)rt + 1);
            if ( (unsigned int)rt >= 2 )
              break;
            v44 = shadowers_pass;
          }
        }
      }
      else
      {
        v181.y = 0.0;
        while ( 1 )
        {
          vostok::render::res_effect::apply((vostok::render::res_effect *)rt, v3[89].m_reference_count);
          v104 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v105,
            (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            (const vostok::render::shader_constant_host *)v3[97].m_reference_count,
            &v179);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v106,
            (vostok::render::constants_handler<1> *)LODWORD(v104),
            (const vostok::render::shader_constant_host *)v3[97].m_vb_stride,
            (vostok::math::float3 *)&v180.elements[2]);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v107,
            (vostok::render::constants_handler<1> *)LODWORD(v104),
            (const vostok::render::shader_constant_host *)v3[97].m_ib.m_object,
            (const vostok::math::float3 *)&v44->attenuation_power);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v108,
            (vostok::render::constants_handler<1> *)LODWORD(v104),
            (const vostok::render::shader_constant_host *)v3[98].m_reference_count,
            (const vostok::math::float3 *)&v44->diffuse_influence_factor);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v109,
            (vostok::render::constants_handler<1> *)LODWORD(v104),
            (const vostok::render::shader_constant_host *)v3[98].m_vb.m_object,
            (const vostok::math::float3 *)&v44->specular_influence_factor);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v110,
            (vostok::render::constants_handler<1> *)LODWORD(v104),
            (const vostok::render::shader_constant_host *)v3[98].m_ib.m_object,
            (vostok::math::float3 *)&v181.elements[1]);
          qmemcpy(&v176, &v44->m_xform, sizeof(v176));
          v111 = shadowers_pass;
          vostok::math::float4x4::set_scale(&v176, &shadowers_pass->scale);
          vostok::math::mul4x3((const vostok::math::float4x4 *)&v3->m_vb.m_object[609].m_size, &v176, &v175);
          v112 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v113,
            (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            (const vostok::render::shader_constant_host *)v3[100].m_reference_count,
            (const vostok::math::float3 *)&v175);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v114,
            (vostok::render::constants_handler<1> *)LODWORD(v112),
            (const vostok::render::shader_constant_host *)v3[96].m_dcl.m_object,
            &v178);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v115,
            (vostok::render::constants_handler<1> *)LODWORD(v112),
            *(const vostok::render::shader_constant_host **)&v3[96].m_is_registered,
            (const vostok::math::float3 *)&v111->intensity);
          vostok::render::backend::set_ps_constant<unsigned int>(
            (vostok::render::backend *)LODWORD(v112),
            (const vostok::render::shader_constant_host *)v3[101].m_dcl.m_object,
            (const int *)&v111->lighting_model);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v116,
            (vostok::render::constants_handler<1> *)LODWORD(v112),
            (const vostok::render::shader_constant_host *)v3[100].m_vb.m_object,
            (const vostok::math::float3 *)&v3->m_vb.m_object[654].pool_range);
          vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
            (vostok::render::backend *)LODWORD(v112),
            (const vostok::render::shader_constant_host *)v3[100].m_ib.m_object,
            &v3->m_vb.m_object[507].m_reference_count);
          vostok::render::res_geometry::apply(v117, (int)l);
          vostok::render::stage_lights::draw_geometry(shadowers_pass, (vostok::render::stage_lights *)LODWORD(v169));
          rt = (vostok::render::render_target *)((char *)rt + 1);
          if ( (unsigned int)rt >= 2 )
            break;
          v44 = shadowers_pass;
        }
      }
    }
    else
    {
      v180.x = 0.0;
      while ( 1 )
      {
        if ( vostok::render::light::is_cast_shadows(v45, (int)v44) )
        {
          vostok::render::res_effect::apply((vostok::render::res_effect *)rt, (int)v3[88].m_dcl.m_object);
          v118 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v119,
            (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            (const vostok::render::shader_constant_host *)v3[101].m_vb.m_object,
            (const vostok::math::float3 *)&v44->shadow_transparency);
          v120 = vostok::math::transpose((const vostok::math::float4x4 *)&v3[102], &v172);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v121,
            (vostok::render::constants_handler<1> *)v118,
            (const vostok::render::shader_constant_host *)v3[100].m_vb_stride,
            (const vostok::math::float3 *)v120);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v122,
            (vostok::render::constants_handler<1> *)v118,
            (const vostok::render::shader_constant_host *)v3[100].m_dcl.m_object,
            (const vostok::math::float3 *)&v3[107].m_ib);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v123,
            (vostok::render::constants_handler<1> *)v118,
            *(const vostok::render::shader_constant_host **)&v3[100].m_is_registered,
            (const vostok::math::float3 *)&v3[107].m_vb_stride);
          if ( v44->static_shadows )
            vostok::render::backend::set_ps_texture(
              v124,
              v118,
              "shadowmap_texture",
              v44->m_shadow_depth_stencil_texture[0].m_object);
          else
            vostok::render::backend::set_ps_texture(
              v124,
              v118,
              "shadowmap_texture",
              *((vostok::render::res_texture **)&v3[5].m_dcl.m_object + v44->m_quality_shadow_map_size_index));
        }
        else
        {
          vostok::render::res_effect::apply((vostok::render::res_effect *)rt, v3[88].m_vb_stride);
        }
        v126 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v125,
          (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::render::shader_constant_host *)v3[97].m_reference_count,
          &v179);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v127,
          (vostok::render::constants_handler<1> *)LODWORD(v126),
          (const vostok::render::shader_constant_host *)v3[97].m_vb.m_object,
          &v177);
        v128 = (__m128)LODWORD(v44->spot_penumbra_angle);
        v128.m128_f32[0] = v128.m128_f32[0] * 0.5;
        v129 = (__m128i)_mm_cvtps_pd(v128);
        __libm_sse2_sin(v129);
        v163 = (const vostok::render::shader_constant_host *)v3[97].m_vb_stride;
        *(float *)v129.m128i_i32 = *(double *)v129.m128i_i64;
        v181.y = v180.z / *(float *)v129.m128i_i32;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v130,
          (vostok::render::constants_handler<1> *)LODWORD(v126),
          v163,
          (vostok::math::float3 *)&v181.elements[1]);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v131,
          (vostok::render::constants_handler<1> *)LODWORD(v126),
          (const vostok::render::shader_constant_host *)v3[97].m_ib.m_object,
          (const vostok::math::float3 *)&v44->attenuation_power);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v132,
          (vostok::render::constants_handler<1> *)LODWORD(v126),
          (const vostok::render::shader_constant_host *)v3[98].m_reference_count,
          (const vostok::math::float3 *)&v44->diffuse_influence_factor);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v133,
          (vostok::render::constants_handler<1> *)LODWORD(v126),
          (const vostok::render::shader_constant_host *)v3[98].m_vb.m_object,
          (const vostok::math::float3 *)&v44->specular_influence_factor);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v134,
          (vostok::render::constants_handler<1> *)LODWORD(v126),
          (const vostok::render::shader_constant_host *)v3[98].m_ib.m_object,
          &v180);
        *(double *)v129.m128i_i64 = (float)(v44->spot_penumbra_angle * 0.5);
        __libm_sse2_cos(v169);
        v164 = *(const vostok::render::shader_constant_host **)&v3[98].m_is_registered;
        *(float *)v129.m128i_i32 = *(double *)v129.m128i_i64;
        LODWORD(v181.x) = v129.m128i_i32[0];
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v135,
          (vostok::render::constants_handler<1> *)LODWORD(v126),
          v164,
          &v181);
        *(double *)v129.m128i_i64 = (float)(v44->spot_umbra_angle * 0.5);
        __libm_sse2_cos(v171);
        v165 = (const vostok::render::shader_constant_host *)v3[99].m_reference_count;
        *(float *)v129.m128i_i32 = *(double *)v129.m128i_i64;
        LODWORD(v181.z) = v129.m128i_i32[0];
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v136,
          (vostok::render::constants_handler<1> *)LODWORD(v126),
          v165,
          (vostok::math::float3 *)&v181.elements[2]);
        v138 = v181.z - v181.x;
        if ( (float)(v181.z - v181.x) <= 0.000099999997 )
          v138 = FLOAT_0_000099999997;
        v166 = (const vostok::render::shader_constant_host *)v3[99].m_vb.m_object;
        v180.y = s_bm_current_air_resistance / v138;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v137,
          (vostok::render::constants_handler<1> *)LODWORD(v126),
          v166,
          (vostok::math::float3 *)&v180.elements[1]);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v139,
          (vostok::render::constants_handler<1> *)LODWORD(v126),
          (const vostok::render::shader_constant_host *)v3[99].m_ib.m_object,
          (const vostok::math::float3 *)&v44->spot_falloff);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v140,
          (vostok::render::constants_handler<1> *)LODWORD(v126),
          (const vostok::render::shader_constant_host *)v3[96].m_dcl.m_object,
          &v178);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v141,
          (vostok::render::constants_handler<1> *)LODWORD(v126),
          *(const vostok::render::shader_constant_host **)&v3[96].m_is_registered,
          (const vostok::math::float3 *)&v44->intensity);
        vostok::render::backend::set_ps_constant<unsigned int>(
          (vostok::render::backend *)LODWORD(v126),
          (const vostok::render::shader_constant_host *)v3[101].m_dcl.m_object,
          (const int *)&v44->lighting_model);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v142,
          (vostok::render::constants_handler<1> *)LODWORD(v126),
          (const vostok::render::shader_constant_host *)v3[100].m_vb.m_object,
          (const vostok::math::float3 *)&v3->m_vb.m_object[654].pool_range);
        vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
          (vostok::render::backend *)LODWORD(v126),
          (const vostok::render::shader_constant_host *)v3[100].m_ib.m_object,
          &v3->m_vb.m_object[507].m_reference_count);
        vostok::render::res_geometry::apply(v143, (int)l);
        vostok::render::stage_lights::draw_geometry(shadowers_pass, (vostok::render::stage_lights *)LODWORD(v169));
        rt = (vostok::render::render_target *)((char *)rt + 1);
        if ( (unsigned int)rt >= 2 )
          break;
        v44 = shadowers_pass;
      }
    }
  }
  else
  {
    while ( 1 )
    {
      v144 = v44->is_shadower ? v3[88].m_reference_count : (int)v3[88].m_vb.m_object;
      vostok::render::res_effect::apply((vostok::render::res_effect *)rt, v144);
      v145 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v146,
        (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        (const vostok::render::shader_constant_host *)v3[97].m_reference_count,
        &v179);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v147,
        (vostok::render::constants_handler<1> *)LODWORD(v145),
        (const vostok::render::shader_constant_host *)v3[97].m_vb_stride,
        (vostok::math::float3 *)&v180.elements[2]);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v148,
        (vostok::render::constants_handler<1> *)LODWORD(v145),
        (const vostok::render::shader_constant_host *)v3[97].m_ib.m_object,
        (const vostok::math::float3 *)&v44->attenuation_power);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v149,
        (vostok::render::constants_handler<1> *)LODWORD(v145),
        (const vostok::render::shader_constant_host *)v3[98].m_reference_count,
        (const vostok::math::float3 *)&v44->diffuse_influence_factor);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v150,
        (vostok::render::constants_handler<1> *)LODWORD(v145),
        (const vostok::render::shader_constant_host *)v3[98].m_vb.m_object,
        (const vostok::math::float3 *)&v44->specular_influence_factor);
      v152 = v44->is_shadower ? s_bm_current_air_resistance : 0.0;
      v167 = (const vostok::render::shader_constant_host *)v3[98].m_ib.m_object;
      v181.z = v152;
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v151,
        (vostok::render::constants_handler<1> *)LODWORD(v145),
        v167,
        (vostok::math::float3 *)&v181.elements[2]);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v153,
        (vostok::render::constants_handler<1> *)LODWORD(v145),
        (const vostok::render::shader_constant_host *)v3[96].m_dcl.m_object,
        &v178);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v154,
        (vostok::render::constants_handler<1> *)LODWORD(v145),
        *(const vostok::render::shader_constant_host **)&v3[96].m_is_registered,
        (const vostok::math::float3 *)&v44->intensity);
      vostok::render::backend::set_ps_constant<unsigned int>(
        (vostok::render::backend *)LODWORD(v145),
        (const vostok::render::shader_constant_host *)v3[101].m_dcl.m_object,
        (const int *)&v44->lighting_model);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v155,
        (vostok::render::constants_handler<1> *)LODWORD(v145),
        (const vostok::render::shader_constant_host *)v3[100].m_vb.m_object,
        (const vostok::math::float3 *)&v3->m_vb.m_object[654].pool_range);
      vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
        (vostok::render::backend *)LODWORD(v145),
        (const vostok::render::shader_constant_host *)v3[100].m_ib.m_object,
        &v3->m_vb.m_object[507].m_reference_count);
      vostok::render::res_geometry::apply(v156, (int)l);
      vostok::render::stage_lights::draw_geometry(shadowers_pass, (vostok::render::stage_lights *)LODWORD(v169));
      rt = (vostok::render::render_target *)((char *)rt + 1);
      if ( (unsigned int)rt >= 2 )
        break;
      v44 = shadowers_pass;
    }
  }
  if ( !s_one_light_dip_value )
    vostok::render::backend::flush_rt_shader_resources(
      (vostok::render::backend *)v45,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
  v157 = (vostok::render::res_pass *)l;
  if ( l )
  {
    v41 = l->m_reference_count-- == 1;
    if ( v41 )
      vostok::render::resource_manager::release(vostok::quasi_singleton<vostok::render::resource_manager>::pinst, v157);
  }
LABEL_81:
  D3DPERF_EndEvent();
}
