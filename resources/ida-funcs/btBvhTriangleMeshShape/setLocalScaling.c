void __thiscall btBvhTriangleMeshShape::setLocalScaling(btBvhTriangleMeshShape *this, const btVector3 *scaling)
{
  const btVector3 *v3; // eax
  float v4; // xmm2_4
  float v5; // xmm1_4
  btBvhTriangleMeshShape *v6; // ecx

  v3 = this->getLocalScaling(this);
  v4 = v3->mVec128.m128_f32[2] - scaling->mVec128.m128_f32[2];
  v5 = v3->mVec128.m128_f32[1] - scaling->mVec128.m128_f32[1];
  if ( (float)((float)((float)((float)(v3->mVec128.m128_f32[0] - scaling->mVec128.m128_f32[0])
                             * (float)(v3->mVec128.m128_f32[0] - scaling->mVec128.m128_f32[0]))
                     + (float)(v4 * v4))
             + (float)(v5 * v5)) > 0.00000011920929 )
  {
    btTriangleMeshShape::setLocalScaling(this, scaling);
    btBvhTriangleMeshShape::buildOptimizedBvh(v6, (int)this);
  }
}
