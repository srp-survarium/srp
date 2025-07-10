void __usercall vostok::resources::query_result::on_save_operation_end(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::query_result *v3; // ecx
  int v4; // edi
  vostok::resources::cook_base::result_enum v5; // eax
  char *v6; // edi
  vostok::vfs::vfs_iterator v7; // [esp-10h] [ebp-1Ch] BYREF

  if ( (*(_DWORD *)(a2 + 688) & 8) != 0 )
  {
    *(_DWORD *)(*(_DWORD *)(a2 + 624) + 256) = *(_DWORD *)(a2 + 256);
    vostok::vfs::vfs_iterator::vfs_iterator(&v7, (const vostok::vfs::vfs_iterator *)(a2 + 160));
    vostok::resources::query_result::late_set_fat_it(v3, *(_DWORD *)(a2 + 624), v7);
    v4 = *(_DWORD *)(a2 + 624);
    v5 = *(_DWORD *)(v4 + 260);
    v7.m_type = v5 != result_error ? type_unset : type_not_scanned|0x8;
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)v7.m_type,
      v4,
      v5,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)v7.m_type);
  }
  if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(a2 + 684), 0xFFFFFFFF) )
    vostok::resources::query_result::end_query_might_destroy_this_impl(this, (vostok::resources::query_result *)a2);
  v6 = __RTCastToVoid((void **)a2);
  (**(void (__thiscall ***)(int, _DWORD))a2)(a2, 0);
  if ( v6 )
  {
    vostok::memory::g_resources_helper_allocator.m_out_of_memory = 0;
    vostok_mspace_free((malloc_state *)vostok::memory::g_resources_helper_allocator.m_arena, v6);
  }
}
