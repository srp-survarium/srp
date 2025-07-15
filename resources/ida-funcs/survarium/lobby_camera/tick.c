void __thiscall survarium::lobby_camera::tick(survarium::lobby_camera *this)
{
  float *p_m_current_distance_to_focus_point; // esi
  float v3; // xmm1_4
  float v4; // xmm0_4
  float m_yaw; // xmm1_4
  __m128i m_yaw_low; // xmm0
  vostok::math::float4x4 *v7; // eax
  double v8; // st7
  long double v9; // rdi
  vostok::math::float4x4 *v10; // eax
  double v11; // st7
  vostok::math::float3 *v12; // edx
  vostok::math::float4x4 *rotation; // eax
  float x; // xmm1_4
  double m_target_distance_to_focus_point; // st7
  float z; // ecx
  float *p_m_fov_factor; // esi
  double v18; // st7
  unsigned int v19; // xmm3_4
  float v20; // xmm0_4
  float y; // xmm1_4
  float v22; // [esp+10h] [ebp-FCh]
  vostok::math::float4x4 *v23; // [esp+20h] [ebp-ECh]
  float v24; // [esp+20h] [ebp-ECh]
  float v25; // [esp+20h] [ebp-ECh]
  float v26; // [esp+20h] [ebp-ECh]
  float v27[2]; // [esp+30h] [ebp-DCh] BYREF
  float v28; // [esp+38h] [ebp-D4h]
  float v29; // [esp+3Ch] [ebp-D0h]
  _DWORD v30[3]; // [esp+40h] [ebp-CCh] BYREF
  vostok::math::float4x4 v31; // [esp+4Ch] [ebp-C0h] BYREF
  vostok::math::float4x4 v32; // [esp+8Ch] [ebp-80h] BYREF
  vostok::math::float4x4 v33; // [esp+CCh] [ebp-40h] BYREF

  *(float *)&this->m_lobby_menu = this->m_z_mouse_axis + *(float *)&this->m_lobby_menu;
  this->m_yaw = this->m_rotation_delta.x + this->m_yaw;
  p_m_current_distance_to_focus_point = &this->m_current_distance_to_focus_point;
  v27[0] = 0.0;
  if ( !vostok::math::is_similar<float>(&this->m_current_distance_to_focus_point, v27, 0.0000099999997) )
  {
    v3 = this->m_target_distance_to_focus_point + *p_m_current_distance_to_focus_point;
    this->m_pitch = v3;
    v4 = vostok::sound::s_lpf_param;
    if ( vostok::sound::s_lpf_param < v3 )
    {
      v4 = FLOAT_40_0;
      if ( v3 <= 40.0 )
        v4 = v3;
    }
    this->m_pitch = v4;
  }
  m_yaw = this->m_yaw;
  m_yaw_low = (__m128i)LODWORD(FLOAT_N1_0471976);
  if ( m_yaw > -1.0471976 )
  {
    m_yaw_low = (__m128i)LODWORD(pi_d3);
    if ( m_yaw <= 1.0471976 )
      m_yaw_low = (__m128i)LODWORD(this->m_yaw);
  }
  LODWORD(this->m_yaw) = m_yaw_low.m128i_i32[0];
  v7 = vostok::math::float4x4::identity(v23, &v31);
  v8 = *(float *)&this->m_lobby_menu;
  qmemcpy(&v32, v7, sizeof(v32));
  HIDWORD(v9) = v7 + 1;
  LODWORD(v9) = &v33;
  v24 = v8;
  v10 = vostok::math::create_rotation_y(v9, m_yaw_low, &v33, v24);
  vostok::math::mul4x3(v10, &v32, &v31);
  v11 = this->m_yaw;
  qmemcpy(v12, &v31, 0x40u);
  LODWORD(v9) = v12;
  v25 = v11;
  rotation = vostok::math::create_rotation(v12, (int)&v33, m_yaw_low, v25);
  vostok::math::mul4x3(rotation, (const vostok::math::float4x4 *)LODWORD(v9), &v31);
  x = v31.k.x;
  this->m_target_distance_to_focus_point = this->m_pitch;
  m_target_distance_to_focus_point = this->m_target_distance_to_focus_point;
  qmemcpy((void *)LODWORD(v9), &v31, 0x40u);
  z = this->m_target_point.z;
  v30[0] = LODWORD(x) ^ _mask__NegFloat_;
  v22 = m_target_distance_to_focus_point;
  v30[1] = LODWORD(v31.k.y) ^ _mask__NegFloat_;
  p_m_fov_factor = &this->m_fov_factor;
  v30[2] = LODWORD(v31.k.z) ^ _mask__NegFloat_;
  (*(void (__thiscall **)(float, vostok::math::float4x4 *, float *, _DWORD *, _DWORD, int, int, _DWORD, int))(*(_DWORD *)LODWORD(z) + 64))(
    COERCE_FLOAT(LODWORD(z)),
    &v33,
    &this->m_fov_factor,
    v30,
    LODWORD(v22),
    16,
    8,
    0,
    1);
  if ( LODWORD(v33.i.x) )
    this->m_target_distance_to_focus_point = fsqrt(
                                               (float)((float)((float)(v33.i.w - this->m_target_point.y)
                                                             * (float)(v33.i.w - this->m_target_point.y))
                                                     + (float)((float)(v33.i.z - this->m_target_point.x)
                                                             * (float)(v33.i.z - this->m_target_point.x)))
                                             + (float)((float)(v33.i.y - *p_m_fov_factor)
                                                     * (float)(v33.i.y - *p_m_fov_factor)));
  v18 = this->m_target_distance_to_focus_point;
  *(float *)&v19 = *p_m_fov_factor - (float)(this->m_target_distance_to_focus_point * v31.k.x);
  v20 = this->m_target_distance_to_focus_point * v31.k.z;
  v28 = this->m_target_point.x - (float)(this->m_target_distance_to_focus_point * v31.k.y);
  y = this->m_target_point.y;
  LODWORD(v27[1]) = v19;
  v29 = y - v20;
  *(_QWORD *)&v32.lines[3].x = __PAIR64__(LODWORD(v28), v19);
  v32.c.z = y - v20;
  qmemcpy(&this->m_view_matrix.lines[3].elements[3], &v32, 0x40u);
  v26 = v18;
  survarium::lobby_menu::on_camera_modified(
    0,
    (survarium::base_game_scene *)LODWORD(this->m_inverted_view_matrix.c.w),
    v26);
}
