void __userpurge vostok::resources::resources_manager::deallocate_unmanaged_resource(
        vostok::resources::unmanaged_resource_buffer *resource_buffer@<esi>,
        vostok::resources::resources_manager *this)
{
  vostok::resources::class_id_enum m_class_id; // ebp
  unsigned int size; // eax
  vostok::resources::query_result *m_destruction_observer; // edi
  int v5; // ecx
  vostok::resources::cook_base *cook; // ebx
  const char *v7; // [esp+0h] [ebp-138h]
  bool is_delay_delete; // [esp+10h] [ebp-128h]
  char *other; // [esp+14h] [ebp-124h] BYREF
  vostok::resources::memory_usage_type memory_usage; // [esp+18h] [ebp-120h] BYREF
  vostok::fs_new::virtual_path_string request_path; // [esp+20h] [ebp-118h] BYREF

  is_delay_delete = resource_buffer->m_is_delay_delete;
  other = (char *)&buf;
  vostok::fs_new::virtual_path_string::virtual_path_string(&request_path, (const char **)&other);
  m_class_id = resource_buffer->m_class_id;
  size = resource_buffer->m_memory_usage.size;
  m_destruction_observer = resource_buffer->m_destruction_observer;
  memory_usage.type = resource_buffer->m_memory_usage.type;
  memory_usage.size = size;
  cook = vostok::resources::resources_manager::find_cook(v5, m_class_id);
  cook->deallocate_resource(cook, resource_buffer);
  vostok::resources::resources_manager::after_resource_deleted(
    this,
    cook,
    m_destruction_observer,
    is_delay_delete,
    &memory_usage,
    m_class_id,
    v7);
}
