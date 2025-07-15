void __thiscall vostok::render::scene_cook::on_particle_world_created(
        vostok::render::scene_cook *this,
        vostok::resources::queries_result *result,
        survarium::pure_game_effect_emitter_base *created_resource,
        vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *in_out_query)
{
  survarium::pure_game_effect_emitter_base *m_object; // esi
  survarium::pure_game_effect_emitter_base *v5; // edi
  int v6; // eax
  survarium::pure_game_effect_emitter_base_vtbl *v7; // eax
  survarium::pure_game_effect_emitter_base *v8; // ecx
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v9; // edi
  vostok::resources::query_result_for_cook *v10; // ecx
  vostok::resources::query_result_for_cook *v11; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v12; // [esp-Ch] [ebp-18h] BYREF
  const vostok::resources::memory_type *v13; // [esp-8h] [ebp-14h]
  char *v14; // [esp-4h] [ebp-10h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v15; // [esp+8h] [ebp-4h] BYREF

  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v15,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&result->m_queries[0].m_unmanaged_resource);
  m_object = v15.m_object;
  v5 = created_resource;
  v6 = 0;
  result = 0;
  if ( v15.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
    v6 = (int)m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  result = *(vostok::resources::queries_result **)((char *)&dword_8B9664 + (_DWORD)v5);
  *(int *)((char *)&dword_8B9664 + (_DWORD)v5) = v6;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v15);
  v7 = *(survarium::pure_game_effect_emitter_base_vtbl **)((char *)&dword_8B9664 + (_DWORD)v5);
  v14 = &a003Bi3BiBoost[4];
  v13 = &vostok::resources::nocache_memory;
  v12.m_object = v8;
  *(survarium::pure_game_effect_emitter_base_vtbl **)((char *)&v5->__vftable + (_DWORD)&loc_5534B0 + 4) = v7;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v12,
    v5);
  v9 = in_out_query;
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v10,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)in_out_query,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v12.m_object,
    v13,
    (unsigned int)v14);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v11,
    v9,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
