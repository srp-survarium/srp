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
  int v9; // edx
  int v10; // ecx
  _DWORD *v11; // eax
  btSoftBody **v12; // eax
  _DWORD *v13; // [esp+4h] [ebp-4h]

  v5 = *(_DWORD *)(a2 + 280);
  v6 = *(_DWORD *)(a2 + 276);
  v7 = body;
  if ( v6 == v5 )
  {
    v8 = v6 ? 2 * v6 : 1;
    if ( v5 < v8 )
    {
      if ( v8 )
        v13 = btAlignedAllocInternal(4 * v8);
      else
        v13 = 0;
      v9 = *(_DWORD *)(a2 + 276);
      v10 = 0;
      if ( v9 > 0 )
      {
        v11 = v13;
        do
        {
          if ( v11 )
          {
            *v11 = *(_DWORD *)(*(_DWORD *)(a2 + 284) + 4 * v10);
            v7 = body;
          }
          ++v10;
          ++v11;
        }
        while ( v10 < v9 );
      }
      if ( *(_DWORD *)(a2 + 284) )
      {
        if ( *(_BYTE *)(a2 + 288) )
          btAlignedFreeInternal(*(void **)(a2 + 284));
        *(_DWORD *)(a2 + 284) = 0;
      }
      *(_BYTE *)(a2 + 288) = 1;
      *(_DWORD *)(a2 + 284) = v13;
      *(_DWORD *)(a2 + 280) = v8;
    }
  }
  v12 = (btSoftBody **)(*(_DWORD *)(a2 + 284) + 4 * *(_DWORD *)(a2 + 276));
  if ( v12 )
    *v12 = v7;
  ++*(_DWORD *)(a2 + 276);
  v7->m_softBodySolver = *(btSoftBodySolver **)(a2 + 416);
  btCollisionWorld::addCollisionObject((btCollisionWorld *)a2, v7, 1, -1);
}
