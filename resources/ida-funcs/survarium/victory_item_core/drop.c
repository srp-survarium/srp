void __thiscall survarium::victory_item_core::drop(survarium::victory_item_core *this)
{
  const vostok::math::float4x4 *v2; // eax
  vostok::math::float4_pod *p_c; // ebp
  vostok::math::float4x4 *v4; // ecx
  vostok::math::float3 *angles; // eax
  vostok::math::float3 *v6; // [esp+4h] [ebp-24h]
  vostok::math::axis_rotation_order v7; // [esp+8h] [ebp-20h]
  survarium::victory_item_core_vtbl *v8; // [esp+18h] [ebp-10h]

  survarium::usable_object::insert(
    (survarium::usable_object *)this,
    &this->survarium::usable_object,
    this->m_physics_world);
  v2 = this->m_user->transform(&this->m_user->survarium::collision_user);
  v8 = this->survarium::carryable_object::survarium::interactive_object::__vftable;
  p_c = &v2->c;
  this->m_user->transform(&this->m_user->survarium::collision_user);
  angles = vostok::math::float4x4::get_angles(v4, v6, v7);
  ((void (__thiscall *)(survarium::victory_item_core *, _DWORD, _DWORD))v8->set_transform)(
    this,
    (const vostok::math::float3 *)p_c,
    angles->y);
  this->m_collision_is_inserted = 1;
}
