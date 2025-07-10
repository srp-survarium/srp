void __thiscall vostok::render::speedtree_instance_cook::on_speedtree_loaded(
        vostok::render::speedtree_instance_cook *this,
        vostok::render::speedtree_tree_base *data,
        vostok::resources::query_result_for_cook *parent_query)
{
  bool v3; // zf
  vostok::resources::unmanaged_resource *v4; // eax
  vostok::render::speedtree_tree_base *v5; // ebx
  vostok::resources::unmanaged_intrusive_base *v6; // ecx
  int *v7; // eax
  vostok::render::speedtree_instance_impl *v8; // ecx
  vostok::configs::binary_config *v9; // eax
  vostok::configs::binary_config *v10; // esi
  vostok::resources::query_result_for_cook *v11; // edi
  vostok::resources::query_result_for_cook *v12; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v13; // [esp-Ch] [ebp-20h] BYREF
  const vostok::resources::memory_type *v14; // [esp-8h] [ebp-1Ch]
  vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> v15[6]; // [esp-4h] [ebp-18h] BYREF

  v3 = *(_DWORD *)&data[1].m_children_resources.gapC == 0;
  v15[5].m_object = 0;
  if ( v3 && data[1].m_children_resources.m_first != (vostok::resources::resource_link *)1 )
  {
    v15[0].m_object = (vostok::render::speedtree_tree_base *)((char *)data + 300);
    data = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v15[0].m_object);
    v4 = data;
    v5 = 0;
    if ( data )
    {
      v6 = &data->vostok::resources::unmanaged_intrusive_base;
      v5 = data;
      _InterlockedExchangeAdd(&data->m_reference_count, 1u);
      if ( !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v6, v4);
    }
    v7 = vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
           0x158u);
    if ( v7 )
    {
      v8 = (vostok::render::speedtree_instance_impl *)v15;
      v15[0].m_object = 0;
      if ( v5 )
      {
        v15[0].m_object = v5;
        v8 = (vostok::render::speedtree_instance_impl *)&v5->vostok::resources::unmanaged_intrusive_base;
        _InterlockedExchangeAdd(&v5->m_reference_count, 1u);
      }
      vostok::render::speedtree_instance_impl::speedtree_instance_impl(v8, (int)v7, v15[0]);
    }
    else
    {
      v9 = 0;
    }
    v10 = 0;
    if ( v9 )
    {
      v10 = v9;
      _InterlockedExchangeAdd(&v9->m_reference_count, 1u);
    }
    v15[0].m_object = (vostok::render::speedtree_tree_base *)344;
    v14 = &vostok::resources::nocache_memory;
    v13.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v13,
      v10);
    v11 = parent_query;
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      parent_query,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v13.m_object,
      v14,
      (unsigned int)v15[0].m_object);
    vostok::resources::query_result_for_cook::finish_query_impl(v12, (int)v11, result_success, assert_on_fail_true, 0);
    if ( v10 && !_InterlockedExchangeAdd(&v10->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v10->vostok::resources::unmanaged_intrusive_base, v10);
    if ( v5 )
    {
      if ( !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
    }
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      (int)parent_query,
      result_error,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)0xB);
  }
}
