void __thiscall vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::deallocate(
        vostok::memory::single_size_buffer_allocator<292,vostok::threading::mutex> *this,
        void **pointer,
        _DWORD **a3)
{
  volatile signed __int64 *v3; // esi
  signed __int64 v4; // rax
  void *v5; // ecx
  _DWORD *v6; // [esp+18h] [ebp-8h]

  v6 = *a3;
  v3 = (volatile signed __int64 *)(pointer + 8);
  do
  {
    LODWORD(v4) = *(_DWORD *)v3;
    v5 = pointer[9];
    *v6 = *(_DWORD *)v3;
    HIDWORD(v4) = v5;
  }
  while ( _InterlockedCompareExchange64(v3, __SPAIR64__((unsigned int)v5, (unsigned int)v6), v4) != __PAIR64__((unsigned int)v5, v4) );
  _InterlockedExchangeAdd((volatile signed __int32 *)pointer + 10, 0xFFFFFFFF);
  *a3 = 0;
}
