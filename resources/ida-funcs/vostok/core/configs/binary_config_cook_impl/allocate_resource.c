vostok::mutable_buffer *__thiscall vostok::core::configs::binary_config_cook_impl::allocate_resource(
        vostok::core::configs::binary_config_cook_impl *this,
        vostok::mutable_buffer *result,
        vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *in_query,
        vostok::const_buffer raw_file_data,
        bool file_exist)
{
  char *v5; // ecx
  vostok::mutable_buffer *v6; // eax

  v5 = (char *)vostok::memory::g_resources_unmanaged_allocator.call_malloc(
                 &vostok::memory::g_resources_unmanaged_allocator,
                 280,
                 "binary config",
                 "vostok::core::configs::binary_config_cook_impl::allocate_resource",
                 ".\\configs_binary_config_cook.cpp",
                 41);
  if ( v5 )
  {
    v6 = result;
    result->m_data = v5;
    result->m_size = 280;
  }
  else
  {
    in_query[6].m_allocated_count = (unsigned int)&vostok::resources::unmanaged_memory;
    in_query[6].m_max_count = 280;
    vostok::resources::query_result_for_cook::finish_query_impl(
      0,
      in_query,
      result_cannot_lock|result_success,
      assert_on_fail_true,
      result_fail);
    v6 = result;
    result->m_data = 0;
    result->m_size = 0;
  }
  return v6;
}
