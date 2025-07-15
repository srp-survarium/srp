void __usercall vostok::resources::resources_manager::push_delayed_delete_managed_resource(
        vostok::resources::resources_manager *this@<edi>,
        vostok::resources::managed_resource *res@<eax>,
        vostok::intrusive_list<vostok::resources::managed_resource,vostok::resources::managed_resource *,236,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *a3@<ecx>)
{
  bool *v3; // [esp+0h] [ebp-4h]

  vostok::intrusive_list<vostok::resources::managed_resource,vostok::resources::managed_resource *,236,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    a3,
    (int *)((char *)&dword_20318 + (_DWORD)this),
    res,
    v3);
  SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)this));
}
