void __usercall vostok::resources::resources_manager::push_delayed_delete_unmanaged_resource(
        vostok::resources::unmanaged_resource *dying_resource@<esi>)
{
  vostok::resources::resources_manager *m_construct_thread_id; // ebx
  vostok::resources::cook_base *cook; // edi
  unsigned int thread_id; // eax
  vostok::resources::resources_manager *v4; // ecx
  vostok::resources::resources_manager *v5; // ecx
  vostok::resources::resources_manager *v6; // ecx
  vostok::resources::cook_base *v7; // [esp-4h] [ebp-1Ch]
  vostok::resources::thread_local_data *thread_local_data; // [esp+Ch] [ebp-Ch]
  LPCRITICAL_SECTION lpCriticalSection; // [esp+14h] [ebp-4h]
  _RTL_CRITICAL_SECTION *lpCriticalSectiona; // [esp+14h] [ebp-4h]

  m_construct_thread_id = (vostok::resources::resources_manager *)dying_resource->m_construct_thread_id;
  cook = vostok::resources::resources_manager::find_cook(dying_resource->m_class_id);
  thread_id = vostok::resources::cook_base::allocate_thread_id(v7, (int)cook);
  dying_resource->m_flags.m_flags |= 1u;
  lpCriticalSection = (LPCRITICAL_SECTION)thread_id;
  thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                        v4,
                        (unsigned int)&s_resources_manager_buffer,
                        (unsigned int)m_construct_thread_id,
                        1);
  v5 = (vostok::resources::resources_manager *)_InterlockedExchangeAdd(
                                                 &s_resources_manager_buffer.m_delay_delete_unmanaged_resources_count,
                                                 1u);
  if ( (cook->m_flags.m_flags & 0x2E) == 0
    && m_construct_thread_id != (vostok::resources::resources_manager *)lpCriticalSection )
  {
    v5 = (vostok::resources::resources_manager *)_InterlockedExchangeAdd(
                                                   &vostok::resources::resources_manager::get_thread_local_data(
                                                      v5,
                                                      (unsigned int)&s_resources_manager_buffer,
                                                      (unsigned int)lpCriticalSection,
                                                      1)->resources_to_deallocate_after_destroy_in_other_thread_count,
                                                   1u);
  }
  dying_resource->m_next_delay_delete = 0;
  if ( thread_local_data == (vostok::resources::thread_local_data *)-392 )
  {
    lpCriticalSectiona = 0;
    vostok::threading::mutex::lock((vostok::threading::mutex *)v5, 0);
  }
  else
  {
    lpCriticalSectiona = (_RTL_CRITICAL_SECTION *)&thread_local_data->delayed_delete_unmanaged_resources.vostok::threading::mutex;
    vostok::threading::mutex::lock(
      (vostok::threading::mutex *)v5,
      (_RTL_CRITICAL_SECTION *)&thread_local_data->delayed_delete_unmanaged_resources.vostok::threading::mutex);
  }
  ++thread_local_data->delayed_delete_unmanaged_resources.m_size;
  if ( thread_local_data->delayed_delete_unmanaged_resources.m_first )
    thread_local_data->delayed_delete_unmanaged_resources.m_last->m_next_delay_delete = dying_resource;
  else
    thread_local_data->delayed_delete_unmanaged_resources.m_first = dying_resource;
  thread_local_data->delayed_delete_unmanaged_resources.m_last = dying_resource;
  LeaveCriticalSection(lpCriticalSectiona);
  vostok::resources::resources_manager::wakeup_thread_by_id_if_needed(
    v6,
    (int)&s_resources_manager_buffer,
    m_construct_thread_id);
}
