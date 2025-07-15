vostok::mutable_buffer *__thiscall vostok::render::shader_binary_source_cook::allocate_resource(
        vostok::render::shader_binary_source_cook *this,
        vostok::mutable_buffer *result,
        vostok::resources::query_result_for_cook *in_query,
        vostok::const_buffer raw_file_data,
        bool file_exist)
{
  unsigned __int8 *v5; // eax

  v5 = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(
                            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                            0x248u);
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    result,
    v5,
    0x248u);
  return result;
}
