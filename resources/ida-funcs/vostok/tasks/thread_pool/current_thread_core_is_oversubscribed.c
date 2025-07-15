bool __usercall vostok::tasks::thread_pool::current_thread_core_is_oversubscribed@<al>(
        vostok::tasks::thread_pool *this@<ecx>,
        _DWORD *a2@<esi>)
{
  return *(int *)(a2[35] + 4 * vostok::threading::current_thread_affinity()) > 1 && a2[26] > a2[38];
}
