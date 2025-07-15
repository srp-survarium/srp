int __usercall vostok::math::create_orthographic_projection@<eax>(
        int result@<eax>,
        float a2@<xmm0>,
        vostok::math *this,
        struct vostok::math::float4x4 *retstr,
        float near_plane)
{
  float v5; // xmm3_4
  float v6; // xmm1_4

  v5 = s_bm_current_air_resistance;
  v6 = s_bm_current_air_resistance / (float)(a2 - near_plane);
  *(float *)result = 2.0 / *(float *)&this;
  *(_DWORD *)(result + 4) = 0;
  *(_DWORD *)(result + 8) = 0;
  *(_DWORD *)(result + 12) = 0;
  *(_DWORD *)(result + 16) = 0;
  *(float *)(result + 20) = 2.0 / *(float *)&retstr;
  *(_DWORD *)(result + 24) = 0;
  *(_DWORD *)(result + 28) = 0;
  *(_DWORD *)(result + 32) = 0;
  *(_DWORD *)(result + 36) = 0;
  *(float *)(result + 40) = v6;
  *(_DWORD *)(result + 44) = 0;
  *(_DWORD *)(result + 48) = 0;
  *(_DWORD *)(result + 52) = 0;
  *(_DWORD *)(result + 56) = COERCE_UNSIGNED_INT(v6 * near_plane) ^ _mask__NegFloat_;
  *(float *)(result + 60) = v5;
  return result;
}
