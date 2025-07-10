vostok::math::float4x4 *__thiscall survarium::player::get_transform_for_animation_player(
        survarium::player *this,
        vostok::math::float4x4 *result,
        survarium::player *animated_object,
        const vostok::math::float4x4 *character_transform)
{
  vostok::math::float4x4 *v4; // eax

  if ( animated_object == this )
  {
    v4 = result;
    qmemcpy((void *)result, character_transform, sizeof(vostok::math::float4x4));
  }
  else
  {
    this->m_current_active_object.m_object->transform(this->m_current_active_object.m_object, result);
    return result;
  }
  return v4;
}
