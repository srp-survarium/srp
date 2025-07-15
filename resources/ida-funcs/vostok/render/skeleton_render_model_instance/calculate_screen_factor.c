void __thiscall vostok::render::skeleton_render_model_instance::calculate_screen_factor(
        vostok::render::skeleton_render_model_instance *this,
        const vostok::math::float4x4 *projection_matrix,
        const vostok::math::float3 *viewer_position)
{
  unsigned __int8 i; // bl

  for ( i = 0; i < this->m_instances_count; ++i )
    vostok::render::render_surface_instance::calculate_screen_factor(
      (vostok::render::render_surface_instance *)this,
      (const vostok::math::float4x4 *)&this->m_surface_instances[i],
      projection_matrix,
      &viewer_position->x);
}
