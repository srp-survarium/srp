vostok::tasks::task *__usercall vostok::tasks::task_allocator::allocate@<eax>(
        vostok::tasks::task_allocator *this@<ecx>,
        int a2@<eax>)
{
  volatile signed __int64 *v2; // esi
  signed __int64 allocated_task; // [esp+10h] [ebp-10h]

  v2 = (volatile signed __int64 *)((char *)&dword_60000 + a2);
  while ( 1 )
  {
    allocated_task = *v2;
    if ( !*(_DWORD *)v2 )
      break;
    if ( _InterlockedCompareExchange64(
           v2,
           __SPAIR64__(*((_DWORD *)v2 + 1) + 1, *(_DWORD *)(*(_DWORD *)v2 + 4)),
           allocated_task) == allocated_task )
      return (vostok::tasks::task *)allocated_task;
  }
  return 0;
}
