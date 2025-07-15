void __userpurge vostok::physics::bullet_character_controller::step_jump_down(
        vostok::physics::bullet_character_controller *this@<ecx>,
        const stlp_std::random_access_iterator_tag *a2@<esi>,
        float down_step,
        btVector3 *out_hit_point_world)
{
  float *v4; // edi
  float v5; // xmm3_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  btVector3 *p_out_closest_hit_fraction; // esi
  int *v10; // esi
  float v11; // [esp+1Ch] [ebp-34h] BYREF
  float v12; // [esp+20h] [ebp-30h] BYREF
  float v13; // [esp+24h] [ebp-2Ch]
  float v14; // [esp+28h] [ebp-28h]
  int v15; // [esp+2Ch] [ebp-24h]
  btVector3 out_closest_hit_fraction; // [esp+30h] [ebp-20h] BYREF
  btVector3 out_hit_normal_world; // [esp+40h] [ebp-10h] BYREF

  v4 = (float *)(LODWORD(down_step) + 64);
  v5 = *(float *)(LODWORD(down_step) + 64)
     + (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]
             * *(float *)&out_hit_point_world);
  v13 = *(float *)(LODWORD(down_step) + 68)
      + (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1]
              * *(float *)&out_hit_point_world);
  v14 = *(float *)(LODWORD(down_step) + 72)
      + (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]
              * *(float *)&out_hit_point_world);
  v15 = 0;
  v12 = v5;
  v11 = s_bm_current_air_resistance;
  if ( vostok::physics::character_controller_jump_vertical_tester::convex_sweep_test(
         (vostok::physics::character_controller_jump_vertical_tester *)this,
         (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type>::cache_predicate)(LODWORD(down_step) + 64),
         a2,
         (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *)(LODWORD(down_step) + 1088),
         (float *)(LODWORD(down_step) + 64),
         out_hit_point_world,
         &out_hit_normal_world,
         &out_closest_hit_fraction,
         &v11) )
  {
    v6 = v11;
    v7 = s_bm_current_air_resistance - v11;
    *v4 = (float)(v12 * v11) + (float)((float)(s_bm_current_air_resistance - v11) * *v4);
    v8 = v14;
    *(float *)(LODWORD(down_step) + 68) = (float)(*(float *)(LODWORD(down_step) + 68) * v7) + (float)(v13 * v6);
    *(float *)(LODWORD(down_step) + 72) = (float)(*(float *)(LODWORD(down_step) + 72) * v7) + (float)(v8 * v6);
    p_out_closest_hit_fraction = &out_closest_hit_fraction;
  }
  else
  {
    *v4 = v12;
    *(float *)(LODWORD(down_step) + 68) = v13;
    *(float *)(LODWORD(down_step) + 72) = v14;
    *(_DWORD *)(LODWORD(down_step) + 76) = v15;
    LODWORD(v12) = vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_i32[0] ^ _mask__NegFloat_;
    LODWORD(v13) = vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_i32[1] ^ _mask__NegFloat_;
    LODWORD(v14) = vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_i32[2] ^ _mask__NegFloat_;
    v15 = 0;
    p_out_closest_hit_fraction = (btVector3 *)&v12;
  }
  *(_DWORD *)(LODWORD(down_step) + 1168) = p_out_closest_hit_fraction->mVec128.m128_i32[0];
  v10 = &p_out_closest_hit_fraction->mVec128.m128_i32[1];
  *(_DWORD *)(LODWORD(down_step) + 1172) = *v10++;
  *(_DWORD *)(LODWORD(down_step) + 1176) = *v10;
  *(_DWORD *)(LODWORD(down_step) + 1180) = v10[1];
}
