vostok::math::float4x4 *__thiscall survarium::victory_item_core::get_transform(
        survarium::victory_item_core *this,
        vostok::math::float4x4 *result)
{
  const vostok::math::float4x4 *v2; // esi
  vostok::math::float4x4 *v3; // eax

  if ( this->m_user )
  {
    v2 = this->m_user->transform(&this->m_user->survarium::collision_user);
    v3 = result;
    qmemcpy(result, v2, sizeof(vostok::math::float4x4));
  }
  else
  {
    if ( this->m_container )
      this->m_container->get_transform(this->m_container, result);
    else
      survarium::usable_object::get_transform(&this->survarium::usable_object, result);
    return result;
  }
  return v3;
}


vostok::math::float4x4 *__thiscall survarium::victory_item_core::get_transform(char *this, vostok::math::float4x4 *a2)
{
  return survarium::victory_item_core::get_transform((survarium::victory_item_core *)(this - 20), a2);
}
