void __userpurge survarium::damage_zone_core_cook::create_resource(
        survarium::damage_zone_core_cook *this@<ecx>,
        int *a2@<eax>,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *parent,
        const vostok::configs::binary_config_value *cfg,
        vostok::resources::queries_result *data)
{
  vostok::memory::doug_lea_allocator *v6; // ecx
  char *v7; // eax
  survarium::pure_game_effect_emitter_base *v8; // ebx
  survarium::pure_game_effect_emitter_base *v9; // ecx
  int v10; // eax
  survarium::pure_game_effect_emitter_base *v11; // ecx
  vostok::resources::query_result_for_cook *v12; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v13[4]; // [esp+10h] [ebp-34h] BYREF
  int v14; // [esp+20h] [ebp-24h]
  vostok::resources::memory_usage_type v15; // [esp+24h] [ebp-20h] BYREF
  vostok::memory::base_allocator v16; // [esp+2Ch] [ebp-18h] BYREF
  int v17; // [esp+40h] [ebp-4h]

  v14 = (*(int (__thiscall **)(int *, const vostok::configs::binary_config_value *))(*a2 + 40))(a2, cfg);
  v7 = vostok::memory::doug_lea_allocator::malloc_impl(
         v6,
         (int)survarium::g_allocator,
         v14,
         "damage_zone",
         (const char *const)v13[1].m_object,
         (const char *const)v13[2].m_object,
         (const unsigned int)v13[3].m_object);
  memset(&v16.m_arena_start, 0, 13);
  v16.__vftable = (vostok::memory::base_allocator_vtbl *)&vostok::memory::stack_allocator::`vftable';
  v17 = 0;
  vostok::memory::base_allocator::initialize(&v16, v7, (unsigned int)v14, "damage_zone");
  v8 = (survarium::pure_game_effect_emitter_base *)(*(int (__thiscall **)(int *, vostok::memory::base_allocator *))(*a2 + 52))(
                                                     a2,
                                                     &v16);
  ((void (__thiscall *)(survarium::pure_game_effect_emitter_base *, const vostok::configs::binary_config_value *))v8[1].is_increasing_quality)(
    &v8[1],
    cfg);
  if ( data )
  {
    v10 = *a2;
    v15.type = 0;
    (*(void (__thiscall **)(int *, survarium::pure_game_effect_emitter_base *, const vostok::configs::binary_config_value *, vostok::resources::queries_result *, vostok::resources::memory_usage_type *, vostok::memory::base_allocator *))(v10 + 48))(
      a2,
      v8,
      cfg,
      data,
      &v15,
      &v16);
  }
  v13[0].m_object = v9;
  v15.type = &vostok::resources::nocache_memory;
  v15.size = v14;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    v13,
    v8);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(&v15, v11, parent, v13[0]);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v12,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
