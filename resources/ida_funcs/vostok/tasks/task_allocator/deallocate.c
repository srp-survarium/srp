void __userpurge vostok::tasks::task_allocator::deallocate(
        vostok::tasks::task_allocator *this@<ecx>,
        int a2@<eax>,
        vostok::tasks::task *freeing_task)
{
  vostok::tasks::task *v3; // edx
  char *v4; // esi
  signed __int64 v5; // rax
  unsigned int v6; // ecx

  v3 = freeing_task;
  freeing_task->m_state = 0;
  v4 = (char *)&dword_60000 + a2;
  while ( 1 )
  {
    LODWORD(v5) = *(_DWORD *)v4;
    v6 = *((_DWORD *)v4 + 1);
    v3->m_next_task_in_allocator = *(vostok::tasks::task **)v4;
    HIDWORD(v5) = v6;
    if ( _InterlockedCompareExchange64((volatile signed __int64 *)v4, __SPAIR64__(v6, (unsigned int)freeing_task), v5) == __PAIR64__(v6, v5) )
      break;
    v3 = freeing_task;
  }
}
