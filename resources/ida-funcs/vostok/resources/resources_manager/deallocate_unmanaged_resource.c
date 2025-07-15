void __userpurge vostok::resources::resources_manager::deallocate_unmanaged_resource(
        vostok::resources::unmanaged_resource_buffer *resource_buffer@<edi>,
        vostok::fixed_string<260> *a2@<ecx>,
        vostok::resources::resources_manager *this)
{
  vostok::resources::class_id_enum m_class_id; // ebx
  vostok::resources::query_result *m_destruction_observer; // eax
  vostok::resources::cook_base *cook; // esi
  const char *v6; // [esp+0h] [ebp-134h]
  vostok::buffer_string v7[22]; // [esp+8h] [ebp-12Ch] BYREF
  char v8; // [esp+118h] [ebp-1Ch]
  vostok::resources::memory_usage_type m_memory_usage; // [esp+120h] [ebp-14h] BYREF
  vostok::resources::query_result *v10; // [esp+128h] [ebp-Ch]
  BOOL v11; // [esp+12Ch] [ebp-8h]

  LOBYTE(v11) = resource_buffer->m_is_delay_delete;
  vostok::fixed_string<260>::fixed_string<260>(a2, v7, (char *)uri);
  m_class_id = resource_buffer->m_class_id;
  m_memory_usage = resource_buffer->m_memory_usage;
  m_destruction_observer = resource_buffer->m_destruction_observer;
  v8 = 47;
  v10 = m_destruction_observer;
  cook = vostok::resources::resources_manager::find_cook(m_class_id);
  cook->deallocate_resource(cook, resource_buffer);
  vostok::resources::resources_manager::after_resource_deleted(this, cook, v11, v10, &m_memory_usage, m_class_id, v6);
}
