void __thiscall vostok::resources::vfs_sub_fat_cook::create_resource(
        vostok::resources::vfs_sub_fat_cook *this,
        vostok::resources::query_result_for_cook *in_out_query,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  _BYTE v4[600]; // [esp-268h] [ebp-270h] BYREF
  vostok::const_buffer v5; // [esp-10h] [ebp-18h]
  vostok::mutable_buffer v6; // [esp-8h] [ebp-10h]

  v6 = in_out_unmanaged_resource_buffer;
  v5 = raw_file_data;
  qmemcpy(v4, in_out_query, sizeof(v4));
  survarium::weapon_user_dead_state::finalize(0);
  JUMPOUT(0x56F94);
}
