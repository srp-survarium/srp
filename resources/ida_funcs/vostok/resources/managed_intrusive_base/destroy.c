void __thiscall vostok::resources::managed_intrusive_base::destroy(
        vostok::resources::managed_intrusive_base *this,
        vostok::resources::query_result_for_cook *resource)
{
  int v2; // ecx
  vostok::resources::cook_base *cook; // eax
  vostok::resources::resources_manager *m_variable; // ebx
  vostok::resources::resources_manager *v5; // [esp+0h] [ebp-10h]

  if ( vostok::resources::base_of_intrusive_base::try_unregister_from_fat_or_from_name_registry<vostok::resources::managed_resource>(
         (vostok::resources::unmanaged_resource *const)resource,
         this,
         0) )
  {
    cook = vostok::resources::resources_manager::find_cook(v2, resource->m_class_id);
    if ( cook )
      vostok::resources::cook_base::call_destroy_resource(cook, resource);
    if ( GetCurrentThreadId() == *(int *)((char *)&dword_203CC
                                        + (unsigned int)vostok::resources::g_resources_manager.m_variable) )
    {
      vostok::resources::resources_manager::free_managed_resource(v5, (vostok::resources::managed_resource *)resource);
    }
    else
    {
      m_variable = vostok::resources::g_resources_manager.m_variable;
      vostok::intrusive_list<vostok::resources::managed_resource,vostok::resources::managed_resource *,236,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        (vostok::intrusive_list<vostok::resources::managed_resource,vostok::resources::managed_resource *,236,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)vostok::resources::g_resources_manager.m_variable,
        (int *)((char *)&dword_20318 + (unsigned int)vostok::resources::g_resources_manager.m_variable),
        (vostok::resources::managed_resource *)resource,
        (bool *)v5);
      SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)m_variable));
    }
  }
}
