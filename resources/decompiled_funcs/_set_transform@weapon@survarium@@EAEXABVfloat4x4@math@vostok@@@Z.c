void __thiscall survarium::weapon::set_transform(survarium::weapon *this, const vostok::math::float4x4 *transform)
{
  qmemcpy(
    (void *)&this->survarium::weapon_core::m_transform,
    transform,
    sizeof(this->survarium::weapon_core::m_transform));
}
