void __thiscall vostok::particle::particle_domain_complex::set_defaults(
        vostok::particle::particle_domain_complex *this,
        int a2)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  vostok::math::float4x4 v4; // [esp+Ch] [ebp-40h] BYREF

  *(_DWORD *)(a2 + 128) = 0;
  *(_DWORD *)(a2 + 132) = 0;
  *(_DWORD *)(a2 + 136) = 0;
  v2 = s_bm_current_air_resistance;
  *(_DWORD *)(a2 + 140) = 0;
  *(_DWORD *)(a2 + 144) = 0;
  *(_DWORD *)(a2 + 148) = 0;
  *(float *)(a2 + 152) = v2;
  *(float *)(a2 + 156) = v2;
  *(_BYTE *)(a2 + 228) = 0;
  *(float *)(a2 + 160) = v2;
  qmemcpy((void *)a2, vostok::math::float4x4::identity(&this->m_transform, &v4), 0x40u);
  qmemcpy((void *)(a2 + 64), vostok::math::float4x4::identity(0, &v4), 0x40u);
  *(_DWORD *)(a2 + 164) = 0;
  *(_DWORD *)(a2 + 168) = 0;
  *(_DWORD *)(a2 + 172) = 0;
  v3 = s_bm_current_air_resistance;
  *(_DWORD *)(a2 + 176) = 0;
  *(_DWORD *)(a2 + 180) = 0;
  *(_DWORD *)(a2 + 184) = 0;
  *(_DWORD *)(a2 + 188) = 0;
  *(_DWORD *)(a2 + 192) = 0;
  *(_DWORD *)(a2 + 196) = 0;
  *(float *)(a2 + 200) = v3;
  *(float *)(a2 + 204) = v3;
  *(float *)(a2 + 208) = v3;
  *(float *)(a2 + 212) = v3;
  *(_DWORD *)(a2 + 216) = 0;
  *(float *)(a2 + 220) = v3;
  *(float *)(a2 + 224) = v3;
  *(_BYTE *)(a2 + 230) = 0;
}
