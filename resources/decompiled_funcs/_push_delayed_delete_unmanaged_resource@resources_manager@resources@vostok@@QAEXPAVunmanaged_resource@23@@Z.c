void __userpurge vostok::resources::resources_manager::push_delayed_delete_unmanaged_resource(
        vostok::resources::unmanaged_resource *dying_resource@<edi>,
        int a2@<ecx>,
        vostok::resources::resources_manager *this)
{
  unsigned int m_construct_thread_id; // ebp
  vostok::resources::cook_base *cook; // esi
  unsigned int m_allocate_thread_id; // eax
  vostok::resources::resources_manager *v7; // ecx
  vostok::resources::resources_manager *v8; // ecx
  bool *v9; // [esp+0h] [ebp-10h]
  vostok::resources::thread_local_data *thread_data; // [esp+Ch] [ebp-4h]
  unsigned int deallocation_thread_id; // [esp+14h] [ebp+4h]

  m_construct_thread_id = dying_resource->m_construct_thread_id;
  cook = vostok::resources::resources_manager::find_cook(a2, dying_resource->m_class_id);
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
  v7 = (vostok::resources::resources_manager *)cook->m_allocate_thread_id;
  dying_resource->m_flags.m_flags |= 1u;
  deallocation_thread_id = (unsigned int)v7;
  thread_data = vostok::resources::resources_manager::get_thread_local_data(v7, this, m_construct_thread_id, 1);
  _InterlockedExchangeAdd((volatile signed __int32 *)((char *)&off_20378 + (_DWORD)this), 1u);
  if ( (cook->m_flags.m_flags & 0x2E) == 0 && m_construct_thread_id != deallocation_thread_id )
    v8 = (vostok::resources::resources_manager *)_InterlockedExchangeAdd(
                                                   &vostok::resources::resources_manager::get_thread_local_data(
                                                      v8,
                                                      this,
                                                      deallocation_thread_id,
                                                      1)->resources_to_deallocate_after_destroy_in_other_thread_count,
                                                   1u);
  vostok::intrusive_list<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_resource *,232,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_resource *,232,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)v8,
    &thread_data->delayed_delete_unmanaged_resources.m_size,
    dying_resource,
    v9);
  if ( m_construct_thread_id == *(int *)((char *)&dword_203CC + (_DWORD)this) )
  {
    SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)this));
  }
  else if ( m_construct_thread_id == *(_DWORD *)&byte_203D8[(_DWORD)this] )
  {
    SetEvent(*(HANDLE *)((char *)&dword_203E0 + (_DWORD)this));
  }
}
