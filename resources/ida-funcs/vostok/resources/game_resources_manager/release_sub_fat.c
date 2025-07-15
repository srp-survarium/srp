void __usercall vostok::resources::game_resources_manager::release_sub_fat(
        vostok::resources::game_resources_manager *this@<eax>,
        vostok::resources::vfs_sub_fat_resource *resource@<edi>,
        vostok::resources::game_resources_manager *a3@<ecx>,
        double a4@<st0>)
{
  vostok::resources::resource_freeing_functionality resource_freeing; // [esp+8h] [ebp-34h] BYREF
  vostok::resources::resources_to_free_collection collection; // [esp+10h] [ebp-2Ch] BYREF

  vostok::resources::game_resources_manager::dispatch_capture(a3, this, a4);
  collection.resources.m_size = 0;
  memset(&collection.resources.m_first, 0, 32);
  resource_freeing.m_collection = &collection;
  resource_freeing.m_data = &this->m_data;
  vostok::resources::resource_freeing_functionality::release_sub_fat(
    resource,
    (vostok::threading::simple_lock *)&resource_freeing,
    &resource_freeing);
}
