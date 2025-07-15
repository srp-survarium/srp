void __usercall vostok::resources::query_result_for_user::query_result_for_user(
        vostok::resources::query_result_for_user *this@<ecx>,
        int a2@<esi>)
{
  unsigned int v2; // [esp+0h] [ebp-4h]

  vostok::resources::resource_base::resource_base((vostok::resources::resource_base *)2, a2, raw_data_class, 1u, v2);
  *(_DWORD *)a2 = &vostok::resources::query_result_for_user::`vftable';
  vostok::const_buffer::const_buffer((vostok::mutable_buffer *)(a2 + 208));
  *(_DWORD *)(a2 + 216) = 0;
  *(_DWORD *)(a2 + 220) = 0;
  *(_DWORD *)(a2 + 224) = 0;
  vostok::vfs::vfs_locked_iterator::vfs_locked_iterator((vostok::vfs::vfs_locked_iterator *)(a2 + 228));
  *(_DWORD *)(a2 + 248) = 0;
  *(_DWORD *)(a2 + 252) = 0;
  *(_DWORD *)(a2 + 256) = 0;
  *(_DWORD *)(a2 + 260) = 0;
}
