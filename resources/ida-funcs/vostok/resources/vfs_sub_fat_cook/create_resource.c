void __userpurge vostok::resources::vfs_sub_fat_cook::create_resource(
        vostok::resources::vfs_sub_fat_cook *this@<ecx>,
        vostok::resources::vfs_sub_fat_cook *in_out_query,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  vostok::resources::vfs_sub_fat_cook *v4; // ecx
  _BYTE v5[616]; // [esp-278h] [ebp-280h] BYREF
  vostok::const_buffer v6; // [esp-10h] [ebp-18h]
  vostok::mutable_buffer v7; // [esp-8h] [ebp-10h]

  v7 = in_out_unmanaged_resource_buffer;
  v6 = raw_file_data;
  qmemcpy(v5, in_out_query, sizeof(v5));
  vostok::memory::process_allocator::finalize_impl(0);
  survarium::network_client::load_replay(v4, in_out_query);
}
