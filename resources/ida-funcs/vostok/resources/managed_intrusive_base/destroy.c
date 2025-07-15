void __userpurge vostok::resources::managed_intrusive_base::destroy(
        vostok::resources::managed_resource *resource@<eax>,
        vostok::resources::managed_intrusive_base *this)
{
  vostok::resources::cook_base *cook; // eax
  vostok::resources::resources_manager *v4; // [esp+0h] [ebp-8h]

  if ( vostok::resources::base_of_intrusive_base::try_unregister_from_fat_or_from_name_registry<vostok::resources::managed_resource>(
         resource,
         this,
         0) )
  {
    cook = vostok::resources::resources_manager::find_cook(resource->m_class_id);
    if ( cook )
      vostok::resources::cook_base::call_destroy_resource(cook, resource);
    if ( GetCurrentThreadId() == s_resources_manager_buffer.m_resources_thread_id )
      vostok::resources::resources_manager::free_managed_resource(
        resource,
        (vostok::fixed_string<512> *)s_resources_manager_buffer.m_resources_thread_id,
        &s_resources_manager_buffer);
    else
      vostok::resources::resources_manager::push_delayed_delete_managed_resource(
        resource,
        (vostok::threading::mutex *)s_resources_manager_buffer.m_resources_thread_id,
        v4);
  }
}
