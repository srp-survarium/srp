void __userpurge vostok::physics::bullet_character_controller::step_jump_up(
        vostok::physics::bullet_character_controller *this@<ecx>,
        const btVector3 *a2@<eax>,
        const stlp_std::random_access_iterator_tag *a3@<esi>,
        btVector3 *up_step)
{
  btVector3 *v4; // edi
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  int *v9; // edi
  float v10; // [esp+1Ch] [ebp-34h] BYREF
  float v11; // [esp+20h] [ebp-30h]
  float v12; // [esp+24h] [ebp-2Ch]
  float v13; // [esp+28h] [ebp-28h]
  int v14; // [esp+2Ch] [ebp-24h]
  btVector3 out_closest_hit_fraction; // [esp+30h] [ebp-20h] BYREF
  btVector3 out_hit_normal_world; // [esp+40h] [ebp-10h] BYREF

  v4 = (btVector3 *)&a2[4];
  v5 = a2[4].mVec128.m128_f32[0]
     + (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0] * *(float *)&up_step);
  v12 = a2[4].mVec128.m128_f32[1]
      + (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1] * *(float *)&up_step);
  v13 = a2[4].mVec128.m128_f32[2]
      + (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2] * *(float *)&up_step);
  v14 = 0;
  v11 = v5;
  v10 = s_bm_current_air_resistance;
  if ( vostok::physics::character_controller_jump_vertical_tester::convex_sweep_test(
         (vostok::physics::character_controller_jump_vertical_tester *)&out_hit_normal_world,
         (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type>::cache_predicate)&a2[4],
         a3,
         (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *)&a2[64],
         a2[4].mVec128.m128_f32,
         up_step,
         &out_hit_normal_world,
         &out_closest_hit_fraction,
         &v10) )
  {
    v6 = v10;
    v7 = s_bm_current_air_resistance - v10;
    v8 = v12;
    v4->mVec128.m128_f32[0] = (float)(v4->mVec128.m128_f32[0] * (float)(s_bm_current_air_resistance - v10))
                            + (float)(v11 * v10);
    v4->mVec128.m128_f32[1] = (float)(v4->mVec128.m128_f32[1] * v7) + (float)(v8 * v6);
    v4->mVec128.m128_f32[2] = (float)(v4->mVec128.m128_f32[2] * v7) + (float)(v13 * v6);
  }
  else
  {
    v4->mVec128.m128_f32[0] = v11;
    v9 = &v4->mVec128.m128_i32[1];
    *(float *)v9++ = v12;
    *(float *)v9 = v13;
    v9[1] = v14;
  }
}
