void __thiscall vostok::physics::bullet_character_controller::update_slide_velocity(
        vostok::physics::bullet_character_controller *this,
        const btVector3 *slide_acceleration,
        const btVector3 *pre_step_bottom_pos,
        float *time_fraction,
        float a5)
{
  btVector3 *v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // [esp+10h] [ebp-60h]
  float v15; // [esp+18h] [ebp-58h]
  btVector3 v16; // [esp+20h] [ebp-50h] BYREF
  btVector3 v17; // [esp+30h] [ebp-40h] BYREF
  btVector3 v18; // [esp+40h] [ebp-30h] BYREF
  btVector3 v19; // [esp+50h] [ebp-20h] BYREF
  btVector3 v20; // [esp+60h] [ebp-10h] BYREF

  v5 = (btVector3 *)&slide_acceleration[77];
  v15 = pre_step_bottom_pos->mVec128.m128_f32[0];
  if ( (float)((float)((float)(pre_step_bottom_pos->mVec128.m128_f32[1] * pre_step_bottom_pos->mVec128.m128_f32[1])
                     + (float)(pre_step_bottom_pos->mVec128.m128_f32[2] * pre_step_bottom_pos->mVec128.m128_f32[2]))
             + (float)(v15 * v15)) > 0.0000099999997
    || (float)((float)((float)(v5->mVec128.m128_f32[0] * v5->mVec128.m128_f32[0])
                     + (float)(slide_acceleration[77].mVec128.m128_f32[1] * slide_acceleration[77].mVec128.m128_f32[1]))
             + (float)(slide_acceleration[77].mVec128.m128_f32[2] * slide_acceleration[77].mVec128.m128_f32[2])) > 0.0000099999997 )
  {
    vostok::physics::capsule_center_to_bottom_position(
      slide_acceleration + 4,
      (const btCapsuleShape *)&slide_acceleration[26],
      (int)&v19);
    v6 = v19.mVec128.m128_f32[1] - time_fraction[1];
    v7 = v19.mVec128.m128_f32[2] - time_fraction[2];
    v8 = s_bm_current_air_resistance / (float)(slide_acceleration[72].mVec128.m128_f32[1] * a5);
    v17.mVec128.m128_f32[0] = (float)(v19.mVec128.m128_f32[0] - *time_fraction) * v8;
    v17.mVec128.m128_f32[1] = v6 * v8;
    v17.mVec128.m128_f32[2] = v7 * v8;
    v17.mVec128.m128_i32[3] = 0;
    memset(&v16, 0, sizeof(v16));
    vostok::physics::normalized_safe(v5, &v18, &v16);
    v9 = (float)((float)(v18.mVec128.m128_f32[0] * v17.mVec128.m128_f32[0])
               + (float)(v18.mVec128.m128_f32[1] * v17.mVec128.m128_f32[1]))
       + (float)(v18.mVec128.m128_f32[2] * v17.mVec128.m128_f32[2]);
    v16.mVec128.m128_f32[0] = v18.mVec128.m128_f32[0] * v9;
    v16.mVec128.m128_f32[1] = v18.mVec128.m128_f32[1] * v9;
    v16.mVec128.m128_f32[2] = v18.mVec128.m128_f32[2] * v9;
    v16.mVec128.m128_i32[3] = 0;
    memset(&v19, 0, sizeof(v19));
    vostok::physics::normalized_safe(&v17, &v20, &v19);
    if ( fabs(
           (float)((float)(v5->mVec128.m128_f32[0] * v5->mVec128.m128_f32[0])
                 + (float)(v5->mVec128.m128_f32[1] * v5->mVec128.m128_f32[1]))
         + (float)(v5->mVec128.m128_f32[2] * v5->mVec128.m128_f32[2])) < 0.0000099999997
      || (float)((float)((float)(v16.mVec128.m128_f32[2] * v16.mVec128.m128_f32[2])
                       + (float)(v16.mVec128.m128_f32[1] * v16.mVec128.m128_f32[1]))
               + (float)(v16.mVec128.m128_f32[0] * v16.mVec128.m128_f32[0])) > (float)((float)((float)(v5->mVec128.m128_f32[0] * v5->mVec128.m128_f32[0])
                                                                                             + (float)(v5->mVec128.m128_f32[1] * v5->mVec128.m128_f32[1]))
                                                                                     + (float)(v5->mVec128.m128_f32[2]
                                                                                             * v5->mVec128.m128_f32[2])) )
    {
      v10 = pre_step_bottom_pos->mVec128.m128_f32[1];
      v11 = pre_step_bottom_pos->mVec128.m128_f32[2];
      v18.mVec128.m128_f32[0] = v17.mVec128.m128_f32[0] - v5->mVec128.m128_f32[0];
      v18.mVec128.m128_f32[1] = v17.mVec128.m128_f32[1] - slide_acceleration[77].mVec128.m128_f32[1];
      v18.mVec128.m128_f32[2] = v17.mVec128.m128_f32[2] - slide_acceleration[77].mVec128.m128_f32[2];
      v18.mVec128.m128_i32[3] = 0;
      if ( (float)((float)((float)(v10 * v10) + (float)(v11 * v11)) + (float)(v15 * v15)) > 0.0000099999997 )
      {
        memset(&v19, 0, sizeof(v19));
        vostok::physics::normalized_safe(&v18, &v20, &v19);
        v14 = (float)((float)(pre_step_bottom_pos->mVec128.m128_f32[1] * v20.mVec128.m128_f32[1])
                    + (float)(pre_step_bottom_pos->mVec128.m128_f32[2] * v20.mVec128.m128_f32[2]))
            + (float)(v15 * v20.mVec128.m128_f32[0]);
        if ( v14 > 0.0 )
        {
          memset(&v19, 0, sizeof(v19));
          vostok::physics::normalized_safe(pre_step_bottom_pos, &v20, &v19);
          v12 = (float)(v20.mVec128.m128_f32[1] * v14) + slide_acceleration[77].mVec128.m128_f32[1];
          v13 = (float)(v20.mVec128.m128_f32[2] * v14) + slide_acceleration[77].mVec128.m128_f32[2];
          v5->mVec128.m128_f32[0] = v5->mVec128.m128_f32[0] + (float)(v20.mVec128.m128_f32[0] * v14);
          slide_acceleration[77].mVec128.m128_f32[1] = v12;
          slide_acceleration[77].mVec128.m128_f32[2] = v13;
        }
      }
    }
    else if ( (float)((float)((float)(v20.mVec128.m128_f32[1] * v18.mVec128.m128_f32[1])
                            + (float)(v20.mVec128.m128_f32[2] * v18.mVec128.m128_f32[2]))
                    + (float)(v20.mVec128.m128_f32[0] * v18.mVec128.m128_f32[0])) >= 0.0 )
    {
      v5->mVec128.m128_i32[0] = v16.mVec128.m128_i32[0];
      *(unsigned __int64 *)((char *)slide_acceleration[77].mVec128.m128_u64 + 4) = *(unsigned __int64 *)((char *)v16.mVec128.m128_u64 + 4);
      slide_acceleration[77].mVec128.m128_i32[3] = v16.mVec128.m128_i32[3];
    }
  }
}
