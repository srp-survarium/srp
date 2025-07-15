btDbvtAabbMm *__usercall VolumeOf@<eax>(const btSoftBody::Face *f@<ecx>, btDbvtAabbMm *result@<eax>, float margin)
{
  btSoftBody::Node *v3; // edx
  btSoftBody::Node *v4; // esi
  btSoftBody::Node *v5; // ecx
  btVector3 *p_mx; // ecx
  int i; // esi
  int v8; // edx
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  _DWORD v15[3]; // [esp+14h] [ebp-Ch]

  v3 = f->m_n[1];
  v4 = f->m_n[0];
  v5 = f->m_n[2];
  v4 = (btSoftBody::Node *)((char *)v4 + 16);
  v15[0] = v4;
  v15[2] = &v5->m_x;
  p_mx = &result->mx;
  result->mx.mVec128.m128_i32[0] = (int)v4->m_tag;
  v4 = (btSoftBody::Node *)((char *)v4 + 4);
  result->mx.mVec128.m128_i32[1] = (int)v4->m_tag;
  result->mx.mVec128.m128_u64[1] = *(_QWORD *)&v4->m_material;
  result->mi = result->mx;
  v15[1] = &v3->m_x;
  for ( i = 1; i < 3; ++i )
  {
    v8 = v15[i];
    if ( result->mi.mVec128.m128_f32[0] > *(float *)v8 )
      result->mi.mVec128.m128_i32[0] = *(_DWORD *)v8;
    v9 = *(float *)(v8 + 4);
    if ( result->mi.mVec128.m128_f32[1] > v9 )
      result->mi.mVec128.m128_f32[1] = v9;
    v10 = *(float *)(v8 + 8);
    if ( result->mi.mVec128.m128_f32[2] > v10 )
      result->mi.mVec128.m128_f32[2] = v10;
    v11 = *(float *)(v8 + 12);
    if ( result->mi.mVec128.m128_f32[3] > v11 )
      result->mi.mVec128.m128_f32[3] = v11;
    if ( *(float *)v8 > p_mx->mVec128.m128_f32[0] )
      p_mx->mVec128.m128_i32[0] = *(_DWORD *)v8;
    v12 = *(float *)(v8 + 4);
    if ( v12 > result->mx.mVec128.m128_f32[1] )
      result->mx.mVec128.m128_f32[1] = v12;
    v13 = *(float *)(v8 + 8);
    if ( v13 > result->mx.mVec128.m128_f32[2] )
      result->mx.mVec128.m128_f32[2] = v13;
    v14 = *(float *)(v8 + 12);
    if ( v14 > result->mx.mVec128.m128_f32[3] )
      result->mx.mVec128.m128_f32[3] = v14;
  }
  result->mi.mVec128.m128_f32[0] = result->mi.mVec128.m128_f32[0] - margin;
  result->mi.mVec128.m128_f32[1] = result->mi.mVec128.m128_f32[1] - margin;
  result->mi.mVec128.m128_f32[2] = result->mi.mVec128.m128_f32[2] - margin;
  p_mx->mVec128.m128_f32[0] = p_mx->mVec128.m128_f32[0] + margin;
  result->mx.mVec128.m128_f32[1] = result->mx.mVec128.m128_f32[1] + margin;
  result->mx.mVec128.m128_f32[2] = result->mx.mVec128.m128_f32[2] + margin;
  return result;
}
