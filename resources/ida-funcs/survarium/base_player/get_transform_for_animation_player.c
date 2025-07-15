vostok::math::float4x4 *__thiscall survarium::base_player::get_transform_for_animation_player(
        survarium::base_player *this,
        vostok::math::float4x4 *result,
        survarium::base_player *animated_object)
{
  vostok::math::float4x4 *v3; // esi
  vostok::math::float4x4 *v4; // eax
  vostok::math::float4x4 v5; // [esp+8h] [ebp-40h] BYREF

  if ( animated_object == this )
    v3 = (vostok::math::float4x4 *)&byte_10E2C[(_DWORD)this];
  else
    v3 = vostok::math::float4x4::identity((vostok::math::float4x4 *)this, &v5);
  v4 = result;
  qmemcpy(result, v3, sizeof(vostok::math::float4x4));
  return v4;
}
