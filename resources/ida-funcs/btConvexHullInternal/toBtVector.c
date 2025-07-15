btVector3 *__userpurge btConvexHullInternal::toBtVector@<eax>(
        const btConvexHullInternal::Point32 *v@<edx>,
        btVector3 *result@<eax>,
        btConvexHullInternal *this)
{
  btVector3 p; // [esp+0h] [ebp-10h]

  p.mVec128.m128_f32[this->medAxis] = (float)v->x;
  p.mVec128.m128_f32[this->maxAxis] = (float)v->y;
  p.mVec128.m128_f32[this->minAxis] = (float)v->z;
  result->mVec128.m128_f32[0] = this->scaling.mVec128.m128_f32[0] * p.mVec128.m128_f32[0];
  result->mVec128.m128_f32[1] = this->scaling.mVec128.m128_f32[1] * p.mVec128.m128_f32[1];
  result->mVec128.m128_f32[2] = this->scaling.mVec128.m128_f32[2] * p.mVec128.m128_f32[2];
  result->mVec128.m128_i32[3] = 0;
  return result;
}
