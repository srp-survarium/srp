void __thiscall vostok::resources::unmanaged_intrusive_base::destroy(
        vostok::resources::unmanaged_intrusive_base *this,
        vostok::resources::unmanaged_resource *resource)
{
  unsigned int m_construct_thread_id; // edi
  vostok::resources::resources_manager *v3; // ecx
  vostok::resources::cook_base *cook; // eax
  vostok::resources::resources_manager *v5; // [esp-4h] [ebp-14h]
  vostok::resources::resources_manager *v6; // [esp+0h] [ebp-10h]

  if ( (resource->m_flags.m_flags & 2) == 0
    && vostok::resources::base_of_intrusive_base::try_unregister_from_fat_or_from_name_registry<vostok::resources::managed_resource>(
         (vostok::resources::managed_resource *const)resource,
         this,
         0) )
  {
    m_construct_thread_id = resource->m_construct_thread_id;
    if ( m_construct_thread_id == GetCurrentThreadId()
      || (cook = vostok::resources::resources_manager::find_cook(resource->m_class_id), v3 = v5, !cook)
      || (cook->m_flags.m_flags & 1) == 1 )
    {
      if ( vostok::resources::g_resources_manager_initialized )
        vostok::resources::resources_manager::delete_unmanaged_resource(v3, &s_resources_manager_buffer, resource);
      else
        vostok::resources::resources_manager::delete_unmanaged_resource(v3, 0, resource);
    }
    else
    {
      vostok::resources::resources_manager::push_delayed_delete_unmanaged_resource(resource, v6);
    }
  }
}
