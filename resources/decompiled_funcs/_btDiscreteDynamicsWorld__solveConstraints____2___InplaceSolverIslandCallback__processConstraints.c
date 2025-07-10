void __usercall btDiscreteDynamicsWorld::solveConstraints_::_2_::InplaceSolverIslandCallback::processConstraints(
        btDiscreteDynamicsWorld::solveConstraints::__l2::InplaceSolverIslandCallback *this@<ecx>,
        int a2@<esi>)
{
  int v2; // edx
  int v3; // edi
  int v4; // eax
  int v5; // edi
  void *v6; // eax
  int v7; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  void *v10; // eax
  int v11; // ecx
  _DWORD *v12; // eax
  int v13; // edi
  void *v14; // eax
  int v15; // ecx
  _DWORD *v16; // eax
  btPersistentManifold **manifold; // [esp+8h] [ebp-8h]
  btCollisionObject **bodies; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 76);
  v3 = *(_DWORD *)(a2 + 56);
  if ( v3 + v2 > 0 )
  {
    if ( *(_DWORD *)(a2 + 36) )
      bodies = *(btCollisionObject ***)(a2 + 44);
    else
      bodies = 0;
    if ( v3 )
      manifold = *(btPersistentManifold ***)(a2 + 64);
    else
      manifold = 0;
    if ( v2 )
      v4 = *(_DWORD *)(a2 + 84);
    else
      v4 = 0;
    (*(void (__thiscall **)(_DWORD, btCollisionObject **, _DWORD, btPersistentManifold **, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(a2 + 8) + 8))(
      *(_DWORD *)(a2 + 8),
      bodies,
      *(_DWORD *)(a2 + 36),
      manifold,
      v3,
      v4,
      v2,
      *(_DWORD *)(a2 + 4),
      *(_DWORD *)(a2 + 20),
      *(_DWORD *)(a2 + 24),
      *(_DWORD *)(a2 + 28));
  }
  v5 = *(_DWORD *)(a2 + 36);
  if ( v5 <= 0 )
  {
    if ( v5 < 0 && *(int *)(a2 + 40) < 0 )
    {
      v6 = *(void **)(a2 + 44);
      if ( v6 )
      {
        if ( *(_BYTE *)(a2 + 48) )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v6);
        }
        *(_DWORD *)(a2 + 44) = 0;
      }
      *(_BYTE *)(a2 + 48) = 1;
      *(_DWORD *)(a2 + 44) = 0;
      *(_DWORD *)(a2 + 40) = 0;
    }
    if ( v5 < 0 )
    {
      v7 = 4 * v5;
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
      v10 = *(void **)(a2 + 64);
      if ( v10 )
      {
        if ( *(_BYTE *)(a2 + 68) )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v10);
        }
        *(_DWORD *)(a2 + 64) = 0;
      }
      *(_BYTE *)(a2 + 68) = 1;
      *(_DWORD *)(a2 + 64) = 0;
      *(_DWORD *)(a2 + 60) = 0;
    }
    if ( v9 < 0 )
    {
      v11 = 4 * v9;
      do
      {
        v12 = (_DWORD *)(v11 + *(_DWORD *)(a2 + 64));
        if ( v12 )
          *v12 = 0;
        v11 += 4;
      }
      while ( v11 < 0 );
    }
  }
  *(_DWORD *)(a2 + 56) = 0;
  v13 = *(_DWORD *)(a2 + 76);
  if ( v13 <= 0 )
  {
    if ( v13 < 0 && *(int *)(a2 + 80) < 0 )
    {
      v14 = *(void **)(a2 + 84);
      if ( v14 )
      {
        if ( *(_BYTE *)(a2 + 88) )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v14);
        }
        *(_DWORD *)(a2 + 84) = 0;
      }
      *(_BYTE *)(a2 + 88) = 1;
      *(_DWORD *)(a2 + 84) = 0;
      *(_DWORD *)(a2 + 80) = 0;
    }
    if ( v13 < 0 )
    {
      v15 = 4 * v13;
      do
      {
        v16 = (_DWORD *)(v15 + *(_DWORD *)(a2 + 84));
        if ( v16 )
          *v16 = 0;
        v15 += 4;
      }
      while ( v15 < 0 );
    }
  }
  *(_DWORD *)(a2 + 76) = 0;
}
