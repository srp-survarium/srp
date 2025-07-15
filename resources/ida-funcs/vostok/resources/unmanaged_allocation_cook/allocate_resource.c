vostok::mutable_buffer *__thiscall vostok::resources::unmanaged_allocation_cook::allocate_resource(
        vostok::resources::unmanaged_allocation_cook *this,
        vostok::mutable_buffer *result,
        vostok::resources::query_result_for_cook *in_query,
        vostok::const_buffer raw_file_data,
        bool file_exist)
{
  char *v5; // esi
  unsigned __int8 *v6; // eax

  v5 = &vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&raw_file_data)->m_name[221];
  type_info::name(&char `RTTI Type Descriptor', &__type_info_root_node);
  v6 = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(
                            &vostok::memory::g_resources_unmanaged_allocator,
                            (unsigned int)v5);
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    result,
    v6,
    (unsigned int)v5);
  return result;
}
