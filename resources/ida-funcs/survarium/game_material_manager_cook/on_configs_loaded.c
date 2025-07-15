void __thiscall survarium::game_material_manager_cook::on_configs_loaded(
        survarium::game_material_manager_cook *this,
        survarium::pure_game_effect_emitter_base *data)
{
  survarium::pure_game_effect_emitter_base *v2; // ebx
  vostok::particle::particle_system_instance_impl *v3; // esi
  vostok::particle::particle_system_instance_impl *v4; // esi
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  char *v8; // eax
  survarium::game_material_manager *v9; // ecx
  survarium::pure_game_effect_emitter_base *v10; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_uid; // eax
  vostok::resources::query_result_for_cook *v12; // ecx
  vostok::configs::binary_config_value **v13; // eax
  survarium::game_material_manager_cook *v14; // ecx
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v15; // ebx
  const vostok::configs::binary_config_value *v16; // eax
  survarium::game_material_manager_cook *v17; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v18; // [esp-Ch] [ebp-28h] BYREF
  assert_on_fail_bool v19; // [esp-8h] [ebp-24h]
  int *v20; // [esp-4h] [ebp-20h]
  const char *v21; // [esp+0h] [ebp-1Ch]
  const char *v22; // [esp+4h] [ebp-18h]
  unsigned int v23; // [esp+8h] [ebp-14h]
  vostok::resources::query_result_for_cook *parent_query; // [esp+Ch] [ebp-10h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v25; // [esp+10h] [ebp-Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v26; // [esp+14h] [ebp-8h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v27; // [esp+18h] [ebp-4h] BYREF

  v2 = data;
  parent_query = (vostok::resources::query_result_for_cook *)this;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data[1].m_children_resources);
  v3 = (vostok::particle::particle_system_instance_impl *)data;
  v26.m_object = 0;
  if ( data )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v26);
    v26.m_object = v3;
    _InterlockedExchangeAdd(&v3->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v2[3].m_next_in_global_delay_delete_list);
  v4 = (vostok::particle::particle_system_instance_impl *)data;
  v27.m_object = 0;
  if ( data )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v27);
    v27.m_object = v4;
    _InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  v5 = survarium::g_allocator;
  v6 = type_info::raw_name(&survarium::game_material_manager `RTTI Type Descriptor');
  v8 = vostok::memory::doug_lea_allocator::malloc_impl(v7, (int)v5, (unsigned int)&dword_10310, v6, v21, v22, v23);
  if ( v8 )
  {
    survarium::game_material_manager::game_material_manager(v9, (int)v8);
    data = v10;
  }
  else
  {
    data = 0;
  }
  m_uid = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)v2->m_uid;
  if ( data )
  {
    v20 = &dword_10310;
    v19 = (assert_on_fail_bool)&vostok::resources::unmanaged_memory;
    v18.m_object = (survarium::pure_game_effect_emitter_base *)v9;
    v25 = m_uid;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v18,
      data);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v12,
      v25,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v18.m_object,
      (const vostok::resources::memory_type *)v19,
      (unsigned int)v20);
    v13 = (vostok::configs::binary_config_value **)vostok::configs::binary_config_value::operator[](
                                                     (vostok::configs::binary_config_value *)v26.m_object->m_lods[0].m_template.m_object,
                                                     "materials");
    survarium::game_material_manager_cook::create_game_materials(
      v14,
      (survarium::game_material_manager_cook *)data,
      v13);
    v15 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v2->m_uid;
    v16 = vostok::configs::binary_config_value::operator[](
            (vostok::configs::binary_config_value *)v27.m_object->m_lods[0].m_template.m_object,
            "pairs");
    survarium::game_material_manager_cook::create_game_material_pairs(
      v17,
      parent_query,
      v15,
      (survarium::game_material_manager *)data,
      (int)v16);
  }
  else
  {
    v20 = 0;
    v19 = assert_on_fail_true;
    m_uid[81].m_object = (vostok::resources::unmanaged_resource *)&vostok::resources::unmanaged_memory;
    m_uid[82].m_object = (vostok::resources::unmanaged_resource *)&dword_10310;
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)&vostok::resources::unmanaged_memory,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v2->m_uid,
      result_cannot_lock|result_success,
      v19,
      (vostok::resources::cook_base::result_enum)v20);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v27);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v26);
}
