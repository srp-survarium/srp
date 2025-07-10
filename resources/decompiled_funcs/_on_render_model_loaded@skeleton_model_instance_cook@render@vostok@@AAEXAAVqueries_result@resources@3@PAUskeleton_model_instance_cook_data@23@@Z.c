void __thiscall vostok::render::skeleton_model_instance_cook::on_render_model_loaded(
        vostok::render::skeleton_model_instance_cook *this,
        vostok::resources::unmanaged_resource *result,
        vostok::render::skeleton_model_instance_cook_data *cook_data)
{
  vostok::resources::query_result_for_cook *m_lock; // ecx
  vostok::resources::unmanaged_resource *v4; // ebx
  vostok::resources::unmanaged_resource *v5; // esi
  vostok::render::skeleton_model_instance_cook_data *v6; // edi
  vostok::resources::unmanaged_intrusive_base *v7; // eax
  vostok::resources::unmanaged_intrusive_base *v8; // ecx
  vostok::resources::unmanaged_resource *m_object; // eax
  bool v10; // zf
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_children_resources; // [esp-4h] [ebp-18h]

  m_lock = (vostok::resources::query_result_for_cook *)result->m_parent_resources.m_lock;
  if ( m_lock == (vostok::resources::query_result_for_cook *)1 )
  {
    p_m_children_resources = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&result[1].m_children_resources;
    result = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_children_resources);
    v4 = result;
    v5 = 0;
    if ( result )
    {
      v5 = result;
      _InterlockedExchangeAdd(&result->m_reference_count, 1u);
    }
    v6 = cook_data;
    v7 = 0;
    if ( v5 )
    {
      v7 = (vostok::resources::unmanaged_intrusive_base *)v5;
      _InterlockedExchangeAdd(&v5->m_reference_count, 1u);
    }
    v8 = v7;
    m_object = v6->render_model.m_object;
    v6->render_model.m_object = (vostok::render::render_model_instance *)v8;
    if ( m_object )
    {
      v8 = &m_object->vostok::resources::unmanaged_intrusive_base;
      if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v8, m_object);
    }
    if ( v5 )
    {
      v8 = &v5->vostok::resources::unmanaged_intrusive_base;
      if ( !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v8, v5);
    }
    if ( v4 )
    {
      v8 = &v4->vostok::resources::unmanaged_intrusive_base;
      if ( !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v8, v4);
    }
    v10 = !v6->skeleton_ready;
    v6->render_model_ready = 1;
    if ( !v10 )
      vostok::render::skeleton_model_instance_cook::on_all_subresources_ready(
        (vostok::render::skeleton_model_instance_cook *)v8,
        v6);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_lock,
      (int)cook_data->parent_query,
      result_error,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)0xB);
  }
}
