void __usercall vostok::resources::query_result::end_query_might_destroy_this_impl(
        vostok::resources::query_result *this@<ecx>,
        int a2@<edi>)
{
  vostok::resources::query_result *v2; // ecx
  int v3; // eax
  volatile signed __int32 *v4; // ebx
  vostok::resources::query_result *v5; // ecx
  vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy> *v6; // ecx
  unsigned __int8 v7; // al
  vostok::resources::resources_manager *v8; // [esp+0h] [ebp-18h]
  vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::iterator v9; // [esp+Ch] [ebp-Ch] BYREF

  if ( !vostok::resources::query_result_for_user::is_successful(this, a2)
    && (*(_DWORD *)(a2 + 320) || *(_DWORD *)(a2 + 332)) )
  {
    v3 = *(_DWORD *)(*(_DWORD *)(a2 + 344) + 32);
    if ( v3 )
    {
      v2 = (vostok::resources::query_result *)_InterlockedExchangeAdd((volatile signed __int32 *)(v3 + 332), 1u);
    }
    else
    {
      v2 = (vostok::resources::query_result *)(a2 + 336);
      v7 = *(_BYTE *)(a2 + 336);
      if ( v7 < 5u )
      {
        LOBYTE(v2->__vftable) = v7 + 1;
        vostok::resources::query_result::prepare_requery(v2, a2);
        _InterlockedExchange((volatile __int32 *)(a2 + 700), 1);
        vostok::resources::resources_manager::push_new_query(
          (vostok::resources::query_result *)a2,
          (vostok::threading::mutex *)(a2 + 700),
          v8);
        return;
      }
    }
  }
  vostok::resources::query_result_for_user::is_successful(v2, a2);
  v4 = (volatile signed __int32 *)(a2 + 704);
  if ( (*(_DWORD *)(a2 + 704) & 2) != 0 )
    _InterlockedExchangeAdd(&s_resources_manager_buffer.m_uncooked_queries_count, 0xFFFFFFFF);
  v5 = (vostok::resources::query_result *)(a2 + 704);
  _InterlockedAnd(v4, 0xFFFDFFFF);
  if ( *(_DWORD *)(a2 + 164) && vostok::resources::get_associated_query_result(*(vostok::vfs::vfs_iterator *)(a2 + 160)) )
    vostok::resources::set_associated(*(vostok::vfs::vfs_iterator *)(a2 + 160), 0);
  vostok::resources::query_result::unlock_fat_it(v5, a2);
  if ( (*v4 & 0x20) != 0 )
    vostok::resources::resources_manager::remove_from_generate_if_no_file_queue(
      (vostok::resources::query_result *)a2,
      v8);
  _InterlockedOr(v4, 0x200u);
  if ( (*v4 & 0x1000000) != 0 )
  {
    vostok::threading::mutex::lock(
      (vostok::threading::mutex *)(a2 + 704),
      (_RTL_CRITICAL_SECTION *)&s_resources_manager_buffer.m_name_registry_mutex);
    vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::find(
      v6,
      &s_resources_manager_buffer.m_name_registry,
      &v9,
      (vostok::resources::name_registry_entry *)(a2 + 668));
    vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::erase(
      &s_resources_manager_buffer.m_name_registry,
      v9.m_index,
      v9.m_value);
    _InterlockedAnd((volatile signed __int32 *)(a2 + 704), 0xFEFFFFFF);
    LeaveCriticalSection((LPCRITICAL_SECTION)&s_resources_manager_buffer.m_name_registry_mutex);
  }
  if ( *(_DWORD *)(a2 + 344) )
    vostok::resources::queries_result::on_child_query_end(
      (vostok::resources::query_result *)a2,
      *(vostok::resources::queries_result **)(a2 + 344),
      (bool)v8);
}
