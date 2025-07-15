void __thiscall vostok::resources::game_resources_manager::out_of_memory_callback(
        vostok::resources::game_resources_manager *this,
        vostok::resources::query_result *query)
{
  const vostok::resources::memory_type *type; // edi
  vostok::threading::mutex *v3; // ecx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+Ch] [ebp-Ch]
  _RTL_CRITICAL_SECTION *v5; // [esp+10h] [ebp-8h]

  if ( ((unsigned int)&loc_400000 & query->m_flags) == 0 )
  {
    type = query->m_out_of_memory.vostok::resources::query_result_for_cook::type;
    if ( !type->in_list )
    {
      vostok::intrusive_list<vostok::vfs::mount_referer_base,vostok::vfs::mount_referer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        (vostok::intrusive_list<vostok::vfs::mount_referer_base,vostok::vfs::mount_referer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&this->m_data.memory_types,
        (vostok::vfs::mount_referer *)type,
        (vostok::threading::mutex *)this);
      type->in_list = 1;
    }
    _InterlockedOr(&query->m_flags, (unsigned int)&loc_400000);
    if ( type == (const vostok::resources::memory_type *)-40 )
    {
      v5 = 0;
      vostok::threading::mutex::lock((vostok::threading::mutex *)&loc_400000, 0);
    }
    else
    {
      v5 = (_RTL_CRITICAL_SECTION *)&type->queue.vostok::threading::mutex;
      vostok::threading::mutex::lock(
        (vostok::threading::mutex *)&loc_400000,
        (_RTL_CRITICAL_SECTION *)&type->queue.vostok::threading::mutex);
    }
    query->m_next_out_of_memory = 0;
    if ( type == (const vostok::resources::memory_type *)-40 )
    {
      lpCriticalSection = 0;
      vostok::threading::mutex::lock(v3, 0);
    }
    else
    {
      lpCriticalSection = (_RTL_CRITICAL_SECTION *)&type->queue.vostok::threading::mutex;
      vostok::threading::mutex::lock(v3, (_RTL_CRITICAL_SECTION *)&type->queue.vostok::threading::mutex);
    }
    ++type->queue.m_size;
    if ( type->queue.m_first )
      type->queue.m_last->m_next_out_of_memory = query;
    else
      type->queue.m_first = query;
    type->queue.m_last = query;
    LeaveCriticalSection(lpCriticalSection);
    type->listen_type = listen_none;
    SetEvent(*(HANDLE *)s_resources_manager_buffer.m_resources_wakeup_event.m_event.m_event);
    LeaveCriticalSection(v5);
  }
}
