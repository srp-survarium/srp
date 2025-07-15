// local variable allocation has failed, the output may be wrong!
const struct vostok::math::float3 *__userpurge vostok::math::quaternion::quaternion@<eax>(
        vostok::math::quaternion *this@<ecx>,
        float *a2@<eax>,
        long double a3@<esi:edi>,
        float a4@<xmm0>,
        const struct vostok::math::float3 *thisa,
        float a6)
{
  __m128i v8; // xmm0
  float v11; // [esp+4h] [ebp-10h]
  float v12; // [esp+Ch] [ebp-8h]
  float v13; // [esp+1Ch] [ebp+8h]

  v13 = a4 * 0.5;
  *(double *)v8.m128i_i64 = (float)(a4 * 0.5);
  __libm_sse2_sin(v8);
  *(float *)v8.m128i_i32 = *(double *)v8.m128i_i64;
  v12 = *(float *)v8.m128i_i32;
  __libm_sse2_cos(a3);
  thisa[1].x = v13;
  v11 = a2[1] * *(float *)v8.m128i_i32;
  *(float *)v8.m128i_i32 = a2[2] * *(float *)v8.m128i_i32;
  thisa->x = *a2 * v12;
  thisa->y = v11;
  LODWORD(thisa->z) = v8.m128i_i32[0];
  return thisa;
}


void __thiscall vostok::math::quaternion::quaternion(
        vostok::math::quaternion *this,
        const vostok::math::float4x4 *matrix_raw)
{
  float v3; // xmm6_4
  float v4; // xmm3_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  int v9; // eax
  int v10; // eax
  float v11; // xmm5_4
  float v12; // xmm5_4
  float v13; // xmm5_4
  float v14; // xmm5_4
  float v15; // xmm2_4
  float v16; // xmm5_4
  float v17; // xmm5_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm5_4
  float v25; // xmm5_4
  float v26; // xmm1_4
  vostok::math::float4x4 v27; // [esp+0h] [ebp-4Ch] BYREF
  vostok::math::float3 scale; // [esp+40h] [ebp-Ch] BYREF

  qmemcpy(&v27, matrix_raw, sizeof(v27));
  scale.x = FLOAT_1_0;
  scale.y = FLOAT_1_0;
  scale.z = FLOAT_1_0;
  vostok::math::float4x4::set_scale(&v27, &scale);
  v3 = v27.k.z + v27.j.y;
  v4 = (float)((float)(v27.k.z + v27.j.y) + v27.i.x) + 1.0;
  if ( v4 > 0.001 )
  {
    v5 = fsqrt(v4);
    v6 = v5 * 0.5;
    v7 = 0.5 / v5;
    this->x = (float)(v27.k.y - v27.j.z) * (float)(0.5 / v5);
    this->y = (float)(v27.i.z - v27.k.x) * (float)(0.5 / v5);
    v8 = v27.j.x - v27.i.y;
    this->w = v6;
LABEL_31:
    this->z = v8 * v7;
    goto LABEL_40;
  }
  if ( v27.i.x > v27.j.y )
  {
    if ( v27.k.z <= v27.i.x )
    {
      v9 = 0;
      goto LABEL_9;
    }
    goto LABEL_7;
  }
  if ( v27.k.z > v27.i.x )
  {
LABEL_7:
    v9 = 2;
    goto LABEL_9;
  }
  v9 = 1;
LABEL_9:
  if ( !v9 )
  {
    v24 = (float)(v27.i.x - v3) + 1.0;
    if ( v24 > 0.0 )
    {
      v14 = fsqrt(v24);
      if ( v14 > 0.1 )
        goto LABEL_29;
    }
    v25 = (float)(v27.k.z - (float)(v27.j.y + v27.i.x)) + 1.0;
    if ( v25 <= 0.0 || (v12 = fsqrt(v25), v12 <= 0.1) )
    {
      v15 = (float)(v27.j.y - (float)(v27.k.z + v27.i.x)) + 1.0;
      if ( v15 <= 0.0 )
        goto LABEL_40;
      goto LABEL_37;
    }
    goto LABEL_34;
  }
  v10 = v9 - 1;
  if ( !v10 )
  {
    v16 = (float)(v27.j.y - (float)(v27.k.z + v27.i.x)) + 1.0;
    if ( v16 > 0.0 )
    {
      v17 = fsqrt(v16);
      if ( v17 > 0.1 )
      {
        this->y = v17 * 0.5;
        v18 = 0.5 / v17;
        goto LABEL_39;
      }
    }
    v19 = (float)(v27.k.z - (float)(v27.j.y + v27.i.x)) + 1.0;
    if ( v19 <= 0.0 || (v20 = fsqrt(v19), v20 <= 0.1) )
    {
      v22 = (float)(v27.i.x - v3) + 1.0;
      if ( v22 <= 0.0 )
        goto LABEL_40;
      v23 = fsqrt(v22);
      if ( v23 <= 0.1 )
        goto LABEL_40;
      this->x = v23 * 0.5;
      v7 = 0.5 / v23;
LABEL_30:
      this->w = (float)(v27.k.y - v27.j.z) * v7;
      this->y = (float)(v27.i.y + v27.j.x) * v7;
      v8 = v27.k.x + v27.i.z;
      goto LABEL_31;
    }
    this->z = v20 * 0.5;
    v21 = 0.5 / v20;
LABEL_35:
    this->w = (float)(v27.j.x - v27.i.y) * v21;
    this->x = (float)(v27.k.x + v27.i.z) * v21;
    this->y = (float)(v27.j.z + v27.k.y) * v21;
    goto LABEL_40;
  }
  if ( v10 != 1 )
    goto LABEL_40;
  v11 = (float)(v27.k.z - (float)(v27.j.y + v27.i.x)) + 1.0;
  if ( v11 > 0.0 )
  {
    v12 = fsqrt(v11);
    if ( v12 > 0.1 )
    {
LABEL_34:
      this->z = v12 * 0.5;
      v21 = 0.5 / v12;
      goto LABEL_35;
    }
  }
  v13 = (float)(v27.i.x - v3) + 1.0;
  if ( v13 > 0.0 )
  {
    v14 = fsqrt(v13);
    if ( v14 > 0.1 )
    {
LABEL_29:
      this->x = v14 * 0.5;
      v7 = 0.5 / v14;
      goto LABEL_30;
    }
  }
  v15 = (float)(v27.j.y - (float)(v27.k.z + v27.i.x)) + 1.0;
  if ( v15 > 0.0 )
  {
LABEL_37:
    v26 = fsqrt(v15);
    if ( v26 <= 0.1 )
      goto LABEL_40;
    v18 = 0.5 / v26;
    this->y = v26 * 0.5;
LABEL_39:
    this->w = (float)(v27.i.z - v27.k.x) * v18;
    this->z = (float)(v27.j.z + v27.k.y) * v18;
    this->x = (float)(v27.i.y + v27.j.x) * v18;
  }
LABEL_40:
  vostok::math::float4_pod::normalize((vostok::math::float4_pod *)this);
}


