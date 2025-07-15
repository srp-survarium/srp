void __thiscall vostok::render::texture_cook_wrapper::on_texture_loaded(
        vostok::render::texture_cook_wrapper *this,
        vostok::resources::queries_result *result)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *m_parent_query; // edi
  vostok::resources::query_result_for_cook *v4; // ecx
  vostok::resources::query_result_for_cook *v5; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v6[3]; // [esp-Ch] [ebp-Ch] BYREF

  v6[2].m_object = (vostok::resources::managed_resource *)this;
  m_result = (vostok::resources::query_result_for_cook *)result->m_result;
  m_parent_query = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)result->m_parent_query;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    v6[0].m_object = (vostok::resources::managed_resource *)1;
    vostok::resources::query_result_for_user::get_managed_resource(&result->m_queries[0], v6);
    vostok::resources::query_result_for_cook::set_managed_resource(
      v4,
      m_parent_query,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v6[0].m_object);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v5,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_parent_query,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_result,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_parent_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
