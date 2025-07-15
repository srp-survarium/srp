btVector3 *__usercall vostok::physics::get_slope_slide_vector@<eax>(
        const btVector3 *slope_normal@<esi>,
        btVector3 *a2@<edi>,
        const btVector3 *up_vector)
{
  float v3; // xmm5_4
  float v4; // xmm6_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm1_4
  float v9; // xmm5_4
  float v10; // xmm4_4
  btVector3 *result; // eax
  float v12; // [esp+4h] [ebp-4Ch]
  float v13; // [esp+8h] [ebp-48h]
  btVector3 v14; // [esp+10h] [ebp-40h] BYREF
  btVector3 v15; // [esp+20h] [ebp-30h] BYREF
  btVector3 v16; // [esp+30h] [ebp-20h] BYREF
  btVector3 v17; // [esp+40h] [ebp-10h] BYREF

  v3 = slope_normal->mVec128.m128_f32[2];
  v4 = slope_normal->mVec128.m128_f32[1];
  v15.mVec128.m128_i32[0] = vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_i32[0]
                          ^ _mask__NegFloat_;
  v12 = slope_normal->mVec128.m128_f32[0];
  v5 = (float)((float)(v4
                     * COERCE_FLOAT(
                         vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_i32[1]
                       ^ _mask__NegFloat_))
             + (float)(v3
                     * COERCE_FLOAT(
                         vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_i32[2]
                       ^ _mask__NegFloat_)))
     + (float)(slope_normal->mVec128.m128_f32[0]
             * COERCE_FLOAT(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_i32[0] ^ _mask__NegFloat_));
  v15.mVec128.m128_i32[1] = vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_i32[1]
                          ^ _mask__NegFloat_;
  v15.mVec128.m128_u64[1] = vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_u32[2]
                          ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
  v16.mVec128.m128_f32[0] = COERCE_FLOAT(
                              vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_i32[0]
                            ^ _mask__NegFloat_)
                          - (float)(v12 * v5);
  v16.mVec128.m128_f32[1] = COERCE_FLOAT(
                              vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_i32[1]
                            ^ _mask__NegFloat_)
                          - (float)(v4 * v5);
  v16.mVec128.m128_f32[2] = COERCE_FLOAT(
                              vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_i32[2]
                            ^ _mask__NegFloat_)
                          - (float)(v3 * v5);
  v16.mVec128.m128_i32[3] = 0;
  vostok::physics::normalized_safe(&v16, &v14, &v15);
  if ( (float)((float)((float)(slope_normal->mVec128.m128_f32[2]
                             * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2])
                     + (float)(slope_normal->mVec128.m128_f32[1]
                             * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1]))
             + (float)(v12 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0])) <= s_cc_slope_slide_full_dot )
  {
    v6 = slope_normal->mVec128.m128_f32[2];
    v7 = slope_normal->mVec128.m128_f32[1];
    v8 = (float)((float)(v7 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1])
               + (float)(v6 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
       + (float)(v12 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]);
    v13 = s_bm_current_air_resistance
        / fabs(
            (float)((float)(v14.mVec128.m128_f32[2]
                          * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2])
                  + (float)(v14.mVec128.m128_f32[1]
                          * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1]))
          + (float)(v14.mVec128.m128_f32[0]
                  * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]));
    memset(&v16, 0, sizeof(v16));
    v15.mVec128.m128_f32[0] = v12
                            - (float)(v8 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]);
    v15.mVec128.m128_f32[1] = v7
                            - (float)(v8 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1]);
    v15.mVec128.m128_f32[2] = v6
                            - (float)(v8 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]);
    v15.mVec128.m128_i32[3] = 0;
    vostok::physics::normalized_safe(&v15, &v17, &v16);
    v9 = (float)(v14.mVec128.m128_f32[1] * v13) + (float)(v17.mVec128.m128_f32[1] * s_cc_slope_slide_bouncing_factor);
    v10 = (float)(v14.mVec128.m128_f32[2] * v13) + (float)(v17.mVec128.m128_f32[2] * s_cc_slope_slide_bouncing_factor);
    a2->mVec128.m128_f32[0] = (float)((float)(v14.mVec128.m128_f32[0] * v13)
                                    + (float)(v17.mVec128.m128_f32[0] * s_cc_slope_slide_bouncing_factor))
                            * *(float *)&up_vector;
    a2->mVec128.m128_f32[1] = v9 * *(float *)&up_vector;
    a2->mVec128.m128_f32[2] = v10 * *(float *)&up_vector;
  }
  else
  {
    a2->mVec128.m128_f32[0] = v14.mVec128.m128_f32[0] * *(float *)&up_vector;
    a2->mVec128.m128_f32[1] = v14.mVec128.m128_f32[1] * *(float *)&up_vector;
    a2->mVec128.m128_f32[2] = v14.mVec128.m128_f32[2] * *(float *)&up_vector;
  }
  result = a2;
  a2->mVec128.m128_i32[3] = 0;
  return result;
}
