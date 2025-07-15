void __thiscall vostok::collision::box_geometry_instance::set_matrix(
        vostok::collision::box_geometry_instance *this,
        const vostok::math::float4x4 *matrix)
{
  vostok::math::float4x4 *v2; // eax
  int v3; // edx
  vostok::math::float4x4 v4; // [esp+8h] [ebp-40h] BYREF

  qmemcpy(&this->m_matrix, matrix, sizeof(this->m_matrix));
  v2 = vostok::math::invert4x3(matrix, &v4);
  qmemcpy((void *)(v3 + 72), v2, 0x40u);
}
