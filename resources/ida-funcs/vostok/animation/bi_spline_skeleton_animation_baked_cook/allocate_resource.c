vostok::mutable_buffer *__thiscall vostok::animation::bi_spline_skeleton_animation_baked_cook::allocate_resource(
        vostok::animation::bi_spline_skeleton_animation_baked_cook *this,
        vostok::mutable_buffer *result,
        vostok::resources::query_result_for_cook *in_query,
        unsigned int file_size,
        unsigned int *out_offset_to_file,
        bool file_exist)
{
  const char *v6; // eax

  *out_offset_to_file = 272;
  v6 = type_info::name(&char `RTTI Type Descriptor', &__type_info_root_node);
  result->m_data = (char *)vostok::resources::allocate_unmanaged_memory(file_size + 272, v6);
  result->m_size = file_size + 272;
  return result;
}
