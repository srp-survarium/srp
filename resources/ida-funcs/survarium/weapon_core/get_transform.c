vostok::math::float4x4 *__thiscall survarium::weapon_core::get_transform(
        survarium::weapon_core *this,
        vostok::math::float4x4 *result)
{
  vostok::math::float4x4 *v2; // eax

  v2 = result;
  qmemcpy(result, &this->m_transform, sizeof(vostok::math::float4x4));
  return v2;
}
