void __thiscall vostok::resources::unmanaged_intrusive_base::destroy(
        vostok::resources::unmanaged_intrusive_base *this,
        vostok::resources::unmanaged_resource *resource)
{
  unsigned int m_construct_thread_id; // esi
  int v3; // ecx
  vostok::resources::cook_base *cook; // eax

  if ( (resource->m_flags.m_flags & 2) == 0
    && vostok::resources::base_of_intrusive_base::try_unregister_from_fat_or_from_name_registry<vostok::resources::managed_resource>(
         resource,
         this,
         0) )
  {
    m_construct_thread_id = resource->m_construct_thread_id;
    if ( m_construct_thread_id == GetCurrentThreadId()
      || (cook = vostok::resources::resources_manager::find_cook(v3, resource->m_class_id)) == 0
      || (cook->m_flags.m_flags & 1) == 1 )
    {
      vostok::resources::resources_manager::delete_unmanaged_resource(
        vostok::resources::g_resources_manager.m_variable,
        resource);
    }
    else
    {
      vostok::resources::resources_manager::push_delayed_delete_unmanaged_resource(
        vostok::resources::g_resources_manager.m_variable,
        resource);
    }
  }
}
