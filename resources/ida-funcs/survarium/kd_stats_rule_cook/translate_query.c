void __thiscall survarium::kd_stats_rule_cook::translate_query(
        survarium::kd_stats_rule_cook *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *parent)
{
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v2; // ebx
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  char *v6; // eax
  survarium::kd_stats_rule *v7; // ecx
  survarium::pure_game_effect_emitter_base *v8; // eax
  survarium::pure_game_effect_emitter_base *v9; // ecx
  vostok::resources::query_result_for_cook *v10; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v11[4]; // [esp-4h] [ebp-18h] BYREF
  vostok::resources::memory_usage_type v12; // [esp+Ch] [ebp-8h] BYREF

  v2 = parent;
  vostok::variant<32>::try_get<survarium::kd_stats_rule_query_data>(
    (vostok::variant<32> *)this,
    (int)parent[66].m_object,
    (survarium::kd_stats_rule_query_data *)&parent);
  v3 = survarium::g_allocator;
  v4 = type_info::raw_name(&survarium::kd_stats_rule `RTTI Type Descriptor');
  v6 = vostok::memory::doug_lea_allocator::malloc_impl(
         v5,
         (int)v3,
         0x1B8u,
         v4,
         (const char *const)v11[1].m_object,
         (const char *const)v11[2].m_object,
         (const unsigned int)v11[3].m_object);
  if ( v6 )
    survarium::kd_stats_rule::kd_stats_rule(v7, (int)v6, (const survarium::match_options *)parent);
  else
    v8 = 0;
  v11[0].m_object = (survarium::pure_game_effect_emitter_base *)v7;
  v12.size = 440;
  v12.type = &vostok::resources::nocache_memory;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    v11,
    v8);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(&v12, v9, v2, v11[0]);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v10,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v2,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
