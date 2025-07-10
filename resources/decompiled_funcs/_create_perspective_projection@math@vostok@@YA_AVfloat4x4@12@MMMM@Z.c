struct vostok::math::float4x4 *__usercall vostok::math::create_perspective_projection@<eax>(
        int a1@<esi>,
        float a2@<xmm0>,
        vostok::math *this,
        struct vostok::math::float4x4 *__return_ptr retstr,
        float far_plane)
{
  long double v5; // st7
  struct vostok::math::float4x4 *result; // eax
  __int64 v7; // xmm3_8
  __int64 v8; // xmm0_8
  unsigned int v9; // [esp+4h] [ebp-10h]
  __int64 v10; // [esp+4h] [ebp-10h]
  __int64 v11; // [esp+Ch] [ebp-8h]

  v5 = 1.0 / tanf(a2 * 0.5);
  v11 = 0;
  result = (struct vostok::math::float4x4 *)a1;
  *(float *)&v9 = v5 / *(float *)&this;
  *(_QWORD *)a1 = v9;
  *((float *)&v10 + 1) = v5;
  *(_QWORD *)(a1 + 8) = v11;
  LODWORD(v10) = 0;
  v11 = 0;
  *(_QWORD *)(a1 + 16) = v10;
  *(_QWORD *)(a1 + 24) = v11;
  HIDWORD(v11) = clear_value;
  *(float *)&v11 = far_plane / (float)(far_plane - *(float *)&retstr);
  *(_QWORD *)(a1 + 32) = 0;
  v7 = v11;
  HIDWORD(v11) = 0;
  *(_QWORD *)(a1 + 48) = 0;
  *(float *)&v11 = -(float)((float)(far_plane / (float)(far_plane - *(float *)&retstr)) * *(float *)&retstr);
  v8 = v11;
  *(_QWORD *)(a1 + 40) = v7;
  *(_QWORD *)(a1 + 56) = v8;
  return result;
}
