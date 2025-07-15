void __userpurge vostok::resources::vfs_sub_fat_cook::allocate_resource(
        vostok::resources::vfs_sub_fat_cook *this@<ecx>,
        vostok::resources::query_result_for_cook *result,
        vostok::const_buffer in_query,
        vostok::mutable_buffer a4)
{
  vostok::resources::vfs_sub_fat_cook *v4; // ecx
  _BYTE v5[616]; // [esp-274h] [ebp-27Ch] BYREF
  unsigned int m_size; // [esp-Ch] [ebp-14h]
  char *m_data; // [esp-8h] [ebp-10h]
  int m_size_low; // [esp-4h] [ebp-Ch]

  m_size_low = LOBYTE(a4.m_size);
  m_data = a4.m_data;
  m_size = in_query.m_size;
  qmemcpy(v5, in_query.m_data, sizeof(v5));
  vostok::memory::process_allocator::finalize_impl(0);
  vostok::resources::vfs_sub_fat_cook::create_resource(v4, result, in_query, a4);
}
