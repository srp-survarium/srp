void __thiscall vostok::collision::box_geometry_instance::set_matrix(
        vostok::collision::box_geometry_instance *this,
        const vostok::math::float4x4 *matrix)
{
  vostok::math::float4x4 *v2; // eax
  int v3; // edx

  qmemcpy((void *)&this->m_matrix, matrix, sizeof(this->m_matrix));
  v2 = invert_impl(
         matrix,
         (float)((float)((float)((float)(matrix->j.y * matrix->k.z) - (float)(matrix->j.z * matrix->k.y)) * matrix->i.x)
               - (float)((float)((float)(matrix->j.x * matrix->k.z) - (float)(matrix->k.x * matrix->j.z)) * matrix->i.y))
       + (float)((float)((float)(matrix->j.x * matrix->k.y) - (float)(matrix->k.x * matrix->j.y)) * matrix->i.z));
  qmemcpy((void *)(v3 + 72), v2, 0x40u);
}
