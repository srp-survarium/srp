vostok::math::float4x4 *__thiscall transform_getter::get_transform(
        transform_getter *this,
        vostok::math::float4x4 *result,
        vostok::math::float4x4 *animated_object)
{
  boost::function1<vostok::math::float4x4,void const *> *v3; // ecx
  vostok::math::float4x4 *v4; // eax
  vostok::math::float4x4 transform; // [esp+8h] [ebp-40h] BYREF

  if ( vostok::animation::animation_player::try_get_transform(
         this->animation_player,
         this->animation_player,
         animated_object) )
  {
    v4 = result;
    qmemcpy((void *)result, &transform, sizeof(vostok::math::float4x4));
  }
  else
  {
    boost::function1<vostok::math::float4x4,void const *>::operator()(v3, result, animated_object);
    return result;
  }
  return v4;
}
