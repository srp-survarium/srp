void __usercall vostok::render::decal_shader_constants_and_geometry::set_geometry(
        vostok::render::decal_shader_constants_and_geometry *this@<ecx>,
        int a2@<eax>)
{
  vostok::render::res_geometry::apply(*(vostok::render::res_geometry **)(a2 + 24));
}
