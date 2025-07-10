void __cdecl vostok::render::on_model_material_effects_instance_ready(
        vostok::resources::queries_result *in_data,
        vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *in_render_surface)
{
  vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *v2; // edi
  char *m_requery_path; // esi
  vostok::render::render_surface *v4; // ecx
  vostok::resources::unmanaged_resource *v5; // esi
  vostok::render::render_surface *v6; // [esp-8h] [ebp-14h]
  const char *v7; // [esp-4h] [ebp-10h]

  v2 = in_render_surface;
  if ( in_render_surface
    && in_data->m_queries[0].m_error_type == error_type_unset
    && in_data->m_queries[0].m_create_resource_result != result_error )
  {
    m_requery_path = in_data->m_queries[0].m_requery_path;
    if ( !m_requery_path )
      m_requery_path = in_data->m_queries[0].m_request_path;
    in_render_surface = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&in_render_surface,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&in_data->m_queries[0].m_unmanaged_resource);
    v7 = m_requery_path;
    v5 = (vostok::resources::unmanaged_resource *)in_render_surface;
    v6 = 0;
    if ( in_render_surface )
    {
      v6 = (vostok::render::render_surface *)in_render_surface;
      v4 = (vostok::render::render_surface *)_InterlockedExchangeAdd(
                                               (volatile signed __int32 *)&in_render_surface[52],
                                               1u);
    }
    vostok::render::render_surface::set_material_effects(
      v4,
      v2,
      (vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base>)v6,
      v7);
    if ( v5 )
    {
      if ( !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
    }
  }
}
