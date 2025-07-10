struct vostok::math::float4x4 *__usercall vostok::math::create_orthographic_projection@<eax>(
        struct vostok::math::float4x4 *result@<eax>,
        float a2@<xmm0>,
        float a3@<xmm3>,
        vostok::math *this,
        struct vostok::math::float4x4 *__return_ptr retstr)
{
  const vostok::math::float4x4 *v5; // xmm4_4
  float v6; // xmm1_4
  __int64 v7; // xmm5_8
  __int64 v8; // xmm2_8
  __int64 v9; // xmm2_8
  __int64 v10; // xmm0_8
  __int64 v11; // [esp+0h] [ebp-14h]
  float v12[3]; // [esp+8h] [ebp-Ch]

  v5 = clear_value;
  v6 = *(float *)&clear_value / (float)(a2 - a3);
  *(_QWORD *)v12 = 0;
  *((float *)&v11 + 1) = 2.0 / *(float *)&retstr;
  LODWORD(v11) = 0;
  *(_QWORD *)&result->i.x = COERCE_UNSIGNED_INT(2.0 / *(float *)&this);
  v7 = *(_QWORD *)v12;
  *(_QWORD *)v12 = 0;
  *(_QWORD *)&result->lines[1].x = v11;
  v8 = *(_QWORD *)v12;
  v12[0] = v6;
  *(_QWORD *)&result->lines[1].elements[2] = v8;
  v12[1] = 0.0;
  *(_QWORD *)&result->lines[2].x = 0;
  v9 = *(_QWORD *)v12;
  *(_QWORD *)&result->lines[3].x = 0;
  v12[0] = -(float)(v6 * a3);
  LODWORD(v12[1]) = v5;
  v10 = *(_QWORD *)v12;
  *(_QWORD *)&result->lines[0].elements[2] = v7;
  *(_QWORD *)&result->lines[2].elements[2] = v9;
  *(_QWORD *)&result->lines[3].elements[2] = v10;
  return result;
}
