void __userpurge vostok::resources::resources_manager::push_name_registry_to_delete(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<edi>,
        vostok::resources::name_registry_entry *entry)
{
  __int16 v3; // ax
  vostok::intrusive_list<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,16,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v4; // ecx
  bool *v5; // [esp+0h] [ebp-10h]

  vostok::threading::mutex::lock((vostok::threading::mutex *)&byte_20168[a2]);
  v3 = vostok::fs_new::crc32(entry->name, strlen(entry->name), 0);
  vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::erase(
    (vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy> *)(a2 + 348),
    v3,
    entry);
  vostok::intrusive_list<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,16,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    v4,
    (char *)&loc_2017F + a2 + 1,
    entry,
    v5);
  SetEvent(*(HANDLE *)((char *)&dword_203D0 + a2));
  LeaveCriticalSection((LPCRITICAL_SECTION)&byte_20168[a2]);
}
