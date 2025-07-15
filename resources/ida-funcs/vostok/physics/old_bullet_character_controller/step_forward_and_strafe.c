void __userpurge vostok::physics::old_bullet_character_controller::step_forward_and_strafe(
        const btVector3 *walkMove@<eax>,
        btMatrix3x3 *a2@<ecx>,
        float a3@<edi>,
        float a4@<esi>,
        const btTransform *this)
{
  btVector3 *v5; // ebx
  btMatrix3x3 *v6; // ecx
  vostok::physics::old_bullet_character_controller *v7; // ecx
  float v8; // xmm2_4
  float v9; // xmm4_4
  float v10; // xmm4_4
  int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm1_4
  bool v14; // al
  btVector3 *updated; // eax
  btVector3 *v16; // edx
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  float v22; // [esp+14h] [ebp-F0h]
  float v23; // [esp+18h] [ebp-ECh]
  btVector3 v24; // [esp+24h] [ebp-E0h] BYREF
  float v25; // [esp+38h] [ebp-CCh]
  int v26; // [esp+3Ch] [ebp-C8h]
  float v27; // [esp+40h] [ebp-C4h] BYREF
  unsigned __int64 max_slope_angle_cos; // [esp+44h] [ebp-C0h] BYREF
  float v29; // [esp+4Ch] [ebp-B8h]
  int v30; // [esp+50h] [ebp-B4h]
  btVector3 out_closest_hit_fraction; // [esp+54h] [ebp-B0h] BYREF
  btTransform finish; // [esp+64h] [ebp-A0h] BYREF
  btVector3 up_vector; // [esp+A4h] [ebp-60h] BYREF
  unsigned __int64 v34; // [esp+D4h] [ebp-30h]
  unsigned __int64 v35; // [esp+DCh] [ebp-28h]
  btVector3 v36; // [esp+E4h] [ebp-20h] BYREF
  btVector3 out_hit_normal_world; // [esp+F4h] [ebp-10h] BYREF

  v5 = &this[1].m_basis.m_el[1];
  v24.mVec128.m128_f32[0] = this[1].m_basis.m_el[1].mVec128.m128_f32[0] + walkMove->mVec128.m128_f32[0];
  v24.mVec128.m128_f32[1] = this[1].m_basis.m_el[1].mVec128.m128_f32[1] + walkMove->mVec128.m128_f32[1];
  v23 = a4;
  v22 = a3;
  v24.mVec128.m128_f32[2] = this[1].m_basis.m_el[1].mVec128.m128_f32[2] + walkMove->mVec128.m128_f32[2];
  v24.mVec128.m128_i32[3] = 0;
  btMatrix3x3::setIdentity(a2, (int)&finish);
  memset(&finish.m_origin, 0, sizeof(finish.m_origin));
  btMatrix3x3::setIdentity(v6, (int)&up_vector);
  v8 = this[1].m_basis.m_el[1].mVec128.m128_f32[1] - v24.mVec128.m128_f32[1];
  v9 = (float)(this[1].m_basis.m_el[1].mVec128.m128_f32[2] - v24.mVec128.m128_f32[2])
     * (float)(this[1].m_basis.m_el[1].mVec128.m128_f32[2] - v24.mVec128.m128_f32[2]);
  v25 = s_bm_current_air_resistance;
  v10 = (float)(v9 + (float)(v8 * v8))
      + (float)((float)(v5->mVec128.m128_f32[0] - v24.mVec128.m128_f32[0])
              * (float)(v5->mVec128.m128_f32[0] - v24.mVec128.m128_f32[0]));
  v34 = 0;
  v35 = 0;
  if ( v10 >= 0.00000011920929 )
  {
    v26 = 10;
    do
    {
      v11 = v26--;
      if ( v11 <= 0 )
        break;
      v12 = v5->mVec128.m128_f32[0] - v24.mVec128.m128_f32[0];
      finish.m_origin.mVec128.m128_u64[0] = v5->mVec128.m128_u64[0];
      finish.m_origin.mVec128.m128_u64[1] = this[1].m_basis.m_el[1].mVec128.m128_u64[1];
      v34 = v24.mVec128.m128_u64[0];
      *(float *)&max_slope_angle_cos = v12;
      v13 = this[1].m_basis.m_el[1].mVec128.m128_f32[1] - v24.mVec128.m128_f32[1];
      v35 = v24.mVec128.m128_u64[1];
      *((float *)&max_slope_angle_cos + 1) = v13;
      v29 = this[1].m_basis.m_el[1].mVec128.m128_f32[2] - v24.mVec128.m128_f32[2];
      v30 = 0;
      v14 = vostok::physics::old_bullet_character_controller::convex_sweep_test(
              v7,
              this,
              &finish,
              (btCollisionWorld::ConvexResultCallback *)&up_vector,
              &max_slope_angle_cos,
              COERCE_INT(0.0),
              (btVector3 *)LODWORD(s_cc_max_allowed_penetration_value),
              &out_hit_normal_world,
              out_closest_hit_fraction.mVec128.m128_f32,
              &v27);
      v25 = v25 - v27;
      if ( v14 )
      {
        updated = vostok::physics::old_bullet_character_controller::updateTargetPositionBasedOnCollision(
                    &v24,
                    &v36,
                    (vostok::physics::old_bullet_character_controller *)this,
                    &out_closest_hit_fraction,
                    v22,
                    v23);
        *v16 = (btVector3)updated->mVec128;
        v17 = v24.mVec128.m128_f32[1] - this[1].m_basis.m_el[1].mVec128.m128_f32[1];
        v18 = v24.mVec128.m128_f32[2] - this[1].m_basis.m_el[1].mVec128.m128_f32[2];
        v19 = v24.mVec128.m128_f32[0] - v5->mVec128.m128_f32[0];
        v20 = (float)((float)(v18 * v18) + (float)(v17 * v17)) + (float)(v19 * v19);
        if ( v20 <= 0.00000011920929 )
          return;
        v21 = fsqrt(v20);
        if ( (float)((float)((float)(this[1].m_basis.m_el[0].mVec128.m128_f32[2]
                                   * (float)(v18 * (float)(s_bm_current_air_resistance / v21)))
                           + (float)(this[1].m_basis.m_el[0].mVec128.m128_f32[1]
                                   * (float)(v17 * (float)(s_bm_current_air_resistance / v21))))
                   + (float)(this[1].m_basis.m_el[0].mVec128.m128_f32[0]
                           * (float)(v19 * (float)(s_bm_current_air_resistance / v21)))) <= 0.0 )
          return;
      }
      else
      {
        v5->mVec128.m128_i32[0] = v24.mVec128.m128_i32[0];
        *(unsigned __int64 *)((char *)this[1].m_basis.m_el[1].mVec128.m128_u64 + 4) = *(unsigned __int64 *)((char *)v24.mVec128.m128_u64 + 4);
        this[1].m_basis.m_el[1].mVec128.m128_i32[3] = v24.mVec128.m128_i32[3];
      }
    }
    while ( v25 > 0.0099999998 );
  }
}
