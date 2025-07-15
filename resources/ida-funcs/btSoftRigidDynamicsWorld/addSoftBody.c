void __userpurge btSoftRigidDynamicsWorld::addSoftBody(
        btSoftRigidDynamicsWorld *this@<ecx>,
        int a2@<esi>,
        btSoftBody *body,
        __int16 collisionFilterGroup,
        __int16 collisionFilterMask)
{
  int v5; // ecx
  int v6; // eax
  btSoftBody *v7; // ebx
  int v8; // edi
  _DWORD *v9; // ebp
  int v10; // edx
  int v11; // eax
  _DWORD *v12; // ecx
  void *v13; // eax
  btSoftBody **v14; // eax

  v5 = *(_DWORD *)(a2 + 280);
  v6 = *(_DWORD *)(a2 + 276);
  v7 = body;
  if ( v6 == v5 )
  {
    v8 = 2 * v6;
    if ( !v6 )
      v8 = 1;
    if ( v5 < v8 )
    {
      if ( v8 )
      {
        ++gNumAlignedAllocs;
        v9 = sAlignedAllocFunc(4 * v8, 16);
      }
      else
      {
        v9 = 0;
      }
      v10 = *(_DWORD *)(a2 + 276);
      v11 = 0;
      if ( v10 > 0 )
      {
        v12 = v9;
        do
        {
          if ( v12 )
            *v12 = *(_DWORD *)(*(_DWORD *)(a2 + 284) + 4 * v11);
          ++v11;
          ++v12;
        }
        while ( v11 < v10 );
        v7 = body;
      }
      v13 = *(void **)(a2 + 284);
      if ( v13 )
      {
        if ( *(_BYTE *)(a2 + 288) )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v13);
        }
        *(_DWORD *)(a2 + 284) = 0;
      }
      *(_DWORD *)(a2 + 284) = v9;
      *(_BYTE *)(a2 + 288) = 1;
      *(_DWORD *)(a2 + 280) = v8;
    }
  }
  v14 = (btSoftBody **)(*(_DWORD *)(a2 + 284) + 4 * *(_DWORD *)(a2 + 276));
  if ( v14 )
    *v14 = v7;
  ++*(_DWORD *)(a2 + 276);
  v7->m_softBodySolver = *(btSoftBodySolver **)(a2 + 416);
  btCollisionWorld::addCollisionObject((btCollisionWorld *)a2, v7, 1, -1);
}
