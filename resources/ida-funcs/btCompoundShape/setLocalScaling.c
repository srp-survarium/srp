void __thiscall btCompoundShape::setLocalScaling(btCompoundShape *this, const btVector3 *scaling)
{
  btCompoundShapeChild *v3; // eax
  float *v4; // eax
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  int *v8; // esi
  btCompoundShapeChild *m_data; // eax
  float v10; // xmm1_4
  float v11; // xmm2_4
  btCompoundShape_vtbl *v12; // eax
  int v13; // [esp+18h] [ebp-78h]
  int v14; // [esp+1Ch] [ebp-74h]
  float v15; // [esp+20h] [ebp-70h] BYREF
  float v16; // [esp+24h] [ebp-6Ch]
  float v17; // [esp+28h] [ebp-68h]
  int v18; // [esp+2Ch] [ebp-64h]
  float v19; // [esp+30h] [ebp-60h]
  float v20; // [esp+34h] [ebp-5Ch]
  float v21; // [esp+38h] [ebp-58h]
  int v22; // [esp+3Ch] [ebp-54h]
  btVector3 v23; // [esp+40h] [ebp-50h]
  btTransform m_transform; // [esp+50h] [ebp-40h] BYREF

  v14 = 0;
  if ( this->m_children.m_size > 0 )
  {
    v22 = 0;
    v23.mVec128.m128_i32[3] = 0;
    v13 = 0;
    do
    {
      v3 = &this->m_children.m_data[v13];
      m_transform = v3->m_transform;
      v4 = (float *)v3->m_childShape->getLocalScaling(v3->m_childShape);
      v5 = scaling->mVec128.m128_f32[0];
      v6 = scaling->mVec128.m128_f32[1];
      v7 = scaling->mVec128.m128_f32[2];
      v15 = *v4;
      v16 = v4[1];
      v17 = v4[2];
      v8 = (int *)(v4 + 3);
      m_data = this->m_children.m_data;
      v18 = *v8;
      v10 = (float)(v6 * v16) / this->m_localScaling.mVec128.m128_f32[1];
      v11 = (float)(v7 * v17) / this->m_localScaling.mVec128.m128_f32[2];
      v19 = (float)(v5 * v15) / this->m_localScaling.mVec128.m128_f32[0];
      v20 = v10;
      v21 = v11;
      v15 = v19;
      v16 = v10;
      v17 = v11;
      v18 = v22;
      m_data[v13].m_childShape->setLocalScaling(m_data[v13].m_childShape, (const btVector3 *)&v15);
      v23.mVec128.m128_f32[0] = scaling->mVec128.m128_f32[0] * m_transform.m_origin.mVec128.m128_f32[0];
      v23.mVec128.m128_f32[1] = scaling->mVec128.m128_f32[1] * m_transform.m_origin.mVec128.m128_f32[1];
      v23.mVec128.m128_f32[2] = scaling->mVec128.m128_f32[2] * m_transform.m_origin.mVec128.m128_f32[2];
      m_transform.m_origin = (btVector3)v23.mVec128;
      btCompoundShape::updateChildTransform(v14++, &m_transform, this, 0);
      ++v13;
    }
    while ( v14 < this->m_children.m_size );
  }
  v12 = this->__vftable;
  this->m_localScaling = (btVector3)scaling->mVec128;
  v12->recalculateLocalAabb(this);
}
