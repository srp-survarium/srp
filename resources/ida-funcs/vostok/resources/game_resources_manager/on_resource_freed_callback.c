void __thiscall vostok::resources::game_resources_manager::on_resource_freed_callback(
        vostok::resources::game_resources_manager *this,
        vostok::resources::query_result *destruction_observer,
        const vostok::resources::memory_usage_type *memory_usage,
        vostok::resources::class_id_enum class_id)
{
  const vostok::resources::memory_type *type; // esi
  _RTL_CRITICAL_SECTION *v5; // edi
  vostok::resources::game_resources_manager *v6; // ecx

  type = memory_usage->type;
  if ( memory_usage->type && type->queue.m_first )
  {
    if ( type == (const vostok::resources::memory_type *)-40 )
      v5 = 0;
    else
      v5 = (_RTL_CRITICAL_SECTION *)&type->queue.vostok::threading::mutex;
    vostok::threading::mutex::lock((vostok::threading::mutex *)this, v5);
    if ( destruction_observer )
    {
      if ( type->listen_type != listen_all )
        type->listen_type = listen_none;
    }
    else if ( type->listen_type != listen_all )
    {
LABEL_13:
      LeaveCriticalSection(v5);
      return;
    }
    if ( vostok::resources::game_resources_manager::try_reallocate_queue(v6, type) )
    {
      type->listen_type = listen_none;
      SetEvent(*(HANDLE *)s_resources_manager_buffer.m_resources_wakeup_event.m_event.m_event);
    }
    goto LABEL_13;
  }
}
