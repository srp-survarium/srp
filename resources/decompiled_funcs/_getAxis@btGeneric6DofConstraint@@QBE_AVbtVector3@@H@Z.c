btVector3 *__userpurge btGeneric6DofConstraint::getAxis@<eax>(
        btGeneric6DofConstraint *this@<ecx>,
        btVector3 *a2@<eax>,
        const btGeneric6DofConstraint *result,
        int axis_index)
{
  btVector3 *v4; // ecx

  v4 = (btVector3 *)((char *)result + 16 * ((_DWORD)this->m_frameInA.m_basis.m_el[2].mVec128.m128_i32 + 2));
  a2->mVec128.m128_u64[0] = v4->mVec128.m128_u64[0];
  a2->mVec128.m128_u64[1] = v4->mVec128.m128_u64[1];
  return a2;
}
