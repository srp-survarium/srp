vostok::math::float4x4 *__userpurge survarium::human_npc::get_eyes_matrix@<eax>(
        survarium::human_npc *this@<ecx>,
        int a2@<edi>,
        vostok::math::float4x4 *result)
{
  vostok::math::float3 *(__thiscall *get_eyes_direction)(struct survarium::human_npc *, vostok::math::float3 *); // edx
  const vostok::math::float3 *v5; // edi
  const vostok::math::float3 *v6; // eax
  vostok::math::float3 local_up_in_world_space; // [esp+8h] [ebp-24h] BYREF
  _BYTE v9[16]; // [esp+14h] [ebp-18h] BYREF
  _BYTE v10[8]; // [esp+24h] [ebp-8h] BYREF

  get_eyes_direction = this->get_eyes_direction;
  local_up_in_world_space.x = 0.0;
  *(_QWORD *)&local_up_in_world_space.elements[1] = (unsigned int)clear_value;
  v5 = (const vostok::math::float3 *)((int (__thiscall *)(survarium::human_npc *, _BYTE *, int))get_eyes_direction)(
                                       this,
                                       v9,
                                       a2);
  v6 = this->get_eyes_position(this, v10);
  vostok::math::create_camera_direction(v6, v5, &local_up_in_world_space);
  return result;
}
