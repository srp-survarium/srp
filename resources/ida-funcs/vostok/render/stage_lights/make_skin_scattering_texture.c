void __thiscall vostok::render::stage_lights::make_skin_scattering_texture(
        vostok::render::stage_lights *this,
        const vostok::math::float3 instance)
{
  float x; // ebx
  int z_low; // esi
  bool v4; // zf
  vostok::render::backend *v5; // ecx
  float *v6; // eax
  float v7; // xmm4_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  unsigned int v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm3_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  int v26; // eax
  int v27; // ecx
  vostok::render::render_surface *v28; // ecx
  vostok::render::res_effect *v29; // eax
  vostok::render::res_effect *v30; // ecx
  int v31; // esi
  vostok::render::backend *v32; // ecx
  vostok::render::backend *v33; // ecx
  vostok::render::backend *v34; // ecx
  int v35; // edi
  vostok::render::res_effect *v36; // eax
  vostok::render::res_effect *v37; // ecx
  vostok::render::backend *v38; // ecx
  vostok::render::backend *v39; // ecx
  vostok::render::backend *v40; // ecx
  __m128 v41; // xmm0
  __m128i v42; // xmm0
  float v43; // xmm1_4
  vostok::render::backend *v44; // ecx
  vostok::render::backend *v45; // ecx
  vostok::render::backend *v46; // ecx
  vostok::render::backend *v47; // ecx
  vostok::render::backend *v48; // ecx
  vostok::render::backend *v49; // ecx
  vostok::render::backend *v50; // ecx
  float v51; // xmm0_4
  vostok::render::backend *v52; // ecx
  vostok::render::backend *v53; // ecx
  vostok::render::backend *v54; // ecx
  vostok::render::backend *v55; // ecx
  vostok::render::light *v56; // ecx
  vostok::render::backend *v57; // ecx
  vostok::math::float4x4 *v58; // eax
  vostok::render::backend *v59; // ecx
  vostok::render::backend *v60; // ecx
  vostok::render::backend *v61; // ecx
  const int *p_z; // eax
  const int *v63; // eax
  vostok::render::res_effect *m_object; // eax
  vostok::render::res_effect *v65; // ecx
  vostok::render::backend *v66; // ecx
  vostok::render::backend *v67; // ecx
  vostok::render::backend *v68; // ecx
  vostok::render::backend *v69; // ecx
  vostok::render::light *v70; // ecx
  vostok::render::backend *v71; // ecx
  vostok::math::float4x4 *v72; // eax
  vostok::render::backend *v73; // ecx
  vostok::render::backend *v74; // ecx
  vostok::render::backend *v75; // ecx
  vostok::render::backend *v76; // ecx
  vostok::render::backend *v77; // ecx
  vostok::render::backend *v78; // ecx
  vostok::render::backend *v79; // ecx
  vostok::render::backend *v80; // ecx
  vostok::render::backend *v81; // ecx
  vostok::render::backend *v82; // ecx
  vostok::render::res_geometry *v83; // ecx
  float y; // edi
  vostok::render::backend *v85; // ecx
  int v86; // eax
  vostok::render::res_effect *v87; // ecx
  vostok::render::render_target *v88; // ecx
  vostok::render::stage_lights *v89; // ecx
  double v90; // st7
  vostok::render::res_effect *v91; // ecx
  unsigned int i; // eax
  float *v93; // edi
  int v94; // eax
  vostok::render::backend *v95; // ecx
  vostok::render::backend *v96; // ecx
  vostok::render::render_target *v97; // ecx
  vostok::render::stage_lights *v98; // ecx
  vostok::render::render_surface *v99; // ecx
  vostok::render::res_effect *v100; // eax
  vostok::render::res_effect *v101; // ecx
  vostok::render::backend *v102; // ecx
  float z; // esi
  vostok::render::backend *v104; // ecx
  vostok::render::render_target *v105; // ecx
  vostok::render::stage_lights *v106; // ecx
  vostok::render::backend *v107; // ecx
  vostok::render::render_surface *v108; // ecx
  vostok::render::res_effect *v109; // eax
  vostok::render::res_effect *v110; // ecx
  vostok::render::backend *v111; // ecx
  float v112; // esi
  vostok::render::backend *v113; // ecx
  vostok::render::render_target *v114; // ecx
  vostok::render::stage_lights *v115; // ecx
  vostok::render::backend *v116; // ecx
  vostok::render::render_surface *v117; // ecx
  vostok::render::res_effect *v118; // eax
  vostok::render::res_effect *v119; // ecx
  vostok::render::backend *v120; // ecx
  float v121; // esi
  vostok::render::backend *v122; // ecx
  vostok::render::render_target *v123; // ecx
  vostok::render::stage_lights *v124; // ecx
  vostok::render::backend *v125; // ecx
  vostok::render::render_surface *v126; // ecx
  vostok::render::res_effect *v127; // eax
  vostok::render::res_effect *v128; // ecx
  vostok::render::backend *v129; // ecx
  float v130; // esi
  vostok::render::backend *v131; // ecx
  vostok::render::render_target *v132; // ecx
  vostok::render::stage_lights *v133; // ecx
  vostok::render::backend *v134; // ecx
  vostok::render::render_surface *v135; // ecx
  vostok::render::res_effect *v136; // eax
  vostok::render::res_effect *v137; // ecx
  vostok::render::backend *v138; // ecx
  vostok::render::render_target *v139; // ecx
  vostok::render::stage_lights *v140; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *rt; // eax
  int v142; // esi
  vostok::render::backend *v143; // ecx
  float v144; // eax
  int v145; // edi
  vostok::render::render_surface *v146; // ecx
  vostok::render::res_effect *v147; // eax
  vostok::render::res_effect *v148; // ecx
  float v149; // esi
  vostok::render::backend *v150; // ecx
  vostok::render::backend *v151; // ecx
  vostok::render::backend *v152; // ecx
  vostok::render::backend *v153; // ecx
  vostok::render::res_geometry *v154; // ecx
  float v155; // edi
  vostok::render::backend *v156; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v157; // eax
  int v158; // esi
  float v159; // eax
  vostok::render::backend *v160; // ecx
  const vostok::render::shader_constant_host *v161; // [esp+4h] [ebp-1DCh]
  const vostok::render::shader_constant_host *v162; // [esp+4h] [ebp-1DCh]
  const vostok::render::shader_constant_host *v163; // [esp+4h] [ebp-1DCh]
  const vostok::render::shader_constant_host *v164; // [esp+4h] [ebp-1DCh]
  const vostok::render::shader_constant_host *v165; // [esp+4h] [ebp-1DCh]
  const vostok::render::shader_constant_host *v166; // [esp+4h] [ebp-1DCh]
  const vostok::render::shader_constant_host *v167; // [esp+4h] [ebp-1DCh]
  const vostok::render::shader_constant_host *v168; // [esp+4h] [ebp-1DCh]
  const vostok::render::shader_constant_host *v169; // [esp+4h] [ebp-1DCh]
  const vostok::render::shader_constant_host *v170; // [esp+4h] [ebp-1DCh]
  const vostok::render::shader_constant_host *v171; // [esp+4h] [ebp-1DCh]
  const vostok::render::shader_constant_host *v172; // [esp+4h] [ebp-1DCh]
  const vostok::render::shader_constant_host *v173; // [esp+4h] [ebp-1DCh]
  const vostok::render::shader_constant_host *v174; // [esp+4h] [ebp-1DCh]
  const vostok::render::shader_constant_host *v175; // [esp+4h] [ebp-1DCh]
  const vostok::render::shader_constant_host *v176; // [esp+4h] [ebp-1DCh]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v177; // [esp+8h] [ebp-1D8h] BYREF
  long double v178; // [esp+Ch] [ebp-1D4h]
  vostok::math::float4 v179; // [esp+1Ch] [ebp-1C4h] BYREF
  vostok::math::float4x4 v180; // [esp+B0h] [ebp-130h] BYREF
  vostok::math::float4x4 v181; // [esp+F0h] [ebp-F0h] BYREF
  float v182[9]; // [esp+130h] [ebp-B0h] BYREF
  float v183[9]; // [esp+154h] [ebp-8Ch] BYREF
  D3D11_VIEWPORT v184; // [esp+178h] [ebp-68h] BYREF
  D3D11_VIEWPORT v185; // [esp+190h] [ebp-50h] BYREF
  vostok::math::float3 v186; // [esp+1A8h] [ebp-38h] BYREF
  vostok::math::float3 v187; // [esp+1B4h] [ebp-2Ch] BYREF
  int v188; // [esp+1C0h] [ebp-20h]
  int v189; // [esp+1C4h] [ebp-1Ch]
  vostok::resources::resource_flags v190; // [esp+1C8h] [ebp-18h] BYREF
  float v191; // [esp+1D4h] [ebp-Ch]
  int arg[2]; // [esp+1D8h] [ebp-8h] BYREF

  x = instance.x;
  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    (pix_event_wrapper_dx11 *)this,
    (pix_event_wrapper_dx11 *)&instance.elements[1] + 3,
    (int)L"render_skin");
  z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    *(const vostok::render::render_target **)(LODWORD(x) + 32),
    *(const vostok::render::render_target **)(LODWORD(x) + 48),
    0,
    0);
  v4 = *(_DWORD *)(z_low + 7384) == 0;
  *(_DWORD *)(z_low + 7384) = 0;
  LOBYTE(v5) = !v4;
  *(_BYTE *)(z_low + 117) |= !v4;
  vostok::render::backend::clear_render_targets(v5, z_low, SLODWORD(FLOAT_N1_0), 0.0, 0.0, 0.0);
  qmemcpy(
    (void *)&v184,
    (const void *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 120),
    sizeof(v184));
  v185.TopLeftX = 0.0;
  v185.TopLeftY = 0.0;
  v185.Width = (float)vostok::quasi_singleton<vostok::render::options>::pinst->current.m_organic_irradiance_texture_size;
  LODWORD(instance.x) = vostok::quasi_singleton<vostok::render::options>::pinst->current.m_organic_irradiance_texture_size;
  v185.Height = (float)LODWORD(instance.x);
  v185.MinDepth = 0.0;
  v185.MaxDepth = s_bm_current_air_resistance;
  vostok::render::backend::set_viewports(
    (vostok::render::backend *)&v185,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    &v185,
    (const D3D11_VIEWPORT *)LODWORD(v178));
  v6 = *(float **)(LODWORD(x) + 4);
  v7 = v6[4885];
  v8 = *(float *)(LODWORD(instance.z) + 536);
  v9 = *(float *)(LODWORD(instance.z) + 532);
  v10 = v6[4881] * v8;
  instance.x = *(float *)(LODWORD(instance.z) + 608);
  v11 = *(float *)(LODWORD(instance.z) + 540);
  v12 = (float)((float)(v10 + (float)(v7 * v11)) + (float)(v6[4877] * v9)) + v6[4889];
  v13 = v6[4882];
  v186.x = v12;
  v14 = (float)((float)((float)(v6[4878] * v9) + (float)(v13 * v8)) + (float)(v6[4886] * v11)) + v6[4890];
  v15 = v6[4885];
  v186.y = v14;
  v186.z = (float)((float)((float)(v6[4879] * v9) + (float)(v6[4883] * v8)) + (float)(v6[4887] * v11)) + v6[4891];
  v16 = *(float *)(LODWORD(instance.z) + 552);
  v17 = *(float *)(LODWORD(instance.z) + 556);
  v18 = *(float *)(LODWORD(instance.z) + 548);
  *(float *)&v19 = (float)((float)(v6[4881] * v16) + (float)(v15 * v17)) + (float)(v18 * v6[4877]);
  v20 = v6[4882];
  v190.type = v19;
  v21 = (float)(v6[4878] * v18) + (float)(v20 * v16);
  v22 = v6[4886];
  v187.y = *(float *)(LODWORD(instance.z) + 516);
  *(float *)&v190.m_flags.m_flags = v21 + (float)(v22 * v17);
  v23 = v6[4879] * v18;
  v24 = v6[4883] * v16;
  v25 = v6[4887];
  v187.z = *(float *)(LODWORD(instance.z) + 520);
  v188 = *(_DWORD *)(LODWORD(instance.z) + 524);
  v191 = (float)(v23 + v24) + (float)(v25 * v17);
  v26 = *(_DWORD *)(LODWORD(instance.y) + 16);
  v27 = *(_DWORD *)(LODWORD(instance.z) + 860) & 0xF;
  v189 = v26;
  if ( !v27 )
  {
    m_object = vostok::render::render_surface::get_material_effects(0, v26)->m_effects[17].m_object;
    m_object->m_cur_technique = 1;
    vostok::render::res_effect::apply_pass(v65, (int)m_object);
    v31 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v66,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2328),
      &v186);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v67,
      (vostok::render::constants_handler<1> *)v31,
      *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2340),
      &instance);
    v35 = LODWORD(instance.z);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v68,
      (vostok::render::constants_handler<1> *)v31,
      *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2336),
      (const vostok::math::float3 *)(LODWORD(instance.z) + 604));
    v177.m_object = (vostok::render::render_target *)arg;
    v167 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2360);
    arg[0] = 0;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v69,
      (vostok::render::constants_handler<1> *)v31,
      v167,
      (const vostok::math::float3 *)arg);
    if ( vostok::render::light::is_cast_shadows(v70, v35) )
    {
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v71,
        (vostok::render::constants_handler<1> *)v31,
        *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2428),
        (const vostok::math::float3 *)(v35 + 612));
      v72 = vostok::math::transpose((const vostok::math::float4x4 *)(LODWORD(x) + 2448), &v181);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v73,
        (vostok::render::constants_handler<1> *)v31,
        *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2412),
        (const vostok::math::float3 *)v72);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v74,
        (vostok::render::constants_handler<1> *)v31,
        *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2416),
        (const vostok::math::float3 *)(LODWORD(x) + 2576));
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v75,
        (vostok::render::constants_handler<1> *)v31,
        *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2420),
        (const vostok::math::float3 *)(LODWORD(x) + 2580));
      arg[0] = 1;
      p_z = arg;
      goto LABEL_11;
    }
    arg[0] = 0;
    v63 = arg;
