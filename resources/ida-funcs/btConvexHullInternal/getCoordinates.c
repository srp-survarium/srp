btVector3 *__userpurge btConvexHullInternal::getCoordinates@<eax>(
        btConvexHullInternal *this@<esi>,
        const btConvexHullInternal::Vertex *v@<edi>,
        btVector3 *a3)
{
  int index; // ebx
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  btVector3 *result; // eax
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // [esp+Ch] [ebp-14h]
  float v14; // [esp+Ch] [ebp-14h]
  float v15; // [esp+Ch] [ebp-14h]
  float v16; // [esp+Ch] [ebp-14h]
  float v17; // [esp+Ch] [ebp-14h]
  float v18; // [esp+Ch] [ebp-14h]
  float v19[4]; // [esp+10h] [ebp-10h]

  index = v->point.index;
  if ( index < 0 )
  {
    v13 = btConvexHullInternal::Int128::toScalar(&v->point128.x);
    v14 = v13 / btConvexHullInternal::Int128::toScalar(&v->point128.denominator);
    x = v14;
  }
  else
  {
    x = (float)v->point.x;
  }
  v19[this->medAxis] = x;
  if ( index < 0 )
  {
    v15 = btConvexHullInternal::Int128::toScalar(&v->point128.y);
    v16 = v15 / btConvexHullInternal::Int128::toScalar(&v->point128.denominator);
    y = v16;
  }
  else
  {
    y = (float)v->point.y;
  }
  v19[this->maxAxis] = y;
  if ( index < 0 )
  {
    v17 = btConvexHullInternal::Int128::toScalar(&v->point128.z);
    v18 = v17 / btConvexHullInternal::Int128::toScalar(&v->point128.denominator);
    z = v18;
  }
  else
  {
    z = (float)v->point.z;
  }
  v7 = this->center.mVec128.m128_f32[0];
  v8 = this->scaling.mVec128.m128_f32[1];
  v9 = this->scaling.mVec128.m128_f32[2];
  v19[this->minAxis] = z;
  result = a3;
  v11 = v9 * v19[2];
  v12 = v7 + (float)(this->scaling.mVec128.m128_f32[0] * v19[0]);
  a3->mVec128.m128_f32[1] = this->center.mVec128.m128_f32[1] + (float)(v8 * v19[1]);
  a3->mVec128.m128_f32[2] = this->center.mVec128.m128_f32[2] + v11;
  a3->mVec128.m128_f32[0] = v12;
  a3->mVec128.m128_i32[3] = 0;
  return result;
}
