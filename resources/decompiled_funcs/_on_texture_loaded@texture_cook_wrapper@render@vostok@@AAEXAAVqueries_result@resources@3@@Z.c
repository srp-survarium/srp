void __thiscall vostok::render::texture_cook_wrapper::on_texture_loaded(
        vostok::render::texture_cook_wrapper *this,
        vostok::resources::queries_result *result)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::resources::query_result_for_cook *m_parent_query; // edi
  vostok::resources::query_result_for_cook *v4; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v5; // [esp-8h] [ebp-Ch] BYREF
  vostok::render::texture_cook_wrapper *v6; // [esp+0h] [ebp-4h]

  v6 = this;
  m_result = (vostok::resources::query_result_for_cook *)result->m_result;
  m_parent_query = result->m_parent_query;
  v6 = 0;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    v5.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &v5,
      &result->m_queries[0].m_managed_resource);
    vostok::resources::query_result_for_cook::set_managed_resource(
      m_parent_query,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v5.m_object);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v4,
      (int)m_parent_query,
      result_success,
      assert_on_fail_true,
      0);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_result,
      (int)m_parent_query,
      result_error,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)0xB);
  }
}
