void __usercall vostok::resources::game_resources_manager::release_sub_fat(
        vostok::resources::game_resources_manager *this@<eax>,
        vostok::resources::vfs_sub_fat_resource *resource@<edi>,
        vostok::resources::game_resources_manager *a3@<ecx>)
{
  vostok::threading::simple_lock *v4; // ecx
  unsigned int v5; // esi
  vostok::resources::resource_freeing_functionality *v6; // ecx
  vostok::resources::resource_freeing_functionality v7; // [esp+8h] [ebp-30h] BYREF
  vostok::resources::resources_to_free_collection v8; // [esp+10h] [ebp-28h] BYREF

  vostok::resources::game_resources_manager::dispatch_capture(a3, this);
  vostok::resources::resources_to_free_collection::resources_to_free_collection(&v8, 0, 0, 0);
  v7.m_data = &this->m_data;
  v7.m_collection = &v8;
  v5 = 0;
  do
  {
    vostok::resources::resource_freeing_functionality::release_sub_fat_from_parents(resource, v4, &v7);
    ++v5;
  }
  while ( v5 < 0xA
       && !vostok::resources::resource_base::try_unregister_from_fat_or_from_name_registry(
             resource,
             resource->m_parent_resources.m_size + 1) );
  vostok::resources::resource_freeing_functionality::collect_to_free(
    (vostok::resources::resource_freeing_functionality *)resource,
    (int)&v7);
  vostok::resources::resource_freeing_functionality::free_collected(
    v6,
    (vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,184,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> **)&v7);
}
