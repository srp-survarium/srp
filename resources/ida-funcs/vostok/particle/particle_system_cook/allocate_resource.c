vostok::mutable_buffer *__thiscall vostok::particle::particle_system_cook::allocate_resource(
        vostok::particle::particle_system_cook *this,
        vostok::mutable_buffer *result,
        vostok::resources::query_result_for_cook *in_query,
        unsigned int file_size,
        unsigned int *out_offset_to_file,
        bool file_exist)
{
  char *v6; // eax

  *out_offset_to_file = 280;
  v6 = type_info::raw_name(&char `RTTI Type Descriptor');
  result->m_data = (char *)vostok::memory::g_resources_unmanaged_allocator.call_malloc(
                             &vostok::memory::g_resources_unmanaged_allocator,
                             file_size + 280,
                             v6,
                             "vostok::particle::particle_system_cook::allocate_resource",
                             "c:\\survarium.deploy\\sources\\vostok\\particle\\sources\\particle_system_cook.h",
                             34);
  result->m_size = file_size + 280;
  return result;
}
