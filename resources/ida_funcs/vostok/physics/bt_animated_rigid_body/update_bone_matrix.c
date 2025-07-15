void __userpurge vostok::physics::bt_animated_rigid_body::update_bone_matrix(
        const vostok::math::float4x4 *new_transform@<esi>,
        vostok::physics::bt_animated_rigid_body *this,
        unsigned int index,
        bool recalculate_aabb)
{
  btTransform newChildTransform; // [esp+50h] [ebp-40h] BYREF

  vostok::physics::from_vostok(new_transform, (vostok::math::quaternion *)&newChildTransform);
  btCompoundShape::updateChildTransform(this->m_shape, index, &newChildTransform, recalculate_aabb);
}
