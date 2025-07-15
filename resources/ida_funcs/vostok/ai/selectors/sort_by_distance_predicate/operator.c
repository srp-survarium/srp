bool __thiscall vostok::ai::selectors::sort_by_distance_predicate::operator()(
        vostok::ai::selectors::sort_by_distance_predicate *this,
        const vostok::ai::movement_target *object1,
        const vostok::ai::movement_target *object2)
{
  const vostok::math::float3 *v3; // eax
  vostok::math::float3 *v4; // eax
  vostok::math::float3_pod *v5; // ecx
  vostok::math::float3 *v6; // eax
  vostok::math::float3_pod *v7; // ecx
  vostok::ai::npc *m_npc; // [esp+10h] [ebp-50h]
  vostok::math::float3 v10; // [esp+24h] [ebp-3Ch] BYREF
  vostok::math::float3 v11; // [esp+30h] [ebp-30h] BYREF
  vostok::math::float3 v12; // [esp+3Ch] [ebp-24h] BYREF
  float length1; // [esp+48h] [ebp-18h]
  vostok::math::float3_pod v14; // [esp+4Ch] [ebp-14h] BYREF
  float length2; // [esp+58h] [ebp-8h]
  const vostok::math::float3 *position; // [esp+5Ch] [ebp-4h]

  m_npc = this->brain->m_npc;
  vostok::math::float3::float3(&v12, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  m_npc->get_position(m_npc, (vostok::math::float3 *)&v14, v3);
  position = (const vostok::math::float3 *)&v14;
  v4 = vostok::math::operator-(&v14, &object1->target_position, &v11);
  length1 = vostok::math::float3_pod::length(v5, &v4->x);
  v6 = vostok::math::operator-(position, &object2->target_position, &v10);
  length2 = vostok::math::float3_pod::length(v7, &v6->x);
  return length2 > length1;
}
