vostok::math::float4x4 *__thiscall survarium::empty_hands::transform(
        survarium::empty_hands *this,
        vostok::math::float4x4 *result)
{
  vostok::math::float4x4 *v2; // eax

  v2 = result;
  qmemcpy((void *)result, &this->m_transform, sizeof(vostok::math::float4x4));
  return v2;
}