LABEL_13:
    vostok::render::backend::set_ps_constant<unsigned int>(
      (vostok::render::backend *)v31,
      *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2424),
      v63);
    goto LABEL_14;
  }
  v28 = (vostok::render::render_surface *)(v27 - 1);
  if ( !v28 )
  {
    v36 = vostok::render::render_surface::get_material_effects(0, v26)->m_effects[17].m_object;
    v36->m_cur_technique = 1;
    vostok::render::res_effect::apply_pass(v37, (int)v36);
    v31 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    v177.m_object = (vostok::render::render_target *)arg;
    v162 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2360);
    arg[0] = 0;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v38,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v162,
      (const vostok::math::float3 *)arg);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v39,
      (vostok::render::constants_handler<1> *)v31,
      *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2328),
      &v186);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v40,
      (vostok::render::constants_handler<1> *)v31,
      *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2332),
      (const vostok::math::float3 *)&v190.type);
    v35 = LODWORD(instance.z);
    v41 = (__m128)*(unsigned int *)(LODWORD(instance.z) + 572);
    v41.m128_f32[0] = v41.m128_f32[0] * 0.5;
    v42 = (__m128i)_mm_cvtps_pd(v41);
    __libm_sse2_sin(v42);
    v43 = *(double *)v42.m128i_i64;
    v177.m_object = (vostok::render::render_target *)&instance.elements[2];
    v163 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2340);
    instance.z = instance.x / v43;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v44,
      (vostok::render::constants_handler<1> *)v31,
      v163,
      (const vostok::math::float3 *)&instance.elements[2]);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v45,
      (vostok::render::constants_handler<1> *)v31,
      *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2336),
      (const vostok::math::float3 *)(v35 + 604));
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v46,
      (vostok::render::constants_handler<1> *)v31,
      *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2352),
      (const vostok::math::float3 *)(v35 + 828));
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v47,
      (vostok::render::constants_handler<1> *)v31,
      *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2356),
      (const vostok::math::float3 *)(v35 + 832));
    *(double *)v42.m128i_i64 = (float)(*(float *)(v35 + 572) * 0.5);
    __libm_sse2_cos(v178);
    v177.m_object = (vostok::render::render_target *)arg;
    v164 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2372);
    *(float *)v42.m128i_i32 = *(double *)v42.m128i_i64;
    arg[0] = v42.m128i_i32[0];
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v48,
      (vostok::render::constants_handler<1> *)v31,
      v164,
      (const vostok::math::float3 *)arg);
    *(double *)v42.m128i_i64 = (float)(*(float *)(v35 + 544) * 0.5);
    __libm_sse2_cos(v178);
    v177.m_object = (vostok::render::render_target *)&instance.elements[2];
    v165 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2376);
    *(float *)v42.m128i_i32 = *(double *)v42.m128i_i64;
    LODWORD(instance.z) = v42.m128i_i32[0];
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v49,
      (vostok::render::constants_handler<1> *)v31,
      v165,
      (const vostok::math::float3 *)&instance.elements[2]);
    v51 = instance.z - *(float *)arg;
    if ( (float)(instance.z - *(float *)arg) <= 0.000099999997 )
      v51 = FLOAT_0_000099999997;
    v177.m_object = (vostok::render::render_target *)&instance.elements[2];
    v166 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2380);
    instance.z = s_bm_current_air_resistance / v51;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v50,
      (vostok::render::constants_handler<1> *)v31,
      v166,
      (const vostok::math::float3 *)&instance.elements[2]);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v52,
      (vostok::render::constants_handler<1> *)v31,
      *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2384),
      (const vostok::math::float3 *)(v35 + 588));
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v53,
      (vostok::render::constants_handler<1> *)v31,
      *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2320),
      (vostok::math::float3 *)&v187.elements[1]);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v54,
      (vostok::render::constants_handler<1> *)v31,
      *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2324),
      (const vostok::math::float3 *)(v35 + 528));
    vostok::render::backend::set_ps_constant<unsigned int>(
      (vostok::render::backend *)v31,
      *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2440),
      (const int *)(v35 + 856));
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v55,
      (vostok::render::constants_handler<1> *)v31,
      *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2404),
      (const vostok::math::float3 *)(*(_DWORD *)(LODWORD(x) + 4) + 20932));
    if ( vostok::render::light::is_cast_shadows(v56, v35) )
    {
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v57,
        (vostok::render::constants_handler<1> *)v31,
        *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2428),
        (const vostok::math::float3 *)(v35 + 612));
      v58 = vostok::math::transpose((const vostok::math::float4x4 *)(LODWORD(x) + 2448), &v180);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v59,
        (vostok::render::constants_handler<1> *)v31,
        *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2412),
        (const vostok::math::float3 *)v58);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v60,
        (vostok::render::constants_handler<1> *)v31,
        *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2416),
        (const vostok::math::float3 *)(LODWORD(x) + 2576));
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v61,
        (vostok::render::constants_handler<1> *)v31,
        *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2420),
        (const vostok::math::float3 *)(LODWORD(x) + 2580));
      LODWORD(instance.z) = 1;
      p_z = (const int *)&instance.z;
