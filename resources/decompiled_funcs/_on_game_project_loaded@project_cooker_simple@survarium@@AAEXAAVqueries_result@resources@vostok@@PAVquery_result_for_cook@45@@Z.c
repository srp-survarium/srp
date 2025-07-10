void __thiscall survarium::project_cooker_simple::on_game_project_loaded(
        survarium::project_cooker_simple *this,
        vostok::resources::unmanaged_resource *data,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::configs::binary_config *m_object; // esi
  survarium::project_cooker_simple *v5; // ecx
  vostok::resources::unmanaged_resource *v6; // eax
  vostok::resources::unmanaged_intrusive_base *v7; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v8; // [esp-8h] [ebp-14h] BYREF
  vostok::resources::query_result_for_cook *v9; // [esp-4h] [ebp-10h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp+8h] [ebp-4h] BYREF

  v10.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v10,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data[1].m_children_resources);
  m_object = v10.m_object;
  data = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
    v10.m_object);
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  v9 = parent;
  v8.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v8,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  survarium::project_cooker_simple::create_game_objects(v5, this, v8.m_object, v9);
  v6 = data;
  if ( data )
  {
    v7 = &data->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&data->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v7, v6);
  }
}
