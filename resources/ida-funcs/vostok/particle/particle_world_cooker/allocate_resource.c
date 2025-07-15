vostok::mutable_buffer *__thiscall vostok::particle::particle_world_cooker::allocate_resource(
        vostok::particle::particle_world_cooker *this,
        vostok::mutable_buffer *result,
        vostok::resources::query_result_for_cook *in_query,
        vostok::const_buffer raw_file_data,
        bool file_exist)
{
  char *v5; // eax
  char *v6; // ecx
  vostok::mutable_buffer *v7; // eax

  v5 = type_info::raw_name(&unsigned char `RTTI Type Descriptor');
  v6 = (char *)vostok::memory::g_resources_unmanaged_allocator.call_malloc(
                 &vostok::memory::g_resources_unmanaged_allocator,
                 raw_file_data.m_size + 432,
                 v5,
                 "vostok::particle::particle_world_cooker::allocate_resource",
                 ".\\particle_world_cooker.cpp",
                 28);
  v7 = result;
  result->m_data = v6;
  result->m_size = raw_file_data.m_size + 432;
  if ( !v6 )
  {
    in_query->m_out_of_memory.type = &vostok::resources::unmanaged_memory;
    in_query->m_out_of_memory.size = raw_file_data.m_size + 432;
  }
  return v7;
}
