void __thiscall survarium::booby_trap_set_cook::on_models_ready(
        survarium::booby_trap_set_cook *this,
        vostok::resources::queries_result *data,
        vostok::configs::binary_config *game_resource)
{
  vostok::configs::binary_config *m_object; // edi
  vostok::configs::binary_config *v4; // esi
  vostok::configs::binary_config *v5; // ebx
  vostok::configs::binary_config *v6; // eax
  vostok::configs::binary_config *v7; // ecx
  vostok::resources::unmanaged_resource *m_current_satisfaction_update_tick_high; // eax
  survarium::booby_trap_set *v9; // edi
  survarium::booby_trap_set *v10; // esi
  survarium::booby_trap_set *v11; // eax
  vostok::resources::resource_base *v12; // ecx
  vostok::resources::unmanaged_resource *m_next_in_increase_quality_queue; // eax
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v14; // [esp+14h] [ebp-8h] BYREF
  survarium::booby_trap_set_core_cook *v15; // [esp+18h] [ebp-4h]

  v15 = this;
  v14.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v14,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = v14.m_object;
  v4 = 0;
  if ( v14.m_object )
  {
    v4 = v14.m_object;
    _InterlockedExchangeAdd(&v14.m_object->m_reference_count, 1u);
  }
  v5 = game_resource;
  v6 = 0;
  if ( v4 )
  {
    v6 = v4;
    _InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
  v7 = v6;
  m_current_satisfaction_update_tick_high = (vostok::resources::unmanaged_resource *)HIDWORD(v5[1].m_current_satisfaction_update_tick);
  HIDWORD(v5[1].m_current_satisfaction_update_tick) = v7;
  if ( m_current_satisfaction_update_tick_high
    && !_InterlockedExchangeAdd(&m_current_satisfaction_update_tick_high->m_reference_count, 0xFFFFFFFF) )
  {
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_current_satisfaction_update_tick_high->vostok::resources::unmanaged_intrusive_base,
      m_current_satisfaction_update_tick_high);
  }
  if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  game_resource = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&game_resource,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[1].m_unmanaged_resource);
  v9 = (survarium::booby_trap_set *)game_resource;
  v10 = 0;
  if ( game_resource )
  {
    v10 = (survarium::booby_trap_set *)game_resource;
    _InterlockedExchangeAdd(&game_resource->m_reference_count, 1u);
  }
  v11 = 0;
  if ( v10 )
  {
    v11 = v10;
    _InterlockedExchangeAdd(&v10->m_reference_count, 1u);
  }
  v12 = v11;
  m_next_in_increase_quality_queue = (vostok::resources::unmanaged_resource *)v5[1].m_next_in_increase_quality_queue;
  v5[1].m_next_in_increase_quality_queue = v12;
  if ( m_next_in_increase_quality_queue
    && !_InterlockedExchangeAdd(&m_next_in_increase_quality_queue->m_reference_count, 0xFFFFFFFF) )
  {
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_next_in_increase_quality_queue->vostok::resources::unmanaged_intrusive_base,
      m_next_in_increase_quality_queue);
  }
  if ( v10 && !_InterlockedExchangeAdd(&v10->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v10->vostok::resources::unmanaged_intrusive_base, v10);
  if ( v9 && !_InterlockedExchangeAdd(&v9->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v9->vostok::resources::unmanaged_intrusive_base, v9);
  survarium::booby_trap_set_core_cook::finish_query(v15, data->m_parent_query, v5);
}
