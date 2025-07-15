int __cdecl _msize(_DWORD *pblock)
{
  int v2; // eax
  int v3; // ecx

  if ( HIBYTE(vostok::memory::g_crt_allocator.__vftable[1].~vostok::memory::doug_lea_mt_allocator) )
    return (*((int (__thiscall **)(vostok::memory::doug_lea_mt_allocator_vtbl *, _DWORD *))vostok::memory::g_crt_allocator.~vostok::memory::doug_lea_mt_allocator
            + 7))(
             vostok::memory::g_crt_allocator.__vftable,
             pblock);
  if ( !pblock )
    return 0;
  v2 = *(pblock - 1);
  if ( (v2 & 2) == 0 )
    return 0;
  if ( (v2 & 1) != 0 || (v3 = 8, (*(_BYTE *)(pblock - 2) & 1) == 0) )
    v3 = 4;
  return (v2 & 0xFFFFFFF8) - v3;
}
