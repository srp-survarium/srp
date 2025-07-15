BOOL __thiscall survarium::human_npc::is_target_in_melee_range(
        survarium::human_npc *this,
        const vostok::ai::npc *const target)
{
  __int64 v2; // xmm0_8
  vostok::math::float3 *(__thiscall *get_position)(vostok::ai::npc *, vostok::math::float3 *, const vostok::math::float3 *); // edx
  float *v4; // eax
  float v6; // [esp+14h] [ebp-1Ch]
  __int64 v7; // [esp+18h] [ebp-18h] BYREF
  float z; // [esp+20h] [ebp-10h]
  vostok::math::float3 v9; // [esp+24h] [ebp-Ch] BYREF

  v2 = *(_QWORD *)&this->m_transform.lines[3].x;
  z = this->m_transform.c.z;
  v6 = z;
  get_position = target->get_position;
  v7 = v2;
  v4 = (float *)get_position(target, &v9, (const vostok::math::float3 *)&v7);
  return sqrtf(
           (float)((float)((float)(v4[2] - v6) * (float)(v4[2] - v6))
                 + (float)((float)(*v4 - *(float *)&v2) * (float)(*v4 - *(float *)&v2)))
         + (float)((float)(v4[1] - *((float *)&v2 + 1)) * (float)(v4[1] - *((float *)&v2 + 1)))) <= 10.0;
}
