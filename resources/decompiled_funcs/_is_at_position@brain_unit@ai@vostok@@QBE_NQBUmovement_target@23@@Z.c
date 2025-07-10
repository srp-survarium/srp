bool __thiscall vostok::ai::brain_unit::is_at_position(
        vostok::ai::brain_unit *this,
        const vostok::ai::movement_target *const target)
{
  const vostok::math::float3 *v2; // eax
  vostok::math::float3 *v3; // eax
  vostok::math::float3 *v4; // eax
  vostok::math::float3 v7; // [esp+18h] [ebp-24h] BYREF
  _BYTE v8[12]; // [esp+24h] [ebp-18h] BYREF
  vostok::math::float3 v9; // [esp+30h] [ebp-Ch] BYREF

  vostok::math::float3::float3(&v9, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  v3 = this->m_npc->get_position(this->m_npc, v8, v2);
  v4 = vostok::math::operator-(v3, &target->target_position, &v7);
  return vostok::math::length(v4) <= 1.3;
}
