void __thiscall vostok::resources::resources_manager::delete_unmanaged_resource(
        vostok::resources::resources_manager *this,
        vostok::resources::resources_manager *dying_resource,
        vostok::resources::unmanaged_resource *inptr)
{
  vostok::resources::unmanaged_resource_buffer *v4; // edi
  bool v5; // zf
  vostok::fixed_string<260> *v6; // ecx
  vostok::resources::cook_base *v7; // ecx
  vostok::resources::cook_base *v8; // ebx
  vostok::resources::unmanaged_resource *v9; // eax
  vostok::resources::class_id_enum m_class_id; // eax
  const vostok::resources::memory_type *type; // ecx
  unsigned int size; // edx
  vostok::resources::resource_base::creation_source_enum v13; // ebx
  vostok::resources::query_result *v14; // eax
  vostok::fixed_string<260> *v15; // ecx
  vostok::resources::thread_local_data *thread_local_data; // eax
  vostok::threading::mutex *v17; // ecx
  vostok::intrusive_list<vostok::resources::unmanaged_resource_buffer,vostok::resources::unmanaged_resource_buffer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *p_delayed_deallocate_unmanaged_resources; // ebx
  vostok::resources::resources_manager *v19; // ecx
  const char *v20; // [esp+4h] [ebp-140h]
  vostok::buffer_string v21[22]; // [esp+14h] [ebp-130h] BYREF
  char v22; // [esp+124h] [ebp-20h]
  vostok::resources::memory_usage_type m_memory_usage_self; // [esp+12Ch] [ebp-18h] BYREF
  vostok::resources::query_result *m_destruction_observer; // [esp+134h] [ebp-10h]
  vostok::resources::resource_base::creation_source_enum m_creation_source; // [esp+138h] [ebp-Ch]
  BOOL v26; // [esp+13Ch] [ebp-8h]
  vostok::resources::cook_base *cook; // [esp+140h] [ebp-4h]
  _RTL_CRITICAL_SECTION *inptra; // [esp+150h] [ebp+Ch]
  bool inptr_3a; // [esp+153h] [ebp+Fh]
  bool inptr_3; // [esp+153h] [ebp+Fh]

  cook = vostok::resources::resources_manager::find_cook(inptr->m_class_id);
  v4 = (vostok::resources::unmanaged_resource_buffer *)__RTCastToVoid((void **)&inptr->__vftable);
  m_memory_usage_self = inptr->m_memory_usage_self;
  LOBYTE(v26) = (inptr->m_flags.m_flags & 1) == 1;
  v5 = inptr->m_creation_source == creation_source_deallocate_buffer_helper;
  m_creation_source = inptr->m_creation_source;
  inptr_3a = v5;
  m_destruction_observer = inptr->m_destruction_observer;
  vostok::fixed_string<260>::fixed_string<260>(v6, v21, "<unknown>");
  v22 = 47;
  if ( inptr_3a )
  {
    ((void (__thiscall *)(vostok::resources::unmanaged_resource *, _DWORD))inptr->~vostok::resources::unmanaged_resource)(
      inptr,
      0);
    v8 = cook;
  }
  else
  {
    v9 = inptr;
    v8 = cook;
    vostok::resources::cook_base::call_destroy_resource(cook, v9);
    if ( (v8->m_flags.m_flags & 0x2E) != 0 )
    {
      vostok::resources::resources_manager::after_resource_deleted(
        dying_resource,
        v8,
        v26,
        m_destruction_observer,
        &m_memory_usage_self,
        v8->m_class_id,
        v20);
      return;
    }
  }
  cook = (vostok::resources::cook_base *)vostok::resources::cook_base::allocate_thread_id(v7, (int)v8);
  inptr_3 = GetCurrentThreadId() != (_DWORD)cook;
  if ( v4 )
  {
    m_class_id = v8->m_class_id;
    type = m_memory_usage_self.type;
    size = m_memory_usage_self.size;
    v13 = m_creation_source;
    v4->m_class_id = m_class_id;
    v4->m_is_delay_deallocate = inptr_3;
    v4->m_is_delay_delete = v26;
    v14 = m_destruction_observer;
    v4->m_next_to_deallocate = 0;
    v4->m_next_in_global_delay_delete_list = 0;
    v4->m_prev_in_global_delay_delete_list = 0;
    v4->m_creation_source = v13;
    v4->m_memory_usage.type = type;
    v4->m_memory_usage.size = size;
    v4->m_destruction_observer = v14;
  }
  else
  {
    v4 = 0;
  }
  if ( (vostok::resources::cook_base *)GetCurrentThreadId() == cook )
  {
    vostok::resources::resources_manager::deallocate_unmanaged_resource(v4, v15, dying_resource);
  }
  else
  {
    thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                          (vostok::resources::resources_manager *)v15,
                          (unsigned int)dying_resource,
                          (unsigned int)cook,
                          1);
    p_delayed_deallocate_unmanaged_resources = &thread_local_data->delayed_deallocate_unmanaged_resources;
    m_creation_source = (vostok::resources::resource_base::creation_source_enum)thread_local_data;
    v4->m_next_to_deallocate = 0;
    if ( thread_local_data == (vostok::resources::thread_local_data *)-440 )
      inptra = 0;
    else
      inptra = (_RTL_CRITICAL_SECTION *)&thread_local_data->delayed_deallocate_unmanaged_resources.vostok::threading::mutex;
    vostok::threading::mutex::lock(v17, inptra);
    ++p_delayed_deallocate_unmanaged_resources->m_size;
    if ( p_delayed_deallocate_unmanaged_resources->m_first )
      p_delayed_deallocate_unmanaged_resources->m_last->m_next_to_deallocate = v4;
    else
      p_delayed_deallocate_unmanaged_resources->m_first = v4;
    p_delayed_deallocate_unmanaged_resources->m_last = v4;
    LeaveCriticalSection(inptra);
    if ( v26 )
      v19 = (vostok::resources::resources_manager *)_InterlockedExchangeAdd(
                                                      (volatile signed __int32 *)(m_creation_source + 544),
                                                      0xFFFFFFFF);
    vostok::resources::resources_manager::wakeup_thread_by_id_if_needed(
      v19,
      (int)dying_resource,
      (vostok::resources::resources_manager *)cook);
  }
}
