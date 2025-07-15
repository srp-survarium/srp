vostok::mutable_buffer *__thiscall vostok::render::texture_gpu_converter_cook::allocate_resource(
        vostok::render::texture_gpu_converter_cook *this,
        vostok::mutable_buffer *result,
        vostok::resources::query_result_for_cook *in_query,
        vostok::const_buffer raw_file_data,
        bool file_exist)
{
  char *v5; // ecx
  vostok::mutable_buffer *v6; // eax
  bool v7; // [esp+0h] [ebp-80h]
  vostok::resources::memory_type v8; // [esp+8h] [ebp-78h] BYREF

  v5 = (char *)vostok::render::texture_compressor_allocate(raw_file_data.m_size, v7);
  if ( v5 )
  {
    v6 = result;
    result->m_data = v5;
    result->m_size = raw_file_data.m_size;
  }
  else
  {
    vostok::resources::memory_type::memory_type(&v8, "texture_gpu_converter_cook", 0);
    in_query->m_out_of_memory.type = &v8;
    in_query->m_out_of_memory.size = raw_file_data.m_size;
    result->m_data = 0;
    result->m_size = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)&v8.queue.vostok::threading::mutex);
    return result;
  }
  return v6;
}
