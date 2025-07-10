void __thiscall btCompoundShape::setLocalScaling(btCompoundShape *this, const btVector3 *scaling)
{
  int v3; // ebx
  btCompoundShapeChild *m_data; // eax
  unsigned __int64 v5; // xmm0_8
  btCompoundShapeChild *v6; // eax
  const btVector3 *v7; // eax
  float v8; // xmm1_4
  float v9; // xmm2_4
  btCompoundShapeChild *v10; // ecx
  float v11; // xmm1_4
  float v12; // xmm2_4
  void (__thiscall *recalculateLocalAabb)(btCompoundShape *); // eax
  int v14; // [esp+BCh] [ebp-74h]
  unsigned __int64 v15; // [esp+C0h] [ebp-70h] BYREF
  __int64 v16; // [esp+C8h] [ebp-68h]
  unsigned __int64 v17; // [esp+D0h] [ebp-60h]
  __int64 v18; // [esp+D8h] [ebp-58h]
  __m128i v19; // [esp+E0h] [ebp-50h] BYREF
  btTransform newChildTransform; // [esp+F0h] [ebp-40h] BYREF

  v3 = 0;
  if ( this->m_children.m_size > 0 )
  {
    HIDWORD(v18) = 0;
    v19.m128i_i32[3] = 0;
    v14 = 0;
    do
    {
      m_data = this->m_children.m_data;
      v5 = m_data[v14].m_transform.m_basis.m_el[0].mVec128.m128_u64[0];
      v6 = &m_data[v14];
      newChildTransform.m_basis.m_el[0].mVec128.m128_u64[0] = v5;
      newChildTransform.m_basis.m_el[0].mVec128.m128_u64[1] = v6->m_transform.m_basis.m_el[0].mVec128.m128_u64[1];
      newChildTransform.m_basis.m_el[1] = v6->m_transform.m_basis.m_el[1];
      newChildTransform.m_basis.m_el[2] = v6->m_transform.m_basis.m_el[2];
      newChildTransform.m_origin = v6->m_transform.m_origin;
      v7 = v6->m_childShape->getLocalScaling(v6->m_childShape);
      v8 = scaling->mVec128.m128_f32[1];
      v9 = scaling->mVec128.m128_f32[2];
      v10 = this->m_children.m_data;
      v15 = v7->mVec128.m128_u64[0];
      v11 = (float)(v8 * *((float *)&v15 + 1)) / this->m_localScaling.mVec128.m128_f32[1];
      v16 = v7->mVec128.m128_i64[1];
      v12 = (float)(v9 * *(float *)&v16) / this->m_localScaling.mVec128.m128_f32[2];
      *(float *)&v17 = (float)(scaling->mVec128.m128_f32[0] * *(float *)&v15) / this->m_localScaling.mVec128.m128_f32[0];
      *((float *)&v17 + 1) = v11;
      v15 = v17;
      *(float *)&v18 = v12;
      v16 = v18;
      v10[v14].m_childShape->setLocalScaling(v10[v14].m_childShape, (const btVector3 *)&v15);
      *(float *)v19.m128i_i32 = scaling->mVec128.m128_f32[0] * newChildTransform.m_origin.mVec128.m128_f32[0];
      *(float *)&v19.m128i_i32[1] = scaling->mVec128.m128_f32[1] * newChildTransform.m_origin.mVec128.m128_f32[1];
      *(float *)&v19.m128i_i32[2] = scaling->mVec128.m128_f32[2] * newChildTransform.m_origin.mVec128.m128_f32[2];
      newChildTransform.m_origin = (btVector3)_mm_load_si128(&v19);
      btCompoundShape::updateChildTransform(v3, &newChildTransform, this, 0);
      ++v14;
      ++v3;
    }
    while ( v3 < this->m_children.m_size );
  }
  recalculateLocalAabb = this->recalculateLocalAabb;
  this->m_localScaling = (btVector3)scaling->mVec128;
  recalculateLocalAabb(this);
}
