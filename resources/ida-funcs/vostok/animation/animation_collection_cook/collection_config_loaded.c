void __thiscall vostok::animation::animation_collection_cook::collection_config_loaded(
        vostok::animation::animation_collection_cook *this,
        vostok::resources::queries_result *data)
{
  const vostok::variant<32> **m_parent_query; // ebx
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::particle::particle_system_instance_impl *m_object; // edi
  vostok::particle::particle_system_instance_impl *v5; // esi
  vostok::configs::binary_config_value *v6; // ecx
  unsigned int v7; // eax
  vostok::resources::query_result_for_cook *v8; // ecx
  vostok::configs::binary_config_value *v9; // eax
  vostok::particle::particle_system_instance_impl *v10; // ecx
  vostok::animation::animation_collection_cook *v11; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v12; // [esp-Ch] [ebp-28h] BYREF
  vostok::configs::binary_config_value *v13; // [esp-8h] [ebp-24h]
  const vostok::variant<32> **v14; // [esp-4h] [ebp-20h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config_ptr; // [esp+10h] [ebp-Ch]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v16; // [esp+14h] [ebp-8h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v17; // [esp+18h] [ebp-4h] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  m_parent_query = (const vostok::variant<32> **)data->m_parent_query;
  config_ptr.m_object = (vostok::configs::binary_config *)this;
  m_result = (vostok::resources::query_result_for_cook *)data->m_result;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v16,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::particle::particle_system_instance_impl *)v16.m_object;
    v5 = 0;
    v17.m_object = 0;
    if ( v16.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v17);
      v5 = m_object;
      v17.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v16);
    if ( debug_macro_helper_ignore_always_55
      || vostok::configs::binary_config_value::value_exists(
           v6,
           (int)v5->m_lods[0].m_template.m_object,
           (unsigned int)&stru_7FF1F0.m_max_end) )
    {
      v9 = vostok::configs::binary_config_value::operator[](
             (vostok::configs::binary_config_value *)v5->m_lods[0].m_template.m_object,
             (char *)&stru_7FF1F0.m_max_end);
      v14 = m_parent_query;
      v13 = v9;
      v12.m_object = v10;
      vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v12,
        &v17);
      vostok::animation::animation_collection_cook::request_items(
        v11,
        (const vostok::variant<32> *)&savedregs,
        (const bool *)&v17,
        (const unsigned int *)&v12,
        config_ptr,
        (const vostok::configs::binary_config_value *)v12.m_object,
        v13,
        v14);
    }
    else
    {
      v7 = occurances_left_28;
      if ( occurances_left_28 == -1 )
        v7 = 10;
      v8 = (vostok::resources::query_result_for_cook *)v7;
      occurances_left_28 = v7 - 1;
      if ( v7 )
      {
        HIBYTE(data) = 0;
        vostok::debug::on_error(
          (bool *)&data + 3,
          process_error_false,
          (bool *)"config_ptr->get_root().value_exists( \"collection\" )",
          ".\\animation_collection_cook.cpp",
          "vostok::animation::animation_collection_cook::collection_config_loaded",
          (const char *)0x47);
        if ( vostok::debug::is_debugger_present() || HIBYTE(data) )
          __debugbreak();
      }
      vostok::resources::query_result_for_cook::finish_query_impl(
        v8,
        (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_parent_query,
        result_success,
        assert_on_fail_true,
        result_out_of_memory|0x8);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v17);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_result,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_parent_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
