void __usercall btDiscreteDynamicsWorld::solveConstraints_::_2_::InplaceSolverIslandCallback::processConstraints(
        btDiscreteDynamicsWorld::solveConstraints::__l2::InplaceSolverIslandCallback *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax
  int v3; // edi
  int v4; // edx
  int v5; // eax
  int v6; // edi
  int v7; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  int v10; // ecx
  _DWORD *v11; // eax
  int v12; // edi
  int v13; // ecx
  _DWORD *v14; // eax
  btDiscreteDynamicsWorld::solveConstraints::__l2::InplaceSolverIslandCallback::btManifoldIndexSortPredicate CompareFunc[4]; // [esp+8h] [ebp-4h]

  if ( *(_DWORD *)(a2 + 76) + *(_DWORD *)(a2 + 56) > 0 )
  {
    v2 = *(_DWORD *)(a2 + 56);
    if ( v2 > 1 )
      ___quickSortInternal_UbtManifoldIndexSortPredicate_InplaceSolverIslandCallback__1__solveConstraints_btDiscreteDynamicsWorld__MAEXAAUbtContactSolverInfo___Z____btAlignedObjectArray_PAVbtPersistentManifold____QAEXUbtManifoldIndexSortPredicate_InplaceSolverIslandCallback__1__solveConstraints_btDiscreteDynamicsWorld__MAEXAAUbtContactSolverInfo___Z_HH_Z(
        (btAlignedObjectArray<btPersistentManifold *> *)(a2 + 52),
        0,
        0,
        v2 - 1);
    if ( *(_DWORD *)(a2 + 36) )
      *(_DWORD *)CompareFunc = *(_DWORD *)(a2 + 44);
    else
      *(_DWORD *)CompareFunc = 0;
    if ( *(_DWORD *)(a2 + 56) )
      v3 = *(_DWORD *)(a2 + 64);
    else
      v3 = 0;
    v4 = *(_DWORD *)(a2 + 76);
    if ( v4 )
      v5 = *(_DWORD *)(a2 + 84);
    else
      v5 = 0;
    (*(void (__thiscall **)(_DWORD, btDiscreteDynamicsWorld::solveConstraints::__l2::InplaceSolverIslandCallback::btManifoldIndexSortPredicate *, _DWORD, int, _DWORD, int, int, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(a2 + 8) + 8))(
      *(_DWORD *)(a2 + 8),
      *(btDiscreteDynamicsWorld::solveConstraints::__l2::InplaceSolverIslandCallback::btManifoldIndexSortPredicate **)CompareFunc,
      *(_DWORD *)(a2 + 36),
      v3,
      *(_DWORD *)(a2 + 56),
      v5,
      v4,
      *(_DWORD *)(a2 + 4),
      *(_DWORD *)(a2 + 20),
      *(_DWORD *)(a2 + 24),
      *(_DWORD *)(a2 + 28));
  }
  v6 = *(_DWORD *)(a2 + 36);
  if ( v6 <= 0 )
  {
    if ( v6 < 0 && *(int *)(a2 + 40) < 0 )
    {
      if ( *(_DWORD *)(a2 + 44) )
      {
        if ( *(_BYTE *)(a2 + 48) )
          btAlignedFreeInternal(*(void **)(a2 + 44));
        *(_DWORD *)(a2 + 44) = 0;
      }
      *(_BYTE *)(a2 + 48) = 1;
      *(_DWORD *)(a2 + 44) = 0;
      *(_DWORD *)(a2 + 40) = 0;
    }
    if ( v6 < 0 )
    {
      v7 = 4 * v6;
      do
      {
        v8 = (_DWORD *)(v7 + *(_DWORD *)(a2 + 44));
        if ( v8 )
          *v8 = 0;
        v7 += 4;
      }
      while ( v7 < 0 );
    }
  }
  *(_DWORD *)(a2 + 36) = 0;
  v9 = *(_DWORD *)(a2 + 56);
  if ( v9 <= 0 )
  {
    if ( v9 < 0 && *(int *)(a2 + 60) < 0 )
    {
      if ( *(_DWORD *)(a2 + 64) )
      {
        if ( *(_BYTE *)(a2 + 68) )
          btAlignedFreeInternal(*(void **)(a2 + 64));
        *(_DWORD *)(a2 + 64) = 0;
      }
      *(_BYTE *)(a2 + 68) = 1;
      *(_DWORD *)(a2 + 64) = 0;
      *(_DWORD *)(a2 + 60) = 0;
    }
    if ( v9 < 0 )
    {
      v10 = 4 * v9;
      do
      {
        v11 = (_DWORD *)(v10 + *(_DWORD *)(a2 + 64));
        if ( v11 )
          *v11 = 0;
        v10 += 4;
      }
      while ( v10 < 0 );
    }
  }
  *(_DWORD *)(a2 + 56) = 0;
  v12 = *(_DWORD *)(a2 + 76);
  if ( v12 <= 0 )
  {
    if ( v12 < 0 && *(int *)(a2 + 80) < 0 )
    {
      if ( *(_DWORD *)(a2 + 84) )
      {
        if ( *(_BYTE *)(a2 + 88) )
          btAlignedFreeInternal(*(void **)(a2 + 84));
        *(_DWORD *)(a2 + 84) = 0;
      }
      *(_BYTE *)(a2 + 88) = 1;
      *(_DWORD *)(a2 + 84) = 0;
      *(_DWORD *)(a2 + 80) = 0;
    }
    if ( v12 < 0 )
    {
      v13 = 4 * v12;
      do
      {
        v14 = (_DWORD *)(v13 + *(_DWORD *)(a2 + 84));
        if ( v14 )
          *v14 = 0;
        v13 += 4;
      }
      while ( v13 < 0 );
    }
  }
  *(_DWORD *)(a2 + 76) = 0;
}
