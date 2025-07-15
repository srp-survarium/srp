void __thiscall vostok::collision::capsule_geometry_instance::set_matrix(
        vostok::collision::capsule_geometry_instance *this,
        const vostok::math::float4x4 *matrix)
{
  long double v3; // st7
  const vostok::math::float4x4 *v4; // xmm0_4
  vostok::math::float3 scale; // [esp+18h] [ebp-4Ch] BYREF

  v3 = sqrtf(
         (float)((float)(matrix->j.y * matrix->j.y) + (float)(matrix->j.z * matrix->j.z))
       + (float)(matrix->j.x * matrix->j.x));
  v4 = clear_value;
  this->m_half_length = v3 * this->m_true_half_length;
  qmemcpy((void *)&this->m_matrix, matrix, sizeof(this->m_matrix));
  LODWORD(scale.x) = v4;
  LODWORD(scale.y) = v4;
  LODWORD(scale.z) = v4;
  vostok::math::float4x4::set_scale(&this->m_matrix, &scale);
  qmemcpy(
    (void *)&this->m_inverted_matrix,
    invert_impl(
      matrix,
      (float)((float)((float)((float)(matrix->j.y * matrix->k.z) - (float)(matrix->j.z * matrix->k.y)) * matrix->i.x)
            - (float)((float)((float)(matrix->j.x * matrix->k.z) - (float)(matrix->k.x * matrix->j.z)) * matrix->i.y))
    + (float)((float)((float)(matrix->j.x * matrix->k.y) - (float)(matrix->k.x * matrix->j.y)) * matrix->i.z)),
    sizeof(this->m_inverted_matrix));
}
