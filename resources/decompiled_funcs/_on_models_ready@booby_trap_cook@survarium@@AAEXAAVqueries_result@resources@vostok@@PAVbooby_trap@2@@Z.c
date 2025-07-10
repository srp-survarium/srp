void __thiscall survarium::booby_trap_cook::on_models_ready(
        survarium::booby_trap_cook *this,
        vostok::resources::queries_result *data,
        vostok::configs::binary_config *game_resource)
{
  vostok::configs::binary_config *v3; // ebx
  vostok::render::static_model_instance *m_link_target; // eax
  survarium::booby_trap *v5; // edi
  survarium::booby_trap *v6; // esi
  survarium::booby_trap *v7; // eax
  vostok::vfs::vfs_iterator::type_enum v8; // ecx
  vostok::resources::unmanaged_resource *m_type; // eax
  survarium::booby_trap *v10; // edi
  survarium::booby_trap *v11; // esi
  survarium::booby_trap *v12; // eax
  vostok::resources::name_registry_entry *v13; // ecx
  vostok::resources::unmanaged_resource *m_name_registry_entry; // eax
  survarium::booby_trap *v15; // edi
  survarium::booby_trap *v16; // esi
  survarium::booby_trap *v17; // eax
  vostok::resources::resource_base *v18; // ecx
  vostok::resources::unmanaged_resource *m_next_for_query_finished_callback; // eax
  survarium::booby_trap *v20; // edi
  vostok::configs::binary_config *m_object; // esi
  vostok::configs::binary_config *v22; // eax
  vostok::configs::binary_config *v23; // ecx
  vostok::resources::unmanaged_resource *m_next_for_grm_observer_list; // eax
  survarium::booby_trap *v25; // edi
  vostok::configs::binary_config *v26; // esi
  vostok::configs::binary_config *v27; // eax
  vostok::resources::query_result *v28; // ecx
  vostok::resources::unmanaged_resource *m_destruction_observer; // eax
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v30; // [esp+14h] [ebp-8h] BYREF
  survarium::booby_trap_core_cook *v31; // [esp+18h] [ebp-4h]

  v3 = game_resource;
  m_link_target = (vostok::render::static_model_instance *)game_resource[1].m_fat_it.m_link_target;
  v31 = this;
  game_resource[1].m_fat_it.m_link_target = 0;
  if ( m_link_target && !_InterlockedExchangeAdd(&m_link_target->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_link_target->vostok::resources::unmanaged_intrusive_base,
      m_link_target);
  game_resource = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&game_resource,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  v5 = (survarium::booby_trap *)game_resource;
  v6 = 0;
  if ( game_resource )
  {
    v6 = (survarium::booby_trap *)game_resource;
    _InterlockedExchangeAdd(&game_resource->m_reference_count, 1u);
  }
  v7 = 0;
  if ( v6 )
  {
    v7 = v6;
    _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
  }
  v8 = (vostok::vfs::vfs_iterator::type_enum)v7;
  m_type = (vostok::resources::unmanaged_resource *)v3[1].m_fat_it.m_type;
  v3[1].m_fat_it.m_type = v8;
  if ( m_type && !_InterlockedExchangeAdd(&m_type->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&m_type->vostok::resources::unmanaged_intrusive_base, m_type);
  if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
  if ( v5 && !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
  game_resource = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&game_resource,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[1].m_unmanaged_resource);
  v10 = (survarium::booby_trap *)game_resource;
  v11 = 0;
  if ( game_resource )
  {
    v11 = (survarium::booby_trap *)game_resource;
    _InterlockedExchangeAdd(&game_resource->m_reference_count, 1u);
  }
  v12 = 0;
  if ( v11 )
  {
    v12 = v11;
    _InterlockedExchangeAdd(&v11->m_reference_count, 1u);
  }
  v13 = (vostok::resources::name_registry_entry *)v12;
  m_name_registry_entry = (vostok::resources::unmanaged_resource *)v3[1].m_name_registry_entry;
  v3[1].m_name_registry_entry = v13;
  if ( m_name_registry_entry && !_InterlockedExchangeAdd(&m_name_registry_entry->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_name_registry_entry->vostok::resources::unmanaged_intrusive_base,
      m_name_registry_entry);
  if ( v11 && !_InterlockedExchangeAdd(&v11->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v11->vostok::resources::unmanaged_intrusive_base, v11);
  if ( v10 && !_InterlockedExchangeAdd(&v10->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v10->vostok::resources::unmanaged_intrusive_base, v10);
  game_resource = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&game_resource,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[2].m_unmanaged_resource);
  v15 = (survarium::booby_trap *)game_resource;
  v16 = 0;
  if ( game_resource )
  {
    v16 = (survarium::booby_trap *)game_resource;
    _InterlockedExchangeAdd(&game_resource->m_reference_count, 1u);
  }
  v17 = 0;
  if ( v16 )
  {
    v17 = v16;
    _InterlockedExchangeAdd(&v16->m_reference_count, 1u);
  }
  v18 = v17;
  m_next_for_query_finished_callback = (vostok::resources::unmanaged_resource *)v3[1].m_next_for_query_finished_callback;
  v3[1].m_next_for_query_finished_callback = v18;
  if ( m_next_for_query_finished_callback
    && !_InterlockedExchangeAdd(&m_next_for_query_finished_callback->m_reference_count, 0xFFFFFFFF) )
  {
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_next_for_query_finished_callback->vostok::resources::unmanaged_intrusive_base,
      m_next_for_query_finished_callback);
  }
  if ( v16 && !_InterlockedExchangeAdd(&v16->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v16->vostok::resources::unmanaged_intrusive_base, v16);
  if ( v15 && !_InterlockedExchangeAdd(&v15->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v15->vostok::resources::unmanaged_intrusive_base, v15);
  game_resource = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&game_resource,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[3].m_unmanaged_resource);
  v20 = (survarium::booby_trap *)game_resource;
  v30.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v30,
    game_resource);
  m_object = v30.m_object;
  v22 = 0;
  if ( v30.m_object )
  {
    v22 = v30.m_object;
    _InterlockedExchangeAdd(&v30.m_object->m_reference_count, 1u);
  }
  v23 = v22;
  m_next_for_grm_observer_list = (vostok::resources::unmanaged_resource *)v3[1].m_next_for_grm_observer_list;
  v3[1].m_next_for_grm_observer_list = v23;
  if ( m_next_for_grm_observer_list
    && !_InterlockedExchangeAdd(&m_next_for_grm_observer_list->m_reference_count, 0xFFFFFFFF) )
  {
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_next_for_grm_observer_list->vostok::resources::unmanaged_intrusive_base,
      m_next_for_grm_observer_list);
  }
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  if ( v20 && !_InterlockedExchangeAdd(&v20->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v20->vostok::resources::unmanaged_intrusive_base, v20);
  game_resource = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&game_resource,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[4].m_unmanaged_resource);
  v25 = (survarium::booby_trap *)game_resource;
  v30.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v30,
    game_resource);
  v26 = v30.m_object;
  v27 = 0;
  if ( v30.m_object )
  {
    v27 = v30.m_object;
    _InterlockedExchangeAdd(&v30.m_object->m_reference_count, 1u);
  }
  v28 = (vostok::resources::query_result *)v27;
  m_destruction_observer = (vostok::resources::unmanaged_resource *)v3[1].m_destruction_observer;
  v3[1].m_destruction_observer = v28;
  if ( m_destruction_observer && !_InterlockedExchangeAdd(&m_destruction_observer->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_destruction_observer->vostok::resources::unmanaged_intrusive_base,
      m_destruction_observer);
  if ( v26 && !_InterlockedExchangeAdd(&v26->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v26->vostok::resources::unmanaged_intrusive_base, v26);
  if ( v25 && !_InterlockedExchangeAdd(&v25->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v25->vostok::resources::unmanaged_intrusive_base, v25);
  survarium::booby_trap_core_cook::finish_query(v31, data->m_parent_query, v3);
}
