void __usercall `btDiscreteDynamicsWorld::solveConstraints'::`2'::InplaceSolverIslandCallback::~InplaceSolverIslandCallback(
        btDiscreteDynamicsWorld::solveConstraints::__l2::InplaceSolverIslandCallback *this@<ecx>,
        int a2@<esi>)
{
  void *v2; // eax
  void *v3; // eax
  void *v4; // eax

  v2 = *(void **)(a2 + 84);
  if ( v2 )
  {
    if ( *(_BYTE *)(a2 + 88) )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v2);
    }
    *(_DWORD *)(a2 + 84) = 0;
  }
  *(_BYTE *)(a2 + 88) = 1;
  *(_DWORD *)(a2 + 84) = 0;
  *(_DWORD *)(a2 + 76) = 0;
  *(_DWORD *)(a2 + 80) = 0;
  v3 = *(void **)(a2 + 64);
  if ( v3 )
  {
    if ( *(_BYTE *)(a2 + 68) )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v3);
    }
    *(_DWORD *)(a2 + 64) = 0;
  }
  *(_BYTE *)(a2 + 68) = 1;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 56) = 0;
  *(_DWORD *)(a2 + 60) = 0;
  v4 = *(void **)(a2 + 44);
  if ( v4 )
  {
    if ( *(_BYTE *)(a2 + 48) )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v4);
    }
    *(_DWORD *)(a2 + 44) = 0;
  }
  *(_DWORD *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_BYTE *)(a2 + 48) = 1;
  *(_DWORD *)a2 = &btSimulationIslandManager::IslandCallback::`vftable';
}
