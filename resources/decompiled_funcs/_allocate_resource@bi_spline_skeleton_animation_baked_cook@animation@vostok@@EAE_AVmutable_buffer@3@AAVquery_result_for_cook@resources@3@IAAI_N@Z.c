vostok::mutable_buffer *__thiscall vostok::animation::bi_spline_skeleton_animation_baked_cook::allocate_resource(
        vostok::animation::bi_spline_skeleton_animation_baked_cook *this,
        vostok::mutable_buffer *result,
        vostok::resources::query_result_for_cook *in_query,
        unsigned int file_size,
        unsigned int *out_offset_to_file,
        bool file_exist)
{
  unsigned __int8 *v6; // eax

  *out_offset_to_file = 272;
  type_info::name(&char `RTTI Type Descriptor', &__type_info_root_node);
  v6 = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(
                            &vostok::memory::g_resources_unmanaged_allocator,
                            file_size + 272);
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    result,
    v6,
    file_size + 272);
  return result;
}
