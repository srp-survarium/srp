void __userpurge vostok::resources::resources_manager::delete_unmanaged_resource(
        vostok::resources::unmanaged_resource *dying_resource@<eax>,
        int a2@<ecx>,
        vostok::resources::resources_manager *this)
{
  vostok::resources::cook_base *cook; // ebx
  vostok::resources::unmanaged_resource_buffer *v5; // eax
  unsigned int m_flags; // edx
  vostok::resources::resource_base::creation_source_enum m_creation_source; // edi
  vostok::resources::unmanaged_resource_buffer *v8; // ebp
  const vostok::resources::memory_type *type; // eax
  vostok::resources::query_result *m_destruction_observer; // eax
  unsigned int m_allocate_thread_id; // eax
  unsigned int v12; // edi
  bool v13; // dl
  const vostok::resources::memory_type *v14; // eax
  vostok::resources::class_id_enum m_class_id; // ebx
  unsigned int size; // ecx
  vostok::resources::resource_base::creation_source_enum v17; // esi
  vostok::resources::resources_manager *v18; // ecx
  vostok::resources::thread_local_data *thread_local_data; // ebx
  vostok::intrusive_list<vostok::resources::unmanaged_resource_buffer,vostok::resources::unmanaged_resource_buffer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v20; // ecx
  char *v21; // [esp+0h] [ebp-140h]
  bool is_delay_delete; // [esp+10h] [ebp-130h]
  vostok::resources::query_result *destruction_observer; // [esp+14h] [ebp-12Ch]
  vostok::resources::memory_usage_type memory_usage; // [esp+18h] [ebp-128h] BYREF
  char *other; // [esp+20h] [ebp-120h] BYREF
  vostok::resources::resource_base::creation_source_enum v26; // [esp+24h] [ebp-11Ch]
  vostok::fs_new::virtual_path_string request_path; // [esp+28h] [ebp-118h] BYREF

  cook = vostok::resources::resources_manager::find_cook(a2, dying_resource->m_class_id);
  v5 = (vostok::resources::unmanaged_resource_buffer *)__RTCastToVoid((void **)&dying_resource->__vftable);
  m_flags = dying_resource->m_flags.m_flags;
  m_creation_source = dying_resource->m_creation_source;
  v8 = v5;
  type = dying_resource->m_memory_usage_self.vostok::resources::resource_base::vostok::resources::resource_quality::type;
  memory_usage.size = dying_resource->m_memory_usage_self.size;
  memory_usage.type = type;
  m_destruction_observer = dying_resource->m_destruction_observer;
  is_delay_delete = (m_flags & 1) == 1;
  v26 = m_creation_source;
  destruction_observer = m_destruction_observer;
  other = "<unknown>";
  vostok::fs_new::virtual_path_string::virtual_path_string(&request_path, (const char **)&other);
  if ( m_creation_source == creation_source_deallocate_buffer_helper )
  {
    ((void (__thiscall *)(vostok::resources::unmanaged_resource *, _DWORD))dying_resource->~vostok::resources::resource_base)(
      dying_resource,
      0);
  }
  else
  {
    vostok::resources::cook_base::call_destroy_resource(cook, dying_resource);
    if ( (cook->m_flags.m_flags & 0x2E) != 0 )
    {
      vostok::resources::resources_manager::after_resource_deleted(
        this,
        cook,
        destruction_observer,
        is_delay_delete,
        &memory_usage,
        cook->m_class_id,
        v21);
      return;
    }
  }
  m_allocate_thread_id = cook->m_allocate_thread_id;
  if ( m_allocate_thread_id == -2 )
  {
    cook->m_allocate_thread_id = *(_DWORD *)&byte_203D8[(unsigned int)vostok::resources::g_resources_manager.m_variable];
  }
  else if ( m_allocate_thread_id == -4 )
  {
    cook->m_allocate_thread_id = *(int *)((char *)&dword_203CC
                                        + (unsigned int)vostok::resources::g_resources_manager.m_variable);
  }
  v12 = cook->m_allocate_thread_id;
  v13 = GetCurrentThreadId() != v12;
  if ( v8 )
  {
    v14 = memory_usage.type;
    m_class_id = cook->m_class_id;
    size = memory_usage.size;
    v8->m_next_to_deallocate = 0;
    v8->m_next_in_global_delay_delete_list = 0;
    v8->m_prev_in_global_delay_delete_list = 0;
    v17 = v26;
    v8->m_memory_usage.type = v14;
    v8->m_is_delay_deallocate = v13;
    v8->m_creation_source = v17;
    v8->m_memory_usage.size = size;
    v8->m_class_id = m_class_id;
    v8->m_is_delay_delete = is_delay_delete;
    v8->m_destruction_observer = destruction_observer;
  }
  else
  {
    v8 = 0;
  }
  if ( GetCurrentThreadId() == v12 )
  {
    vostok::resources::resources_manager::deallocate_unmanaged_resource(v8, this);
  }
  else
  {
    thread_local_data = vostok::resources::resources_manager::get_thread_local_data(v18, this, v12, 1);
    vostok::intrusive_list<vostok::resources::memory_type,vostok::resources::memory_type *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v20,
      (int)&thread_local_data->delayed_deallocate_unmanaged_resources,
      v8,
      (bool *)v21);
    if ( is_delay_delete )
      _InterlockedExchangeAdd(
        &thread_local_data->resources_to_deallocate_after_destroy_in_other_thread_count,
        0xFFFFFFFF);
    if ( v12 == *(int *)((char *)&dword_203CC + (_DWORD)this) )
    {
      SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)this));
    }
    else if ( v12 == *(_DWORD *)&byte_203D8[(_DWORD)this] )
    {
      SetEvent(*(HANDLE *)((char *)&dword_203E0 + (_DWORD)this));
    }
  }
}
