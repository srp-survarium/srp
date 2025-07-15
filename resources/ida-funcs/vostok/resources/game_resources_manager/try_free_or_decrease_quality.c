char __userpurge vostok::resources::game_resources_manager::try_free_or_decrease_quality@<al>(
        vostok::resources::query_result *query@<eax>,
        vostok::resources::game_resources_manager *this,
        vostok::resources::memory_type *info)
{
  vostok::resources::resource_freeing_functionality *v3; // ecx
  vostok::resources::resource_freeing_functionality *v4; // ecx
  vostok::resources::resources_to_free_collection v6; // [esp+8h] [ebp-38h] BYREF
  vostok::resources::memory_usage_type m_out_of_memory; // [esp+30h] [ebp-10h] BYREF
  vostok::resources::resource_freeing_functionality v8; // [esp+38h] [ebp-8h] BYREF

  m_out_of_memory = query->m_out_of_memory;
  vostok::resources::resources_to_free_collection::resources_to_free_collection(&v6, &m_out_of_memory, info, query);
  v8.m_collection = &v6;
  v8.m_data = &this->m_data;
  if ( !vostok::resources::resource_freeing_functionality::try_collect_to_free(v3, &v8) )
    return 0;
  vostok::resources::resource_freeing_functionality::free_collected(
    v4,
    (vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,184,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> **)&v8);
  return 1;
}
