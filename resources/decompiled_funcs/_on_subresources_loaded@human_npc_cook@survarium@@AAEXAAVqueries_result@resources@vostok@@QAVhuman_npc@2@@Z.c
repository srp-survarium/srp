void __thiscall survarium::human_npc_cook::on_subresources_loaded(
        survarium::human_npc_cook *this,
        vostok::resources::queries_result *data,
        survarium::human_npc *const human)
{
  vostok::resources::query_result_for_cook *m_parent_query; // esi
  vostok::sound::encoded_sound_interface *m_data; // eax
  vostok::configs::binary_config_value *v5; // eax
  vostok::configs::binary_config_value *v6; // eax
  vostok::resources::query_result_for_cook *v7; // ecx
  volatile int m_result; // edx
  vostok::configs::binary_config *m_object; // esi
  vostok::resources::unmanaged_resource *v10; // eax
  vostok::resources::unmanaged_resource *v11; // ecx
  vostok::resources::unmanaged_resource *v12; // eax
  vostok::configs::binary_config *v13; // eax
  vostok::resources::unmanaged_intrusive_base *v14; // ecx
  vostok::resources::managed_resource *v15; // eax
  vostok::configs::binary_config *v16; // eax
  vostok::configs::binary_config *v17; // ebx
  vostok::resources::unmanaged_intrusive_base *v18; // ecx
  vostok::configs::binary_config *v19; // eax
  vostok::resources::query_result_for_cook *v20; // ecx
  survarium::animated_model_instance *v21; // eax
  vostok::resources::unmanaged_intrusive_base *v22; // ecx
  vostok::resources::unmanaged_resource *v23; // eax
  vostok::resources::unmanaged_intrusive_base *v24; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v25[4]; // [esp-4h] [ebp-64h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v26; // [esp+Ch] [ebp-54h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> default_animation; // [esp+10h] [ebp-50h] BYREF
  vostok::resources::resource_ptr<survarium::animated_model_instance,vostok::resources::unmanaged_intrusive_base> model_ptr; // [esp+14h] [ebp-4Ch] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> brain_unit_ptr; // [esp+18h] [ebp-48h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v30; // [esp+1Ch] [ebp-44h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v31; // [esp+20h] [ebp-40h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v32; // [esp+24h] [ebp-3Ch] BYREF
  vostok::resources::resource_ptr<survarium::animation_space_graph,vostok::resources::unmanaged_intrusive_base> new_graph; // [esp+28h] [ebp-38h] BYREF
  vostok::resources::query_result_for_cook *parent; // [esp+2Ch] [ebp-34h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v35; // [esp+30h] [ebp-30h] BYREF
  survarium::human_npc::npc_game_attributes *v36; // [esp+34h] [ebp-2Ch]
  vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v37; // [esp+38h] [ebp-28h] BYREF
  unsigned int m_size; // [esp+3Ch] [ebp-24h]
  vostok::resources::memory_usage_type memory_usage; // [esp+40h] [ebp-20h] BYREF
  vostok::configs::binary_config_value human_attributes_config; // [esp+48h] [ebp-18h] BYREF

  v35.m_object = 0;
  m_parent_query = data->m_parent_query;
  m_data = (vostok::sound::encoded_sound_interface *)m_parent_query->m_creation_data_from_user.m_data;
  v36 = (survarium::human_npc::npc_game_attributes *)this;
  m_size = m_parent_query->m_creation_data_from_user.m_size;
  parent = m_parent_query;
  v37.m_object = m_data;
  v5 = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr(&v37);
  v6 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v5, "attributes");
  m_result = data->m_result;
  human_attributes_config = *v6;
  if ( m_result == 1 )
  {
    v30.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v30,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = v30.m_object;
    brain_unit_ptr.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&brain_unit_ptr,
      v30.m_object);
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
    v10 = 0;
    if ( brain_unit_ptr.m_object )
    {
      v10 = brain_unit_ptr.m_object;
      _InterlockedExchangeAdd(&brain_unit_ptr.m_object->m_reference_count, 1u);
    }
    v11 = v10;
    v12 = human->m_brain_unit.m_object;
    human->m_brain_unit.m_object = v11;
    if ( v12 && !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v12->vostok::resources::unmanaged_intrusive_base, v12);
    v31.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v31,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[1].m_unmanaged_resource);
    v13 = v31.m_object;
    model_ptr.m_object = 0;
    if ( v31.m_object )
    {
      v14 = &v31.m_object->vostok::resources::unmanaged_intrusive_base;
      model_ptr.m_object = (survarium::animated_model_instance *)v31.m_object;
      _InterlockedExchangeAdd(&v31.m_object->m_reference_count, 1u);
      if ( !_InterlockedExchangeAdd(&v13->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v14, v13);
    }
    survarium::human_npc::set_model((survarium::human_npc *)&model_ptr, (int)human);
    v26.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &v26,
      &data->m_queries[2].m_managed_resource);
    default_animation.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &default_animation,
      v26.m_object);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v26);
    v15 = 0;
    if ( default_animation.m_object )
    {
      v15 = default_animation.m_object;
      _InterlockedExchangeAdd(&default_animation.m_object->m_reference_count, 1u);
    }
    v35.m_object = human->m_default_animation.m_object;
    human->m_default_animation.m_object = v15;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v35);
    v32.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v32,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[3].m_unmanaged_resource);
    v16 = v32.m_object;
    v17 = 0;
    new_graph.m_object = 0;
    if ( v32.m_object )
    {
      v17 = v32.m_object;
      v18 = &v32.m_object->vostok::resources::unmanaged_intrusive_base;
      new_graph.m_object = (survarium::animation_space_graph *)v32.m_object;
      _InterlockedExchangeAdd(&v32.m_object->m_reference_count, 1u);
      if ( !_InterlockedExchangeAdd(&v16->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v18, v16);
    }
    survarium::human_npc::set_animation_space_graph((survarium::human_npc *)&new_graph, (int)human);
    if ( human )
      v19 = (vostok::configs::binary_config *)&human->survarium::game_object_;
    else
      v19 = 0;
    memory_usage.type = &vostok::resources::nocache_memory;
    memory_usage.size = 736;
    v25[0].m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      v25,
      v19);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      &memory_usage,
      parent,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v25[0].m_object);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v20,
      (int)parent,
      result_success,
      assert_on_fail_true,
      0);
    v25[0].m_object = 0;
    vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v25,
      human);
    survarium::game_world::on_npc_attributes_received(
      &human_attributes_config,
      v36,
      *(survarium::game_world **)&v36->weapons.gap20,
      (vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base>)v25[0].m_object);
    if ( v17 && !_InterlockedExchangeAdd(&v17->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v17->vostok::resources::unmanaged_intrusive_base, v17);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&default_animation);
    v21 = model_ptr.m_object;
    if ( model_ptr.m_object )
    {
      v22 = &model_ptr.m_object->vostok::resources::unmanaged_intrusive_base;
      if ( !_InterlockedExchangeAdd(&model_ptr.m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v22, v21);
    }
    v23 = brain_unit_ptr.m_object;
    if ( brain_unit_ptr.m_object )
    {
      v24 = &brain_unit_ptr.m_object->vostok::resources::unmanaged_intrusive_base;
      if ( !_InterlockedExchangeAdd(&brain_unit_ptr.m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v24, v23);
    }
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      v7,
      (int)m_parent_query,
      result_error,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)0xB);
  }
}
