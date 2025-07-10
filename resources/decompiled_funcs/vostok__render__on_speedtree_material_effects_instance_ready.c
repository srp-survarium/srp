void __cdecl vostok::render::on_speedtree_material_effects_instance_ready(
        vostok::resources::unmanaged_resource *data,
        vostok::render::speedtree_tree *tree)
{
  char *m_thread_id; // esi
  vostok::resources::unmanaged_resource *v3; // esi
  vostok::resources::queries_result *v4; // [esp-8h] [ebp-10h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_children_resources; // [esp-4h] [ebp-Ch]
  const char *v6; // [esp-4h] [ebp-Ch]

  if ( !*(_DWORD *)&data[1].m_parent_resources.gapC
    && data[1].m_parent_resources.m_first != (vostok::resources::resource_link *)1 )
  {
    m_thread_id = (char *)data[1].m_parent_resources.m_thread_id;
    if ( !m_thread_id )
      m_thread_id = (char *)data[1].m_parent_resources.m_lock;
    p_m_children_resources = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&data[1].m_children_resources;
    data = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_children_resources);
    v6 = m_thread_id;
    v3 = data;
    v4 = 0;
    if ( data )
    {
      v4 = (vostok::resources::queries_result *)data;
      _InterlockedExchangeAdd(&data->m_reference_count, 1u);
    }
    vostok::render::speedtree_tree::set_material_effects(
      tree,
      branch,
      (vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base>)v4,
      v6);
    if ( v3 )
    {
      if ( !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v3);
    }
  }
}
