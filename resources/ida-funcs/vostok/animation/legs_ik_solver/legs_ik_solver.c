void __usercall vostok::animation::legs_ik_solver::legs_ik_solver(
        vostok::animation::legs_ik_solver *this@<ecx>,
        int a2@<eax>)
{
  float v2; // xmm1_4
  unsigned int v3; // edx

  v2 = s_bm_current_air_resistance;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 4) = -1;
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 52) = 0;
  *(float *)(a2 + 44) = v2;
  *(_BYTE *)(a2 + 60) = 0;
  *(_BYTE *)(a2 + 61) = 0;
  *(_DWORD *)(a2 + 56) = -1;
  *(_DWORD *)(a2 + 84) = 0;
  *(_DWORD *)(a2 + 88) = 0;
  *(_DWORD *)(a2 + 96) = 0;
  *(_DWORD *)(a2 + 100) = 0;
  *(float *)(a2 + 92) = v2;
  *(_BYTE *)(a2 + 108) = 0;
  *(_BYTE *)(a2 + 109) = 0;
  *(_DWORD *)(a2 + 104) = -1;
  *(_DWORD *)(a2 + 112) = -1;
  *(_DWORD *)(a2 + 116) = -1;
  *(_DWORD *)(a2 + 124) = 100;
  *(_DWORD *)(a2 + 128) = 100;
  *(float *)(a2 + 136) = FLOAT_0_1;
  *(_DWORD *)(a2 + 132) = &vostok::animation::fermi_interpolator::`vftable';
  *(float *)(a2 + 140) = FLOAT_0_0049999999;
  v3 = *(_DWORD *)(a2 + 128);
  *(_DWORD *)(a2 + 144) = &vostok::animation::fermi_interpolator::`vftable';
  *(float *)(a2 + 152) = FLOAT_0_0049999999;
  *(float *)(a2 + 148) = (double)v3 * 0.001;
}
