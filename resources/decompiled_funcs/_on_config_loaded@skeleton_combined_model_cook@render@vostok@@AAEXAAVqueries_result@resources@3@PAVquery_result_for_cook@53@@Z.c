void __thiscall vostok::render::skeleton_combined_model_cook::on_config_loaded(
        vostok::render::skeleton_combined_model_cook *this,
        vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *result,
        vostok::resources::query_result_for_cook *parent)
{
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v3; // ebx
  volatile int m_object; // eax
  void *v5; // eax
  vostok::render::skeleton_combined_cook_data *v6; // ecx
  vostok::render::skeleton_combined_cook_data *v7; // eax
  vostok::render::skeleton_combined_cook_data *v8; // edi
  vostok::configs::binary_config *v9; // esi
  vostok::resources::unmanaged_resource *v10; // eax
  vostok::resources::unmanaged_intrusive_base *v11; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v12; // [esp+Ch] [ebp-8h] BYREF
  vostok::resources::query_result_for_cook *v13; // [esp+10h] [ebp-4h]

  v3 = result;
  m_object = (volatile int)result[16].m_object;
  v13 = (vostok::resources::query_result_for_cook *)this;
  if ( m_object == 1 )
  {
    v5 = vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
           0x1C98u);
    if ( v5 )
    {
      vostok::render::skeleton_combined_cook_data::skeleton_combined_cook_data(v6, (int)v5, 1);
      v8 = v7;
    }
    else
    {
      v8 = 0;
    }
    v12.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v12,
      v3 + 75);
    v9 = v12.m_object;
    result = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result,
      v12.m_object);
    if ( v9 && !_InterlockedExchangeAdd(&v9->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v9->vostok::resources::unmanaged_intrusive_base, v9);
    vostok::render::build_from_config(
      (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&result,
      v8);
    vostok::render::skeleton_combined_model_cook::query_resources_by_data(
      (vostok::render::skeleton_combined_model_cook *)parent,
      (vostok::render::skeleton_combined_model_cook *)v13,
      parent,
      v8);
    v10 = (vostok::resources::unmanaged_resource *)result;
    if ( result )
    {
      v11 = (vostok::resources::unmanaged_intrusive_base *)&result[52];
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&result[52], 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v11, v10);
    }
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      result_error,
      assert_on_fail_true,
      error_type_cook_failed);
  }
}
