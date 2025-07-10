void __cdecl SpeedTree::st_delete_array<SpeedTree::CArray<SpeedTree::CInstance,1>>(
        SpeedTree::CArray<SpeedTree::CInstance,1> **pRawBlock)
{
  void (__thiscall ***v1)(_DWORD, _DWORD); // esi
  unsigned int *v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // edi

  v1 = (void (__thiscall ***)(_DWORD, _DWORD))*pRawBlock;
  if ( *pRawBlock )
  {
    v2 = (unsigned int *)(v1 - 1);
    if ( v1 != (void (__thiscall ***)(_DWORD, _DWORD))4 )
    {
      v3 = *v2;
      SpeedTree::g_siHeapMemoryUsed += -4 - 20 * *v2;
      v4 = 0;
      if ( v3 )
      {
        do
        {
          (**v1)(v1, 0);
          ++v4;
          v1 += 5;
        }
        while ( v4 < *v2 );
      }
      if ( SpeedTree::g_pAllocator )
        SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, v2);
      *pRawBlock = 0;
    }
  }
}
