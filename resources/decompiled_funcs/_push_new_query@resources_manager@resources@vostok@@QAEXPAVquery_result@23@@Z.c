void __usercall vostok::resources::resources_manager::push_new_query(
        vostok::resources::resources_manager *this@<edi>,
        vostok::resources::query_result *query@<eax>,
        double a3@<st0>)
{
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v4; // ecx
  volatile int m_flags; // ecx
  bool *v6; // [esp+0h] [ebp-8h]

  if ( (query->m_flags & 0x10000000) == 0
    || ((unsigned int)&vostok::memory::s_CRT_arena[22351416] & query->m_flags) != 0 )
  {
    m_flags = query->m_flags;
    if ( (m_flags & 0x8000000) != 0 || query->m_parent->m_parent_query )
    {
      vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)m_flags,
        (char *)&loc_202B8 + (_DWORD)this,
        query,
        v6);
    }
    else if ( (query->m_flags & 0x10) != 0 )
    {
      vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)m_flags,
        (volatile int *)((char *)&this->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20227 + 1),
        query,
        v6);
    }
    else
    {
      vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)m_flags,
        (volatile int *)((char *)&this->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20257 + 1),
        query,
        v6);
    }
  }
  else if ( GetCurrentThreadId() == *(int *)((char *)&dword_203CC + (_DWORD)this) )
  {
    vostok::resources::resources_manager::init_new_autoselect_quality_query(
      query,
      (int)v4,
      a3,
      (vostok::resources::resources_manager *)v6);
  }
  else
  {
    vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v4,
      (volatile int *)((char *)&this->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_202E7 + 1),
      query,
      v6);
    SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)this));
  }
}
