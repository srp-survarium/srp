void __thiscall survarium::human_npc_cook::on_queried_data_received(
        survarium::human_npc_cook *this,
        vostok::configs::binary_config *data)
{
  vostok::resources::query_result_for_cook *m_lock; // ecx
  vostok::resources::query_result_for_cook *m_uid; // edi
  vostok::resources::unmanaged_resource *v5; // esi
  vostok::configs::binary_config *m_object; // esi
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v7; // [esp-4h] [ebp-14h]
  vostok::resources::query_result_for_cook *v8; // [esp+0h] [ebp-10h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config; // [esp+Ch] [ebp-4h] BYREF

  m_lock = (vostok::resources::query_result_for_cook *)data->m_parent_resources.m_lock;
  m_uid = (vostok::resources::query_result_for_cook *)data->m_uid;
  if ( m_lock == (vostok::resources::query_result_for_cook *)1 )
  {
    v7 = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(&data[1].m_reconstruction_size + 1);
    data = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v7);
    v5 = data;
    config.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &config,
      data);
    if ( v5 && !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
    m_object = config.m_object;
    survarium::human_npc_cook::on_npc_options_received(
      (survarium::human_npc_cook *)config.m_object->m_root,
      (unsigned int)this,
      m_uid,
      v8);
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_lock,
      (int)m_uid,
      result_error,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)0xB);
  }
}