void __userpurge vostok::math::quaternion::quaternion(
        vostok::math::quaternion *this@<ecx>,
        float *a2@<esi>,
        vostok::math::float3 angles)
{
  __m128 x_low; // xmm1
  __m128i v4; // xmm0
  float v5; // xmm3_4
  long double v6; // [esp+0h] [ebp-20h]
  long double v7; // [esp+0h] [ebp-20h]
  long double v8; // [esp+0h] [ebp-20h]
  float v9; // [esp+10h] [ebp-10h]

  x_low = (__m128)LODWORD(angles.x);
  angles.y = angles.y * 0.5;
  x_low.m128_f32[0] = angles.x * 0.5;
  angles.z = angles.z * 0.5;
  v4 = (__m128i)_mm_cvtps_pd(x_low);
  __libm_sse2_sin(v4);
  *(float *)v4.m128i_i32 = *(double *)v4.m128i_i64;
  v9 = *(float *)v4.m128i_i32;
  __libm_sse2_cos(v6);
  *(double *)v4.m128i_i64 = angles.y;
  __libm_sse2_sin(v4);
  __libm_sse2_cos(v7);
  *(double *)v4.m128i_i64 = angles.z;
  __libm_sse2_sin(v4);
  __libm_sse2_cos(v8);
  v5 = angles.y * (float)(angles.x * 0.5);
  *a2 = COERCE_FLOAT(COERCE_UNSIGNED_INT(angles.z * (float)(angles.y * v9)) ^ _mask__NegFloat_) - (float)(angles.z * v5);
  a2[1] = (float)(angles.z * (float)(angles.y * v9)) - (float)(angles.z * v5);
  a2[2] = COERCE_FLOAT(COERCE_UNSIGNED_INT(angles.z * (float)((float)(angles.x * 0.5) * angles.y)) ^ _mask__NegFloat_)
        - (float)(angles.z * (float)(angles.y * v9));
  a2[3] = (float)(angles.z * (float)(angles.y * v9)) - (float)(angles.z * (float)((float)(angles.x * 0.5) * angles.y));
}
