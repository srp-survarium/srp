vostok::math::float4x4 *__cdecl vostok::math::get_relative_matrix(
        vostok::math::float4x4 *result,
        const vostok::math::float4x4 *original_matrix,
        const vostok::math::float4x4 *parent_matrix)
{
  vostok::math::float4x4 *v3; // eax
  survarium::game_options v5; // [esp+50h] [ebp-80h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v5.m_conflicted_action_to_bind);
  if ( vostok::math::float4x4::try_invert((vostok::math::float4x4 *)&v5.m_conflicted_action_to_bind, parent_matrix) )
  {
    vostok::math::operator*(result, original_matrix, (const vostok::math::float4x4 *)&v5.m_conflicted_action_to_bind);
  }
  else
  {
    __debugbreak();
    v3 = (vostok::math::float4x4 *)survarium::weapon_core::cast_weapon_core(&v5);
    qmemcpy((void *)result, vostok::math::float4x4::identity(v3), sizeof(vostok::math::float4x4));
  }
  return result;
}
