void __thiscall vostok::collision::sphere_geometry_instance::set_matrix(
        vostok::collision::sphere_geometry_instance *this,
        const vostok::math::float4x4 *matrix)
{
  qmemcpy(&this->m_matrix, matrix, sizeof(this->m_matrix));
}
