void __thiscall survarium::timelimit_rule_core_cook::translate_query(
        survarium::timelimit_rule_core_cook *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *parent)
{
  survarium::timelimit_rule_core_cook_vtbl *v3; // eax
  survarium::pure_game_effect_emitter_base *v4; // eax
  survarium::pure_game_effect_emitter_base *v5; // ecx
  vostok::resources::query_result_for_cook *v6; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v7; // [esp-4h] [ebp-24h] BYREF
  survarium::pure_game_effect_emitter_base *v8; // [esp+Ch] [ebp-14h] BYREF
  vostok::resources::memory_usage_type v9; // [esp+10h] [ebp-10h] BYREF
  survarium::timelimit_rule_query_data out_value; // [esp+18h] [ebp-8h] BYREF

  vostok::variant<32>::try_get<survarium::timelimit_rule_query_data>(
    (vostok::variant<32> *)parent[66].m_object,
    &out_value);
  v3 = this->__vftable;
  v8 = 0;
  v4 = (survarium::pure_game_effect_emitter_base *)v3->create_resource(this, &out_value, (unsigned int *)&v8);
  v7.m_object = v8;
  v9.type = &vostok::resources::nocache_memory;
  v9.size = (unsigned int)v8;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v7,
    v4);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(&v9, v5, parent, v7);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v6,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
