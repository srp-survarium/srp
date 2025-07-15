void __thiscall survarium::victory_item_core::put(
        survarium::victory_item_core *this,
        vostok::physics::world *world,
        const vostok::math::float4x4 *transform)
{
  survarium::usable_object::insert(this, world);
  this->set_transform(this, transform);
  this->m_is_inserted = 1;
}
