vostok::math::float4x4 *__thiscall survarium::_dynamic_initializer_for__last_bullet_particle__(
        vostok::math::float4x4 *this)
{
  vostok::math::float4x4 *result; // eax
  vostok::math::float4x4 v2; // [esp+8h] [ebp-40h] BYREF

  result = vostok::math::float4x4::identity(this, &v2);
  qmemcpy(&survarium::last_bullet_particle, result, sizeof(survarium::last_bullet_particle));
  return result;
}
