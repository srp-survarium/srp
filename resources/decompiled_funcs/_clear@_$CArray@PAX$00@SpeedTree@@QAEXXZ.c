void __usercall SpeedTree::CArray<void *,1>::clear(SpeedTree::CArray<void *,1> *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  _DWORD *v3; // eax

  if ( !*(_BYTE *)(a2 + 16) )
  {
    v2 = *(_DWORD *)(a2 + 4);
    if ( v2 )
    {
      v3 = (_DWORD *)(v2 - 4);
      if ( v3 )
      {
        SpeedTree::g_siHeapMemoryUsed += -4 - 4 * *v3;
        if ( SpeedTree::g_pAllocator )
          SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, v3);
      }
    }
    *(_DWORD *)(a2 + 4) = 0;
    *(_DWORD *)(a2 + 12) = 0;
  }
  *(_DWORD *)(a2 + 8) = 0;
}
