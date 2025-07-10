void __thiscall btSoftSoftCollisionAlgorithm::processCollision(
        btSoftSoftCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        const btDispatcherInfo *__formal,
        btManifoldResult *a5)
{
  (*(void (__thiscall **)(int, btCollisionObject *, btCollisionObject *))(*(_DWORD *)body0[1].m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[1]
                                                                        + 32))(
    body0[1].m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[1],
    body0,
    body1);
}
