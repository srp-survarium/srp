void __thiscall vostok::resources::game_resources_manager::query_finished_callback(
        vostok::resources::game_resources_manager *this,
        vostok::resources::resource_base *resource)
{
  if ( GetCurrentThreadId() == s_resources_manager_buffer.m_resources_thread_id )
  {
    vostok::resources::game_resources_manager::dispatch_capture(
      (vostok::resources::game_resources_manager *)s_resources_manager_buffer.m_resources_thread_id,
      this,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)resource);
  }
  else
  {
    vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &this->m_resources_to_capture,
      resource,
      (vostok::threading::mutex *)s_resources_manager_buffer.m_resources_thread_id);
    SetEvent(*(HANDLE *)s_resources_manager_buffer.m_resources_wakeup_event.m_event.m_event);
  }
}
