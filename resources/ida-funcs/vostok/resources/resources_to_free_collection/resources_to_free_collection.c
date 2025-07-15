void __userpurge vostok::resources::resources_to_free_collection::resources_to_free_collection(
        vostok::resources::resources_to_free_collection *this@<eax>,
        const vostok::resources::memory_usage_type *required_memory@<edx>,
        vostok::resources::memory_type *info,
        vostok::resources::query_result *query)
{
  this->resources.m_size = 0;
  this->resources.m_first = 0;
  this->resources.m_last = 0;
  this->collected_memory.type = 0;
  this->collected_memory.size = 0;
  this->required_memory.type = 0;
  this->required_memory.size = 0;
  this->info = info;
  this->query = query;
  if ( required_memory )
    this->required_memory = *required_memory;
  this->collected_memory.type = this->required_memory.type;
  this->collected_memory.size = 0;
}
