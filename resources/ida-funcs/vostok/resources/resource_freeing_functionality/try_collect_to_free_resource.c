char __thiscall vostok::resources::resource_freeing_functionality::try_collect_to_free_resource(
        vostok::resources::resource_freeing_functionality *this,
        vostok::resources::resource_base *resource)
{
  vostok::resources::resource_flags *v3; // ecx
  vostok::threading::simple_lock *v5; // ecx

  if ( (resource->m_flags.m_flags & 0x20) == 0 )
  {
    __RTDynamicCast(
      resource,
      0,
      &vostok::resources::resource_base `RTTI Type Descriptor',
      &vostok::resources::test_resource `RTTI Type Descriptor',
      0);
    if ( vostok::resources::resource_base::has_user_references(resource) )
      return 0;
    if ( (vostok::resources::resource_flags::cast_base_of_intrusive_base(v3)->m_flags.m_flags & 1) != 0 )
    {
      if ( !vostok::resources::resource_freeing_functionality::try_collect_parents_to_free(resource, v5, this)
        || !vostok::resources::resource_base::try_unregister_from_fat_or_from_name_registry(
              resource,
              resource->m_parent_resources.m_size + 1) )
      {
        return 0;
      }
      vostok::resources::resource_freeing_functionality::collect_to_free(
        (vostok::resources::resource_freeing_functionality *)resource,
        (int)this);
    }
  }
  return 1;
}
