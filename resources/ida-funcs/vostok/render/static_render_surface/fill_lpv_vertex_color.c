void __thiscall vostok::render::static_render_surface::fill_lpv_vertex_color(
        vostok::render::static_render_surface *this,
        vostok::render::batched_geometry_interface *in_out_geometry,
        const vostok::math::float4x4 *transform)
{
  vostok::render::enum_vertex_input_type m_vertex_input_type; // eax

  m_vertex_input_type = this->m_vertex_input_type;
  if ( m_vertex_input_type == static_mesh_vertex_input_type )
  {
    vostok::render::fill_static_lpv_vertex_color__vostok::render::static_render_surface::fill_lpv_vertex_color_::_2_::static_vertex0_(
      &this->m_materail_effects_instance,
      in_out_geometry,
      &this->m_render_geometry,
      transform);
  }
  else if ( m_vertex_input_type == static_mesh_vertex_colored_input_type )
  {
    vostok::render::fill_static_lpv_vertex_color__vostok::render::static_render_surface::fill_lpv_vertex_color_::_2_::colored_static_vertex_(
      &this->m_materail_effects_instance,
      in_out_geometry,
      &this->m_render_geometry,
      transform);
  }
}
