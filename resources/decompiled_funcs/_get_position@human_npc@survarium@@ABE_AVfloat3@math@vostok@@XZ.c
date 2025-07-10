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
