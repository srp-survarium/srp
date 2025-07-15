char __usercall vostok::resources::query_result::try_push_created_resource_to_manager_might_destroy_this@<al>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::query_result *v2; // ecx
  vostok::resources::query_result *v3; // eax
  vostok::threading::mutex *v4; // ecx
  vostok::resources::resources_manager *v6; // [esp+0h] [ebp-Ch]

  v2 = (vostok::resources::query_result *)(a2 + 728);
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)(a2 + 728), 0xFFFFFFFF) )
    return 0;
  if ( *(_DWORD *)(a2 + 260) == 4 )
  {
    vostok::resources::query_result::prepare_requery(v2, a2);
    vostok::resources::resources_manager::push_new_query(v3, v4, v6);
  }
  else
  {
    vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &s_resources_manager_buffer.m_created_resources,
      (vostok::resources::query_result *)a2,
      (vostok::threading::mutex *)v2);
  }
  SetEvent(*(HANDLE *)s_resources_manager_buffer.m_resources_wakeup_event.m_event.m_event);
  return 1;
}
