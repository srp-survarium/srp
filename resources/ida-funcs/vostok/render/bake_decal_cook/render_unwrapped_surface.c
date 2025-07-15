void __userpurge vostok::render::bake_decal_cook::render_unwrapped_surface(
        vostok::render::bake_decal_cook *this@<ecx>,
        vostok::render::render_surface_instance *surface@<eax>,
        const vostok::math::float4x4 *world_transform)
{
  int *m_render_surface; // ebx
  float z; // esi
  vostok::render::backend *v7; // ecx
  vostok::render::res_geometry *v8; // ecx
  vostok::render::backend *v9; // ecx

  surface->m_parent->set_constants(surface->m_parent, 0);
  m_render_surface = (int *)surface->m_render_surface;
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  ++m_render_surface;
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    this->m_world_matrix_parameter,
    (const unsigned int *)world_transform);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v7,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    this->m_world_matrix_parameter,
    (const vostok::math::float3 *)world_transform);
  vostok::render::res_geometry::apply(v8, *m_render_surface);
  vostok::render::backend::render_indexed(
    (vostok::render::backend *)LODWORD(z),
    3 * m_render_surface[5],
    v9,
    D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
    0,
    0);
}
