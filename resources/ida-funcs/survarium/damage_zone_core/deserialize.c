void __thiscall survarium::damage_zone_core::deserialize(
        survarium::damage_zone_core *this,
        vostok::network_core::buffer_reader *reader,
        unsigned int time_offset)
{
  const unsigned __int8 *m_pointer; // esi
  vostok::resources::class_id_enum v4; // edx

  m_pointer = reader->m_pointer;
  v4 = *(_DWORD *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  this->m_class_id = v4;
  if ( v4 != -1 )
    this->m_class_id = time_offset + v4;
  BYTE1(this->grm_satisfaction_tree_hook.parent_) = vostok::network_core::buffer_reader::r<bool>(reader);
}
