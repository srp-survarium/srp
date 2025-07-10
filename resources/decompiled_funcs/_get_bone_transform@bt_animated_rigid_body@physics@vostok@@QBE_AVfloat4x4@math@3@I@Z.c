vostok::math::float4x4 *__userpurge vostok::physics::bt_animated_rigid_body::get_bone_transform@<eax>(
        vostok::physics::bt_animated_rigid_body *this@<ecx>,
        const unsigned int index@<eax>,
        vostok::math::float4x4 *a3)
{
  vostok::physics::from_bullet(&this->m_shape->m_children.m_data[index].m_transform, (btMatrix3x3 *)this, a3);
  return a3;
}
