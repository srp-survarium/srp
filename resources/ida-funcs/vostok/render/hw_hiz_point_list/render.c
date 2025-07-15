void __thiscall vostok::render::hw_hiz_point_list::render(
        vostok::render::hw_hiz_point_list *this,
        const unsigned int num_points,
        unsigned int vertex_count)
{
  int z_low; // edi
  vostok::render::backend *v4; // ecx

  z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  vostok::render::backend::set_declaration(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    *(vostok::render::res_declaration **)num_points);
  vostok::render::backend::set_ib(0, z_low);
  vostok::render::backend::set_vb(
    (vostok::render::backend *)z_low,
    *(vostok::render::untyped_buffer **)(num_points + 4),
    0x18u);
  vostok::render::backend::render(
    (vostok::render::backend *)z_low,
    D3D_PRIMITIVE_TOPOLOGY_POINTLIST,
    v4,
    vertex_count,
    0);
}
