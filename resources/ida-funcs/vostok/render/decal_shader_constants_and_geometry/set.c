void __userpurge vostok::render::decal_shader_constants_and_geometry::set(
        vostok::render::decal_shader_constants_and_geometry *this@<edi>,
        const vostok::math::float4x4 *world_to_decal_matrix@<ecx>,
        vostok::render::renderer_context *context,
        const vostok::math::float4x4 *decal_tangent_to_view_space_matrix,
        __int64 alpha_angle,
        const vostok::math::float3 *decal_width_height_far_distance,
        const vostok::math::float4x4 *decal_transform)
{
  vostok::math::float4x4 *v7; // eax
  float z; // esi
  vostok::render::backend *v9; // ecx
  vostok::math::float4x4 *v10; // eax
  vostok::render::backend *v11; // ecx
  vostok::render::backend *v12; // ecx
  vostok::render::backend *v13; // ecx
  vostok::render::shader_constant_host *m_decal_angle_parameters; // [esp-8h] [ebp-A0h]
  vostok::math::float4x4 v15; // [esp+8h] [ebp-90h] BYREF
  vostok::math::float4x4 v16; // [esp+48h] [ebp-50h] BYREF
  vostok::math::float3 v17; // [esp+88h] [ebp-10h] BYREF
  int v18; // [esp+94h] [ebp-4h]

  v7 = vostok::math::transpose(world_to_decal_matrix, &v16);
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v9,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    this->m_world_to_decal_parameter,
    (const vostok::math::float3 *)v7);
  v10 = vostok::math::transpose(decal_tangent_to_view_space_matrix, &v15);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v11,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    this->m_decal_tangent_to_view_space_matrix_parameter,
    (const vostok::math::float3 *)v10);
  *(_QWORD *)&v17.x = alpha_angle;
  m_decal_angle_parameters = this->m_decal_angle_parameters;
  v17.z = 0.0;
  v18 = 0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v12,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    m_decal_angle_parameters,
    &v17);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v13,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    this->m_eye_ray_corner_parameter,
    context->m_eye_rays);
}
