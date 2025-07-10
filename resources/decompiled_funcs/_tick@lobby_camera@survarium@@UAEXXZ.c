void __thiscall survarium::lobby_camera::tick(survarium::lobby_camera *this)
{
  float v2; // xmm0_4
  int v3; // xmm1_4
  float m_yaw; // xmm1_4
  float v5; // xmm0_4
  vostok::math::float4x4 *v6; // eax
  double v7; // st7
  vostok::math::float4x4 *rotation_y; // eax
  const vostok::math::float4x4 *rotation; // eax
  vostok::math::float4_pod si128; // xmm0
  float v11; // xmm3_4
  float y; // xmm1_4
  vostok::math::float4x4 *result; // [esp+140h] [ebp-E4h]
  float resulta; // [esp+140h] [ebp-E4h]
  vostok::math::float3 direction; // [esp+158h] [ebp-CCh] BYREF
  vostok::math::float4x4 v16; // [esp+164h] [ebp-C0h] BYREF
  vostok::math::float4x4 left; // [esp+1A4h] [ebp-80h] BYREF
  _QWORD v18[8]; // [esp+1E4h] [ebp-40h] BYREF

  *(float *)&this->m_capture_move = this->m_z_mouse_axis + *(float *)&this->m_capture_move;
  this->m_yaw = this->m_rotation_delta.x + this->m_yaw;
  if ( COERCE_FLOAT(LODWORD(this->m_current_distance_to_focus_point) & 0x7FFFFFFF) >= 0.0000099999997 )
  {
    v2 = this->m_target_distance_to_focus_point + this->m_current_distance_to_focus_point;
    this->m_pitch = v2;
    *(float *)&v3 = 1.5;
    if ( v2 <= 1.5 || (*(float *)&v3 = 40.0, v2 > 40.0) )
      v2 = *(float *)&v3;
    this->m_pitch = v2;
  }
  m_yaw = this->m_yaw;
  v5 = -1.0471976;
  if ( m_yaw > -1.0471976 )
  {
    v5 = pi_d3;
    if ( m_yaw <= 1.0471976 )
      v5 = this->m_yaw;
  }
  this->m_yaw = v5;
  v6 = vostok::math::float4x4::identity(&v16);
  v7 = *(float *)&this->m_capture_move;
  qmemcpy((void *)&left, v6, sizeof(left));
  *(float *)&result = v7;
  rotation_y = vostok::math::create_rotation_y(v18, result);
  vostok::math::mul4x3(&v16, &left, rotation_y);
  resulta = this->m_yaw;
  left.i = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&v16);
  left.lines[1] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&v16.lines[1]);
  left.lines[2] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&v16.lines[2]);
  left.lines[3] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&v16.lines[3]);
  rotation = vostok::math::create_rotation((const vostok::math::float3 *)&left, resulta);
  vostok::math::mul4x3(&v16, &left, rotation);
  si128 = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&v16);
  this->m_target_distance_to_focus_point = this->m_pitch;
  left.i = si128;
  left.lines[1] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&v16.lines[1]);
  left.lines[2] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&v16.lines[2]);
  left.lines[3] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&v16.lines[3]);
  direction.x = -v16.k.x;
  LODWORD(direction.y) = LODWORD(v16.k.y) ^ 0x80000000;
  direction.z = -v16.k.z;
  survarium::lobby_camera::process_collision(
    (survarium::lobby_camera *)((char *)this - 4),
    (const vostok::math::float3 *)&this->m_fov_factor,
    &this->m_target_distance_to_focus_point,
    &direction);
  v11 = this->m_fov_factor - (float)(this->m_target_distance_to_focus_point * v16.k.x);
  si128.x = this->m_target_distance_to_focus_point * v16.k.z;
  direction.y = this->m_target_point.x - (float)(this->m_target_distance_to_focus_point * v16.k.y);
  y = this->m_target_point.y;
  direction.x = v11;
  *(_QWORD *)&left.lines[3].x = *(_QWORD *)&direction.x;
  left.c.z = y - si128.x;
  qmemcpy(&this->survarium::game_camera, &left, 0x40u);
}
