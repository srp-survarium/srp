void __thiscall vostok::resources::resources_manager::cooker_thread_tick(vostok::resources::resources_manager *this)
{
  vostok::resources::query_result *v1; // edi
  vostok::resources::resources_manager *v2; // ecx
  vostok::resources::resources_manager *v3; // ecx
  const vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v4; // [esp+0h] [ebp-Ch]
  bool v5; // [esp+4h] [ebp-8h]

  v1 = vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
         (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this,
         (int)&s_resources_manager_buffer.m_resources_to_create,
         0);
  vostok::resources::resources_manager::dispatch_callbacks(&s_resources_manager_buffer, 0);
  vostok::resources::resources_manager::delete_delayed_unmanaged_resources(v2, &s_resources_manager_buffer);
  vostok::resources::resources_manager::create_resources<vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>(
    v1,
    0,
    v4,
    v5);
  vostok::resources::resources_manager::decompress_resources(v3);
}
