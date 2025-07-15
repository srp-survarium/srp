vostok::math::float3 *__cdecl survarium::get_air_control_vector(float *air_control_speed, float jump_type, int a3)
{
  const survarium::player_input *v3; // ecx
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v20; // [esp+Ch] [ebp-4h]

  switch ( survarium::get_move_direction(v3) )
  {
    case 0:
      v4 = 0.0;
      *air_control_speed = 0.0;
      goto LABEL_3;
    case 1:
      if ( (unsigned int)(a3 - 2) <= 5 )
      {
        v5 = 0.0;
        v20 = 0.0;
      }
      else
      {
        v5 = jump_type * 0.0;
        v20 = jump_type;
      }
      *air_control_speed = v5;
      air_control_speed[1] = v5;
      air_control_speed[2] = v20;
      return (vostok::math::float3 *)air_control_speed;
    case 2:
      v8 = sqrt(2.0);
      v9 = s_bm_current_air_resistance / v8;
      v10 = s_bm_current_air_resistance / v8;
      goto LABEL_14;
    case 3:
      v6 = jump_type;
      *air_control_speed = jump_type;
      goto LABEL_10;
    case 4:
      v11 = sqrt(2.0);
      v12 = s_bm_current_air_resistance / v11;
      v13 = (float)((float)(s_bm_current_air_resistance / v11) * 0.0) * jump_type;
      v14 = v12 * jump_type;
      v4 = (float)(v12 * -1.0) * jump_type;
      *air_control_speed = v14;
      air_control_speed[1] = v13;
      goto LABEL_4;
    case 5:
      v7 = jump_type * 0.0;
      air_control_speed[1] = jump_type * 0.0;
      air_control_speed[2] = jump_type * -1.0;
      goto LABEL_18;
    case 6:
      v15 = sqrt(2.0);
      v9 = s_bm_current_air_resistance / v15;
      v10 = (float)(s_bm_current_air_resistance / v15) * -1.0;
LABEL_14:
      *air_control_speed = v10 * jump_type;
      air_control_speed[1] = (float)(v9 * 0.0) * jump_type;
      air_control_speed[2] = v10 * jump_type;
      break;
    case 7:
      v6 = jump_type;
      *air_control_speed = jump_type * -1.0;
LABEL_10:
      v4 = v6 * 0.0;
LABEL_3:
      air_control_speed[1] = v4;
LABEL_4:
      air_control_speed[2] = v4;
      break;
    case 8:
      v16 = sqrt(2.0);
      v17 = s_bm_current_air_resistance / v16;
      v18 = (float)((float)(s_bm_current_air_resistance / v16) * 0.0) * jump_type;
      v7 = (float)((float)(s_bm_current_air_resistance / v16) * -1.0) * jump_type;
      air_control_speed[1] = v18;
      air_control_speed[2] = v17 * jump_type;
LABEL_18:
      *air_control_speed = v7;
      break;
  }
  return (vostok::math::float3 *)air_control_speed;
}
