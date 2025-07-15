void __thiscall survarium::weapon_core::set_transform(
        survarium::weapon_core *this,
        const vostok::math::float4x4 *transform)
{
  qmemcpy(&this->m_transform, transform, sizeof(this->m_transform));
}
