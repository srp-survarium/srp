void __thiscall survarium::grenade_set_core_cook::finish_query(
        survarium::grenade_set_core_cook *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *parent,
        survarium::pure_game_effect_emitter_base *resource)
{
  survarium::grenade_set_core_cook_vtbl *v3; // eax
  unsigned int v4; // eax
  survarium::pure_game_effect_emitter_base *v5; // ecx
  survarium::pure_game_effect_emitter_base *v6; // ecx
  vostok::resources::query_result_for_cook *v7; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v8; // [esp-4h] [ebp-14h] BYREF
  vostok::resources::memory_usage_type v9; // [esp+8h] [ebp-8h] BYREF

  v3 = this->__vftable;
  v9.type = &vostok::resources::nocache_memory;
  v4 = v3->get_derived_resource_size(this);
  v8.m_object = v5;
  v9.size = v4;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v8,
    resource);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(&v9, v6, parent, v8);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v7,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
