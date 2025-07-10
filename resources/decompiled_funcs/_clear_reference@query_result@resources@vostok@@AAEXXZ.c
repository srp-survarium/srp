void __usercall vostok::resources::query_result::clear_reference(
        vostok::resources::query_result *this@<ecx>,
        int a2@<esi>)
{
  int i; // eax

  if ( (*(_DWORD *)(a2 + 688) & 0x40) != 0 )
  {
    for ( i = *(_DWORD *)(a2 + 620); (*(_DWORD *)(i + 688) & 0x40) == 0; i = *(_DWORD *)(i + 620) )
      ;
    for ( ; *(_DWORD *)(i + 620) != a2; i = *(_DWORD *)(i + 620) )
      ;
    *(_DWORD *)(i + 620) = *(_DWORD *)(a2 + 620);
    vostok::threading::interlocked_and((volatile int *)(a2 + 688), 0xFFFFFFBF);
    *(_DWORD *)(a2 + 620) = a2;
  }
}
