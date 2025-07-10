vostok::math::float3 *__thiscall vostok::collision::sphere_geometry_instance::get_random_surface_point(
        vostok::collision::sphere_geometry_instance *this,
        vostok::math::float3 *result,
        vostok::math::random32 *randomizer)
{
  long double v4; // st7
  unsigned int v5; // ecx
  unsigned int v6; // eax
  long double v7; // st7
  float _X; // [esp+0h] [ebp-14h]
  float r_coefficient; // [esp+Ch] [ebp-8h]
  float z_random; // [esp+10h] [ebp-4h]
  float z_randoma; // [esp+10h] [ebp-4h]
  float teta_angle; // [esp+1Ch] [ebp+8h]

  z_random = sqrtf(
               (float)((float)(this->m_matrix.i.y * this->m_matrix.i.y)
                     + (float)(this->m_matrix.i.z * this->m_matrix.i.z))
             + (float)(this->m_matrix.i.x * this->m_matrix.i.x));
  v4 = sqrtf(
         (float)((float)(this->m_matrix.i.y * this->m_matrix.i.y) + (float)(this->m_matrix.i.z * this->m_matrix.i.z))
       + (float)(this->m_matrix.i.x * this->m_matrix.i.x));
  v5 = 134775813 * randomizer->m_seed + 1;
  v6 = 134775813 * v5 + 1;
  randomizer->m_seed = v6;
  z_randoma = v4 * ((double)((unsigned __int64)v5 >> 12) * 0.00000095367432)
            + v4 * ((double)((unsigned __int64)v5 >> 12) * 0.00000095367432)
            - z_random;
  teta_angle = 0.00000095367432 * (double)((unsigned __int64)v6 >> 12) * 6.2831855;
  v7 = sqrtf(
         (float)((float)(this->m_matrix.i.z * this->m_matrix.i.z) + (float)(this->m_matrix.i.x * this->m_matrix.i.x))
       + (float)(this->m_matrix.i.y * this->m_matrix.i.y));
  _X = v7 * v7 - z_randoma * z_randoma;
  r_coefficient = sqrtf(_X);
  result->x = cosf(teta_angle) * r_coefficient;
  result->y = sinf(teta_angle) * r_coefficient;
  result->z = z_randoma;
  return result;
}
