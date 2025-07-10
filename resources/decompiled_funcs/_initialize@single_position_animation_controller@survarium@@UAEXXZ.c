void __thiscall survarium::single_position_animation_controller::initialize(
        survarium::single_position_animation_controller *this)
{
  _QWORD *v2; // eax
  survarium::animation_space_vertex_id *m_target_vertex; // ecx
  survarium::human_npc *m_owner; // ecx
  vostok::math::float3 v5[2]; // [esp-14h] [ebp-34h] BYREF
  __int64 v6; // [esp+4h] [ebp-1Ch] BYREF
  vostok::math::quaternion *v7; // [esp+Ch] [ebp-14h]
  vostok::math::float3 v8; // [esp+10h] [ebp-10h] BYREF

  v7 = 0;
  v6 = 0;
  memset(v5, 0, 12);
  vostok::math::quaternion::quaternion(0, &v8.x, v5[0]);
  m_target_vertex = this->m_target_vertex;
  *(_QWORD *)&m_target_vertex->rotation.x = *v2;
  *(_QWORD *)&m_target_vertex->rotation.vector.elements[2] = v2[1];
  m_owner = this->m_owner;
  v6 = 0;
  v7 = 0;
  this->m_target_vertex->translation = *m_owner->get_position(m_owner, &v8, (const vostok::math::float3 *)&v6);
}
