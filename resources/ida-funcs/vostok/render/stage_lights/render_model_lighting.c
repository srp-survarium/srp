void __userpurge vostok::render::stage_lights::render_model_lighting(
        vostok::render::stage_lights *this@<ecx>,
        long double a2@<esi:edi>,
        const vostok::math::float3 instance)
{
  int z_low; // ebx
  float v4; // xmm0_4
  float *v5; // eax
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm3_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  int v23; // eax
  vostok::render::material_effects *material_effects; // eax
  vostok::render::stage_lights *v25; // ecx
  int m_object; // eax
  int v27; // ebx
  int v28; // ebx
  int v29; // ebx
  int v30; // ebx
  int v31; // ebx
  vostok::render::backend *v32; // ecx
  bool v33; // zf
  float z; // ebx
  vostok::render::backend *v35; // ecx
  __m128 v36; // xmm0
  __m128i v37; // xmm0
  float v38; // xmm1_4
  vostok::render::backend *v39; // ecx
  vostok::render::backend *v40; // ecx
  vostok::render::backend *v41; // ecx
  vostok::render::backend *v42; // ecx
  vostok::render::backend *v43; // ecx
  float v44; // xmm0_4
  vostok::render::backend *v45; // ecx
  vostok::render::backend *v46; // ecx
  vostok::math::float4x4 *v47; // eax
  vostok::render::backend *v48; // ecx
  vostok::render::backend *v49; // ecx
  vostok::render::backend *v50; // ecx
  vostok::render::backend *v51; // ecx
  vostok::render::backend *v52; // ecx
  vostok::render::backend *v53; // ecx
  vostok::render::backend *v54; // ecx
  const vostok::math::float4x4 *view2shadow; // eax
  vostok::math::float4x4 *v56; // eax
  vostok::render::backend *v57; // ecx
  vostok::render::backend *v58; // ecx
  vostok::render::backend *v59; // ecx
  vostok::render::backend *v60; // ecx
  vostok::render::backend *v61; // ecx
  vostok::render::backend *v62; // ecx
  vostok::render::backend *v63; // ecx
  vostok::render::backend *v64; // ecx
  vostok::render::backend *v65; // ecx
  vostok::render::backend *v66; // ecx
  vostok::render::backend *v67; // ecx
  vostok::render::backend *v68; // ecx
  vostok::render::backend *v69; // ecx
  vostok::render::backend *v70; // ecx
  vostok::render::backend *v71; // ecx
  vostok::render::backend *v72; // ecx
  vostok::render::backend *v73; // ecx
  vostok::render::backend *v74; // ecx
  double v75; // xmm0_8
  vostok::render::backend *v76; // ecx
  double v77; // xmm0_8
  vostok::render::backend *v78; // ecx
  float v79; // xmm0_4
  vostok::render::backend *v80; // ecx
  vostok::render::backend *v81; // ecx
  vostok::render::backend *v82; // ecx
  vostok::render::backend *v83; // ecx
  vostok::render::backend *v84; // ecx
  vostok::render::backend *v85; // ecx
  float *v86; // eax
  float v87; // xmm0_4
  float v88; // xmm1_4
  vostok::render::backend *v89; // ecx
  vostok::render::backend *v90; // ecx
  vostok::render::backend *v91; // ecx
  vostok::render::backend *v92; // ecx
  vostok::math::float3 v93; // [esp-14h] [ebp-110h]
  const vostok::render::shader_constant_host *v94; // [esp-10h] [ebp-10Ch]
  const vostok::render::shader_constant_host *v95; // [esp-10h] [ebp-10Ch]
  const vostok::render::shader_constant_host *v96; // [esp-10h] [ebp-10Ch]
  const vostok::render::shader_constant_host *v97; // [esp-10h] [ebp-10Ch]
  const vostok::render::shader_constant_host *v98; // [esp-10h] [ebp-10Ch]
  const vostok::render::shader_constant_host *v99; // [esp-10h] [ebp-10Ch]
  const vostok::render::shader_constant_host *v100; // [esp-10h] [ebp-10Ch]
  const vostok::render::shader_constant_host *v101; // [esp-10h] [ebp-10Ch]
  const vostok::render::shader_constant_host *v102; // [esp-10h] [ebp-10Ch]
  const vostok::render::shader_constant_host *v103; // [esp-10h] [ebp-10Ch]
  long double v104; // [esp-8h] [ebp-104h]
  long double v105; // [esp-8h] [ebp-104h]
  long double v106; // [esp-8h] [ebp-104h]
  vostok::math::float4x4 v107; // [esp+8h] [ebp-F4h] BYREF
  vostok::math::float4x4 v108; // [esp+48h] [ebp-B4h] BYREF
  vostok::math::float4x4 v109; // [esp+88h] [ebp-74h] BYREF
  vostok::math::float3 v110; // [esp+C8h] [ebp-34h] BYREF
  float v111; // [esp+D4h] [ebp-28h]
  vostok::math::float3 v112; // [esp+D8h] [ebp-24h] BYREF
  vostok::math::float3 v113; // [esp+E4h] [ebp-18h] BYREF
  vostok::math::float3 v114; // [esp+F0h] [ebp-Ch] BYREF

  z_low = LODWORD(instance.z);
  v4 = *(float *)(LODWORD(instance.z) + 608);
  v104 = a2;
  v112 = *(vostok::math::float3 *)(LODWORD(instance.z) + 516);
  *(float *)&a2 = instance.x;
  v5 = *(float **)(LODWORD(instance.x) + 4);
  v6 = v5[4885];
  v7 = *(float *)(LODWORD(instance.z) + 536);
  v8 = *(float *)(LODWORD(instance.z) + 532);
  v9 = v5[4881] * v7;
  v114.y = v4;
  v10 = *(float *)(LODWORD(instance.z) + 540);
  v11 = (float)((float)(v9 + (float)(v6 * v10)) + (float)(v5[4877] * v8)) + v5[4889];
  v12 = v5[4882];
  v113.x = v11;
  v13 = (float)((float)((float)(v5[4878] * v8) + (float)(v12 * v7)) + (float)(v5[4886] * v10)) + v5[4890];
  v14 = v5[4885];
  v113.y = v13;
  v113.z = (float)((float)((float)(v5[4879] * v8) + (float)(v5[4883] * v7)) + (float)(v5[4887] * v10)) + v5[4891];
  v15 = *(float *)(LODWORD(instance.z) + 552);
  v16 = *(float *)(LODWORD(instance.z) + 556);
  v17 = *(float *)(LODWORD(instance.z) + 548);
  v18 = (float)((float)(v5[4881] * v15) + (float)(v14 * v16)) + (float)(v17 * v5[4877]);
  v19 = v5[4882];
  v110.y = v18;
  v110.z = (float)((float)(v5[4878] * v17) + (float)(v19 * v15)) + (float)(v5[4886] * v16);
  v20 = v5[4879] * v17;
  v21 = v5[4883] * v15;
  v22 = v5[4887];
  v23 = *(_DWORD *)(LODWORD(instance.y) + 16);
  v111 = (float)(v20 + v21) + (float)(v22 * v16);
  material_effects = vostok::render::render_surface::get_material_effects(
                       (vostok::render::render_surface *)(LODWORD(instance.z) + 548),
                       v23);
  LOBYTE(v25) = material_effects->is_organic;
  if ( (_BYTE)v25 )
  {
    v25 = (vostok::render::stage_lights *)(*(_DWORD *)(z_low + 860) & 0xF);
    if ( v25 == (vostok::render::stage_lights *)1 )
    {
      if ( vostok::render::light::is_cast_shadows((vostok::render::light *)1, z_low) )
      {
        HIDWORD(a2) = z_low;
        vostok::render::stage_lights::make_spot_light_shadowmap(a2, (vostok::render::light *)LODWORD(a2), LODWORD(v104));
      }
LABEL_5:
      *(_QWORD *)&v93.elements[1] = __PAIR64__(z_low, LODWORD(instance.y));
      v93.x = *(float *)&a2;
      vostok::render::stage_lights::make_skin_scattering_texture(v25, v93);
      return;
    }
    if ( !v25 || v25 == (vostok::render::stage_lights *)4 )
      goto LABEL_5;
  }
  m_object = (int)material_effects->m_effects[17].m_object;
  v27 = *(_DWORD *)(z_low + 860) & 0xF;
  if ( !v27 )
  {
    *(_DWORD *)(m_object + 22048) = 0;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v25, m_object);
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    HIDWORD(a2) = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v81,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2328),
      &v113);
