void __usercall vostok::render::static_render_surface::create_shadow_pass_geometry_::_2_::opt_static_vertex::set(
        vostok::render::static_render_surface::create_shadow_pass_geometry::__l2::opt_static_vertex *this@<ecx>,
        const vostok::render::static_render_surface::create_shadow_pass_geometry::__l2::static_vertex0 *base@<eax>)
{
  *(_QWORD *)&this->position.x = *(_QWORD *)base;
  this->position.z = *((float *)base + 2);
  this->normal.m_value = *((_DWORD *)base + 3);
  this->uv = (vostok::math::float2)*((_QWORD *)base + 3);
}
