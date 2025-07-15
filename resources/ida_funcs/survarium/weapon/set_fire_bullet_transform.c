void __thiscall survarium::weapon::set_fire_bullet_transform(
        survarium::weapon *this,
        const vostok::math::float4x4 *transform)
{
  vostok::math::float4x4 *p_m_barrel_transform; // eax

  p_m_barrel_transform = &this->m_barrel_transform;
  if ( !this->m_is_third_view )
    p_m_barrel_transform = transform;
  survarium::weapon_core::set_fire_bullet_transform(this, p_m_barrel_transform);
}
