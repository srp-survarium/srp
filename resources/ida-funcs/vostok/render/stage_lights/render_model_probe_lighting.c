void __thiscall vostok::render::stage_lights::render_model_probe_lighting(
        vostok::render::stage_lights *this,
        vostok::render::backend *instance,
        vostok::render::environment_probe *probe,
        float min_probe_scale)
{
  vostok::render::res_effect *m_object; // eax
  vostok::render::res_effect *v5; // ecx
  vostok::render::res_texture *v6; // edi
  vostok::render::backend *v7; // ecx
  vostok::render::resource_manager *v8; // ecx
  bool v9; // zf
  vostok::render::res_texture *v10; // edi
  vostok::render::backend *v11; // ecx
  vostok::render::resource_manager *v12; // ecx
  float v13; // xmm1_4
  float v14; // xmm0_4
  float z; // ebx
  float v16; // xmm1_4
  float v17; // esi
  vostok::render::backend *v18; // ecx
  double v19; // st7
  int v20; // eax
  float v21; // xmm0_4
  vostok::math::float4x4 *v22; // eax
  vostok::math::float4x4 *v23; // esi
  vostok::math::float3 *scale; // eax
  vostok::render::backend *v25; // ecx
  vostok::math::float3 *v26; // eax
  vostok::render::backend *v27; // ecx
  vostok::math::float4x4 *v28; // eax
  vostok::render::backend *v29; // ecx
  float *v30; // eax
  float v31; // xmm0_4
  vostok::render::backend *v32; // ecx
  vostok::render::backend *v33; // ecx
  const vostok::render::shader_constant_host *v34; // [esp-8h] [ebp-10Ch]
  const vostok::render::shader_constant_host *v35; // [esp-8h] [ebp-10Ch]
  const vostok::render::shader_constant_host *v36; // [esp-8h] [ebp-10Ch]
  const vostok::render::shader_constant_host *v37; // [esp-8h] [ebp-10Ch]
  const vostok::render::shader_constant_host *v38; // [esp-8h] [ebp-10Ch]
  vostok::math::float4x4 v39; // [esp+10h] [ebp-F4h] BYREF
  vostok::math::float4x4 v40; // [esp+50h] [ebp-B4h] BYREF
  vostok::math::float4x4 v41; // [esp+90h] [ebp-74h] BYREF
  vostok::math::float3 v42; // [esp+D4h] [ebp-30h] BYREF
  vostok::render::res_texture *v43; // [esp+E0h] [ebp-24h]
  int *arg; // [esp+E4h] [ebp-20h]
  const vostok::math::float4x4 *v45; // [esp+E8h] [ebp-1Ch]
  vostok::math::float3 v46; // [esp+ECh] [ebp-18h] BYREF
  float v47; // [esp+F8h] [ebp-Ch]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v48[2]; // [esp+FCh] [ebp-8h] BYREF

  m_object = vostok::render::render_surface::get_material_effects(
               (vostok::render::render_surface *)this,
               (int)probe->m_properties.texture_name.m_end)->m_effects[17].m_object;
  m_object->m_cur_technique = 1;
  vostok::render::res_effect::apply_pass(v5, (int)m_object);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    v48,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(LODWORD(min_probe_scale) + 600));
  v6 = v48[0].m_object;
  vostok::render::backend::set_ps_texture(
    v7,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    "t_probe_cubemap",
    v48[0].m_object);
  if ( v6 )
  {
    v9 = v6->m_reference_count-- == 1;
    if ( v9 )
      vostok::render::resource_manager::release(
        v8,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        v6);
  }
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    v48,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(LODWORD(min_probe_scale) + 596));
  v10 = v48[0].m_object;
  vostok::render::backend::set_ps_texture(
    v11,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    "t_probe_cubemap_diffuse",
    v48[0].m_object);
  if ( v10 )
  {
    v9 = v10->m_reference_count-- == 1;
    if ( v9 )
      vostok::render::resource_manager::release(
        v12,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        v10);
  }
  v13 = *(float *)(LODWORD(min_probe_scale) + 520);
  v14 = 0.0;
  v48[0].m_object = (vostok::render::res_texture *)(*(_DWORD *)(instance->vertex_small.m_size + 16268) + 280);
  if ( v13 > 0.0 )
    v14 = v13;
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  *(_QWORD *)&v46.x = *(_QWORD *)(LODWORD(min_probe_scale) + 508);
  v16 = *(float *)(LODWORD(min_probe_scale) + 516);
  v45 = (const vostok::math::float4x4 *)(LODWORD(min_probe_scale) + 508);
  v34 = (const vostok::render::shader_constant_host *)instance->m_gs_textures_handler.m_tmp_buffer[31];
  v17 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  v46.z = v16;
  v47 = v14;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    instance,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v34,
    &v46);
  v19 = (double)*(int *)(LODWORD(min_probe_scale) + 580);
  v46.x = *(float *)(LODWORD(min_probe_scale) + 528) * *(float *)&v48[0].m_object->m_name.m_string.m_buffer[188];
  v20 = *(_DWORD *)(LODWORD(min_probe_scale) + 580);
  v46.y = *(float *)(LODWORD(min_probe_scale) + 532) * *(float *)&v48[0].m_object->m_name.m_string.m_buffer[192];
  if ( v20 < 0 )
    v19 = v19 + 4294967300.0;
  v46.z = v19;
  v35 = (const vostok::render::shader_constant_host *)instance->m_gs_textures_handler.m_tmp_buffer[32];
  v47 = 0.0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v18,
    (vostok::render::constants_handler<1> *)LODWORD(v17),
    v35,
    &v46);
  v21 = *(float *)(LODWORD(min_probe_scale) + 520);
  v9 = *(_DWORD *)(LODWORD(min_probe_scale) + 548) == 0;
  v48[0] = *(vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(LODWORD(min_probe_scale) + 524);
  arg = (int *)(LODWORD(min_probe_scale) + 548);
  if ( v9 )
  {
    v46.y = v21;
    v46.z = v21;
    v47 = v21;
    v45 = vostok::math::create_translation((const vostok::math::float3 *)v45, &v40);
    v22 = vostok::math::create_scale((vostok::math::float3 *)&v46.elements[1], &v39);
    vostok::math::mul4x3(v45, v22, &v41);
    v23 = &v41;
  }
  else
  {
    v23 = (vostok::math::float4x4 *)(LODWORD(min_probe_scale) + 284);
  }
  qmemcpy(&v39, v23, sizeof(v39));
  qmemcpy(&v40, (const void *)(LODWORD(min_probe_scale) + 348), sizeof(v40));
  qmemcpy(&v41, (const void *)(LODWORD(min_probe_scale) + 284), sizeof(v41));
  vostok::math::float4x4::try_invert(&v41, &v41);
  scale = vostok::math::float4x4::get_scale(&v39, (vostok::math::float3 *)&v46.elements[1]);
  *(_QWORD *)&v42.x = *(_QWORD *)&scale->x;
  v36 = (const vostok::render::shader_constant_host *)instance->m_gs_textures_handler.m_tmp_buffer[33];
  v42.z = scale->z;
  v43 = v48[0].m_object;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v25,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    v36,
    &v42);
  v26 = vostok::math::float4x4::get_scale(&v40, (vostok::math::float3 *)&v46.elements[1]);
  *(_QWORD *)&v42.x = *(_QWORD *)&v26->x;
  v37 = (const vostok::render::shader_constant_host *)instance->m_gs_textures_handler.m_tmp_buffer[34];
  v42.z = v26->z;
  v43 = 0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v27,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    v37,
    &v42);
  v28 = vostok::math::transpose(&v41, &v40);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v29,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    (const vostok::render::shader_constant_host *)instance->m_gs_textures_handler.m_tmp_buffer[35],
    (const vostok::math::float3 *)v28);
  vostok::render::backend::set_ps_constant<unsigned int>(
    (vostok::render::backend *)LODWORD(z),
    (const vostok::render::shader_constant_host *)instance->m_gs_textures_handler.m_tmp_buffer[36],
    arg);
  v30 = *(float **)(instance->vertex_small.m_size + 16268);
  v31 = v30[87];
  v30 += 70;
  v46.y = v31 * v30[18];
  v46.z = v30[19] * v31;
  v38 = (const vostok::render::shader_constant_host *)instance->m_gs_textures_handler.m_tmp_buffer[47];
  v47 = v30[20] * v31;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v32,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    v38,
    (vostok::math::float3 *)&v46.elements[1]);
  vostok::render::backend::render_indexed(
    (vostok::render::backend *)LODWORD(z),
    3 * *((_DWORD *)probe->m_properties.texture_name.m_end + 6),
    v33,
    D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
    0,
    0);
}
