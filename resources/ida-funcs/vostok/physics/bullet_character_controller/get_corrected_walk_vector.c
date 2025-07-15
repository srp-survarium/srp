btVector3 *__userpurge vostok::physics::bullet_character_controller::get_corrected_walk_vector@<eax>(
        vostok::physics::bullet_character_controller *this@<ecx>,
        btVector3 *a2@<eax>,
        btVector3 *result)
{
  const btVector3 *v4; // esi
  float v5; // xmm3_4
  float v6; // xmm5_4
  float v7; // xmm6_4
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  int *v13; // esi
  btVector3 v15; // [esp+10h] [ebp-10h] BYREF

  v4 = a2 + 2;
  if ( fabs(
         (float)((float)(a2[2].mVec128.m128_f32[0] * a2[2].mVec128.m128_f32[0])
               + (float)(a2[2].mVec128.m128_f32[1] * a2[2].mVec128.m128_f32[1]))
       + (float)(a2[2].mVec128.m128_f32[2] * a2[2].mVec128.m128_f32[2])) < 0.0000099999997 )
    goto LABEL_5;
  if ( !vostok::physics::bullet_character_controller::on_steep_slope(this, a2->mVec128.m128_f32) )
    goto LABEL_5;
  v5 = (float)((float)(a2[73].mVec128.m128_f32[0]
                     * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0])
             + (float)(a2[73].mVec128.m128_f32[2]
                     * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
     + (float)(a2[73].mVec128.m128_f32[1]
             * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1]);
  v6 = a2[73].mVec128.m128_f32[2]
     - (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2] * v5);
  v7 = a2[73].mVec128.m128_f32[0]
     - (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0] * v5);
  v8 = a2[73].mVec128.m128_f32[1]
     - (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1] * v5);
  v9 = v4->mVec128.m128_f32[2];
  v10 = s_bm_current_air_resistance / fsqrt((float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)(v6 * v6));
  v11 = v4->mVec128.m128_f32[1] * (float)(v10 * v8);
  v15.mVec128.m128_f32[1] = v10 * v8;
  v12 = v4->mVec128.m128_f32[0];
  v15.mVec128.m128_f32[2] = v10 * v6;
  v15.mVec128.m128_f32[0] = v7 * v10;
  v15.mVec128.m128_i32[3] = 0;
  if ( (float)((float)((float)(v9 * (float)(v10 * v6)) + v11) + (float)(v12 * (float)(v7 * v10))) < 0.0 )
  {
    vostok::physics::get_wall_slide_vector(v4, &v15, result);
  }
  else
  {
LABEL_5:
    result->mVec128.m128_i32[0] = v4->mVec128.m128_i32[0];
    v13 = &v4->mVec128.m128_i32[1];
    result->mVec128.m128_i32[1] = *v13;
    result->mVec128.m128_u64[1] = *(_QWORD *)(v13 + 1);
  }
  return result;
}
