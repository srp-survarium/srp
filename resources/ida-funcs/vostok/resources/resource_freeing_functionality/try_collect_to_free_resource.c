char __thiscall vostok::resources::resource_freeing_functionality::try_collect_to_free_resource(
        vostok::resources::resource_freeing_functionality *this,
        vostok::resources::resource_base *resource)
{
  vostok::resources::resource_base *v3; // ecx
  vostok::resources::action_logger *v4; // ecx
  vostok::threading::simple_lock *v6; // ecx
  vostok::resources::action_logger test_logger; // [esp+Ch] [ebp-Ch] BYREF

  if ( (resource->m_flags.m_flags & 0x20) == 0 )
  {
    test_logger.result = 0;
    test_logger.grm_test_resource = (vostok::resources::test_resource *)__RTDynamicCast(
                                                                          (void **)&resource->__vftable,
                                                                          0,
                                                                          (TypeDescriptor *)&vostok::resources::resource_base `RTTI Type Descriptor',
                                                                          (TypeDescriptor *)&vostok::resources::test_resource `RTTI Type Descriptor',
                                                                          0);
    test_logger.action_message = "freeing";
    if ( vostok::resources::resource_base::has_user_references(v3, resource) )
    {
LABEL_3:
      vostok::resources::action_logger::~action_logger(v4, (int)&test_logger);
      return 0;
    }
    if ( vostok::resources::resource_flags::is_pinned_by_grm((vostok::resources::resource_flags *)v4, resource) )
    {
      if ( !vostok::resources::resource_freeing_functionality::try_collect_parents_to_free(resource, v6, this)
        || !vostok::resources::resource_base::try_unregister_from_fat_or_from_name_registry(
              resource,
              (vostok::vfs::vfs_hashset *)(resource->m_parent_resources.m_size + 1)) )
      {
        goto LABEL_3;
      }
      vostok::resources::resource_freeing_functionality::collect_to_free(this, resource);
      test_logger.result = 1;
    }
    vostok::resources::action_logger::~action_logger((vostok::resources::action_logger *)v6, (int)&test_logger);
  }
  return 1;
}
