void __thiscall survarium::body_part_parameters::deserialize(
        survarium::body_part_parameters *this,
        vostok::network_core::buffer_reader *reader,
        const unsigned int time_offset)
{
  const unsigned __int8 *m_pointer; // esi
  float v4; // xmm0_4
  const unsigned __int8 *v5; // esi
  const unsigned __int8 *v6; // esi
  unsigned __int8 v7; // dl
  vostok::fixed_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int>,8> *p_m_affects; // eax
  const unsigned __int8 *v9; // esi
  survarium::hit_affects_type_enum v10; // edx
  unsigned __int8 v11; // [esp+Eh] [ebp-12h]
  int v12; // [esp+10h] [ebp-10h]
  vostok::fixed_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int>,8> *v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> value; // [esp+18h] [ebp-8h] BYREF

  m_pointer = reader->m_pointer;
  v4 = *(float *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  this->m_health = v4;
  v5 = reader->m_pointer;
  v12 = *(_DWORD *)v5;
  reader->m_pointer = v5 + 4;
  this->m_last_hit_time = v12 != 0 ? time_offset + v12 : 0;
  v6 = reader->m_pointer;
  v7 = *v6;
  reader->m_pointer = v6 + 1;
  p_m_affects = &this->m_affects;
  v11 = v7;
  v13 = &this->m_affects;
  this->m_affects.m_end = this->m_affects.m_begin;
  if ( v7 )
  {
    while ( 1 )
    {
      v9 = reader->m_pointer;
      v10 = *v9;
      reader->m_pointer = ++v9;
      v14 = *(_DWORD *)v9;
      value.first = v10;
      reader->m_pointer = v9 + 4;
      value.second = v14 != 0 ? time_offset + v14 : 0;
      vostok::buffer_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int>>::push_back(
        p_m_affects,
        &value);
      if ( !--v11 )
        break;
      p_m_affects = v13;
    }
  }
}
