void __usercall vostok::resources::query_result::on_save_operation_end(
        vostok::resources::query_result *this@<ecx>,
        void **a2@<eax>)
{
  vostok::resources::query_result_for_cook *v3; // ecx
  char *v4; // edi
  vostok::memory::doug_lea_allocator *v5; // ecx
  vostok::vfs::vfs_iterator v6; // [esp-14h] [ebp-20h] BYREF
  vostok::resources::managed_resource *v7; // [esp-4h] [ebp-10h]
  const char *v8; // [esp+0h] [ebp-Ch]
  const char *v9; // [esp+4h] [ebp-8h]
  unsigned int v10; // [esp+8h] [ebp-4h]

  if ( ((unsigned __int8)a2[176] & 8) != 0 )
  {
    *((_DWORD *)a2[160] + 64) = a2[64];
    v6.m_node = (vostok::vfs::base_node<1> *)a2[40];
    v6.m_link_target = (vostok::vfs::base_node<1> *)a2[41];
    v6.m_type = (vostok::vfs::vfs_iterator::type_enum)a2[42];
    v7 = (vostok::resources::managed_resource *)a2[43];
    v6.m_hashset = (vostok::vfs::vfs_hashset *)a2[160];
    vostok::resources::query_result::late_set_fat_it((vostok::resources::query_result *)&v6.m_node, v6, v7);
    vostok::resources::query_result_for_cook::finish_query(
      v3,
      *((vostok::resources::cook_base::result_enum *)a2[160] + 65),
      assert_on_fail_true);
  }
  vostok::resources::query_result::end_query_might_destroy_this(this, (int)a2);
  v4 = __RTCastToVoid(a2);
  (*(void (__thiscall **)(void **, _DWORD))*a2)(a2, 0);
  vostok::memory::doug_lea_allocator::free_impl(v5, (int)&vostok::memory::g_resources_helper_allocator, v4, v8, v9, v10);
  _InterlockedExchangeAdd(&s_resources_manager_buffer.m_save_resources_queries_count, 0xFFFFFFFF);
}
