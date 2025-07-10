void __usercall survarium::stats_graph::~stats_graph(survarium::stats_graph *this@<ecx>, int a2@<edi>)
{
  unsigned int i; // ebp
  _DWORD *v3; // eax
  void *v4; // esi
  _DWORD *v5; // eax
  void *v6; // esi

  for ( i = 0; i < *(_DWORD *)(a2 + 32); ++i )
  {
    v3 = *(_DWORD **)a2;
    *(_DWORD *)a2 = **(_DWORD **)a2;
    if ( v3 )
    {
      v4 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
      *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
      vostok_mspace_free(v4, v3);
    }
  }
  while ( *(_DWORD *)(a2 + 4) )
  {
    v5 = *(_DWORD **)(a2 + 4);
    *(_DWORD *)(a2 + 4) = *v5;
    if ( v5 )
    {
      v6 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
      *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
      vostok_mspace_free(v6, v5);
    }
  }
}
