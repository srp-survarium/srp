void __userpurge vostok::resources::game_resources_manager::tick_memory_type(
        vostok::resources::memory_type *info@<edi>,
        vostok::threading::mutex *a2@<ecx>,
        vostok::resources::game_resources_manager *this)
{
  vostok::timing::timer *v3; // ecx
  vostok::resources::query_result *v4; // eax
  vostok::resources::memory_type::listen_enum listen_type; // esi
  vostok::resources::game_resources_manager *v6; // ecx
  vostok::resources::query_result *v7; // ecx
  vostok::resources::sorting_functionality v8; // [esp+8h] [ebp-1Ch] BYREF
  vostok::resources::query_result *m_first; // [esp+18h] [ebp-Ch]
  LPCRITICAL_SECTION lpCriticalSection; // [esp+1Ch] [ebp-8h]

  if ( info->queue.m_first && info->listen_type != listen_freed )
  {
    if ( info == (vostok::resources::memory_type *)-40 )
      lpCriticalSection = 0;
    else
      lpCriticalSection = (LPCRITICAL_SECTION)&info->queue.vostok::threading::mutex;
    vostok::threading::mutex::lock(a2, lpCriticalSection);
    if ( !info->queue.m_first
      || info->listen_type == listen_all
      && vostok::timing::timer::get_elapsed_sec(v3, (int)&info->listen_all_timer) < 1.0 )
    {
      goto LABEL_18;
    }
    v8.m_data = &this->m_data;
    v8.m_sort_actuality_tick = 1;
    vostok::resources::sorting_functionality::sort_resources_if_needed(info, &v8);
    listen_type = info->listen_type;
    m_first = info->queue.m_first;
    v4 = m_first;
    info->listen_type = listen_freed;
    if ( vostok::resources::game_resources_manager::try_free_or_decrease_quality(v4, this, info) )
      goto LABEL_18;
    info->listen_type = listen_type;
    if ( listen_type )
    {
      if ( (info == &vostok::resources::managed_memory || info == &vostok::resources::unmanaged_memory)
        && vostok::resources::game_resources_manager::try_reallocate_queue(v6, info) )
      {
        info->listen_type = listen_none;
        SetEvent(*(HANDLE *)s_resources_manager_buffer.m_resources_wakeup_event.m_event.m_event);
LABEL_18:
        LeaveCriticalSection(lpCriticalSection);
        return;
      }
      vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,616,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_front(
        (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,616,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)v6,
        (int)&info->queue);
      vostok::resources::query_result::end_query_might_destroy_this(v7, (int)m_first);
      if ( !info->queue.m_first )
      {
        info->listen_type = listen_none;
        goto LABEL_18;
      }
    }
    info->listen_type = listen_all;
    vostok::timing::timer::start((vostok::timing::timer *)v6, (LARGE_INTEGER *)&info->listen_all_timer);
    goto LABEL_18;
  }
}
