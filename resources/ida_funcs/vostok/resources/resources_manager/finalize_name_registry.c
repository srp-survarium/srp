void __usercall vostok::resources::resources_manager::finalize_name_registry(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<eax>)
{
  _RTL_CRITICAL_SECTION *v3; // edi
  int m_index; // eax
  vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::iterator *v5; // ecx
  vostok::resources::name_registry_entry *m_value; // esi
  __int64 v7; // xmm0_8
  vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::iterator it; // [esp+Ch] [ebp-28h]
  vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::iterator it_next; // [esp+18h] [ebp-1Ch] BYREF
  vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::iterator v10; // [esp+24h] [ebp-10h] BYREF

  vostok::resources::resources_manager::delete_name_registry_entries(this, a2);
  v3 = (_RTL_CRITICAL_SECTION *)&byte_20168[a2];
  vostok::threading::mutex::lock((vostok::threading::mutex *)&byte_20168[a2]);
  it.m_container = (vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy> *)(a2 + 348);
  it.m_index = 0;
  it.m_value = 0;
  m_index = 0;
  v5 = (vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::iterator *)(a2 + 352);
  while ( !v5->m_container )
  {
    ++m_index;
    v5 = (vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::iterator *)((char *)v5 + 4);
    if ( m_index >= 0x8000 )
      goto LABEL_4;
  }
  m_value = *(vostok::resources::name_registry_entry **)(a2 + 348 + 4 * m_index + 4);
  it.m_value = m_value;
  v7 = *(_QWORD *)&it.m_container;
  while ( m_value )
  {
    it_next.m_index = m_index;
    *(_QWORD *)&it_next.m_container = v7;
    vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::iterator::operator++(
      v5,
      &v10,
      (__int64 *)&it_next);
    vostok::memory::g_resources_helper_allocator.m_out_of_memory = 0;
    vostok_mspace_free((malloc_state *)vostok::memory::g_resources_helper_allocator.m_arena, (char *)m_value);
    v7 = *(_QWORD *)&it_next.m_container;
    m_index = it_next.m_index;
    *(_QWORD *)&it.m_container = *(_QWORD *)&it_next.m_container;
    m_value = it_next.m_value;
  }
LABEL_4:
  LeaveCriticalSection(v3);
}
