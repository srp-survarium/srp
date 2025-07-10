void __thiscall survarium::profile_skin_visual_cook::on_visual_loaded(
        survarium::profile_skin_visual_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::query_result_for_cook *parent,
        vostok::render::skeleton_combined_cook_data *cook_data)
{
  vostok::resources::query_result_for_cook *v4; // ecx
  vostok::render::skeleton_combined_cook_data *v5; // ecx
  int f; // esi
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v7; // [esp-Ch] [ebp-1Ch] BYREF
  const vostok::resources::memory_type *v8; // [esp-8h] [ebp-18h]
  unsigned int v9; // [esp-4h] [ebp-14h]
  int v10; // [esp+Ch] [ebp-4h]

  v9 = 272;
  v8 = &vostok::resources::nocache_memory;
  v10 = 0;
  v7.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v7,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    parent,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v7.m_object,
    v8,
    v9);
  vostok::resources::query_result_for_cook::finish_query_impl(v4, result_success, assert_on_fail_true, error_type_unset);
  f = (int)survarium::g_allocator.f_.f_;
  if ( cook_data )
  {
    vostok::render::skeleton_combined_cook_data::~skeleton_combined_cook_data(v5, cook_data);
    *(_BYTE *)(f + 42) = 0;
    vostok_mspace_free(*(void **)(f + 20), cook_data);
  }
}
