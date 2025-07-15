void __thiscall vostok::sound::sound_collection_cook::collection_config_loaded(
        vostok::sound::sound_collection_cook *this,
        vostok::particle::particle_system_instance_impl *data)
{
  vostok::resources::query_result_for_cook *m_uid; // ebx
  vostok::particle::particle_system_instance_impl *v3; // esi
  vostok::particle::particle_system_instance_impl *v4; // ecx
  unsigned int v5; // eax
  vostok::resources::query_result_for_cook *v6; // ecx
  vostok::sound::sound_collection_cook *v7; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v8; // [esp-8h] [ebp-1Ch] BYREF
  vostok::resources::query_result_for_cook *v9; // [esp-4h] [ebp-18h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config_ptr; // [esp+Ch] [ebp-8h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> other; // [esp+10h] [ebp-4h] BYREF

  m_uid = (vostok::resources::query_result_for_cook *)data->m_uid;
  config_ptr.m_object = (vostok::configs::binary_config *)this;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_lods[1].m_emitter_instance_list);
  v3 = data;
  other.m_object = 0;
  if ( data )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&other);
    other.m_object = v3;
    _InterlockedExchangeAdd(&v3->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  if ( debug_macro_helper_ignore_always_7
    || vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)v4,
         (int)other.m_object->m_lods[0].m_template.m_object,
         (unsigned int)&stru_7FF1F0.m_max_end) )
  {
    v9 = m_uid;
    v8.m_object = v4;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v8,
      &other);
    vostok::sound::sound_collection_cook::request_items(
      v7,
      (vostok::sound::sound_collection_cook *)config_ptr.m_object,
      (vostok::resources::query_result_for_cook *const)v8.m_object,
      v9);
  }
  else
  {
    v5 = occurances_left_6;
    if ( occurances_left_6 == -1 )
      v5 = 10;
    v6 = (vostok::resources::query_result_for_cook *)v5;
    occurances_left_6 = v5 - 1;
    if ( v5 )
    {
      HIBYTE(data) = 0;
      vostok::debug::on_error(
        (bool *)&data + 3,
        process_error_false,
        (bool *)"config_ptr->get_root().value_exists( \"collection\" )",
        ".\\sound_collection_cook.cpp",
        "vostok::sound::sound_collection_cook::collection_config_loaded",
        (const char *)0x41);
      if ( vostok::debug::is_debugger_present() || HIBYTE(data) )
        __debugbreak();
    }
    vostok::resources::query_result_for_cook::finish_query_impl(
      v6,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_uid,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&other);
}
