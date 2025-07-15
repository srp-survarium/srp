void __thiscall survarium::human_npc::on_hit_event(survarium::human_npc *this, const survarium::hit_object *hit_source)
{
  vostok::math::float3 *(__thiscall *get_position)(struct survarium::human_npc *, vostok::math::float3 *, const vostok::math::float3 *); // edx
  int v4; // eax
  vostok::ai::game_object *m_source; // ecx
  float z; // edx
  __int64 v7; // xmm0_8
  vostok::ai::world *m_ai_world; // ecx
  vostok::math::float3 v9; // [esp+10h] [ebp-30h] BYREF
  vostok::ai::sensed_hit_object perceived_hit; // [esp+1Ch] [ebp-24h] BYREF

  get_position = this->get_position;
  perceived_hit.direction.z = -4.2170408e37;
  *(_QWORD *)&perceived_hit.direction.x = 0xFDFDCDCDFDFDCDCDuLL;
  *(_QWORD *)&perceived_hit.own_position.x = 0xFDFDCDCDFDFDCDCDuLL;
  perceived_hit.extent_of_damage = -4.2170408e37;
  perceived_hit.bone_index = -12851;
  perceived_hit.own_position.z = -4.2170408e37;
  perceived_hit.object = 0;
  v4 = (int)get_position(this, &v9, &hit_source->m_position);
  m_source = hit_source->m_source;
  z = hit_source->m_position.z;
  *(_QWORD *)&perceived_hit.own_position.x = *(_QWORD *)v4;
  v7 = *(_QWORD *)&hit_source->m_position.x;
  perceived_hit.own_position.z = *(float *)(v4 + 8);
  LOWORD(v4) = hit_source->m_target_bone;
  perceived_hit.object = m_source;
  m_ai_world = this->m_ai_world;
  *(_QWORD *)&perceived_hit.direction.x = v7;
  *(float *)&v7 = hit_source->m_power;
  perceived_hit.bone_index = v4;
  perceived_hit.direction.z = z;
  LODWORD(perceived_hit.extent_of_damage) = v7;
  m_ai_world->on_hit_event(m_ai_world, this, &perceived_hit);
  this->m_sound_produced = 1;
}
