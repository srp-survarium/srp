void __usercall ApplyClampedForce(btSoftBody::Node *n@<eax>, const btVector3 *f@<ecx>, float dt)
{
  float v3; // xmm6_4
  float v4; // xmm4_4
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float v15; // xmm0_4

  v3 = n->m_im * dt;
  v4 = f->mVec128.m128_f32[2];
  v5 = f->mVec128.m128_f32[0];
  v6 = f->mVec128.m128_f32[1];
  if ( (float)((float)((float)((float)(v4 * v3) * (float)(v4 * v3))
                     + (float)((float)(f->mVec128.m128_f32[0] * v3) * (float)(f->mVec128.m128_f32[0] * v3)))
             + (float)((float)(v6 * v3) * (float)(v6 * v3))) <= (float)((float)((float)(n->m_v.mVec128.m128_f32[0]
                                                                                      * n->m_v.mVec128.m128_f32[0])
                                                                              + (float)(n->m_v.mVec128.m128_f32[1]
                                                                                      * n->m_v.mVec128.m128_f32[1]))
                                                                      + (float)(n->m_v.mVec128.m128_f32[2]
                                                                              * n->m_v.mVec128.m128_f32[2])) )
  {
    v15 = n->m_f.mVec128.m128_f32[1];
    n->m_f.mVec128.m128_f32[0] = v5 + n->m_f.mVec128.m128_f32[0];
    n->m_f.mVec128.m128_f32[1] = v15 + f->mVec128.m128_f32[1];
    v14 = n->m_f.mVec128.m128_f32[2] + f->mVec128.m128_f32[2];
  }
  else
  {
    v7 = s_bm_current_air_resistance / fsqrt((float)((float)(v6 * v6) + (float)(v4 * v4)) + (float)(v5 * v5));
    v8 = v4 * v7;
    v9 = v5 * v7;
    v10 = v6 * v7;
    v11 = (float)((float)(n->m_v.mVec128.m128_f32[2] * v8) + (float)(n->m_v.mVec128.m128_f32[1] * v10))
        + (float)(n->m_v.mVec128.m128_f32[0] * (float)(v5 * v7));
    v12 = (float)(v10 * v11) * (float)(s_bm_current_air_resistance / v3);
    v13 = (float)(v8 * v11) * (float)(s_bm_current_air_resistance / v3);
    n->m_f.mVec128.m128_f32[0] = n->m_f.mVec128.m128_f32[0]
                               - (float)((float)(v9 * v11) * (float)(s_bm_current_air_resistance / v3));
    n->m_f.mVec128.m128_f32[1] = n->m_f.mVec128.m128_f32[1] - v12;
    v14 = n->m_f.mVec128.m128_f32[2] - v13;
  }
  n->m_f.mVec128.m128_f32[2] = v14;
}
