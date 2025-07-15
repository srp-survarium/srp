vostok::math::float3 *__usercall survarium::human_npc::get_position@<eax>(
        survarium::human_npc *this@<ecx>,
        vostok::math::float3 *a2@<eax>)
{
  __int64 v2; // xmm0_8
  float z; // ecx

  v2 = *(_QWORD *)&this->m_transform.lines[3].x;
  z = this->m_transform.c.z;
  *(_QWORD *)&a2->x = v2;
  a2->z = z;
  return a2;
}


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
