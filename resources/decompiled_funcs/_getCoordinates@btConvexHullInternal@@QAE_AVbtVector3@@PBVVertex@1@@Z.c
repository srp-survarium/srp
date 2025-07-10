btVector3 *__userpurge btConvexHullInternal::getCoordinates@<eax>(
        btConvexHullInternal *this@<ecx>,
        int a2@<esi>,
        btVector3 *result,
        const btConvexHullInternal::Vertex *v)
{
  int index; // edi
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  btVector3 *v8; // eax
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // [esp+1Ch] [ebp-14h]
  float v15; // [esp+1Ch] [ebp-14h]
  float v16; // [esp+1Ch] [ebp-14h]
  float v17; // [esp+1Ch] [ebp-14h]
  float v18; // [esp+1Ch] [ebp-14h]
  float v19; // [esp+1Ch] [ebp-14h]
  float v20[4]; // [esp+20h] [ebp-10h]

  index = v->point.index;
  if ( index < 0 )
  {
    v14 = btConvexHullInternal::Int128::toScalar(&v->point128.x);
    v15 = v14 / btConvexHullInternal::Int128::toScalar(&v->point128.denominator);
    x = v15;
  }
  else
  {
    x = (float)v->point.x;
  }
  v20[*(_DWORD *)(a2 + 108)] = x;
  if ( index < 0 )
  {
    v16 = btConvexHullInternal::Int128::toScalar(&v->point128.y);
    v17 = v16 / btConvexHullInternal::Int128::toScalar(&v->point128.denominator);
    y = v17;
  }
  else
  {
    y = (float)v->point.y;
  }
  v20[*(_DWORD *)(a2 + 112)] = y;
  if ( index < 0 )
  {
    v18 = btConvexHullInternal::Int128::toScalar(&v->point128.z);
    v19 = v18 / btConvexHullInternal::Int128::toScalar(&v->point128.denominator);
    z = v19;
  }
  else
  {
    z = (float)v->point.z;
  }
  v8 = result;
  v9 = *(float *)(a2 + 16);
  v10 = *(float *)(a2 + 4);
  v11 = *(float *)(a2 + 8);
  v20[*(_DWORD *)(a2 + 104)] = z;
  v12 = v11 * v20[2];
  v13 = v9 + (float)(*(float *)a2 * v20[0]);
  result->mVec128.m128_f32[1] = *(float *)(a2 + 20) + (float)(v10 * v20[1]);
  result->mVec128.m128_f32[2] = *(float *)(a2 + 24) + v12;
  result->mVec128.m128_f32[0] = v13;
  result->mVec128.m128_i32[3] = 0;
  return v8;
}
