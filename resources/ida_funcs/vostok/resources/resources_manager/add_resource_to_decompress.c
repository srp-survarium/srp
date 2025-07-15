void __usercall vostok::resources::resources_manager::add_resource_to_decompress(
        vostok::resources::resources_manager *this@<edi>,
        vostok::resources::query_result *query@<eax>,
        vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *a3@<ecx>)
{
  bool *v3; // [esp+0h] [ebp-4h]

  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    a3,
    (volatile int *)((char *)&this->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_2047F + 1),
    query,
    v3);
  SetEvent(*(HANDLE *)((char *)&dword_203E0 + (_DWORD)this));
}
