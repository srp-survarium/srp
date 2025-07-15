void __usercall ApplyClampedForce(btSoftBody::Node *n@<esi>, const btVector3 *f@<eax>, float dt)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // [esp+10h] [ebp-14h]
  float v10; // [esp+14h] [ebp-10h]
  __int64 v11; // [esp+18h] [ebp-Ch]
  float v12; // [esp+20h] [ebp-4h]

  v3 = n->m_im * dt;
  v4 = f->mVec128.m128_f32[0];
  v11 = *(__int64 *)((char *)f->mVec128.m128_i64 + 4);
  v12 = v3;
  v10 = f->mVec128.m128_f32[0];
  if ( (float)((float)((float)((float)(*((float *)&v11 + 1) * v3) * (float)(*((float *)&v11 + 1) * v3))
                     + (float)((float)(*(float *)&v11 * v3) * (float)(*(float *)&v11 * v3)))
             + (float)((float)(v4 * v3) * (float)(v4 * v3))) <= (float)((float)((float)(n->m_v.mVec128.m128_f32[0]
                                                                                      * n->m_v.mVec128.m128_f32[0])
                                                                              + (float)(n->m_v.mVec128.m128_f32[1]
                                                                                      * n->m_v.mVec128.m128_f32[1]))
                                                                      + (float)(n->m_v.mVec128.m128_f32[2]
                                                                              * n->m_v.mVec128.m128_f32[2])) )
  {
    v8 = n->m_f.mVec128.m128_f32[1];
    n->m_f.mVec128.m128_f32[0] = v4 + n->m_f.mVec128.m128_f32[0];
    n->m_f.mVec128.m128_f32[1] = v8 + f->mVec128.m128_f32[1];
    n->m_f.mVec128.m128_f32[2] = n->m_f.mVec128.m128_f32[2] + f->mVec128.m128_f32[2];
  }
  else
  {
    v9 = 1.0
       / sqrtf(
           (float)((float)(f->mVec128.m128_f32[1] * f->mVec128.m128_f32[1])
                 + (float)(f->mVec128.m128_f32[2] * f->mVec128.m128_f32[2]))
         + (float)(v4 * v4));
    v5 = (float)((float)(n->m_v.mVec128.m128_f32[2] * (float)(*((float *)&v11 + 1) * v9))
               + (float)(n->m_v.mVec128.m128_f32[1] * (float)(*(float *)&v11 * v9)))
       + (float)(n->m_v.mVec128.m128_f32[0] * (float)(v10 * v9));
    v6 = (float)((float)(*(float *)&v11 * v9) * v5) * (float)(*(float *)&clear_value / v12);
    v7 = (float)((float)(*((float *)&v11 + 1) * v9) * v5) * (float)(*(float *)&clear_value / v12);
    n->m_f.mVec128.m128_f32[0] = n->m_f.mVec128.m128_f32[0]
                               - (float)((float)((float)(v10 * v9) * v5) * (float)(*(float *)&clear_value / v12));
    n->m_f.mVec128.m128_f32[1] = n->m_f.mVec128.m128_f32[1] - v6;
    n->m_f.mVec128.m128_f32[2] = n->m_f.mVec128.m128_f32[2] - v7;
  }
}
