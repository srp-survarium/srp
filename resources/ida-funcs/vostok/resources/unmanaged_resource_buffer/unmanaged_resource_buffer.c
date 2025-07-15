void __userpurge vostok::resources::unmanaged_resource_buffer::unmanaged_resource_buffer(
        vostok::resources::unmanaged_resource_buffer *this@<ecx>,
        int a2@<eax>,
        vostok::resources::resource_base::creation_source_enum creation_source,
        const char *request_name,
        vostok::resources::memory_usage_type memory_usage,
        vostok::resources::query_result *class_id,
        vostok::resources::query_result *destruction_observer,
        bool is_delay_delete,
        bool is_delay_deallocate)
{
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = creation_source;
  *(_DWORD *)(a2 + 16) = request_name;
  *(vostok::resources::memory_usage_type *)(a2 + 20) = memory_usage;
  *(_BYTE *)(a2 + 28) = is_delay_delete;
  *(_BYTE *)(a2 + 29) = (_BYTE)destruction_observer;
  *(_DWORD *)(a2 + 32) = class_id;
}
