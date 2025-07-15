void __usercall vostok::collision::sphere_geometry_instance::sphere_geometry_instance(
        vostok::collision::sphere_geometry_instance *this@<eax>,
        const vostok::math::float4x4 *matrix@<edx>)
{
  this->m_delete_by_collision_object = 1;
  this->__vftable = (vostok::collision::sphere_geometry_instance_vtbl *)&vostok::collision::sphere_geometry_instance::`vftable';
  qmemcpy((void *)&this->m_matrix, matrix, sizeof(this->m_matrix));
}
