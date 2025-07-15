void __usercall survarium::base_player_creation_params::base_player_creation_params(
        survarium::base_player_creation_params *this@<ecx>,
        int a2@<edi>,
        const float *a3@<esi>)
{
  unsigned int v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  const float *v7; // [esp-8h] [ebp-10h]
  unsigned int size; // [esp+4h] [ebp-4h] BYREF

  v3 = LODWORD(s_bm_current_air_resistance);
  *(_DWORD *)a2 = a2 + 12;
  *(_DWORD *)(a2 + 4) = a2 + 12;
  *(_DWORD *)(a2 + 8) = a2 + 64;
  *(_DWORD *)(a2 + 64) = a2 + 76;
  *(_DWORD *)(a2 + 68) = a2 + 76;
  *(_DWORD *)(a2 + 72) = a2 + 112;
  size = v3;
  vostok::buffer_vector<float>::resize((vostok::buffer_vector<float> *)0xD, (int *)a2, (float *)&size, a3);
  size = LODWORD(s_bm_current_air_resistance);
  vostok::buffer_vector<float>::resize((vostok::buffer_vector<float> *)9, (int *)(a2 + 64), (float *)&size, v7);
  v4 = s_bm_current_air_resistance;
  *(_BYTE *)(a2 + 124) = -1;
  *(_DWORD *)(a2 + 120) = 0;
  *(_DWORD *)(a2 + 128) = 0;
  *(_BYTE *)(a2 + 136) = 0;
  *(float *)(a2 + 140) = v4;
  *(float *)(a2 + 144) = v4;
  *(float *)(a2 + 148) = v4;
  *(float *)(a2 + 152) = v4;
  *(_DWORD *)(a2 + 156) = 0;
  *(_DWORD *)(a2 + 160) = 0;
  *(_DWORD *)(a2 + 164) = 0;
  *(_DWORD *)(a2 + 168) = 0;
  *(_DWORD *)(a2 + 172) = 0;
  *(_DWORD *)(a2 + 176) = 0;
  *(_DWORD *)(a2 + 180) = 0;
  *(_DWORD *)(a2 + 184) = 0;
  *(_DWORD *)(a2 + 188) = 0;
  *(_DWORD *)(a2 + 192) = 0;
  *(_DWORD *)(a2 + 196) = 0;
  *(_DWORD *)(a2 + 200) = 0;
  *(_DWORD *)(a2 + 204) = 0;
  *(float *)(a2 + 208) = v4;
  *(float *)(a2 + 212) = v4;
  *(float *)(a2 + 216) = v4;
  *(float *)(a2 + 220) = v4;
  *(float *)(a2 + 224) = v4;
  *(float *)(a2 + 228) = v4;
  *(float *)(a2 + 232) = v4;
  *(float *)(a2 + 236) = v4;
  *(float *)(a2 + 240) = v4;
  *(float *)(a2 + 244) = v4;
  *(float *)(a2 + 248) = v4;
  *(float *)(a2 + 252) = v4;
  *(float *)(a2 + 256) = v4;
  *(float *)(a2 + 260) = v4;
  *(float *)(a2 + 264) = v4;
  *(float *)(a2 + 268) = FLOAT_5_0;
  *(float *)(a2 + 272) = c_anim_center;
  v5 = vostok::sound::s_lpf_param;
  *(float *)(a2 + 276) = vostok::sound::s_lpf_param;
  *(float *)(a2 + 288) = v5;
  *(float *)(a2 + 280) = FLOAT_0_15000001;
  *(float *)(a2 + 284) = v4;
  *(float *)(a2 + 300) = v4;
  v6 = SNaN;
  *(float *)(a2 + 292) = FLOAT_0_2;
  *(float *)(a2 + 296) = FLOAT_0_15000001;
  *(float *)(a2 + 428) = v6;
  *(float *)(a2 + 432) = v6;
  *(_DWORD *)(a2 + 388) = 0;
  *(_DWORD *)(a2 + 392) = 0;
  *(_DWORD *)(a2 + 396) = 0;
  *(float *)(a2 + 436) = v6;
  *(float *)(a2 + 440) = v6;
  *(_DWORD *)(a2 + 424) = 0;
}
