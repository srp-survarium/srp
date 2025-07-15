vostok::math::float3 *__thiscall survarium::human_npc::get_source_position(
        survarium::human_npc *this,
        vostok::math::float3 *result,
        const vostok::math::float3 *requester)
{
  (*(void (__thiscall **)(float *, vostok::math::float3 *, const vostok::math::float3 *))(LODWORD(this[-1].m_feet_target.z)
                                                                                        + 8))(
    &this[-1].m_feet_target.z,
    result,
    requester);
  return result;
}
