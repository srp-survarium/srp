void __usercall vostok::resources::fs_task_composite::add_child(
        vostok::resources::fs_task *const child@<eax>,
        vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *a2@<ecx>,
        vostok::resources::fs_task_composite *this)
{
  bool *v3; // [esp+0h] [ebp-4h]

  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    a2,
    (_DWORD *)0x20,
    child,
    v3);
}
