vostok::math::float4x4 *__thiscall survarium::human_npc::local_to_cell(
        survarium::human_npc *this,
        vostok::math::float4x4 *result,
        const vostok::math::float3 *requester)
{
  vostok::math::float4x4 *v3; // eax

  v3 = result;
  qmemcpy((void *)result, &this->m_game_attributes.outfit_id, sizeof(vostok::math::float4x4));
  return v3;
}
