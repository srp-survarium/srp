void __usercall vostok::resources::resources_manager::push_delayed_delete_managed_resource(
        vostok::resources::managed_resource *res@<esi>,
        vostok::threading::mutex *a2@<ecx>)
{
  vostok::resources::resources_manager *v2; // ecx

  res->m_next_delay_delete = 0;
  vostok::threading::mutex::lock(
    a2,
    (_RTL_CRITICAL_SECTION *)&s_resources_manager_buffer.m_delayed_delete_managed_resources.vostok::threading::mutex);
  ++s_resources_manager_buffer.m_delayed_delete_managed_resources.m_size;
  if ( s_resources_manager_buffer.m_delayed_delete_managed_resources.m_first )
    s_resources_manager_buffer.m_delayed_delete_managed_resources.m_last->m_next_delay_delete = res;
  else
    s_resources_manager_buffer.m_delayed_delete_managed_resources.m_first = res;
  s_resources_manager_buffer.m_delayed_delete_managed_resources.m_last = res;
  LeaveCriticalSection((LPCRITICAL_SECTION)&s_resources_manager_buffer.m_delayed_delete_managed_resources.vostok::threading::mutex);
  vostok::resources::resources_manager::wakeup_resources_thread(v2, (int)&s_resources_manager_buffer);
}
