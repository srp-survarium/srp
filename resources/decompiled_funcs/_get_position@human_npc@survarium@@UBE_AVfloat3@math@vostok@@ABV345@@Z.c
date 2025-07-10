vostok::math::float3 *__thiscall survarium::human_npc::get_position(
        survarium::human_npc *this,
        vostok::math::float3 *result,
        const vostok::math::float3 *requester)
{
  vostok::math::float4x4 *v3; // eax
  float z; // edx
  _BYTE v6[64]; // [esp+0h] [ebp-40h] BYREF

  v3 = this->local_to_cell(&this->vostok::ai::game_object, v6, requester);
  z = v3->c.z;
  *(_QWORD *)&result->x = *(_QWORD *)&v3->lines[3].x;
  result->z = z;
  return result;
}
