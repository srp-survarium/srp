void __cdecl vostok::render::calculate_screen_factors_task(
        const vostok::math::float4x4 *projection_matrix,
        const vostok::math::float3 *viewer_position,
        vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *it,
        vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *end)
{
  while ( it != end )
  {
    it->m_object->calculate_screen_factor(it->m_object, projection_matrix, viewer_position);
    ++it;
  }
}
