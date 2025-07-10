void __thiscall vostok::render::material_cook::on_material_config_loaded(
        vostok::render::material_cook *this,
        vostok::resources::unmanaged_resource *result)
{
  vostok::resources::query_result_for_cook *m_lock; // ecx
  vostok::resources::query_result_for_cook *m_uid; // edi
  vostok::resources::unmanaged_resource *v4; // esi
  vostok::resources::unmanaged_intrusive_base *v5; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_children_resources; // [esp-4h] [ebp-14h]
  vostok::configs::binary_config *v7; // [esp+0h] [ebp-10h]

  m_lock = (vostok::resources::query_result_for_cook *)result->m_parent_resources.m_lock;
  m_uid = (vostok::resources::query_result_for_cook *)result->m_uid;
  if ( m_lock == (vostok::resources::query_result_for_cook *)1 )
  {
    p_m_children_resources = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&result[1].m_children_resources;
    result = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_children_resources);
    v4 = result;
    if ( result )
    {
      v5 = &result->vostok::resources::unmanaged_intrusive_base;
      if ( !_InterlockedExchangeAdd(&result->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v5, v4);
    }
    vostok::render::material_cook::on_material_binary_config_loaded(m_uid, (vostok::render::material_cook *)v4, v7);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_lock,
      (int)m_uid,
      result_error,
      assert_on_fail_false,
      (vostok::resources::query_result_for_cook *)0xB);
  }
}