LABEL_11:
      vostok::render::backend::set_ps_constant<unsigned int>(
        (vostok::render::backend *)v31,
        *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2424),
        p_z);
      vostok::render::backend::set_ps_texture(
        v76,
        v31,
        "shadowmap_texture",
        *(vostok::render::res_texture **)(LODWORD(x) + 4 * *(_DWORD *)(v35 + 900) + 136));
      v31 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
      goto LABEL_14;
    }
    instance.z = 0.0;
    v63 = (const int *)&instance.z;
    goto LABEL_13;
  }
  v29 = vostok::render::render_surface::get_material_effects(v28, v26)->m_effects[17].m_object;
  v29->m_cur_technique = 1;
  vostok::render::res_effect::apply_pass(v30, (int)v29);
  v31 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v32,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2332),
    (const vostok::math::float3 *)&v190.type);
  arg[0] = 0;
  vostok::render::backend::set_ps_constant<unsigned int>(
    (vostok::render::backend *)v31,
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2424),
    arg);
  v177.m_object = (vostok::render::render_target *)arg;
  v161 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2360);
  arg[0] = 0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v33,
    (vostok::render::constants_handler<1> *)v31,
    v161,
    (const vostok::math::float3 *)arg);
  v35 = LODWORD(instance.z);
LABEL_14:
  v177.m_object = (vostok::render::render_target *)&v190;
  v168 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2344);
  *(float *)&v190.__vftable = s_bm_current_air_resistance;
  *(float *)&v190.type = s_bm_current_air_resistance;
  *(float *)&v190.m_flags.m_flags = s_bm_current_air_resistance;
  v191 = FLOAT_1000_0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v34,
    (vostok::render::constants_handler<1> *)v31,
    v168,
    (const vostok::math::float3 *)&v190);
  v177.m_object = (vostok::render::render_target *)&instance.elements[2];
  v169 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2348);
  instance.z = 0.0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v77,
    (vostok::render::constants_handler<1> *)v31,
    v169,
    (const vostok::math::float3 *)&instance.elements[2]);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v78,
    (vostok::render::constants_handler<1> *)v31,
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2320),
    (vostok::math::float3 *)&v187.elements[1]);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v79,
    (vostok::render::constants_handler<1> *)v31,
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2324),
    (const vostok::math::float3 *)(v35 + 528));
  vostok::render::backend::set_ps_constant<unsigned int>(
    (vostok::render::backend *)v31,
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2440),
    (const int *)(v35 + 856));
  LODWORD(instance.z) = *(_DWORD *)(v35 + 860) & 0xF;
  vostok::render::backend::set_ps_constant<unsigned int>(
    (vostok::render::backend *)v31,
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2312),
    (const int *)&instance.z);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v80,
    (vostok::render::constants_handler<1> *)v31,
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2352),
    (const vostok::math::float3 *)(v35 + 828));
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v81,
    (vostok::render::constants_handler<1> *)v31,
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2356),
    (const vostok::math::float3 *)(v35 + 832));
  v177.m_object = (vostok::render::render_target *)&v190;
  v170 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2444);
  *(float *)&v190.__vftable = s_bm_current_air_resistance;
  *(float *)&v190.type = s_bm_current_air_resistance;
  *(float *)&v190.m_flags.m_flags = s_bm_current_air_resistance;
  v191 = 0.0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v82,
    (vostok::render::constants_handler<1> *)v31,
    v170,
    (const vostok::math::float3 *)&v190);
  vostok::render::res_geometry::apply(v83, *(_DWORD *)(v189 + 4));
  y = instance.y;
  vostok::render::renderer_context::set_w(
    *(const vostok::math::float4x4 **)(LODWORD(instance.y) + 36),
    *(vostok::render::renderer_context **)(LODWORD(x) + 4));
  vostok::render::backend::render_indexed(
    (vostok::render::backend *)v31,
    3 * *(_DWORD *)(*(_DWORD *)(LODWORD(y) + 16) + 24),
    v85,
    D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
    0,
    0);
  v86 = *(_DWORD *)(LODWORD(x) + 2164);
  *(_DWORD *)(v86 + 22048) = 0;
  vostok::render::res_effect::apply_pass(v87, v86);
  v177.m_object = v88;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v177,
    (const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(LODWORD(x) + 40));
  vostok::render::stage_lights::fill_surface(v89, LODWORD(x), v177.m_object);
  LODWORD(instance.z) = vostok::quasi_singleton<vostok::render::options>::pinst->current.m_organic_irradiance_texture_size;
  v90 = (double)LODWORD(instance.z);
  get_gaussain_weights_offsets(v183, (unsigned __int64)v90, LODWORD(x) + 40, v182);
  get_gaussain_weights_offsets(&v180.j.w, (unsigned __int64)v90, LODWORD(x) + 40, &v181.j.w);
  v91 = (vostok::render::res_effect *)&v179;
  for ( i = 0; i < 9; ++i )
  {
    *(float *)&v190.__vftable = v182[i];
    *(float *)&v190.type = v183[i];
    v190.m_flags.m_flags = *(_DWORD *)((char *)&v181.j.w + i * 4);
    v191 = *(float *)((char *)&v180.j.w + i * 4);
    v91->vostok::resources::resource_flags = v190;
    v93 = (float *)(&v91->vostok::resources::resource_flags + 1);
    v91 = (vostok::render::res_effect *)((char *)v91 + 16);
    *v93 = v191;
  }
  v94 = *(_DWORD *)(LODWORD(x) + 2160);
  *(_DWORD *)(v94 + 22048) = 0;
  vostok::render::res_effect::apply_pass(v91, v94);
  vostok::render::backend::set_ps_texture(
    v95,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    "t_base",
    *(vostok::render::res_texture **)(LODWORD(x) + 44));
  v177.m_object = (vostok::render::render_target *)&v190;
  v171 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2444);
  *(float *)&v190.__vftable = s_bm_current_air_resistance;
  *(float *)&v190.type = s_bm_current_air_resistance;
  *(float *)&v190.m_flags.m_flags = s_bm_current_air_resistance;
  v191 = 0.0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v96,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v171,
    (const vostok::math::float3 *)&v190);
  v177.m_object = v97;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v177,
    (const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(LODWORD(x) + 56));
  vostok::render::stage_lights::fill_surface(v98, LODWORD(x), v177.m_object);
  v100 = vostok::render::render_surface::get_material_effects(v99, *(_DWORD *)(LODWORD(instance.y) + 16))->m_effects[17].m_object;
  v100->m_cur_technique = 2;
  vostok::render::res_effect::apply_pass(v101, (int)v100);
  vostok::render::backend::set_ps_texture(
    v102,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    "t_base",
    *(vostok::render::res_texture **)(LODWORD(x) + 60));
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  v177.m_object = (vostok::render::render_target *)&v190;
  v172 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2444);
  *(float *)&v190.__vftable = s_bm_current_air_resistance;
  *(float *)&v190.type = s_bm_current_air_resistance;
  *(float *)&v190.m_flags.m_flags = s_bm_current_air_resistance;
  v191 = 0.0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v104,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v172,
    (const vostok::math::float3 *)&v190);
  vostok::render::backend::set_ps_constant<vostok::math::float4>(
    (vostok::render::backend *)LODWORD(z),
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2308),
    &v179,
    LODWORD(v178));
  v177.m_object = v105;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v177,
    (const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(LODWORD(x) + 64));
  vostok::render::stage_lights::fill_surface(v106, LODWORD(x), v177.m_object);
  vostok::render::backend::flush_rt_shader_resources(
    v107,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
  v109 = vostok::render::render_surface::get_material_effects(v108, *(_DWORD *)(LODWORD(instance.y) + 16))->m_effects[17].m_object;
  v109->m_cur_technique = 2;
  vostok::render::res_effect::apply_pass(v110, (int)v109);
  vostok::render::backend::set_ps_texture(
    v111,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    "t_base",
    *(vostok::render::res_texture **)(LODWORD(x) + 68));
  v112 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  v177.m_object = (vostok::render::render_target *)&v190;
  v173 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2444);
  *(float *)&v190.__vftable = s_bm_current_air_resistance;
  *(float *)&v190.type = s_bm_current_air_resistance;
  *(float *)&v190.m_flags.m_flags = s_bm_current_air_resistance;
  v191 = 0.0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v113,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v173,
    (const vostok::math::float3 *)&v190);
  vostok::render::backend::set_ps_constant<vostok::math::float4>(
    (vostok::render::backend *)LODWORD(v112),
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2308),
    &v179,
    LODWORD(v178));
  v177.m_object = v114;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v177,
    (const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(LODWORD(x) + 72));
  vostok::render::stage_lights::fill_surface(v115, LODWORD(x), v177.m_object);
  vostok::render::backend::flush_rt_shader_resources(
    v116,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
  v118 = vostok::render::render_surface::get_material_effects(v117, *(_DWORD *)(LODWORD(instance.y) + 16))->m_effects[17].m_object;
  v118->m_cur_technique = 2;
  vostok::render::res_effect::apply_pass(v119, (int)v118);
  vostok::render::backend::set_ps_texture(
    v120,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    "t_base",
    *(vostok::render::res_texture **)(LODWORD(x) + 76));
  v121 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  v177.m_object = (vostok::render::render_target *)&v190;
  v174 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2444);
  *(float *)&v190.__vftable = s_bm_current_air_resistance;
  *(float *)&v190.type = s_bm_current_air_resistance;
  *(float *)&v190.m_flags.m_flags = s_bm_current_air_resistance;
  v191 = 0.0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v122,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v174,
    (const vostok::math::float3 *)&v190);
  vostok::render::backend::set_ps_constant<vostok::math::float4>(
    (vostok::render::backend *)LODWORD(v121),
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2308),
    &v179,
    LODWORD(v178));
  v177.m_object = v123;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v177,
    (const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(LODWORD(x) + 80));
  vostok::render::stage_lights::fill_surface(v124, LODWORD(x), v177.m_object);
  vostok::render::backend::flush_rt_shader_resources(
    v125,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
  v127 = vostok::render::render_surface::get_material_effects(v126, *(_DWORD *)(LODWORD(instance.y) + 16))->m_effects[17].m_object;
  v127->m_cur_technique = 2;
  vostok::render::res_effect::apply_pass(v128, (int)v127);
  vostok::render::backend::set_ps_texture(
    v129,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    "t_base",
    *(vostok::render::res_texture **)(LODWORD(x) + 84));
  v130 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  v177.m_object = (vostok::render::render_target *)&v190;
  v175 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2444);
  *(float *)&v190.__vftable = s_bm_current_air_resistance;
  *(float *)&v190.type = s_bm_current_air_resistance;
  *(float *)&v190.m_flags.m_flags = s_bm_current_air_resistance;
  v191 = 0.0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v131,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v175,
    (const vostok::math::float3 *)&v190);
  vostok::render::backend::set_ps_constant<vostok::math::float4>(
    (vostok::render::backend *)LODWORD(v130),
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2308),
    &v179,
    LODWORD(v178));
  v177.m_object = v132;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v177,
    (const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(LODWORD(x) + 88));
  vostok::render::stage_lights::fill_surface(v133, LODWORD(x), v177.m_object);
  vostok::render::backend::flush_rt_shader_resources(
    v134,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
  v136 = vostok::render::render_surface::get_material_effects(v135, *(_DWORD *)(LODWORD(instance.y) + 16))->m_effects[17].m_object;
  v136->m_cur_technique = 2;
  vostok::render::res_effect::apply_pass(v137, (int)v136);
  vostok::render::backend::set_ps_texture(
    v138,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    "t_base",
    *(vostok::render::res_texture **)(LODWORD(x) + 92));
  vostok::render::backend::set_ps_constant<vostok::math::float4>(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2308),
    &v179,
    LODWORD(v178));
  v177.m_object = v139;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v177,
    (const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(LODWORD(x) + 96));
  vostok::render::stage_lights::fill_surface(v140, LODWORD(x), v177.m_object);
  rt = vostok::render::renderer_context::get_rt(
         *(vostok::render::renderer_context **)(LODWORD(x) + 4),
         rt_generic_0,
         (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&instance.elements[2]);
  v142 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    rt->m_object,
    0,
    0,
    0);
  v144 = instance.z;
  if ( LODWORD(instance.z) )
  {
    --*(_DWORD *)LODWORD(instance.z);
    if ( !*(_DWORD *)LODWORD(v144) )
    {
      vostok::render::resource_manager::release(
        (vostok::render::render_target *)LODWORD(instance.z),
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      v142 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    }
  }
  v145 = *(_DWORD *)(v142 + 7440);
  v4 = *(_DWORD *)(v142 + 7384) == v145;
  *(_DWORD *)(v142 + 7384) = v145;
  LOBYTE(v143) = !v4;
  *(_BYTE *)(v142 + 117) |= !v4;
  vostok::render::backend::set_viewports(v143, v142, &v184, (const D3D11_VIEWPORT *)LODWORD(v178));
  v147 = vostok::render::render_surface::get_material_effects(v146, *(_DWORD *)(LODWORD(instance.y) + 16))->m_effects[17].m_object;
  v147->m_cur_technique = 3;
  vostok::render::res_effect::apply_pass(v148, (int)v147);
  v149 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v150,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2328),
    &v186);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v151,
    (vostok::render::constants_handler<1> *)LODWORD(v149),
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2340),
    &instance);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v152,
    (vostok::render::constants_handler<1> *)LODWORD(v149),
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2320),
    (vostok::math::float3 *)&v187.elements[1]);
  v177.m_object = (vostok::render::render_target *)&v187;
  v176 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2444);
  v187.x = s_bm_current_air_resistance;
  v187.y = s_bm_current_air_resistance;
  v187.z = s_bm_current_air_resistance;
  v188 = 0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v153,
    (vostok::render::constants_handler<1> *)LODWORD(v149),
    v176,
    &v187);
  vostok::render::res_geometry::apply(v154, *(_DWORD *)(v189 + 4));
  v155 = instance.y;
  vostok::render::renderer_context::set_w(
    *(const vostok::math::float4x4 **)(LODWORD(instance.y) + 36),
    *(vostok::render::renderer_context **)(LODWORD(x) + 4));
  vostok::render::backend::render_indexed(
    (vostok::render::backend *)LODWORD(v149),
    3 * *(_DWORD *)(*(_DWORD *)(LODWORD(v155) + 16) + 24),
    v156,
    D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
    0,
    0);
  v157 = vostok::render::renderer_context::get_rt(
           *(vostok::render::renderer_context **)(LODWORD(x) + 4),
           rt_generic_0,
           (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&instance.elements[1]);
  v158 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v157->m_object,
    0,
    0,
    0);
  v159 = instance.y;
  if ( LODWORD(instance.y) )
  {
    --*(_DWORD *)LODWORD(instance.y);
    if ( !*(_DWORD *)LODWORD(v159) )
    {
      vostok::render::resource_manager::release(
        (vostok::render::render_target *)LODWORD(instance.y),
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      v158 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    }
  }
  v160 = *(vostok::render::backend **)(v158 + 7440);
  v4 = *(_DWORD *)(v158 + 7384) == (_DWORD)v160;
  *(_DWORD *)(v158 + 7384) = v160;
  *(_BYTE *)(v158 + 117) |= !v4;
  vostok::render::backend::set_viewports(v160, v158, &v184, (const D3D11_VIEWPORT *)LODWORD(v178));
  D3DPERF_EndEvent();
}
