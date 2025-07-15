btVector3 *__userpurge vostok::physics::old_bullet_character_controller::updateTargetPositionBasedOnCollision@<eax>(
        const btVector3 *target_pos@<edx>,
        btVector3 *result@<eax>,
        vostok::physics::old_bullet_character_controller *this,
        const btVector3 *hitNormal,
        float __formal,
        float normalMag)
{
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm6_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm0_4
  float v12; // xmm4_4
  float v13; // xmm6_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  float v20; // xmm6_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm0_4
  float v24; // xmm4_4
  float v25; // xmm6_4
  float v26; // [esp+0h] [ebp-14h]
  float v27; // [esp+8h] [ebp-Ch]
  float v28; // [esp+Ch] [ebp-8h]

  v6 = target_pos->mVec128.m128_f32[1] - this->m_current_pos.mVec128.m128_f32[1];
  v7 = target_pos->mVec128.m128_f32[2] - this->m_current_pos.mVec128.m128_f32[2];
  v8 = target_pos->mVec128.m128_f32[0] - this->m_current_pos.mVec128.m128_f32[0];
  *result = this->m_current_pos;
  v9 = fsqrt((float)((float)(v6 * v6) + (float)(v8 * v8)) + (float)(v7 * v7));
  v26 = v9;
  if ( v9 > 0.00000011920929 )
  {
    v10 = hitNormal->mVec128.m128_f32[2];
    v11 = s_bm_current_air_resistance / v9;
    v12 = hitNormal->mVec128.m128_f32[1];
    v13 = v8 * v11;
    v28 = v11 * v7;
    v27 = v6 * v11;
    v14 = (float)((float)((float)(hitNormal->mVec128.m128_f32[0] * v13) + (float)(v12 * (float)(v6 * v11)))
                + (float)(v10 * (float)(v11 * v7)))
        * 2.0;
    v15 = v28 - (float)(v10 * v14);
    v16 = v12 * v14;
    v17 = v13 - (float)(hitNormal->mVec128.m128_f32[0] * v14);
    v18 = v27 - v16;
    v19 = fsqrt((float)((float)(v15 * v15) + (float)(v18 * v18)) + (float)(v17 * v17));
    v20 = v15 * (float)(s_bm_current_air_resistance / v19);
    v21 = v17 * (float)(s_bm_current_air_resistance / v19);
    v22 = v18 * (float)(s_bm_current_air_resistance / v19);
    v23 = (float)((float)(hitNormal->mVec128.m128_f32[2] * v20) + (float)(hitNormal->mVec128.m128_f32[1] * v22))
        + (float)(hitNormal->mVec128.m128_f32[0] * v21);
    v24 = (float)(v22 - (float)(hitNormal->mVec128.m128_f32[1] * v23)) * v26;
    v25 = (float)(v20 - (float)(hitNormal->mVec128.m128_f32[2] * v23)) * v26;
    result->mVec128.m128_f32[0] = result->mVec128.m128_f32[0]
                                + (float)((float)(v21 - (float)(hitNormal->mVec128.m128_f32[0] * v23)) * v26);
    result->mVec128.m128_f32[1] = result->mVec128.m128_f32[1] + v24;
    result->mVec128.m128_f32[2] = result->mVec128.m128_f32[2] + v25;
  }
  return result;
}
