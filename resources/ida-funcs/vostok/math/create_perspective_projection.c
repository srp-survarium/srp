vostok::math *__usercall vostok::math::create_perspective_projection@<eax>(
        long double a1@<esi:edi>,
        float a2@<xmm0>,
        vostok::math *this,
        struct vostok::math::float4x4 *retstr,
        float near_plane,
        float far_plane)
{
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v9; // [esp+Ch] [ebp-8h]

  __libm_sse2_tan(a1);
  v6 = s_bm_current_air_resistance;
  v7 = s_bm_current_air_resistance / (float)(a2 * 0.5);
  *(float *)this = v7 / *(float *)&retstr;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((float *)this + 5) = v7;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  v9 = far_plane / (float)(far_plane - near_plane);
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((float *)this + 10) = v9;
  *((float *)this + 11) = v6;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = COERCE_UNSIGNED_INT(v9 * near_plane) ^ _mask__NegFloat_;
  *((_DWORD *)this + 15) = 0;
  return this;
}
