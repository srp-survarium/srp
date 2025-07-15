void __usercall vostok::tasks::task::execute(vostok::tasks::task *this@<ecx>, _DWORD *a2@<eax>)
{
  _DWORD *v3; // eax
  int v4; // ecx
  volatile signed __int32 *v5; // edi
  int v6; // eax
  HANDLE *v7; // eax
  vostok::tasks::task *v8; // ecx

  v3 = a2 + 10;
  v4 = -(*v3 != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v4) != 0 )
    boost::function0<void>::operator()((boost::function0<bool> *)v4, v3);
  vostok::tasks::current_task_thread_tls()->current_task = 0;
  v5 = a2 + 22;
  while ( _InterlockedCompareExchange(v5, 4, 2) != 2 )
    ;
  v6 = a2[21];
  if ( v6 )
  {
    _InterlockedExchangeAdd((volatile signed __int32 *)(v6 + 32), 0xFFFFFFFF);
    if ( !*(_DWORD *)(v6 + 32) )
    {
      v7 = *(HANDLE **)(v6 + 36);
      if ( v7 )
        SetEvent(*v7);
    }
  }
  _InterlockedCompareExchange(v5, 3, 4);
  vostok::tasks::task::unlink_from_children((vostok::tasks::task *)3, a2);
  vostok::tasks::task::decrement_reference_count_and_deallocate_when_zero(v8, (unsigned int)a2);
}
