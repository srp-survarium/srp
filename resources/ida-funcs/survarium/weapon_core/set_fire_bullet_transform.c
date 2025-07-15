void __thiscall survarium::weapon_core::set_fire_bullet_transform(
        survarium::weapon_core *this,
        const vostok::math::float4x4 *fire_bullet_transform)
{
  this->m_ready_for_fire = 1;
  qmemcpy((void *)&this->m_fire_bullet_transform, fire_bullet_transform, sizeof(this->m_fire_bullet_transform));
}
