void __thiscall btBvhTriangleMeshShape::setLocalScaling(btBvhTriangleMeshShape *this, btTriangleMeshShape *scaling)
{
  const btVector3 *v3; // eax
  float v4; // xmm1_4
  float v5; // xmm2_4
  btBvhTriangleMeshShape *v6; // ecx

  v3 = this->getLocalScaling(this);
  v4 = v3->mVec128.m128_f32[1] - *(float *)&scaling->m_shapeType;
  v5 = v3->mVec128.m128_f32[2] - *(float *)&scaling->m_userPointer;
  if ( (float)((float)((float)((float)(v3->mVec128.m128_f32[0] - *(float *)&scaling->__vftable)
                             * (float)(v3->mVec128.m128_f32[0] - *(float *)&scaling->__vftable))
                     + (float)(v4 * v4))
             + (float)(v5 * v5)) > 0.00000011920929 )
  {
    this->m_meshInterface->m_scaling = (btVector3)scaling->btConcaveShape;
    btTriangleMeshShape::recalcLocalAabb(scaling);
    btBvhTriangleMeshShape::buildOptimizedBvh(v6, (int)this);
  }
}
