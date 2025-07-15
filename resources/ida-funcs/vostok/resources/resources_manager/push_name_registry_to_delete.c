void __usercall vostok::resources::resources_manager::push_name_registry_to_delete(
        vostok::resources::name_registry_entry *entry@<edi>,
        vostok::threading::mutex *a2@<ecx>)
{
  __int16 v2; // ax
  vostok::threading::mutex *v3; // ecx
  vostok::resources::resources_manager *v4; // ecx
  vostok::resources::detail::name_registry_hash *v5; // [esp+0h] [ebp-Ch]

  vostok::threading::mutex::lock(a2, (_RTL_CRITICAL_SECTION *)&s_resources_manager_buffer.m_name_registry_mutex);
  v2 = vostok::resources::detail::name_registry_hash::operator()(entry, v5);
  vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::erase(
    &s_resources_manager_buffer.m_name_registry,
    v2,
    entry);
  entry->next_to_delete = 0;
  vostok::threading::mutex::lock(
    v3,
    (_RTL_CRITICAL_SECTION *)&s_resources_manager_buffer.m_name_registry_delete_queue.vostok::threading::mutex);
  ++s_resources_manager_buffer.m_name_registry_delete_queue.m_size;
  if ( s_resources_manager_buffer.m_name_registry_delete_queue.m_first )
    s_resources_manager_buffer.m_name_registry_delete_queue.m_last->next_to_delete = entry;
  else
    s_resources_manager_buffer.m_name_registry_delete_queue.m_first = entry;
  s_resources_manager_buffer.m_name_registry_delete_queue.m_last = entry;
  LeaveCriticalSection((LPCRITICAL_SECTION)&s_resources_manager_buffer.m_name_registry_delete_queue.vostok::threading::mutex);
  vostok::resources::resources_manager::wakeup_resources_thread(v4, (int)&s_resources_manager_buffer);
  LeaveCriticalSection((LPCRITICAL_SECTION)&s_resources_manager_buffer.m_name_registry_mutex);
}
