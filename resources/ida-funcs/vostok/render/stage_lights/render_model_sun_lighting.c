void __userpurge vostok::render::stage_lights::render_model_sun_lighting(
        vostok::render::stage_lights *this@<ecx>,
        const vostok::math::float3 instance)
{
  float x; // ebx
  int v4; // ecx
  vostok::math::float3 *sun_direction; // eax
  int v6; // edi
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  int v10; // eax
  float v11; // xmm4_4
  vostok::render::environment_properties *v12; // ecx
  vostok::math::float3 *v13; // eax
  float z; // xmm0_4
  float y; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // edi
  int v22; // eax
  vostok::render::render_surface *v23; // ecx
  vostok::render::res_effect *m_object; // eax
  float v25; // esi
  const vostok::math::float4x4 *view2shadow; // eax
  vostok::math::float4x4 *v27; // eax
  vostok::render::backend *v28; // ecx
  vostok::render::backend *v29; // ecx
  vostok::render::backend *v30; // ecx
  vostok::render::backend *v31; // ecx
  vostok::render::backend *v32; // ecx
  vostok::render::backend *v33; // ecx
  vostok::render::backend *v34; // ecx
  vostok::render::backend *v35; // ecx
  vostok::render::backend *v36; // ecx
  vostok::render::backend *v37; // ecx
  const vostok::render::shader_constant_host *v38; // eax
  vostok::render::backend *v39; // ecx
  vostok::render::backend *v40; // ecx
  float *v41; // eax
  float v42; // xmm0_4
  vostok::render::backend *v43; // ecx
  vostok::render::backend *v44; // ecx
  const vostok::render::shader_constant_host *v45; // [esp-14h] [ebp-90h]
  const vostok::render::shader_constant_host *v46; // [esp-14h] [ebp-90h]
  const vostok::render::shader_constant_host *v47; // [esp-14h] [ebp-90h]
  const vostok::render::shader_constant_host *v48; // [esp-14h] [ebp-90h]
  const vostok::render::shader_constant_host *v49; // [esp-14h] [ebp-90h]
  const vostok::render::shader_constant_host *v50; // [esp-14h] [ebp-90h]
  const vostok::render::shader_constant_host *v51; // [esp-14h] [ebp-90h]
  vostok::math::float4x4 v52; // [esp+4h] [ebp-78h] BYREF
  vostok::math::float3 v53; // [esp+44h] [ebp-38h] BYREF
  float v54; // [esp+50h] [ebp-2Ch]
  vostok::math::float3 v55; // [esp+54h] [ebp-28h] BYREF
  vostok::math::float3 v56; // [esp+60h] [ebp-1Ch] BYREF
  vostok::math::float3 v57; // [esp+6Ch] [ebp-10h] BYREF
  float v58; // [esp+78h] [ebp-4h] BYREF

  x = instance.x;
  v4 = *(_DWORD *)(*(_DWORD *)(LODWORD(instance.x) + 4) + 16268);
  v55 = *(vostok::math::float3 *)(v4 + 352);
  v58 = FLOAT_10000_0;
  sun_direction = vostok::render::environment_properties::get_sun_direction(
                    (vostok::render::environment_properties *)v4,
                    v4 + 280,
                    &v56.x);
  v6 = *(_DWORD *)(LODWORD(x) + 4);
  v7 = sun_direction->y * -1000.0;
  v8 = sun_direction->x * -1000.0;
  v9 = sun_direction->z * -1000.0;
  v10 = *(_DWORD *)(v6 + 16268);
  v11 = *(float *)(v6 + 19528);
  v57.x = (float)((float)((float)(*(float *)(v6 + 19540) * v9) + (float)(*(float *)(v6 + 19524) * v7))
                + (float)(*(float *)(v6 + 19508) * v8))
        + *(float *)(v6 + 19556);
  v57.y = (float)((float)((float)(*(float *)(v6 + 19544) * v9) + (float)(v11 * v7))
                + (float)(*(float *)(v6 + 19512) * v8))
        + *(float *)(v6 + 19560);
  v57.z = (float)((float)((float)(*(float *)(v6 + 19548) * v9) + (float)(*(float *)(v6 + 19532) * v7))
                + (float)(*(float *)(v6 + 19516) * v8))
        + *(float *)(v6 + 19564);
  v13 = vostok::render::environment_properties::get_sun_direction(v12, v10 + 280, &v53.y);
  z = v13->z;
  y = v13->y;
  v16 = v13->x;
  v17 = *(float *)(v6 + 19528);
  v56.x = (float)((float)(*(float *)(v6 + 19524) * y) + (float)(*(float *)(v6 + 19540) * z))
        + (float)(v13->x * *(float *)(v6 + 19508));
  v56.y = (float)((float)(*(float *)(v6 + 19512) * v16) + (float)(v17 * y)) + (float)(*(float *)(v6 + 19544) * z);
  v18 = *(float *)(v6 + 19516) * v16;
  v19 = *(float *)(v6 + 19532) * y;
  v20 = *(float *)(v6 + 19548);
  v21 = instance.y;
  v22 = *(_DWORD *)(LODWORD(instance.y) + 16);
  v56.z = (float)(v18 + v19) + (float)(v20 * z);
  m_object = vostok::render::render_surface::get_material_effects(v23, v22)->m_effects[17].m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_object->m_cur_technique = 0;
    vostok::render::res_effect::apply_pass(
      (vostok::render::res_effect *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
      (int)m_object);
    instance.x = 0.0;
    v25 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    LODWORD(instance.y) = LODWORD(x) + 2288;
    do
    {
      view2shadow = vostok::render::renderer_context::get_view2shadow(
                      *(vostok::render::renderer_context **)(LODWORD(x) + 4),
                      LODWORD(instance.x));
      v27 = vostok::math::transpose(view2shadow, &v52);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v28,
        (vostok::render::constants_handler<1> *)LODWORD(v25),
        *(const vostok::render::shader_constant_host **)LODWORD(instance.y),
        (const vostok::math::float3 *)v27);
      ++LODWORD(instance.x);
      LODWORD(instance.y) += 4;
    }
    while ( LODWORD(instance.x) < 4 );
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v29,
      (vostok::render::constants_handler<1> *)LODWORD(v25),
      *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2328),
      &v57);
    v45 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2428);
    instance.x = 0.0;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v30,
      (vostok::render::constants_handler<1> *)LODWORD(v25),
      v45,
      &instance);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v31,
      (vostok::render::constants_handler<1> *)LODWORD(v25),
      *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2332),
      &v56);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v32,
      (vostok::render::constants_handler<1> *)LODWORD(v25),
      *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2340),
      (const vostok::math::float3 *)&v58);
    v46 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2336);
    instance.x = s_bm_current_air_resistance;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v33,
      (vostok::render::constants_handler<1> *)LODWORD(v25),
      v46,
      &instance);
    v47 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2344);
    v53.x = s_bm_current_air_resistance;
    v53.y = s_bm_current_air_resistance;
    v53.z = s_bm_current_air_resistance;
    v54 = FLOAT_1000_0;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v34,
      (vostok::render::constants_handler<1> *)LODWORD(v25),
      v47,
      &v53);
    v48 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2348);
    instance.x = 0.0;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v35,
      (vostok::render::constants_handler<1> *)LODWORD(v25),
      v48,
      &instance);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v36,
      (vostok::render::constants_handler<1> *)LODWORD(v25),
      *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2320),
      &v55);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v37,
      (vostok::render::constants_handler<1> *)LODWORD(v25),
      *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2324),
      (const vostok::math::float3 *)(*(_DWORD *)(*(_DWORD *)(LODWORD(x) + 4) + 16268) + 348));
    instance.x = 0.0;
    vostok::render::backend::set_ps_constant<unsigned int>(
      (vostok::render::backend *)LODWORD(v25),
      *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2440),
      (const int *)&instance);
    v38 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2312);
    LODWORD(instance.x) = 4;
    vostok::render::backend::set_ps_constant<unsigned int>(
      (vostok::render::backend *)LODWORD(v25),
      v38,
      (const int *)&instance);
    v49 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2352);
    instance.x = s_bm_current_air_resistance;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v39,
      (vostok::render::constants_handler<1> *)LODWORD(v25),
      v49,
      &instance);
    v50 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2356);
    instance.x = s_bm_current_air_resistance;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v40,
      (vostok::render::constants_handler<1> *)LODWORD(v25),
      v50,
      &instance);
    v41 = *(float **)(*(_DWORD *)(LODWORD(x) + 4) + 16268);
    v42 = v41[87];
    v41 += 70;
    v56.x = v42 * v41[18];
    v56.y = v41[19] * v42;
    v51 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 2316);
    v56.z = v41[20] * v42;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v43,
      (vostok::render::constants_handler<1> *)LODWORD(v25),
      v51,
      &v56);
    vostok::render::backend::render_indexed(
      (vostok::render::backend *)LODWORD(v25),
      3 * *(_DWORD *)(*(_DWORD *)(LODWORD(v21) + 16) + 24),
      v44,
      D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
      0,
      0);
  }
}
