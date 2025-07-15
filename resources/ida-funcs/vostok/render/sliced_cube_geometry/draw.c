void __usercall vostok::render::sliced_cube_geometry::draw(
        vostok::render::sliced_cube_geometry *this@<ecx>,
        int a2@<edi>)
{
  int z_low; // ebx
  vostok::render::backend *v3; // ecx

  z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  vostok::render::backend::set_declaration(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    *(vostok::render::res_declaration **)a2);
  vostok::render::backend::set_vb(
    (vostok::render::backend *)z_low,
    *(vostok::render::untyped_buffer **)(a2 + 4),
    *(_DWORD *)(a2 + 16));
  vostok::render::backend::set_ib(*(vostok::render::backend **)(a2 + 8), z_low);
  vostok::render::backend::render_indexed(
    (vostok::render::backend *)z_low,
    6 * *(_DWORD *)(a2 + 12),
    v3,
    D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
    0,
    0);
}
