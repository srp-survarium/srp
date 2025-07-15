void __thiscall btSoftRigidCollisionAlgorithm::processCollision(
        btSoftRigidCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  btCollisionObject *v5; // esi

  v5 = body1;
  if ( !this->m_isSwapped )
  {
    v5 = body0;
    body0 = body1;
  }
  if ( btAlignedObjectArray<int>::findLinearSearch((btAlignedObjectArray<int> *)&v5[1], (int *)&body0) == *((_DWORD *)&v5[1].__vftable + 1) )
    (*(void (__thiscall **)(int, btCollisionObject *, btCollisionObject *))(*(_DWORD *)v5[1].m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[1]
                                                                          + 36))(
      v5[1].m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[1],
      v5,
      body0);
}
