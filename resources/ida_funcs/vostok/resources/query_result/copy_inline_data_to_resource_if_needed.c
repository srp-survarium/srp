char __usercall vostok::resources::query_result::copy_inline_data_to_resource_if_needed@<al>(
        vostok::resources::query_result *this@<ecx>,
        vostok::vfs::vfs_iterator *a2@<esi>)
{
  vostok::const_buffer inline_data; // [esp+0h] [ebp-Ch] BYREF

  vostok::const_buffer::const_buffer((vostok::mutable_buffer *)&inline_data);
  vostok::vfs::vfs_iterator::get_inline_data(a2 + 10, &inline_data);
  vostok::resources::query_result::copy_data_to_resource(
    (vostok::resources::query_result *)inline_data.m_size,
    (int)a2,
    inline_data);
  return 1;
}
