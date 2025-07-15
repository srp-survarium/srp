void __userpurge vostok::resources::unmanaged_resource::set_creation_source(
        vostok::resources::unmanaged_resource *this@<eax>,
        const vostok::resources::memory_usage_type *memory_usage@<ecx>,
        vostok::resources::resource_base::creation_source_enum creation_source,
        const char *request_path)
{
  this->m_creation_source = creation_source;
  this->m_memory_usage_self = *memory_usage;
}
