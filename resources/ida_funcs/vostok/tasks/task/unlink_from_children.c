void __usercall vostok::tasks::task::unlink_from_children(vostok::tasks::task *this@<ecx>, _DWORD *a2@<esi>)
{
  int *v2; // edx
  int v3; // eax
  signed __int32 v4; // eax

  while ( a2[6] )
  {
    v2 = (int *)a2[6];
    --a2[4];
    v3 = *v2;
    a2[6] = *v2;
    if ( !v3 )
      a2[7] = 0;
    *v2 = 0;
    if ( v2[22] != 3 )
    {
      do
      {
        while ( 1 )
        {
          v4 = _InterlockedCompareExchange(v2 + 22, 4, 2);
          if ( v4 != 2 )
            break;
          v2[21] = 0;
          _InterlockedCompareExchange(v2 + 22, 2, 4);
        }
      }
      while ( v4 != 3 );
    }
    if ( !_InterlockedDecrement(v2 + 23) )
      vostok::tasks::task_allocator::deallocate(
        (vostok::tasks::task_allocator *)(v2 + 23),
        (int)&s_task_manager.m_task_allocator,
        (vostok::tasks::task *)v2);
  }
}
