void __thiscall btSoftRigidCollisionAlgorithm::processCollision(
        btSoftRigidCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  btCollisionObject *v5; // esi
  btCollisionObject *v6; // edi
  int v7; // ecx
  int v8; // eax
  btCollisionObject **v9; // edx

  v5 = body1;
  if ( this->m_isSwapped )
  {
    v6 = body0;
  }
  else
  {
    v5 = body0;
    v6 = body1;
  }
  v7 = *((_DWORD *)&v5[1].__vftable + 1);
  v8 = 0;
  if ( v7 > 0 )
  {
    v9 = (btCollisionObject **)*((_DWORD *)&v5[1].__vftable + 3);
    while ( *v9 != v6 )
    {
      ++v8;
      ++v9;
      if ( v8 >= v7 )
        goto LABEL_10;
    }
    v7 = v8;
  }
LABEL_10:
  if ( v7 == *((_DWORD *)&v5[1].__vftable + 1) )
    (*(void (__thiscall **)(int, btCollisionObject *, btCollisionObject *))(*(_DWORD *)v5[1].m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[1]
                                                                          + 36))(
      v5[1].m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[1],
      v5,
      v6);
}
