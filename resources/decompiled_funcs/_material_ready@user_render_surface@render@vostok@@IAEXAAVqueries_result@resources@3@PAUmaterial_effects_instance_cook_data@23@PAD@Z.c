void __thiscall vostok::render::user_render_surface::material_ready(
        vostok::render::user_render_surface *this,
        vostok::resources::unmanaged_resource *data,
        vostok::render::material_effects_instance_cook_data *cook_data,
        char *material_name)
{
  char *v4; // edi
  vostok::render::render_surface *v5; // ecx
  vostok::resources::unmanaged_resource *v6; // esi
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::resources::queries_result *v8; // [esp-8h] [ebp-18h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_children_resources; // [esp-4h] [ebp-14h]

  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::render::material_effects_instance_cook_data,vostok::memory::detail::call_destructor_predicate>(
    (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
    (vostok::resources::unmanaged_resource ***)&cook_data);
  v4 = material_name;
  if ( data->m_parent_resources.m_lock == 1 )
  {
    p_m_children_resources = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&data[1].m_children_resources;
    data = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_children_resources);
    v6 = data;
    v8 = 0;
    if ( data )
    {
      v8 = (vostok::resources::queries_result *)data;
      _InterlockedExchangeAdd(&data->m_reference_count, 1u);
    }
    vostok::render::render_surface::set_material_effects(
      v5,
      (vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base>)v8,
      v4);
    if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
  }
  if ( v4 )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v4);
  }
}