LABEL_31:
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v61,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2340),
      (vostok::math::float3 *)&v114.elements[1]);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v82,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2336),
      (const vostok::math::float3 *)(LODWORD(instance.z) + 604));
    goto LABEL_32;
  }
  v28 = v27 - 1;
  if ( !v28 )
  {
    *(_DWORD *)(m_object + 22048) = 0;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v25, m_object);
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    HIDWORD(a2) = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v71,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2328),
      &v113);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v72,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2332),
      (vostok::math::float3 *)&v110.elements[1]);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v73,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2340),
      (vostok::math::float3 *)&v114.elements[1]);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v74,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2336),
      (const vostok::math::float3 *)(LODWORD(instance.z) + 604));
    v75 = (float)(*(float *)(LODWORD(instance.z) + 572) * 0.5);
    __libm_sse2_cos(v104);
    v99 = *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2372);
    *(float *)&v75 = v75;
    instance.x = *(float *)&v75;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v76,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      v99,
      &instance);
    v77 = (float)(*(float *)(LODWORD(instance.z) + 544) * 0.5);
    __libm_sse2_cos(v106);
    *(float *)&v77 = v77;
    v79 = *(float *)&v77 - instance.x;
    if ( v79 <= 0.000099999997 )
      v79 = FLOAT_0_000099999997;
    v100 = *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2380);
    instance.x = s_bm_current_air_resistance / v79;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v78,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      v100,
      &instance);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v80,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2384),
      (const vostok::math::float3 *)(LODWORD(instance.z) + 588));
    goto LABEL_32;
  }
  v29 = v28 - 1;
  if ( !v29 )
  {
    *(_DWORD *)(m_object + 22048) = 0;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v25, m_object);
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    HIDWORD(a2) = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v68,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2328),
      &v113);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v69,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2340),
      (vostok::math::float3 *)&v114.elements[1]);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v70,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2336),
      (const vostok::math::float3 *)(LODWORD(instance.z) + 604));
    qmemcpy(&v109, (const void *)(LODWORD(instance.z) + 388), sizeof(v109));
    vostok::math::float4x4::set_scale(&v109, (const vostok::math::float3 *)(LODWORD(instance.z) + 592));
    a2 = COERCE_DOUBLE(__PAIR64__(LODWORD(z), LODWORD(instance.x)));
    vostok::math::mul4x3((const vostok::math::float4x4 *)(*(_DWORD *)(LODWORD(instance.x) + 4) + 19508), &v109, &v108);
    v47 = &v108;
    goto LABEL_17;
  }
  v30 = v29 - 1;
  if ( !v30 )
  {
    *(_DWORD *)(m_object + 22048) = 0;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v25, m_object);
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    HIDWORD(a2) = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v62,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2328),
      &v113);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v63,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2332),
      (vostok::math::float3 *)&v110.elements[1]);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v64,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2340),
      (vostok::math::float3 *)&v114.elements[1]);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v65,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2336),
      (const vostok::math::float3 *)(LODWORD(instance.z) + 604));
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v66,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2388),
      (const vostok::math::float3 *)(LODWORD(instance.z) + 600));
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v67,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2392),
      (const vostok::math::float3 *)(LODWORD(instance.z) + 592));
    goto LABEL_18;
  }
  v31 = v30 - 1;
  if ( v31 )
  {
    *(_DWORD *)(m_object + 22048) = 0;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v25, m_object);
    v33 = v31 == 1;
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    v94 = *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2328);
    HIDWORD(a2) = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    if ( v33 )
    {
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v32,
        (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        v94,
        &v113);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v52,
        (vostok::render::constants_handler<1> *)HIDWORD(a2),
        *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2340),
        (vostok::math::float3 *)&v114.elements[1]);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v53,
        (vostok::render::constants_handler<1> *)HIDWORD(a2),
        *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2336),
        (const vostok::math::float3 *)(LODWORD(instance.z) + 604));
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v54,
        (vostok::render::constants_handler<1> *)HIDWORD(a2),
        *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2396),
        (const vostok::math::float3 *)(LODWORD(instance.z) + 592));
      goto LABEL_18;
    }
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v32,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v94,
      &v113);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v35,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2332),
      (vostok::math::float3 *)&v110.elements[1]);
    v36 = (__m128)*(unsigned int *)(LODWORD(instance.z) + 572);
    v36.m128_f32[0] = v36.m128_f32[0] * 0.5;
    v37 = (__m128i)_mm_cvtps_pd(v36);
    __libm_sse2_sin(v37);
    v38 = *(double *)v37.m128i_i64;
    v95 = *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2340);
    instance.x = v114.y / v38;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v39,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      v95,
      &instance);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v40,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2336),
      (const vostok::math::float3 *)(LODWORD(instance.z) + 604));
    *(double *)v37.m128i_i64 = (float)(*(float *)(LODWORD(instance.z) + 572) * 0.5);
    __libm_sse2_cos(v104);
    v96 = *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2372);
    *(float *)v37.m128i_i32 = *(double *)v37.m128i_i64;
    LODWORD(v114.x) = v37.m128i_i32[0];
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v41,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      v96,
      &v114);
    *(double *)v37.m128i_i64 = (float)(*(float *)(LODWORD(instance.z) + 544) * 0.5);
    __libm_sse2_cos(v105);
    v97 = *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2376);
    *(float *)v37.m128i_i32 = *(double *)v37.m128i_i64;
    LODWORD(instance.x) = v37.m128i_i32[0];
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v42,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      v97,
      &instance);
    v44 = instance.x - v114.x;
    if ( (float)(instance.x - v114.x) <= 0.000099999997 )
      v44 = FLOAT_0_000099999997;
    v98 = *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2380);
    instance.x = s_bm_current_air_resistance / v44;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v43,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      v98,
      &instance);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v45,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2384),
      (const vostok::math::float3 *)(LODWORD(instance.z) + 588));
    vostok::math::mul4x3(
      (const vostok::math::float4x4 *)(*(_DWORD *)(LODWORD(a2) + 4) + 19508),
      (const vostok::math::float4x4 *)(LODWORD(instance.z) + 452),
      &v109);
    v47 = &v109;
