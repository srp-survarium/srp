void __usercall vostok::resources::resources_manager::push_generated_resource_to_save(
        vostok::resources::resources_manager *this@<edi>,
        vostok::resources::query_result *in_query@<eax>,
        vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *a3@<ecx>)
{
  bool *v3; // [esp+0h] [ebp-4h]

  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    a3,
    (volatile int *)((char *)&this->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_2044D + 3),
    in_query,
    v3);
  SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)this));
}
