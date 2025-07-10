char __userpurge vostok::resources::game_resources_manager::try_free_or_decrease_quality@<al>(
        vostok::resources::query_result *query@<eax>,
        vostok::resources::memory_type *info@<edx>,
        double a3@<st0>,
        vostok::resources::game_resources_manager *this)
{
  const vostok::resources::memory_type *type; // edx
  vostok::resources::resource_freeing_functionality resource_freeing; // [esp+0h] [ebp-30h] BYREF
  vostok::resources::resources_to_free_collection collection; // [esp+8h] [ebp-28h] BYREF

  collection.info = info;
  collection.required_memory = query->m_out_of_memory;
  type = query->m_out_of_memory.vostok::resources::query_result_for_cook::type;
  collection.query = query;
  collection.collected_memory.type = type;
  collection.resources.m_size = 0;
  collection.resources.m_first = 0;
  collection.resources.m_last = 0;
  collection.collected_memory.size = 0;
  resource_freeing.m_collection = &collection;
  resource_freeing.m_data = &this->m_data;
  if ( !vostok::resources::resource_freeing_functionality::try_collect_to_free(
          (vostok::resources::resource_freeing_functionality *)&collection,
          a3,
          &resource_freeing) )
    return 0;
  vostok::resources::resource_freeing_functionality::free_collected(
    &resource_freeing,
    (vostok::resources::releasing_functionality)&resource_freeing);
  return 1;
}
