void __usercall vostok::render::sphere_occluder_geometry::render(
        vostok::render::sphere_occluder_geometry *this@<ecx>,
        int *a2@<eax>)
{
  vostok::render::backend *v2; // ecx

  vostok::render::res_geometry::apply((vostok::render::res_geometry *)this, *a2);
  vostok::render::backend::render_indexed(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    0x21Cu,
    v2,
    D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
    0,
    0);
}
