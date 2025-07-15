void __userpurge vostok::resources::game_resources_manager::query_finished_callback(
        vostok::resources::game_resources_manager *this@<ecx>,
        double a2@<st0>,
        vostok::resources::resource_base *resource)
{
  bool *v4; // [esp+0h] [ebp-8h]

  if ( GetCurrentThreadId() == *(int *)((char *)&dword_203CC
                                      + (unsigned int)vostok::resources::g_resources_manager.m_variable) )
  {
    vostok::resources::game_resources_manager::dispatch_capture(
      (vostok::resources::game_resources_manager *)resource,
      this,
      a2);
  }
  else
  {
    vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      (vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)vostok::resources::g_resources_manager.m_variable,
      this,
      resource,
      v4);
    SetEvent(*(HANDLE *)((char *)&dword_203D0 + (unsigned int)vostok::resources::g_resources_manager.m_variable));
  }
}
