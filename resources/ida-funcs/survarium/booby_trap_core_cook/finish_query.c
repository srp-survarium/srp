void __userpurge survarium::booby_trap_core_cook::finish_query(
        survarium::booby_trap_core_cook *this@<ecx>,
        survarium::booby_trap_core *resource@<eax>,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *parent)
{
  survarium::pure_game_effect_emitter_base *v3; // edi
  survarium::booby_trap_core_cook_vtbl *v4; // eax
  unsigned int v5; // eax
  survarium::pure_game_effect_emitter_base *v6; // ecx
  survarium::pure_game_effect_emitter_base *v7; // ecx
  vostok::resources::query_result_for_cook *v8; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v9; // [esp-4h] [ebp-18h] BYREF
  vostok::resources::memory_usage_type v10; // [esp+8h] [ebp-Ch] BYREF

  if ( resource )
    v3 = (survarium::pure_game_effect_emitter_base *)&resource->vostok::resources::unmanaged_resource;
  else
    v3 = 0;
  v4 = this->__vftable;
  v10.type = &vostok::resources::nocache_memory;
  v5 = v4->get_derived_resource_size(this);
  v9.m_object = v6;
  v10.size = v5;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v9,
    v3);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(&v10, v7, parent, v9);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v8,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
