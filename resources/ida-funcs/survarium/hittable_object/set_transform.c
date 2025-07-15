void __thiscall survarium::hittable_object::set_transform(
        survarium::hittable_object *this,
        const vostok::math::float4x4 *transform)
{
  this->m_rigid_body->set_transform(this->m_rigid_body, transform);
}
