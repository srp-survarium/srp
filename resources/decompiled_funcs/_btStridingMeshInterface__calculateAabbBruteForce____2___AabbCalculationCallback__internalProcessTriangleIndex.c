void __thiscall btStridingMeshInterface::calculateAabbBruteForce_::_2_::AabbCalculationCallback::internalProcessTriangleIndex(
        btStridingMeshInterface::calculateAabbBruteForce::__l2::AabbCalculationCallback *this,
        btVector3 *triangle,
        int partId,
        int triangleIndex)
{
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm0_4

  if ( *((float *)this + 4) > triangle->mVec128.m128_f32[0] )
    *((_DWORD *)this + 4) = triangle->mVec128.m128_i32[0];
  v4 = triangle->mVec128.m128_f32[1];
  if ( *((float *)this + 5) > v4 )
    *((float *)this + 5) = v4;
  v5 = triangle->mVec128.m128_f32[2];
  if ( *((float *)this + 6) > v5 )
    *((float *)this + 6) = v5;
  v6 = triangle->mVec128.m128_f32[3];
  if ( *((float *)this + 7) > v6 )
    *((float *)this + 7) = v6;
  if ( triangle->mVec128.m128_f32[0] > *((float *)this + 8) )
    *((_DWORD *)this + 8) = triangle->mVec128.m128_i32[0];
  v7 = triangle->mVec128.m128_f32[1];
  if ( v7 > *((float *)this + 9) )
    *((float *)this + 9) = v7;
  v8 = triangle->mVec128.m128_f32[2];
  if ( v8 > *((float *)this + 10) )
    *((float *)this + 10) = v8;
  v9 = triangle->mVec128.m128_f32[3];
  if ( v9 > *((float *)this + 11) )
    *((float *)this + 11) = v9;
  v10 = triangle[1].mVec128.m128_f32[0];
  if ( *((float *)this + 4) > v10 )
    *((float *)this + 4) = v10;
  v11 = triangle[1].mVec128.m128_f32[1];
  if ( *((float *)this + 5) > v11 )
    *((float *)this + 5) = v11;
  v12 = triangle[1].mVec128.m128_f32[2];
  if ( *((float *)this + 6) > v12 )
    *((float *)this + 6) = v12;
  v13 = triangle[1].mVec128.m128_f32[3];
  if ( *((float *)this + 7) > v13 )
    *((float *)this + 7) = v13;
  v14 = triangle[1].mVec128.m128_f32[0];
  if ( v14 > *((float *)this + 8) )
    *((float *)this + 8) = v14;
  v15 = triangle[1].mVec128.m128_f32[1];
  if ( v15 > *((float *)this + 9) )
    *((float *)this + 9) = v15;
  v16 = triangle[1].mVec128.m128_f32[2];
  if ( v16 > *((float *)this + 10) )
    *((float *)this + 10) = v16;
  v17 = triangle[1].mVec128.m128_f32[3];
  if ( v17 > *((float *)this + 11) )
    *((float *)this + 11) = v17;
  v18 = triangle[2].mVec128.m128_f32[0];
  if ( *((float *)this + 4) > v18 )
    *((float *)this + 4) = v18;
  v19 = triangle[2].mVec128.m128_f32[1];
  if ( *((float *)this + 5) > v19 )
    *((float *)this + 5) = v19;
  v20 = triangle[2].mVec128.m128_f32[2];
  if ( *((float *)this + 6) > v20 )
    *((float *)this + 6) = v20;
  v21 = triangle[2].mVec128.m128_f32[3];
  if ( *((float *)this + 7) > v21 )
    *((float *)this + 7) = v21;
  v22 = triangle[2].mVec128.m128_f32[0];
  if ( v22 > *((float *)this + 8) )
    *((float *)this + 8) = v22;
  v23 = triangle[2].mVec128.m128_f32[1];
  if ( v23 > *((float *)this + 9) )
    *((float *)this + 9) = v23;
  v24 = triangle[2].mVec128.m128_f32[2];
  if ( v24 > *((float *)this + 10) )
    *((float *)this + 10) = v24;
  v25 = triangle[2].mVec128.m128_f32[3];
  if ( v25 > *((float *)this + 11) )
    *((float *)this + 11) = v25;
}
