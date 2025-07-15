vostok::mutable_buffer *__thiscall vostok::render::user_mesh_cook::allocate_resource(
        vostok::render::user_mesh_cook *this,
        vostok::mutable_buffer *result,
        vostok::resources::query_result_for_cook *in_query,
        vostok::const_buffer raw_file_data,
        bool file_exist)
{
  vostok::mutable_buffer *v5; // eax

  v5 = result;
  result->m_data = 0;
  result->m_size = 0;
  return v5;
}
