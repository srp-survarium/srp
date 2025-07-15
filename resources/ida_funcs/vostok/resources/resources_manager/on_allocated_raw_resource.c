void __usercall vostok::resources::resources_manager::on_allocated_raw_resource(
        vostok::resources::resources_manager *this@<edi>,
        vostok::resources::query_result *query@<eax>,
        vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *a3@<ecx>)
{
  bool *v3; // [esp+0h] [ebp-4h]

  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    a3,
    (int *)((char *)dword_20380 + (_DWORD)this),
    query,
    v3);
  SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)this));
}
