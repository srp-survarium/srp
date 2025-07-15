vostok::mutable_buffer *__thiscall vostok::core::configs::binary_config_cook_impl::allocate_resource(
        vostok::core::configs::binary_config_cook_impl *this,
        vostok::mutable_buffer *result,
        vostok::resources::query_result_for_cook *in_query,
        vostok::const_buffer raw_file_data,
        bool file_exist)
{
  unsigned __int8 *v5; // eax

  v5 = (unsigned __int8 *)vostok::memory::g_resources_unmanaged_allocator.call_malloc(
                            &vostok::memory::g_resources_unmanaged_allocator,
                            280);
  if ( v5 )
  {
    boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
      result,
      v5,
      0x118u);
  }
  else
  {
    in_query->m_out_of_memory.type = &vostok::resources::unmanaged_memory;
    in_query->m_out_of_memory.size = 280;
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)0x118,
      result_out_of_memory,
      assert_on_fail_true,
      error_type_unset);
    boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
      result,
      0,
      0);
  }
  return result;
}
