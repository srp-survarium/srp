BOOL __usercall vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex>::empty@<eax>(
        vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex> *this@<ecx>,
        _DWORD *a2@<eax>)
{
  return !*a2 && !a2[16];
}
