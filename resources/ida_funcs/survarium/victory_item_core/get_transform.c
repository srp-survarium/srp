vostok::math::float4x4 *__thiscall survarium::victory_item_core::get_transform(
        survarium::victory_item_core *this,
        vostok::math::float4x4 *result)
{
  qmemcpy((void *)result, &this->m_transform, sizeof(vostok::math::float4x4));
  return result;
}
