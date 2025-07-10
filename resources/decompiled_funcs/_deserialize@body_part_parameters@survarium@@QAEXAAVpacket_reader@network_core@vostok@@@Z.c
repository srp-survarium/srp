void __userpurge survarium::body_part_parameters::deserialize(
        survarium::body_part_parameters *this@<ecx>,
        float a2@<xmm0>,
        vostok::network_core::packet_reader *reader)
{
  vostok::network_core::packet_reader *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> affect; // [esp+20h] [ebp-Ch] BYREF
  unsigned __int8 affects_count; // [esp+2Bh] [ebp-1h]

  vostok::network_core::packet_reader::r<float>(reader);
  this->m_health = a2;
  this->m_last_hit_time = vostok::network_core::packet_reader::r<unsigned int>(v3, (int)reader);
  affects_count = vostok::network_core::packet_reader::r<unsigned char>(
                    (vostok::network_core::packet_reader *)this,
                    (int)reader);
  survarium::weapon_user_dead_state::finalize(v4);
  survarium::weapon_user_dead_state::finalize(v5);
  while ( affects_count )
  {
    affect.first = affects_type_death;
    affect.second = 0;
    survarium::deserialize_affect(reader, &affect);
    survarium::body_part_parameters::apply_affect_by_force(this, affect.first, affect_applying, affect.second);
    --affects_count;
  }
}