LABEL_17:
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v46,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2400),
      (const vostok::math::float3 *)v47);
LABEL_18:
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v48,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2320),
      &v112);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v49,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2324),
      (const vostok::math::float3 *)(LODWORD(instance.z) + 528));
    vostok::render::backend::set_ps_constant<unsigned int>(
      (vostok::render::backend *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2440),
      (const int *)(LODWORD(instance.z) + 856));
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v50,
      (vostok::render::constants_handler<1> *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2404),
      (const vostok::math::float3 *)(*(_DWORD *)(LODWORD(a2) + 4) + 20932));
    vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
      (vostok::render::backend *)HIDWORD(a2),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2408),
      (const unsigned int *)(*(_DWORD *)(LODWORD(a2) + 4) + 16224));
LABEL_32:
    v101 = *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2344);
    v110.x = s_bm_current_air_resistance;
    v110.y = s_bm_current_air_resistance;
    v110.z = s_bm_current_air_resistance;
    v111 = FLOAT_1000_0;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v51,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      v101,
      &v110);
    v102 = *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2348);
    instance.x = 0.0;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v83,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      v102,
      &instance);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v84,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2320),
      &v112);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v85,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2324),
      (const vostok::math::float3 *)(LODWORD(instance.z) + 528));
    vostok::render::backend::set_ps_constant<unsigned int>(
      (vostok::render::backend *)LODWORD(z),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2440),
      (const int *)(LODWORD(instance.z) + 856));
    v86 = *(float **)(*(_DWORD *)(LODWORD(a2) + 4) + 16268);
    v87 = v86[87];
    v88 = v86[88];
    v86 += 70;
    v112.x = v88 * v87;
    v112.y = v86[19] * v87;
    v103 = *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2316);
    v112.z = v86[20] * v87;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v89,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      v103,
      &v112);
    LODWORD(instance.x) = *(_DWORD *)(LODWORD(instance.z) + 860) & 0xF;
    vostok::render::backend::set_ps_constant<unsigned int>(
      (vostok::render::backend *)LODWORD(z),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2312),
      (const int *)&instance);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v90,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2352),
      (const vostok::math::float3 *)(LODWORD(instance.z) + 828));
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v91,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2356),
      (const vostok::math::float3 *)(LODWORD(instance.z) + 832));
    vostok::render::backend::render_indexed(
      (vostok::render::backend *)LODWORD(z),
      3 * *(_DWORD *)(*(_DWORD *)(LODWORD(instance.y) + 16) + 24),
      v92,
      D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
      0,
      0);
    return;
  }
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    *(_DWORD *)(m_object + 22048) = 0;
    vostok::render::res_effect::apply_pass(
      (vostok::render::res_effect *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
      m_object);
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    instance.x = 0.0;
    LODWORD(v114.x) = LODWORD(a2) + 2288;
    do
    {
      view2shadow = vostok::render::renderer_context::get_view2shadow(
                      *(vostok::render::renderer_context **)(LODWORD(a2) + 4),
                      LODWORD(instance.x));
      v56 = vostok::math::transpose(view2shadow, &v107);
      *((float *)&a2 + 1) = z;
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v57,
        (vostok::render::constants_handler<1> *)LODWORD(z),
        *(const vostok::render::shader_constant_host **)LODWORD(v114.x),
        (const vostok::math::float3 *)v56);
      ++LODWORD(instance.x);
      LODWORD(v114.x) += 4;
    }
    while ( LODWORD(instance.x) < 4 );
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v58,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2328),
      &v113);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v59,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2428),
      (const vostok::math::float3 *)(LODWORD(instance.z) + 612));
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v60,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      *(const vostok::render::shader_constant_host **)(LODWORD(a2) + 2332),
      (vostok::math::float3 *)&v110.elements[1]);
    goto LABEL_31;
  }
}
