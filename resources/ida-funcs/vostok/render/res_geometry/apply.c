void __usercall vostok::render::res_geometry::apply(vostok::render::res_geometry *this@<ecx>, int a2@<edi>)
{
  int z_low; // ebx

  z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  vostok::render::backend::set_declaration(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    *(vostok::render::res_declaration **)(a2 + 16));
  vostok::render::backend::set_vb(
    (vostok::render::backend *)z_low,
    *(vostok::render::untyped_buffer **)(a2 + 4),
    *(_DWORD *)(a2 + 12));
  vostok::render::backend::set_ib(*(vostok::render::backend **)(a2 + 8), z_low);
}
