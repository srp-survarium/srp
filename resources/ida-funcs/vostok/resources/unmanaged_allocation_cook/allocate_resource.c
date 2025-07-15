vostok::mutable_buffer *__thiscall vostok::resources::unmanaged_allocation_cook::allocate_resource(
        vostok::resources::unmanaged_allocation_cook *this,
        vostok::mutable_buffer *result,
        vostok::resources::query_result_for_cook *in_query,
        vostok::const_buffer raw_file_data,
        bool file_exist)
{
  const char *v5; // eax

  v5 = type_info::name(&char `RTTI Type Descriptor', &__type_info_root_node);
  result->m_data = (char *)vostok::resources::allocate_unmanaged_memory(raw_file_data.m_size + 272, v5);
  result->m_size = raw_file_data.m_size + 272;
  return result;
}
