void __usercall vostok::physics::bt_rigid_body_construction_info::bt_rigid_body_construction_info(
        vostok::physics::bt_rigid_body_construction_info *this@<ecx>,
        int a2@<eax>)
{
  float v2; // xmm0_4

  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(float *)(a2 + 16) = c_anim_center;
  *(_DWORD *)(a2 + 20) = 0;
  *(float *)(a2 + 24) = FLOAT_0_80000001;
  v2 = s_bm_current_air_resistance;
  *(float *)(a2 + 36) = FLOAT_0_0049999999;
  *(float *)(a2 + 28) = v2;
  *(_BYTE *)(a2 + 32) = 0;
  *(float *)(a2 + 40) = FLOAT_0_0099999998;
  *(float *)(a2 + 44) = FLOAT_0_0099999998;
  *(float *)(a2 + 48) = FLOAT_0_0099999998;
  *(float *)(a2 + 52) = v2;
  *(float *)(a2 + 56) = v2;
  *(float *)(a2 + 60) = v2;
  *(float *)(a2 + 64) = v2;
  *(float *)(a2 + 68) = v2;
  *(float *)(a2 + 72) = v2;
  *(_BYTE *)(a2 + 76) = 0;
}
