void __thiscall vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
        vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this)
{
  this->m_size = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    (vostok::threading::mutex_tasks_unaware *)this,
    (_RTL_CRITICAL_SECTION *)&this->vostok::threading::mutex);
  this->m_first = 0;
  this->m_last = 0;
}


void __usercall vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
        vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        int a2@<esi>)
{
  *(_DWORD *)a2 = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    (vostok::threading::mutex_tasks_unaware *)this,
    (_RTL_CRITICAL_SECTION *)(a2 + 8));
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
}
