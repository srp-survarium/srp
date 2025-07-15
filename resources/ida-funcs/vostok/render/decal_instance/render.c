void __userpurge vostok::render::decal_instance::render(
        vostok::render::decal_instance *this@<ecx>,
        int a2@<eax>,
        vostok::render::renderer_context *context,
        vostok::render::enum_render_stage_type stage_type)
{
  const vostok::render::material_effects *effects; // eax
  const vostok::math::float4x4 *world_to_decal_matrix; // eax
  float y; // edi
  vostok::render::res_geometry *v8; // ecx
  vostok::render::backend *v9; // ecx
  const vostok::math::float4x4 *decal_view_matrix; // [esp-4h] [ebp-94h]
  __int64 v11; // [esp+0h] [ebp-90h]
  const vostok::math::float3 *v12; // [esp+8h] [ebp-88h]
  const vostok::math::float4x4 *v13; // [esp+Ch] [ebp-84h]
  vostok::math::float4x4 v14; // [esp+10h] [ebp-80h] BYREF
  vostok::math::float4x4 result; // [esp+50h] [ebp-40h] BYREF

  effects = vostok::render::decal_instance::get_effects(this, a2);
  if ( vostok::render::res_effect::apply((vostok::render::res_effect *)1, (int)effects->m_effects[stage_type].m_object) )
  {
    *((float *)&v11 + 1) = *(float *)(a2 + 88);
    *(float *)&v11 = *(float *)(a2 + 84);
    decal_view_matrix = vostok::render::get_decal_view_matrix(&result, (vostok::render::decal_instance *)a2);
    world_to_decal_matrix = vostok::render::get_world_to_decal_matrix(&v14, (vostok::render::decal_instance *)a2);
    y = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.y;
    vostok::render::decal_shader_constants_and_geometry::set(
      (vostok::render::decal_shader_constants_and_geometry *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.y),
      world_to_decal_matrix,
      context,
      decal_view_matrix,
      v11,
      v12,
      v13);
    *(_DWORD *)(a2 + 148) = 0;
    vostok::render::res_geometry::apply(v8, *(_DWORD *)(LODWORD(y) + 24));
    vostok::render::backend::render_indexed(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      0x24u,
      v9,
      D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
      0,
      0);
  }
}
