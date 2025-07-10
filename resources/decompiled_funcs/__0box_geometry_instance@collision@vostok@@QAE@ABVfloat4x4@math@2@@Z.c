void __fastcall vostok::collision::box_geometry_instance::box_geometry_instance(
        int a1,
        const vostok::math::float4x4 *matrix,
        vostok::collision::box_geometry_instance *this)
{
  this->m_delete_by_collision_object = 1;
  this->__vftable = (vostok::collision::box_geometry_instance_vtbl *)&vostok::collision::box_geometry_instance::`vftable';
  qmemcpy((void *)&this->m_matrix, matrix, sizeof(this->m_matrix));
  invert_impl(
    matrix,
    (float)((float)((float)((float)(matrix->j.y * matrix->k.z) - (float)(matrix->j.z * matrix->k.y)) * matrix->i.x)
          - (float)((float)((float)(matrix->j.x * matrix->k.z) - (float)(matrix->k.x * matrix->j.z)) * matrix->i.y))
  + (float)((float)((float)(matrix->j.x * matrix->k.y) - (float)(matrix->k.x * matrix->j.y)) * matrix->i.z));
}
