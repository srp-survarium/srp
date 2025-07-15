void __usercall vostok::resources::resources_manager::on_allocated_raw_resource(
        vostok::resources::query_result *query@<edi>,
        vostok::threading::mutex *a2@<ecx>)
{
  vostok::resources::resources_manager *v2; // ecx

  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    &s_resources_manager_buffer.m_queries_with_allocated_raw_resources,
    query,
    a2);
  vostok::resources::resources_manager::wakeup_resources_thread(v2, (int)&s_resources_manager_buffer);
}
