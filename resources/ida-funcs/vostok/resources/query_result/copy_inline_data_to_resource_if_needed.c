char __usercall vostok::resources::query_result::copy_inline_data_to_resource_if_needed@<al>(
        vostok::resources::query_result *this@<ecx>,
        vostok::vfs::vfs_iterator *a2@<edi>)
{
  vostok::resources::query_result *v2; // ecx
  vostok::const_buffer v4; // [esp+8h] [ebp-8h] BYREF

  v4.m_data = 0;
  v4.m_size = 0;
  vostok::vfs::vfs_iterator::get_inline_data(a2 + 10, &v4);
  vostok::resources::query_result::copy_data_to_resource(
    v2,
    (vostok::const_buffer)__PAIR64__((unsigned int)v4.m_data, (unsigned int)a2),
    (vostok::resources::managed_resource *)v4.m_size);
  return 1;
}
