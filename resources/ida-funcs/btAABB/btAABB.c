void __stdcall btAABB::btAABB(btAABB *this, float margin)
{
  const btVector3 *V2; // edx
  const btVector3 *V3; // ecx
  const btVector3 *V1; // esi
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm3_4

  if ( V2->mVec128.m128_f32[0] <= V3->mVec128.m128_f32[0] )
    v5 = V2->mVec128.m128_f32[0];
  else
    v5 = V3->mVec128.m128_f32[0];
  if ( V1->mVec128.m128_f32[0] <= v5 )
  {
    v6 = V1->mVec128.m128_f32[0];
  }
  else if ( V2->mVec128.m128_f32[0] <= V3->mVec128.m128_f32[0] )
  {
    v6 = V2->mVec128.m128_f32[0];
  }
  else
  {
    v6 = V3->mVec128.m128_f32[0];
  }
  this->m_min.mVec128.m128_f32[0] = v6;
  v7 = V2->mVec128.m128_f32[1];
  v8 = V3->mVec128.m128_f32[1];
  if ( v7 <= v8 )
    v9 = V2->mVec128.m128_f32[1];
  else
    v9 = V3->mVec128.m128_f32[1];
  if ( V1->mVec128.m128_f32[1] <= v9 )
  {
    v7 = V1->mVec128.m128_f32[1];
  }
  else if ( v7 > v8 )
  {
    v7 = V3->mVec128.m128_f32[1];
  }
  this->m_min.mVec128.m128_f32[1] = v7;
  v10 = V2->mVec128.m128_f32[2];
  v11 = V3->mVec128.m128_f32[2];
  if ( v10 <= v11 )
    v12 = V2->mVec128.m128_f32[2];
  else
    v12 = V3->mVec128.m128_f32[2];
  if ( V1->mVec128.m128_f32[2] <= v12 )
  {
    v10 = V1->mVec128.m128_f32[2];
  }
  else if ( v10 > v11 )
  {
    v10 = V3->mVec128.m128_f32[2];
  }
  this->m_min.mVec128.m128_f32[2] = v10;
  v13 = V3->mVec128.m128_f32[0];
  if ( V3->mVec128.m128_f32[0] <= V2->mVec128.m128_f32[0] )
    v14 = V2->mVec128.m128_f32[0];
  else
    v14 = V3->mVec128.m128_f32[0];
  if ( v14 <= V1->mVec128.m128_f32[0] )
  {
    v13 = V1->mVec128.m128_f32[0];
  }
  else if ( v13 <= V2->mVec128.m128_f32[0] )
  {
    v13 = V2->mVec128.m128_f32[0];
  }
  this->m_max.mVec128.m128_f32[0] = v13;
  v15 = V2->mVec128.m128_f32[1];
  v16 = V3->mVec128.m128_f32[1];
  if ( v16 <= v15 )
    v17 = V2->mVec128.m128_f32[1];
  else
    v17 = V3->mVec128.m128_f32[1];
  if ( v17 <= V1->mVec128.m128_f32[1] )
  {
    v16 = V1->mVec128.m128_f32[1];
  }
  else if ( v16 <= v15 )
  {
    v16 = V2->mVec128.m128_f32[1];
  }
  this->m_max.mVec128.m128_f32[1] = v16;
  v18 = V2->mVec128.m128_f32[2];
  v19 = V3->mVec128.m128_f32[2];
  if ( v19 <= v18 )
    v20 = V2->mVec128.m128_f32[2];
  else
    v20 = V3->mVec128.m128_f32[2];
  if ( v20 <= V1->mVec128.m128_f32[2] )
  {
    v19 = V1->mVec128.m128_f32[2];
  }
  else if ( v19 <= v18 )
  {
    v19 = V2->mVec128.m128_f32[2];
  }
  this->m_max.mVec128.m128_f32[2] = v19;
  this->m_min.mVec128.m128_f32[0] = v6 - margin;
  this->m_min.mVec128.m128_f32[1] = this->m_min.mVec128.m128_f32[1] - margin;
  this->m_min.mVec128.m128_f32[2] = this->m_min.mVec128.m128_f32[2] - margin;
  this->m_max.mVec128.m128_f32[0] = this->m_max.mVec128.m128_f32[0] + margin;
  this->m_max.mVec128.m128_f32[1] = this->m_max.mVec128.m128_f32[1] + margin;
  this->m_max.mVec128.m128_f32[2] = this->m_max.mVec128.m128_f32[2] + margin;
}
