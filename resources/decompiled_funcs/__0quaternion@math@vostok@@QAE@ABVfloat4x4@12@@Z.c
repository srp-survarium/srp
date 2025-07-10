void __userpurge vostok::math::quaternion::quaternion(
        const vostok::math::float4x4 *matrix_raw@<eax>,
        vostok::math::quaternion *this)
{
  float z; // xmm0_4
  float y; // xmm2_4
  float x; // xmm1_4
  const vostok::math::float4x4 *v6; // xmm3_4
  float v7; // xmm4_4
  long double v8; // st7
  float v9; // xmm1_4
  int v10; // eax
  int v11; // eax
  float _X; // xmm0_4
  long double v13; // st7
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  long double v17; // st7
  float v18; // xmm2_4
  float v19; // xmm0_4
  long double v20; // st7
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // [esp+14h] [ebp-50h]
  float v28; // [esp+14h] [ebp-50h]
  vostok::math::float3 scale; // [esp+18h] [ebp-4Ch] BYREF
  vostok::math::float4x4 matrix; // [esp+24h] [ebp-40h] BYREF
  float sd; // [esp+68h] [ebp+4h]
  float s; // [esp+68h] [ebp+4h]
  float sa; // [esp+68h] [ebp+4h]
  float sb; // [esp+68h] [ebp+4h]
  float sc; // [esp+68h] [ebp+4h]
  float se; // [esp+68h] [ebp+4h]

  qmemcpy((void *)&matrix, matrix_raw, sizeof(matrix));
  LODWORD(scale.x) = clear_value;
  LODWORD(scale.y) = clear_value;
  LODWORD(scale.z) = clear_value;
  vostok::math::float4x4::set_scale(&matrix, &scale);
  z = matrix.k.z;
  y = matrix.j.y;
  x = matrix.i.x;
  v6 = clear_value;
  v7 = matrix.k.z + matrix.j.y;
  v27 = matrix.k.z + matrix.j.y;
  if ( (float)((float)((float)(matrix.k.z + matrix.j.y) + matrix.i.x) + *(float *)&clear_value) > 0.001 )
  {
    v8 = sqrtf((float)((float)(matrix.k.z + matrix.j.y) + matrix.i.x) + *(float *)&clear_value);
    sd = v8;
    v9 = (float)(matrix.k.y - matrix.j.z) * (float)(0.5 / sd);
    this->w = v8 * 0.5;
    this->x = v9;
    this->y = (float)(matrix.i.z - matrix.k.x) * (float)(0.5 / sd);
    this->z = (float)(matrix.j.x - matrix.i.y) * (float)(0.5 / sd);
    return;
  }
  if ( matrix.i.x <= matrix.j.y )
  {
    v10 = 2;
    if ( matrix.k.z <= matrix.i.x )
      v10 = 1;
  }
  else if ( matrix.k.z <= matrix.i.x )
  {
    v10 = 0;
  }
  else
  {
    v10 = 2;
  }
  if ( !v10 )
  {
    sb = (float)(matrix.i.x - v7) + *(float *)&clear_value;
    if ( sb > 0.0 )
    {
      v20 = sqrtf(sb);
      sc = v20;
      if ( v20 > 0.1 )
      {
        this->w = (float)(matrix.k.y - matrix.j.z) * (float)(0.5 / sc);
        this->y = (float)(matrix.i.y + matrix.j.x) * (float)(0.5 / sc);
        v21 = (float)(matrix.k.x + matrix.i.z) * (float)(0.5 / sc);
        this->x = sc * 0.5;
        this->z = v21;
        goto LABEL_34;
      }
      x = matrix.i.x;
      y = matrix.j.y;
      z = matrix.k.z;
      v6 = clear_value;
    }
    v19 = (float)(z - (float)(y + x)) + *(float *)&v6;
    sqrt_safe(v19);
    if ( v19 <= 0.1 )
    {
LABEL_31:
      v24 = (float)(matrix.j.y - (float)(matrix.k.z + matrix.i.x)) + *(float *)&clear_value;
      sqrt_safe(v24);
      if ( v24 <= 0.1 )
        goto LABEL_34;
      v18 = v24 * 0.5;
      this->w = (float)(matrix.i.z - matrix.k.x) * (float)(0.5 / v24);
      this->z = (float)(matrix.j.z + matrix.k.y) * (float)(0.5 / v24);
      this->x = (float)(matrix.i.y + matrix.j.x) * (float)(0.5 / v24);
LABEL_33:
      this->y = v18;
      goto LABEL_34;
    }
LABEL_30:
    v22 = v19 * 0.5;
    this->w = (float)(matrix.j.x - matrix.i.y) * (float)(0.5 / v19);
    this->x = (float)(matrix.k.x + matrix.i.z) * (float)(0.5 / v19);
    v23 = (float)(matrix.j.z + matrix.k.y) * (float)(0.5 / v19);
    this->z = v22;
    this->y = v23;
    goto LABEL_34;
  }
  v11 = v10 - 1;
  if ( !v11 )
  {
    if ( (float)((float)(matrix.j.y - (float)(matrix.k.z + matrix.i.x)) + *(float *)&clear_value) > 0.0 )
    {
      v17 = sqrtf((float)(matrix.j.y - (float)(matrix.k.z + matrix.i.x)) + *(float *)&clear_value);
      sa = v17;
      if ( v17 > 0.1 )
      {
        v18 = sa * 0.5;
        this->w = (float)(matrix.i.z - matrix.k.x) * (float)(0.5 / sa);
        this->z = (float)(matrix.j.z + matrix.k.y) * (float)(0.5 / sa);
        this->x = (float)(matrix.i.y + matrix.j.x) * (float)(0.5 / sa);
        goto LABEL_33;
      }
      x = matrix.i.x;
      y = matrix.j.y;
      z = matrix.k.z;
      v6 = clear_value;
    }
    v19 = (float)(z - (float)(y + x)) + *(float *)&v6;
    sqrt_safe(v19);
    if ( v19 <= 0.1 )
    {
      _X = (float)(matrix.i.x - v27) + *(float *)&clear_value;
      sqrt_safe(_X);
      if ( _X <= 0.1 )
        goto LABEL_34;
      goto LABEL_17;
    }
    goto LABEL_30;
  }
  if ( v11 == 1 )
  {
    _X = (float)(matrix.k.z - (float)(matrix.j.y + matrix.i.x)) + *(float *)&clear_value;
    if ( _X > 0.0 )
    {
      v13 = sqrtf(_X);
      s = v13;
      if ( v13 > 0.1 )
      {
        this->w = (float)(matrix.j.x - matrix.i.y) * (float)(0.5 / s);
        this->x = (float)(matrix.k.x + matrix.i.z) * (float)(0.5 / s);
        v14 = (float)(matrix.j.z + matrix.k.y) * (float)(0.5 / s);
        this->z = s * 0.5;
        this->y = v14;
        goto LABEL_34;
      }
      x = matrix.i.x;
      v7 = v27;
      v6 = clear_value;
    }
    sqrt_safe((float)(x - v7) + *(float *)&v6);
    if ( _X > 0.1 )
    {
LABEL_17:
      v15 = _X * 0.5;
      this->w = (float)(matrix.k.y - matrix.j.z) * (float)(0.5 / _X);
      this->y = (float)(matrix.i.y + matrix.j.x) * (float)(0.5 / _X);
      v16 = (float)(matrix.k.x + matrix.i.z) * (float)(0.5 / _X);
      this->x = v15;
      this->z = v16;
      goto LABEL_34;
    }
    goto LABEL_31;
  }
LABEL_34:
  v28 = this->x;
  se = sqrtf(
         (float)((float)((float)(this->y * this->y) + (float)(this->z * this->z)) + (float)(this->x * this->x))
       + (float)(this->w * this->w));
  v25 = *(float *)&clear_value / se;
  this->x = (float)(*(float *)&clear_value / se) * v28;
  this->y = this->y * v25;
  v26 = v25 * this->z;
  this->w = v25 * this->w;
  this->z = v26;
}
