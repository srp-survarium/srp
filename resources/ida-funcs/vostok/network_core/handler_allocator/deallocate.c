void __thiscall vostok::network_core::handler_allocator<1024,96,1>::deallocate(
        vostok::network_core::handler_allocator<1024,96,1> *this,
        char *pointer,
        _DWORD *a3)
{
  volatile signed __int64 *v3; // esi
  signed __int64 v4; // rax
  unsigned int v5; // ecx

  v3 = (volatile signed __int64 *)(pointer + 40);
  do
  {
    LODWORD(v4) = *(_DWORD *)v3;
    v5 = *((_DWORD *)pointer + 11);
    *a3 = *(_DWORD *)v3;
    HIDWORD(v4) = v5;
  }
  while ( _InterlockedCompareExchange64(v3, __SPAIR64__(v5, (unsigned int)a3), v4) != __PAIR64__(v5, v4) );
  _InterlockedExchangeAdd((volatile signed __int32 *)pointer + 12, 0xFFFFFFFF);
}
