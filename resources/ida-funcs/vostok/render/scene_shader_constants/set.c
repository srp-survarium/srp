void __userpurge vostok::render::scene_shader_constants::set(
        vostok::render::scene_shader_constants *this@<edi>,
        vostok::render::backend *height_lights@<ecx>,
        const vostok::math::float3 *fade_color@<eax>,
        const vostok::math::float3 *context,
        const vostok::math::float3 *mid_tones,
        const vostok::math::float3 shadows,
        float desaturation,
        const vostok::math::float4 *image_grain_parameters,
        const vostok::render::environment_properties *parameters)
{
  vostok::render::untyped_buffer *m_object; // xmm0_4
  float z; // ebx
  float y; // xmm1_4
  float v12; // esi
  float v13; // xmm0_4
  float v14; // xmm1_4
  vostok::render::backend *v15; // ecx
  vostok::render::backend *v16; // ecx
  vostok::render::backend *v17; // ecx
  vostok::render::backend *v18; // ecx
  vostok::render::backend *v19; // ecx
  vostok::render::backend *v20; // ecx
  vostok::render::backend *v21; // ecx
  vostok::render::shader_constant_host *m_frame_height_lights_and_desaturation_parameters; // [esp-10h] [ebp-34h]
  vostok::render::shader_constant_host *m_bloom_parameters; // [esp-10h] [ebp-34h]
  vostok::math::float3 v24; // [esp+0h] [ebp-24h] BYREF
  float v25; // [esp+Ch] [ebp-18h]
  vostok::math::float3 v26; // [esp+10h] [ebp-14h] BYREF
  float v27; // [esp+1Ch] [ebp-8h]

  m_object = height_lights->vertex_small.m_buffer.m_object;
  z = shadows.z;
  v24.x = fade_color->x;
  y = fade_color->y;
  v12 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  LODWORD(v26.x) = m_object;
  v13 = *(float *)&height_lights->vertex_small.m_size;
  v24.y = y;
  v14 = fade_color->z;
  v26.y = v13;
  m_frame_height_lights_and_desaturation_parameters = this->m_frame_height_lights_and_desaturation_parameters;
  LODWORD(v26.z) = height_lights->vertex_small.m_position;
  v27 = s_bm_current_air_resistance;
  v24.z = v14;
  v25 = s_bm_current_air_resistance;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    height_lights,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    m_frame_height_lights_and_desaturation_parameters,
    &v26);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v15,
    (vostok::render::constants_handler<1> *)LODWORD(v12),
    this->m_scene_mid_tones_parameters,
    context);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v16,
    (vostok::render::constants_handler<1> *)LODWORD(v12),
    this->m_scene_shadows_parameters,
    mid_tones);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v17,
    (vostok::render::constants_handler<1> *)LODWORD(v12),
    this->m_gamma_correction_factor,
    &shadows);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v18,
    (vostok::render::constants_handler<1> *)LODWORD(v12),
    this->m_scene_fade_parameters,
    &v24);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v19,
    (vostok::render::constants_handler<1> *)LODWORD(v12),
    this->m_blueshift_parameter,
    (const vostok::math::float3 *)(LODWORD(z) + 500));
  m_bloom_parameters = this->m_bloom_parameters;
  *(_QWORD *)&v24.x = *(unsigned int *)(LODWORD(z) + 556);
  v24.z = 0.0;
  v25 = 0.0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v20,
    (vostok::render::constants_handler<1> *)LODWORD(v12),
    m_bloom_parameters,
    &v24);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v21,
    (vostok::render::constants_handler<1> *)LODWORD(v12),
    this->m_image_grain_parameters,
    (const vostok::math::float3 *)LODWORD(shadows.y));
}
