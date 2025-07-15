void __usercall vostok::physics::old_bullet_character_controller::step_up(
        vostok::physics::old_bullet_character_controller *this@<eax>)
{
  float y; // xmm5_4
  float x; // xmm0_4
  float v3; // xmm1_4
  int v4; // edx
  float *v5; // eax
  float v6; // [esp+0h] [ebp-8h] BYREF
  float v7; // [esp+4h] [ebp-4h]

  y = this->m_current_shape_dim.y;
  x = this->m_current_shape_dim.x;
  v3 = (float)(y - x) - s_step_height;
  if ( v3 < 0.0 )
    v3 = 0.0;
  v6 = this->m_current_shape_dim.x;
  v7 = x + v3;
  vostok::physics::old_bullet_character_controller::setup_shape_dim(
    (vostok::physics::old_bullet_character_controller *)&v6,
    (int)this);
  *(float *)(v4 + 4) = (float)(y - v7) * 0.5;
  *(_DWORD *)(v4 + 8) = 0;
  *(_DWORD *)v4 = 0;
  *(_DWORD *)(v4 + 12) = 0;
  v5[20] = v5[20];
  v5[21] = *(float *)(v4 + 4) + v5[21];
  v5[22] = v5[22] + *(float *)(v4 + 8);
  v5[24] = *(float *)(v4 + 4);
}
