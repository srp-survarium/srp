vostok::math::float3 *__thiscall vostok::collision::cylinder_geometry_instance::get_random_surface_point(
        vostok::collision::cylinder_geometry_instance *this,
        vostok::math::float3 *result,
        vostok::math::random32 *randomizer)
{
  float v4; // xmm0_4
  long double v5; // st7
  unsigned int m_seed; // ebx
  unsigned int v7; // ebx
  vostok::fixed_vector<float,6>::allign_helper *m_buffer; // ecx
  int v9; // edx
  int v10; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  int v13; // ecx
  long double v14; // st7
  double v15; // st7
  float v16; // xmm1_4
  float y; // xmm0_4
  float z; // xmm3_4
  long double v19; // st7
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  long double v23; // st7
  vostok::math::float3 *v24; // eax
  long double v25; // st7
  float v26; // xmm3_4
  float v27; // xmm2_4
  long double v28; // st7
  int v29; // ebx
  long double v30; // st7
  long double v31; // st7
  float _Xa; // [esp+0h] [ebp-44h]
  float _X; // [esp+0h] [ebp-44h]
  float _Xb; // [esp+0h] [ebp-44h]
  float alphaa; // [esp+10h] [ebp-34h]
  float alpha; // [esp+10h] [ebp-34h]
  float r_coefficient; // [esp+14h] [ebp-30h]
  float r_coefficienta; // [esp+14h] [ebp-30h]
  float r_coefficientb; // [esp+14h] [ebp-30h]
  float r_coefficientc; // [esp+14h] [ebp-30h]
  float x; // [esp+18h] [ebp-2Ch]
  float area2; // [esp+1Ch] [ebp-28h]
  float area2a; // [esp+1Ch] [ebp-28h]
  float radius_randoma; // [esp+20h] [ebp-24h]
  float radius_random; // [esp+20h] [ebp-24h]
  float radius_randomb; // [esp+20h] [ebp-24h]
  float radius_randomc; // [esp+20h] [ebp-24h]
  float radius_randomd; // [esp+20h] [ebp-24h]
  float radius_randome; // [esp+20h] [ebp-24h]
  float radius_randomf; // [esp+20h] [ebp-24h]
  vostok::fixed_vector<float,6> cylinder_planes; // [esp+24h] [ebp-20h] BYREF

  r_coefficient = sqrtf(
                    (float)((float)(this->m_matrix.i.y * this->m_matrix.i.y)
                          + (float)(this->m_matrix.i.z * this->m_matrix.i.z))
                  + (float)(this->m_matrix.i.x * this->m_matrix.i.x));
  v4 = r_coefficient;
  x = this->m_matrix.j.x;
  alphaa = this->m_matrix.j.z;
  r_coefficienta = this->m_matrix.j.y;
  area2 = sqrtf(
            (float)((float)(this->m_matrix.i.y * this->m_matrix.i.y) + (float)(this->m_matrix.i.z * this->m_matrix.i.z))
          + (float)(this->m_matrix.i.x * this->m_matrix.i.x));
  v5 = sqrtf((float)((float)(r_coefficienta * r_coefficienta) + (float)(alphaa * alphaa)) + (float)(x * x));
  m_seed = randomizer->m_seed;
  area2a = v5 * area2 * 6.2831855;
  *(float *)cylinder_planes.m_buffer = (float)(v4 * v4) * 3.1415927;
  *(float *)&cylinder_planes.m_buffer[1] = *(float *)cylinder_planes.m_buffer * 2.0;
  v7 = 134775813 * m_seed + 1;
  radius_randoma = (float)(*(float *)cylinder_planes.m_buffer * 2.0) + area2a;
  *(float *)&cylinder_planes.m_buffer[2] = radius_randoma;
  cylinder_planes.m_end = (float *)&cylinder_planes.m_buffer[3];
  randomizer->m_seed = v7;
  m_buffer = cylinder_planes.m_buffer;
  v9 = 3;
  radius_random = (double)((unsigned __int64)v7 >> 12) * 0.00000095367432 * radius_randoma;
  do
  {
    v10 = v9 >> 1;
    if ( radius_random <= *(float *)&m_buffer[v9 >> 1] )
    {
      v9 >>= 1;
    }
    else
    {
      m_buffer += v10 + 1;
      v9 += -1 - v10;
    }
  }
  while ( v9 > 0 );
  if ( m_buffer == cylinder_planes.m_buffer )
    v11 = 0.0;
  else
    v11 = *(float *)&m_buffer[-1];
  v12 = *(float *)m_buffer - v11;
  v13 = m_buffer - cylinder_planes.m_buffer;
  alpha = 6.2831855 - (float)((float)((float)(radius_random - v11) / v12) * 6.2831855);
  if ( v13 < 0 )
    return result;
  if ( v13 > 1 )
  {
    if ( v13 == 2 )
    {
      radius_randomb = sqrtf(
                         (float)((float)(this->m_matrix.j.y * this->m_matrix.j.y)
                               + (float)(this->m_matrix.j.z * this->m_matrix.j.z))
                       + (float)(this->m_matrix.j.x * this->m_matrix.j.x));
      v14 = sqrtf(
              (float)((float)(this->m_matrix.j.z * this->m_matrix.j.z) + (float)(this->m_matrix.j.x * this->m_matrix.j.x))
            + (float)(this->m_matrix.j.y * this->m_matrix.j.y));
      _Xa = v14 + v14;
      v15 = vostok::math::random32::random_f(randomizer, _Xa);
      v16 = this->m_matrix.i.x;
      y = this->m_matrix.i.y;
      z = this->m_matrix.i.z;
      result->y = v15 - radius_randomb;
      radius_randomc = sqrtf((float)((float)(z * z) + (float)(v16 * v16)) + (float)(y * y));
      v19 = cosf(alpha);
      v20 = this->m_matrix.i.x;
      v21 = this->m_matrix.i.y;
      v22 = this->m_matrix.i.z;
      result->x = v19 * radius_randomc;
      radius_randomd = sqrtf((float)((float)(v22 * v22) + (float)(v20 * v20)) + (float)(v21 * v21));
      v23 = sinf(alpha);
      v24 = result;
      result->z = v23 * radius_randomd;
      return v24;
    }
    return result;
  }
  _X = (float)((float)(this->m_matrix.j.y * this->m_matrix.j.y) + (float)(this->m_matrix.j.z * this->m_matrix.j.z))
     + (float)(this->m_matrix.j.x * this->m_matrix.j.x);
  if ( v13 )
    v25 = -sqrtf(_X);
  else
    v25 = sqrtf(_X);
  r_coefficientb = v25;
  v26 = this->m_matrix.i.z * this->m_matrix.i.z;
  v27 = this->m_matrix.i.x * this->m_matrix.i.x;
  result->y = r_coefficientb;
  radius_randome = sqrtf((float)(v26 + v27) + (float)(this->m_matrix.i.y * this->m_matrix.i.y));
  v28 = sqrtf(
          (float)((float)(this->m_matrix.i.z * this->m_matrix.i.z) + (float)(this->m_matrix.i.x * this->m_matrix.i.x))
        + (float)(this->m_matrix.i.y * this->m_matrix.i.y));
  v29 = 134775813 * v7;
  randomizer->m_seed = v29 + 1;
  radius_randomf = v28 * ((double)((unsigned __int64)(unsigned int)(v29 + 1) >> 12) * 0.00000095367432)
                 + v28 * ((double)((unsigned __int64)(unsigned int)(v29 + 1) >> 12) * 0.00000095367432)
                 - radius_randome;
  v30 = sqrtf(
          (float)((float)(this->m_matrix.i.z * this->m_matrix.i.z) + (float)(this->m_matrix.i.x * this->m_matrix.i.x))
        + (float)(this->m_matrix.i.y * this->m_matrix.i.y));
  _Xb = v30 * v30 - radius_randomf * radius_randomf;
  r_coefficientc = sqrtf(_Xb);
  result->x = cosf(alpha) * r_coefficientc;
  v31 = sinf(alpha);
  v24 = result;
  result->z = v31 * r_coefficientc;
  return v24;
}
