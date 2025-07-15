void __thiscall survarium::victory_item_core::insert(
        survarium::victory_item_core *this,
        const vostok::math::float3 *position,
        const float orientation)
{
  survarium::usable_object::insert(
    (survarium::usable_object *)this,
    &this->survarium::usable_object,
    this->m_physics_world);
  ((void (__thiscall *)(survarium::victory_item_core *, const vostok::math::float3 *, _DWORD))this->set_transform)(
    this,
    position,
    LODWORD(orientation));
  this->m_collision_is_inserted = 1;
}
