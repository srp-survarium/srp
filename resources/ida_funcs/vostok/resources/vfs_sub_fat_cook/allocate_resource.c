// local variable allocation has failed, the output may be wrong!
void __thiscall vostok::resources::vfs_sub_fat_cook::allocate_resource(
        vostok::resources::vfs_sub_fat_cook *this,
        vostok::mutable_buffer *result,
        vostok::const_buffer in_query,
        int a4,
        bool file_exist)
{
  vostok::resources::vfs_sub_fat_cook *v5; // ecx
  _BYTE v6[600]; // [esp-264h] [ebp-26Ch] BYREF
  unsigned int m_size; // [esp-Ch] [ebp-14h]
  int v8; // [esp-8h] [ebp-10h]
  BOOL v9; // [esp-4h] [ebp-Ch]

  v9 = file_exist;
  v8 = a4;
  m_size = in_query.m_size;
  qmemcpy(v6, in_query.m_data, sizeof(v6));
  survarium::weapon_user_dead_state::finalize(0);
  vostok::resources::vfs_sub_fat_cook::create_resource(
    v5,
    (vostok::resources::query_result_for_cook *)result,
    in_query,
    *(vostok::mutable_buffer *)(&file_exist - 4));
}
